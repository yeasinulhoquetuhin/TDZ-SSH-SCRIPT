#!/usr/bin/env python3
"""TDZ OpenVPN account hooks, session accounting, and management control.

The helper intentionally has no network-facing API.  OpenVPN invokes the
``connect`` and ``disconnect`` commands, while the TDZ limiter invokes
``sync`` and the management commands locally.
"""

from __future__ import annotations

import argparse
import csv
import datetime as dt
import fcntl
import hashlib
import json
import os
import pwd
import socket
import subprocess
import sys
import tempfile
import time
from contextlib import contextmanager
from dataclasses import dataclass
from pathlib import Path
from typing import Iterable


DB_FILE = Path(os.environ.get("TDZ_DB_FILE", "/etc/tdztunnel/users.db"))
BW_DIR = Path(os.environ.get("TDZ_BW_DIR", "/etc/tdztunnel/bandwidth"))
OVPN_DIR = Path(os.environ.get("TDZ_OVPN_DIR", "/etc/tdztunnel/openvpn"))
STATE_DIR = Path(os.environ.get("TDZ_OVPN_SESSION_DIR", str(BW_DIR / "openvpn-sessions")))
ADMISSION_DIR = Path(
    os.environ.get("TDZ_OVPN_ADMISSION_DIR", str(STATE_DIR / "admissions"))
)
LOCK_FILE = Path(os.environ.get("TDZ_USAGE_LOCK", str(BW_DIR / ".usage.lock")))
STATUS_TCP = Path(os.environ.get("TDZ_OVPN_STATUS_TCP", str(OVPN_DIR / "run/status-tcp.tsv")))
STATUS_UDP = Path(os.environ.get("TDZ_OVPN_STATUS_UDP", str(OVPN_DIR / "run/status-udp.tsv")))
MGMT_TCP = Path(os.environ.get("TDZ_OVPN_MGMT_TCP", str(OVPN_DIR / "run/management-tcp.sock")))
MGMT_UDP = Path(os.environ.get("TDZ_OVPN_MGMT_UDP", str(OVPN_DIR / "run/management-udp.sock")))
SESSION_SNAPSHOT = Path(
    os.environ.get("TDZ_OVPN_SESSION_SNAPSHOT", str(OVPN_DIR / "run/sessions.tsv"))
)
SSH_SESSION_SNAPSHOT = Path(
    os.environ.get("TDZ_SSH_SESSION_SNAPSHOT", str(BW_DIR / "ssh-sessions.tsv"))
)
TEST_MODE = os.environ.get("TDZ_RUNTIME_TEST_MODE") == "1"


@dataclass(frozen=True)
class Account:
    username: str
    password: str
    expiry: str
    limit: int
    quota_gb: float
    account_type: str = ""
    activation_days: int = 0


@dataclass(frozen=True)
class Session:
    instance: str
    username: str
    client_id: str
    connected_epoch: int
    bytes_total: int
    remote_ip: str = ""
    remote_port: str = ""

    @property
    def key(self) -> str:
        raw = f"{self.instance}\0{self.client_id}\0{self.connected_epoch}\0{self.username}"
        return hashlib.sha256(raw.encode()).hexdigest()


def _safe_username(value: str) -> bool:
    return (
        bool(value)
        and len(value) <= 32
        and all(c.isascii() and (c.isalnum() or c in "_-") for c in value)
    )


def read_accounts() -> dict[str, Account]:
    accounts: dict[str, Account] = {}
    try:
        lines = DB_FILE.read_text(encoding="utf-8", errors="replace").splitlines()
    except OSError:
        return accounts
    for line in lines:
        if not line or line.startswith("#"):
            continue
        fields = line.split(":")
        if len(fields) < 5 or not _safe_username(fields[0]):
            continue
        try:
            limit = max(1, int(fields[3] or "1"))
        except ValueError:
            limit = 1
        try:
            quota = max(0.0, float(fields[4] or "0"))
        except ValueError:
            quota = 0.0
        account_type = fields[5] if len(fields) > 5 else ""
        try:
            activation_days = int(fields[6]) if len(fields) > 6 else 0
        except ValueError:
            activation_days = 0
        accounts[fields[0]] = Account(
            fields[0], fields[1], fields[2], limit, quota, account_type, activation_days
        )
    return accounts


@contextmanager
def state_lock():
    BW_DIR.mkdir(parents=True, exist_ok=True, mode=0o700)
    LOCK_FILE.touch(mode=0o600, exist_ok=True)
    with LOCK_FILE.open("r+") as handle:
        fcntl.flock(handle.fileno(), fcntl.LOCK_EX)
        try:
            yield
        finally:
            fcntl.flock(handle.fileno(), fcntl.LOCK_UN)


def usage_path(username: str) -> Path:
    if not _safe_username(username):
        raise ValueError("invalid username")
    return BW_DIR / f"{username}.usage"


def read_usage(username: str) -> int:
    try:
        value = int(usage_path(username).read_text().strip() or "0")
        return max(0, value)
    except (OSError, ValueError):
        return 0


def write_usage(username: str, value: int) -> None:
    target = usage_path(username)
    target.parent.mkdir(parents=True, exist_ok=True, mode=0o700)
    fd, name = tempfile.mkstemp(prefix=f".{username}.", dir=target.parent, text=True)
    try:
        os.fchmod(fd, 0o600)
        with os.fdopen(fd, "w", encoding="ascii") as handle:
            handle.write(f"{max(0, int(value))}\n")
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(name, target)
    except Exception:
        try:
            os.unlink(name)
        except OSError:
            pass
        raise


def account_expired(account: Account) -> bool:
    if account.expiry in ("", "Never", "pending") or account.account_type == "pending":
        return False
    try:
        # A TDZ date remains valid until the end of that local calendar day.
        expiry_date = dt.date.fromisoformat(account.expiry)
    except ValueError:
        return True
    return dt.date.today() > expiry_date


def account_locked(username: str) -> bool:
    if TEST_MODE:
        return os.environ.get("TDZ_TEST_LOCKED") == "1"
    try:
        result = subprocess.run(
            ["passwd", "-S", username], capture_output=True, text=True, timeout=5, check=False
        )
    except (OSError, subprocess.SubprocessError):
        return True
    parts = result.stdout.split()
    return result.returncode != 0 or len(parts) < 2 or parts[1] in {"L", "LK"}


def quota_exceeded(account: Account) -> bool:
    if account.quota_gb <= 0:
        return False
    return read_usage(account.username) >= int(account.quota_gb * 1024**3)


def activate_pending(account: Account) -> Account:
    if account.account_type != "pending":
        return account
    if account.activation_days < 1:
        raise RuntimeError("invalid first-use duration")
    expiry = dt.date.today() + dt.timedelta(days=account.activation_days)
    original = DB_FILE.read_text(encoding="utf-8", errors="strict")
    changed = False
    output: list[str] = []
    for raw in original.splitlines(keepends=True):
        fields = raw.rstrip("\r\n").split(":")
        ending = "\n" if raw.endswith("\n") else ""
        if len(fields) >= 7 and fields[0] == account.username and fields[5] == "pending":
            output.append(":".join(fields[:2] + [expiry.isoformat()] + fields[3:5]) + ending)
            changed = True
        else:
            output.append(raw)
    if not changed:
        raise RuntimeError("account state changed; retry")

    stat = DB_FILE.stat()
    fd, name = tempfile.mkstemp(prefix=".users.activate.", dir=DB_FILE.parent, text=True)
    expiry_updated = False
    try:
        os.fchmod(fd, stat.st_mode & 0o777)
        if hasattr(os, "fchown"):
            os.fchown(fd, stat.st_uid, stat.st_gid)
        with os.fdopen(fd, "w", encoding="utf-8") as handle:
            handle.writelines(output)
            handle.flush()
            os.fsync(handle.fileno())
        if not TEST_MODE:
            result = subprocess.run(
                ["chage", "-E", expiry.isoformat(), account.username],
                capture_output=True,
                text=True,
                timeout=8,
                check=False,
            )
            if result.returncode != 0:
                raise RuntimeError("could not activate account")
            expiry_updated = True
        os.replace(name, DB_FILE)
    except Exception:
        try:
            os.unlink(name)
        except OSError:
            pass
        if not TEST_MODE and expiry_updated:
            subprocess.run(["chage", "-E", "-1", account.username], check=False)
        raise
    return Account(
        account.username, account.password, expiry.isoformat(), account.limit, account.quota_gb
    )


def count_ssh_sessions(username: str) -> int:
    if TEST_MODE:
        try:
            return max(0, int(os.environ.get("TDZ_TEST_SSH_SESSIONS", "0")))
        except ValueError:
            return 0
    # The TDZ limiter publishes its own authoritative SSH count once per
    # second.  Reusing that value keeps the combined SSH + OpenVPN limit
    # consistent even for payload/no-PTY sessions that no longer appear as a
    # conventional sshd child.
    try:
        if SSH_SESSION_SNAPSHOT.stat().st_mtime >= time.time() - 5:
            for line in SSH_SESSION_SNAPSHOT.read_text(
                encoding="utf-8", errors="replace"
            ).splitlines():
                fields = line.split("\t")
                if len(fields) == 2 and fields[0] == username:
                    return max(0, int(fields[1]))
    except (OSError, ValueError):
        pass

    counts = 0
    try:
        result = subprocess.run(["who"], capture_output=True, text=True, timeout=5, check=False)
        counts = sum(1 for line in result.stdout.splitlines() if line.split()[:1] == [username])
    except (OSError, subprocess.SubprocessError):
        pass
    try:
        result = subprocess.run(
            ["ps", "-C", "sshd", "-o", "user="],
            capture_output=True,
            text=True,
            timeout=5,
            check=False,
        )
        sshd_count = sum(1 for line in result.stdout.splitlines() if line.strip() == username)
        counts = max(counts, sshd_count)
    except (OSError, subprocess.SubprocessError):
        pass
    if counts == 0:
        # Fallback for a non-interactive SSH tunnel whose sshd child has
        # already exec'd the user process and therefore is absent from `who`
        # and `ps -C sshd`.
        try:
            uid = pwd.getpwnam(username).pw_uid
            result = subprocess.run(
                ["ps", "-eo", "uid="],
                capture_output=True,
                text=True,
                timeout=5,
                check=False,
            )
            if any(line.strip() == str(uid) for line in result.stdout.splitlines()):
                counts = 1
        except (KeyError, OSError, subprocess.SubprocessError):
            pass
    return counts


def _parse_int(value: str, default: int = 0) -> int:
    try:
        return int(value)
    except (TypeError, ValueError):
        return default


def split_real_address(value: str) -> tuple[str, str]:
    value = value.strip()
    if value.startswith("["):
        end = value.find("]")
        if end > 1 and value[end + 1 :].startswith(":"):
            return value[1:end], value[end + 2 :]
    host, separator, port = value.rpartition(":")
    if separator and host and port.isdigit():
        return host, port
    return value, ""


def peer_signature(username: str, instance: str, remote_ip: str, remote_port: str) -> str:
    raw = f"{username}\0{instance}\0{remote_ip}\0{remote_port}"
    return hashlib.sha256(raw.encode()).hexdigest()


def session_matches_peer(
    session: Session, username: str, instance: str, remote_ip: str, remote_port: str
) -> bool:
    return bool(
        remote_ip
        and remote_port
        and session.username == username
        and (not instance or session.instance == instance)
        and session.remote_ip == remote_ip
        and session.remote_port == remote_port
    )


def cleanup_admissions(sessions: Iterable[Session]) -> None:
    ADMISSION_DIR.mkdir(parents=True, exist_ok=True, mode=0o700)
    live = {
        peer_signature(
            session.username,
            session.instance,
            session.remote_ip,
            session.remote_port,
        )
        for session in sessions
        if session.remote_ip and session.remote_port
    }
    now = int(time.time())
    for path in ADMISSION_DIR.glob("*.json"):
        data = load_state(path)
        created = _parse_int(str(data.get("created", 0)))
        signature = str(data.get("signature", ""))
        if not signature or signature in live or now - created > 30:
            try:
                path.unlink()
            except OSError:
                pass


def count_admissions(username: str, exclude_signature: str = "") -> int:
    count = 0
    for path in ADMISSION_DIR.glob("*.json"):
        data = load_state(path)
        if data.get("username") == username and data.get("signature") != exclude_signature:
            count += 1
    return count


def reserve_admission(
    username: str, instance: str, remote_ip: str, remote_port: str
) -> None:
    ADMISSION_DIR.mkdir(parents=True, exist_ok=True, mode=0o700)
    signature = peer_signature(username, instance, remote_ip, remote_port)
    target = ADMISSION_DIR / f"{signature}.json"
    data = {
        "signature": signature,
        "username": username,
        "instance": instance,
        "remote_ip": remote_ip,
        "remote_port": remote_port,
        "created": int(time.time()),
    }
    fd, name = tempfile.mkstemp(prefix=".admission.", dir=ADMISSION_DIR, text=True)
    try:
        os.fchmod(fd, 0o600)
        with os.fdopen(fd, "w", encoding="utf-8") as handle:
            json.dump(data, handle, separators=(",", ":"))
            handle.write("\n")
        os.replace(name, target)
    except Exception:
        try:
            os.unlink(name)
        except OSError:
            pass
        raise


def clear_admission(username: str, instance: str, remote_ip: str, remote_port: str) -> None:
    if not (remote_ip and remote_port):
        return
    path = ADMISSION_DIR / f"{peer_signature(username, instance, remote_ip, remote_port)}.json"
    try:
        path.unlink()
    except OSError:
        pass


def parse_status(path: Path, instance: str) -> list[Session]:
    sessions: list[Session] = []
    try:
        with path.open(newline="", encoding="utf-8", errors="replace") as handle:
            rows = csv.reader(handle, delimiter="\t")
            for row in rows:
                if not row or row[0] != "CLIENT_LIST" or len(row) < 11:
                    continue
                # OpenVPN status-version 3: Username=9, Client ID=10.
                username = row[9].strip()
                if username in {"", "UNDEF"}:
                    username = row[1].strip()
                if not _safe_username(username):
                    continue
                remote_ip, remote_port = split_real_address(row[2])
                sessions.append(
                    Session(
                        instance=instance,
                        username=username,
                        client_id=row[10].strip(),
                        connected_epoch=max(0, _parse_int(row[8])),
                        bytes_total=max(0, _parse_int(row[5])) + max(0, _parse_int(row[6])),
                        remote_ip=remote_ip,
                        remote_port=remote_port,
                    )
                )
    except OSError:
        pass
    return sessions


def live_sessions() -> list[Session]:
    return parse_status(STATUS_TCP, "tcp") + parse_status(STATUS_UDP, "udp")


def state_path(session: Session) -> Path:
    return STATE_DIR / f"{session.key}.json"


def load_state(path: Path) -> dict:
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
        return data if isinstance(data, dict) else {}
    except (OSError, ValueError):
        return {}


def save_state(session: Session, observed: int) -> None:
    STATE_DIR.mkdir(parents=True, exist_ok=True, mode=0o700)
    target = state_path(session)
    data = {
        "instance": session.instance,
        "username": session.username,
        "client_id": session.client_id,
        "connected_epoch": session.connected_epoch,
        "observed": max(0, observed),
        "last_seen": int(time.time()),
        "remote_ip": session.remote_ip,
        "remote_port": session.remote_port,
    }
    fd, name = tempfile.mkstemp(prefix=".session.", dir=STATE_DIR, text=True)
    try:
        os.fchmod(fd, 0o600)
        with os.fdopen(fd, "w", encoding="utf-8") as handle:
            json.dump(data, handle, separators=(",", ":"))
            handle.write("\n")
        os.replace(name, target)
    except Exception:
        try:
            os.unlink(name)
        except OSError:
            pass
        raise


def sync_usage(sessions: Iterable[Session]) -> list[Session]:
    current = list(sessions)
    live_keys = {session.key for session in current}
    STATE_DIR.mkdir(parents=True, exist_ok=True, mode=0o700)
    with state_lock():
        cleanup_admissions(current)
        for session in current:
            path = state_path(session)
            previous = max(0, _parse_int(str(load_state(path).get("observed", 0))))
            delta = session.bytes_total - previous if session.bytes_total >= previous else session.bytes_total
            if delta:
                write_usage(session.username, read_usage(session.username) + delta)
            save_state(session, session.bytes_total)
        now = int(time.time())
        for path in STATE_DIR.glob("*.json"):
            if path.stem in live_keys:
                continue
            # Keep a short reconciliation window for the client-disconnect
            # hook, which may run just after the status row disappears.
            data = load_state(path)
            if now - _parse_int(str(data.get("last_seen", 0))) > 120:
                try:
                    path.unlink()
                except OSError:
                    pass
    return current


def command_connect() -> int:
    # PAM authentication supplies the raw username to the plugin.  With
    # username-as-common-name, OpenVPN guarantees the authenticated identity
    # to post-auth client-connect scripts as common_name; some releases do not
    # also export username at that hook.
    username = (os.environ.get("username") or os.environ.get("common_name") or "").strip()
    if not _safe_username(username) or username == "root":
        print("TDZ account is not allowed", file=sys.stderr)
        return 1
    instance = os.environ.get("TDZ_OVPN_INSTANCE", "").strip()
    trusted_ip = (os.environ.get("trusted_ip") or os.environ.get("trusted_ip6") or "").strip()
    trusted_port = os.environ.get("trusted_port", "").strip()
    if instance not in {"tcp", "udp"} or not trusted_ip or not trusted_port.isdigit():
        print("TDZ OpenVPN hook context is incomplete", file=sys.stderr)
        return 1
    signature = peer_signature(username, instance, trusted_ip, trusted_port)
    with state_lock():
        account = read_accounts().get(username)
        if account is None:
            print("TDZ account was not found", file=sys.stderr)
            return 1
        if account_locked(username):
            print("TDZ account is locked", file=sys.stderr)
            return 1
        if account.account_type == "pending":
            try:
                account = activate_pending(account)
            except (OSError, RuntimeError, ValueError):
                print("TDZ first-use activation failed", file=sys.stderr)
                return 1
        if account_expired(account):
            print("TDZ account has expired", file=sys.stderr)
            return 1
        if quota_exceeded(account):
            print("TDZ bandwidth limit reached", file=sys.stderr)
            return 1
        sessions = live_sessions()
        cleanup_admissions(sessions)
        current_is_live = any(
            session_matches_peer(session, username, instance, trusted_ip, trusted_port)
            for session in sessions
        )
        ovpn_count = sum(
            1
            for session in sessions
            if session.username == username
            and not session_matches_peer(session, username, instance, trusted_ip, trusted_port)
        )
        pending_count = count_admissions(username, signature)
        if count_ssh_sessions(username) + ovpn_count + pending_count >= account.limit:
            print("TDZ connection limit reached", file=sys.stderr)
            return 1
        if not current_is_live:
            reserve_admission(username, instance, trusted_ip, trusted_port)
    return 0


def command_disconnect() -> int:
    username = (os.environ.get("username") or os.environ.get("common_name") or "").strip()
    if not _safe_username(username):
        return 0
    instance = os.environ.get("TDZ_OVPN_INSTANCE", "").strip()
    client_id = os.environ.get("client_id", "").strip()
    trusted_ip = (os.environ.get("trusted_ip") or os.environ.get("trusted_ip6") or "").strip()
    trusted_port = os.environ.get("trusted_port", "").strip()
    final_total = max(0, _parse_int(os.environ.get("bytes_received", "0"))) + max(
        0, _parse_int(os.environ.get("bytes_sent", "0"))
    )
    with state_lock():
        clear_admission(username, instance, trusted_ip, trusted_port)
        candidates: list[Path] = []
        for path in STATE_DIR.glob("*.json"):
            data = load_state(path)
            if data.get("username") != username:
                continue
            if instance and data.get("instance") != instance:
                continue
            if client_id and str(data.get("client_id", "")) != client_id:
                continue
            if trusted_ip and str(data.get("remote_ip", "")) != trusted_ip:
                continue
            if trusted_port and str(data.get("remote_port", "")) != trusted_port:
                continue
            candidates.append(path)
        if len(candidates) == 1:
            previous = max(0, _parse_int(str(load_state(candidates[0]).get("observed", 0))))
            delta = final_total - previous if final_total >= previous else 0
            if delta:
                write_usage(username, read_usage(username) + delta)
            try:
                candidates[0].unlink()
            except OSError:
                pass
    return 0


def management_socket(instance: str) -> Path:
    if instance == "tcp":
        return MGMT_TCP
    if instance == "udp":
        return MGMT_UDP
    raise ValueError("invalid OpenVPN instance")


def management_command(instance: str, command: str) -> bool:
    path = management_socket(instance)
    if not path.exists():
        return False
    try:
        with socket.socket(socket.AF_UNIX, socket.SOCK_STREAM) as sock:
            sock.settimeout(3)
            sock.connect(str(path))
            try:
                sock.recv(8192)
            except socket.timeout:
                pass
            sock.sendall((command + "\nquit\n").encode("ascii", errors="strict"))
            response = b""
            while len(response) < 65536:
                try:
                    block = sock.recv(8192)
                except socket.timeout:
                    break
                if not block:
                    break
                response += block
        return b"ERROR" not in response.upper()
    except OSError:
        return False


def command_sync(print_rows: bool = True) -> int:
    sessions = sync_usage(live_sessions())
    write_session_snapshot(sessions)
    if print_rows:
        for session in sessions:
            print(
                "\t".join(
                    [session.username, session.instance, session.client_id, str(session.connected_epoch)]
                )
            )
    return 0


def write_session_snapshot(sessions: Iterable[Session]) -> None:
    SESSION_SNAPSHOT.parent.mkdir(parents=True, exist_ok=True, mode=0o700)
    fd, name = tempfile.mkstemp(prefix=".sessions.", dir=SESSION_SNAPSHOT.parent, text=True)
    try:
        os.fchmod(fd, 0o600)
        with os.fdopen(fd, "w", encoding="utf-8") as handle:
            for session in sessions:
                handle.write(
                    "\t".join(
                        [
                            session.username,
                            session.instance,
                            session.client_id,
                            str(session.connected_epoch),
                        ]
                    )
                    + "\n"
                )
        os.replace(name, SESSION_SNAPSHOT)
    except Exception:
        try:
            os.unlink(name)
        except OSError:
            pass
        raise


def command_kill_user(username: str) -> int:
    if not _safe_username(username):
        return 2
    killed = False
    for session in live_sessions():
        if session.username == username and management_command(
            session.instance, f"client-kill {session.client_id}"
        ):
            killed = True
    return 0 if killed else 1


def command_kill_client(instance: str, client_id: str) -> int:
    if not client_id.isdigit():
        return 2
    return 0 if management_command(instance, f"client-kill {client_id}") else 1


def lock_linux_account(username: str) -> None:
    if TEST_MODE:
        return
    subprocess.run(
        ["usermod", "-L", username],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        timeout=8,
        check=False,
    )
    subprocess.run(
        ["pkill", "-KILL", "-u", username],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
        timeout=8,
        check=False,
    )


def enforce_sessions(sessions: list[Session]) -> None:
    accounts = read_accounts()
    grouped: dict[str, list[Session]] = {}
    for session in sessions:
        grouped.setdefault(session.username, []).append(session)

    for username, user_sessions in grouped.items():
        account = accounts.get(username)
        invalid = account is None
        should_lock = False
        if account is not None:
            expired = account_expired(account)
            over_quota = quota_exceeded(account)
            locked = account_locked(username)
            invalid = expired or over_quota or locked
            should_lock = expired or over_quota
        if invalid:
            if should_lock:
                lock_linux_account(username)
            for session in user_sessions:
                management_command(session.instance, f"client-kill {session.client_id}")
            continue

        assert account is not None
        excess = count_ssh_sessions(username) + len(user_sessions) - account.limit
        if excess > 0:
            # Remove the newest OpenVPN connections first.  Existing SSH and
            # older VPN sessions remain stable while the account limit wins.
            newest_first = sorted(
                user_sessions, key=lambda item: item.connected_epoch, reverse=True
            )
            for session in newest_first[:excess]:
                management_command(session.instance, f"client-kill {session.client_id}")


def command_watch(interval: float) -> int:
    while True:
        try:
            sessions = sync_usage(live_sessions())
            write_session_snapshot(sessions)
            enforce_sessions(sessions)
        except Exception as exc:  # keep accounting alive across transient files/service restarts
            print(f"TDZ OpenVPN runtime warning: {exc}", file=sys.stderr, flush=True)
        time.sleep(interval)


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description="TDZ OpenVPN local runtime helper")
    sub = parser.add_subparsers(dest="command", required=True)
    sub.add_parser("connect")
    sub.add_parser("disconnect")
    sub.add_parser("sync")
    sub.add_parser("sessions")
    watch = sub.add_parser("watch")
    watch.add_argument("--interval", type=float, default=1.0)
    kill_user = sub.add_parser("kill-user")
    kill_user.add_argument("username")
    kill_client = sub.add_parser("kill-client")
    kill_client.add_argument("instance", choices=("tcp", "udp"))
    kill_client.add_argument("client_id")
    return parser


def main() -> int:
    args = build_parser().parse_args()
    if os.geteuid() != 0 and not TEST_MODE:
        print("root privileges are required", file=sys.stderr)
        return 1
    if args.command == "connect":
        return command_connect()
    if args.command == "disconnect":
        return command_disconnect()
    if args.command in {"sync", "sessions"}:
        return command_sync(print_rows=True)
    if args.command == "watch":
        if args.interval < 0.2 or args.interval > 60:
            print("watch interval must be between 0.2 and 60 seconds", file=sys.stderr)
            return 2
        return command_watch(args.interval)
    if args.command == "kill-user":
        return command_kill_user(args.username)
    if args.command == "kill-client":
        return command_kill_client(args.instance, args.client_id)
    return 2


if __name__ == "__main__":
    raise SystemExit(main())
