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


class RuntimeTests(unittest.TestCase):
    def setUp(self) -> None:
        self.temp = tempfile.TemporaryDirectory()
        root = Path(self.temp.name)
        self.db = root / "users.db"
        self.bw = root / "bandwidth"
        self.ovpn = root / "openvpn"
        (self.ovpn / "run").mkdir(parents=True)
        self.env = os.environ.copy()
        self.env.update(
            {
                "TDZ_RUNTIME_TEST_MODE": "1",
                "TDZ_DB_FILE": str(self.db),
                "TDZ_BW_DIR": str(self.bw),
                "TDZ_OVPN_DIR": str(self.ovpn),
                "TDZ_OVPN_SESSION_DIR": str(self.bw / "sessions"),
                "TDZ_USAGE_LOCK": str(self.bw / ".lock"),
                "TDZ_OVPN_STATUS_TCP": str(self.ovpn / "run/status-tcp.tsv"),
                "TDZ_OVPN_STATUS_UDP": str(self.ovpn / "run/status-udp.tsv"),
                "TDZ_OVPN_ADMISSION_DIR": str(self.bw / "admissions"),
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

    def test_connection_limit_waits_for_adapter_reconciliation_grace(self):
        now = int(time.time())
        script = textwrap.dedent(
            f"""
            import importlib.util
            import sys
            spec = importlib.util.spec_from_file_location("runtime", {str(RUNTIME)!r})
            runtime = importlib.util.module_from_spec(spec)
            sys.modules[spec.name] = runtime
            spec.loader.exec_module(runtime)
            runtime.read_accounts = lambda: {{
                "alice": runtime.Account("alice", "secret", "2099-12-31", 1, 0)
            }}
            runtime.account_expired = lambda account: False
            runtime.quota_exceeded = lambda account: False
            runtime.account_locked = lambda username: False
            runtime.count_ssh_sessions = lambda username: 0
            killed = []
            runtime.kill_session = lambda session, reason: killed.append((session.client_id, reason)) or True
            old = runtime.Session("tcp", "alice", "1", {now - 30}, 0)
            fresh = runtime.Session("tcp", "alice", "2", {now}, 0)
            runtime.enforce_sessions([old, fresh])
            print(killed)
            fresh = runtime.Session("tcp", "alice", "2", {now - 10}, 0)
            runtime.enforce_sessions([old, fresh])
            print(killed)
            """
        )
        result = subprocess.run(
            ["python3", "-c", script],
            env={**self.env, "TDZ_OVPN_SESSION_GRACE": "8"},
            text=True,
            capture_output=True,
            check=False,
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        lines = result.stdout.splitlines()
        self.assertEqual(lines[0], "[]")
        self.assertEqual(lines[1], "[('2', 'connection-limit')]")

    def test_status_accounting_adds_only_deltas(self):
        self.db.write_text("alice:secret:2099-12-31:3:5\n")
        self.write_status(100, 200)
        first = self.run_runtime("sync")
        self.assertEqual(first.returncode, 0, first.stderr)
        self.assertTrue(first.stdout.startswith("alice\ttcp\t7\t"))
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


if __name__ == "__main__":
    unittest.main()
