#!/usr/bin/env python3

import subprocess
import shutil
import tempfile
import unittest
import re
from html.parser import HTMLParser
from pathlib import Path


REPO = Path(__file__).resolve().parents[1]
MODULE = REPO / "openvpn_module.sh"
MENU = REPO / "menu.sh"
INSTALLER = REPO / "install.sh"


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
        if tag == "img" and "src" in attributes:
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

    def run_menu_bash(self, body: str):
        return subprocess.run(
            ["bash", "-c", f"source {MENU!s} --source-only\n{body}"],
            text=True,
            capture_output=True,
            check=False,
        )

    def test_dead_optional_downloaders_are_removed(self):
        menu = MENU.read_text()
        self.assertNotIn("install_udp_custom()", menu)
        self.assertNotIn("uninstall_udp_custom()", menu)
        self.assertNotIn("udp-custom-linux-", menu)
        self.assertNotIn("install_tdz_proxy()", menu)
        self.assertNotIn("uninstall_tdz_proxy()", menu)
        self.assertNotIn("TDZPROXY_", menu)
        self.assertNotIn("Installing Node.js and PM2", menu)
        self.assertNotIn("Downloading pre-compiled DNSTT", menu)
        self.assertNotIn("Downloading ZiVPN binary", menu)
        self.assertIn('tdz_progress_run 1 3 "Preparing service runtime"', menu)

    def test_haproxy_template_generation_never_executes_comment_text(self):
        with tempfile.TemporaryDirectory() as temp:
            config = Path(temp) / "haproxy" / "haproxy.cfg"
            result = self.run_menu_bash(
                f"""
                HAPROXY_CONFIG={config}
                EDGE_PUBLIC_HTTP_PORT=2080
                EDGE_PUBLIC_TLS_PORT=442
                NGINX_INTERNAL_HTTP_PORT=8770
                NGINX_INTERNAL_TLS_PORT=8442
                HAPROXY_INTERNAL_DECRYPT_PORT=10443
                WS_SSH_BRIDGE_PORT=8890
                TDZ_SSL_CERT_FILE=/etc/tdztunnel/ssl/tdztunnel.pem
                write_haproxy_edge_config
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertNotIn("command not found", result.stderr)
            rendered = config.read_text()
            self.assertIn("option  tcplog", rendered)
            self.assertIn("server ws_bridge 127.0.0.1:8890", rendered)

    def test_openvpn_service_can_traverse_parent_without_reading_database(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp) / "data"
            database = root / "users.db"
            portal = Path(temp) / "portal"
            (root / "openvpn" / "pki").mkdir(parents=True)
            portal.mkdir()
            database.write_text("root:secret:Never:1:0\n")
            database.chmod(0o600)
            result = self.run_bash(
                f"""
                TDZ_OVPN_ROOT={root}/openvpn
                TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
                TDZ_OVPN_RUN=$TDZ_OVPN_ROOT/run
                TDZ_OVPN_HOOKS=$TDZ_OVPN_ROOT/hooks
                TDZ_OVPN_PORTAL_BASE={portal}
                TDZ_OVPN_SERVICE_USER=root
                mkdir -p "$TDZ_OVPN_RUN" "$TDZ_OVPN_HOOKS"
                tdz_openvpn_apply_private_permissions
                [[ "$(stat -c %a {root})" == 710 ]] || exit 21
                [[ "$(stat -c %a {root}/openvpn)" == 750 ]] || exit 22
                [[ "$(stat -c %a {database})" == 600 ]] || exit 23
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)

    def test_openvpn_runtime_validation_accepts_a_complete_generated_layout(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            pki = root / "openvpn" / "pki"
            pki.mkdir(parents=True)
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
                    "/CN=validator.test",
                    "-keyout",
                    str(pki / "server.key"),
                    "-out",
                    str(pki / "server.crt"),
                ],
                stdout=subprocess.DEVNULL,
                stderr=subprocess.DEVNULL,
                check=False,
            )
            self.assertEqual(generated.returncode, 0)
            shutil.copy2(pki / "server.crt", pki / "ca.crt")
            shutil.copy2(pki / "server.crt", pki / "gateway.crt")
            shutil.copy2(pki / "server.key", pki / "gateway.key")
            systemd = root / "systemd"
            profiles = root / "profiles"
            systemd.mkdir()
            profiles.mkdir()
            (root / "openvpn" / "server-tcp.conf").write_text("proto tcp\nport 447\n")
            (root / "openvpn" / "server-udp.conf").write_text("proto udp\nport 448\n")
            for name, port in (("http", 449), ("wss", 450), ("ssl", 446), ("portal", 1180)):
                (systemd / f"tdz-openvpn-{name}.service").write_text(
                    f"ExecStart=/bin/true --port {port} --test\n"
                )
            (profiles / "tdz-openvpn-tcp.ovpn").write_text("<tls-crypt>\nkey\n</tls-crypt>\n")
            diagnostic = root / "validation.log"
            result = self.run_bash(
                f"""
                TDZ_OVPN_ROOT={root}/openvpn
                TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
                TDZ_OVPN_SYSTEMD_DIR={systemd}
                TDZ_OVPN_PROFILES={profiles}
                TDZ_OVPN_RUNTIME={REPO}/tdz_openvpn_runtime.py
                TDZ_OVPN_GATEWAY={REPO}/tdz_openvpn_gateway.py
                TDZ_OVPN_PORTAL={REPO}/tdz_openvpn_portal.py
                TDZ_OVPN_DIAG_LOG={diagnostic}
                TDZ_OVPN_TCP_PORT=447
                TDZ_OVPN_UDP_PORT=448
                TDZ_OVPN_HTTP_PORT=449
                TDZ_OVPN_WSS_PORT=450
                TDZ_OVPN_SSL_PORT=446
                TDZ_OVPN_PORTAL_PORT=1180
                tdz_openvpn_validate_runtime_files || exit 21
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr + diagnostic.read_text())

    def test_package_commands_are_logged_without_terminal_noise(self):
        with tempfile.TemporaryDirectory() as temp:
            log = Path(temp) / "packages.log"
            result = self.run_menu_bash(
                f"""
                TDZ_PACKAGE_LOG={log}
                APT_CACHE_READY=0
                apt-get() {{ echo 'verbose package output'; return 0; }}
                tdz_apt_install example-package
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertNotIn("verbose package output", result.stdout)
            self.assertIn("verbose package output", log.read_text())

    def test_firewall_rules_are_recorded_and_removed_transactionally(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            calls = root / "firewall.calls"
            result = self.run_menu_bash(
                f"""
                DB_DIR={root}/data
                FIREWALL_STATE_FILE=$DB_DIR/firewall-rules.db
                opened=false
                ufw() {{
                    case "$1" in
                        status)
                            echo 'Status: active'
                            $opened && echo '449/tcp ALLOW'
                            ;;
                        allow)
                            opened=true
                            printf 'allow %s\n' "$2" >> {calls}
                            ;;
                        --force)
                            opened=false
                            printf 'delete %s\n' "$4" >> {calls}
                            ;;
                    esac
                }}
                systemctl() {{ return 1; }}
                check_and_open_firewall_port 449 tcp <<< 'y' || exit 21
                grep -Fxq 'ufw|449|tcp' "$FIREWALL_STATE_FILE" || exit 22
                tdz_remove_recorded_firewall_rules || exit 23
                [[ ! -e "$FIREWALL_STATE_FILE" ]] || exit 24
                grep -Fxq 'delete 449/tcp' {calls} || exit 25
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr + result.stdout)

    def test_uninstall_preserves_unrelated_reboot_cron_entries(self):
        with tempfile.TemporaryDirectory() as temp:
            cron = Path(temp) / "cron"
            cron.write_text(
                "0 0 * * * systemctl reboot\n"
                "0 0 * * * systemctl reboot # tdztunnel-managed-auto-reboot\n"
                "15 3 * * 1 systemctl reboot\n"
                "*/5 * * * * /usr/local/bin/health-check\n"
            )
            result = self.run_menu_bash(
                f"""
                CRON_STATE={cron}
                crontab() {{
                    case "$1" in
                        -l) cat "$CRON_STATE" ;;
                        -r) : > "$CRON_STATE" ;;
                        *) cp "$1" "$CRON_STATE" ;;
                    esac
                }}
                tdz_remove_auto_reboot_job || exit 21
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            remaining = cron.read_text()
            self.assertNotIn("tdztunnel-managed-auto-reboot", remaining)
            self.assertNotIn("0 0 * * * systemctl reboot\n", remaining)
            self.assertIn("15 3 * * 1 systemctl reboot", remaining)
            self.assertIn("/usr/local/bin/health-check", remaining)

    def test_dnstt_defers_resolver_changes_and_has_failure_rollback(self):
        menu = MENU.read_text()
        start = menu.index("install_dnstt() {")
        end = menu.index("uninstall_dnstt() {", start)
        install = menu[start:end]
        activation = install.index('tdz_progress_begin 4 4 "Starting and verifying service"')
        resolver_capture = install.index("capture_dnstt_resolver_state")
        self.assertGreater(resolver_capture, activation)
        self.assertIn('rollback_dnstt_failed_install "$resolver_changed"', install)

    def test_mobile_terminal_layout_stays_inside_requested_width(self):
        result = self.run_menu_bash(
            """
            TDZ_BOX_WIDTH=40
            refresh_banner_cache() { :; }
            refresh_dashboard_cache() { :; }
            show_banner
            tdz_screen_title "SERVICE SETUP" "A deliberately long description that must fit."
            tdz_message WARNING "A deliberately long warning that should wrap cleanly instead of splitting against the screen edge."
            """
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        plain = re.sub(r"\x1b\[[0-9;]*[A-Za-z]", "", result.stdout)
        border = next(line for line in plain.splitlines() if "╔" in line)
        self.assertEqual(border.count("═"), 40)
        for line in plain.splitlines():
            self.assertLessEqual(len(line), 44, line)

    def test_installer_keeps_original_step_copy_and_uses_progress_marker(self):
        installer = INSTALLER.read_text()
        expected_steps = (
            'run_step "Checking latest release" 20 prepare_payload',
            'run_step "Saving current setup" 40 backup_current_state',
            'run_step "Updating core files" 60 install_core',
            'run_step "Validating SSH setup" 80 configure_ssh',
            'run_step "Refreshing services" 100 refresh_and_finish',
        )
        for step in expected_steps:
            self.assertIn(step, installer)
        self.assertNotIn('run_step "Preparing installation files"', installer)
        self.assertIn("printf '  ◐ [%d/%d]", installer)
        self.assertIn('draw_live_progress 100 "Complete" " ◐"', installer)

        menu = MENU.read_text()
        progress_start = menu.index("tdz_progress_begin() {")
        progress_end = menu.index("\n}\n\ntdz_progress_done()", progress_start)
        self.assertIn("◐ [%s/%s]", menu[progress_start:progress_end])

    def test_full_uninstall_cleans_legacy_dead_component_leftovers(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            paths = {
                "LEGACY_UDP_DIR": root / "udp",
                "LEGACY_UDP_SERVICE": root / "udp-custom.service",
                "LEGACY_UDPGW_BINARY": root / "udpgw",
                "LEGACY_UDPGW_SERVICE": root / "udpgw.service",
                "LEGACY_PROXY_BINARY": root / "proxy",
                "LEGACY_PROXY_SERVICE": root / "proxy.service",
                "LEGACY_PROXY_CONFIG": root / "proxy.conf",
            }
            paths["LEGACY_UDP_DIR"].mkdir()
            for key, path in paths.items():
                if key != "LEGACY_UDP_DIR":
                    path.write_text("legacy\n")
            assignments = "\n".join(f"{key}={value}" for key, value in paths.items())
            result = self.run_menu_bash(
                f"""
                {assignments}
                tdz_remove_legacy_dead_components || exit 21
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertTrue(all(not path.exists() for path in paths.values()))

    def test_dnstt_resolver_state_round_trip(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            resolver = root / "resolv.conf"
            resolver.write_text("nameserver 1.1.1.1\n")
            keys = root / "dnstt"
            result = self.run_menu_bash(
                f"""
                TDZ_RESOLV_CONF={resolver}
                TDZ_RESOLVED_STUB={root}/stub-resolv.conf
                DNSTT_KEYS_DIR={keys}
                DNSTT_RESOLVER_STATE_FILE=$DNSTT_KEYS_DIR/resolver.state
                DNSTT_RESOLV_BACKUP=$DNSTT_KEYS_DIR/resolv.conf.before
                chattr() {{ :; }}
                systemctl() {{
                    case "$1" in
                        is-active|is-enabled) return 0 ;;
                        *) return 0 ;;
                    esac
                }}
                capture_dnstt_resolver_state || exit 21
                printf 'nameserver 8.8.8.8\n' > "$TDZ_RESOLV_CONF"
                restore_dnstt_resolver_state || exit 22
                grep -Fxq 'nameserver 1.1.1.1' "$TDZ_RESOLV_CONF" || exit 23
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)

    def test_full_uninstall_removes_and_verifies_managed_paths(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            result = self.run_menu_bash(
                f"""
                DB_DIR={root}/data
                DB_FILE=$DB_DIR/users.db
                TDZ_LIB_DIR={root}/lib
                TDZ_MENU_BINARY={root}/bin/menu
                LIMITER_SERVICE={root}/systemd/limiter.service
                LIMITER_SCRIPT={root}/bin/limiter
                BANDWIDTH_SERVICE={root}/systemd/bandwidth.service
                BANDWIDTH_SCRIPT={root}/bin/bandwidth
                LEGACY_BANDWIDTH_DIR={root}/legacy-bandwidth
                TRIAL_CLEANUP_SCRIPT={root}/bin/trial-cleanup
                SSHD_TDZ_CONFIG={root}/sshd/tdztunnel.conf
                SSH_AUTH_SESSION_DIR={root}/run/ssh-sessions
                SSH_BANNER_FILE={root}/data/banner
                LOGIN_INFO_SCRIPT={root}/bin/login-info
                AUTO_BACKUP_CONF={root}/auto-backup.conf
                AUTO_BACKUP_SCRIPT={root}/bin/auto-backup
                AUTO_BACKUP_LOG={root}/auto-backup.log
                AUTO_BACKUP_DIR={root}/backups
                BADVPN_SERVICE_FILE={root}/systemd/badvpn.service
                BADVPN_BUILD_DIR={root}/badvpn-build
                DNSTT_SERVICE_FILE={root}/systemd/dnstt.service
                DNSTT_BINARY={root}/bin/dnstt
                DNSTT_KEYS_DIR={root}/dnstt
                ZIVPN_SERVICE_FILE={root}/systemd/zivpn.service
                ZIVPN_BIN={root}/bin/zivpn
                ZIVPN_DIR={root}/zivpn
                WS_SSH_BRIDGE_SERVICE={root}/systemd/ws.service
                WS_SSH_BRIDGE_SCRIPT={root}/bin/ws-bridge
                TDZ_PACKAGE_LOG={root}/package.log
                TDZ_CERTIFICATE_LOG={root}/certificate.log
                TDZ_SERVICE_LOG={root}/service.log
                TDZ_OVPN_DIAG_LOG={root}/openvpn.log
                TDZ_UNINSTALL_LOG={root}/uninstall.log
                TDZ_RESOLV_CONF={root}/resolv.conf
                mkdir -p "$DB_DIR" "$TDZ_LIB_DIR" "$(dirname "$TDZ_MENU_BINARY")" \
                    "$(dirname "$LIMITER_SERVICE")" "$LEGACY_BANDWIDTH_DIR" \
                    "$SSH_AUTH_SESSION_DIR" "$AUTO_BACKUP_DIR" "$BADVPN_BUILD_DIR" \
                    "$DNSTT_KEYS_DIR" "$ZIVPN_DIR"
                touch "$DB_FILE" "$TDZ_MENU_BINARY" "$LIMITER_SERVICE" "$LIMITER_SCRIPT" \
                    "$BANDWIDTH_SERVICE" "$BANDWIDTH_SCRIPT" "$TRIAL_CLEANUP_SCRIPT" \
                    "$SSHD_TDZ_CONFIG" "$LOGIN_INFO_SCRIPT" "$AUTO_BACKUP_CONF" \
                    "$AUTO_BACKUP_SCRIPT" "$BADVPN_SERVICE_FILE" "$DNSTT_SERVICE_FILE" \
                    "$DNSTT_BINARY" "$ZIVPN_SERVICE_FILE" "$ZIVPN_BIN" \
                    "$WS_SSH_BRIDGE_SERVICE" "$WS_SSH_BRIDGE_SCRIPT"
                clear() {{ :; }}
                show_banner() {{ :; }}
                systemctl() {{
                    [[ "$1" == "is-active" ]] && return 1
                    return 0
                }}
                chattr() {{ :; }}
                get_tdztunnel_known_users() {{ :; }}
                remove_ssh_auth_session_hook() {{ :; }}
                tdz_remove_managed_trial_jobs() {{ :; }}
                tdz_remove_auto_reboot_job() {{ :; }}
                tdz_remove_recorded_firewall_rules() {{ :; }}
                tdz_uninstall_optional_components() {{
                    rm -rf "$BADVPN_BUILD_DIR" "$DNSTT_KEYS_DIR" "$ZIVPN_DIR"
                    rm -f "$BADVPN_SERVICE_FILE" "$DNSTT_SERVICE_FILE" "$DNSTT_BINARY" \
                        "$ZIVPN_SERVICE_FILE" "$ZIVPN_BIN" "$WS_SSH_BRIDGE_SERVICE" "$WS_SSH_BRIDGE_SCRIPT"
                }}
                uninstall_script <<< "yes"
                """,
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertIn("[6/6]", result.stdout)
            self.assertIn("verified as removed", result.stdout)
            self.assertNotIn("UNINSTALL DNSTT", result.stdout)
            self.assertFalse((root / "data").exists())
            self.assertFalse((root / "bin/menu").exists())

    def test_openvpn_uninstall_removes_all_managed_runtime_paths(self):
        with tempfile.TemporaryDirectory() as temp:
            base = Path(temp)
            data = base / "data"
            openvpn = data / "openvpn"
            portal = base / "portal"
            systemd = base / "systemd"
            pam = base / "pam" / "openvpn"
            sysctl = base / "sysctl.conf"
            firewall = base / "firewall"
            (openvpn / "pki").mkdir(parents=True)
            portal.mkdir()
            systemd.mkdir()
            pam.parent.mkdir()
            (openvpn / "state.conf").write_text(
                "\n".join(
                    [
                        "VERSION=test",
                        "HOST=vpn.example.com",
                        "PORTAL_PORT=1180",
                        "SSL_PORT=446",
                        "TCP_PORT=447",
                        "UDP_PORT=448",
                        "HTTP_PORT=449",
                        "WSS_PORT=450",
                        "SUPPORT_USERNAME=TUSTDZ",
                        "TCP_SUBNET=10.87.0.0",
                        "UDP_SUBNET=10.88.0.0",
                        "SERVICE_USER_CREATED=0",
                        "SERVICE_GROUP_CREATED=0",
                        "IP_FORWARD_PREVIOUS=0",
                    ]
                )
                + "\n"
            )
            (openvpn / "pki" / "ca.crt").write_text("ca")
            (openvpn / "pki" / "server.key").write_text("key")
            for unit in (
                "network",
                "tcp",
                "udp",
                "http",
                "wss",
                "ssl",
                "portal",
                "accounting",
            ):
                (systemd / f"tdz-openvpn-{unit}.service").write_text("unit")
            pam.write_text("pam")
            sysctl.write_text("sysctl")
            firewall.write_text("#!/bin/sh\nexit 0\n")
            firewall.chmod(0o700)
            result = self.run_bash(
                f"""
                TDZ_OVPN_ROOT={openvpn}
                TDZ_OVPN_STATE=$TDZ_OVPN_ROOT/state.conf
                TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
                TDZ_OVPN_PORTAL_BASE={portal}
                TDZ_OVPN_SYSTEMD_DIR={systemd}
                TDZ_OVPN_PAM_SERVICE={pam}
                TDZ_OVPN_SYSCTL={sysctl}
                TDZ_OVPN_FIREWALL={firewall}
                TDZ_OVPN_SERVICE_USER=root
                sysctl() {{ printf '%s\n' "$*" >> {base}/sysctl.calls; }}
                systemctl() {{
                    [[ "$1" == "is-active" ]] && return 1
                    return 0
                }}
                tdz_openvpn_uninstall silent || exit 21
                [[ ! -e "$TDZ_OVPN_ROOT" ]] || exit 22
                [[ ! -e "$TDZ_OVPN_PORTAL_BASE" ]] || exit 23
                [[ ! -e "$TDZ_OVPN_PAM_SERVICE" ]] || exit 24
                [[ ! -e "$TDZ_OVPN_SYSCTL" ]] || exit 25
                [[ ! -e "$TDZ_OVPN_FIREWALL" ]] || exit 26
                [[ "$(stat -c %a {data})" == 700 ]] || exit 27
                if find "$TDZ_OVPN_SYSTEMD_DIR" -name 'tdz-openvpn-*.service' -print -quit | grep -q .; then exit 28; fi
                grep -Fxq -- '-w net.ipv4.ip_forward=0' {base}/sysctl.calls || exit 29
                exit 0
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)

    def test_online_list_footer_counts_visible_users_and_sessions(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            database = root / "users.db"
            bandwidth = root / "bandwidth"
            bandwidth.mkdir()
            database.write_text("root:secret:Never:5:0\n")
            result = self.run_menu_bash(
                f"""
                DB_FILE={database}
                BANDWIDTH_DIR={bandwidth}
                clear() {{ :; }}
                show_banner() {{ :; }}
                refresh_ssh_session_cache() {{ SSH_SESSION_COUNTS[root]=3; }}
                tdz_user_policy_reason() {{ printf 'active\\n'; }}
                tdz_user_is_manually_locked() {{ return 1; }}
                list_users_view online "ONLINE USERS"
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            plain = result.stdout.replace("\x1b", "")
            self.assertIn("SESSIONS:", plain)
            self.assertIn("TOTAL:", plain)
            self.assertNotIn("PENDING", plain)
            self.assertIn("3", plain)

            menu = MENU.read_text()
            start = menu.index('if [[ "$view_filter" == "online" ]]', menu.index("list_users_view() {"))
            end = menu.index("\n    else", start)
            footer = menu[start:end]
            self.assertLess(footer.index("TOTAL:"), footer.index("SESSIONS:"))
            self.assertIn("${C_WHITE}${user_count}", footer)
            self.assertIn("${C_WHITE}${session_count}", footer)
            self.assertNotIn("${C_GREEN}${user_count}", footer)
            self.assertNotIn("${C_GREEN}${session_count}", footer)

    def test_empty_online_list_still_shows_zero_totals(self):
        with tempfile.TemporaryDirectory() as temp:
            database = Path(temp) / "users.db"
            database.write_text("")
            result = self.run_menu_bash(
                f"""
                DB_FILE={database}
                clear() {{ :; }}
                show_banner() {{ :; }}
                refresh_ssh_session_cache() {{ :; }}
                list_users_view online "ONLINE USERS"
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            plain = result.stdout.replace("\x1b", "")
            self.assertIn("SESSIONS:", plain)
            self.assertIn("TOTAL:", plain)
            self.assertNotIn("PENDING", plain)

    def test_standalone_service_uninstallers_have_bounded_progress_and_verification(self):
        menu = MENU.read_text()
        functions = {
            "uninstall_badvpn": "load_edge_cert_info",
            "uninstall_ssl_tunnel": "show_dnstt_details",
            "uninstall_dnstt": "install_zivpn",
            "uninstall_zivpn": "purge_nginx",
            "purge_nginx": "install_nginx_proxy",
        }
        for function, following_function in functions.items():
            with self.subTest(function=function):
                start = menu.index(f"{function}() {{")
                end = menu.index(f"\n{following_function}() {{", start)
                body = menu[start:end]
                self.assertIn("tdz_progress_begin", body)
                self.assertIn("systemctl is-active --quiet", body)
                self.assertRegex(body, r'Verifying|verifying')

        openvpn = MODULE.read_text()
        start = openvpn.index("tdz_openvpn_uninstall() {")
        end = openvpn.index("\ntdz_openvpn_regenerate_profiles_action() {", start)
        body = openvpn[start:end]
        self.assertIn('tdz_openvpn_progress_begin 1 4 "Stopping services"', body)
        self.assertIn('tdz_openvpn_progress_begin 4 4 "Verifying cleanup"', body)
        self.assertIn("systemctl is-active --quiet", body)

    def test_badvpn_uninstall_finishes_and_verifies_temp_state(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            service = root / "badvpn.service"
            build = root / "badvpn-build"
            service.write_text("unit")
            build.mkdir()
            result = self.run_menu_bash(
                f"""
                BADVPN_SERVICE_FILE={service}
                BADVPN_BUILD_DIR={build}
                systemctl() {{
                    [[ "$1" == "is-active" ]] && return 1
                    return 0
                }}
                UNINSTALL_MODE=interactive
                uninstall_badvpn
                [[ ! -e "$BADVPN_SERVICE_FILE" ]] || exit 21
                [[ ! -e "$BADVPN_BUILD_DIR" ]] || exit 22
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertIn("[1/3]", result.stdout)
            self.assertIn("[3/3]", result.stdout)
            self.assertIn("BadVPN was removed successfully", result.stdout)

    def test_menu_actions_pause_exactly_once(self):
        menu = MENU.read_text()
        main = menu[menu.index("main_menu() {") :]
        self.assertIn("8) tdz_run_action client_config_menu ;;", main)
        self.assertIn("1) tdz_run_action create_user ;;", main)
        result = self.run_menu_bash(
            """
            leaf_with_pause() { press_enter; }
            leaf_without_pause() { :; }
            tdz_run_action leaf_with_pause <<< ""
            tdz_run_action leaf_without_pause <<< ""
            """
        )
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(result.stdout.count("Press"), 2, result.stdout)

    def test_lock_and_unlock_selectors_only_show_actionable_accounts(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            database = root / "users.db"
            manual_locks = root / "manual-locks.db"
            lock_input = root / "lock-input"
            unlock_input = root / "unlock-input"
            database.write_text(
                "alice:pass:Never:1:0\n"
                "bob:pass:Never:1:0\n"
                "carol:pass:Never:1:0\n"
            )
            manual_locks.write_text("bob\n")
            lock_input.write_text("all\n")
            unlock_input.write_text("all\n")

            result = self.run_menu_bash(
                f"""
                DB_FILE={database}
                MANUAL_LOCK_FILE={manual_locks}
                clear() {{ :; }}
                show_banner() {{ :; }}
                tdz_box_top() {{ :; }}
                tdz_box_header() {{ :; }}
                tdz_box_divider() {{ :; }}
                tdz_box_bot() {{ :; }}
                tdz_menu1() {{ :; }}
                tdz_row() {{ :; }}
                id() {{
                    case "$1" in
                        alice|bob|carol) return 0 ;;
                        *) return 1 ;;
                    esac
                }}
                _select_multi_user_interface "LOCK ACCOUNTS" false unlocked < {lock_input}
                [[ "${{SELECTED_USERS[*]}}" == "alice carol" ]] || {{
                    printf 'lock-list=%s\n' "${{SELECTED_USERS[*]}}" >&2
                    exit 20
                }}

                _select_multi_user_interface "UNLOCK ACCOUNTS" false locked < {unlock_input}
                [[ "${{SELECTED_USERS[*]}}" == "bob" ]] || {{
                    printf 'unlock-list=%s\n' "${{SELECTED_USERS[*]}}" >&2
                    exit 21
                }}
                """
            )
            self.assertEqual(
                result.returncode, 0, result.stderr + "\n" + result.stdout
            )

        menu = MENU.read_text()
        lock_start = menu.index("lock_user() {")
        unlock_start = menu.index("unlock_user() {")
        list_start = menu.index("list_users() {")
        lock = menu[lock_start:unlock_start]
        unlock = menu[unlock_start:list_start]
        self.assertIn(
            '_select_multi_user_interface "LOCK ACCOUNTS" "false" "unlocked"',
            lock,
        )
        self.assertIn(
            '_select_multi_user_interface "UNLOCK ACCOUNTS" "false" "locked"',
            unlock,
        )
        self.assertIn('current_state=$(tdz_account_lock_state "$u"', lock)
        self.assertIn('current_state=$(tdz_account_lock_state "$u"', unlock)
        self.assertGreaterEqual(
            lock.count('current_state=$(tdz_account_lock_state "$u"'), 2
        )
        self.assertGreaterEqual(
            unlock.count('current_state=$(tdz_account_lock_state "$u"'), 2
        )

    def test_lock_and_unlock_actions_transition_state_without_moving_database_rows(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            database = root / "users.db"
            manual_locks = root / "manual-locks.db"
            manual_mutex = root / ".manual-locks.lock"
            lock_input = root / "lock-input"
            unlock_input = root / "unlock-input"
            original_row = "alice:pass:Never:2:10\n"
            database.write_text(original_row)
            lock_input.write_text("all\n")
            unlock_input.write_text("all\n")

            result = self.run_menu_bash(
                f"""
                DB_FILE={database}
                DB_DIR={root}
                MANUAL_LOCK_FILE={manual_locks}
                MANUAL_LOCK_MUTEX={manual_mutex}
                vpn_kills=0
                process_kills=0
                clear() {{ :; }}
                show_banner() {{ :; }}
                tdz_box_top() {{ :; }}
                tdz_box_header() {{ :; }}
                tdz_box_divider() {{ :; }}
                tdz_box_bot() {{ :; }}
                tdz_menu1() {{ :; }}
                tdz_row() {{ :; }}
                id() {{ [[ "$1" == alice ]]; }}
                tdz_openvpn_kill_user() {{ ((vpn_kills += 1)); }}
                killall() {{ ((process_kills += 1)); }}

                lock_user < {lock_input}
                grep -Fxq alice "$MANUAL_LOCK_FILE" || exit 30
                [[ "$vpn_kills" == 1 && "$process_kills" == 1 ]] || exit 31
                [[ "$(cat "$DB_FILE")" == 'alice:pass:Never:2:10' ]] || exit 32

                unlock_user < {unlock_input}
                ! grep -Fxq alice "$MANUAL_LOCK_FILE" || exit 33
                [[ "$(cat "$DB_FILE")" == 'alice:pass:Never:2:10' ]] || exit 34
                """
            )
            self.assertEqual(
                result.returncode, 0, result.stderr + "\n" + result.stdout
            )

    def test_numeric_multi_select_never_appends_an_empty_username(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            database = root / "users.db"
            selection = root / "selection"
            database.write_text("alice:pass:Never:1:0\nbob:pass:Never:1:0\n")
            selection.write_text("1\n")
            result = self.run_menu_bash(
                f"""
                DB_FILE={database}
                clear() {{ :; }}
                show_banner() {{ :; }}
                tdz_box_top() {{ :; }}
                tdz_box_header() {{ :; }}
                tdz_box_divider() {{ :; }}
                tdz_box_bot() {{ :; }}
                tdz_menu1() {{ :; }}
                tdz_row() {{ :; }}
                _select_multi_user_interface "TEST" false any < {selection}
                [[ "${{#SELECTED_USERS[@]}}" == 1 ]] || exit 40
                [[ "${{SELECTED_USERS[0]}}" == alice ]] || exit 41
                [[ -n "${{SELECTED_USERS[0]}}" ]] || exit 42
                """
            )
            self.assertEqual(
                result.returncode, 0, result.stderr + "\n" + result.stdout
            )

    def test_expiry_and_quota_are_not_manual_unlock_states(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            database = root / "users.db"
            locks = root / "manual-locks.db"
            bandwidth = root / "bandwidth"
            bandwidth.mkdir()
            database.write_text(
                "expired:pass:2000-01-01:1:0\n"
                "quota:pass:Never:1:1\n"
                "manual:pass:Never:1:0\n"
                "active:pass:Never:1:0\n"
            )
            locks.write_text("manual\n")
            (bandwidth / "quota.usage").write_text(str(1024**3) + "\n")
            result = self.run_menu_bash(
                f"""
                DB_FILE={database}
                MANUAL_LOCK_FILE={locks}
                BANDWIDTH_DIR={bandwidth}
                id() {{ return 0; }}
                [[ "$(tdz_user_policy_reason expired)" == expired ]] || exit 50
                [[ "$(tdz_user_policy_reason quota)" == quota ]] || exit 51
                [[ "$(tdz_account_lock_state expired)" == unlocked ]] || exit 52
                [[ "$(tdz_account_lock_state quota)" == unlocked ]] || exit 53
                [[ "$(tdz_account_lock_state manual)" == locked ]] || exit 54
                """
            )
            self.assertEqual(
                result.returncode, 0, result.stderr + "\n" + result.stdout
            )

    def test_legacy_shadow_locks_migrate_only_operator_intent(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            database = root / "users.db"
            locks = root / "manual-locks.db"
            mutex = root / ".manual-locks.lock"
            bandwidth = root / "bandwidth"
            unlock_log = root / "unlocked.log"
            bandwidth.mkdir()
            database.write_text(
                "active:pass:Never:1:0\n"
                "expired:pass:2000-01-01:1:0\n"
                "quota:pass:Never:1:1\n"
            )
            (bandwidth / "quota.usage").write_text(str(1024**3) + "\n")
            result = self.run_menu_bash(
                f"""
                DB_DIR={root}
                DB_FILE={database}
                MANUAL_LOCK_FILE={locks}
                MANUAL_LOCK_MUTEX={mutex}
                BANDWIDTH_DIR={bandwidth}
                id() {{ return 0; }}
                passwd() {{ printf '%s L 2026-07-20 0 99999 7 -1\n' "$2"; }}
                usermod() {{
                    [[ "$1" == -U ]] || return 1
                    printf '%s\n' "$2" >> {unlock_log}
                }}
                migrate_legacy_shadow_locks || exit 55
                [[ "$(cat "$MANUAL_LOCK_FILE")" == active ]] || exit 56
                [[ "$(sort {unlock_log} | tr '\n' ' ')" == 'active expired quota ' ]] || exit 57
                """
            )
            self.assertEqual(
                result.returncode, 0, result.stderr + "\n" + result.stdout
            )

    def test_manual_lock_backup_and_legacy_restore_keep_reasons_separate(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            db_dir = root / "tdztunnel"
            bandwidth = db_dir / "bandwidth"
            restore_root = root / "restore"
            db_dir.mkdir()
            bandwidth.mkdir()
            restore_root.mkdir()
            database = db_dir / "users.db"
            manual_locks = db_dir / "manual-locks.db"
            mutex = db_dir / ".manual-locks.lock"
            database.write_text(
                "active:pass:Never:1:0\n"
                "expired:pass:2000-01-01:1:0\n"
                "quota:pass:Never:1:1\n"
            )
            manual_locks.write_text("active\n")
            (bandwidth / "quota.usage").write_text(str(1024**3) + "\n")
            archive = root / "backup.tar.gz"

            result = self.run_menu_bash(
                f"""
                DB_DIR={db_dir}
                DB_FILE={database}
                BANDWIDTH_DIR={bandwidth}
                MANUAL_LOCK_FILE={manual_locks}
                MANUAL_LOCK_MUTEX={mutex}
                id() {{ return 0; }}
                create_user_backup_archive {archive} || exit 60
                : > "$MANUAL_LOCK_FILE"
                printf 'active:locked\nexpired:locked\nquota:locked\n' > {restore_root}/locks.db
                tdz_restore_manual_lock_archive {restore_root} || exit 61
                [[ "$(cat "$MANUAL_LOCK_FILE")" == active ]] || {{
                    printf 'restored=%s\n' "$(cat "$MANUAL_LOCK_FILE")" >&2
                    exit 62
                }}
                """
            )
            self.assertEqual(
                result.returncode, 0, result.stderr + "\n" + result.stdout
            )
            listed = subprocess.run(
                ["tar", "-tzf", str(archive)],
                text=True,
                capture_output=True,
                check=False,
            )
            self.assertEqual(listed.returncode, 0, listed.stderr)
            self.assertIn("tdz-user-data/manual-locks.db", listed.stdout)
            extracted = root / "extracted"
            extracted.mkdir()
            subprocess.run(
                ["tar", "-xzf", str(archive), "-C", str(extracted)],
                check=True,
            )
            backup_root = extracted / "tdz-user-data"
            self.assertEqual((backup_root / "manual-locks.db").read_text(), "active\n")
            self.assertIn("version=2", (backup_root / "meta.txt").read_text())
            self.assertIn("active:locked", (backup_root / "locks.db").read_text())

    def test_generated_account_workers_pass_shell_syntax(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            auto_worker = root / "auto-backup.sh"
            trial_worker = root / "trial-cleanup.sh"
            limiter_worker = root / "limiter.sh"
            limiter_service = root / "limiter.service"
            result = self.run_menu_bash(
                f"""
                AUTO_BACKUP_SCRIPT={auto_worker}
                TRIAL_CLEANUP_SCRIPT={trial_worker}
                LIMITER_SCRIPT={limiter_worker}
                LIMITER_SERVICE={limiter_service}
                systemctl() {{ return 0; }}
                pkill() {{ return 0; }}
                auto_backup_write_worker || exit 70
                setup_trial_cleanup_script || exit 71
                setup_limiter_service || exit 72
                bash -n "$AUTO_BACKUP_SCRIPT" || exit 73
                bash -n "$TRIAL_CLEANUP_SCRIPT" || exit 74
                bash -n "$LIMITER_SCRIPT" || exit 75
                """
            )
            self.assertEqual(
                result.returncode, 0, result.stderr + "\n" + result.stdout
            )
            worker = auto_worker.read_text()
            self.assertIn('MANUAL_LOCK_FILE="$DB_DIR/manual-locks.db"', worker)
            self.assertIn("restore_manual_lock_policy", worker)
            limiter = limiter_worker.read_text()
            self.assertIn('MANUAL_LOCK_FILE="/etc/tdztunnel/manual-locks.db"', limiter)
            self.assertNotIn("usermod -L", limiter)
            self.assertIn("activate_pending_account() (", limiter)

    def test_list_users_opens_filtered_views(self):
        menu = MENU.read_text()
        list_start = menu.index("list_users() {")
        list_end = menu.index("\n}\n\nrenew_user()", list_start)
        block = menu[list_start:list_end]
        for label in (
            "All Managed Users",
            "Expired Users",
            "Quota Ended Users",
            "Online Users",
        ):
            self.assertIn(label, block)
        self.assertIn('list_users_view expired "EXPIRED USERS"', block)
        self.assertIn('list_users_view quota "QUOTA ENDED USERS"', block)
        self.assertIn('list_users_view online "ONLINE USERS"', block)

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
            tdz_openvpn_valid_telegram_username TUSTDZ || exit 19
            tdz_openvpn_valid_telegram_username Support_24 || exit 20
            ! tdz_openvpn_valid_telegram_username '@TUSTDZ' || exit 21
            ! tdz_openvpn_valid_telegram_username abcd || exit 22
            ! tdz_openvpn_valid_telegram_username 'bad-name' || exit 23
            ! tdz_openvpn_valid_telegram_username '1Support' || exit 24
            for port in 80 443 442 8443 2080 2086 2096 2053 1080 1180 8080 8880 8888; do
                tdz_openvpn_forbidden_port "$port" || exit 15
            done
            ! tdz_openvpn_forbidden_port 35001 || exit 16
            """
        )
        self.assertEqual(result.returncode, 0, result.stderr)

    def test_default_and_custom_openvpn_port_state(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            result = self.run_bash(
                f"""
                tdz_openvpn_apply_fixed_port_mapping
                [[ "$TDZ_OVPN_PORTAL_PORT" == 1180 ]] || exit 19
                [[ "$TDZ_OVPN_SSL_PORT" == 446 ]] || exit 20
                [[ "$TDZ_OVPN_TCP_PORT" == 447 ]] || exit 21
                [[ "$TDZ_OVPN_UDP_PORT" == 448 ]] || exit 22
                [[ "$TDZ_OVPN_HTTP_PORT" == 449 ]] || exit 23
                [[ "$TDZ_OVPN_WSS_PORT" == 450 ]] || exit 24
                tdz_openvpn_ports_match_fixed_mapping || exit 25
                tdz_openvpn_valid_saved_port 446 || exit 26
                tdz_openvpn_valid_saved_port 25001 || exit 27
                tdz_openvpn_valid_saved_port 1024 || exit 28
                ! tdz_openvpn_valid_saved_port 0 || exit 33
                ! tdz_openvpn_valid_saved_port 65536 || exit 34
                ! tdz_openvpn_valid_saved_port 00443 || exit 42
                tdz_openvpn_requested_ports_valid 1180 446 447 448 449 450 || exit 35
                tdz_openvpn_requested_ports_valid 25000 25001 25002 25003 25004 25005 || exit 36
                ! tdz_openvpn_requested_ports_valid 25000 25001 25002 25003 25004 25004 || exit 37
                ! tdz_openvpn_requested_ports_valid 25000 25001 25002 25003 25004 443 || exit 38
                tdz_openvpn_ports_match_layout 1180 446 447 448 449 450 || exit 43
                ! tdz_openvpn_ports_match_layout 1180 446 447 448 449 451 || exit 44

                TDZ_OVPN_ROOT={root}/openvpn
                TDZ_OVPN_STATE=$TDZ_OVPN_ROOT/state.conf
                TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
                mkdir -p "$TDZ_OVPN_PKI"
                printf 'test\n' > "$TDZ_OVPN_PKI/ca.crt"
                printf 'test\n' > "$TDZ_OVPN_PKI/server.key"
                TDZ_OVPN_HOST=vpn.example.com
                TDZ_OVPN_PORTAL_PORT=25000
                TDZ_OVPN_TCP_PORT=25001
                TDZ_OVPN_UDP_PORT=25002
                TDZ_OVPN_HTTP_PORT=25003
                TDZ_OVPN_WSS_PORT=25004
                TDZ_OVPN_SSL_PORT=25005
                TDZ_OVPN_SUPPORT_USERNAME=CustomSupport
                TDZ_OVPN_TCP_SUBNET=10.100.10.0
                TDZ_OVPN_UDP_SUBNET=10.101.11.0
                tdz_openvpn_save_state || exit 29
                tdz_openvpn_load_state || exit 30
                [[ "$TDZ_OVPN_PORTAL_PORT" == 25000 ]] || exit 39
                [[ "$TDZ_OVPN_TCP_PORT" == 25001 ]] || exit 40
                [[ "$TDZ_OVPN_SUPPORT_USERNAME" == CustomSupport ]] || exit 45
                ! tdz_openvpn_needs_refresh || exit 41

                tdz_openvpn_apply_fixed_port_mapping
                tdz_openvpn_save_state || exit 31
                ! tdz_openvpn_needs_refresh || exit 32
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)

    def test_unchanged_interactive_ports_skip_confirmation_and_rebuild(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            input_file = root / "input.txt"
            input_file.write_text("\n" * 6 + "yes\n")
            result = self.run_bash(
                f"""
                TDZ_OVPN_ROOT={root}/openvpn
                TDZ_OVPN_STATE=$TDZ_OVPN_ROOT/state.conf
                TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
                TDZ_OVPN_HOST=vpn.example.com
                tdz_openvpn_apply_fixed_port_mapping
                TDZ_OVPN_TCP_SUBNET=10.100.10.0
                TDZ_OVPN_UDP_SUBNET=10.101.11.0
                mkdir -p "$TDZ_OVPN_PKI"
                printf 'test\n' > "$TDZ_OVPN_PKI/ca.crt"
                printf 'test\n' > "$TDZ_OVPN_PKI/server.key"
                tdz_openvpn_save_state || exit 20

                tdz_openvpn_apply_port_layout() {{ printf 'APPLY_CALLED\n'; return 90; }}
                exec 9<{input_file}
                tdz_openvpn_configure_ports <&9 || exit 21
                IFS= read -r remaining <&9 || exit 22
                [[ "$remaining" == yes ]] || exit 23
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertIn("No port changes were entered", result.stdout)
            self.assertNotIn("APPLY_CALLED", result.stdout)
            self.assertNotIn("disconnects active OpenVPN sessions", result.stdout)

    def test_changed_interactive_ports_warn_and_apply_exact_layout(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            input_file = root / "input.txt"
            input_file.write_text("25100\n\n\n\n\n\nyes\n")
            result = self.run_bash(
                f"""
                TDZ_OVPN_ROOT={root}/openvpn
                TDZ_OVPN_STATE=$TDZ_OVPN_ROOT/state.conf
                TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
                TDZ_OVPN_HOST=vpn.example.com
                tdz_openvpn_apply_fixed_port_mapping
                TDZ_OVPN_TCP_SUBNET=10.100.10.0
                TDZ_OVPN_UDP_SUBNET=10.101.11.0
                mkdir -p "$TDZ_OVPN_PKI"
                printf 'test\n' > "$TDZ_OVPN_PKI/ca.crt"
                printf 'test\n' > "$TDZ_OVPN_PKI/server.key"
                tdz_openvpn_save_state || exit 30

                tdz_openvpn_apply_port_layout() {{
                    [[ "$#" == 6 ]] || return 91
                    [[ "$1 $2 $3 $4 $5 $6" == "25100 446 447 448 449 450" ]] || return 92
                    printf 'APPLIED:%s\n' "$*"
                }}
                tdz_openvpn_configure_ports < {input_file} || exit 31
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertIn("disconnects active OpenVPN sessions", result.stdout)
            self.assertIn("APPLIED:25100 446 447 448 449 450", result.stdout)
            self.assertNotIn("No port changes were entered", result.stdout)

    def test_restore_defaults_is_a_noop_when_defaults_are_active(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            input_file = root / "input.txt"
            input_file.write_text("yes\n")
            result = self.run_bash(
                f"""
                TDZ_OVPN_ROOT={root}/openvpn
                TDZ_OVPN_STATE=$TDZ_OVPN_ROOT/state.conf
                TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
                TDZ_OVPN_HOST=vpn.example.com
                tdz_openvpn_apply_fixed_port_mapping
                TDZ_OVPN_TCP_SUBNET=10.100.10.0
                TDZ_OVPN_UDP_SUBNET=10.101.11.0
                mkdir -p "$TDZ_OVPN_PKI"
                printf 'test\n' > "$TDZ_OVPN_PKI/ca.crt"
                printf 'test\n' > "$TDZ_OVPN_PKI/server.key"
                tdz_openvpn_save_state || exit 40

                tdz_openvpn_apply_port_layout() {{ printf 'APPLY_CALLED\n'; return 93; }}
                exec 9<{input_file}
                tdz_openvpn_restore_default_ports <&9 || exit 41
                IFS= read -r remaining <&9 || exit 42
                [[ "$remaining" == yes ]] || exit 43
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertIn("Default OpenVPN ports are already active", result.stdout)
            self.assertNotIn("APPLY_CALLED", result.stdout)
            self.assertNotIn("disconnects active OpenVPN sessions", result.stdout)

    def test_support_contact_change_is_persistent_and_does_not_restart_openvpn(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            input_file = root / "input.txt"
            input_file.write_text("@NewSupport\n")
            result = self.run_bash(
                f"""
                TDZ_OVPN_ROOT={root}/openvpn
                TDZ_OVPN_STATE=$TDZ_OVPN_ROOT/state.conf
                TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
                TDZ_OVPN_HOST=vpn.example.com
                TDZ_OVPN_SUPPORT_USERNAME=TUSTDZ
                tdz_openvpn_apply_fixed_port_mapping
                TDZ_OVPN_TCP_SUBNET=10.100.10.0
                TDZ_OVPN_UDP_SUBNET=10.101.11.0
                mkdir -p "$TDZ_OVPN_PKI"
                printf 'test\n' > "$TDZ_OVPN_PKI/ca.crt"
                printf 'test\n' > "$TDZ_OVPN_PKI/server.key"
                tdz_openvpn_save_state || exit 20

                generated=0
                tdz_openvpn_generate_profiles() {{
                    ((generated += 1))
                    [[ "$TDZ_OVPN_SUPPORT_USERNAME" == NewSupport ]]
                }}
                tdz_openvpn_apply_private_permissions() {{ return 0; }}
                systemctl() {{ printf 'SYSTEMCTL_CALLED\n'; return 91; }}

                tdz_openvpn_configure_support_contact < {input_file} || exit 21
                [[ "$generated" == 1 ]] || exit 22
                tdz_openvpn_load_state || exit 23
                [[ "$TDZ_OVPN_SUPPORT_USERNAME" == NewSupport ]] || exit 24
                grep -q '^SUPPORT_USERNAME=NewSupport$' "$TDZ_OVPN_STATE" || exit 25
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertIn("changed to @NewSupport", result.stdout)
            self.assertIn("active VPN sessions were not restarted", result.stdout)
            self.assertNotIn("SYSTEMCTL_CALLED", result.stdout)

    def test_legacy_state_without_portal_port_uses_default(self):
        with tempfile.TemporaryDirectory() as temp:
            state = Path(temp) / "state.conf"
            state.write_text(
                "\n".join(
                    (
                        "VERSION=legacy",
                        "HOST=vpn.example.com",
                        "TCP_PORT=25001",
                        "UDP_PORT=25002",
                        "HTTP_PORT=25003",
                        "WSS_PORT=25004",
                        "SSL_PORT=25005",
                        "TCP_SUBNET=10.100.10.0",
                        "UDP_SUBNET=10.101.11.0",
                        "SERVICE_USER_CREATED=0",
                        "SERVICE_GROUP_CREATED=0",
                    )
                )
                + "\n"
            )
            result = self.run_bash(
                f"""
                TDZ_OVPN_STATE={state}
                tdz_openvpn_load_state || exit 20
                [[ "$TDZ_OVPN_PORTAL_PORT" == 1180 ]] || exit 21
                [[ "$TDZ_OVPN_TCP_PORT" == 25001 ]] || exit 22
                [[ "$TDZ_OVPN_SUPPORT_USERNAME" == TUSTDZ ]] || exit 23
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
            TDZ_OVPN_SUPPORT_USERNAME=TUSTDZ
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
            self.assertEqual(
                profile,
                """client
dev tun
proto tcp
remote vpn.example.com 447
resolv-retry infinite
nobind
persist-key
persist-tun
remote-cert-tls server
cipher AES-256-GCM
auth SHA256
verb 3
mute-replay-warnings
redirect-gateway def1
route 0.0.0.0 0.0.0.0
dhcp-option DNS 8.8.8.8
dhcp-option DNS 8.8.4.4
tun-mtu 1400
auth-user-pass
setenv CLIENT_CERT 0
keepalive 10 60

http-proxy vpn.example.com 449
http-proxy-option CUSTOM-HEADER CONNECT HTTP/1.1
http-proxy-option CUSTOM-HEADER Host vpn.example.com
http-proxy-option CUSTOM-HEADER X-Online-Host vpn.example.com
http-proxy-option CUSTOM-HEADER X-Forward-Host vpn.example.com
http-proxy-option CUSTOM-HEADER Connection Keep-Alive

<ca>
TEST CA
</ca>
<tls-crypt>
TEST TLS KEY
</tls-crypt>
""",
            )
            self.assertNotIn("password", profile.lower())
            self.assertNotIn("auth-nocache", profile)

            direct_profile = (root / "portal/ovpn-configs/tdz-openvpn-tcp.ovpn").read_text()
            self.assertIn("data-ciphers AES-128-GCM:AES-256-GCM", direct_profile)
            self.assertIn("setenv CLIENT_CERT 0", direct_profile)
            self.assertIn("tun-mtu 1400", direct_profile)
            self.assertNotIn("mssfix 1360", direct_profile)
            self.assertNotIn("route vpn.example.com 255.255.255.255 net_gateway", direct_profile)
            self.assertNotIn("route vpn.example.com 255.255.255.255 net_gateway", profile)
            udp_profile = (root / "portal/ovpn-configs/tdz-openvpn-udp.ovpn").read_text()
            self.assertIn("data-ciphers AES-256-GCM:AES-128-GCM", udp_profile)
            self.assertIn("setenv CLIENT_CERT 0", udp_profile)
            self.assertNotIn("tun-mtu 1400", udp_profile)
            for adapter_name in (
                "tdz-openvpn-ws-injector.ovpn",
                "tdz-openvpn-wss-injector.ovpn",
                "tdz-openvpn-ssl-injector.ovpn",
            ):
                adapter_profile = (root / "portal/ovpn-configs" / adapter_name).read_text()
                self.assertIn("cipher AES-256-GCM", adapter_profile)
                self.assertIn("setenv CLIENT_CERT 0", adapter_profile)
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
            logo_url = "https://raw.githubusercontent.com/yeasinulhoquetuhin/Tuhin-Droid-Zone/master/Screenshot_20260720-074518_Via.png"
            self.assertIn("Fast when it can be.", portal)
            self.assertIn('class="site-logo site-logo-header"', portal)
            self.assertIn(f'src="{logo_url}"', portal)
            self.assertIn('<span class="brand-copy"><strong>TDZ</strong>', portal)
            self.assertNotIn('class="signal-panel"', portal)
            self.assertNotIn("Gateway signal", portal)
            self.assertIn("From zero to connected in four steps", portal)
            self.assertIn("Six paths. One destination.", portal)
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
            self.assertIn("--bg:#edf7f2", css)
            self.assertIn("--bg:#07110d", css)
            self.assertIn("--accent:#047857", css)
            self.assertIn("--accent:#34d399", css)
            self.assertIn("--grid:rgba(4,120,87,.065)", css)
            self.assertIn("--button-text:#052e21", css)
            self.assertNotIn("--blue:", css)
            self.assertNotIn("#2878ff", css)
            self.assertNotIn("rgba(40,120,255", css)
            self.assertNotIn("#ef4050", css)
            self.assertNotIn("#ff5262", css)
            self.assertIn(':root[data-theme="dark"]', css)
            self.assertIn("@media(prefers-color-scheme:dark)", css)
            self.assertIn("backdrop-filter:blur(26px)", css)
            self.assertIn(".theme-switch{display:flex", css)
            self.assertIn('.theme-option[aria-pressed="true"]', css)
            self.assertIn(".site-logo-header{width:42px", css)
            self.assertIn("border-radius:13px", css)
            self.assertIn("object-fit:contain", css)
            self.assertIn("filter:blur(28px);opacity:.4", css)
            self.assertNotIn("translate(-32%", css)
            self.assertNotIn(".nav-link.active{box-shadow", css)
            self.assertIn(".support-banner{position:relative;display:grid", css)
            self.assertIn("background:linear-gradient(120deg,var(--accent-soft),var(--panel) 55%)", css)
            self.assertIn(".support-orb svg{width:29px", css)
            self.assertIn(".button.telegram{border-color:var(--accent)", css)
            self.assertNotIn(".radar-ring", css)
            self.assertNotIn(".signal-panel", css)
            self.assertIn(".developer-line .developer-link", css)
            self.assertIn(".project-spotlight{display:grid", css)
            self.assertIn(".footer-repo{display:inline-flex", css)
            self.assertIn(".footer-repo span{color:var(--accent)}", css)
            portal_js = (root / "portal/ovpn-configs/portal.js").read_text()
            self.assertIn("navigator.clipboard.writeText", portal_js)
            self.assertIn("window.localStorage", portal_js)
            self.assertIn('document.documentElement.setAttribute("data-theme"', portal_js)
            self.assertIn('window.matchMedia("(prefers-color-scheme: dark)")', portal_js)
            self.assertIn('[data-theme-option]', portal_js)
            self.assertTrue((root / "portal/ovpn-configs/openvpn-profiles.zip").is_file())
            self.assertFalse((root / "portal/ovpn-configs/tdz-logo.png").exists())
            self.assertFalse((root / "portal/ovpn-configs/tdz-favicon.svg").exists())

            visitor_pages = portal + docs + downloads
            self.assertIn("SSH/OVPN account", visitor_pages)
            self.assertNotIn("TDZ account", visitor_pages)
            self.assertNotIn("1180", visitor_pages)
            self.assertNotIn("External firewall", visitor_pages)
            self.assertNotIn("security group", visitor_pages)
            self.assertNotIn("VPS service", visitor_pages)
            self.assertIn("then contact support", docs)
            self.assertNotIn("brand-mark", visitor_pages)
            self.assertNotIn("<strong>PORTAL</strong>", visitor_pages)

            public = root / "portal/ovpn-configs"
            valid_pages = {
                "/openvpn/",
                "/openvpn/docs",
                "/openvpn/download",
                "/openvpn/assets/portal.css",
                "/openvpn/assets/portal.js",
                logo_url,
                "https://tuhinbro.com/",
                "https://t.me/TuhinBroh",
                "https://t.me/TUSTDZ",
                "https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT",
            }
            self.assertIn('class="section project-spotlight"', portal)
            self.assertIn("Part of TDZ SSH TUNNEL.", portal)
            self.assertIn("View GitHub repository", portal)
            self.assertNotIn("TDZ SSH TUNNEL powers both SSH and OpenVPN.", portal)
            self.assertNotIn('class="section project-spotlight"', docs + downloads)
            for page_name in ("index.html", "docs.html", "download.html"):
                page_text = (public / page_name).read_text()
                self.assertIn("<title>TDZ • OVPN PORTAL</title>", page_text)
                self.assertIn("Developed By:", page_text)
                self.assertIn("Yeasinul Hoque Tuhin", page_text)
                self.assertIn('class="developer-link" href="https://tuhinbro.com/"', page_text)
                self.assertIn("Telegram:", page_text)
                self.assertIn('href="https://t.me/TuhinBroh"', page_text)
                self.assertIn('href="https://t.me/TUSTDZ"', page_text)
                self.assertIn('<p class="developer-line footer-contact-line"><span>Contact:</span><a class="developer-link" href="https://t.me/TUSTDZ"', page_text)
                self.assertNotIn("Telegram @TUSTDZ", page_text)
                self.assertIn("No SSH/OVPN account yet? Start here.", page_text)
                self.assertIn("Get Account or Support", page_text)
                self.assertIn("Message @TUSTDZ", page_text)
                self.assertIn('<div class="support-orb" aria-hidden="true"><svg', page_text)
                self.assertNotIn("<span>✦</span>", page_text)
                self.assertIn(
                    'class="footer-repo" '
                    'href="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT"',
                    page_text,
                )
                self.assertNotIn("<h2>Developer</h2>", page_text)
                self.assertNotIn("Designed and developed", page_text)
                self.assertNotIn("© 2026", page_text)
                self.assertNotIn("All rights reserved", page_text)
                self.assertNotIn("Private routes. Clear setup.", page_text)
                self.assertIn('src="/openvpn/assets/portal.js"', page_text)
                self.assertIn(f'rel="icon" type="image/png" href="{logo_url}"', page_text)
                self.assertIn('class="site-logo site-logo-header"', page_text)
                self.assertNotIn('class="header-support"', page_text)
                self.assertIn('data-theme-option="light"', page_text)
                self.assertIn('data-theme-option="system"', page_text)
                self.assertIn('data-theme-option="dark"', page_text)
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
            self.assertNotIn("http://vpn.example.com:1180/openvpn/", guide)
            self.assertNotIn("Portal (HTTP):", guide)
            self.assertIn("https://vpn.example.com:1180/openvpn/docs", guide)
            self.assertIn("https://vpn.example.com:1180/openvpn/download", guide)
            self.assertIn("HTTPS is recommended for downloading profiles", guide)
            self.assertIn("public carrier endpoint outside the tunnel", guide)
            self.assertIn("Contact for account/support: @TUSTDZ (https://t.me/TUSTDZ)", guide)
            self.assertNotIn("route-gateway", guide)
            self.assertNotIn("/ovpn-configs", portal + docs + downloads + guide)
            self.assertNotIn("external firewall", guide.lower())
            self.assertNotIn("security group", guide.lower())

            (root / "portal/ovpn-configs/stale.ovpn").write_text("stale\n")
            regenerated = self.run_bash(script)
            self.assertEqual(regenerated.returncode, 0, regenerated.stderr)
            self.assertFalse((root / "portal/ovpn-configs/stale.ovpn").exists())
            self.assertEqual(list((root / "portal").glob(".ovpn-configs.*")), [])

    def test_custom_support_contact_propagates_to_every_portal_page(self):
        with tempfile.TemporaryDirectory() as temp:
            public = Path(temp) / "ovpn-configs"
            result = self.run_bash(
                f"""
                TDZ_OVPN_PROFILES={public}
                TDZ_OVPN_HOST=vpn.example.com
                TDZ_OVPN_SUPPORT_USERNAME=TeamHelp
                TDZ_OVPN_TCP_PORT=447
                TDZ_OVPN_UDP_PORT=448
                TDZ_OVPN_HTTP_PORT=449
                TDZ_OVPN_WSS_PORT=450
                TDZ_OVPN_SSL_PORT=446
                mkdir -p "$TDZ_OVPN_PROFILES"
                tdz_openvpn_generate_portal_html || exit 20
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            for page_name in ("index.html", "docs.html", "download.html"):
                page = (public / page_name).read_text()
                self.assertIn('href="https://t.me/TeamHelp"', page)
                self.assertIn("@TeamHelp", page)
                self.assertNotIn("https://t.me/TUSTDZ", page)

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

    def test_custom_ports_propagate_to_state_services_firewall_and_profiles(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            script = f"""
            TDZ_OVPN_ROOT={root}/openvpn
            TDZ_OVPN_STATE=$TDZ_OVPN_ROOT/state.conf
            TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
            TDZ_OVPN_RUN=$TDZ_OVPN_ROOT/run
            TDZ_OVPN_HOOKS=$TDZ_OVPN_ROOT/hooks
            TDZ_OVPN_PORTAL_BASE={root}/portal
            TDZ_OVPN_PROFILES=$TDZ_OVPN_PORTAL_BASE/ovpn-configs
            TDZ_OVPN_SYSTEMD_DIR={root}/systemd
            TDZ_OVPN_PAM_SERVICE={root}/pam/tdz-openvpn
            TDZ_OVPN_SYSCTL={root}/sysctl/tdz-openvpn.conf
            TDZ_OVPN_FIREWALL={root}/libexec/tdz-openvpn-firewall
            TDZ_OVPN_RUNTIME=/runtime-helper
            TDZ_OVPN_GATEWAY=/gateway-helper
            TDZ_OVPN_PORTAL=/portal-helper
            TDZ_OVPN_SERVICE_USER=root
            TDZ_OVPN_BIN=/bin/true
            TDZ_OVPN_HOST=vpn.example.com
            TDZ_OVPN_PORTAL_PORT=25100
            TDZ_OVPN_SSL_PORT=25101
            TDZ_OVPN_TCP_PORT=25102
            TDZ_OVPN_UDP_PORT=25103
            TDZ_OVPN_HTTP_PORT=25104
            TDZ_OVPN_WSS_PORT=25105
            TDZ_OVPN_TCP_SUBNET=10.100.10.0
            TDZ_OVPN_UDP_SUBNET=10.101.11.0
            TDZ_OVPN_IP_FORWARD_PREVIOUS=0
            tdz_openvpn_has_modern_cipher_option() {{ return 0; }}
            mkdir -p "$TDZ_OVPN_PKI" "$TDZ_OVPN_RUN" "$TDZ_OVPN_HOOKS"
            printf '%s\n' 'TEST CA' > "$TDZ_OVPN_PKI/ca.crt"
            printf '%s\n' 'TEST TLS KEY' > "$TDZ_OVPN_PKI/tls-crypt.key"
            : > "$TDZ_OVPN_PKI/gateway.crt"
            : > "$TDZ_OVPN_PKI/gateway.key"
            tdz_openvpn_save_state
            tdz_openvpn_write_server_config tcp tcp-server "$TDZ_OVPN_TCP_PORT" "$TDZ_OVPN_TCP_SUBNET" /pam-plugin.so
            tdz_openvpn_write_server_config udp udp "$TDZ_OVPN_UDP_PORT" "$TDZ_OVPN_UDP_SUBNET" /pam-plugin.so
            tdz_openvpn_generate_profiles
            tdz_openvpn_write_network_service
            tdz_openvpn_write_systemd_units
            """
            result = self.run_bash(script)
            self.assertEqual(result.returncode, 0, result.stderr)

            state = (root / "openvpn/state.conf").read_text()
            for entry in (
                "PORTAL_PORT=25100",
                "SSL_PORT=25101",
                "TCP_PORT=25102",
                "UDP_PORT=25103",
                "HTTP_PORT=25104",
                "WSS_PORT=25105",
            ):
                self.assertIn(entry, state)

            self.assertIn("port 25102", (root / "openvpn/server-tcp.conf").read_text())
            self.assertIn("port 25103", (root / "openvpn/server-udp.conf").read_text())
            firewall = (root / "libexec/tdz-openvpn-firewall").read_text()
            for entry in (
                'PORTAL_PORT="25100"',
                'SSL_PORT="25101"',
                'TCP_PORT="25102"',
                'UDP_PORT="25103"',
                'HTTP_PORT="25104"',
                'WSS_PORT="25105"',
                'IP_FORWARD_PREVIOUS="0"',
            ):
                self.assertIn(entry, firewall)

            systemd = root / "systemd"
            self.assertIn("--port 25100 ", (systemd / "tdz-openvpn-portal.service").read_text())
            self.assertIn("--port 25104 ", (systemd / "tdz-openvpn-http.service").read_text())
            self.assertIn("--backend-port 25102 ", (systemd / "tdz-openvpn-http.service").read_text())
            self.assertIn("--port 25105 ", (systemd / "tdz-openvpn-wss.service").read_text())
            self.assertIn("--port 25101 ", (systemd / "tdz-openvpn-ssl.service").read_text())

            profiles = root / "portal/ovpn-configs"
            self.assertIn("remote vpn.example.com 25103", (profiles / "tdz-openvpn-udp.ovpn").read_text())
            self.assertIn("remote vpn.example.com 25102", (profiles / "tdz-openvpn-tcp.ovpn").read_text())
            http_profile = (profiles / "tdz-openvpn-http-connect.ovpn").read_text()
            self.assertIn("remote vpn.example.com 25102", http_profile)
            self.assertIn("http-proxy vpn.example.com 25104", http_profile)
            self.assertIn("remote vpn.example.com 25104", (profiles / "tdz-openvpn-ws-injector.ovpn").read_text())
            self.assertIn("remote vpn.example.com 25105", (profiles / "tdz-openvpn-wss-injector.ovpn").read_text())
            self.assertIn("remote vpn.example.com 25101", (profiles / "tdz-openvpn-ssl-injector.ovpn").read_text())
            guide = (profiles / "connection-guide.txt").read_text()
            self.assertIn("https://vpn.example.com:25100/openvpn/", guide)

    def test_failed_port_change_restores_previous_state(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            result = self.run_bash(
                f"""
                TDZ_OVPN_ROOT={root}/openvpn
                TDZ_OVPN_STATE=$TDZ_OVPN_ROOT/state.conf
                TDZ_OVPN_PKI=$TDZ_OVPN_ROOT/pki
                TDZ_OVPN_HOST=vpn.example.com
                TDZ_OVPN_PORTAL_PORT=1180
                TDZ_OVPN_SSL_PORT=446
                TDZ_OVPN_TCP_PORT=447
                TDZ_OVPN_UDP_PORT=448
                TDZ_OVPN_HTTP_PORT=449
                TDZ_OVPN_WSS_PORT=450
                TDZ_OVPN_TCP_SUBNET=10.100.10.0
                TDZ_OVPN_UDP_SUBNET=10.101.11.0
                mkdir -p "$TDZ_OVPN_PKI"
                : > "$TDZ_OVPN_PKI/ca.crt"
                : > "$TDZ_OVPN_PKI/server.key"
                tdz_openvpn_save_state || exit 20

                tdz_openvpn_python_supported() {{ return 0; }}
                tdz_openvpn_resolve_binary() {{ TDZ_OVPN_BIN=/bin/true; return 0; }}
                tdz_openvpn_find_pam_plugin() {{ printf /pam-plugin.so; }}
                tdz_openvpn_ensure_service_user() {{ return 0; }}
                tdz_openvpn_snapshot_runtime() {{ mkdir -p "$1"; cp "$TDZ_OVPN_STATE" "$1/original-state"; }}
                tdz_openvpn_stop_services() {{ return 0; }}
                tdz_openvpn_selected_ports_free() {{ return 0; }}
                tdz_openvpn_ensure_pki() {{ return 0; }}
                tdz_openvpn_write_hooks() {{ return 0; }}
                tdz_openvpn_prepare_gateway_certificate() {{ return 0; }}
                tdz_openvpn_write_pam() {{ return 0; }}
                tdz_openvpn_write_server_config() {{ return 0; }}
                tdz_openvpn_generate_profiles() {{ return 0; }}
                tdz_openvpn_apply_private_permissions() {{ return 0; }}
                tdz_openvpn_write_network_service() {{ return 0; }}
                tdz_openvpn_write_systemd_units() {{ return 0; }}
                tdz_openvpn_validate_runtime_files() {{ return 0; }}
                tdz_openvpn_start_services() {{ return 1; }}
                tdz_openvpn_restore_snapshot() {{ cp "$1/original-state" "$TDZ_OVPN_STATE"; tdz_openvpn_load_state; }}
                tdz_openvpn_show_details() {{ return 0; }}

                if tdz_openvpn_apply_port_layout 25100 25101 25102 25103 25104 25105; then
                    exit 21
                fi
                tdz_openvpn_load_state || exit 22
                [[ "$TDZ_OVPN_PORTAL_PORT" == 1180 ]] || exit 23
                [[ "$TDZ_OVPN_SSL_PORT" == 446 ]] || exit 24
                [[ "$TDZ_OVPN_TCP_PORT" == 447 ]] || exit 25
                [[ "$TDZ_OVPN_UDP_PORT" == 448 ]] || exit 26
                [[ "$TDZ_OVPN_HTTP_PORT" == 449 ]] || exit 27
                [[ "$TDZ_OVPN_WSS_PORT" == 450 ]] || exit 28
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)

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
                TDZ_OVPN_IP_FORWARD_PREVIOUS=0
                tdz_openvpn_save_state || exit 20
                TDZ_OVPN_SERVICE_USER_CREATED=0
                TDZ_OVPN_SERVICE_GROUP_CREATED=0
                TDZ_OVPN_IP_FORWARD_PREVIOUS=""
                tdz_openvpn_load_state || exit 21
                [[ "$TDZ_OVPN_SERVICE_USER_CREATED" == 1 ]] || exit 22
                [[ "$TDZ_OVPN_SERVICE_GROUP_CREATED" == 1 ]] || exit 23
                [[ "$TDZ_OVPN_IP_FORWARD_PREVIOUS" == 0 ]] || exit 24
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)

    def test_limiter_uses_the_shared_first_use_lock(self):
        menu = (REPO / "menu.sh").read_text()
        start = menu.index("activate_pending_account() (")
        end = menu.index("\n)\n\nload_banner_identity", start)
        activation = menu[start:end]
        self.assertIn('exec 8>"$USAGE_LOCK"', activation)
        self.assertIn("flock -x 8", activation)
        self.assertIn("active:*", activation)
        self.assertNotIn("activate_pending_account() {", activation)

    def test_limiter_never_evicts_established_sessions_for_connection_limit(self):
        menu = (REPO / "menu.sh").read_text()
        self.assertIn("# TDZ SSH TUNNEL limiter version 2026-07-20.5", menu)
        self.assertNotIn("if (( online_count > limit )); then", menu)
        self.assertIn(
            "Connection limits are enforced atomically by the SSH account hook",
            menu,
        )
        self.assertIn("banner_session_count=$online_count", menu)
        self.assertNotIn("banner_session_count=$((online_count + 1))", menu)
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
        refresh_end = menu.index(
            "\n}\n\nprovision_dynamic_banners_for_new_users", refresh_start
        )
        refresh = menu[refresh_start:refresh_end]
        self.assertIn('[[ -f "/etc/tdztunnel/banners_enabled" ]]', refresh)
        self.assertNotIn("is_dynamic_ssh_banner_enabled", refresh)
        self.assertIn('-s "$banner_dir/${user}.txt"', refresh)
        self.assertIn('users+=("$user")', refresh)
        self.assertLess(
            refresh.index("systemctl start tdztunnel-limiter"),
            refresh.index('-s "$banner_dir/${user}.txt"'),
        )
        self.assertLess(
            refresh.index('-s "$banner_dir/${user}.txt"'),
            refresh.index("update_ssh_banners_config || return 1"),
        )

        provision_start = menu.index("provision_dynamic_banners_for_new_users() {")
        provision_end = menu.index("\n}\n\nupdate_ssh_banners_config", provision_start)
        provision = menu[provision_start:provision_end]
        self.assertIn('rm -f "$DB_DIR/banners/${user}.txt"', provision)
        self.assertIn('refresh_dynamic_banner_routing_if_enabled "${users[@]}"', provision)

        limiter_start = menu.index("# TDZ SSH TUNNEL limiter version 2026-07-20.5")
        limiter_end = menu.index("\nEOF\n    chmod +x \"$LIMITER_SCRIPT\"", limiter_start)
        limiter = menu[limiter_start:limiter_end]
        self.assertIn('${#unique_sshd_sessions[@]} -gt 0', limiter)
        self.assertIn('${#unique_pam_sessions[@]} -gt 0', limiter)
        self.assertNotIn('${#unique_pids[@]} -gt 0', limiter)
        self.assertNotIn('online_count=1\n', limiter)
        self.assertIn(
            'printf \'%s\\t%s\\n\' "$user" "$online_count" >> "$SSH_SESSION_SNAPSHOT_TMP"',
            limiter,
        )
        self.assertIn(
            'mv -f "$SSH_SESSION_SNAPSHOT_TMP" "$SSH_SESSION_SNAPSHOT"',
            limiter,
        )

        cache_start = menu.index("refresh_ssh_session_cache() {")
        cache_end = menu.index("\n}\n\ncount_managed_online_sessions", cache_start)
        cache = menu[cache_start:cache_end]
        self.assertIn('pam_session_pids["$marker_user"]', cache)
        self.assertIn('SSH_SESSION_COUNTS["$user"]=$_conns', cache)

    def test_dynamic_banner_uses_authenticated_pam_account_delivery(self):
        menu = (REPO / "menu.sh").read_text()
        installer = (REPO / "install.sh").read_text()
        helper = (REPO / "tdz_ssh_auth_session.py").read_text()

        hook_start = menu.index("setup_ssh_auth_session_hook() {")
        hook_end = menu.index("\n}\n\nremove_ssh_auth_session_hook", hook_start)
        hook = menu[hook_start:hook_end]
        self.assertIn(
            "account requisite pam_exec.so quiet stdout type=account",
            hook,
        )
        self.assertIn(
            "auth requisite pam_exec.so quiet type=auth",
            hook,
        )
        self.assertNotIn(
            "auth requisite pam_exec.so quiet stdout type=auth",
            hook,
        )
        self.assertIn("common-auth", hook)
        self.assertIn('cat "$body_file"', hook)
        self.assertLess(
            hook.index('printf \'%s\\n%s\\n%s\\n\''),
            hook.index('cat "$body_file"'),
        )
        self.assertNotIn("expose_authtok", hook)
        self.assertIn(
            'install -d -o root -g root -m 700 "$SSH_AUTH_SESSION_DIR"',
            hook,
        )
        self.assertIn('[[ "$registry_security" == "0:0:700" ]]', hook)

        config_start = menu.index("update_ssh_banners_config() {")
        config_end = menu.index("\n}\n\nsetup_ssh_login_info", config_start)
        config = menu[config_start:config_end]
        self.assertIn("authenticated dynamic account banners", config)
        self.assertNotIn("Banner /etc/tdztunnel/banners/", config)
        self.assertNotIn("Match User", config)

        self.assertIn("tdz_ssh_auth_session.py|$PAYLOAD_SSH_AUTH_SESSION", installer)
        self.assertLess(
            installer.index(
                'install -m 755 "$PAYLOAD_SSH_AUTH_SESSION" "$TARGET_SSH_AUTH_SESSION"'
            ),
            installer.index(
                'install -m 755 "$PAYLOAD_OVPN_RUNTIME" "$TARGET_OVPN_RUNTIME"'
            ),
        )
        self.assertIn('env.get("PAM_SERVICE") != "sshd"', helper)
        self.assertIn('pam_type not in ("auth", "account")', helper)
        self.assertIn('return LoginDecision("", False, "retry_guard")', helper)
        self.assertIn("identity.start_time == expected_start", helper)
        self.assertIn('return 0 if decision.allowed else 1', helper)

    def test_pam_retry_guard_is_after_common_auth_and_hook_is_idempotent(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            pam_config = root / "sshd"
            session_dir = root / "ssh-auth-sessions"
            helper = REPO / "tdz_ssh_auth_session.py"
            pam_config.write_text(
                "# PAM configuration for sshd\n"
                "@include common-auth\n"
                "account required pam_nologin.so\n"
                "@include common-account\n"
            )
            result = self.run_menu_bash(
                f"""
                SSH_PAM_CONFIG={pam_config}
                SSH_AUTH_SESSION_DIR={session_dir}
                SSH_AUTH_SESSION_HELPER={helper}
                setup_ssh_auth_session_hook || exit 20
                setup_ssh_auth_session_hook || exit 21
                cat "$SSH_PAM_CONFIG"
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            lines = result.stdout.splitlines()
            account_line = (
                "account requisite pam_exec.so quiet stdout type=account "
                + str(helper)
            )
            auth_line = (
                "auth requisite pam_exec.so quiet type=auth " + str(helper)
            )
            self.assertEqual(lines.count(account_line), 1)
            self.assertEqual(lines.count(auth_line), 1)
            self.assertLess(lines.index(account_line), lines.index("@include common-account"))
            self.assertLess(lines.index("@include common-auth"), lines.index(auth_line))
            self.assertEqual(session_dir.stat().st_mode & 0o777, 0o700)

    def test_custom_pam_without_common_auth_keeps_account_hook_only(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            pam_config = root / "sshd"
            session_dir = root / "ssh-auth-sessions"
            helper = REPO / "tdz_ssh_auth_session.py"
            pam_config.write_text(
                "auth required pam_unix.so\n"
                "account required pam_unix.so\n"
            )
            result = self.run_menu_bash(
                f"""
                SSH_PAM_CONFIG={pam_config}
                SSH_AUTH_SESSION_DIR={session_dir}
                SSH_AUTH_SESSION_HELPER={helper}
                setup_ssh_auth_session_hook || exit 30
                cat "$SSH_PAM_CONFIG"
                """
            )
            self.assertEqual(result.returncode, 0, result.stderr)
            self.assertIn("type=account", result.stdout)
            self.assertNotIn("type=auth", result.stdout)

    def test_new_accounts_provision_dynamic_banner_before_follow_up_ui(self):
        menu = (REPO / "menu.sh").read_text()

        create_start = menu.index("create_user() {")
        create_end = menu.index("\n}\n\ndelete_user()", create_start)
        create = menu[create_start:create_end]
        create_db = create.index(
            'echo "$username:$password:$stored_expiry:$limit:$bandwidth_gb$metadata_suffix" >> "$DB_FILE"'
        )
        create_sync = create.index(
            'provision_dynamic_banners_for_new_users "$username"'
        )
        create_details = create.index("clear; show_banner", create_db)
        create_config_prompt = create.index("Generate client configuration now?")
        self.assertLess(create_db, create_sync)
        self.assertLess(create_sync, create_details)
        self.assertLess(create_sync, create_config_prompt)
        self.assertEqual(
            create.count('provision_dynamic_banners_for_new_users "$username"'), 1
        )

        trial_start = menu.index("create_trial_account() {")
        trial_end = menu.index("\n}\n\nformat_trial_time_left()", trial_start)
        trial = menu[trial_start:trial_end]
        trial_db = trial.index(
            'echo "$username:$password:$expire_date:$limit:$bandwidth_gb:trial:$expiry_epoch" >> "$DB_FILE"'
        )
        trial_sync = trial.index(
            'provision_dynamic_banners_for_new_users "$username"'
        )
        trial_details = trial.index("clear; show_banner", trial_db)
        trial_config_prompt = trial.index("Generate client configuration now?")
        self.assertLess(trial_db, trial_sync)
        self.assertLess(trial_sync, trial_details)
        self.assertLess(trial_sync, trial_config_prompt)

        bulk_start = menu.index("bulk_create_users() {")
        bulk_end = menu.index("\n}\n\ngenerate_client_config()", bulk_start)
        bulk = menu[bulk_start:bulk_end]
        bulk_db = bulk.index(
            'echo "$username:$password:$stored_expiry:$limit:$bandwidth_gb$metadata_suffix" >> "$DB_FILE"'
        )
        bulk_sync = bulk.index(
            'provision_dynamic_banners_for_new_users "${created_usernames[@]}"'
        )
        bulk_success = bulk.index('tdz_message OK "Created $created account(s).')
        self.assertLess(bulk_db, bulk_sync)
        self.assertLess(bulk_sync, bulk_success)

        provision_start = menu.index("provision_dynamic_banners_for_new_users() {")
        provision_end = menu.index("\n}\n\nupdate_ssh_banners_config", provision_start)
        provision = menu[provision_start:provision_end]
        self.assertIn('$SSH_AUTH_SESSION_DIR/${user}.denied', provision)

        delete_start = menu.index("delete_tdztunnel_user_accounts() {")
        delete_end = menu.index("\n}\n\nrequire_interactive_terminal", delete_start)
        delete_accounts = menu[delete_start:delete_end]
        self.assertIn('$SSH_AUTH_SESSION_DIR/${username}.denied', delete_accounts)

        setup_start = menu.index("setup_ssh_login_info() {")
        setup_end = menu.index("\n}\n\n\ndomain_cert_menu()", setup_start)
        setup = menu[setup_start:setup_end]
        self.assertIn("refresh_dynamic_banner_routing_if_enabled", setup)
        self.assertNotIn("update_ssh_banners_config\n", setup)

    def test_main_dashboard_keeps_openvpn_status_inside_protocol_suite(self):
        menu = (REPO / "menu.sh").read_text()
        main_start = menu.index("main_menu() {")
        main = menu[main_start:]
        service_start = main.index('tdz_box_header "SERVICE STATUS"')
        service_end = main.index("# ── SECTION 3: USER MANAGEMENT", service_start)
        service_block = main[service_start:service_end]
        self.assertNotIn("OpenVPN Suite", service_block)
        self.assertNotIn("TDZ_OVPN_PORTAL_PORT", service_block)

        protocol_start = menu.index("protocol_menu() {")
        protocol_end = menu.index("\n}\n\nuninstall_script()", protocol_start)
        protocol = menu[protocol_start:protocol_end]
        self.assertIn('tdz_menu_status "[10]" "OpenVPN Protocol Suite"', protocol)

    def test_protocol_manager_numbering_is_sequential(self):
        menu = (REPO / "menu.sh").read_text()
        start = menu.index("protocol_menu() {")
        end = menu.index("\n}\n\nuninstall_script()", start)
        protocol = menu[start:end]
        openvpn = protocol.index('tdz_menu_status "[10]" "OpenVPN Protocol Suite"')
        self.assertIn("10) if declare -F tdz_openvpn_menu", protocol)
        self.assertNotIn("MANAGEMENT PANELS", protocol)
        self.assertNotIn("11)", protocol)
        self.assertNotIn("12) tdz_run_action", protocol)
        self.assertNotRegex(menu, r"(?i)x[-_]?ui")
        self.assertNotRegex((REPO / "README.md").read_text(), r"(?i)x[-_]?ui")

        traffic_start = menu.index("traffic_monitor_menu() {")
        traffic_end = menu.index("\n}\n\nauto_reboot_menu()", traffic_start)
        traffic = menu[traffic_start:traffic_end]
        self.assertIn('tdz_menu1 "[ 1]" "Live Monitor"', traffic)
        self.assertNotIn("No Installation", traffic)

        openvpn_module = MODULE.read_text()
        suite_start = openvpn_module.index("tdz_openvpn_menu() {")
        suite = openvpn_module[suite_start:]
        self.assertIn('tdz_menu1 "[ 8]" "Change Contact Username"', suite)
        self.assertIn("8) tdz_run_action tdz_openvpn_configure_support_contact", suite)


if __name__ == "__main__":
    unittest.main()
