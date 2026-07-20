#!/usr/bin/env python3

import subprocess
import shutil
import tempfile
import unittest
from html.parser import HTMLParser
from pathlib import Path


REPO = Path(__file__).resolve().parents[1]
MODULE = REPO / "openvpn_module.sh"
MENU = REPO / "menu.sh"


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

    def test_lock_and_unlock_selectors_only_show_actionable_accounts(self):
        with tempfile.TemporaryDirectory() as temp:
            root = Path(temp)
            database = root / "users.db"
            lock_input = root / "lock-input"
            unlock_input = root / "unlock-input"
            database.write_text(
                "alice:pass:Never:1:0\n"
                "bob:pass:Never:1:0\n"
                "carol:pass:Never:1:0\n"
            )
            lock_input.write_text("all\n")
            unlock_input.write_text("all\n")

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
                id() {{
                    case "$1" in
                        alice|bob|carol) return 0 ;;
                        *) return 1 ;;
                    esac
                }}
                passwd() {{
                    [[ "$1" == "-S" ]] || return 1
                    case "$2" in
                        alice) printf 'alice P 2026-07-20 0 99999 7 -1\n' ;;
                        bob) printf 'bob L 2026-07-20 0 99999 7 -1\n' ;;
                        carol) printf 'carol NP 2026-07-20 0 99999 7 -1\n' ;;
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
            lock_input = root / "lock-input"
            unlock_input = root / "unlock-input"
            original_row = "alice:pass:Never:2:10\n"
            database.write_text(original_row)
            lock_input.write_text("all\n")
            unlock_input.write_text("all\n")

            result = self.run_menu_bash(
                f"""
                DB_FILE={database}
                mock_passwd_state=P
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
                passwd() {{
                    [[ "$1" == "-S" && "$2" == alice ]] || return 1
                    printf 'alice %s 2026-07-20 0 99999 7 -1\n' "$mock_passwd_state"
                }}
                usermod() {{
                    case "$1:$2" in
                        -L:alice) mock_passwd_state=L ;;
                        -U:alice) mock_passwd_state=P ;;
                        *) return 1 ;;
                    esac
                }}
                tdz_openvpn_kill_user() {{ ((vpn_kills += 1)); }}
                killall() {{ ((process_kills += 1)); }}

                lock_user < {lock_input}
                [[ "$mock_passwd_state" == L ]] || exit 30
                [[ "$vpn_kills" == 1 && "$process_kills" == 1 ]] || exit 31
                [[ "$(cat "$DB_FILE")" == 'alice:pass:Never:2:10' ]] || exit 32

                unlock_user < {unlock_input}
                [[ "$mock_passwd_state" == P ]] || exit 33
                [[ "$(cat "$DB_FILE")" == 'alice:pass:Never:2:10' ]] || exit 34
                """
            )
            self.assertEqual(
                result.returncode, 0, result.stderr + "\n" + result.stdout
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
        self.assertIn("# TDZ SSH TUNNEL limiter version 2026-07-20.2", menu)
        self.assertIn("if (( online_count > limit )); then", menu)
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

        limiter_start = menu.index("# TDZ SSH TUNNEL limiter version 2026-07-20.2")
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
            "account optional pam_exec.so quiet stdout type=account",
            hook,
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
        self.assertIn('env.get("PAM_SERVICE") != "sshd"', helper)
        self.assertIn('env.get("PAM_TYPE") != "account"', helper)
        self.assertIn("identity.start_time == expected_start", helper)

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
        install_xui = protocol.index('tdz_menu_status "[11]" "Install X-UI')
        uninstall_xui = protocol.index('tdz_menu1 "[12]" "Uninstall X-UI Panel"')
        self.assertLess(openvpn, install_xui)
        self.assertLess(install_xui, uninstall_xui)
        self.assertIn("10) if declare -F tdz_openvpn_menu", protocol)
        self.assertIn("11) install_xui_panel", protocol)
        self.assertIn("12) uninstall_xui_panel", protocol)

        openvpn_module = MODULE.read_text()
        suite_start = openvpn_module.index("tdz_openvpn_menu() {")
        suite = openvpn_module[suite_start:]
        self.assertIn('tdz_menu1 "[ 8]" "Change Contact Username"', suite)
        self.assertIn("8) tdz_openvpn_configure_support_contact", suite)


if __name__ == "__main__":
    unittest.main()
