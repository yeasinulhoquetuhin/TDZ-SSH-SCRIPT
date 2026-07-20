#!/usr/bin/env python3
"""Authenticated SSH session registry and post-auth TDZ banner renderer.

The OpenSSH ``Banner`` directive is intentionally not used for account data:
it is delivered before authentication.  This helper is called only from the
PAM *account* phase after an authentication method has succeeded.  It records
the lifetime of the connection's privileged sshd process and returns the
per-user banner through pam_exec's ``stdout``/PAM_TEXT_INFO path.  A short,
root-private PAM *auth* guard turns an immediate retry after a policy banner
into a normal authentication failure so reconnecting clients do not loop.

Marker identity is a PID plus the kernel process start time.  Checking both
prevents a stale marker from becoming valid again after PID reuse.
"""

import csv
import datetime as dt
import fcntl
import grp
import hashlib
import json
import math
import os
import pwd
import re
import stat
import subprocess
import sys
import syslog
import tempfile
import time
from collections import Counter
from contextlib import contextmanager
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, FrozenSet, Iterable, Mapping, Optional, Tuple


MARKER_VERSION = "v1"
DENIAL_GUARD_VERSION = "v1"
DENIAL_GUARD_TTL_SECONDS = 10.0
OPENVPN_ADMISSION_DEFAULT_TTL_SECONDS = 10.0
OPENVPN_ADMISSION_MAX_TTL_SECONDS = 60.0
OPENVPN_STATE_CLOCK_SKEW_SECONDS = 5.0
SSH_PROCESS_NAMES = frozenset(("sshd", "sshd-session"))
MANAGED_SYSTEM_GROUP = "tdzusers"
SAFE_USERNAME = re.compile(r"^[A-Za-z0-9_][A-Za-z0-9_.-]{0,31}$")
AUTHENTICATED_TITLE = re.compile(
    r"^(?:sshd|sshd-session): ([A-Za-z0-9_][A-Za-z0-9_.-]{0,31})@"
    r"(?:notty|pts/[^ ]+|tty[^ ]*)$"
)
SESSION_TEXT = re.compile(
    r"(<b>\[-\] Active Session:</b>\s*)[0-9]+/[0-9]+"
)
STATUS_TEXT = re.compile(r"(<b>\[-\] Status:</b>\s*)[^<]*(<br>)")
ADMIN_SECTION_TEXT = re.compile(
    r"(?P<separator>-{3,}<br>)"
    r"<b>\[-\] Admin:</b>\s*"
    r'(?P<link><a href="https://t\.me/[A-Za-z0-9_]+">'
    r"@[A-Za-z0-9_]+</a>)<br>"
)
BANNER_SEPARATOR = "---------------------------------"
CONNECTION_LIMIT_MESSAGE = "Oops! Your session limit has been reached."

POLICY_STATUS = {
    "expired": "Expired",
    "quota": "Traffic Ended",
    "manual_lock": "Locked",
    "connection_limit": "Session Full",
    "session_error": "Session Verification Failed",
    "policy_error": "Policy Check Failed",
}
POLICY_REASONS = frozenset(POLICY_STATUS)
RETRY_GUARD_REASONS = frozenset(
    ("expired", "quota", "manual_lock", "connection_limit", "policy_error")
)


@dataclass(frozen=True)
class RuntimePaths:
    db_file: Path = Path("/etc/tdztunnel/users.db")
    manual_lock_file: Path = Path("/etc/tdztunnel/manual-locks.db")
    bandwidth_dir: Path = Path("/etc/tdztunnel/bandwidth")
    usage_lock: Path = Path("/etc/tdztunnel/bandwidth/.usage.lock")
    banner_dir: Path = Path("/etc/tdztunnel/banners")
    banner_flag: Path = Path("/etc/tdztunnel/banners_enabled")
    session_dir: Path = Path("/run/tdztunnel/ssh-auth-sessions")
    openvpn_snapshot: Path = Path("/etc/tdztunnel/openvpn/run/sessions.tsv")
    openvpn_admission_dir: Path = Path(
        "/etc/tdztunnel/bandwidth/openvpn-sessions/admissions"
    )
    openvpn_status_tcp: Path = Path(
        "/etc/tdztunnel/openvpn/run/status-tcp.tsv"
    )
    openvpn_status_udp: Path = Path(
        "/etc/tdztunnel/openvpn/run/status-udp.tsv"
    )
    proc_root: Path = Path("/proc")


@dataclass(frozen=True)
class ProcessIdentity:
    pid: int
    parent_pid: int
    start_time: int
    command: str


@dataclass(frozen=True)
class Account:
    username: str
    expiry: str
    limit: int
    quota_gb: float
    account_type: str = ""
    metadata_value: str = ""


@dataclass(frozen=True)
class LoginDecision:
    message: str
    allowed: bool
    reason: str = "active"


def load_accounts(db_file: Path) -> Dict[str, Account]:
    accounts: Dict[str, Account] = {}
    try:
        with db_file.open("r", encoding="utf-8", errors="replace") as handle:
            for raw_line in handle:
                fields = raw_line.rstrip("\r\n").split(":")
                if len(fields) < 5:
                    continue
                username = fields[0]
                if not SAFE_USERNAME.fullmatch(username):
                    continue
                try:
                    limit = int(fields[3])
                except ValueError:
                    limit = 1
                try:
                    quota_gb = max(0.0, float(fields[4] or "0"))
                except ValueError:
                    quota_gb = 0.0
                accounts[username] = Account(
                    username=username,
                    expiry=fields[2],
                    limit=max(1, limit),
                    quota_gb=quota_gb,
                    account_type=fields[5] if len(fields) > 5 else "",
                    metadata_value=fields[6] if len(fields) > 6 else "",
                )
    except OSError:
        pass
    return accounts


def is_tdztunnel_system_user(username: str) -> bool:
    """Identify TDZ-owned accounts without affecting unrelated SSH admins."""

    if not SAFE_USERNAME.fullmatch(username):
        return False
    try:
        user_record = pwd.getpwnam(username)
        group_record = grp.getgrnam(MANAGED_SYSTEM_GROUP)
    except (KeyError, OSError):
        return False
    return bool(
        user_record.pw_gid == group_record.gr_gid
        or username in group_record.gr_mem
    )


def load_manual_locks(lock_file: Path) -> FrozenSet[str]:
    try:
        info = lock_file.lstat()
    except FileNotFoundError:
        return frozenset()
    if not stat.S_ISREG(info.st_mode) or stat.S_ISLNK(info.st_mode):
        raise RuntimeError("manual lock policy is not a regular file")
    if os.geteuid() == 0 and (
        info.st_uid != 0 or stat.S_IMODE(info.st_mode) & 0o022
    ):
        raise RuntimeError("manual lock policy has unsafe ownership or mode")
    locks = set()
    with lock_file.open("r", encoding="utf-8", errors="strict") as handle:
        for raw_line in handle:
            username = raw_line.rstrip("\r\n")
            if SAFE_USERNAME.fullmatch(username):
                locks.add(username)
    return frozenset(locks)


def read_usage(bandwidth_dir: Path, username: str) -> int:
    try:
        value = int((bandwidth_dir / (username + ".usage")).read_text().strip() or "0")
    except (OSError, ValueError):
        return 0
    return max(0, value)


@contextmanager
def account_state_lock(paths: RuntimePaths):
    paths.usage_lock.parent.mkdir(mode=0o700, parents=True, exist_ok=True)
    flags = os.O_RDWR | os.O_CREAT | getattr(os, "O_NOFOLLOW", 0)
    descriptor = os.open(str(paths.usage_lock), flags, 0o600)
    try:
        info = os.fstat(descriptor)
        if not stat.S_ISREG(info.st_mode):
            raise RuntimeError("shared account lock is not a regular file")
        if os.geteuid() == 0 and (
            info.st_uid != 0 or stat.S_IMODE(info.st_mode) & 0o022
        ):
            raise RuntimeError("shared account lock has unsafe ownership or mode")
        os.fchmod(descriptor, 0o600)
        fcntl.flock(descriptor, fcntl.LOCK_EX)
        try:
            yield
        finally:
            fcntl.flock(descriptor, fcntl.LOCK_UN)
    finally:
        os.close(descriptor)


def account_policy_reason(
    paths: RuntimePaths,
    account: Account,
    now: Optional[float] = None,
) -> str:
    now = time.time() if now is None else now
    if account.account_type == "trial" and account.metadata_value.isdigit():
        if int(account.metadata_value) > 0 and int(account.metadata_value) <= int(now):
            return "expired"
    if account.account_type != "pending" and account.expiry not in ("", "Never"):
        try:
            expiry_date = dt.date.fromisoformat(account.expiry)
        except ValueError:
            return "expired"
        if dt.datetime.fromtimestamp(now).date() > expiry_date:
            return "expired"
    if account.quota_gb > 0:
        quota_bytes = max(1, int(account.quota_gb * 1024**3))
        if read_usage(paths.bandwidth_dir, account.username) >= quota_bytes:
            return "quota"
    if account.username in load_manual_locks(paths.manual_lock_file):
        return "manual_lock"
    return "pending" if account.account_type == "pending" else "active"


def read_process_identity(proc_root: Path, pid: int) -> Optional[ProcessIdentity]:
    if pid <= 1:
        return None
    process_dir = proc_root / str(pid)
    try:
        stat_line = (process_dir / "stat").read_text(
            encoding="utf-8", errors="replace"
        ).strip()
        close_paren = stat_line.rfind(")")
        if close_paren < 0:
            return None
        fields = stat_line[close_paren + 2 :].split()
        # After removing PID and (comm), index 0 is field 3 (state), index 1
        # is field 4 (PPID), and index 19 is field 22 (process start time).
        if len(fields) <= 19:
            return None
        parent_pid = int(fields[1])
        start_time = int(fields[19])
        command = (process_dir / "comm").read_text(
            encoding="utf-8", errors="replace"
        ).strip()
    except (OSError, ValueError):
        return None
    return ProcessIdentity(pid, parent_pid, start_time, command)


def find_sshd_ancestor(
    proc_root: Path, start_pid: int, max_depth: int = 8
) -> Optional[ProcessIdentity]:
    pid = start_pid
    seen = set()
    for _ in range(max_depth):
        if pid in seen:
            return None
        seen.add(pid)
        identity = read_process_identity(proc_root, pid)
        if identity is None:
            return None
        if identity.command in SSH_PROCESS_NAMES:
            return identity
        pid = identity.parent_pid
    return None


def ensure_private_session_dir(session_dir: Path) -> None:
    session_dir.mkdir(mode=0o700, parents=True, exist_ok=True)
    info = session_dir.lstat()
    if not stat.S_ISDIR(info.st_mode) or stat.S_ISLNK(info.st_mode):
        raise RuntimeError("SSH session registry path is not a real directory")
    if os.geteuid() == 0 and info.st_uid != 0:
        raise RuntimeError("SSH session registry is not owned by root")
    os.chmod(str(session_dir), 0o700)


def _denial_guard_path(paths: RuntimePaths, username: str) -> Path:
    return paths.session_dir / (username + ".denied")


def clear_denial_guard(paths: RuntimePaths, username: str) -> None:
    try:
        _denial_guard_path(paths, username).unlink()
    except FileNotFoundError:
        pass
    except OSError:
        pass


def write_denial_guard(
    paths: RuntimePaths,
    username: str,
    reason: str,
    now: Optional[float] = None,
) -> None:
    """Atomically remember a recent post-auth policy denial.

    The guard contains no password or account metadata. Its only purpose is
    to make the next valid-password retry fail during PAM auth instead of
    reaching OpenSSH's fatal PAM account rejection again.
    """

    if not SAFE_USERNAME.fullmatch(username) or reason not in RETRY_GUARD_REASONS:
        raise ValueError("invalid SSH denial guard")
    now = time.time() if now is None else now
    ensure_private_session_dir(paths.session_dir)
    destination = _denial_guard_path(paths, username)
    payload = "\t".join(
        (
            DENIAL_GUARD_VERSION,
            username,
            reason,
            "%.6f" % (now + DENIAL_GUARD_TTL_SECONDS),
        )
    ) + "\n"
    temp_name = ""
    try:
        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            newline="\n",
            prefix=".%s." % username,
            suffix=".tmp",
            dir=str(paths.session_dir),
            delete=False,
        ) as handle:
            temp_name = handle.name
            os.fchmod(handle.fileno(), 0o600)
            handle.write(payload)
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(temp_name, str(destination))
        temp_name = ""
    finally:
        if temp_name:
            try:
                os.unlink(temp_name)
            except OSError:
                pass


def read_denial_guard(
    paths: RuntimePaths,
    username: str,
    now: Optional[float] = None,
) -> Optional[str]:
    """Return the unexpired, securely stored policy reason for ``username``."""

    if not SAFE_USERNAME.fullmatch(username):
        return None
    now = time.time() if now is None else now
    path = _denial_guard_path(paths, username)
    descriptor = -1
    try:
        directory_info = paths.session_dir.lstat()
        if not stat.S_ISDIR(directory_info.st_mode) or stat.S_ISLNK(
            directory_info.st_mode
        ):
            return None
        if os.geteuid() == 0 and directory_info.st_uid != 0:
            return None
        if stat.S_IMODE(directory_info.st_mode) != 0o700:
            return None
        info = path.lstat()
        if not stat.S_ISREG(info.st_mode) or stat.S_ISLNK(info.st_mode):
            return None
        if stat.S_IMODE(info.st_mode) != 0o600:
            return None
        if os.geteuid() == 0 and info.st_uid != 0:
            return None
        descriptor = os.open(
            str(path), os.O_RDONLY | getattr(os, "O_NOFOLLOW", 0)
        )
        opened_info = os.fstat(descriptor)
        if not stat.S_ISREG(opened_info.st_mode):
            return None
        if (opened_info.st_dev, opened_info.st_ino) != (info.st_dev, info.st_ino):
            return None
        with os.fdopen(
            descriptor, "r", encoding="utf-8", errors="strict"
        ) as handle:
            descriptor = -1
            fields = handle.readline(512).rstrip("\r\n").split("\t")
        if (
            len(fields) != 4
            or fields[0] != DENIAL_GUARD_VERSION
            or fields[1] != username
            or fields[2] not in RETRY_GUARD_REASONS
        ):
            return None
        expires_at = float(fields[3])
        if not now < expires_at <= now + DENIAL_GUARD_TTL_SECONDS + 1:
            clear_denial_guard(paths, username)
            return None
        return fields[2]
    except (OSError, UnicodeError, ValueError):
        return None
    finally:
        if descriptor >= 0:
            os.close(descriptor)


def write_marker(
    paths: RuntimePaths, username: str, identity: ProcessIdentity
) -> Path:
    ensure_private_session_dir(paths.session_dir)
    destination = paths.session_dir / (str(identity.pid) + ".session")
    payload = "\t".join(
        (
            MARKER_VERSION,
            username,
            str(identity.pid),
            str(identity.start_time),
        )
    ) + "\n"
    temp_name = ""
    try:
        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            newline="\n",
            prefix=".%d." % identity.pid,
            suffix=".tmp",
            dir=str(paths.session_dir),
            delete=False,
        ) as handle:
            temp_name = handle.name
            os.fchmod(handle.fileno(), 0o600)
            handle.write(payload)
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(temp_name, str(destination))
        temp_name = ""
    finally:
        if temp_name:
            try:
                os.unlink(temp_name)
            except OSError:
                pass
    return destination


def _read_marker(path: Path) -> Optional[Tuple[str, int, int]]:
    try:
        info = path.lstat()
        if not stat.S_ISREG(info.st_mode) or stat.S_ISLNK(info.st_mode):
            return None
        if stat.S_IMODE(info.st_mode) != 0o600:
            return None
        if os.geteuid() == 0 and info.st_uid != 0:
            return None
        descriptor = os.open(
            str(path), os.O_RDONLY | getattr(os, "O_NOFOLLOW", 0)
        )
        try:
            handle = os.fdopen(descriptor, "r", encoding="utf-8", errors="replace")
        except Exception:
            os.close(descriptor)
            raise
        with handle:
            fields = handle.readline(512).rstrip("\r\n").split("\t")
        if len(fields) != 4 or fields[0] != MARKER_VERSION:
            return None
        username = fields[1]
        pid = int(fields[2])
        start_time = int(fields[3])
        if not SAFE_USERNAME.fullmatch(username):
            return None
        if path.name != "%d.session" % pid:
            return None
        return username, pid, start_time
    except (OSError, ValueError):
        return None


def prune_and_count_markers(
    paths: RuntimePaths, managed_users: Iterable[str]
) -> Tuple[Counter, Dict[str, Tuple[int, ...]]]:
    ensure_private_session_dir(paths.session_dir)
    managed = set(managed_users)
    counts: Counter = Counter()
    pids: Dict[str, list] = {}
    for marker in paths.session_dir.iterdir():
        if not marker.name.endswith(".session"):
            continue
        record = _read_marker(marker)
        live = False
        if record is not None:
            username, pid, expected_start = record
            identity = read_process_identity(paths.proc_root, pid)
            live = bool(
                username in managed
                and identity is not None
                and identity.command in SSH_PROCESS_NAMES
                and identity.start_time == expected_start
            )
        if not live:
            try:
                marker.unlink()
            except OSError:
                pass
            continue
        counts[username] += 1
        pids.setdefault(username, []).append(pid)
    return counts, {user: tuple(sorted(values)) for user, values in pids.items()}


def count_authenticated_children(paths: RuntimePaths) -> Counter:
    counts: Counter = Counter()
    try:
        process_dirs = list(paths.proc_root.iterdir())
    except OSError:
        return counts
    for process_dir in process_dirs:
        if not process_dir.name.isdigit():
            continue
        identity = read_process_identity(paths.proc_root, int(process_dir.name))
        if identity is None or identity.command not in SSH_PROCESS_NAMES:
            continue
        try:
            command_line = (process_dir / "cmdline").read_bytes().replace(b"\0", b" ")
            title = command_line.decode("utf-8", errors="replace").strip()
        except OSError:
            continue
        match = AUTHENTICATED_TITLE.fullmatch(title)
        if match:
            counts[match.group(1)] += 1
    return counts


def count_who_sessions(who_output: Optional[str] = None) -> Counter:
    counts: Counter = Counter()
    if who_output is None:
        try:
            result = subprocess.run(
                ["/usr/bin/who"],
                check=False,
                stdout=subprocess.PIPE,
                stderr=subprocess.DEVNULL,
                text=True,
                timeout=1,
                env={"PATH": "/usr/sbin:/usr/bin:/sbin:/bin", "LANG": "C"},
            )
            who_output = result.stdout
        except (OSError, subprocess.SubprocessError):
            who_output = ""
    for line in who_output.splitlines():
        fields = line.split()
        if fields and SAFE_USERNAME.fullmatch(fields[0]):
            counts[fields[0]] += 1
    return counts


def _fresh_file(path: Path, now: float) -> bool:
    try:
        modified = path.stat().st_mtime
    except OSError:
        return False
    return bool(
        now - OPENVPN_STATE_CLOCK_SKEW_SECONDS
        <= modified
        <= now + OPENVPN_STATE_CLOCK_SKEW_SECONDS
    )


def _split_openvpn_real_address(value: str) -> Tuple[str, str]:
    value = value.strip()
    if value.startswith("["):
        end = value.find("]")
        if end > 1 and value[end + 1 :].startswith(":"):
            return value[1:end], value[end + 2 :]
    host, separator, port = value.rpartition(":")
    if separator and host and port.isdigit():
        return host, port
    return value, ""


def _openvpn_peer_signature(
    username: str, instance: str, remote_ip: str, remote_port: str
) -> str:
    raw = "%s\0%s\0%s\0%s" % (username, instance, remote_ip, remote_port)
    return hashlib.sha256(raw.encode()).hexdigest()


def _snapshot_openvpn_slots(
    snapshot: Path, username: str, now: float
) -> Tuple[set, int]:
    """Return identified slots plus legacy rows that lack peer identity."""

    if not _fresh_file(snapshot, now):
        return set(), 0
    try:
        rows = snapshot.read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError:
        return set(), 0
    slots = set()
    legacy_count = 0
    for row in rows:
        fields = row.split("\t")
        if not fields or fields[0] != username:
            continue
        if (
            len(fields) >= 6
            and fields[1] in ("tcp", "udp")
            and fields[4]
            and fields[5].isdigit()
        ):
            slots.add(
                _openvpn_peer_signature(
                    username, fields[1], fields[4], fields[5]
                )
            )
        else:
            legacy_count += 1
    return slots, legacy_count


def _status_openvpn_slots(
    status_file: Path, instance: str, username: str, now: float
) -> set:
    if not _fresh_file(status_file, now):
        return set()
    slots = set()
    try:
        with status_file.open(
            newline="", encoding="utf-8", errors="replace"
        ) as handle:
            rows = csv.reader(handle, delimiter="\t")
            for row in rows:
                if not row or row[0] != "CLIENT_LIST" or len(row) < 11:
                    continue
                row_username = row[9].strip()
                if row_username in ("", "UNDEF"):
                    row_username = row[1].strip()
                if row_username != username:
                    continue
                remote_ip, remote_port = _split_openvpn_real_address(row[2])
                if remote_ip and remote_port.isdigit():
                    slots.add(
                        _openvpn_peer_signature(
                            username, instance, remote_ip, remote_port
                        )
                    )
                else:
                    # A malformed peer address cannot be merged with an
                    # admission record, but it is still an occupied slot.
                    slots.add(
                        "status:%s:%s:%s"
                        % (instance, row[10].strip(), row[8].strip())
                    )
    except OSError:
        return set()
    return slots


def _read_openvpn_admission(path: Path) -> Optional[dict]:
    descriptor = -1
    try:
        info = path.lstat()
        if not stat.S_ISREG(info.st_mode) or stat.S_ISLNK(info.st_mode):
            return None
        if stat.S_IMODE(info.st_mode) != 0o600:
            return None
        if os.geteuid() == 0 and info.st_uid != 0:
            return None
        descriptor = os.open(
            str(path), os.O_RDONLY | getattr(os, "O_NOFOLLOW", 0)
        )
        opened_info = os.fstat(descriptor)
        if not stat.S_ISREG(opened_info.st_mode):
            return None
        if (opened_info.st_dev, opened_info.st_ino) != (info.st_dev, info.st_ino):
            return None
        with os.fdopen(
            descriptor, "r", encoding="utf-8", errors="strict"
        ) as handle:
            descriptor = -1
            payload = handle.read(4097)
        if len(payload) > 4096:
            return None
        data = json.loads(payload)
        return data if isinstance(data, dict) else None
    except (OSError, UnicodeError, ValueError):
        return None
    finally:
        if descriptor >= 0:
            os.close(descriptor)


def _pending_openvpn_slots(
    admission_dir: Path, username: str, now: float
) -> set:
    try:
        directory_info = admission_dir.lstat()
    except FileNotFoundError:
        return set()
    except OSError:
        return set()
    if not stat.S_ISDIR(directory_info.st_mode) or stat.S_ISLNK(
        directory_info.st_mode
    ):
        raise RuntimeError("OpenVPN admission registry is not a real directory")
    if os.geteuid() == 0 and (
        directory_info.st_uid != 0
        or stat.S_IMODE(directory_info.st_mode) & 0o022
    ):
        raise RuntimeError("OpenVPN admission registry has unsafe permissions")

    slots = set()
    try:
        candidates = list(admission_dir.glob("*.json"))
    except OSError:
        return slots
    for path in candidates:
        data = _read_openvpn_admission(path)
        if data is None or data.get("username") != username:
            continue
        instance = str(data.get("instance", ""))
        remote_ip = str(data.get("remote_ip", ""))
        remote_port = str(data.get("remote_port", ""))
        signature = str(data.get("signature", ""))
        try:
            created = float(data.get("created", 0))
            expires_at = float(
                data.get(
                    "expires_at",
                    created + OPENVPN_ADMISSION_DEFAULT_TTL_SECONDS,
                )
            )
        except (TypeError, ValueError):
            continue
        expected_signature = _openvpn_peer_signature(
            username, instance, remote_ip, remote_port
        )
        if (
            instance not in ("tcp", "udp")
            or not remote_ip
            or not remote_port.isdigit()
            or signature != expected_signature
            or path.name != signature + ".json"
            or not math.isfinite(created)
            or not math.isfinite(expires_at)
            or created > now + OPENVPN_STATE_CLOCK_SKEW_SECONDS
            or not now < expires_at
            or expires_at
            > created
            + OPENVPN_ADMISSION_MAX_TTL_SECONDS
            + OPENVPN_STATE_CLOCK_SKEW_SECONDS
        ):
            continue
        slots.add(signature)
    return slots


def count_openvpn_sessions(
    snapshot: Path, username: str, now: Optional[float] = None
) -> int:
    """Compatibility count for callers that only have the published snapshot."""

    now = time.time() if now is None else now
    slots, legacy_count = _snapshot_openvpn_slots(snapshot, username, now)
    return len(slots) + legacy_count


def count_openvpn_slots(
    paths: RuntimePaths, username: str, now: Optional[float] = None
) -> int:
    """Count live and client-connect-reserved OpenVPN slots once.

    OpenVPN writes an admission record while holding the same account lock as
    this SSH account hook.  Counting that record closes the short interval
    before the new client appears in a status file.  Peer signatures merge a
    reservation with its eventual live row so a successful VPN connection is
    never counted twice.
    """

    now = time.time() if now is None else now
    snapshot_slots, legacy_count = _snapshot_openvpn_slots(
        paths.openvpn_snapshot, username, now
    )
    live_slots = set(snapshot_slots)
    live_slots.update(
        _status_openvpn_slots(paths.openvpn_status_tcp, "tcp", username, now)
    )
    live_slots.update(
        _status_openvpn_slots(paths.openvpn_status_udp, "udp", username, now)
    )
    admission_slots = _pending_openvpn_slots(
        paths.openvpn_admission_dir, username, now
    )
    pending_slots = admission_slots.difference(live_slots)
    # A four-column snapshot from an in-place upgrade has no peer signature.
    # Treat it only as a live-count floor; a simultaneous reservation remains
    # an additional occupied slot until the new snapshot format is published.
    return max(len(live_slots), legacy_count) + len(pending_slots)


def _minimal_policy_banner(
    username: str, total: int, limit: int, reason: str
) -> str:
    status = POLICY_STATUS.get(reason, "Access Denied")
    banner = (
        f"<br><br>{BANNER_SEPARATOR}<br>"
        "<b>[!] ACCOUNT • DETAILS [!]</b><br>"
        f"{BANNER_SEPARATOR}<br>"
        f"<b>[-] Username:</b> {username}<br>"
        f"<b>[-] Status:</b> {status}<br>"
        f"<b>[-] Active Session:</b> {max(0, total)}/{max(1, limit)}<br>"
    )
    if reason == "connection_limit":
        banner += (
            f"{BANNER_SEPARATOR}<br>"
            f"{_connection_limit_message()}<br>"
        )
    return banner + BANNER_SEPARATOR


def _connection_limit_message(admin_link: str = "") -> str:
    if admin_link:
        return (
            f'<font color="red">{CONNECTION_LIMIT_MESSAGE}<br>'
            "Please disconnect another device<br>"
            "Or contact </font>"
            f"{admin_link}"
            '<font color="red"> to increase<br>'
            "your connection limit.</font>"
        )
    return (
        f'<font color="red">{CONNECTION_LIMIT_MESSAGE}<br>'
        "Please disconnect another device<br>"
        "Or contact the admin to increase<br>"
        "your connection limit.</font>"
    )


def _add_connection_limit_message(rendered: str) -> str:
    if CONNECTION_LIMIT_MESSAGE.casefold() in rendered.casefold():
        return rendered
    admin_section = ADMIN_SECTION_TEXT.search(rendered)
    if admin_section is not None:
        message = _connection_limit_message(admin_section.group("link"))
        insertion = (
            admin_section.group("separator")
            + message
            + "<br>"
            + admin_section.group(0)
        )
        return (
            rendered[: admin_section.start()]
            + insertion
            + rendered[admin_section.end() :]
        )
    separator = "" if rendered.endswith("<br>") else "<br>"
    return (
        rendered
        + separator
        + BANNER_SEPARATOR
        + "<br>"
        + _connection_limit_message()
        + "<br>"
        + BANNER_SEPARATOR
    )


def render_banner(
    paths: RuntimePaths,
    username: str,
    total: int,
    limit: int,
    reason: str = "active",
) -> str:
    banner_file = paths.banner_dir / (username + ".txt")
    try:
        content = banner_file.read_text(encoding="utf-8", errors="replace")
    except OSError:
        if reason in POLICY_REASONS:
            return _minimal_policy_banner(username, total, limit, reason)
        return ""
    replacement = r"\g<1>%d/%d" % (max(0, total), max(1, limit))
    rendered, substitutions = SESSION_TEXT.subn(replacement, content, count=1)
    if substitutions != 1:
        if reason in POLICY_REASONS:
            return _minimal_policy_banner(username, total, limit, reason)
        return ""
    if reason in POLICY_REASONS:
        status = POLICY_STATUS[reason]
        rendered, status_substitutions = STATUS_TEXT.subn(
            r"\g<1>%s\g<2>" % status, rendered, count=1
        )
        if status_substitutions != 1:
            return _minimal_policy_banner(username, total, limit, reason)
    if reason == "connection_limit":
        rendered = _add_connection_limit_message(rendered)
    # pam_exec turns each physical output line into a separate PAM message.
    # The TDZ HTML already uses <br>, so send one atomic informational message.
    return rendered.replace("\r", "").replace("\n", "")


def _process_managed_login(
    paths: RuntimePaths,
    accounts: Mapping[str, Account],
    username: str,
    parent_pid: Optional[int] = None,
    who_output: Optional[str] = None,
    now: Optional[float] = None,
) -> LoginDecision:
    account = accounts[username]
    try:
        reason = account_policy_reason(paths, account, now=now)
    except Exception:
        reason = "policy_error"

    if reason in RETRY_GUARD_REASONS:
        try:
            write_denial_guard(paths, username, reason, now=now)
        except Exception:
            # Policy still fails closed if a damaged runtime filesystem stops
            # the reconnect-loop guard from being persisted.
            pass
    else:
        clear_denial_guard(paths, username)

    marker_counts, _marker_pids = prune_and_count_markers(paths, accounts)
    process_counts = count_authenticated_children(paths)
    who_counts = count_who_sessions(who_output)
    ssh_total = max(
        marker_counts.get(username, 0),
        process_counts.get(username, 0),
        who_counts.get(username, 0),
    )
    total = ssh_total + count_openvpn_slots(paths, username, now=now)
    if reason in POLICY_REASONS:
        message = ""
        if paths.banner_flag.is_file():
            message = render_banner(
                paths, username, total, account.limit, reason=reason
            )
        return LoginDecision(message, False, reason)

    caller = os.getppid() if parent_pid is None else parent_pid
    sshd_identity = find_sshd_ancestor(paths.proc_root, caller)
    if sshd_identity is None:
        message = ""
        if paths.banner_flag.is_file():
            message = render_banner(
                paths,
                username,
                total,
                account.limit,
                reason="session_error",
            )
        return LoginDecision(message, False, "session_error")
    write_marker(paths, username, sshd_identity)

    marker_counts, _marker_pids = prune_and_count_markers(paths, accounts)
    ssh_total = max(
        marker_counts.get(username, 0),
        process_counts.get(username, 0),
        who_counts.get(username, 0),
    )
    total = ssh_total + count_openvpn_slots(paths, username, now=now)
    if total > account.limit:
        try:
            (paths.session_dir / (str(sshd_identity.pid) + ".session")).unlink()
        except OSError:
            pass
        try:
            write_denial_guard(
                paths, username, "connection_limit", now=now
            )
        except Exception:
            # The rejected marker is already gone, so a damaged guard cannot
            # turn this failed attempt into a counted session.
            pass
        message = ""
        if paths.banner_flag.is_file():
            message = render_banner(
                paths,
                username,
                max(0, total - 1),
                account.limit,
                reason="connection_limit",
            )
        return LoginDecision(message, False, "connection_limit")
    if not paths.banner_flag.is_file():
        return LoginDecision("", True, reason)
    return LoginDecision(
        render_banner(paths, username, total, account.limit), True, reason
    )


def _process_auth_retry_guard(
    paths: RuntimePaths,
    accounts: Mapping[str, Account],
    account: Account,
    who_output: Optional[str] = None,
    now: Optional[float] = None,
) -> LoginDecision:
    """Stop only a retry that follows a matching post-auth policy banner."""

    try:
        reason = account_policy_reason(paths, account, now=now)
    except Exception:
        reason = "policy_error"
    guarded_reason = read_denial_guard(paths, account.username, now=now)
    if guarded_reason == "connection_limit" and reason in ("active", "pending"):
        marker_counts, _marker_pids = prune_and_count_markers(paths, accounts)
        process_counts = count_authenticated_children(paths)
        who_counts = count_who_sessions(who_output)
        ssh_total = max(
            marker_counts.get(account.username, 0),
            process_counts.get(account.username, 0),
            who_counts.get(account.username, 0),
        )
        total = ssh_total + count_openvpn_slots(
            paths, account.username, now=now
        )
        if total >= account.limit:
            try:
                # Keep reconnecting clients in the ordinary authentication
                # failure path only while every shared connection slot is
                # still occupied.
                write_denial_guard(
                    paths, account.username, "connection_limit", now=now
                )
            except Exception:
                pass
            return LoginDecision("", False, "retry_guard")
        clear_denial_guard(paths, account.username)
        return LoginDecision("", True, reason)
    if reason in RETRY_GUARD_REASONS and guarded_reason == reason:
        try:
            # Sliding expiry keeps a persistently retrying client in the
            # ordinary auth-failure path until it actually stops retrying.
            write_denial_guard(paths, account.username, reason, now=now)
        except Exception:
            pass
        return LoginDecision("", False, "retry_guard")
    if guarded_reason is not None:
        clear_denial_guard(paths, account.username)
    return LoginDecision("", True, reason)


def _missing_managed_policy_decision(
    paths: RuntimePaths,
    username: str,
    pam_type: str,
    now: Optional[float] = None,
) -> LoginDecision:
    if pam_type == "auth":
        if read_denial_guard(paths, username, now=now) == "policy_error":
            try:
                write_denial_guard(paths, username, "policy_error", now=now)
            except Exception:
                pass
            return LoginDecision("", False, "retry_guard")
        return LoginDecision("", True, "policy_error")
    try:
        write_denial_guard(paths, username, "policy_error", now=now)
    except Exception:
        pass
    message = ""
    if paths.banner_flag.is_file():
        message = _minimal_policy_banner(username, 0, 1, "policy_error")
    return LoginDecision(message, False, "policy_error")


def process_authenticated_login(
    paths: RuntimePaths = RuntimePaths(),
    environment: Optional[Mapping[str, str]] = None,
    parent_pid: Optional[int] = None,
    who_output: Optional[str] = None,
    now: Optional[float] = None,
) -> LoginDecision:
    env = os.environ if environment is None else environment
    pam_type = env.get("PAM_TYPE", "")
    if env.get("PAM_SERVICE") != "sshd" or pam_type not in ("auth", "account"):
        return LoginDecision("", True, "not_applicable")
    username = env.get("PAM_USER", "")
    if not SAFE_USERNAME.fullmatch(username):
        return LoginDecision("", True, "not_managed")
    accounts = load_accounts(paths.db_file)
    if username not in accounts:
        # A TDZ system account without a trustworthy database row must never
        # bypass expiry/quota/manual-lock policy. Unrelated SSH admin accounts
        # remain outside this project and continue through the normal PAM stack.
        if is_tdztunnel_system_user(username):
            return _missing_managed_policy_decision(
                paths, username, pam_type, now=now
            )
        return LoginDecision("", True, "not_managed")

    account = accounts[username]
    try:
        # This is the same advisory lock used by first-use activation and the
        # OpenVPN client-connect hook. It serializes simultaneous SSH account
        # decisions so two successful passwords cannot both claim the final
        # connection slot.
        with account_state_lock(paths):
            accounts = load_accounts(paths.db_file)
            account = accounts.get(username)
            if account is None:
                return _missing_managed_policy_decision(
                    paths, username, pam_type, now=now
                )
            if pam_type == "auth":
                return _process_auth_retry_guard(
                    paths,
                    accounts,
                    account,
                    who_output=who_output,
                    now=now,
                )
            return _process_managed_login(
                paths,
                accounts,
                username,
                parent_pid=parent_pid,
                who_output=who_output,
                now=now,
            )
    except Exception:
        message = ""
        if paths.banner_flag.is_file():
            message = render_banner(
                paths,
                username,
                0,
                account.limit,
                reason="policy_error",
            )
        return LoginDecision(message, False, "policy_error")


def main() -> int:
    try:
        decision = process_authenticated_login()
        if decision.message:
            sys.stdout.write(decision.message + "\n")
            sys.stdout.flush()
        return 0 if decision.allowed else 1
    except Exception as exc:
        try:
            syslog.openlog("tdztunnel-ssh-auth")
            syslog.syslog(syslog.LOG_ERR, "post-auth helper failed: %s" % exc)
        except Exception:
            pass
        # Preserve emergency/admin SSH access, but fail closed for accounts
        # owned by TDZ when their policy helper cannot complete safely.
        return 1 if is_tdztunnel_system_user(os.environ.get("PAM_USER", "")) else 0


if __name__ == "__main__":
    raise SystemExit(main())
