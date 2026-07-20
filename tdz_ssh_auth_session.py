#!/usr/bin/env python3
"""Authenticated SSH session registry and post-auth TDZ banner renderer.

The OpenSSH ``Banner`` directive is intentionally not used for account data:
it is delivered before authentication.  This helper is called only from the
PAM *account* phase after an authentication method has succeeded.  It records
the lifetime of the connection's privileged sshd process and returns the
per-user banner through pam_exec's ``stdout``/PAM_TEXT_INFO path.

Marker identity is a PID plus the kernel process start time.  Checking both
prevents a stale marker from becoming valid again after PID reuse.
"""

import os
import re
import stat
import subprocess
import sys
import syslog
import tempfile
import time
from collections import Counter
from dataclasses import dataclass
from pathlib import Path
from typing import Dict, Iterable, Mapping, Optional, Tuple


MARKER_VERSION = "v1"
SSH_PROCESS_NAMES = frozenset(("sshd", "sshd-session"))
SAFE_USERNAME = re.compile(r"^[A-Za-z0-9_][A-Za-z0-9_.-]{0,31}$")
AUTHENTICATED_TITLE = re.compile(
    r"^(?:sshd|sshd-session): ([A-Za-z0-9_][A-Za-z0-9_.-]{0,31})@"
    r"(?:notty|pts/[^ ]+|tty[^ ]*)$"
)
SESSION_TEXT = re.compile(
    r"(<b>\[-\] Active Session:</b>\s*)[0-9]+/[0-9]+"
)


@dataclass(frozen=True)
class RuntimePaths:
    db_file: Path = Path("/etc/tdztunnel/users.db")
    banner_dir: Path = Path("/etc/tdztunnel/banners")
    banner_flag: Path = Path("/etc/tdztunnel/banners_enabled")
    session_dir: Path = Path("/run/tdztunnel/ssh-auth-sessions")
    openvpn_snapshot: Path = Path("/etc/tdztunnel/openvpn/run/sessions.tsv")
    proc_root: Path = Path("/proc")


@dataclass(frozen=True)
class ProcessIdentity:
    pid: int
    parent_pid: int
    start_time: int
    command: str


def load_accounts(db_file: Path) -> Dict[str, int]:
    accounts: Dict[str, int] = {}
    try:
        with db_file.open("r", encoding="utf-8", errors="replace") as handle:
            for raw_line in handle:
                fields = raw_line.rstrip("\r\n").split(":")
                if len(fields) < 4:
                    continue
                username = fields[0]
                if not SAFE_USERNAME.fullmatch(username):
                    continue
                try:
                    limit = int(fields[3])
                except ValueError:
                    limit = 1
                accounts[username] = max(1, limit)
    except OSError:
        pass
    return accounts


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


def count_openvpn_sessions(
    snapshot: Path, username: str, now: Optional[float] = None
) -> int:
    now = time.time() if now is None else now
    try:
        modified = snapshot.stat().st_mtime
        if modified < now - 5 or modified > now + 5:
            return 0
        rows = snapshot.read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError:
        return 0
    total = 0
    for row in rows:
        fields = row.split("\t")
        if fields and fields[0] == username:
            total += 1
    return total


def render_banner(paths: RuntimePaths, username: str, total: int, limit: int) -> str:
    banner_file = paths.banner_dir / (username + ".txt")
    try:
        content = banner_file.read_text(encoding="utf-8", errors="replace")
    except OSError:
        return ""
    replacement = r"\g<1>%d/%d" % (max(0, total), max(1, limit))
    rendered, substitutions = SESSION_TEXT.subn(replacement, content, count=1)
    if substitutions != 1:
        return ""
    # pam_exec turns each physical output line into a separate PAM message.
    # The TDZ HTML already uses <br>, so send one atomic informational message.
    return rendered.replace("\r", "").replace("\n", "")


def process_authenticated_login(
    paths: RuntimePaths = RuntimePaths(),
    environment: Optional[Mapping[str, str]] = None,
    parent_pid: Optional[int] = None,
    who_output: Optional[str] = None,
    now: Optional[float] = None,
) -> str:
    env = os.environ if environment is None else environment
    if env.get("PAM_SERVICE") != "sshd" or env.get("PAM_TYPE") != "account":
        return ""
    username = env.get("PAM_USER", "")
    accounts = load_accounts(paths.db_file)
    if username not in accounts or not SAFE_USERNAME.fullmatch(username):
        return ""

    caller = os.getppid() if parent_pid is None else parent_pid
    sshd_identity = find_sshd_ancestor(paths.proc_root, caller)
    if sshd_identity is None:
        return ""
    write_marker(paths, username, sshd_identity)

    marker_counts, _marker_pids = prune_and_count_markers(paths, accounts)
    process_counts = count_authenticated_children(paths)
    who_counts = count_who_sessions(who_output)
    ssh_total = max(
        marker_counts.get(username, 0),
        process_counts.get(username, 0),
        who_counts.get(username, 0),
    )
    total = ssh_total + count_openvpn_sessions(
        paths.openvpn_snapshot, username, now=now
    )
    if not paths.banner_flag.is_file():
        return ""
    return render_banner(paths, username, total, accounts[username])


def main() -> int:
    try:
        message = process_authenticated_login()
        if message:
            sys.stdout.write(message + "\n")
            sys.stdout.flush()
    except Exception as exc:  # PAM helper must never turn a login into an outage.
        try:
            syslog.openlog("tdztunnel-ssh-auth")
            syslog.syslog(syslog.LOG_ERR, "post-auth helper failed: %s" % exc)
        except Exception:
            pass
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
