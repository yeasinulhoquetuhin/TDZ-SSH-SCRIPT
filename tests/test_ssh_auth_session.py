import os
import shutil
import tempfile
import time
import unittest
from pathlib import Path

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
            banner_dir=self.root / "banners",
            banner_flag=self.root / "banners_enabled",
            session_dir=self.root / "run/ssh-auth-sessions",
            openvpn_snapshot=self.root / "openvpn-sessions.tsv",
            proc_root=self.proc,
        )
        self.paths.db_file.write_text("E:secret:2026-07-25:2:10\n")
        self.paths.banner_dir.mkdir()
        (self.paths.banner_dir / "E.txt").write_text(
            "<br><b>[-] Username:</b> E<br>"
            "<b>[-] Active Session:</b> 0/2<br>"
        )
        self.paths.banner_flag.touch()
        self.env = {"PAM_SERVICE": "sshd", "PAM_TYPE": "account", "PAM_USER": "E"}

    def tearDown(self):
        self.temp_dir.cleanup()

    def login(self, pid: int, start_time: int) -> str:
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
        message = auth_session.process_authenticated_login(
            paths=self.paths,
            environment={"PAM_SERVICE": "sshd", "PAM_TYPE": "auth", "PAM_USER": "E"},
            parent_pid=100,
            who_output="",
        )
        self.assertEqual(message, "")
        self.assertFalse(self.paths.session_dir.exists())

    def test_successful_auth_is_included_immediately_once(self):
        message = self.login(101, 1100)
        self.assertIn("Active Session:</b> 1/2", message)
        self.assertTrue((self.paths.session_dir / "101.session").is_file())

        second = self.login(102, 1200)
        self.assertIn("Active Session:</b> 2/2", second)
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
        message = self.login(105, 1500)
        self.assertIn("Active Session:</b> 2/2", message)

        shutil.rmtree(self.proc / "105")
        os.utime(self.paths.openvpn_snapshot, (now - 30, now - 30))
        message = self.login(106, 1600)
        self.assertIn("Active Session:</b> 1/2", message)

    def test_disabled_banner_still_registers_for_authoritative_accounting(self):
        self.paths.banner_flag.unlink()
        message = self.login(107, 1700)
        self.assertEqual(message, "")
        counts, _ = auth_session.prune_and_count_markers(self.paths, {"E"})
        self.assertEqual(counts["E"], 1)


if __name__ == "__main__":
    unittest.main()
