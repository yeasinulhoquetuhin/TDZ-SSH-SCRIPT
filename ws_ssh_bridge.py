#!/usr/bin/env python3
"""TDZ SSH TUNNEL WebSocket-to-SSH Bridge v2 (with branding support)."""
import socket, select, threading, sys, os, signal, time

LISTEN_HOST = os.environ.get("TDZ_WS_BRIDGE_HOST", "127.0.0.1")
LISTEN_PORT = int(os.environ.get("TDZ_WS_BRIDGE_PORT", "8890"))
SSH_HOST    = os.environ.get("TDZ_WS_BRIDGE_SSH_HOST", "127.0.0.1")
SSH_PORT    = int(os.environ.get("TDZ_WS_BRIDGE_SSH_PORT", "22"))
BRANDING_FILE = os.environ.get("TDZ_WS_BRIDGE_BRANDING", "/etc/tdztunnel/ws_branding.conf")

SWITCHING_RESPONSE_BASE = (
b'HTTP/1.1 101 <b><font color="red" size="7">Script By:</font> <font color="#0057B7" size="7">tuhinbro.com</font></b>\r\n'
b"Upgrade: websocket\r\n"
b"Connection: Upgrade\r\n"
)
MAX_HEADER_BYTES = 65536
RECV_CHUNK = 65536
BRANDING_CACHE_TTL = 30
# Tuned for stability over mobile / carrier-grade NAT (BD, SG, etc.)
#   - HANDSHAKE_TIMEOUT: increased from 10s to 30s for slow mobile handshakes
#   - SSH_CONNECT_TIMEOUT: increased from 5s to 10s
#   - BRIDGE_IDLE_TIMEOUT: reduced from 300s to 60s so dead peers are detected
#     faster. Combined with SO_KEEPALIVE (60s idle, 10s interval, 3 probes),
#     a silently-dropped connection is reaped within ~90s instead of staying
#     half-open for 5 minutes.
HANDSHAKE_TIMEOUT = 30
SSH_CONNECT_TIMEOUT = 10
BRIDGE_IDLE_TIMEOUT = 60
# TCP keepalive parameters (Linux specific) - fights NAT idle eviction
KEEPALIVE_IDLE = 60     # send first keepalive probe after 60s idle
KEEPALIVE_INTERVAL = 10 # then probe every 10s
KEEPALIVE_COUNT = 3     # after 3 failed probes (~90s), declare dead

_branding_cache = {"bytes": b"", "mtime": 0, "ts": 0}

def log(m):
    sys.stderr.write(f"[tdz-ws-bridge] {m}\n"); sys.stderr.flush()

def set_tcp_keepalive(sock):
    """Enable SO_KEEPALIVE + aggressive TCP_KEEPIDLE/INTVL/CNT.
    Critical for mobile/CGNAT environments where idle TCP connections get
    silently dropped by carrier NAT after ~5 minutes of inactivity.
    Without this, the tunnel "times out" periodically even though the
    server itself is fine."""
    try:
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
    except OSError:
        return
    if hasattr(socket, "TCP_KEEPIDLE"):
        try: sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, KEEPALIVE_IDLE)
        except OSError: pass
    if hasattr(socket, "TCP_KEEPINTVL"):
        try: sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, KEEPALIVE_INTERVAL)
        except OSError: pass
    if hasattr(socket, "TCP_KEEPCNT"):
        try: sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, KEEPALIVE_COUNT)
        except OSError: pass

def set_nodelay(sock):
    """Disable Nagle's algorithm so small SSH packets are not buffered.
    Without this, interactive SSH feels laggy / stalls."""
    try: sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
    except OSError: pass

def load_branding_headers():
    now = time.time()
    try:
        st = os.stat(BRANDING_FILE)
    except (OSError, FileNotFoundError):
        _branding_cache["bytes"] = b""
        _branding_cache["mtime"] = 0
        _branding_cache["ts"] = now
        return b""
    if (now - _branding_cache["ts"] < BRANDING_CACHE_TTL
            and st.st_mtime == _branding_cache["mtime"]
            and _branding_cache["bytes"] is not None):
        return _branding_cache["bytes"]
    extra = []
    try:
        with open(BRANDING_FILE, "r", encoding="utf-8", errors="replace") as f:
            for line in f:
                line = line.rstrip("\r\n")
                if not line or line.lstrip().startswith("#"): continue
                if ":" not in line: continue
                if "\r" in line or "\n" in line: continue
                extra.append(line)
    except OSError:
        extra = []
    raw = "".join(h + "\r\n" for h in extra).encode("utf-8", errors="replace")
    _branding_cache["bytes"] = raw
    _branding_cache["mtime"] = st.st_mtime
    _branding_cache["ts"] = now
    return raw

def build_switching_response():
    return SWITCHING_RESPONSE_BASE + load_branding_headers() + b"\r\n"

def bridge_socks(c, s):
    # Apply stability options to BOTH sockets — previously only the client
    # socket had TCP_NODELAY, which caused Nagle buffering on the SSH→client
    # path and produced visible stalls on interactive SSH.
    set_nodelay(c)
    set_nodelay(s)
    set_tcp_keepalive(c)
    set_tcp_keepalive(s)
    socks = [c, s]
    try:
        while True:
            # Shorter idle timeout so dead peers are detected within ~90s
            # (60s select + ~30s keepalive probes) instead of being held open
            # for 5+ minutes as half-open sockets.
            r, _, _ = select.select(socks, [], [], BRIDGE_IDLE_TIMEOUT)
            if not r:
                # Idle cycle — rely on TCP keepalive to detect dead peers.
                # If keepalive has killed the socket, recv() on next loop
                # will return empty and we exit cleanly.
                continue
            for sock in r:
                try: data = sock.recv(RECV_CHUNK)
                except OSError: return
                if not data: return
                other = s if sock is c else c
                try: other.sendall(data)
                except OSError: return
    finally:
        for sock in (c, s):
            try: sock.shutdown(socket.SHUT_RDWR)
            except OSError: pass
            try: sock.close()
            except OSError: pass

def handle(client, addr):
    try:
        # Increased handshake timeout: mobile networks (especially on first
        # TLS+WS handshake through HAProxy) can take 15-25s on slow links.
        client.settimeout(HANDSHAKE_TIMEOUT)
        buf = b""
        while b"\r\n\r\n" not in buf and len(buf) < MAX_HEADER_BYTES:
            try: chunk = client.recv(4096)
            except socket.timeout: return
            if not chunk: return
            buf += chunk
        if buf.startswith(b"SSH-"):
            client.settimeout(None)
            try: ssh = socket.create_connection((SSH_HOST, SSH_PORT), timeout=SSH_CONNECT_TIMEOUT)
            except Exception as e: log(f"ssh connect fail: {e}"); return
            ssh.sendall(buf)
            bridge_socks(client, ssh); return
        try: client.sendall(build_switching_response())
        except OSError: return
        try: ssh = socket.create_connection((SSH_HOST, SSH_PORT), timeout=SSH_CONNECT_TIMEOUT)
        except Exception as e: log(f"ssh connect fail: {e}"); return
        client.settimeout(None)
        log(f"bridged {addr[0]}:{addr[1]} -> SSH {SSH_HOST}:{SSH_PORT}")
        bridge_socks(client, ssh)
    except Exception as e:
        log(f"err {addr}: {e}")
    finally:
        try: client.close()
        except OSError: pass

def main():
    log(f"starting on {LISTEN_HOST}:{LISTEN_PORT} -> SSH {SSH_HOST}:{SSH_PORT}")
    log(f"branding file: {BRANDING_FILE}")
    srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    try: srv.bind((LISTEN_HOST, LISTEN_PORT))
    except OSError as e: log(f"FATAL bind: {e}"); sys.exit(1)
    srv.listen(128); log("listening")
    def stop(*_):
        try: srv.close()
        except: pass
        sys.exit(0)
    signal.signal(signal.SIGTERM, stop); signal.signal(signal.SIGINT, stop)
    while True:
        try: c, a = srv.accept()
        except OSError: break
        # TCP_NODELAY on accepted client socket (keepalive set in bridge_socks)
        c.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
        threading.Thread(target=handle, args=(c, a), daemon=True).start()

if __name__ == "__main__": main()
