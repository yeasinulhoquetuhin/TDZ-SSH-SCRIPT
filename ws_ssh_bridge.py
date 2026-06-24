#!/usr/bin/env python3
"""
TDZ TUNNEL Manager — WebSocket-to-SSH Bridge  (v2 with branding)
=================================================================
Listens on 127.0.0.1:8890. For each incoming connection:
  1. Read the HTTP request line + headers (until \\r\\n\\r\\n)
  2. Reply with HTTP/1.1 101 Switching Protocols
       + optional custom headers loaded from /etc/tdztunnel/ws_branding.conf
  3. Connect to SSH (127.0.0.1:22) and bridge raw TCP bidirectionally

This is what DarkTunnel / HTTP Custom / NPV / NapsternetV etc. expect when
they send a payload like:
  GET wss://[cf] HTTP/1.1[crlf]Host: telegram.org[crlf]
  User-Agent: [ua][crlf]Connection: Upgrade[crlf]Upgrade: websocket[crlf][crlf]

The "wss://" scheme and absolute-URI form confuse nginx (returns 400).
This bridge accepts ANY HTTP-like request without strict validation.

Branding config file format (/etc/tdztunnel/ws_branding.conf):
  Plain text file. Each non-empty, non-comment line becomes a custom HTTP
  header added to the 101 response. Examples:
    X-Powered-By: VPS BY @TuhinBroh
    X-Owner: Tuhin
    X-Telegram: @TuhinBroh
  If the file does not exist or is empty, only the standard 101 headers are
  sent. Lines starting with '#' are ignored.
"""

import socket
import select
import threading
import sys
import os
import signal
import time

LISTEN_HOST = os.environ.get("TDZ_WS_BRIDGE_HOST", "127.0.0.1")
LISTEN_PORT = int(os.environ.get("TDZ_WS_BRIDGE_PORT", "8890"))
SSH_HOST    = os.environ.get("TDZ_WS_BRIDGE_SSH_HOST", "127.0.0.1")
SSH_PORT    = int(os.environ.get("TDZ_WS_BRIDGE_SSH_PORT", "22"))

BRANDING_FILE = os.environ.get("TDZ_WS_BRIDGE_BRANDING", "/etc/tdztunnel/ws_branding.conf")

# Standard 101 response — protocol-required headers
SWITCHING_RESPONSE_BASE = (
    b"HTTP/1.1 101 Switching Protocols\r\n"
    b"Upgrade: websocket\r\n"
    b"Connection: Upgrade\r\n"
)

MAX_HEADER_BYTES = 65536
RECV_CHUNK = 65536
BRANDING_CACHE_TTL = 30  # seconds — re-read branding file this often

_branding_cache = {"bytes": b"", "mtime": 0, "ts": 0}

def log(msg):
    sys.stderr.write(f"[tdz-ws-bridge] {msg}\n")
    sys.stderr.flush()

def load_branding_headers():
    """Read /etc/tdztunnel/ws_branding.conf and return raw header bytes.
    Cached for BRANDING_CACHE_TTL seconds OR until file mtime changes."""
    now = time.time()
    try:
        st = os.stat(BRANDING_FILE)
    except (OSError, FileNotFoundError):
        _branding_cache["bytes"] = b""
        _branding_cache["mtime"] = 0
        _branding_cache["ts"] = now
        return b""

    # Re-read if cache expired or file changed
    if (now - _branding_cache["ts"] < BRANDING_CACHE_TTL
            and st.st_mtime == _branding_cache["mtime"]
            and _branding_cache["bytes"] is not None):
        return _branding_cache["bytes"]

    extra = []
    try:
        with open(BRANDING_FILE, "r", encoding="utf-8", errors="replace") as f:
            for line in f:
                line = line.rstrip("\r\n")
                if not line or line.lstrip().startswith("#"):
                    continue
                # Validate: must look like "Header-Name: value"
                if ":" not in line:
                    continue
                # No CR/LF inside (would break HTTP framing)
                if "\r" in line or "\n" in line:
                    continue
                extra.append(line)
    except OSError:
        extra = []

    raw = "".join(h + "\r\n" for h in extra).encode("utf-8", errors="replace")
    _branding_cache["bytes"] = raw
    _branding_cache["mtime"] = st.st_mtime
    _branding_cache["ts"] = now
    return raw

def build_switching_response():
    """Build the full 101 response: base headers + custom branding + blank line."""
    return SWITCHING_RESPONSE_BASE + load_branding_headers() + b"\r\n"

def bridge_socks(c, s):
    """Bidirectionally bridge two sockets until either closes."""
    socks = [c, s]
    try:
        while True:
            r, _, _ = select.select(socks, [], [], 300)
            if not r:
                # 5 min idle — keep alive
                continue
            for sock in r:
                try:
                    data = sock.recv(RECV_CHUNK)
                except (ConnectionResetError, OSError):
                    return
                if not data:
                    return
                other = s if sock is c else c
                try:
                    other.sendall(data)
                except (ConnectionResetError, OSError):
                    return
    finally:
        for sock in (c, s):
            try: sock.shutdown(socket.SHUT_RDWR)
            except: pass
            try: sock.close()
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
            bridge_socks(client_sock, ssh_sock)
            return

        # Otherwise: it's an HTTP/WS upgrade request — send 101 (with branding)
        try:
            client_sock.sendall(build_switching_response())
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
        bridge_socks(client_sock, ssh_sock)
    except Exception as e:
        log(f"error handling {client_addr}: {e}")
    finally:
        try: client_sock.close()
        except: pass

def main():
    log(f"starting on {LISTEN_HOST}:{LISTEN_PORT} -> SSH {SSH_HOST}:{SSH_PORT}")
    log(f"branding file: {BRANDING_FILE}")
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
