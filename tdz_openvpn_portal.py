#!/usr/bin/env python3
"""Read-only HTTP-to-HTTPS documentation and download portal for TDZ OpenVPN."""

from __future__ import annotations

import argparse
import html
import ipaddress
import mimetypes
import os
import re
import socket
import ssl
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import quote, unquote, urlsplit


PUBLIC_PREFIX = "/openvpn"
LEGACY_PREFIX = "/ovpn-configs"
DOWNLOAD_SUFFIXES = {".ovpn", ".zip", ".conf", ".txt", ".crt", ".pem"}
DOWNLOAD_NAME_PATTERN = re.compile(r"[A-Za-z0-9][A-Za-z0-9._-]*\Z")
PUBLIC_HOST_PATTERN = re.compile(
    r"(?:[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?)(?:\.(?:[A-Za-z0-9](?:[A-Za-z0-9-]{0,61}[A-Za-z0-9])?))*\Z"
)
PAGE_ROUTES = {
    f"{PUBLIC_PREFIX}/": "index.html",
    f"{PUBLIC_PREFIX}/docs": "docs.html",
    f"{PUBLIC_PREFIX}/docs/": "docs.html",
    f"{PUBLIC_PREFIX}/download": "download.html",
    f"{PUBLIC_PREFIX}/download/": "download.html",
    f"{PUBLIC_PREFIX}/assets/portal.css": "portal.css",
    f"{PUBLIC_PREFIX}/assets/portal.js": "portal.js",
}


class PortalServer(ThreadingHTTPServer):
    daemon_threads = True
    allow_reuse_address = True
    request_queue_size = 128

    def __init__(
        self,
        address: tuple[str, int],
        root: Path,
        tls_context: ssl.SSLContext,
        public_host: str,
        trusted_subnets: tuple[ipaddress.IPv4Network, ...],
    ) -> None:
        super().__init__(address, PortalHandler)
        self.portal_root = root.resolve()
        self.public_root = (self.portal_root / "ovpn-configs").resolve()
        self.tls_context = tls_context
        self.public_host = public_host
        self.public_port = int(address[1])
        self.trusted_subnets = trusted_subnets

    def get_request(self):
        request, client_address = super().get_request()
        request.settimeout(5)
        try:
            prefix = request.recv(3, socket.MSG_PEEK | socket.MSG_WAITALL)
            is_tls = len(prefix) >= 3 and prefix[0] == 0x16 and prefix[1] == 0x03
            if is_tls:
                request = self.tls_context.wrap_socket(request, server_side=True)
            request.settimeout(15)
            return request, client_address
        except Exception:
            request.close()
            raise


class PortalHandler(BaseHTTPRequestHandler):
    server_version = "TDZ-OpenVPN-Portal/2.0"
    sys_version = ""

    def log_message(self, fmt: str, *args: object) -> None:
        # Keep normal access information without emitting request headers.
        print(f"{self.address_string()} - {fmt % args}", flush=True)

    def _security_headers(self) -> None:
        self.send_header("X-Content-Type-Options", "nosniff")
        self.send_header("X-Frame-Options", "DENY")
        self.send_header("Referrer-Policy", "no-referrer")
        self.send_header("Cache-Control", "no-store")
        self.send_header("Cross-Origin-Resource-Policy", "same-origin")
        self.send_header(
            "Permissions-Policy",
            "camera=(), microphone=(), geolocation=(), payment=()",
        )
        self.send_header(
            "Content-Security-Policy",
            "default-src 'none'; style-src 'self'; script-src 'self'; "
            "img-src 'self'; connect-src 'none'; object-src 'none'; "
            "base-uri 'none'; form-action 'none'; frame-ancestors 'none'",
        )
        if isinstance(self.connection, ssl.SSLSocket):
            self.send_header("Strict-Transport-Security", "max-age=31536000")

    def _redirect(self, location: str) -> None:
        self.send_response(HTTPStatus.FOUND)
        self.send_header("Location", location)
        self._security_headers()
        self.send_header("Content-Length", "0")
        self.end_headers()

    def _redirect_plain_http(self) -> bool:
        if isinstance(self.connection, ssl.SSLSocket):
            return False
        try:
            client_ip = ipaddress.ip_address(self.client_address[0])
        except ValueError:
            client_ip = None
        trusted_subnets = self.server.trusted_subnets  # type: ignore[attr-defined]
        if client_ip is not None and any(
            client_ip in subnet for subnet in trusted_subnets
        ):
            # The request is already protected by the authenticated OpenVPN
            # tunnel. Serve it directly so the tunnel gateway IP does not hit
            # a public-host redirect or a certificate-name mismatch.
            return False
        parsed = urlsplit(self.path)
        path = quote(unquote(parsed.path or "/"), safe="/:@-._~!$&'()*+,;=")
        if parsed.query:
            path += "?" + quote(parsed.query, safe="=&:@-._~!$'()*+,;/%")
        host = self.server.public_host  # type: ignore[attr-defined]
        port = self.server.public_port  # type: ignore[attr-defined]
        self.send_response(HTTPStatus.PERMANENT_REDIRECT)
        self.send_header("Location", f"https://{host}:{port}{path}")
        self._security_headers()
        self.send_header("Content-Length", "0")
        self.end_headers()
        return True

    def _error(self, status: HTTPStatus, message: str) -> None:
        body = (
            "<!doctype html><html><head><meta charset='utf-8'>"
            f"<title>{status.value}</title></head><body>"
            f"<h1>{status.value}</h1><p>{html.escape(message)}</p></body></html>"
        ).encode("utf-8")
        self.send_response(status)
        self.send_header("Content-Type", "text/html; charset=utf-8")
        self._security_headers()
        self.send_header("Content-Length", str(len(body)))
        self.end_headers()
        if self.command != "HEAD":
            self.wfile.write(body)

    def _public_target(self, name: str) -> Path:
        root = self.server.public_root  # type: ignore[attr-defined]
        target = (root / name).resolve()
        try:
            relative = target.relative_to(root)
        except ValueError as exc:
            raise PermissionError from exc
        if not relative.parts or any(part.startswith(".") for part in relative.parts):
            raise PermissionError
        return target

    @staticmethod
    def _safe_download_name(value: str) -> str:
        if not DOWNLOAD_NAME_PATTERN.fullmatch(value):
            raise PermissionError
        if Path(value).suffix.lower() not in DOWNLOAD_SUFFIXES:
            raise PermissionError
        return value

    def _resolve_request(self) -> tuple[Path | None, bool, str | None]:
        request_path = unquote(urlsplit(self.path).path)
        if "\x00" in request_path:
            raise PermissionError
        if request_path in {"/", PUBLIC_PREFIX}:
            return None, False, f"{PUBLIC_PREFIX}/"
        if request_path in {LEGACY_PREFIX, f"{LEGACY_PREFIX}/"}:
            return None, False, f"{PUBLIC_PREFIX}/"
        if request_path in PAGE_ROUTES:
            return self._public_target(PAGE_ROUTES[request_path]), False, None

        download_prefix = f"{PUBLIC_PREFIX}/download/"
        if request_path.startswith(download_prefix):
            name = self._safe_download_name(request_path[len(download_prefix) :])
            return self._public_target(name), True, None

        legacy_download_prefix = f"{LEGACY_PREFIX}/"
        if request_path.startswith(legacy_download_prefix):
            name = self._safe_download_name(request_path[len(legacy_download_prefix) :])
            legacy_target = self._public_target(name)
            if not legacy_target.is_file():
                raise PermissionError
            return None, False, f"{PUBLIC_PREFIX}/download/{quote(name)}"
        raise PermissionError

    def _serve(self) -> None:
        try:
            target, force_download, redirect = self._resolve_request()
        except PermissionError:
            self._error(HTTPStatus.NOT_FOUND, "The requested page was not found.")
            return

        if redirect is not None:
            self._redirect(redirect)
            return
        if target is None:
            self._error(HTTPStatus.NOT_FOUND, "The requested page was not found.")
            return
        if not target.is_file():
            self._error(HTTPStatus.NOT_FOUND, "The requested file was not found.")
            return

        try:
            size = target.stat().st_size
            content_type = mimetypes.guess_type(str(target))[0] or "application/octet-stream"
            self.send_response(HTTPStatus.OK)
            self.send_header("Content-Type", content_type)
            self._security_headers()
            self.send_header("Content-Length", str(size))
            if force_download:
                safe_name = target.name.replace('"', "")
                self.send_header("Content-Disposition", f'attachment; filename="{safe_name}"')
            self.end_headers()
            if self.command == "HEAD":
                return
            with target.open("rb") as source:
                while True:
                    chunk = source.read(128 * 1024)
                    if not chunk:
                        break
                    self.wfile.write(chunk)
        except (BrokenPipeError, ConnectionResetError):
            return
        except OSError:
            if not self.wfile.closed:
                self._error(HTTPStatus.INTERNAL_SERVER_ERROR, "Unable to read the file.")

    def do_GET(self) -> None:  # noqa: N802 - BaseHTTPRequestHandler API
        if not self._redirect_plain_http():
            self._serve()

    def do_HEAD(self) -> None:  # noqa: N802 - BaseHTTPRequestHandler API
        if not self._redirect_plain_http():
            self._serve()

    def do_POST(self) -> None:  # noqa: N802 - BaseHTTPRequestHandler API
        if not self._redirect_plain_http():
            self._error(HTTPStatus.METHOD_NOT_ALLOWED, "This portal is read-only.")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="TDZ OpenVPN profile portal")
    parser.add_argument("--listen", default="0.0.0.0")
    parser.add_argument("--port", type=int, default=1180)
    parser.add_argument("--public-host", required=True)
    parser.add_argument("--root", required=True, type=Path)
    parser.add_argument("--tls-cert", required=True, type=Path)
    parser.add_argument("--tls-key", required=True, type=Path)
    parser.add_argument("--trusted-subnet", action="append", default=[])
    args = parser.parse_args()
    if not 1 <= args.port <= 65535:
        parser.error("port must be between 1 and 65535")
    if not args.root.is_dir():
        parser.error("portal root does not exist")
    if not args.tls_cert.is_file():
        parser.error("TLS certificate does not exist")
    if not args.tls_key.is_file():
        parser.error("TLS private key does not exist")
    if not PUBLIC_HOST_PATTERN.fullmatch(args.public_host):
        parser.error("public host must be a valid IPv4 address or domain")
    try:
        args.trusted_subnet = tuple(
            ipaddress.ip_network(value, strict=True) for value in args.trusted_subnet
        )
    except ValueError:
        parser.error("trusted subnet must be a valid IPv4 network")
    if any(network.version != 4 for network in args.trusted_subnet):
        parser.error("trusted subnet must use IPv4")
    return args


def build_tls_context(certificate: Path, private_key: Path) -> ssl.SSLContext:
    context = ssl.SSLContext(ssl.PROTOCOL_TLS_SERVER)
    context.minimum_version = ssl.TLSVersion.TLSv1_2
    context.options |= ssl.OP_NO_COMPRESSION
    context.load_cert_chain(certificate, private_key)
    return context


def main() -> None:
    args = parse_args()
    os.chdir("/")
    tls_context = build_tls_context(args.tls_cert, args.tls_key)
    server = PortalServer(
        (args.listen, args.port),
        args.root,
        tls_context,
        args.public_host,
        args.trusted_subnet,
    )
    try:
        print(
            f"TDZ OpenVPN HTTP/HTTPS portal listening on {args.listen}:{args.port}",
            flush=True,
        )
        server.serve_forever(poll_interval=0.5)
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()


if __name__ == "__main__":
    main()
