#!/usr/bin/env python3
"""Minimal, read-only download server for TDZ OpenVPN profiles."""

from __future__ import annotations

import argparse
import html
import mimetypes
import os
import posixpath
from http import HTTPStatus
from http.server import BaseHTTPRequestHandler, ThreadingHTTPServer
from pathlib import Path
from urllib.parse import unquote, urlsplit


class PortalServer(ThreadingHTTPServer):
    daemon_threads = True
    allow_reuse_address = True
    request_queue_size = 128

    def __init__(self, address: tuple[str, int], root: Path) -> None:
        super().__init__(address, PortalHandler)
        self.portal_root = root.resolve()
        self.public_root = (self.portal_root / "ovpn-configs").resolve()

    def get_request(self):
        request, client_address = super().get_request()
        request.settimeout(15)
        return request, client_address


class PortalHandler(BaseHTTPRequestHandler):
    server_version = "TDZ-OpenVPN-Portal/1.0"
    sys_version = ""

    def log_message(self, fmt: str, *args: object) -> None:
        # Keep normal access information without emitting request headers.
        print(f"{self.address_string()} - {fmt % args}", flush=True)

    def _security_headers(self) -> None:
        self.send_header("X-Content-Type-Options", "nosniff")
        self.send_header("X-Frame-Options", "DENY")
        self.send_header("Referrer-Policy", "no-referrer")
        self.send_header("Cache-Control", "no-store")
        self.send_header(
            "Content-Security-Policy",
            "default-src 'none'; style-src 'unsafe-inline'; img-src 'self'; "
            "base-uri 'none'; form-action 'none'; frame-ancestors 'none'",
        )

    def _redirect(self, location: str) -> None:
        self.send_response(HTTPStatus.FOUND)
        self.send_header("Location", location)
        self._security_headers()
        self.send_header("Content-Length", "0")
        self.end_headers()

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

    def _resolve_request(self) -> Path | None:
        request_path = unquote(urlsplit(self.path).path)
        if "\x00" in request_path:
            raise PermissionError
        if request_path == "/":
            return None
        if not request_path.startswith("/ovpn-configs/"):
            raise PermissionError

        relative = posixpath.normpath(request_path[len("/ovpn-configs/") :])
        if relative.startswith("../") or "/../" in relative:
            raise PermissionError
        root = self.server.public_root  # type: ignore[attr-defined]
        target = (root / relative).resolve()
        try:
            target.relative_to(root)
        except ValueError as exc:
            raise PermissionError from exc
        if any(part.startswith(".") for part in target.relative_to(root).parts):
            raise PermissionError
        return target

    def _validate_public_target(self, target: Path) -> Path:
        root = self.server.public_root  # type: ignore[attr-defined]
        resolved = target.resolve()
        try:
            relative = resolved.relative_to(root)
        except ValueError as exc:
            raise PermissionError from exc
        if any(part.startswith(".") for part in relative.parts):
            raise PermissionError
        return resolved

    def _serve(self) -> None:
        try:
            target = self._resolve_request()
        except PermissionError:
            self._error(HTTPStatus.NOT_FOUND, "The requested page was not found.")
            return

        if target is None:
            self._redirect("/ovpn-configs/")
            return
        if target.is_dir():
            if not self.path.endswith("/"):
                self._redirect(urlsplit(self.path).path + "/")
                return
            try:
                # Re-resolve the directory index as well. This prevents an
                # otherwise in-tree directory from exposing an out-of-tree
                # index through a symlink.
                target = self._validate_public_target(target / "index.html")
            except PermissionError:
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
            if target.suffix.lower() in {".ovpn", ".zip", ".conf", ".txt", ".crt", ".pem"}:
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
        self._serve()

    def do_HEAD(self) -> None:  # noqa: N802 - BaseHTTPRequestHandler API
        self._serve()

    def do_POST(self) -> None:  # noqa: N802 - BaseHTTPRequestHandler API
        self._error(HTTPStatus.METHOD_NOT_ALLOWED, "This portal is read-only.")


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="TDZ OpenVPN profile portal")
    parser.add_argument("--listen", default="0.0.0.0")
    parser.add_argument("--port", type=int, default=1180)
    parser.add_argument("--root", required=True, type=Path)
    args = parser.parse_args()
    if not 1 <= args.port <= 65535:
        parser.error("port must be between 1 and 65535")
    if not args.root.is_dir():
        parser.error("portal root does not exist")
    return args


def main() -> None:
    args = parse_args()
    os.chdir("/")
    server = PortalServer((args.listen, args.port), args.root)
    try:
        print(f"TDZ OpenVPN portal listening on {args.listen}:{args.port}", flush=True)
        server.serve_forever(poll_interval=0.5)
    except KeyboardInterrupt:
        pass
    finally:
        server.server_close()


if __name__ == "__main__":
    main()
