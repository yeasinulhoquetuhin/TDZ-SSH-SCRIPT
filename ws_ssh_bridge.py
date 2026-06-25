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
# RECV_CHUNK increased from 64KB -> 1MB. Each recv() syscall in Python has
# ~10-50μs overhead. At 64KB chunks, a 50Mbps stream needs ~100 syscalls/sec
# per direction = 200 syscalls/sec = 2-10ms of pure Python overhead per second.
# At 1MB chunks, that drops to ~6 syscalls/sec per direction. Massive win for
# speed tests and large downloads.
RECV_CHUNK = 1024 * 1024  # 1 MB
# Kernel socket buffers. Default Linux SO_RCVBUF is ~200KB which is WAY too
# small for high-BDP paths (BD <-> SG at 80ms RTT × 100Mbps = 1MB BDP).
# Without bigger buffers, the kernel throttles the sender via TCP window
# scale, capping throughput at ~20-30 Mbps even when both ends could go faster.
# 4MB lets the kernel buffer ~40MB of in-flight data per direction.
SOCKET_BUF_SIZE = 4 * 1024 * 1024  # 4 MB
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

def set_large_buffers(sock):
    """Set SO_RCVBUF and SO_SNDBUF to SOCKET_BUF_SIZE (4MB).
    Default Linux socket buffers (~200KB) cap throughput at ~20-30 Mbps
    on long-RTT paths due to TCP window size limits. 4MB buffers let the
    kernel sustain ~400 Mbps over a 80ms RTT path."""
    try: sock.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, SOCKET_BUF_SIZE)
    except OSError: pass
    try: sock.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, SOCKET_BUF_SIZE)
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
    """High-throughput bidirectional TCP bridge.
    Optimizations vs. naive version:
      - TCP_NODELAY on BOTH sockets (was client-only)
      - SO_KEEPALIVE + aggressive TCP_KEEPIDLE/INTVL/CNT on both
      - SO_RCVBUF/SO_SNDBUF 4MB on both (was kernel default ~200KB)
      - Pre-allocated 1MB bytearrays with recv_into() (was recv() allocating
        a new bytes object every call — ~10μs GC pressure per call × 100+ Hz
        = several % of CPU wasted on allocation alone)
      - sendall() is CPython-optimized internally; kept as-is.
    """
    set_nodelay(c)
    set_nodelay(s)
    set_tcp_keepalive(c)
    set_tcp_keepalive(s)
    set_large_buffers(c)
    set_large_buffers(s)
    # Pre-allocate recv buffers ONCE per connection, reuse across iterations.
    # Avoids ~10μs of allocation + GC per recv() call. At 100 Hz recv rate
    # that's 1ms/sec saved — sounds small but adds up under load.
    c_buf = bytearray(RECV_CHUNK)
    s_buf = bytearray(RECV_CHUNK)
    socks = [c, s]
    try:
        while True:
            r, _, _ = select.select(socks, [], [], BRIDGE_IDLE_TIMEOUT)
            if not r:
                # Idle cycle — keepalive will detect dead peers.
                # recv() on next loop will return empty if socket died.
                continue
            for sock in r:
                other = s if sock is c else c
                buf = c_buf if sock is c else s_buf
                try:
                    n = sock.recv_into(buf, RECV_CHUNK)
                except OSError:
                    return
                if not n:
                    return
                try:
                    # sendall with memoryview of exactly the bytes we got —
                    # avoids creating a sliced copy.
                    other.sendall(memoryview(buf)[:n])
                except OSError:
                    return
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
        # Apply all stability + throughput socket options on accepted socket.
        # (keepalive + nodelay + large buffers — bridge_socks re-applies
        # them too, but setting them early means even the handshake benefits
        # from large buffers.)
        c.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
        try: c.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, SOCKET_BUF_SIZE)
        except OSError: pass
        try: c.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, SOCKET_BUF_SIZE)
        except OSError: pass
        threading.Thread(target=handle, args=(c, a), daemon=True).start()

if __name__ == "__main__": main()
