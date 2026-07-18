#!/usr/bin/env python3
"""TDZ OpenVPN transport gateway.

The gateway exposes a fixed local OpenVPN TCP backend through one of three
frontends:

* HTTP CONNECT (works with stock OpenVPN HTTP proxy profiles)
* HTTP Upgrade / WebSocket (works with injector apps and real WS clients)
* raw TCP, optionally wrapped in TLS (for SSL-tunnel clients)

The destination is never taken from client input.  This is deliberate: the
service cannot be turned into an open proxy or used for SSRF.
"""

from __future__ import annotations

import argparse
import asyncio
import base64
import contextlib
import hashlib
import logging
import signal
import socket
import ssl
import struct
from dataclasses import dataclass
from typing import Dict, Optional, Tuple


LOG = logging.getLogger("tdz-openvpn-gateway")
MAX_HEADER_BYTES = 32 * 1024
COPY_BUFFER = 128 * 1024
WS_GUID = "258EAFA5-E914-47DA-95CA-C5AB0DC85B11"
HTTP_METHOD_PREFIXES = (b"GET ", b"POST ", b"HEAD ", b"OPTIONS ")


@dataclass(frozen=True)
class Settings:
    backend_host: str
    backend_port: int
    mode: str
    handshake_timeout: float
    max_clients: int


class BufferedStream:
    """Small read buffer used when bytes follow the HTTP headers."""

    def __init__(self, reader: asyncio.StreamReader, initial: bytes = b"") -> None:
        self.reader = reader
        self.buffer = bytearray(initial)

    async def readexactly(self, size: int) -> bytes:
        while len(self.buffer) < size:
            chunk = await self.reader.read(size - len(self.buffer))
            if not chunk:
                raise asyncio.IncompleteReadError(bytes(self.buffer), size)
            self.buffer.extend(chunk)
        result = bytes(self.buffer[:size])
        del self.buffer[:size]
        return result


def tune_socket(writer: asyncio.StreamWriter) -> None:
    sock = writer.get_extra_info("socket")
    if sock is None:
        return
    with contextlib.suppress(OSError):
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
    with contextlib.suppress(OSError):
        sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)


async def close_writer(writer: Optional[asyncio.StreamWriter]) -> None:
    if writer is None:
        return
    writer.close()
    with contextlib.suppress(Exception):
        await writer.wait_closed()


async def pipe(
    reader: asyncio.StreamReader,
    writer: asyncio.StreamWriter,
    initial: bytes = b"",
) -> None:
    if initial:
        writer.write(initial)
        await writer.drain()
    while True:
        chunk = await reader.read(COPY_BUFFER)
        if not chunk:
            return
        writer.write(chunk)
        await writer.drain()


async def relay_raw(
    client_reader: asyncio.StreamReader,
    client_writer: asyncio.StreamWriter,
    backend_reader: asyncio.StreamReader,
    backend_writer: asyncio.StreamWriter,
    initial_client_data: bytes = b"",
) -> None:
    to_backend = asyncio.create_task(
        pipe(client_reader, backend_writer, initial_client_data)
    )
    to_client = asyncio.create_task(pipe(backend_reader, client_writer))
    done, pending = await asyncio.wait(
        (to_backend, to_client), return_when=asyncio.FIRST_COMPLETED
    )
    for task in pending:
        task.cancel()
    for task in done | pending:
        with contextlib.suppress(asyncio.CancelledError, ConnectionError, OSError):
            await task


async def read_http_head(
    reader: asyncio.StreamReader, timeout: float, initial: bytes = b""
) -> Tuple[bytes, bytes]:
    data = bytearray(initial)
    deadline = asyncio.get_running_loop().time() + timeout
    while b"\r\n\r\n" not in data:
        remaining = deadline - asyncio.get_running_loop().time()
        if remaining <= 0:
            raise TimeoutError("HTTP handshake timed out")
        chunk = await asyncio.wait_for(reader.read(4096), timeout=remaining)
        if not chunk:
            raise ConnectionError("client closed during HTTP handshake")
        data.extend(chunk)
        if len(data) > MAX_HEADER_BYTES:
            raise ValueError("HTTP headers exceed limit")
    if data.index(b"\r\n\r\n") + 4 > MAX_HEADER_BYTES:
        raise ValueError("HTTP headers exceed limit")
    head, remainder = bytes(data).split(b"\r\n\r\n", 1)
    return head + b"\r\n\r\n", remainder


async def probe_nested_http_request(
    reader: asyncio.StreamReader,
    initial: bytes,
    timeout: float,
) -> Tuple[Optional[Tuple[bytes, bytes]], bytes]:
    """Distinguish raw OpenVPN bytes from an injector's second HTTP request.

    Several Android injector clients first establish an HTTP CONNECT tunnel and
    only then send their configured GET/Upgrade payload.  A stock OpenVPN HTTP
    proxy client sends binary OpenVPN data immediately after CONNECT instead.
    The small prefix probe supports both without trusting the CONNECT target.
    """

    data = bytearray(initial)
    deadline = asyncio.get_running_loop().time() + timeout
    while True:
        if any(data.startswith(prefix) for prefix in HTTP_METHOD_PREFIXES):
            head, remainder = await read_http_head(reader, timeout, bytes(data))
            return (head, remainder), b""
        if data and not any(prefix.startswith(data) for prefix in HTTP_METHOD_PREFIXES):
            return None, bytes(data)
        if len(data) >= max(len(prefix) for prefix in HTTP_METHOD_PREFIXES):
            return None, bytes(data)
        remaining = deadline - asyncio.get_running_loop().time()
        if remaining <= 0:
            return None, bytes(data)
        chunk = await asyncio.wait_for(reader.read(4096), timeout=remaining)
        if not chunk:
            return None, bytes(data)
        data.extend(chunk)


def parse_http_head(head: bytes) -> Tuple[str, str, str, Dict[str, str]]:
    text = head.decode("iso-8859-1", errors="strict")
    lines = text.split("\r\n")
    parts = lines[0].split(" ", 2)
    if len(parts) != 3:
        raise ValueError("invalid HTTP request line")
    method, target, version = parts
    if not version.startswith("HTTP/"):
        raise ValueError("invalid HTTP version")
    headers: Dict[str, str] = {}
    for line in lines[1:]:
        if not line:
            continue
        if ":" not in line:
            raise ValueError("invalid HTTP header")
        name, value = line.split(":", 1)
        headers[name.strip().lower()] = value.strip()
    return method.upper(), target, version, headers


def websocket_accept(key: str) -> str:
    try:
        decoded = base64.b64decode(key, validate=True)
    except Exception as exc:
        raise ValueError("invalid WebSocket key") from exc
    if len(decoded) != 16:
        raise ValueError("invalid WebSocket key length")
    digest = hashlib.sha1((key + WS_GUID).encode("ascii")).digest()
    return base64.b64encode(digest).decode("ascii")


def ws_frame(payload: bytes, opcode: int = 0x2) -> bytes:
    first = 0x80 | (opcode & 0x0F)
    length = len(payload)
    if length < 126:
        return bytes((first, length)) + payload
    if length <= 0xFFFF:
        return bytes((first, 126)) + struct.pack("!H", length) + payload
    return bytes((first, 127)) + struct.pack("!Q", length) + payload


async def probe_websocket_framing(
    reader: asyncio.StreamReader,
    initial: bytes,
    timeout: float,
) -> Tuple[bool, bytes]:
    """Detect whether bytes after a WebSocket handshake are RFC frames.

    Standards-compliant browser/WebSocket clients mask every client frame.
    Several Android injector apps still send ``Sec-WebSocket-Key`` in their
    payload but switch directly to a raw OpenVPN stream after the 101 reply.
    The two-byte frame prefix lets the gateway support both behaviours without
    selecting a mode from headers alone.
    """

    data = bytearray(initial)
    deadline = asyncio.get_running_loop().time() + timeout
    while len(data) < 2:
        remaining = deadline - asyncio.get_running_loop().time()
        if remaining <= 0:
            raise TimeoutError("WebSocket/OpenVPN data probe timed out")
        chunk = await asyncio.wait_for(reader.read(4096), timeout=remaining)
        if not chunk:
            raise ConnectionError("client closed before tunnel data")
        data.extend(chunk)

    first, second = data[0], data[1]
    opcode = first & 0x0F
    is_framed = (
        not (first & 0x70)
        # The first frame on a new tunnel cannot be a continuation. Requiring
        # FIN also avoids mistaking OpenVPN's two-byte TCP length prefix (for
        # example 00 e0) for a masked WebSocket frame.
        and bool(first & 0x80)
        and opcode in {0x1, 0x2, 0x8, 0x9, 0xA}
        and bool(second & 0x80)
    )
    return is_framed, bytes(data)


async def websocket_to_backend(
    client: BufferedStream,
    client_writer: asyncio.StreamWriter,
    backend_writer: asyncio.StreamWriter,
) -> None:
    while True:
        first, second = await client.readexactly(2)
        if first & 0x70:
            raise ValueError("unsupported WebSocket extension bits")
        opcode = first & 0x0F
        masked = bool(second & 0x80)
        if not masked:
            raise ValueError("client WebSocket frames must be masked")
        length = second & 0x7F
        if length == 126:
            length = struct.unpack("!H", await client.readexactly(2))[0]
        elif length == 127:
            length = struct.unpack("!Q", await client.readexactly(8))[0]
        if length > 16 * 1024 * 1024:
            raise ValueError("WebSocket frame is too large")
        if opcode >= 0x8 and (not (first & 0x80) or length > 125):
            raise ValueError("invalid WebSocket control frame")
        mask = await client.readexactly(4) if masked else b""
        payload = await client.readexactly(length)
        if masked:
            payload = bytes(value ^ mask[index % 4] for index, value in enumerate(payload))

        if opcode == 0x8:  # close
            client_writer.write(ws_frame(payload[:125], 0x8))
            await client_writer.drain()
            return
        if opcode == 0x9:  # ping
            client_writer.write(ws_frame(payload[:125], 0xA))
            await client_writer.drain()
            continue
        if opcode == 0xA:  # pong
            continue
        if opcode not in (0x0, 0x1, 0x2):
            raise ValueError("unsupported WebSocket opcode")
        if payload:
            backend_writer.write(payload)
            await backend_writer.drain()


async def backend_to_websocket(
    backend_reader: asyncio.StreamReader, client_writer: asyncio.StreamWriter
) -> None:
    while True:
        chunk = await backend_reader.read(64 * 1024)
        if not chunk:
            return
        client_writer.write(ws_frame(chunk))
        await client_writer.drain()


async def relay_websocket(
    client_reader: asyncio.StreamReader,
    client_writer: asyncio.StreamWriter,
    backend_reader: asyncio.StreamReader,
    backend_writer: asyncio.StreamWriter,
    initial: bytes,
) -> None:
    buffered = BufferedStream(client_reader, initial)
    to_backend = asyncio.create_task(
        websocket_to_backend(buffered, client_writer, backend_writer)
    )
    to_client = asyncio.create_task(
        backend_to_websocket(backend_reader, client_writer)
    )
    done, pending = await asyncio.wait(
        (to_backend, to_client), return_when=asyncio.FIRST_COMPLETED
    )
    for task in pending:
        task.cancel()
    for task in done | pending:
        with contextlib.suppress(asyncio.CancelledError, ConnectionError, OSError):
            await task


async def open_backend(settings: Settings) -> Tuple[asyncio.StreamReader, asyncio.StreamWriter]:
    reader, writer = await asyncio.wait_for(
        asyncio.open_connection(settings.backend_host, settings.backend_port),
        timeout=settings.handshake_timeout,
    )
    tune_socket(writer)
    return reader, writer


BRANDED_WS_STATUS = (
    "HTTP/1.1 101 <b><font color=\"red\" size=\"7\">Script By:</font> "
    "<font color=\"#0057B7\" size=\"7\">tuhinbro.com</font></b>\r\n"
)


async def relay_http_upgrade(
    head: bytes,
    remainder: bytes,
    client_reader: asyncio.StreamReader,
    client_writer: asyncio.StreamWriter,
    backend_reader: asyncio.StreamReader,
    backend_writer: asyncio.StreamWriter,
    probe_timeout: float,
) -> None:
    method, _target, _version, headers = parse_http_head(head)
    if method not in {"GET", "POST", "HEAD", "OPTIONS"}:
        raise ValueError("unsupported tunneled HTTP method")

    upgrade = headers.get("upgrade", "").lower()
    ws_key = headers.get("sec-websocket-key", "")
    if upgrade == "websocket" and ws_key:
        try:
            accept_value = websocket_accept(ws_key)
        except (UnicodeEncodeError, ValueError) as exc:
            raise ValueError("invalid WebSocket key") from exc
        response = (
            BRANDED_WS_STATUS
            + "Upgrade: websocket\r\n"
            + "Connection: Upgrade\r\n"
            + f"Sec-WebSocket-Accept: {accept_value}\r\n\r\n"
        )
        client_writer.write(response.encode("ascii"))
        await client_writer.drain()
        framed, buffered = await probe_websocket_framing(
            client_reader, remainder, probe_timeout
        )
        if framed:
            await relay_websocket(
                client_reader,
                client_writer,
                backend_reader,
                backend_writer,
                buffered,
            )
        else:
            # Injector compatibility: some apps request a standards-compliant
            # handshake but carry unframed OpenVPN bytes afterward.
            await relay_raw(
                client_reader,
                client_writer,
                backend_reader,
                backend_writer,
                buffered,
            )
        return

    # Injector-compatible HTTP Upgrade/raw payload mode.  The request target
    # and Host value are display/payload fields only; the backend stays fixed.
    status = (
        BRANDED_WS_STATUS.encode("ascii")
        + b"Connection: Upgrade\r\n"
        + b"Upgrade: websocket\r\n\r\n"
        if upgrade == "websocket"
        else b"HTTP/1.1 200 Connection Established\r\n\r\n"
    )
    client_writer.write(status)
    await client_writer.drain()
    await relay_raw(
        client_reader,
        client_writer,
        backend_reader,
        backend_writer,
        remainder,
    )


async def handle_http(
    client_reader: asyncio.StreamReader,
    client_writer: asyncio.StreamWriter,
    settings: Settings,
) -> None:
    head, remainder = await read_http_head(client_reader, settings.handshake_timeout)
    method, _target, _version, _headers = parse_http_head(head)
    backend_reader, backend_writer = await open_backend(settings)
    try:
        if method == "CONNECT":
            client_writer.write(
                b"HTTP/1.1 200 Connection Established\r\n"
                b"Proxy-Agent: TDZ-OpenVPN\r\n\r\n"
            )
            await client_writer.drain()
            nested, raw_data = await probe_nested_http_request(
                client_reader,
                remainder,
                settings.handshake_timeout,
            )
            if nested is not None:
                nested_head, nested_remainder = nested
                await relay_http_upgrade(
                    nested_head,
                    nested_remainder,
                    client_reader,
                    client_writer,
                    backend_reader,
                    backend_writer,
                    settings.handshake_timeout,
                )
                return
            await relay_raw(
                client_reader,
                client_writer,
                backend_reader,
                backend_writer,
                raw_data,
            )
            return

        await relay_http_upgrade(
            head,
            remainder,
            client_reader,
            client_writer,
            backend_reader,
            backend_writer,
            settings.handshake_timeout,
        )
    finally:
        await close_writer(backend_writer)


async def serve_client(
    client_reader: asyncio.StreamReader,
    client_writer: asyncio.StreamWriter,
    settings: Settings,
    semaphore: asyncio.Semaphore,
) -> None:
    peer = client_writer.get_extra_info("peername")
    tune_socket(client_writer)
    try:
        try:
            # Keep overload handling bounded. A plain acquire can queue an
            # unlimited number of sockets behind the active-session cap.
            await asyncio.wait_for(semaphore.acquire(), timeout=0.05)
        except TimeoutError:
            client_writer.write(
                b"HTTP/1.1 503 Service Unavailable\r\nConnection: close\r\n\r\n"
            )
            await client_writer.drain()
            return
        try:
            if settings.mode == "raw":
                backend_reader, backend_writer = await open_backend(settings)
                try:
                    await relay_raw(
                        client_reader, client_writer, backend_reader, backend_writer
                    )
                finally:
                    await close_writer(backend_writer)
            else:
                await handle_http(client_reader, client_writer, settings)
        finally:
            semaphore.release()
    except (asyncio.IncompleteReadError, ConnectionError, TimeoutError):
        pass
    except (ValueError, OSError, ssl.SSLError) as exc:
        LOG.warning("Rejected connection from %r: %s", peer, exc)
        with contextlib.suppress(Exception):
            client_writer.write(
                b"HTTP/1.1 400 Bad Request\r\nConnection: close\r\n\r\n"
            )
            await client_writer.drain()
    except Exception:
        LOG.exception("Unhandled gateway error for %r", peer)
    finally:
        await close_writer(client_writer)


def build_ssl_context(args: argparse.Namespace) -> Optional[ssl.SSLContext]:
    if not args.tls_cert and not args.tls_key:
        return None
    if not args.tls_cert or not args.tls_key:
        raise SystemExit("--tls-cert and --tls-key must be supplied together")
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    context.minimum_version = ssl.TLSVersion.TLSv1_2
    context.options |= ssl.OP_NO_COMPRESSION
    context.load_cert_chain(args.tls_cert, args.tls_key)
    return context


async def async_main(args: argparse.Namespace) -> None:
    settings = Settings(
        backend_host=args.backend_host,
        backend_port=args.backend_port,
        mode=args.mode,
        handshake_timeout=args.handshake_timeout,
        max_clients=args.max_clients,
    )
    semaphore = asyncio.Semaphore(settings.max_clients)
    ssl_context = build_ssl_context(args)
    server = await asyncio.start_server(
        lambda reader, writer: serve_client(reader, writer, settings, semaphore),
        host=args.listen,
        port=args.port,
        ssl=ssl_context,
        backlog=256,
        limit=MAX_HEADER_BYTES + 4096,
        reuse_address=True,
    )
    sockets = ", ".join(str(sock.getsockname()) for sock in server.sockets or [])
    LOG.info(
        "Listening on %s (%s%s), backend %s:%d",
        sockets,
        settings.mode,
        "+tls" if ssl_context else "",
        settings.backend_host,
        settings.backend_port,
    )

    stop = asyncio.Event()
    loop = asyncio.get_running_loop()
    for signame in (signal.SIGINT, signal.SIGTERM):
        with contextlib.suppress(NotImplementedError):
            loop.add_signal_handler(signame, stop.set)
    async with server:
        await stop.wait()


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="TDZ fixed-backend OpenVPN gateway")
    parser.add_argument("--listen", default="0.0.0.0")
    parser.add_argument("--port", required=True, type=int)
    parser.add_argument("--backend-host", default="127.0.0.1")
    parser.add_argument("--backend-port", required=True, type=int)
    parser.add_argument("--mode", choices=("http", "raw"), default="http")
    parser.add_argument("--tls-cert")
    parser.add_argument("--tls-key")
    parser.add_argument("--handshake-timeout", type=float, default=15.0)
    parser.add_argument("--max-clients", type=int, default=512)
    parser.add_argument("--log-level", choices=("DEBUG", "INFO", "WARNING"), default="INFO")
    args = parser.parse_args()
    if not (1 <= args.port <= 65535 and 1 <= args.backend_port <= 65535):
        parser.error("ports must be between 1 and 65535")
    if args.max_clients < 1:
        parser.error("--max-clients must be positive")
    return args


def main() -> None:
    args = parse_args()
    logging.basicConfig(
        level=getattr(logging, args.log_level),
        format="%(asctime)s %(levelname)s %(message)s",
    )
    asyncio.run(async_main(args))


if __name__ == "__main__":
    main()
