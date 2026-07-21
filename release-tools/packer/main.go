// tdz-packer assembles the feature-compatible v0.0.1 BETA runtime payload.
// It is release tooling and is never installed on customer systems.
package main

import (
	"bytes"
	"compress/gzip"
	"crypto/aes"
	"crypto/cipher"
	"crypto/rand"
	"encoding/base64"
	"encoding/hex"
	"encoding/json"
	"errors"
	"flag"
	"fmt"
	"io"
	"os"
	"path/filepath"
	"strings"
)

const releaseName = "v0.0.1 BETA"

func main() {
	source := flag.String("source", ".", "source repository root")
	out := flag.String("out", "release-tools/launcher/payload.enc", "encrypted payload output")
	keyOut := flag.String("key-out", ".release-work/payload.key", "hex build key output")
	plainDir := flag.String("plain-dir", "", "optional private QA output directory")
	flag.Parse()
	if err := pack(*source, *out, *keyOut, *plainDir); err != nil {
		fmt.Fprintln(os.Stderr, "tdz-packer:", err)
		os.Exit(1)
	}
}

func pack(root, output, keyOutput, plainOutput string) error {
	menu, err := read(root, "menu.sh")
	if err != nil {
		return err
	}
	module, err := read(root, "openvpn_module.sh")
	if err != nil {
		return err
	}

	limiter, err := heredoc(menu, `cat > "$LIMITER_SCRIPT" << 'EOF'`, "EOF")
	if err != nil {
		return err
	}
	trial, err := heredoc(menu, `cat > "$TRIAL_CLEANUP_SCRIPT" << 'TREOF'`, "TREOF")
	if err != nil {
		return err
	}
	backup, err := heredoc(menu, `cat > "$AUTO_BACKUP_SCRIPT" << 'WORKER_EOF'`, "WORKER_EOF")
	if err != nil {
		return err
	}
	bridge, err := heredoc(menu, `cat > "$WS_SSH_BRIDGE_SCRIPT" <<'PYEOF'`, "PYEOF")
	if err != nil {
		return err
	}

	module, err = transformModule(module)
	if err != nil {
		return err
	}
	menu, err = transformMenu(menu, module)
	if err != nil {
		return err
	}
	limiter = strings.ReplaceAll(limiter,
		`OVPN_RUNTIME="/usr/local/lib/tdz-ssh-tunnel/tdz_openvpn_runtime.py"`,
		`OVPN_RUNTIME="/usr/local/bin/tdz-openvpn-runtime"`)
	backup = strings.ReplaceAll(backup,
		`TRIAL_CLEANUP_SCRIPT="/usr/local/bin/tdztunnel-trial-cleanup.sh"`,
		`TRIAL_CLEANUP_SCRIPT="/usr/local/bin/tdz-trial-cleanup"`)

	sshAuth := mustRead(root, "tdz_ssh_auth_session.py")
	openVPNRuntime := mustRead(root, "tdz_openvpn_runtime.py")
	moduleBootstrap := fmt.Sprintf(`import base64 as _tdz_b64, sys as _tdz_sys, types as _tdz_types
_tdz_auth = _tdz_types.ModuleType("tdz_ssh_auth_session")
_tdz_auth.__file__ = "<packed:tdz_ssh_auth_session>"
_tdz_sys.modules["tdz_ssh_auth_session"] = _tdz_auth
exec(compile(_tdz_b64.b64decode("%s"), _tdz_auth.__file__, "exec"), _tdz_auth.__dict__)
import tdz_ssh_auth_session as ssh_auth_session`, base64.StdEncoding.EncodeToString(sshAuth))
	openVPNRuntime = []byte(strings.Replace(
		string(openVPNRuntime),
		"import tdz_ssh_auth_session as ssh_auth_session",
		moduleBootstrap,
		1,
	))

	resources := map[string][]byte{
		"menu.sh":             []byte(menu),
		"limiter.sh":          []byte(limiter),
		"trial-cleanup.sh":    []byte(trial),
		"auto-backup.sh":      []byte(backup),
		"ws-ssh-bridge.py":    []byte(bridge),
		"openvpn-runtime.py":  openVPNRuntime,
		"openvpn-gateway.py":  mustRead(root, "tdz_openvpn_gateway.py"),
		"openvpn-portal.py":   mustRead(root, "tdz_openvpn_portal.py"),
		"openvpn-firewall.sh": []byte(openVPNFirewall),
		"ssh-auth-session.py": sshAuth,
	}
	for name, data := range resources {
		if len(bytes.TrimSpace(data)) == 0 {
			return fmt.Errorf("resource %s is empty", name)
		}
	}
	if plainOutput != "" {
		if err := os.MkdirAll(plainOutput, 0700); err != nil {
			return err
		}
		for name, data := range resources {
			if err := os.WriteFile(filepath.Join(plainOutput, name), data, 0600); err != nil {
				return err
			}
		}
	}

	plain, err := json.Marshal(resources)
	if err != nil {
		return err
	}
	var compressed bytes.Buffer
	zw, _ := gzip.NewWriterLevel(&compressed, gzip.BestCompression)
	if _, err := zw.Write(plain); err != nil {
		return err
	}
	if err := zw.Close(); err != nil {
		return err
	}

	key := make([]byte, 32)
	if _, err := io.ReadFull(rand.Reader, key); err != nil {
		return err
	}
	block, err := aes.NewCipher(key)
	if err != nil {
		return err
	}
	gcm, err := cipher.NewGCM(block)
	if err != nil {
		return err
	}
	nonce := make([]byte, gcm.NonceSize())
	if _, err := io.ReadFull(rand.Reader, nonce); err != nil {
		return err
	}
	sealed := gcm.Seal(nil, nonce, compressed.Bytes(), []byte(releaseName))
	payload := append(nonce, sealed...)

	if err := os.MkdirAll(filepath.Dir(output), 0755); err != nil {
		return err
	}
	if err := os.MkdirAll(filepath.Dir(keyOutput), 0700); err != nil {
		return err
	}
	if err := os.WriteFile(output, payload, 0600); err != nil {
		return err
	}
	if err := os.WriteFile(keyOutput, []byte(hex.EncodeToString(key)+"\n"), 0600); err != nil {
		return err
	}
	fmt.Printf("packed %d authenticated runtimes (%d bytes)\n", len(resources), len(payload))
	return nil
}

func transformMenu(menu, module string) (string, error) {
	replacements := [][2]string{
		{`WS_SSH_BRIDGE_SCRIPT="/usr/local/bin/tdz-ws-ssh-bridge.py"`, `WS_SSH_BRIDGE_SCRIPT="/usr/local/bin/tdz-ws-ssh-bridge"`},
		{`LIMITER_SCRIPT="/usr/local/bin/tdztunnel-limiter.sh"`, `LIMITER_SCRIPT="/usr/local/bin/tdz-limiter"`},
		{`TRIAL_CLEANUP_SCRIPT="/usr/local/bin/tdztunnel-trial-cleanup.sh"`, `TRIAL_CLEANUP_SCRIPT="/usr/local/bin/tdz-trial-cleanup"`},
		{`AUTO_BACKUP_SCRIPT="/usr/local/bin/tdztunnel-auto-backup-bot.sh"`, `AUTO_BACKUP_SCRIPT="/usr/local/bin/tdz-auto-backup-bot"`},
		{`SSH_AUTH_SESSION_HELPER="$TDZ_LIB_DIR/tdz_ssh_auth_session.py"`, `SSH_AUTH_SESSION_HELPER="/usr/local/bin/tdz-ssh-auth"`},
		{`VersionAddendum By: @TuhinBroh`, `VersionAddendum @TuhinBroh`},
		{`pm2 start "$AUTO_BACKUP_SCRIPT" --name "$AUTO_BACKUP_PM2_NAME"`, `pm2 start "$AUTO_BACKUP_SCRIPT" --name "$AUTO_BACKUP_PM2_NAME" --interpreter none`},
		{`for service in tdztunnel-limiter tdztunnel-bandwidth tdz-ws-ssh-bridge \`, `for service in tdztunnel-limiter tdztunnel-bandwidth tdz-ws-ssh-bridge tdz-ssh-branding-guard \`},
		{`for unit in tdztunnel-limiter tdztunnel-bandwidth tdz-ws-ssh-bridge \`, `for unit in tdztunnel-limiter tdztunnel-bandwidth tdz-ws-ssh-bridge tdz-ssh-branding-guard \`},
	}
	for _, pair := range replacements {
		menu = strings.ReplaceAll(menu, pair[0], pair[1])
	}

	start := strings.Index(menu, "# OpenVPN is optional.")
	endMarker := "\nfi\n\ntdz_is_valid_port_number()"
	if start < 0 {
		return "", errors.New("OpenVPN source-loader marker not found")
	}
	end := strings.Index(menu[start:], endMarker)
	if end < 0 {
		return "", errors.New("OpenVPN source-loader end not found")
	}
	end += start
	module = strings.TrimPrefix(module, "#!/bin/bash\n")
	menu = menu[:start] + "# OpenVPN implementation is packed into the official binary.\n" + module + "\n\ntdz_is_valid_port_number()" + menu[end+len(endMarker):]

	menu, err := replaceSection(menu, "setup_limiter_service() {", "\nsetup_ssh_auth_session_hook() {", packedLimiterSetup+"\n\nsetup_ssh_auth_session_hook() {")
	if err != nil {
		return "", err
	}
	menu, err = replaceSection(menu, "setup_trial_cleanup_script() {", "\ndisable_dynamic_ssh_banner_system() {", packedTrialSetup+"\n\ndisable_dynamic_ssh_banner_system() {")
	if err != nil {
		return "", err
	}
	menu, err = replaceSection(menu, "auto_backup_write_worker() {", "\nauto_backup_choose_interval() {", packedBackupSetup+"\n\nauto_backup_choose_interval() {")
	if err != nil {
		return "", err
	}
	menu, err = replaceSection(menu, "write_ws_ssh_bridge_script() {", "\nwrite_ws_ssh_bridge_service() {", packedBridgeSetup+"\n\nwrite_ws_ssh_bridge_service() {")
	if err != nil {
		return "", err
	}
	menu = strings.ReplaceAll(menu,
		`if [[ ! -f "$LIMITER_SCRIPT" ]] || ! grep -Fqx "$limiter_marker" "$LIMITER_SCRIPT" 2>/dev/null; then`,
		`if [[ ! -x "$LIMITER_SCRIPT" || ! -f "$LIMITER_SERVICE" ]]; then`)
	menu = strings.ReplaceAll(menu,
		`index($0, helper) { next }`,
		`(index($0, helper) || index($0, "tdz_ssh_auth_session.py")) { next }`)
	menu = strings.ReplaceAll(menu,
		`rm -f "$LOGIN_INFO_SCRIPT" "$SSHD_TDZ_CONFIG" "$SSH_BANNER_FILE" || cleanup_failed=true`,
		`rm -f "$LOGIN_INFO_SCRIPT" "$SSHD_TDZ_CONFIG" "$SSH_BANNER_FILE" /etc/systemd/system/tdz-ssh-branding-guard.service || cleanup_failed=true`)
	menu = strings.ReplaceAll(menu,
		`rm -f "$TDZ_MENU_BINARY" || return 1`,
		`rm -f "$TDZ_MENU_BINARY" /usr/local/bin/tdz-limiter /usr/local/bin/tdz-trial-cleanup /usr/local/bin/tdz-auto-backup-bot /usr/local/bin/tdz-ws-ssh-bridge /usr/local/bin/tdz-openvpn-runtime /usr/local/bin/tdz-openvpn-gateway /usr/local/bin/tdz-openvpn-portal /usr/local/bin/tdz-openvpn-firewall /usr/local/bin/tdz-ssh-auth /usr/local/bin/tdztunnel-limiter.sh /usr/local/bin/tdztunnel-trial-cleanup.sh /usr/local/bin/tdztunnel-auto-backup-bot.sh /usr/local/bin/tdz-ws-ssh-bridge.py /usr/local/bin/tdz || return 1`)
	return menu, nil
}

func transformModule(module string) (string, error) {
	replacements := [][2]string{
		{`TDZ_OVPN_RUNTIME="${TDZ_OVPN_RUNTIME:-$TDZ_OVPN_LIB/tdz_openvpn_runtime.py}"`, `TDZ_OVPN_RUNTIME="${TDZ_OVPN_RUNTIME:-/usr/local/bin/tdz-openvpn-runtime}"`},
		{`TDZ_OVPN_GATEWAY="${TDZ_OVPN_GATEWAY:-$TDZ_OVPN_LIB/tdz_openvpn_gateway.py}"`, `TDZ_OVPN_GATEWAY="${TDZ_OVPN_GATEWAY:-/usr/local/bin/tdz-openvpn-gateway}"`},
		{`TDZ_OVPN_PORTAL="${TDZ_OVPN_PORTAL:-$TDZ_OVPN_LIB/tdz_openvpn_portal.py}"`, `TDZ_OVPN_PORTAL="${TDZ_OVPN_PORTAL:-/usr/local/bin/tdz-openvpn-portal}"`},
		{`TDZ_OVPN_FIREWALL="${TDZ_OVPN_FIREWALL:-/usr/local/libexec/tdz-openvpn-firewall}"`, `TDZ_OVPN_FIREWALL="${TDZ_OVPN_FIREWALL:-/usr/local/bin/tdz-openvpn-firewall}"`},
		{`ExecStart=/usr/bin/python3 $TDZ_OVPN_PORTAL`, `ExecStart=$TDZ_OVPN_PORTAL`},
		{`ExecStart=/usr/bin/python3 $TDZ_OVPN_RUNTIME`, `ExecStart=$TDZ_OVPN_RUNTIME`},
		{`ExecStart=/usr/bin/python3 $TDZ_OVPN_GATEWAY`, `ExecStart=$TDZ_OVPN_GATEWAY`},
	}
	for _, pair := range replacements {
		module = strings.ReplaceAll(module, pair[0], pair[1])
	}
	var err error
	module, err = replaceSection(module, "tdz_openvpn_write_network_service() {", "\ntdz_openvpn_profile_common() {", packedNetworkSetup+"\n\ntdz_openvpn_profile_common() {")
	if err != nil {
		return "", err
	}
	oldValidation := `if ! python3 -c 'import pathlib,sys; [compile(pathlib.Path(p).read_bytes(), p, "exec") for p in sys.argv[1:]]' \
        "$TDZ_OVPN_RUNTIME" "$TDZ_OVPN_GATEWAY" "$TDZ_OVPN_PORTAL" >>"$TDZ_OVPN_DIAG_LOG" 2>&1; then
        echo "Validation failed: runtime syntax" >>"$TDZ_OVPN_DIAG_LOG"
        return 1
    fi`
	newValidation := `if [[ ! -x "$TDZ_OVPN_RUNTIME" || ! -x "$TDZ_OVPN_GATEWAY" || ! -x "$TDZ_OVPN_PORTAL" ]]; then
        echo "Validation failed: packed runtime dispatchers" >>"$TDZ_OVPN_DIAG_LOG"
        return 1
    fi`
	if !strings.Contains(module, oldValidation) {
		return "", errors.New("OpenVPN validation block not found")
	}
	module = strings.Replace(module, oldValidation, newValidation, 1)
	return module, nil
}

func replaceSection(source, startMarker, endMarker, replacement string) (string, error) {
	start := strings.Index(source, startMarker)
	if start < 0 {
		return "", fmt.Errorf("section %q not found", startMarker)
	}
	end := strings.Index(source[start:], endMarker)
	if end < 0 {
		return "", fmt.Errorf("end for %q not found", startMarker)
	}
	end += start
	return source[:start] + replacement + source[end+len(endMarker):], nil
}

func heredoc(source, marker, delimiter string) (string, error) {
	start := strings.Index(source, marker)
	if start < 0 {
		return "", fmt.Errorf("heredoc marker %q not found", marker)
	}
	start += len(marker)
	if start >= len(source) || source[start] != '\n' {
		return "", errors.New("heredoc content does not start on the next line")
	}
	start++
	end := strings.Index(source[start:], "\n"+delimiter+"\n")
	if end < 0 {
		return "", fmt.Errorf("heredoc delimiter %q not found", delimiter)
	}
	return source[start:start+end] + "\n", nil
}

func read(root, name string) (string, error) {
	data, err := os.ReadFile(filepath.Join(root, name))
	if err != nil {
		return "", fmt.Errorf("read %s: %w", name, err)
	}
	return string(data), nil
}

func mustRead(root, name string) []byte {
	data, err := os.ReadFile(filepath.Join(root, name))
	if err != nil {
		panic(err)
	}
	return data
}

const packedLimiterSetup = `setup_limiter_service() {
    ln -sfn /usr/local/bin/tdz "$LIMITER_SCRIPT" || return 1
    cat > "$LIMITER_SERVICE" <<EOF
[Unit]
Description=TDZ SSH TUNNEL Active User Limiter
After=network.target

[Service]
Type=simple
ExecStart=$LIMITER_SCRIPT
Restart=always
RestartSec=10
Nice=10
IOSchedulingClass=best-effort
IOSchedulingPriority=7

[Install]
WantedBy=multi-user.target
EOF
    systemctl daemon-reload >/dev/null 2>&1
    systemctl enable tdztunnel-limiter >/dev/null 2>&1
    systemctl restart tdztunnel-limiter --no-block >/dev/null 2>&1
}`

const packedTrialSetup = `setup_trial_cleanup_script() {
    ln -sfn /usr/local/bin/tdz "$TRIAL_CLEANUP_SCRIPT"
}`

const packedBackupSetup = `auto_backup_write_worker() {
    ln -sfn /usr/local/bin/tdz "$AUTO_BACKUP_SCRIPT"
}`

const packedBridgeSetup = `write_ws_ssh_bridge_script() {
    ln -sfn /usr/local/bin/tdz "$WS_SSH_BRIDGE_SCRIPT"
}`

const packedNetworkSetup = `tdz_openvpn_write_network_service() {
    mkdir -p "$TDZ_OVPN_SYSTEMD_DIR" "$(dirname "$TDZ_OVPN_SYSCTL")"
    ln -sfn /usr/local/bin/tdz "$TDZ_OVPN_FIREWALL" || return 1
    printf 'net.ipv4.ip_forward=1\n' > "$TDZ_OVPN_SYSCTL"
    cat > "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-network.service" <<EOF
[Unit]
Description=TDZ OpenVPN Network Rules
After=network-pre.target
Before=tdz-openvpn-tcp.service tdz-openvpn-udp.service

[Service]
Type=oneshot
ExecStart=$TDZ_OVPN_FIREWALL start
ExecStop=$TDZ_OVPN_FIREWALL stop
RemainAfterExit=yes

[Install]
WantedBy=multi-user.target
EOF
}`

const openVPNFirewall = `#!/bin/sh
set -eu
STATE=/etc/tdztunnel/openvpn/state.conf
action=${1:-start}
TCP_SUBNET= UDP_SUBNET= TCP_PORT= UDP_PORT= HTTP_PORT= WSS_PORT= SSL_PORT= PORTAL_PORT= IP_FORWARD_PREVIOUS=
while IFS='=' read -r key value; do
    case "$key" in
        TCP_SUBNET) TCP_SUBNET=$value ;;
        UDP_SUBNET) UDP_SUBNET=$value ;;
        TCP_PORT) TCP_PORT=$value ;;
        UDP_PORT) UDP_PORT=$value ;;
        HTTP_PORT) HTTP_PORT=$value ;;
        WSS_PORT) WSS_PORT=$value ;;
        SSL_PORT) SSL_PORT=$value ;;
        PORTAL_PORT) PORTAL_PORT=$value ;;
        IP_FORWARD_PREVIOUS) IP_FORWARD_PREVIOUS=$value ;;
    esac
done < "$STATE"
[ -n "$TCP_SUBNET" ] && [ -n "$UDP_SUBNET" ] || exit 1
case "$TCP_SUBNET:$UDP_SUBNET" in *[!0-9.:]*) exit 1;; esac
for value in "$TCP_PORT" "$UDP_PORT" "$HTTP_PORT" "$WSS_PORT" "$SSL_PORT" "$PORTAL_PORT"; do
    case "$value" in ''|*[!0-9]*) exit 1;; esac
done
TCP_SUBNET="$TCP_SUBNET/24"; UDP_SUBNET="$UDP_SUBNET/24"
filter_add() { iptables -C "$@" >/dev/null 2>&1 || iptables -I "$@"; }
nat_add() { iptables -t nat -C "$@" >/dev/null 2>&1 || iptables -t nat -I "$@"; }
mangle_add() { iptables -t mangle -C "$@" >/dev/null 2>&1 || iptables -t mangle -I "$@"; }
filter_del() { while iptables -C "$@" >/dev/null 2>&1; do iptables -D "$@"; done; }
nat_del() { while iptables -t nat -C "$@" >/dev/null 2>&1; do iptables -t nat -D "$@"; done; }
mangle_del() { while iptables -t mangle -C "$@" >/dev/null 2>&1; do iptables -t mangle -D "$@"; done; }
if [ "$action" = start ]; then
    trap '"$0" stop >/dev/null 2>&1 || true' 0
    sysctl -w net.ipv4.ip_forward=1 >/dev/null
    filter_add INPUT -p tcp -m multiport --dports "$TCP_PORT,$HTTP_PORT,$WSS_PORT,$SSL_PORT,$PORTAL_PORT" -j ACCEPT
    filter_add INPUT -p udp --dport "$UDP_PORT" -j ACCEPT
    for subnet in "$TCP_SUBNET" "$UDP_SUBNET"; do
        filter_add FORWARD -s "$subnet" -j ACCEPT
        filter_add FORWARD -d "$subnet" -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
        nat_add POSTROUTING -s "$subnet" -j MASQUERADE
    done
    mangle_add FORWARD -s "$TCP_SUBNET" -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
    mangle_add FORWARD -d "$TCP_SUBNET" -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
    for source in "$TCP_SUBNET" "$UDP_SUBNET"; do
        for destination in "$TCP_SUBNET" "$UDP_SUBNET"; do
            filter_add FORWARD -s "$source" -d "$destination" -j DROP
        done
    done
    trap - 0
else
    filter_del INPUT -p tcp -m multiport --dports "$TCP_PORT,$HTTP_PORT,$WSS_PORT,$SSL_PORT,$PORTAL_PORT" -j ACCEPT
    filter_del INPUT -p udp --dport "$UDP_PORT" -j ACCEPT
    for subnet in "$TCP_SUBNET" "$UDP_SUBNET"; do
        filter_del FORWARD -s "$subnet" -j ACCEPT
        filter_del FORWARD -d "$subnet" -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
        nat_del POSTROUTING -s "$subnet" -j MASQUERADE
    done
    mangle_del FORWARD -s "$TCP_SUBNET" -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
    mangle_del FORWARD -d "$TCP_SUBNET" -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
    for source in "$TCP_SUBNET" "$UDP_SUBNET"; do
        for destination in "$TCP_SUBNET" "$UDP_SUBNET"; do
            filter_del FORWARD -s "$source" -d "$destination" -j DROP
        done
    done
    case "$IP_FORWARD_PREVIOUS" in 0|1) sysctl -w "net.ipv4.ip_forward=$IP_FORWARD_PREVIOUS" >/dev/null;; esac
fi
`
