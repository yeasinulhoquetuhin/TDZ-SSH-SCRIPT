#!/bin/bash
set -Eeuo pipefail

# TDZ SSH TUNNEL smart installer/updater. Re-running the same command detects
# an existing installation and refreshes the application without deleting
# accounts, usage, certificates, Telegram settings, or enabled feature state.

if [[ ${EUID:-$(id -u)} -ne 0 ]]; then
    echo "Error: This installer must be run as root."
    exit 1
fi

if [[ -t 1 ]]; then
    C_RESET=$'\033[0m'; C_BOLD=$'\033[1m'; C_DIM=$'\033[2m'
    C_CYAN=$'\033[38;2;0;212;255m'; C_GREEN=$'\033[38;5;46m'
    C_YELLOW=$'\033[38;5;226m'; C_RED=$'\033[38;5;196m'; C_GRAY=$'\033[38;5;245m'
else
    C_RESET=''; C_BOLD=''; C_DIM=''; C_CYAN=''; C_GREEN=''; C_YELLOW=''; C_RED=''; C_GRAY=''
fi

TARGET_MENU="/usr/local/bin/menu"
TARGET_BRIDGE="/usr/local/bin/tdz-ws-ssh-bridge.py"
TARGET_LIB_DIR="/usr/local/lib/tdz-ssh-tunnel"
TARGET_OVPN_MODULE="$TARGET_LIB_DIR/openvpn_module.sh"
TARGET_OVPN_GATEWAY="$TARGET_LIB_DIR/tdz_openvpn_gateway.py"
TARGET_OVPN_PORTAL="$TARGET_LIB_DIR/tdz_openvpn_portal.py"
TARGET_OVPN_RUNTIME="$TARGET_LIB_DIR/tdz_openvpn_runtime.py"
TARGET_SSH_AUTH_SESSION="$TARGET_LIB_DIR/tdz_ssh_auth_session.py"
DATA_DIR="/etc/tdztunnel"
INSTALL_FLAG="$DATA_DIR/.install"
SSHD_CONFIG="/etc/ssh/sshd_config"
SSHD_DROPIN_DIR="/etc/ssh/sshd_config.d"
SSHD_DROPIN="$SSHD_DROPIN_DIR/tdztunnel.conf"
SCRIPT_DIR="$(CDPATH= cd -- "$(dirname -- "$0")" 2>/dev/null && pwd || true)"
MENU_URL="${MENU_URL:-https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/menu.sh}"
BRIDGE_URL="${BRIDGE_URL:-https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/ws_ssh_bridge.py}"
OVPN_MODULE_URL="${OVPN_MODULE_URL:-https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/openvpn_module.sh}"
OVPN_GATEWAY_URL="${OVPN_GATEWAY_URL:-https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/tdz_openvpn_gateway.py}"
OVPN_PORTAL_URL="${OVPN_PORTAL_URL:-https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/tdz_openvpn_portal.py}"
OVPN_RUNTIME_URL="${OVPN_RUNTIME_URL:-https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/tdz_openvpn_runtime.py}"
SSH_AUTH_SESSION_URL="${SSH_AUTH_SESSION_URL:-https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/tdz_ssh_auth_session.py}"

WORK_DIR="$(mktemp -d /tmp/tdz-installer.XXXXXX)"
LOG_FILE="$WORK_DIR/install.log"
PAYLOAD_MENU="$WORK_DIR/menu.sh"
PAYLOAD_BRIDGE="$WORK_DIR/ws_ssh_bridge.py"
PAYLOAD_OVPN_MODULE="$WORK_DIR/openvpn_module.sh"
PAYLOAD_OVPN_GATEWAY="$WORK_DIR/tdz_openvpn_gateway.py"
PAYLOAD_OVPN_PORTAL="$WORK_DIR/tdz_openvpn_portal.py"
PAYLOAD_OVPN_RUNTIME="$WORK_DIR/tdz_openvpn_runtime.py"
PAYLOAD_SSH_AUTH_SESSION="$WORK_DIR/tdz_ssh_auth_session.py"
OLD_MENU="$WORK_DIR/menu.previous"
OLD_LIB_DIR="$WORK_DIR/lib.previous"
OLD_SSHD_CONFIG="$WORK_DIR/sshd_config.previous"
OLD_SSHD_DROPIN="$WORK_DIR/sshd_dropin.previous"
HAD_OLD_MENU=false
HAD_OLD_LIB=false
HAD_OLD_DROPIN=false
SSH_CHANGED=false
FINISHED=false

MODE="install"
if [[ -x "$TARGET_MENU" || -f "$INSTALL_FLAG" || -f "$DATA_DIR/users.db" ||
      -f "$DATA_DIR/banners_enabled" ]]; then
    MODE="update"
fi
[[ -f "$TARGET_MENU" ]] && HAD_OLD_MENU=true
[[ -d "$TARGET_LIB_DIR" ]] && HAD_OLD_LIB=true
[[ -f "$SSHD_DROPIN" ]] && HAD_OLD_DROPIN=true

cleanup() {
    rm -rf "$WORK_DIR"
}

restart_ssh() {
    if command -v systemctl >/dev/null 2>&1; then
        systemctl restart sshd >/dev/null 2>&1 || systemctl restart ssh >/dev/null 2>&1
    elif command -v service >/dev/null 2>&1; then
        service sshd restart >/dev/null 2>&1 || service ssh restart >/dev/null 2>&1
    elif command -v rc-service >/dev/null 2>&1; then
        rc-service sshd restart >/dev/null 2>&1 || rc-service ssh restart >/dev/null 2>&1
    elif [[ -x /etc/init.d/sshd ]]; then
        /etc/init.d/sshd restart >/dev/null 2>&1
    elif [[ -x /etc/init.d/ssh ]]; then
        /etc/init.d/ssh restart >/dev/null 2>&1
    else
        return 1
    fi
}

rollback() {
    $FINISHED && return 0

    if $HAD_OLD_MENU && [[ -f "$OLD_MENU" ]]; then
        install -m 755 "$OLD_MENU" "$TARGET_MENU" 2>/dev/null || true
    elif ! $HAD_OLD_MENU; then
        rm -f "$TARGET_MENU" 2>/dev/null || true
    fi

    if $HAD_OLD_LIB && [[ -d "$OLD_LIB_DIR" ]]; then
        rm -rf "$TARGET_LIB_DIR" 2>/dev/null || true
        cp -a "$OLD_LIB_DIR" "$TARGET_LIB_DIR" 2>/dev/null || true
    elif ! $HAD_OLD_LIB; then
        rm -rf "$TARGET_LIB_DIR" 2>/dev/null || true
    fi

    if $SSH_CHANGED && [[ -f "$OLD_SSHD_CONFIG" ]]; then
        cp "$OLD_SSHD_CONFIG" "$SSHD_CONFIG" 2>/dev/null || true
        if $HAD_OLD_DROPIN; then
            cp "$OLD_SSHD_DROPIN" "$SSHD_DROPIN" 2>/dev/null || true
        else
            rm -f "$SSHD_DROPIN" 2>/dev/null || true
        fi
        restart_ssh >/dev/null 2>&1 || true
    fi
}

on_exit() {
    local rc=$?
    if (( rc != 0 )); then
        rollback
        echo
        echo -e "  ${C_RED}${C_BOLD}Installation could not be completed.${C_RESET}"
        echo -e "  ${C_GRAY}Previous installation data and configuration were kept.${C_RESET}"
    fi
    cleanup
    exit "$rc"
}
trap on_exit EXIT

print_centered_line() {
    local clean_text=$1 styled_text=$2 left right
    left=$(( (64 - ${#clean_text}) / 2 ))
    (( left < 0 )) && left=0
    right=$((64 - ${#clean_text} - left))
    (( right < 0 )) && right=0
    printf "  ${C_CYAN}║${C_RESET}%*s%s%*s${C_CYAN}║${C_RESET}\n" \
        "$left" "" "$styled_text" "$right" ""
}

show_header() {
    [[ -t 1 ]] && clear || true
    echo
    echo -e "  ${C_CYAN}╔════════════════════════════════════════════════════════════════╗${C_RESET}"
    print_centered_line "TDZ SSH TUNNEL   •   SETUP" "${C_CYAN}TDZ SSH TUNNEL   •   SETUP${C_RESET}"
    print_centered_line "Powered By: t.me/TuhinBroh" "${C_GRAY}Powered By: t.me/TuhinBroh${C_RESET}"
    echo -e "  ${C_CYAN}╚════════════════════════════════════════════════════════════════╝${C_RESET}"
    echo
    if [[ "$MODE" == "update" ]]; then
        echo -e "  ${C_YELLOW}${C_BOLD}● UPDATE MODE${C_RESET}"
        echo -e "  ${C_DIM}  Existing setup found • saved data will be preserved${C_RESET}"
    else
        echo -e "  ${C_GREEN}${C_BOLD}● INSTALL MODE${C_RESET}"
        echo -e "  ${C_DIM}  Preparing a clean TDZ SSH TUNNEL setup${C_RESET}"
    fi
    echo
}

TOTAL_STEPS=5
CURRENT_STEP=0
CURRENT_PERCENT=0
ANIMATION_TICKS="${TDZ_INSTALL_ANIMATION_TICKS:-30}"
[[ "$ANIMATION_TICKS" =~ ^[1-9][0-9]*$ ]] || ANIMATION_TICKS=30

draw_live_progress() {
    local percent=$1 label=$2 spinner=${3:-} width=28 filled empty fill_bar="" empty_bar=""
    filled=$((percent * width / 100))
    empty=$((width - filled))
    (( filled > 0 )) && printf -v fill_bar '%*s' "$filled" '' && fill_bar=${fill_bar// /█}
    if (( empty > 0 )); then
        printf -v empty_bar '%*s' "$empty" ''
        empty_bar=${empty_bar// /░}
    fi
    printf '\r\033[2K  %s[%s%s%s%s]%s %s%3d%%%s  %s%s%s' \
        "$C_CYAN" "$fill_bar" "$C_GRAY" "$empty_bar" "$C_CYAN" "$C_RESET" \
        "$C_BOLD" "$percent" "$C_RESET" "$label" "$spinner" "$C_RESET"
}

run_step() {
    local label=$1 target_percent=$2
    shift 2
    local job_pid tick percent spinner_index=0
    local -a spinners=(' ◐' ' ◓' ' ◑' ' ◒')
    CURRENT_STEP=$((CURRENT_STEP + 1))

    if [[ ! -t 1 ]]; then
        printf '  [%d/%d] %-28s' "$CURRENT_STEP" "$TOTAL_STEPS" "$label"
        if "$@" >>"$LOG_FILE" 2>&1; then
            echo " DONE"
            CURRENT_PERCENT=$target_percent
            return 0
        fi
        echo " FAILED"
        return 1
    fi

    "$@" >>"$LOG_FILE" 2>&1 &
    job_pid=$!
    for ((tick=1; tick<=ANIMATION_TICKS; tick++)); do
        percent=$((CURRENT_PERCENT + (target_percent - CURRENT_PERCENT) * tick / ANIMATION_TICKS))
        (( percent >= target_percent )) && percent=$((target_percent - 1))
        draw_live_progress "$percent" "$label" "${spinners[$spinner_index]}"
        spinner_index=$(((spinner_index + 1) % ${#spinners[@]}))
        sleep 0.1
    done
    while kill -0 "$job_pid" 2>/dev/null; do
        draw_live_progress "$((target_percent - 1))" "$label" "${spinners[$spinner_index]}"
        spinner_index=$(((spinner_index + 1) % ${#spinners[@]}))
        sleep 0.1
    done

    if wait "$job_pid"; then
        printf '\r\033[2K  %s✓%s %s\n' "$C_GREEN" "$C_RESET" "$label"
        CURRENT_PERCENT=$target_percent
        return 0
    fi
    printf '\r\033[2K  %s✗%s %s\n' "$C_RED" "$C_RESET" "$label"
    return 1
}

download_file() {
    local url=$1 destination=$2
    if command -v curl >/dev/null 2>&1; then
        curl -4 -fLsS --retry 3 --connect-timeout 15 -o "$destination" "$url"
    elif command -v wget >/dev/null 2>&1; then
        wget -4 -q --tries=3 --timeout=15 -O "$destination" "$url"
    else
        return 1
    fi
}

prepare_payload() {
    if [[ -n "$SCRIPT_DIR" && -f "$SCRIPT_DIR/menu.sh" ]]; then
        cp "$SCRIPT_DIR/menu.sh" "$PAYLOAD_MENU"
    else
        download_file "$MENU_URL" "$PAYLOAD_MENU"
    fi
    [[ -s "$PAYLOAD_MENU" ]] && bash -n "$PAYLOAD_MENU"

    if [[ -n "$SCRIPT_DIR" && -f "$SCRIPT_DIR/ws_ssh_bridge.py" ]]; then
        cp "$SCRIPT_DIR/ws_ssh_bridge.py" "$PAYLOAD_BRIDGE"
    else
        download_file "$BRIDGE_URL" "$PAYLOAD_BRIDGE" || rm -f "$PAYLOAD_BRIDGE"
    fi

    local source_file payload_file source_url
    while IFS='|' read -r source_file payload_file source_url; do
        if [[ -n "$SCRIPT_DIR" && -f "$SCRIPT_DIR/$source_file" ]]; then
            cp "$SCRIPT_DIR/$source_file" "$payload_file"
        else
            download_file "$source_url" "$payload_file"
        fi
        [[ -s "$payload_file" ]] || return 1
    done <<EOF
openvpn_module.sh|$PAYLOAD_OVPN_MODULE|$OVPN_MODULE_URL
tdz_openvpn_gateway.py|$PAYLOAD_OVPN_GATEWAY|$OVPN_GATEWAY_URL
tdz_openvpn_portal.py|$PAYLOAD_OVPN_PORTAL|$OVPN_PORTAL_URL
tdz_openvpn_runtime.py|$PAYLOAD_OVPN_RUNTIME|$OVPN_RUNTIME_URL
tdz_ssh_auth_session.py|$PAYLOAD_SSH_AUTH_SESSION|$SSH_AUTH_SESSION_URL
EOF
    bash -n "$PAYLOAD_OVPN_MODULE"
    if command -v python3 >/dev/null 2>&1 &&
       python3 -c 'import sys; raise SystemExit(sys.version_info < (3, 7))'; then
        PYTHONDONTWRITEBYTECODE=1 python3 -m py_compile \
            "$PAYLOAD_OVPN_GATEWAY" "$PAYLOAD_OVPN_PORTAL" "$PAYLOAD_OVPN_RUNTIME" \
            "$PAYLOAD_SSH_AUTH_SESSION"
    fi
}

backup_current_state() {
    if [[ -f "$TARGET_MENU" ]]; then
        cp "$TARGET_MENU" "$OLD_MENU"
    fi
    if [[ -d "$TARGET_LIB_DIR" ]]; then
        cp -a "$TARGET_LIB_DIR" "$OLD_LIB_DIR"
    fi
    [[ -f "$SSHD_CONFIG" ]] || return 1
    cp "$SSHD_CONFIG" "$OLD_SSHD_CONFIG"
    if [[ -f "$SSHD_DROPIN" ]]; then
        cp "$SSHD_DROPIN" "$OLD_SSHD_DROPIN"
    fi
}

install_core() {
    install -m 755 "$PAYLOAD_MENU" "$TARGET_MENU"
    if [[ -s "$PAYLOAD_BRIDGE" ]]; then
        install -m 755 "$PAYLOAD_BRIDGE" "$TARGET_BRIDGE"
    fi
    install -d -m 755 "$TARGET_LIB_DIR"
    install -m 644 "$PAYLOAD_OVPN_MODULE" "$TARGET_OVPN_MODULE"
    install -m 755 "$PAYLOAD_OVPN_GATEWAY" "$TARGET_OVPN_GATEWAY"
    install -m 755 "$PAYLOAD_OVPN_PORTAL" "$TARGET_OVPN_PORTAL"
    install -m 755 "$PAYLOAD_SSH_AUTH_SESSION" "$TARGET_SSH_AUTH_SESSION"
    install -m 755 "$PAYLOAD_OVPN_RUNTIME" "$TARGET_OVPN_RUNTIME"
}

configure_ssh() {
    local sshd_bin
    sshd_bin="$(command -v sshd 2>/dev/null || true)"
    [[ -n "$sshd_bin" ]] || sshd_bin="/usr/sbin/sshd"
    [[ -x "$sshd_bin" ]] || return 1

    mkdir -p "$SSHD_DROPIN_DIR"
    sed -i \
        -e 's/^[[:space:]]*AddressFamily[[:space:]]\+any[[:space:]]*$/# TDZ disabled: AddressFamily any/' \
        -e 's/^[[:space:]]*ListenAddress[[:space:]]\+::[[:space:]]*$/# TDZ disabled: ListenAddress ::/' \
        "$SSHD_CONFIG"

    if ! grep -qE '^[[:space:]]*Include[[:space:]]+/etc/ssh/sshd_config\.d/\*\.conf' "$SSHD_CONFIG" 2>/dev/null; then
        printf '\n# TDZ SSH TUNNEL drop-ins\nInclude /etc/ssh/sshd_config.d/*.conf\n' >> "$SSHD_CONFIG"
    fi

    cat > "$SSHD_DROPIN" <<'EOF'
# TDZ SSH TUNNEL safe SSH settings
Port 22
DebianBanner no
VersionAddendum By: @TuhinBroh
AddressFamily inet
ListenAddress 0.0.0.0
PermitRootLogin yes
PasswordAuthentication yes
KbdInteractiveAuthentication yes
ChallengeResponseAuthentication yes
UsePAM yes
X11Forwarding yes
PrintMotd no
AcceptEnv LANG LC_*
ClientAliveInterval 30
ClientAliveCountMax 3
UseDNS no
LoginGraceTime 60
MaxStartups 30:30:100
TCPKeepAlive yes
PermitTunnel yes
AllowTcpForwarding yes
GatewayPorts yes
EOF
    chmod 600 "$SSHD_DROPIN"
    "$sshd_bin" -t
}

sync_runtime() {
    if [[ "$MODE" == "update" ]]; then
        bash "$TARGET_MENU" --update-setup
    else
        bash "$TARGET_MENU" --install-setup
    fi
}

finish_setup() {
    restart_ssh || true
    mkdir -p "$(dirname "$INSTALL_FLAG")"
    touch "$INSTALL_FLAG"
}

refresh_and_finish() {
    sync_runtime
    finish_setup
}

show_header
run_step "Preparing installation files" 20 prepare_payload
run_step "Preserving current settings" 40 backup_current_state
run_step "Installing core services" 60 install_core
SSH_CHANGED=true
run_step "Configuring secure access" 80 configure_ssh
run_step "Starting and verifying services" 100 refresh_and_finish

FINISHED=true
echo
draw_live_progress 100 "Complete" ""
echo
echo
if [[ "$MODE" == "update" ]]; then
    echo -e "  ${C_GREEN}${C_BOLD}✓ UPDATE COMPLETE${C_RESET}"
    echo -e "  ${C_GRAY}  All accounts and settings were preserved.${C_RESET}"
else
    echo -e "  ${C_GREEN}${C_BOLD}✓ INSTALLATION COMPLETE${C_RESET}"
fi
echo -e "  ${C_CYAN}  Run: ${C_BOLD}menu${C_RESET}"
echo
