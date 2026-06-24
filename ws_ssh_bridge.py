#!/usr/bin/env python3
"""
TDZ TUNNEL Manager — WebSocket-to-SSH Bridge
=============================================
Listens on 127.0.0.1:8890 (or any port). For each incoming connection:
  1. Read the HTTP request line + headers (until \r\n\r\n)
  2. Reply with HTTP/1.1 101 Switching Protocols
  3. Connect to SSH (127.0.0.1:22) and bridge raw TCP bidirectionally

This is what DarkTunnel / HTTP Custom / NPV / NapsternetV etc. expect when
they send a payload like:
  GET wss://[cf] HTTP/1.1[crlf]Host: telegram.org[crlf]
  User-Agent: [ua][crlf]Connection: Upgrade[crlf]Upgrade: websocket[crlf][crlf]

The "wss://" scheme and absolute-URI form confuse nginx (returns 400).
This bridge accepts ANY HTTP-like request without strict validation.
"""

import socket
import select
import threading
import sys
import os
import signal

LISTEN_HOST = os.environ.get("TDZ_WS_BRIDGE_HOST", "127.0.0.1")
LISTEN_PORT = int(os.environ.get("TDZ_WS_BRIDGE_PORT", "8890"))
SSH_HOST    = os.environ.get("TDZ_WS_BRIDGE_SSH_HOST", "127.0.0.1")
SSH_PORT    = int(os.environ.get("TDZ_WS_BRIDGE_SSH_PORT", "22"))

# Response sent back to client — this is what DarkTunnel expects
SWITCHING_RESPONSE = (
    b"HTTP/1.1 101 Switching Protocols\r\n"
    b"Upgrade: websocket\r\n"
    b"Connection: Upgrade\r\n"
    b"\r\n"
)

MAX_HEADER_BYTES = 65536  # max we'll read while waiting for \r\n\r\n
RECV_CHUNK = 65536

def log(msg):
    sys.stderr.write(f"[tdz-ws-bridge] {msg}\n")
    sys.stderr.flush()

def bridge_sockets(client_sock, ssh_sock):
    """Bidirectionally bridge two sockets until either closes."""
    socks = [client_sock, ssh_sock]
    try:
        while True:
            r, _, _ = select.select(socks, [], [], 300)
            if not r:
                # 5 min idle — keep alive
                continue
            for s in r:
                try:
                    data = s.recv(RECV_CHUNK)
                except (ConnectionResetError, OSError):
                    return
                if not data:
                    return
                other = ssh_sock if s is client_sock else client_sock
                try:
                    other.sendall(data)
                except (ConnectionResetError, OSError):
                    return
    finally:
        for s in (client_sock, ssh_sock):
            try: s.shutdown(socket.SHUT_RDWR)
            except: pass
            try: s.close()
            except: pass

def handle_client(client_sock, client_addr):
    try:
        client_sock.settimeout(10)
        buf = b""
        # Read until end of HTTP headers (\r\n\r\n)
        while b"\r\n\r\n" not in buf and len(buf) < MAX_HEADER_BYTES:
            try:
                chunk = client_sock.recv(4096)
            except socket.timeout:
                log(f"timeout reading headers from {client_addr}")
                return
            if not chunk:
                log(f"client closed before headers from {client_addr}")
                return
            buf += chunk

        # If first bytes look like raw SSH (SSH-2.0-...), skip the 101 response
        # — this lets the same port also accept direct SSH clients.
        if buf.startswith(b"SSH-"):
            # Raw SSH client — bridge directly without 101
            client_sock.settimeout(None)
            try:
                ssh_sock = socket.create_connection((SSH_HOST, SSH_PORT), timeout=5)
            except Exception as e:
                log(f"failed to connect to SSH for {client_addr}: {e}")
                return
            # Push the already-read SSH banner back to SSH server
            ssh_sock.sendall(buf)
            bridge_sockets(client_sock, ssh_sock)
            return

        # Otherwise: it's an HTTP/WS upgrade request — send 101
        try:
            client_sock.sendall(SWITCHING_RESPONSE)
        except OSError as e:
            log(f"failed to send 101 to {client_addr}: {e}")
            return

        # Connect to SSH
        try:
            ssh_sock = socket.create_connection((SSH_HOST, SSH_PORT), timeout=5)
        except Exception as e:
            log(f"failed to connect to SSH for {client_addr}: {e}")
            return

        client_sock.settimeout(None)
        log(f"bridged {client_addr[0]}:{client_addr[1]} -> SSH {SSH_HOST}:{SSH_PORT}")
        bridge_sockets(client_sock, ssh_sock)
    except Exception as e:
        log(f"error handling {client_addr}: {e}")
    finally:
        try: client_sock.close()
        except: pass

def main():
    log(f"starting on {LISTEN_HOST}:{LISTEN_PORT} -> SSH {SSH_HOST}:{SSH_PORT}")
    srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    try:
        srv.bind((LISTEN_HOST, LISTEN_PORT))
    except OSError as e:
        log(f"FATAL: cannot bind {LISTEN_HOST}:{LISTEN_PORT}: {e}")
        sys.exit(1)
    srv.listen(128)
    log("listening")

    def sigterm(*_):
        log("SIGTERM received, shutting down")
        try: srv.close()
        except: pass
        sys.exit(0)

    signal.signal(signal.SIGTERM, sigterm)
    signal.signal(signal.SIGINT, sigterm)

    while True:
        try:
            client_sock, client_addr = srv.accept()
        except OSError:
            break
        client_sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
        t = threading.Thread(target=handle_client, args=(client_sock, client_addr), daemon=True)
        t.start()

if __name__ == "__main__":
    main()
