#!/usr/bin/env python3

import os
import subprocess
import tempfile
import textwrap
import time
import unittest
from pathlib import Path


REPO = Path(__file__).resolve().parents[1]
RUNTIME = REPO / "tdz_openvpn_runtime.py"


def write_fake_process(
    proc_root: Path,
    pid: int,
    parent_pid: int,
    start_time: int,
    command: str,
    title: str,
) -> None:
    process_dir = proc_root / str(pid)
    process_dir.mkdir(parents=True, exist_ok=True)
    fields = ["S", str(parent_pid)] + ["0"] * 17 + [str(start_time)] + ["0"] * 8
    (process_dir / "stat").write_text(
        "%d (%s) %s\n" % (pid, command, " ".join(fields))
    )
    (process_dir / "comm").write_text(command + "\n")
    (process_dir / "cmdline").write_bytes(title.encode() + b"\0")


class RuntimeTests(unittest.TestCase):
    def setUp(self) -> None:
        self.temp = tempfile.TemporaryDirectory()
        root = Path(self.temp.name)
        self.db = root / "users.db"
        self.manual_locks = root / "manual-locks.db"
        self.bw = root / "bandwidth"
        self.ovpn = root / "openvpn"
        self.proc = root / "proc"
        self.ssh_session_dir = root / "ssh-auth-sessions"
        self.ssh_snapshot = self.bw / "ssh-sessions.tsv"
        (self.ovpn / "run").mkdir(parents=True)
        self.proc.mkdir()
        self.env = os.environ.copy()
        self.env.pop("TDZ_TEST_SSH_SESSIONS", None)
        self.env.update(
            {
                "TDZ_RUNTIME_TEST_MODE": "1",
                "TDZ_DB_FILE": str(self.db),
                "TDZ_BW_DIR": str(self.bw),
                "TDZ_MANUAL_LOCK_FILE": str(self.manual_locks),
                "TDZ_OVPN_DIR": str(self.ovpn),
                "TDZ_OVPN_SESSION_DIR": str(self.bw / "sessions"),
                "TDZ_USAGE_LOCK": str(self.bw / ".lock"),
                "TDZ_OVPN_STATUS_TCP": str(self.ovpn / "run/status-tcp.tsv"),
                "TDZ_OVPN_STATUS_UDP": str(self.ovpn / "run/status-udp.tsv"),
                "TDZ_OVPN_ADMISSION_DIR": str(self.bw / "admissions"),
                "TDZ_SSH_SESSION_SNAPSHOT": str(self.ssh_snapshot),
                "TDZ_SSH_AUTH_SESSION_DIR": str(self.ssh_session_dir),
                "TDZ_PROC_ROOT": str(self.proc),
                "TDZ_TEST_WHO_OUTPUT": "",
                "TDZ_OVPN_INSTANCE": "tcp",
                "trusted_ip": "198.51.100.8",
                "trusted_port": "50000",
            }
        )

    def tearDown(self) -> None:
        self.temp.cleanup()

    def run_runtime(self, command: str, *args: str, extra_env=None):
        env = self.env.copy()
        if extra_env:
            env.update(extra_env)
        return subprocess.run(
            [str(RUNTIME), command, *args],
            env=env,
            text=True,
            capture_output=True,
            check=False,
        )

    def write_status(self, received=100, sent=200, username="alice") -> None:
        fields = [
            "CLIENT_LIST",
            username,
            "198.51.100.8:50000",
            "10.87.0.2",
            "",
            str(received),
            str(sent),
            "2026-07-18 10:00:00",
            "1784340000",
            username,
            "7",
            "0",
            "AES-256-GCM",
        ]
        (self.ovpn / "run/status-tcp.tsv").write_text("\t".join(fields) + "\n")

    def test_active_account_connects(self):
        self.db.write_text("alice:secret:2099-12-31:2:5\n")
        # client-connect is guaranteed common_name after
        # username-as-common-name; username is not exported there by every
        # supported OpenVPN release.
        result = self.run_runtime("connect", extra_env={"common_name": "alice"})
        self.assertEqual(result.returncode, 0, result.stderr)

    def test_expired_quota_and_limit_are_rejected(self):
        self.db.write_text("alice:secret:2020-01-01:1:1\n")
        expired = self.run_runtime("connect", extra_env={"username": "alice"})
        self.assertNotEqual(expired.returncode, 0)
        self.assertIn("expired", expired.stderr)

        self.db.write_text("alice:secret:2099-12-31:1:1\n")
        self.bw.mkdir(exist_ok=True)
        (self.bw / "alice.usage").write_text(str(1024**3))
        quota = self.run_runtime("connect", extra_env={"username": "alice"})
        self.assertNotEqual(quota.returncode, 0)
        self.assertIn("bandwidth", quota.stderr)

        (self.bw / "alice.usage").write_text("0\n")
        limited = self.run_runtime(
            "connect",
            extra_env={"username": "alice", "TDZ_TEST_SSH_SESSIONS": "1"},
        )
        self.assertNotEqual(limited.returncode, 0)
        self.assertIn("connection limit", limited.stderr)

        locked = self.run_runtime(
            "connect",
            extra_env={"username": "alice", "TDZ_TEST_LOCKED": "1"},
        )
        self.assertNotEqual(locked.returncode, 0)
        self.assertIn("locked", locked.stderr)

        self.manual_locks.write_text("alice\n")
        locked_from_policy = self.run_runtime(
            "connect",
            extra_env={"username": "alice"},
        )
        self.assertNotEqual(locked_from_policy.returncode, 0)
        self.assertIn("locked", locked_from_policy.stderr)

    def test_pending_account_activates_atomically(self):
        self.db.write_text("alice:secret:Never:2:5:pending:30\n")
        result = self.run_runtime("connect", extra_env={"username": "alice"})
        self.assertEqual(result.returncode, 0, result.stderr)
        fields = self.db.read_text().strip().split(":")
        self.assertEqual(len(fields), 5)
        self.assertRegex(fields[2], r"^\d{4}-\d{2}-\d{2}$")

    def test_atomic_admission_blocks_races_but_allows_reauthentication(self):
        self.db.write_text("alice:secret:2099-12-31:1:5\n")
        first = self.run_runtime("connect", extra_env={"common_name": "alice"})
        self.assertEqual(first.returncode, 0, first.stderr)

        raced = self.run_runtime(
            "connect",
            extra_env={
                "common_name": "alice",
                "trusted_port": "50001",
            },
        )
        self.assertNotEqual(raced.returncode, 0)
        self.assertIn("connection limit", raced.stderr)

        self.write_status(username="alice")
        self.assertEqual(self.run_runtime("sync").returncode, 0)
        reauth = self.run_runtime("connect", extra_env={"common_name": "alice"})
        self.assertEqual(reauth.returncode, 0, reauth.stderr)

    def test_new_openvpn_arrival_cannot_replace_an_established_ssh_session(self):
        self.db.write_text(
            "alice:secret:2099-12-31:1:5\n"
            "bob:secret:2099-12-31:1:5\n"
        )
        self.bw.mkdir(parents=True)
        self.ssh_snapshot.write_text("alice\t0\n")
        now = time.time()
        os.utime(self.ssh_snapshot, (now, now))

        write_fake_process(
            self.proc,
            pid=401,
            parent_pid=1,
            start_time=4001,
            command="sshd",
            title="sshd: alice [priv]",
        )
        self.ssh_session_dir.mkdir(mode=0o700)
        marker = self.ssh_session_dir / "401.session"
        marker.write_text("v1\talice\t401\t4001\n")
        marker.chmod(0o600)
        write_fake_process(
            self.proc,
            pid=402,
            parent_pid=1,
            start_time=4002,
            command="sshd",
            title="sshd: bob [priv]",
        )
        other_marker = self.ssh_session_dir / "402.session"
        other_marker.write_text("v1\tbob\t402\t4002\n")
        other_marker.chmod(0o600)

        result = self.run_runtime("connect", extra_env={"common_name": "alice"})

        self.assertNotEqual(result.returncode, 0)
        self.assertIn("connection limit", result.stderr)
        self.assertTrue(marker.is_file())
        self.assertTrue(other_marker.is_file())
        self.assertTrue((self.proc / "401").is_dir())
        self.assertFalse(list((self.bw / "admissions").glob("*.json")))

    def test_stale_admission_does_not_block_an_adapter_retry(self):
        self.db.write_text("alice:secret:2099-12-31:1:5\n")
        admissions = self.bw / "admissions"
        admissions.mkdir(parents=True)
        (admissions / "stale.json").write_text(
            '{"signature":"stale","username":"alice","created":1}\n'
        )
        result = self.run_runtime("connect", extra_env={"common_name": "alice"})
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertFalse((admissions / "stale.json").exists())

    def test_accounting_cycle_never_issues_a_management_kill(self):
        script = textwrap.dedent(
            """
            import importlib.util
            import sys
            spec = importlib.util.spec_from_file_location("runtime", {runtime_path!r})
            runtime = importlib.util.module_from_spec(spec)
            sys.modules[spec.name] = runtime
            spec.loader.exec_module(runtime)
            session = runtime.Session("tcp", "alice", "1", 100, 0)
            runtime.live_sessions = lambda: [session]
            runtime.sync_usage = lambda sessions: list(sessions)
            snapshots = []
            runtime.write_session_snapshot = lambda sessions: snapshots.extend(sessions)
            runtime.management_command = lambda *args: (_ for _ in ()).throw(
                AssertionError("accounting must not kill a client")
            )
            result = runtime.accounting_cycle()
            print([(item.client_id, item.username) for item in result])
            print([(item.client_id, item.username) for item in snapshots])
            """.format(runtime_path=str(RUNTIME))
        )
        result = subprocess.run(
            ["python3", "-c", script],
            env=self.env,
            text=True,
            capture_output=True,
            check=False,
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        lines = result.stdout.splitlines()
        self.assertEqual(lines[0], "[('1', 'alice')]")
        self.assertEqual(lines[1], "[('1', 'alice')]")

    def test_intended_disconnect_has_a_visible_policy_reason(self):
        script = textwrap.dedent(
            """
            import importlib.util
            import sys
            spec = importlib.util.spec_from_file_location("runtime", {runtime_path!r})
            runtime = importlib.util.module_from_spec(spec)
            sys.modules[spec.name] = runtime
            spec.loader.exec_module(runtime)
            session = runtime.Session("tcp", "alice", "7", 100, 0)
            runtime.live_sessions = lambda: [session]
            commands = []
            runtime.management_command = lambda instance, command: commands.append((instance, command)) or True
            print(runtime.command_kill_user("alice", "quota"))
            print(commands)
            """.format(runtime_path=str(RUNTIME))
        )
        result = subprocess.run(
            ["python3", "-c", script],
            env=self.env,
            text=True,
            capture_output=True,
            check=False,
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(result.stdout.splitlines()[0], "0")
        self.assertIn("client-kill 7 RESTART,[P]TDZ-quota", result.stdout)

    def test_status_accounting_adds_only_deltas(self):
        self.db.write_text("alice:secret:2099-12-31:3:5\n")
        self.write_status(100, 200)
        first = self.run_runtime("sync")
        self.assertEqual(first.returncode, 0, first.stderr)
        self.assertTrue(first.stdout.startswith("alice\ttcp\t7\t"))
        self.assertIn(
            "alice\ttcp\t7\t1784340000\t198.51.100.8\t50000",
            (self.ovpn / "run/sessions.tsv").read_text(),
        )
        self.assertEqual((self.bw / "alice.usage").read_text().strip(), "300")

        second = self.run_runtime("sync")
        self.assertEqual(second.returncode, 0, second.stderr)
        self.assertEqual((self.bw / "alice.usage").read_text().strip(), "300")

        self.write_status(250, 450)
        third = self.run_runtime("sync")
        self.assertEqual(third.returncode, 0, third.stderr)
        self.assertEqual((self.bw / "alice.usage").read_text().strip(), "700")

    def test_disconnect_reconciles_the_final_byte_tail(self):
        self.db.write_text("alice:secret:2099-12-31:3:5\n")
        self.write_status(100, 200)
        self.assertEqual(self.run_runtime("sync").returncode, 0)
        (self.ovpn / "run/status-tcp.tsv").write_text("")
        self.assertEqual(self.run_runtime("sync").returncode, 0)
        result = self.run_runtime(
            "disconnect",
            extra_env={
                "username": "alice",
                "TDZ_OVPN_INSTANCE": "tcp",
                "trusted_ip": "198.51.100.8",
                "trusted_port": "50000",
                "bytes_received": "150",
                "bytes_sent": "250",
            },
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual((self.bw / "alice.usage").read_text().strip(), "400")

    def test_disconnect_immediately_removes_the_published_session(self):
        self.db.write_text("alice:secret:2099-12-31:3:5\n")
        self.write_status(100, 200)
        self.assertEqual(self.run_runtime("sync").returncode, 0)
        snapshot = self.ovpn / "run/sessions.tsv"
        self.assertIn("alice\ttcp\t7", snapshot.read_text())

        result = self.run_runtime(
            "disconnect",
            extra_env={
                "username": "alice",
                "TDZ_OVPN_INSTANCE": "tcp",
                "client_id": "7",
                "trusted_ip": "198.51.100.8",
                "trusted_port": "50000",
                "bytes_received": "100",
                "bytes_sent": "200",
            },
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(snapshot.read_text(), "")


if __name__ == "__main__":
    unittest.main()
