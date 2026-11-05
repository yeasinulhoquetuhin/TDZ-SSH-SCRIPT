#!/usr/bin/env python3
"""Local socket checks for the managed SSH payload bridge."""

import os
import shlex
import socket
import subprocess
import sys
import tempfile
import threading
import time
import unittest
from pathlib import Path


REPO = Path(__file__).resolve().parents[1]
BRIDGE = REPO / "ws_ssh_bridge.py"
MENU = REPO / "menu.sh"
SERVER_BANNER = b"SSH-2.0-TDZ_TEST\r\n"
CLIENT_BANNER = b"SSH-2.0-test-client\r\n"


class EchoSSH:
    def __init__(self):
        self.listener = socket.socket()
        self.listener.bind(("127.0.0.1", 0))
        self.port = self.listener.getsockname()[1]
        self.listener.listen()
        self.listener.settimeout(0.1)
        self.stopped = threading.Event()
        self.connections = 0
        self.workers = []
        self.thread = threading.Thread(target=self.run, daemon=True)
        self.thread.start()

    def run(self):
        while not self.stopped.is_set():
            try:
                client, _ = self.listener.accept()
            except socket.timeout:
                continue
            except OSError:
                return
            self.connections += 1
            worker = threading.Thread(target=self.echo, args=(client,), daemon=True)
            self.workers.append(worker)
            worker.start()

    def echo(self, client):
        with client:
            client.settimeout(0.1)
            try:
                client.sendall(SERVER_BANNER)
                while not self.stopped.is_set():
                    try:
                        data = client.recv(65536)
                    except socket.timeout:
                        continue
                    if not data:
                        return
                    client.sendall(data)
            except OSError:
                return

    def close(self):
        self.stopped.set()
        self.listener.close()
        self.thread.join(2)
        for worker in self.workers:
            worker.join(1)


class Reader:
    def __init__(self, client):
        self.client = client
        self.pending = b""

    def until(self, marker):
        while marker not in self.pending:
            chunk = self.client.recv(65536)
            if not chunk:
                raise AssertionError("connection closed before response")
            self.pending += chunk
        result, self.pending = self.pending.split(marker, 1)
        return result + marker

    def exact(self, size):
        while len(self.pending) < size:
            chunk = self.client.recv(65536)
            if not chunk:
                raise AssertionError("connection closed before stream data")
            self.pending += chunk
        result, self.pending = self.pending[:size], self.pending[size:]
        return result


class BridgeTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.root = Path(self.temp.name)
        self.processes = []
        self.backend = EchoSSH()
        self.addCleanup(self.backend.close)
        self.addCleanup(self.temp.cleanup)
        self.addCleanup(self.stop_processes)
        self.port = self.start_bridge()

    def stop_processes(self):
        for process in self.processes:
            process.terminate()
            try:
                process.wait(timeout=3)
            except subprocess.TimeoutExpired:
                process.kill()
                process.wait(timeout=3)

    def start_bridge(self, script=BRIDGE, backend_port=None):
        with socket.socket() as reservation:
            reservation.bind(("127.0.0.1", 0))
            port = reservation.getsockname()[1]
        environment = dict(os.environ, PYTHONDONTWRITEBYTECODE="1", TDZ_WS_BRIDGE_HOST="127.0.0.1",
                           TDZ_WS_BRIDGE_PORT=str(port), TDZ_WS_BRIDGE_SSH_HOST="127.0.0.1",
                           TDZ_WS_BRIDGE_SSH_PORT=str(backend_port or self.backend.port),
                           TDZ_WS_BRIDGE_BRANDING=str(self.root / "branding.conf"))
        # A short establishment timeout makes timeout-leak regressions testable.
        runner = ("import importlib.util, sys; "
                  "s = importlib.util.spec_from_file_location('bridge', sys.argv[1]); "
                  "m = importlib.util.module_from_spec(s); s.loader.exec_module(m); "
                  "m.SSH_CONNECT_TIMEOUT = 0.1; m.HANDSHAKE_TIMEOUT = 2; m.main()")
        process = subprocess.Popen([sys.executable, "-c", runner, str(script)], env=environment,
                                   stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
        self.processes.append(process)
        deadline = time.monotonic() + 5
        while time.monotonic() < deadline:
            self.assertIsNone(process.poll(), "bridge exited during startup")
            try:
                with socket.create_connection(("127.0.0.1", port), timeout=0.1):
                    return port
            except OSError:
                time.sleep(0.02)
        self.fail("bridge did not start")

    def connect(self, port=None):
        client = socket.create_connection(("127.0.0.1", port or self.port), timeout=2)
        self.addCleanup(client.close)
        return client, Reader(client)

    def assert_upgrade(self, reader):
        header = reader.until(b"\r\n\r\n")
        self.assertTrue(header.startswith(b"HTTP/1.1 101 Script By: tuhinbro.com\r\n"))
        self.assertIn(b"Upgrade: websocket\r\n", header)
        self.assertIn(b"Connection: Upgrade\r\n", header)
        self.assertNotIn(b"Content-Length", header)
        self.assertEqual(reader.exact(len(SERVER_BANNER)), SERVER_BANNER)

    def test_http_payload_branding_and_existing_ssh_credentials_path(self):
        client, reader = self.connect()
        request = (b"CONNECT / HTTP/1.1\r\nHost: ssh.example.com\r\n"
                   + f"x-real-host:\tlocalhost:{self.backend.port}\r\n".encode()
                   + b"X-Pass: \r\n\r\n")
        client.sendall(request)
        self.assert_upgrade(reader)
        client.sendall(CLIENT_BANNER)
        self.assertEqual(reader.exact(len(CLIENT_BANNER)), CLIENT_BANNER)

    def test_fragmented_payload_preserves_coalesced_ssh_data(self):
        client, reader = self.connect()
        for fragment in (b"GE", b"T / HTTP/1.1\r\nHo", b"st: ssh.example.com\r\n\r", b"\n" + CLIENT_BANNER):
            client.sendall(fragment)
            time.sleep(0.01)
        self.assert_upgrade(reader)
        self.assertEqual(reader.exact(len(CLIENT_BANNER)), CLIENT_BANNER)

    def test_dark_tunnel_absolute_ws_request_keeps_raw_stream_behavior(self):
        client, reader = self.connect()
        client.sendall(b"GET wss://ssh.example.com/ HTTP/1.1\r\nHost: ssh.example.com\r\n"
                       b"Upgrade: websocket\r\nConnection: Upgrade\r\n\r\n")
        self.assert_upgrade(reader)
        data = CLIENT_BANNER + bytes(range(256)) * 1024
        client.sendall(data)
        self.assertEqual(reader.exact(len(data)), data)

    def test_x_split_coalesced_http_preface_does_not_enter_ssh_stream(self):
        client, reader = self.connect()
        client.sendall(b"GET / HTTP/1.1\r\nX-Split: 1\r\n\r\n"
                       b"\r\nGET /split HTTP/1.1\r\nHost: ssh.example.com\r\n\r\n" + CLIENT_BANNER)
        self.assert_upgrade(reader)
        self.assertEqual(reader.exact(len(CLIENT_BANNER)), CLIENT_BANNER)

    def test_x_split_delayed_fragmented_preface_preserves_ssh_banner(self):
        client, reader = self.connect()
        client.sendall(b"GET / HTTP/1.1\r\nX-Split: 1\r\n\r\n")
        self.assert_upgrade(reader)
        for fragment in (b"\r\nG", b"ET /split HTTP/1.1\r\nHost: test\r", b"\n\r\nS", b"SH-2.0-test-client\r\n"):
            client.sendall(fragment)
            time.sleep(0.01)
        self.assertEqual(reader.exact(len(CLIENT_BANNER)), CLIENT_BANNER)

    def test_x_split_without_extra_request_keeps_first_ssh_bytes(self):
        client, reader = self.connect()
        client.sendall(b"GET / HTTP/1.1\r\nX-Split: 1\r\n\r\n" + CLIENT_BANNER)
        self.assert_upgrade(reader)
        self.assertEqual(reader.exact(len(CLIENT_BANNER)), CLIENT_BANNER)

    def test_fragmented_direct_ssh_does_not_wait_for_http_terminator(self):
        client, reader = self.connect()
        client.sendall(b"S")
        time.sleep(0.01)
        client.sendall(CLIENT_BANNER[1:])
        self.assertEqual(reader.exact(len(SERVER_BANNER)), SERVER_BANNER)
        self.assertEqual(reader.exact(len(CLIENT_BANNER)), CLIENT_BANNER)

    def test_active_stream_outlives_backend_connect_timeout(self):
        client, reader = self.connect()
        client.sendall(b"GET / HTTP/1.1\r\n\r\n")
        self.assert_upgrade(reader)
        time.sleep(0.25)
        client.sendall(CLIENT_BANNER)
        self.assertEqual(reader.exact(len(CLIENT_BANNER)), CLIENT_BANNER)

    def test_other_destinations_are_rejected_before_opening_backend(self):
        for target in ("127.0.0.1:1", "localhost.example.com:22", "203.0.113.1:22"):
            with self.subTest(target=target):
                client, reader = self.connect()
                client.sendall(f"GET / HTTP/1.1\r\nX-Real-Host: {target}\r\n\r\n".encode())
                self.assertTrue(reader.until(b"\r\n\r\n").startswith(b"HTTP/1.1 403 Forbidden\r\n"))
        self.assertEqual(self.backend.connections, 0)

    def test_failed_ssh_connection_returns_502_instead_of_false_success(self):
        with socket.socket() as unavailable:
            unavailable.bind(("127.0.0.1", 0))
            port = self.start_bridge(backend_port=unavailable.getsockname()[1])
            client, reader = self.connect(port)
            client.sendall(b"GET / HTTP/1.1\r\n\r\n")
            self.assertTrue(reader.until(b"\r\n\r\n").startswith(b"HTTP/1.1 502 Bad Gateway\r\n"))

    def test_oversized_and_malformed_headers_do_not_open_backend(self):
        for request, status in ((b"GET / HTTP/1.1\r\nBrokenHeader\r\n\r\n", 400),
                                (b"GET / HTTP/1.1\r\nX-Long: " + b"x" * 65512, 431)):
            with self.subTest(status=status):
                client, reader = self.connect()
                client.sendall(request)
                self.assertTrue(reader.until(b"\r\n\r\n").startswith(f"HTTP/1.1 {status} ".encode()))
        self.assertEqual(self.backend.connections, 0)

    def test_generated_runtime_matches_source_and_serves_http_payload(self):
        generated = self.root / "generated-bridge.py"
        result = subprocess.run(
            ["bash", "-c", f"source {shlex.quote(str(MENU))} --source-only; "
             f"WS_SSH_BRIDGE_SCRIPT={shlex.quote(str(generated))}; write_ws_ssh_bridge_script"],
            text=True, capture_output=True, check=False,
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(generated.read_bytes(), BRIDGE.read_bytes())
        client, reader = self.connect(self.start_bridge(script=generated))
        client.sendall(b"GET / HTTP/1.1\r\nX-Split: 1\r\n\r\n" + CLIENT_BANNER)
        self.assert_upgrade(reader)
        self.assertEqual(reader.exact(len(CLIENT_BANNER)), CLIENT_BANNER)


class BridgeDeploymentTests(unittest.TestCase):
    def test_client_details_show_payload_port_target_and_branding(self):
        result = subprocess.run(
            ["bash", "-c", f'''
            source {shlex.quote(str(MENU))} --source-only
            clear() {{ :; }}
            show_banner() {{ :; }}
            curl() {{ printf '203.0.113.1\n'; }}
            detect_preferred_host() {{ printf 'ssh.example.com\n'; }}
            systemctl() {{ [[ "$*" == 'is-active --quiet haproxy' ]]; }}
            EDGE_PUBLIC_HTTP_PORT=2080
            generate_client_config testuser testpass
            '''], text=True, capture_output=True, check=False,
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("HTTP Payload / WS", result.stdout)
        self.assertIn("2080", result.stdout)
        self.assertIn("127.0.0.1:22 (X-Real-Host)", result.stdout)
        self.assertIn("101 Script By: tuhinbro.com", result.stdout)

    def test_failed_python_validation_keeps_previous_bridge(self):
        with tempfile.TemporaryDirectory() as temp:
            runtime = Path(temp) / "bridge.py"
            runtime.write_text("# previous bridge\n")
            result = subprocess.run(
                ["bash", "-c", f'''
                source {shlex.quote(str(MENU))} --source-only
                WS_SSH_BRIDGE_SCRIPT={runtime}
                python3() {{ return 1; }}
                write_ws_ssh_bridge_script
                '''], text=True, capture_output=True, check=False,
            )
            self.assertNotEqual(result.returncode, 0)
            self.assertEqual(runtime.read_text(), "# previous bridge\n")
            self.assertEqual(list(Path(temp).iterdir()), [runtime])

    def test_refresh_preserves_running_state_and_rolls_back_a_failed_restart(self):
        for active, fail in ((True, False), (False, False), (True, True)):
            with self.subTest(active=active, fail=fail), tempfile.TemporaryDirectory() as temp:
                root = Path(temp)
                runtime = root / "bridge.py"
                service = root / "bridge.service"
                calls = root / "calls"
                runtime.write_text("# previous bridge\n")
                service.write_text("# previous service\n")
                result = subprocess.run(
                    ["bash", "-c", f'''
                    source {shlex.quote(str(MENU))} --source-only
                    WS_SSH_BRIDGE_SCRIPT={runtime}
                    WS_SSH_BRIDGE_SERVICE={service}
                    running={str(active).lower()}
                    fail_new={str(fail).lower()}
                    sleep() {{ :; }}
                    systemctl() {{
                        printf '%s\n' "$*" >> {calls}
                        case "$1" in
                            is-active) $running ;;
                            restart)
                                if $fail_new && grep -Fq 'bridge v3.' "$WS_SSH_BRIDGE_SCRIPT"; then
                                    running=false; return 1
                                fi
                                running=true ;;
                        esac
                    }}
                    refresh_ws_ssh_bridge_runtime
                    rc=$?
                    (( rc == {1 if fail else 0} )) || exit 21
                    if (( rc == 0 )); then refresh_ws_ssh_bridge_runtime || exit 22; fi
                    '''], text=True, capture_output=True, check=False,
                )
                self.assertEqual(result.returncode, 0, result.stderr)
                recorded = calls.read_text()
                self.assertNotIn("enable", recorded)
                if fail:
                    self.assertEqual(runtime.read_text(), "# previous bridge\n")
                    self.assertEqual(service.read_text(), "# previous service\n")
                    self.assertEqual(recorded.count("restart tdz-ws-ssh-bridge"), 2)
                else:
                    self.assertEqual(runtime.read_bytes(), BRIDGE.read_bytes())
                    self.assertIn("Script By: tuhinbro.com", service.read_text())
                    self.assertEqual(recorded.count("restart tdz-ws-ssh-bridge"), int(active))


if __name__ == "__main__":
    unittest.main()
