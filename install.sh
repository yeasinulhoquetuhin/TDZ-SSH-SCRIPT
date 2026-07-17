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
    C_RESET='\033[0m'; C_BOLD='\033[1m'; C_DIM='\033[2m'
    C_CYAN='\033[38;2;0;212;255m'; C_GREEN='\033[38;5;46m'
    C_YELLOW='\033[38;5;226m'; C_RED='\033[38;5;196m'; C_GRAY='\033[38;5;245m'
else
    C_RESET=''; C_BOLD=''; C_DIM=''; C_CYAN=''; C_GREEN=''; C_YELLOW=''; C_RED=''; C_GRAY=''
fi

TARGET_MENU="/usr/local/bin/menu"
TARGET_BRIDGE="/usr/local/bin/tdz-ws-ssh-bridge.py"
DATA_DIR="/etc/tdztunnel"
INSTALL_FLAG="$DATA_DIR/.install"
SSHD_CONFIG="/etc/ssh/sshd_config"
SSHD_DROPIN_DIR="/etc/ssh/sshd_config.d"
SSHD_DROPIN="$SSHD_DROPIN_DIR/tdztunnel.conf"
SCRIPT_DIR="$(CDPATH= cd -- "$(dirname -- "$0")" 2>/dev/null && pwd || true)"
MENU_URL="${MENU_URL:-https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/menu.sh}"
BRIDGE_URL="${BRIDGE_URL:-https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/ws_ssh_bridge.py}"

WORK_DIR="$(mktemp -d /tmp/tdz-installer.XXXXXX)"
LOG_FILE="$WORK_DIR/install.log"
PAYLOAD_MENU="$WORK_DIR/menu.sh"
PAYLOAD_BRIDGE="$WORK_DIR/ws_ssh_bridge.py"
OLD_MENU="$WORK_DIR/menu.previous"
OLD_SSHD_CONFIG="$WORK_DIR/sshd_config.previous"
OLD_SSHD_DROPIN="$WORK_DIR/sshd_dropin.previous"
HAD_OLD_MENU=false
HAD_OLD_DROPIN=false
SSH_CHANGED=false
FINISHED=false

MODE="install"
if [[ -x "$TARGET_MENU" || -f "$INSTALL_FLAG" || -f "$DATA_DIR/users.db" ||
      -f "$DATA_DIR/banners_enabled" ]]; then
    MODE="update"
fi

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
    print_centered_line "TDZ SSH TUNNEL • SETUP" "${C_BOLD}${C_CYAN}TDZ SSH TUNNEL • SETUP${C_RESET}"
    print_centered_line "T.me/TuhinBroh" "${C_GRAY}T.me/TuhinBroh${C_RESET}"
    echo -e "  ${C_CYAN}╚════════════════════════════════════════════════════════════════╝${C_RESET}"
    echo
    if [[ "$MODE" == "update" ]]; then
        echo -e "  ${C_YELLOW}● Existing installation detected${C_RESET}"
        echo -e "  ${C_DIM}  Safe update mode • accounts and settings will be preserved${C_RESET}"
    else
        echo -e "  ${C_GREEN}● New installation${C_RESET}"
        echo -e "  ${C_DIM}  Preparing a clean TDZ SSH TUNNEL setup${C_RESET}"
    fi
    echo
}

TOTAL_STEPS=5
CURRENT_STEP=0

draw_progress() {
    local done_count=$1 width=36 filled empty percent bar=""
    percent=$((done_count * 100 / TOTAL_STEPS))
    filled=$((done_count * width / TOTAL_STEPS))
    empty=$((width - filled))
    (( filled > 0 )) && printf -v bar '%*s' "$filled" '' && bar=${bar// /■}
    if (( empty > 0 )); then
        local rest
        printf -v rest '%*s' "$empty" ''
        rest=${rest// /·}
        bar+="$rest"
    fi
    echo -e "  ${C_CYAN}[${bar}]${C_RESET} ${C_BOLD}${percent}%${C_RESET}"
}

run_step() {
    local label=$1
    shift
    CURRENT_STEP=$((CURRENT_STEP + 1))
    printf "  %s[%d/%d]%s %-40s" "$C_CYAN" "$CURRENT_STEP" "$TOTAL_STEPS" "$C_RESET" "$label"
    if "$@" >>"$LOG_FILE" 2>&1; then
        echo -e " ${C_GREEN}DONE${C_RESET}"
        draw_progress "$CURRENT_STEP"
        return 0
    fi
    echo -e " ${C_RED}FAILED${C_RESET}"
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
}

backup_current_state() {
    if [[ -f "$TARGET_MENU" ]]; then
        cp "$TARGET_MENU" "$OLD_MENU"
        HAD_OLD_MENU=true
    fi
    [[ -f "$SSHD_CONFIG" ]] || return 1
    cp "$SSHD_CONFIG" "$OLD_SSHD_CONFIG"
    if [[ -f "$SSHD_DROPIN" ]]; then
        cp "$SSHD_DROPIN" "$OLD_SSHD_DROPIN"
        HAD_OLD_DROPIN=true
    fi
}

install_core() {
    install -m 755 "$PAYLOAD_MENU" "$TARGET_MENU"
    if [[ -s "$PAYLOAD_BRIDGE" ]]; then
        install -m 755 "$PAYLOAD_BRIDGE" "$TARGET_BRIDGE"
    fi
}

configure_ssh() {
    local sshd_bin
    sshd_bin="$(command -v sshd 2>/dev/null || true)"
    [[ -n "$sshd_bin" ]] || sshd_bin="/usr/sbin/sshd"
    [[ -x "$sshd_bin" ]] || return 1

    SSH_CHANGED=true
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

show_header
draw_progress 0
echo
run_step "Downloading and validating release" prepare_payload
run_step "Protecting current installation" backup_current_state
run_step "Installing application components" install_core
run_step "Applying validated SSH configuration" configure_ssh
run_step "Synchronizing services and saved state" sync_runtime
finish_setup

FINISHED=true
echo
if [[ "$MODE" == "update" ]]; then
    echo -e "  ${C_GREEN}${C_BOLD}✓ TDZ SSH TUNNEL updated successfully${C_RESET}"
    echo -e "  ${C_GRAY}Accounts, usage, certificates, Telegram settings, and banner state were preserved.${C_RESET}"
else
    echo -e "  ${C_GREEN}${C_BOLD}✓ TDZ SSH TUNNEL installed successfully${C_RESET}"
fi
echo -e "  ${C_CYAN}Run ${C_BOLD}menu${C_RESET}${C_CYAN} to open the dashboard.${C_RESET}"
echo
