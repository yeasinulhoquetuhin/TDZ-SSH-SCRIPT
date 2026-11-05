#!/usr/bin/env python3
"""Exercise DNSTT installation and migration without touching host services."""

import json
import os
import re
import shlex
import shutil
import subprocess
import tempfile
import unittest
from pathlib import Path


MENU = Path(__file__).resolve().parents[1] / "menu.sh"

FAKE_IPTABLES = r'''#!/usr/bin/env python3
import json
import os
import sys
from pathlib import Path

root = Path(os.environ["TDZ_DNSTT_TEST_ROOT"])
args = sys.argv[1:]
with (root / "iptables.calls").open("a") as handle:
    handle.write(json.dumps([Path(sys.argv[0]).name] + args) + "\n")
args = args[2:] if args[:1] == ["-w"] else args
table = "filter"
if args[:1] == ["-t"]:
    table, args = args[1], args[2:]
operation, chain, *rule = args
if operation == "-I":
    rule = rule[1:]
entry = [Path(sys.argv[0]).name, table, chain, rule]
state_file = root / "rules.json"
state = json.loads(state_file.read_text()) if state_file.exists() else []
if operation == "-C":
    sys.exit(0 if entry in state else 1)
if operation == "-I":
    if table == "nat" and os.environ.get("TDZ_DNSTT_FAIL_NAT") == "1":
        sys.exit(1)
    state.append(entry)
elif operation == "-D":
    if os.environ.get("TDZ_DNSTT_FAIL_DELETE") == "1":
        sys.exit(1)
    state.remove(entry)
else:
    sys.exit(2)
state_file.write_text(json.dumps(state))
'''

FAKE_SYSTEMCTL = r'''#!/usr/bin/env python3
import json
import os
import subprocess
import sys
from pathlib import Path

root = Path(os.environ["TDZ_DNSTT_TEST_ROOT"])
with (root / "systemctl.calls").open("a") as handle:
    handle.write(json.dumps(sys.argv[1:]) + "\n")
state_file = root / "services.json"
state = json.loads(state_file.read_text()) if state_file.exists() else {}
action = sys.argv[1]
unit = sys.argv[-1]
if unit.endswith(".service"):
    unit = unit[:-len(".service")]
network = root / "dnstt" / "network.sh"

def save():
    state_file.write_text(json.dumps(state))

def network_stop():
    if state.get("tdz-dnstt-network"):
        result = subprocess.run(["bash", str(network), "stop"])
        if result.returncode:
            sys.exit(result.returncode)
    state["tdz-dnstt-network"] = False

if action in ("is-active", "is-enabled"):
    sys.exit(0 if state.get(unit) else 1)
if action == "stop":
    if unit in ("dnstt", "tdz-dnstt-network"):
        network_stop()
    state[unit] = False
elif action == "start" and unit == "dnstt":
    service = (root / "systemd" / "dnstt.service").read_text()
    if "Requires=tdz-dnstt-network.service" in service:
        result = subprocess.run(["bash", str(network), "start"])
        if result.returncode:
            sys.exit(result.returncode)
        state["tdz-dnstt-network"] = True
    if "-udp :54" in service and os.environ.get("TDZ_DNSTT_FAIL_START") == "1":
        save()
        sys.exit(1)
    state[unit] = True
save()
'''


class DnsttTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.bin = self.root / "bin"
        self.systemd = self.root / "systemd"
        self.keys = self.root / "dnstt"
        for directory in (self.bin, self.systemd, self.keys):
            directory.mkdir()
        self.service = self.systemd / "dnstt.service"
        self.network_service = self.systemd / "tdz-dnstt-network.service"
        self.network_script = self.keys / "network.sh"
        self.config = self.root / "dnstt_info.conf"
        self.resolver = self.root / "resolv.conf"
        self.resolver.write_text("nameserver 127.0.0.53\n")
        for name, source in (("iptables", FAKE_IPTABLES), ("ip6tables", FAKE_IPTABLES),
                             ("systemctl", FAKE_SYSTEMCTL)):
            executable = self.bin / name
            executable.write_text(source)
            executable.chmod(0o755)
        self.environment = dict(os.environ, PATH=f"{self.bin}:{os.environ['PATH']}",
                                TDZ_DNSTT_TEST_ROOT=str(self.root), PYTHONDONTWRITEBYTECODE="1")

    def run_menu(self, body, **environment):
        assignments = {
            "DNSTT_SERVICE_FILE": self.service,
            "DNSTT_NETWORK_SERVICE_FILE": self.network_service,
            "DNSTT_NETWORK_SCRIPT": self.network_script,
            "DNSTT_KEYS_DIR": self.keys,
            "DNSTT_CONFIG_FILE": self.config,
            "DNSTT_BINARY": self.bin / "dnstt-server",
            "DNSTT_RESOLVER_STATE_FILE": self.keys / "resolver.state",
            "DNSTT_RESOLV_BACKUP": self.keys / "resolv.conf.before",
            "TDZ_RESOLV_CONF": self.resolver,
        }
        setup = "\n".join(f"{key}={shlex.quote(str(value))}" for key, value in assignments.items())
        return subprocess.run(
            ["bash", "-c", f"source {shlex.quote(str(MENU))} --source-only\n{setup}\n"
             "clear() { :; }; show_banner() { :; }; sleep() { :; }\n" + body],
            env=dict(self.environment, **environment), text=True, capture_output=True,
            check=False, timeout=30,
        )

    def read_json(self, name, default=None):
        path = self.root / name
        return json.loads(path.read_text()) if path.exists() else default

    def calls(self):
        path = self.root / "systemctl.calls"
        return [json.loads(line) for line in path.read_text().splitlines()] if path.exists() else []

    def seed_legacy(self, active=True):
        self.service.write_text(
            "[Unit]\nDescription=DNSTT\nAfter=network.target\n[Service]\n"
            f"ExecStart={self.bin}/dnstt-server -udp :53 -mtu 512 "
            f"-privkey-file {self.keys}/server.key ns.sgx.example.com 127.0.0.1:22\n"
            "Restart=always\n[Install]\nWantedBy=multi-user.target\n"
        )
        self.config.write_text('TUNNEL_DOMAIN="ns.sgx.example.com"\nPUBLIC_KEY="keep-public-key"\n'
                               'FORWARD_DESC="SSH (port 22)"\nNS_DOMAIN="sgx.example.com"\n')
        (self.keys / "server.key").write_text("keep-private-key\n")
        (self.root / "services.json").write_text(json.dumps({"dnstt": active}))

    def test_network_rules_are_scoped_idempotent_and_removed_without_other_rules(self):
        unrelated = ["iptables", "filter", "INPUT", ["-p", "tcp", "--dport", "22", "-j", "ACCEPT"]]
        (self.root / "rules.json").write_text(json.dumps([unrelated]))
        result = self.run_menu('write_dnstt_network_service && bash "$DNSTT_NETWORK_SCRIPT" start '
                               '&& bash "$DNSTT_NETWORK_SCRIPT" start')
        self.assertEqual(result.returncode, 0, result.stderr)
        rules = self.read_json("rules.json")
        managed = [entry for entry in rules if entry != unrelated]
        self.assertEqual(len(managed), len({json.dumps(entry) for entry in managed}))
        self.assertIn("iptables", {entry[0] for entry in managed})
        if Path("/proc/net/if_inet6").read_text().strip():
            self.assertIn("ip6tables", {entry[0] for entry in managed})
        for _, table, chain, rule in managed:
            if table == "nat":
                self.assertEqual(chain, "PREROUTING")
                self.assertEqual(rule[rule.index("--dport") + 1], "53")
                self.assertEqual(rule[rule.index("--to-ports") + 1], "54")
                self.assertIn("LOCAL", rule)
                self.assertEqual(rule[:3], ["!", "-i", "lo"])
            else:
                self.assertEqual(chain, "INPUT")
                self.assertEqual(rule[rule.index("--dport") + 1], "54")
        self.assertIn("PartOf=dnstt.service", self.network_service.read_text())
        self.assertIn("RemainAfterExit=yes", self.network_service.read_text())
        result = self.run_menu('bash "$DNSTT_NETWORK_SCRIPT" stop && bash "$DNSTT_NETWORK_SCRIPT" stop')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(self.read_json("rules.json"), [unrelated])

    def test_partial_forwarding_failure_rolls_back_filter_rules(self):
        result = self.run_menu('write_dnstt_network_service && bash "$DNSTT_NETWORK_SCRIPT" start',
                               TDZ_DNSTT_FAIL_NAT="1")
        self.assertNotEqual(result.returncode, 0)
        self.assertEqual(self.read_json("rules.json"), [])

    def test_existing_install_migrates_preserving_keys_and_client_details(self):
        self.seed_legacy()
        old_config = self.config.read_bytes()
        result = self.run_menu('ss() { return 0; }; refresh_dnstt_runtime || exit 21; '
                               'refresh_dnstt_runtime || exit 22; show_dnstt_details; '
                               'curl() { printf "203.0.113.1\\n"; }; '
                               'detect_preferred_host() { printf "sgx.example.com\\n"; }; '
                               'generate_client_config testuser testpass')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("-udp :54 -mtu 512", self.service.read_text())
        self.assertIn("ns.sgx.example.com 127.0.0.1:22", self.service.read_text())
        self.assertEqual(self.config.read_bytes(), old_config)
        self.assertEqual((self.keys / "server.key").read_text(), "keep-private-key\n")
        plain = re.sub(r"\x1b\[[0-9;]*[A-Za-z]", "", result.stdout)
        for section in ("DNSTT CONNECTION DETAILS", "DNSTT / SLOWDNS"):
            details = plain.split(section, 1)[1]
            self.assertRegex(details, r"Public DNS Port:\s+53 / UDP")
            self.assertRegex(details, r"DNSTT Listener:\s+54 / UDP \(server-side\)")
            self.assertRegex(details, r"SSH Port:\s+22 / TCP")
        self.assertIn("1.1.1.1:53 / 8.8.8.8:53", plain)
        self.assertEqual(self.calls().count(["start", "dnstt.service"]), 1)
        self.assertEqual(self.resolver.read_text(), "nameserver 127.0.0.53\n")

    def test_failed_service_migration_restores_working_legacy_install(self):
        self.seed_legacy()
        old_service = self.service.read_bytes()
        result = self.run_menu('ss() { return 0; }; refresh_dnstt_runtime', TDZ_DNSTT_FAIL_START="1")
        self.assertNotEqual(result.returncode, 0)
        self.assertEqual(self.service.read_bytes(), old_service)
        self.assertTrue(self.read_json("services.json")["dnstt"])
        self.assertEqual(self.read_json("rules.json"), [])
        self.assertFalse(self.network_service.exists())
        self.assertFalse(self.network_script.exists())
        self.assertEqual((self.keys / "server.key").read_text(), "keep-private-key\n")

    def test_client_config_only_shows_ssh_dns_backend(self):
        self.seed_legacy()
        for backend, visible in (("SSH (port 22)", True), ("V2Ray (port 8787)", False),
                                 (None, False)):
            with self.subTest(backend=backend):
                self.config.write_text(
                    'TUNNEL_DOMAIN="dns-only.example.com"\nPUBLIC_KEY="dns-only-public-key"\n'
                    + (f'FORWARD_DESC="{backend}"\n' if backend is not None else "")
                )
                result = self.run_menu('FORWARD_DESC="SSH (port 22)"; '
                                       'curl() { printf "203.0.113.1\\n"; }; '
                                       'detect_preferred_host() { printf "ssh.example.com\\n"; }; '
                                       'generate_client_config testuser testpass')
                self.assertEqual(result.returncode, 0, result.stderr)
                self.assertIn("SSH DIRECT", result.stdout)
                for detail in ("DNSTT / SLOWDNS", "dns-only.example.com", "dns-only-public-key"):
                    self.assertEqual(detail in result.stdout, visible, detail)

    def test_stopped_service_is_migrated_without_starting_or_enabling(self):
        self.seed_legacy(active=False)
        result = self.run_menu('ss() { return 0; }; refresh_dnstt_runtime')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("-udp :54", self.service.read_text())
        self.assertFalse(any(call[0] in ("start", "enable") for call in self.calls()))
        self.assertFalse(self.read_json("services.json")["dnstt"])

    def test_failed_network_migration_restores_legacy_service(self):
        self.seed_legacy()
        old_service = self.service.read_bytes()
        result = self.run_menu('ss() { return 0; }; refresh_dnstt_runtime', TDZ_DNSTT_FAIL_NAT="1")
        self.assertNotEqual(result.returncode, 0)
        self.assertEqual(self.service.read_bytes(), old_service)
        self.assertTrue(self.read_json("services.json")["dnstt"])
        self.assertEqual(self.read_json("rules.json"), [])
        self.assertFalse(self.network_script.exists())

    def test_occupied_listener_aborts_before_changing_existing_service(self):
        self.seed_legacy()
        old_service = self.service.read_bytes()
        result = self.run_menu('ss() { printf "UNCONN 0 0 0.0.0.0:54 0.0.0.0:*\\n"; }; '
                               'refresh_dnstt_runtime')
        self.assertNotEqual(result.returncode, 0)
        self.assertEqual(self.service.read_bytes(), old_service)
        self.assertFalse(self.network_service.exists())
        self.assertFalse(any(call[0] in ("stop", "start") for call in self.calls()))

    def test_new_install_and_uninstall_keep_local_resolver(self):
        result = self.run_menu(r'''
            ss() { [[ "$*" == *":54"* ]] || return 1; }
            curl() {
                local destination=""
                while (( $# )); do
                    if [[ "$1" == -o ]]; then destination="$2"; break; fi
                    shift
                done
                cat > "$destination" <<'FAKE_SERVER'
#!/bin/bash
while (( $# )); do
    case "$1" in
        -privkey-file) printf 'private-key\n' > "$2"; shift ;;
        -pubkey-file) printf 'public-key\n' > "$2"; shift ;;
    esac
    shift
done
FAKE_SERVER
            }
            install_dnstt <<< $'1\nsgx.example.com\nns.sgx.example.com\n\n'
        ''')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertIn("has been installed and started", result.stdout)
        self.assertIn("-udp :54", self.service.read_text())
        self.assertTrue(self.read_json("rules.json"))
        self.assertFalse((self.keys / "resolver.state").exists())
        self.assertEqual(self.resolver.read_text(), "nameserver 127.0.0.53\n")
        if shutil.which("systemd-analyze"):
            verified = subprocess.run(
                ["systemd-analyze", "verify", str(self.service), str(self.network_service)],
                env=self.environment, text=True, capture_output=True, check=False,
            )
            self.assertEqual(verified.returncode, 0, verified.stderr)
        result = self.run_menu('UNINSTALL_MODE=silent; uninstall_dnstt')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(self.read_json("rules.json"), [])
        for path in (self.service, self.network_service, self.config, self.keys):
            self.assertFalse(path.exists(), path)
        self.assertEqual(self.resolver.read_text(), "nameserver 127.0.0.53\n")
        self.assertFalse(any("systemd-resolved" in call for call in self.calls()))

    def test_uninstall_failure_keeps_files_needed_to_retry_rule_removal(self):
        self.seed_legacy()
        result = self.run_menu('ss() { return 0; }; refresh_dnstt_runtime')
        self.assertEqual(result.returncode, 0, result.stderr)
        result = self.run_menu('UNINSTALL_MODE=silent; uninstall_dnstt', TDZ_DNSTT_FAIL_DELETE="1")
        self.assertNotEqual(result.returncode, 0)
        self.assertTrue(self.network_script.exists())
        self.assertTrue(self.service.exists())
        self.assertTrue(self.read_json("rules.json"))
        result = self.run_menu('UNINSTALL_MODE=silent; uninstall_dnstt')
        self.assertEqual(result.returncode, 0, result.stderr)
        self.assertEqual(self.read_json("rules.json"), [])
        self.assertFalse(self.network_script.exists())


if __name__ == "__main__":
    unittest.main()
