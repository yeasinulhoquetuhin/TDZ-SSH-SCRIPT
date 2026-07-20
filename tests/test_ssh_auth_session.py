import os
import shutil
import tempfile
import time
import unittest
from pathlib import Path
from unittest import mock

import tdz_ssh_auth_session as auth_session


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
    # read_process_identity removes fields 1-2. The remaining array begins at
    # field 3, so process start time (field 22) is index 19.
    fields = ["S", str(parent_pid)] + ["0"] * 17 + [str(start_time)] + ["0"] * 8
    (process_dir / "stat").write_text(
        "%d (%s) %s\n" % (pid, command, " ".join(fields))
    )
    (process_dir / "comm").write_text(command + "\n")
    (process_dir / "cmdline").write_bytes(title.encode() + b"\0")


class AuthenticatedSshSessionTests(unittest.TestCase):
    def setUp(self):
        self.temp_dir = tempfile.TemporaryDirectory()
        self.root = Path(self.temp_dir.name)
        self.proc = self.root / "proc"
        self.proc.mkdir()
        self.paths = auth_session.RuntimePaths(
            db_file=self.root / "users.db",
            manual_lock_file=self.root / "manual-locks.db",
            bandwidth_dir=self.root / "bandwidth",
            usage_lock=self.root / "bandwidth/.usage.lock",
            banner_dir=self.root / "banners",
            banner_flag=self.root / "banners_enabled",
            session_dir=self.root / "run/ssh-auth-sessions",
            openvpn_snapshot=self.root / "openvpn-sessions.tsv",
            proc_root=self.proc,
        )
        self.paths.db_file.write_text("E:secret:2099-12-31:2:10\n")
        self.paths.banner_dir.mkdir()
        (self.paths.banner_dir / "E.txt").write_text(
            "<br><b>[-] Username:</b> E<br>"
            "<b>[-] Active Session:</b> 0/2<br>"
        )
        self.paths.banner_flag.touch()
        self.env = {"PAM_SERVICE": "sshd", "PAM_TYPE": "account", "PAM_USER": "E"}

    def tearDown(self):
        self.temp_dir.cleanup()

    def login(self, pid: int, start_time: int) -> auth_session.LoginDecision:
        write_fake_process(
            self.proc,
            pid=pid,
            parent_pid=1,
            start_time=start_time,
            command="sshd",
            title="sshd: E [priv]",
        )
        return auth_session.process_authenticated_login(
            paths=self.paths,
            environment=self.env,
            parent_pid=pid,
            who_output="",
            now=time.time(),
        )

    def test_pre_auth_or_failed_auth_path_never_registers_or_displays(self):
        write_fake_process(self.proc, 100, 1, 1000, "sshd", "sshd: E [preauth]")
        decision = auth_session.process_authenticated_login(
            paths=self.paths,
            environment={"PAM_SERVICE": "sshd", "PAM_TYPE": "auth", "PAM_USER": "E"},
            parent_pid=100,
            who_output="",
        )
        self.assertTrue(decision.allowed)
        self.assertEqual(decision.message, "")
        self.assertEqual(decision.reason, "not_applicable")
        self.assertFalse(self.paths.session_dir.exists())

    def test_missing_policy_row_fails_closed_only_for_tdz_system_users(self):
        self.paths.db_file.write_text("")
        with mock.patch.object(
            auth_session, "is_tdztunnel_system_user", return_value=True
        ):
            managed = auth_session.process_authenticated_login(
                paths=self.paths,
                environment=self.env,
                who_output="",
            )
        self.assertFalse(managed.allowed)
        self.assertEqual(managed.reason, "policy_error")
        self.assertIn("Policy Check Failed", managed.message)
        self.assertFalse(self.paths.session_dir.exists())

        with mock.patch.object(
            auth_session, "is_tdztunnel_system_user", return_value=False
        ):
            unrelated = auth_session.process_authenticated_login(
                paths=self.paths,
                environment=self.env,
                who_output="",
            )
        self.assertTrue(unrelated.allowed)
        self.assertEqual(unrelated.reason, "not_managed")

    def test_successful_auth_is_included_immediately_once(self):
        decision = self.login(101, 1100)
        self.assertTrue(decision.allowed)
        self.assertIn("Active Session:</b> 1/2", decision.message)
        self.assertTrue((self.paths.session_dir / "101.session").is_file())

        second = self.login(102, 1200)
        self.assertTrue(second.allowed)
        self.assertIn("Active Session:</b> 2/2", second.message)
        counts, pids = auth_session.prune_and_count_markers(self.paths, {"E"})
        self.assertEqual(counts["E"], 2)
        self.assertEqual(pids["E"], (101, 102))

    def test_disconnect_and_pid_reuse_are_removed_without_stale_count(self):
        self.login(103, 1300)
        shutil.rmtree(self.proc / "103")
        counts, _ = auth_session.prune_and_count_markers(self.paths, {"E"})
        self.assertEqual(counts["E"], 0)
        self.assertFalse((self.paths.session_dir / "103.session").exists())

        self.login(104, 1400)
        shutil.rmtree(self.proc / "104")
        write_fake_process(self.proc, 104, 1, 9999, "sshd", "sshd: E [priv]")
        counts, _ = auth_session.prune_and_count_markers(self.paths, {"E"})
        self.assertEqual(counts["E"], 0)
        self.assertFalse((self.paths.session_dir / "104.session").exists())

    def test_only_authenticated_sshd_child_titles_are_fallback_sessions(self):
        write_fake_process(self.proc, 201, 1, 2001, "sshd", "sshd: E@notty")
        write_fake_process(self.proc, 202, 1, 2002, "sshd", "sshd: E [priv]")
        write_fake_process(self.proc, 203, 1, 2003, "sshd", "sshd: E [preauth]")
        write_fake_process(self.proc, 204, 1, 2004, "worker", "sshd: E@notty")
        counts = auth_session.count_authenticated_children(self.paths)
        self.assertEqual(counts["E"], 1)

    def test_openvpn_count_is_combined_but_stale_snapshot_is_ignored(self):
        now = time.time()
        self.paths.openvpn_snapshot.write_text("E\tudp\t7\t1000\n")
        os.utime(self.paths.openvpn_snapshot, (now, now))
        decision = self.login(105, 1500)
        self.assertTrue(decision.allowed)
        self.assertIn("Active Session:</b> 2/2", decision.message)

        shutil.rmtree(self.proc / "105")
        os.utime(self.paths.openvpn_snapshot, (now - 30, now - 30))
        decision = self.login(106, 1600)
        self.assertTrue(decision.allowed)
        self.assertIn("Active Session:</b> 1/2", decision.message)

    def test_disabled_banner_still_registers_for_authoritative_accounting(self):
        self.paths.banner_flag.unlink()
        decision = self.login(107, 1700)
        self.assertTrue(decision.allowed)
        self.assertEqual(decision.message, "")
        counts, _ = auth_session.prune_and_count_markers(self.paths, {"E"})
        self.assertEqual(counts["E"], 1)

    def test_expired_quota_and_manual_lock_show_reason_without_counting(self):
        cases = (
            ("E:secret:2000-01-01:2:10\n", None, None, "expired", "Expired"),
            (
                "E:secret:2099-12-31:2:1\n",
                str(1024**3),
                None,
                "quota",
                "Traffic Ended",
            ),
            (
                "E:secret:2099-12-31:2:10\n",
                None,
                "E\n",
                "manual_lock",
                "Locked",
            ),
        )
        for offset, (row, usage, locks, reason, status) in enumerate(cases, 1):
            with self.subTest(reason=reason):
                self.paths.db_file.write_text(row)
                self.paths.manual_lock_file.write_text(locks or "")
                self.paths.bandwidth_dir.mkdir(exist_ok=True)
                usage_file = self.paths.bandwidth_dir / "E.usage"
                if usage is None:
                    usage_file.unlink(missing_ok=True)
                else:
                    usage_file.write_text(usage + "\n")
                decision = self.login(300 + offset, 3000 + offset)
                self.assertFalse(decision.allowed)
                self.assertEqual(decision.reason, reason)
                self.assertIn("Status:</b> " + status, decision.message)
                self.assertFalse(
                    (self.paths.session_dir / (str(300 + offset) + ".session")).exists()
                )

    def test_connection_limit_denial_removes_the_rejected_marker(self):
        self.login(401, 4001)
        self.login(402, 4002)
        denied = self.login(403, 4003)
        self.assertFalse(denied.allowed)
        self.assertEqual(denied.reason, "connection_limit")
        self.assertIn("Connection Limit Reached", denied.message)
        counts, pids = auth_session.prune_and_count_markers(self.paths, {"E"})
        self.assertEqual(counts["E"], 2)
        self.assertEqual(pids["E"], (401, 402))

    def test_pending_account_is_allowed_and_counted(self):
        self.paths.db_file.write_text("E:secret:Never:2:10:pending:30\n")
        decision = self.login(501, 5001)
        self.assertTrue(decision.allowed)
        self.assertEqual(decision.reason, "pending")
        self.assertIn("Active Session:</b> 1/2", decision.message)


if __name__ == "__main__":
    unittest.main()
