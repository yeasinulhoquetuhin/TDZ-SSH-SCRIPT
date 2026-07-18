#!/usr/bin/env python3

import base64
import hashlib
import http.client
import os
import socket
import ssl
import struct
import subprocess
import tempfile
import threading
import time
import unittest
from pathlib import Path


REPO = Path(__file__).resolve().parents[1]
GATEWAY = REPO / "tdz_openvpn_gateway.py"
PORTAL = REPO / "tdz_openvpn_portal.py"


def free_port() -> int:
    with socket.socket() as sock:
        sock.bind(("127.0.0.1", 0))
        return sock.getsockname()[1]


def wait_port(port: int, timeout=5.0) -> None:
    deadline = time.monotonic() + timeout
    while time.monotonic() < deadline:
        try:
            with socket.create_connection(("127.0.0.1", port), timeout=0.2):
                return
        except OSError:
            time.sleep(0.05)
    raise AssertionError(f"port {port} did not open")


class EchoServer:
    def __init__(self):
        self.port = free_port()
        self.stop = threading.Event()
        self.thread = threading.Thread(target=self.run, daemon=True)

    def __enter__(self):
        self.thread.start()
        wait_port(self.port)
        return self

    def __exit__(self, *_args):
        self.stop.set()
        try:
            socket.create_connection(("127.0.0.1", self.port), timeout=0.2).close()
        except OSError:
            pass
        self.thread.join(timeout=2)

    def run(self):
        with socket.socket() as server:
            server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
            server.bind(("127.0.0.1", self.port))
            server.listen()
            server.settimeout(0.2)
            while not self.stop.is_set():
                try:
                    client, _ = server.accept()
                except socket.timeout:
                    continue
                threading.Thread(target=self.echo, args=(client,), daemon=True).start()

    @staticmethod
    def echo(client):
        with client:
            while True:
                data = client.recv(65536)
                if not data:
                    return
                client.sendall(data)


class ProcessCase(unittest.TestCase):
    def setUp(self):
        self.processes = []

    def tearDown(self):
        for process in self.processes:
            process.terminate()
            try:
                process.wait(timeout=3)
            except subprocess.TimeoutExpired:
                process.kill()
                process.wait(timeout=3)

    def start(self, *command):
        process = subprocess.Popen(
            command,
            stdout=subprocess.DEVNULL,
            stderr=subprocess.DEVNULL,
        )
        self.processes.append(process)
        return process


class GatewayTests(ProcessCase):
    def start_gateway(self, backend_port: int) -> int:
        port = free_port()
        self.start(
            str(GATEWAY),
            "--listen",
            "127.0.0.1",
            "--port",
            str(port),
            "--backend-port",
            str(backend_port),
            "--mode",
            "http",
        )
        wait_port(port)
        return port

    def test_http_connect_is_a_fixed_backend_tunnel(self):
        with EchoServer() as backend:
            port = self.start_gateway(backend.port)
            with socket.create_connection(("127.0.0.1", port), timeout=3) as client:
                client.sendall(b"CONNECT ignored.example:9999 HTTP/1.1\r\nHost: ignored\r\n\r\n")
                response = client.recv(4096)
                self.assertIn(b"200 Connection Established", response)
                client.sendall(b"openvpn-bytes")
                self.assertEqual(client.recv(13), b"openvpn-bytes")

    def test_real_websocket_frames_are_relayed(self):
        with EchoServer() as backend:
            port = self.start_gateway(backend.port)
            key = base64.b64encode(os.urandom(16)).decode()
            with socket.create_connection(("127.0.0.1", port), timeout=3) as client:
                request = (
                    "GET / HTTP/1.1\r\nHost: vpn.example\r\nUpgrade: websocket\r\n"
                    f"Connection: Upgrade\r\nSec-WebSocket-Key: {key}\r\n"
                    "Sec-WebSocket-Version: 13\r\n\r\n"
                )
                client.sendall(request.encode())
                response = client.recv(4096)
                expected = base64.b64encode(
                    hashlib.sha1((key + "258EAFA5-E914-47DA-95CA-C5AB0DC85B11").encode()).digest()
                )
                self.assertIn(b"101 Switching Protocols", response)
                self.assertIn(expected, response)

                payload = b"vpn"
                mask = b"\x01\x02\x03\x04"
                masked = bytes(value ^ mask[index % 4] for index, value in enumerate(payload))
                client.sendall(bytes((0x82, 0x80 | len(payload))) + mask + masked)
                first, length = client.recv(2)
                self.assertEqual(first, 0x82)
                self.assertEqual(length, len(payload))
                self.assertEqual(client.recv(length), payload)

    def test_raw_ssl_gateway_relays_encrypted_transport(self):
        with EchoServer() as backend, tempfile.TemporaryDirectory() as temp:
            cert = Path(temp) / "gateway.crt"
            key = Path(temp) / "gateway.key"
            generated = subprocess.run(
                [
                    "openssl",
                    "req",
                    "-x509",
                    "-newkey",
                    "rsa:2048",
                    "-nodes",
                    "-days",
                    "1",
                    "-subj",
                    "/CN=vpn.example",
                    "-keyout",
                    str(key),
                    "-out",
                    str(cert),
                ],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                check=False,
            )
            self.assertEqual(generated.returncode, 0)
            port = free_port()
            self.start(
                str(GATEWAY),
                "--listen",
                "127.0.0.1",
                "--port",
                str(port),
                "--backend-port",
                str(backend.port),
                "--mode",
                "raw",
                "--tls-cert",
                str(cert),
                "--tls-key",
                str(key),
            )
            wait_port(port)
            context = ssl.create_default_context()
            context.check_hostname = False
            context.verify_mode = ssl.CERT_NONE
            with socket.create_connection(("127.0.0.1", port), timeout=3) as plain:
                with context.wrap_socket(plain, server_hostname="vpn.example") as client:
                    self.assertGreaterEqual(client.version(), "TLSv1.2")
                    client.sendall(b"ssl-openvpn-bytes")
                    self.assertEqual(client.recv(17), b"ssl-openvpn-bytes")


class PortalTests(ProcessCase):
    def test_portal_serves_only_the_public_prefix(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            public = root / "ovpn-configs"
            public.mkdir()
            (public / "index.html").write_text("TDZ portal")
            (public / "client.ovpn").write_text("client\n")
            (public / ".secret").write_text("hidden")
            (root / "outside.ovpn").write_text("must not be served\n")
            (public / "linked.ovpn").symlink_to(root / "outside.ovpn")
            linked_directory = public / "linked-directory"
            linked_directory.mkdir()
            (linked_directory / "index.html").symlink_to(root / "outside.ovpn")
            port = free_port()
            self.start(
                str(PORTAL), "--listen", "127.0.0.1", "--port", str(port), "--root", str(root)
            )
            wait_port(port)

            connection = http.client.HTTPConnection("127.0.0.1", port, timeout=3)
            connection.request("GET", "/ovpn-configs/")
            response = connection.getresponse()
            self.assertEqual(response.status, 200)
            self.assertEqual(response.read(), b"TDZ portal")
            self.assertEqual(response.getheader("X-Content-Type-Options"), "nosniff")

            connection.request("GET", "/ovpn-configs/client.ovpn")
            profile = connection.getresponse()
            self.assertEqual(profile.status, 200)
            self.assertIn("attachment", profile.getheader("Content-Disposition"))
            profile.read()

            for path in (
                "/etc/passwd",
                "/ovpn-configs/.secret",
                "/ovpn-configs/../.secret",
                "/ovpn-configs/linked.ovpn",
                "/ovpn-configs/linked-directory/",
            ):
                connection.request("GET", path)
                denied = connection.getresponse()
                self.assertEqual(denied.status, 404)
                denied.read()
            connection.close()


if __name__ == "__main__":
    unittest.main()
