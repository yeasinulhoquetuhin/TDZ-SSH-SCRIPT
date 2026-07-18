#!/usr/bin/env python3

import subprocess
import shutil
import tempfile
import unittest
from html.parser import HTMLParser
from pathlib import Path


REPO = Path(__file__).resolve().parents[1]
MODULE = REPO / "openvpn_module.sh"


class LinkCollector(HTMLParser):
    def __init__(self):
        super().__init__()
        self.links = []
        self.ids = set()

    def handle_starttag(self, tag, attrs):
        attributes = dict(attrs)
        if "id" in attributes:
            self.ids.add(attributes["id"])
        if tag == "script" and "src" in attributes:
            self.links.append(attributes["src"])
            return
        if tag not in {"a", "link"}:
            return
        if "href" in attributes:
            self.links.append(attributes["href"])


class ModuleTests(unittest.TestCase):
    def run_bash(self, body: str):
        return subprocess.run(
            ["bash", "-c", f"source {MODULE!s}\n{body}"],
            text=True,
            capture_output=True,
            check=False,
        )

    def test_host_and_forbidden_port_validation(self):
        result = self.run_bash(
            """
            tdz_openvpn_valid_host vpn.example.com || exit 10
            tdz_openvpn_valid_host 203.0.113.9 || exit 11
            ! tdz_openvpn_valid_host 999.0.0.1 || exit 12
            ! tdz_openvpn_valid_host bad..example.com || exit 13
            ! tdz_openvpn_valid_host '-bad.example' || exit 14
            ! tdz_openvpn_valid_host '.bad.example' || exit 17
            ! tdz_openvpn_valid_host 'bad.example.' || exit 18
            for port in 80 443 442 8443 2080 2086 2096 2053 1080 1180 8080 8880 8888; do
                tdz_openvpn_forbidden_port "$port" || exit 15
            done
            ! tdz_openvpn_forbidden_port 35001 || exit 16
            """
        )
        self.assertEqual(result.returncode, 0, result.stderr)

    def test_fixed_openvpn_port_mapping_and_legacy_state_detection(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            result = self.run_bash(
                f"""
                tdz_openvpn_apply_fixed_port_mapping
                [[ "$TDZ_OVPN_SSL_PORT" == 446 ]] || exit 20
                [[ "$TDZ_OVPN_TCP_PORT" == 447 ]] || exit 21
                [[ "$TDZ_OVPN_UDP_PORT" == 448 ]] || exit 22
                [[ "$TDZ_OVPN_HTTP_PORT" == 449 ]] || exit 23
                [[ "$TDZ_OVPN_WSS_PORT" == 450 ]] || exit 24
                tdz_openvpn_ports_match_fixed_mapping || exit 25
                tdz_openvpn_valid_saved_port 446 || exit 26
                tdz_openvpn_valid_saved_port 25001 || exit 27
                ! tdz_openvpn_valid_saved_port 1024 || exit 28

                TDZ_OVPN_ROOT={root}/openvpn
                TDZ_OVPN_STATE=$TDZ_OVPN_ROOT/state.conf
                TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
                mkdir -p "$TDZ_OVPN_PKI"
                printf 'test\n' > "$TDZ_OVPN_PKI/ca.crt"
                printf 'test\n' > "$TDZ_OVPN_PKI/server.key"
                TDZ_OVPN_HOST=vpn.example.com
                TDZ_OVPN_TCP_PORT=25001
                TDZ_OVPN_UDP_PORT=25002
                TDZ_OVPN_HTTP_PORT=25003
                TDZ_OVPN_WSS_PORT=25004
                TDZ_OVPN_SSL_PORT=25005
                TDZ_OVPN_TCP_SUBNET=10.100.10.0
                TDZ_OVPN_UDP_SUBNET=10.101.11.0
                tdz_openvpn_save_state || exit 29
                tdz_openvpn_needs_refresh || exit 30

                tdz_openvpn_apply_fixed_port_mapping
                tdz_openvpn_save_state || exit 31
                ! tdz_openvpn_needs_refresh || exit 32
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)

    def test_matching_shared_certificate_is_reused_for_outer_tls(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            matching_cert = root / "matching.crt"
            matching_key = root / "matching.key"
            private_cert = root / "private.crt"
            private_key = root / "private.key"
            for cert, key, name in (
                (matching_cert, matching_key, "vpn.example.com"),
                (private_cert, private_key, "tdz-openvpn-server"),
            ):
                generated = subprocess.run(
                    [
                        "openssl",
                        "req",
                        "-x509",
                        "-newkey",
                        "rsa:2048",
                        "-nodes",
                        "-days",
                        "2",
                        "-subj",
                        f"/CN={name}",
                        "-addext",
                        f"subjectAltName=DNS:{name}",
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
            result = self.run_bash(
                f"""
                TDZ_OVPN_PKI={root}/pki
                TDZ_OVPN_SERVICE_USER=root
                TDZ_OVPN_HOST=vpn.example.com
                SSL_CERT_CHAIN_FILE={matching_cert}
                SSL_CERT_KEY_FILE={matching_key}
                mkdir -p "$TDZ_OVPN_PKI"
                cp {private_cert} "$TDZ_OVPN_PKI/server.crt"
                cp {private_key} "$TDZ_OVPN_PKI/server.key"
                tdz_openvpn_prepare_gateway_certificate || exit 20
                [[ "$TDZ_OVPN_GATEWAY_CERT_SOURCE" == shared ]] || exit 21
                cmp -s {matching_cert} "$TDZ_OVPN_PKI/gateway.crt" || exit 22

                TDZ_OVPN_HOST=other.example.com
                tdz_openvpn_prepare_gateway_certificate || exit 23
                [[ "$TDZ_OVPN_GATEWAY_CERT_SOURCE" == private ]] || exit 24
                [[ "$TDZ_OVPN_GATEWAY_CERT_NOTE" == shared-host-mismatch ]] || exit 25
                cmp -s {private_cert} "$TDZ_OVPN_PKI/gateway.crt" || exit 26
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)

    def test_profiles_and_server_config_are_generated_without_credentials(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            script = f"""
            TDZ_OVPN_ROOT={root}/openvpn
            TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
            TDZ_OVPN_RUN=$TDZ_OVPN_ROOT/run
            TDZ_OVPN_HOOKS=$TDZ_OVPN_ROOT/hooks
            TDZ_OVPN_PROFILES={root}/portal/ovpn-configs
            TDZ_OVPN_RUNTIME=/runtime-helper
            TDZ_OVPN_HOST=vpn.example.com
            TDZ_OVPN_TCP_PORT=447
            TDZ_OVPN_UDP_PORT=448
            TDZ_OVPN_HTTP_PORT=449
            TDZ_OVPN_WSS_PORT=450
            TDZ_OVPN_SSL_PORT=446
            TDZ_OVPN_TCP_SUBNET=10.100.10.0
            TDZ_OVPN_UDP_SUBNET=10.101.11.0
            mkdir -p "$TDZ_OVPN_PKI" "$TDZ_OVPN_RUN" "$TDZ_OVPN_HOOKS"
            printf '%s\n' 'TEST CA' > "$TDZ_OVPN_PKI/ca.crt"
            printf '%s\n' 'TEST TLS KEY' > "$TDZ_OVPN_PKI/tls-crypt.key"
            tdz_openvpn_write_server_config tcp tcp-server 447 10.100.10.0 /pam-plugin.so
            tdz_openvpn_write_server_config udp udp 448 10.101.11.0 /pam-plugin.so
            tdz_openvpn_generate_profiles
            """
            result = self.run_bash(script)
            self.assertEqual(result.returncode, 0, result.stderr)

            server = (root / "openvpn/server-tcp.conf").read_text()
            self.assertIn("verify-client-cert none", server)
            self.assertIn("plugin /pam-plugin.so tdz-openvpn", server)
            self.assertIn("username-as-common-name", server)
            self.assertIn("duplicate-cn", server)
            self.assertIn("client-connect ", server)
            self.assertIn("client-disconnect ", server)
            self.assertNotIn("auth-gen-token", server)
            self.assertIn("max-clients 250", server)
            self.assertIn("tls-version-min 1.2", server)
            self.assertIn("tcp-nodelay", server)
            self.assertIn("tun-mtu 1400", server)
            self.assertIn("tcp-queue-limit 128", server)
            self.assertIn("up ", server)
            self.assertIn("/up-tcp", server)
            self.assertIn("AES-128-GCM:AES-256-GCM", server)
            self.assertNotIn("fast-io", server)
            self.assertNotIn("comp-lzo", server)

            udp_server = (root / "openvpn/server-udp.conf").read_text()
            self.assertNotIn("tcp-nodelay", udp_server)
            self.assertIn("fast-io", udp_server)
            self.assertNotIn("tun-mtu 1400", udp_server)
            self.assertNotIn("tcp-queue-limit", udp_server)
            self.assertIn("AES-256-GCM:AES-128-GCM", udp_server)

            profile = (root / "portal/ovpn-configs/tdz-openvpn-http-connect.ovpn").read_text()
            self.assertIn("remote vpn.example.com 447", profile)
            self.assertIn("http-proxy vpn.example.com 449", profile)
            self.assertIn("tun-mtu 1400", profile)
            self.assertIn("setenv CLIENT_CERT 0", profile)
            self.assertIn("<tls-crypt>", profile)
            self.assertNotIn("password", profile.lower())
            self.assertNotIn("auth-nocache", profile)

            direct_profile = (root / "portal/ovpn-configs/tdz-openvpn-tcp.ovpn").read_text()
            self.assertIn("data-ciphers AES-128-GCM:AES-256-GCM", direct_profile)
            self.assertIn("tun-mtu 1400", direct_profile)
            self.assertNotIn("mssfix 1360", direct_profile)
            self.assertNotIn("route vpn.example.com 255.255.255.255 net_gateway", direct_profile)
            self.assertNotIn("route vpn.example.com 255.255.255.255 net_gateway", profile)
            udp_profile = (root / "portal/ovpn-configs/tdz-openvpn-udp.ovpn").read_text()
            self.assertIn("data-ciphers AES-256-GCM:AES-128-GCM", udp_profile)
            self.assertNotIn("tun-mtu 1400", udp_profile)
            for adapter_name in (
                "tdz-openvpn-ws-injector.ovpn",
                "tdz-openvpn-wss-injector.ovpn",
                "tdz-openvpn-ssl-injector.ovpn",
            ):
                adapter_profile = (root / "portal/ovpn-configs" / adapter_name).read_text()
                self.assertIn("cipher AES-256-GCM", adapter_profile)
                self.assertNotIn("data-ciphers", adapter_profile)
                self.assertIn(
                    "route vpn.example.com 255.255.255.255 net_gateway",
                    adapter_profile,
                )
                self.assertIn("tun-mtu 1400", adapter_profile)
                self.assertNotIn("mssfix 1360", adapter_profile)
                self.assertIn('pull-filter ignore "sndbuf"', adapter_profile)
                self.assertIn('pull-filter ignore "rcvbuf"', adapter_profile)
                self.assertIn("sndbuf 524288", adapter_profile)
                self.assertIn("rcvbuf 524288", adapter_profile)

            for direct_name in (
                "tdz-openvpn-udp.ovpn",
                "tdz-openvpn-tcp.ovpn",
                "tdz-openvpn-http-connect.ovpn",
            ):
                direct = (root / "portal/ovpn-configs" / direct_name).read_text()
                self.assertNotIn('pull-filter ignore "sndbuf"', direct)
                self.assertNotIn('pull-filter ignore "rcvbuf"', direct)
                self.assertNotIn("sndbuf 524288", direct)
                self.assertNotIn("rcvbuf 524288", direct)

            portal = (root / "portal/ovpn-configs/index.html").read_text()
            self.assertIn("TDZ <span>•</span><br>OVPN PORTAL", portal)
            self.assertIn('<span class="brand-main">TDZ</span>', portal)
            self.assertIn("HTTP + HTTPS", portal)
            self.assertIn('href="/openvpn/docs"', portal)
            self.assertIn('href="/openvpn/download"', portal)
            docs = (root / "portal/ovpn-configs/docs.html").read_text()
            self.assertIn("CONNECT vpn.example.com:447 HTTP/1.1", docs)
            self.assertIn("Mode-by-mode setup", docs)
            self.assertIn('data-copy-target="http-connect-payload"', docs)
            self.assertIn('data-copy-target="websocket-payload"', docs)
            self.assertIn('id="http-connect-payload"', docs)
            self.assertIn('id="websocket-payload"', docs)
            downloads = (root / "portal/ovpn-configs/download.html").read_text()
            self.assertIn("/openvpn/download/openvpn-profiles.zip", downloads)
            css = (root / "portal/ovpn-configs/portal.css").read_text()
            self.assertIn("--bg:#efeee9", css)
            self.assertIn("--accent:#12b98f", css)
            self.assertIn(':root[data-theme="dark"]', css)
            self.assertIn("@media(prefers-color-scheme:dark)", css)
            self.assertIn("backdrop-filter:blur", css)
            self.assertIn(".theme-toggle{display:inline-flex;align-items:center;gap:5px;min-height:32px", css)
            self.assertIn(".developer-line .developer-link", css)
            self.assertIn("color:#1267d6", css)
            self.assertIn(
                ".developer-line>span{color:var(--text);font-size:.94rem;font-weight:700",
                css,
            )
            self.assertIn(
                ".developer-line .developer-link{display:inline;width:auto;margin:0;"
                "color:#1267d6;font-size:.94rem;font-weight:650",
                css,
            )
            self.assertIn(".project-spotlight{position:relative;display:grid", css)
            self.assertIn(".footer-repo{display:inline-flex", css)
            self.assertIn(".footer-bottom .footer-repo span{color:var(--accent)}", css)
            portal_js = (root / "portal/ovpn-configs/portal.js").read_text()
            self.assertIn("navigator.clipboard.writeText", portal_js)
            self.assertIn("window.localStorage", portal_js)
            self.assertIn('document.documentElement.setAttribute("data-theme"', portal_js)
            self.assertTrue((root / "portal/ovpn-configs/openvpn-profiles.zip").is_file())

            visitor_pages = portal + docs + downloads
            self.assertNotIn("1180", visitor_pages)
            self.assertNotIn("brand-mark", visitor_pages)
            self.assertNotIn("<strong>PORTAL</strong>", visitor_pages)

            public = root / "portal/ovpn-configs"
            valid_pages = {
                "/openvpn/",
                "/openvpn/docs",
                "/openvpn/download",
                "/openvpn/assets/portal.css",
                "/openvpn/assets/portal.js",
                "https://tuhinbro.com/",
                "https://t.me/TuhinBroh",
                "https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT",
            }
            self.assertIn('class="section project-spotlight"', portal)
            self.assertIn("Part of TDZ SSH TUNNEL.", portal)
            self.assertIn("View GitHub repository", portal)
            self.assertNotIn('class="section project-spotlight"', docs + downloads)
            for page_name in ("index.html", "docs.html", "download.html"):
                page_text = (public / page_name).read_text()
                self.assertIn("<title>TDZ • OVPN PORTAL</title>", page_text)
                self.assertIn("Developed By:", page_text)
                self.assertIn("Yeasinul Hoque Tuhin", page_text)
                self.assertIn('class="developer-link" href="https://tuhinbro.com/"', page_text)
                self.assertIn("Telegram:", page_text)
                self.assertIn('href="https://t.me/TuhinBroh"', page_text)
                self.assertIn(
                    'class="footer-repo" '
                    'href="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT"',
                    page_text,
                )
                self.assertNotIn("<h2>Developer</h2>", page_text)
                self.assertNotIn("Designed and developed", page_text)
                self.assertNotIn("© 2026", page_text)
                self.assertNotIn("All rights reserved", page_text)
                self.assertIn('src="/openvpn/assets/portal.js"', page_text)
                self.assertIn("data-theme-toggle", page_text)
                self.assertNotIn("Powered By", page_text)
                parser = LinkCollector()
                parser.feed(page_text)
                for link in parser.links:
                    if link.startswith("#"):
                        self.assertIn(link[1:], parser.ids, f"broken anchor in {page_name}: {link}")
                        continue
                    if link.startswith("/openvpn/download/"):
                        self.assertTrue(
                            (public / link.rsplit("/", 1)[-1]).is_file(),
                            f"broken generated link in {page_name}: {link}",
                        )
                    else:
                        self.assertIn(link, valid_pages, f"unexpected link in {page_name}: {link}")

            guide = (public / "connection-guide.txt").read_text()
            self.assertIn("http://vpn.example.com:1180/openvpn/", guide)
            self.assertIn("https://vpn.example.com:1180/openvpn/docs", guide)
            self.assertIn("https://vpn.example.com:1180/openvpn/download", guide)
            self.assertIn("HTTPS is recommended for downloading profiles", guide)
            self.assertIn("public carrier endpoint outside the tunnel", guide)
            self.assertNotIn("route-gateway", guide)
            self.assertNotIn("/ovpn-configs", portal + docs + downloads + guide)

            (root / "portal/ovpn-configs/stale.ovpn").write_text("stale\n")
            regenerated = self.run_bash(script)
            self.assertEqual(regenerated.returncode, 0, regenerated.stderr)
            self.assertFalse((root / "portal/ovpn-configs/stale.ovpn").exists())
            self.assertEqual(list((root / "portal").glob(".ovpn-configs.*")), [])

    def test_firewall_and_service_files_are_syntactically_well_formed(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            script = f"""
            TDZ_OVPN_ROOT={root}/openvpn
            TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
            TDZ_OVPN_RUN=$TDZ_OVPN_ROOT/run
            TDZ_OVPN_HOOKS=$TDZ_OVPN_ROOT/hooks
            TDZ_OVPN_PORTAL_BASE={root}/portal
            TDZ_OVPN_PROFILES=$TDZ_OVPN_PORTAL_BASE/ovpn-configs
            TDZ_OVPN_SYSTEMD_DIR={root}/systemd
            TDZ_OVPN_PAM_SERVICE={root}/pam/tdz-openvpn
            TDZ_OVPN_SYSCTL={root}/sysctl/tdz-openvpn.conf
            TDZ_OVPN_FIREWALL={root}/libexec/tdz-openvpn-firewall
            TDZ_OVPN_RUNTIME=/bin/true
            TDZ_OVPN_GATEWAY=/bin/true
            TDZ_OVPN_PORTAL=/bin/true
            TDZ_OVPN_SERVICE_USER=root
            TDZ_OVPN_BIN=/bin/true
            TDZ_OVPN_TCP_PORT=447
            TDZ_OVPN_UDP_PORT=448
            TDZ_OVPN_HTTP_PORT=449
            TDZ_OVPN_WSS_PORT=450
            TDZ_OVPN_SSL_PORT=446
            TDZ_OVPN_TCP_SUBNET=10.100.10.0
            TDZ_OVPN_UDP_SUBNET=10.101.11.0
            mkdir -p "$TDZ_OVPN_PKI"
            : > "$TDZ_OVPN_PKI/gateway.crt"
            : > "$TDZ_OVPN_PKI/gateway.key"
            tdz_openvpn_write_network_service
            tdz_openvpn_write_hooks
            tdz_openvpn_write_systemd_units
            dash -n "$TDZ_OVPN_FIREWALL"
            dash -n "$TDZ_OVPN_HOOKS/up-tcp"
            """
            result = self.run_bash(script)
            self.assertEqual(result.returncode, 0, result.stderr)
            firewall = (root / "libexec/tdz-openvpn-firewall").read_text()
            self.assertIn('TCP_PORT="447"', firewall)
            self.assertIn('UDP_PORT="448"', firewall)
            self.assertIn('HTTP_PORT="449"', firewall)
            self.assertIn('WSS_PORT="450"', firewall)
            self.assertIn('SSL_PORT="446"', firewall)
            self.assertIn("MASQUERADE", firewall)
            self.assertIn("-t mangle", firewall)
            self.assertIn("TCPMSS --clamp-mss-to-pmtu", firewall)
            self.assertNotIn("SSH_PORT=", firewall)
            self.assertNotIn("filter_add INPUT -i tun-tdz-tcp", firewall)
            self.assertNotIn("filter_add INPUT -i tun-tdz-udp", firewall)
            qdisc_hook = (root / "openvpn/hooks/up-tcp").read_text()
            self.assertIn("fq_codel", qdisc_hook)
            self.assertIn('command -v tc', qdisc_hook)
            units = list((root / "systemd").glob("tdz-openvpn-*.service"))
            self.assertEqual(len(units), 8)
            for unit in units:
                text = unit.read_text()
                self.assertIn("[Unit]", text)
                self.assertIn("[Service]", text)
            gateway = (root / "systemd/tdz-openvpn-wss.service").read_text()
            self.assertIn("User=root", gateway)
            self.assertIn("NoNewPrivileges=true", gateway)
            self.assertIn("CapabilityBoundingSet=CAP_NET_BIND_SERVICE", gateway)
            self.assertIn("AmbientCapabilities=CAP_NET_BIND_SERVICE", gateway)
            portal = (root / "systemd/tdz-openvpn-portal.service").read_text()
            self.assertIn("--port 1180", portal)
            self.assertIn("--public-host", portal)
            self.assertIn("--allow-http", portal)
            self.assertNotIn("--trusted-subnet", portal)
            self.assertIn("--tls-cert", portal)
            self.assertIn("--tls-key", portal)
            if shutil.which("systemd-analyze"):
                verified = subprocess.run(
                    ["systemd-analyze", "verify", *map(str, units)],
                    text=True,
                    capture_output=True,
                    check=False,
                )
                self.assertEqual(verified.returncode, 0, verified.stderr)

    def test_state_round_trip_preserves_service_account_ownership(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            result = self.run_bash(
                f"""
                TDZ_OVPN_ROOT={root}/openvpn
                TDZ_OVPN_STATE=$TDZ_OVPN_ROOT/state.conf
                TDZ_OVPN_HOST=vpn.example.com
                TDZ_OVPN_TCP_PORT=447
                TDZ_OVPN_UDP_PORT=448
                TDZ_OVPN_HTTP_PORT=449
                TDZ_OVPN_WSS_PORT=450
                TDZ_OVPN_SSL_PORT=446
                TDZ_OVPN_TCP_SUBNET=10.100.10.0
                TDZ_OVPN_UDP_SUBNET=10.101.11.0
                TDZ_OVPN_SERVICE_USER_CREATED=1
                TDZ_OVPN_SERVICE_GROUP_CREATED=1
                tdz_openvpn_save_state || exit 20
                TDZ_OVPN_SERVICE_USER_CREATED=0
                TDZ_OVPN_SERVICE_GROUP_CREATED=0
                tdz_openvpn_load_state || exit 21
                [[ "$TDZ_OVPN_SERVICE_USER_CREATED" == 1 ]] || exit 22
                [[ "$TDZ_OVPN_SERVICE_GROUP_CREATED" == 1 ]] || exit 23
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)

    def test_limiter_uses_the_shared_first_use_lock(self):
        menu = (REPO / "menu.sh").read_text()
        start = menu.index("activate_pending_account() {")
        end = menu.index("\n}\n\nload_banner_identity", start)
        activation = menu[start:end]
        self.assertIn('exec 8>"$USAGE_LOCK"', activation)
        self.assertIn("flock -x 8", activation)
        self.assertIn("active:*", activation)

    def test_limiter_preserves_established_openvpn_sessions(self):
        menu = (REPO / "menu.sh").read_text()
        self.assertIn("# TDZ SSH TUNNEL limiter version 2026-07-19.7", menu)
        self.assertIn("if (( online_count > limit )); then", menu)
        self.assertIn("banner_session_count=$((online_count + 1))", menu)
        self.assertIn(
            "Active Session:</b> $banner_session_count/$limit",
            menu,
        )
        self.assertIn('kill-user "$user" expired', menu)
        self.assertIn('kill-user "$user" quota', menu)
        self.assertNotIn(
            'if (( online_count > limit )) && (( ${ovpn_online[$user]:-0} == 0 )); then',
            menu,
        )

    def test_banner_refresh_and_session_detection_are_immediate_and_authoritative(self):
        menu = (REPO / "menu.sh").read_text()
        refresh_start = menu.index("refresh_dynamic_banner_routing_if_enabled() {")
        refresh_end = menu.index("\n}\n\nupdate_ssh_banners_config", refresh_start)
        refresh = menu[refresh_start:refresh_end]
        self.assertIn('[[ -f "/etc/tdztunnel/banners_enabled" ]]', refresh)
        self.assertNotIn("is_dynamic_ssh_banner_enabled", refresh)
        self.assertIn('-s "$banner_dir/${user}.txt"', refresh)

        limiter_start = menu.index("# TDZ SSH TUNNEL limiter version 2026-07-19.7")
        limiter_end = menu.index("\nEOF\n    chmod +x \"$LIMITER_SCRIPT\"", limiter_start)
        limiter = menu[limiter_start:limiter_end]
        self.assertIn('${#unique_sshd_sessions[@]} -gt 0', limiter)
        self.assertNotIn('${#unique_pids[@]} -gt 0', limiter)
        self.assertNotIn('online_count=1\n', limiter)

    def test_protocol_manager_numbering_is_sequential(self):
        menu = (REPO / "menu.sh").read_text()
        start = menu.index("protocol_menu() {")
        end = menu.index("\n}\n\nuninstall_script()", start)
        protocol = menu[start:end]
        openvpn = protocol.index('tdz_menu_status "[10]" "OpenVPN Protocol Suite"')
        install_xui = protocol.index('tdz_menu_status "[11]" "Install X-UI')
        uninstall_xui = protocol.index('tdz_menu1 "[12]" "Uninstall X-UI Panel"')
        self.assertLess(openvpn, install_xui)
        self.assertLess(install_xui, uninstall_xui)
        self.assertIn("10) if declare -F tdz_openvpn_menu", protocol)
        self.assertIn("11) install_xui_panel", protocol)
        self.assertIn("12) uninstall_xui_panel", protocol)


if __name__ == "__main__":
    unittest.main()
