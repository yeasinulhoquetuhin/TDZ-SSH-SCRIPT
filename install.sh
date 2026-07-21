#!/bin/bash
set -Eeuo pipefail

# TDZ SSH TUNNEL checksummed-release installer/updater. A version argument pins any
# published release, for example: install.sh v0.0.3

DEFAULT_VERSION="v0.0.1"
REPOSITORY="yeasinulhoquetuhin/TDZ-SSH-SCRIPT"
REQUESTED_VERSION="${1:-$DEFAULT_VERSION}"
TARGET_BINARY="/usr/local/bin/tdz"
TARGET_MENU="/usr/local/bin/menu"
DATA_DIR="/etc/tdztunnel"
INSTALL_FLAG="$DATA_DIR/.install"
SSHD_CONFIG="/etc/ssh/sshd_config"
SSHD_DROPIN_DIR="/etc/ssh/sshd_config.d"
SSHD_DROPIN="$SSHD_DROPIN_DIR/tdztunnel.conf"
SSH_PAM_CONFIG="/etc/pam.d/sshd"
GUARD_SERVICE="/etc/systemd/system/tdz-ssh-branding-guard.service"
LEGACY_LIB_DIR="/usr/local/lib/tdz-ssh-tunnel"

if [[ ${EUID:-$(id -u)} -ne 0 && "${TDZ_INSTALLER_TEST_MODE:-0}" != "1" &&
      "${TDZ_INSTALLER_VERIFY_ONLY:-0}" != "1" ]]; then
    echo "Error: This installer must be run as root."
    exit 1
fi

if [[ ! "$REQUESTED_VERSION" =~ ^(latest|v[0-9]+\.[0-9]+\.[0-9]+([.-][A-Za-z0-9.-]+)?)$ ]]; then
    echo "Error: Invalid release version: $REQUESTED_VERSION"
    exit 1
fi

if [[ -t 1 ]]; then
    C_RESET=$'\033[0m'; C_BOLD=$'\033[1m'; C_DIM=$'\033[2m'
    C_CYAN=$'\033[38;2;0;212;255m'; C_GREEN=$'\033[38;5;46m'
    C_YELLOW=$'\033[38;5;226m'; C_RED=$'\033[38;5;196m'; C_GRAY=$'\033[38;5;245m'
else
    C_RESET=''; C_BOLD=''; C_DIM=''; C_CYAN=''; C_GREEN=''
    C_YELLOW=''; C_RED=''; C_GRAY=''
fi

detect_architecture() {
    local machine
    machine=$(uname -m)
    case "$machine" in
        x86_64|amd64) echo "amd64" ;;
        aarch64|arm64) echo "arm64" ;;
        armv7l|armv7) echo "armv7" ;;
        armv6l|armv6) echo "armv6" ;;
        i386|i486|i586|i686) echo "386" ;;
        ppc64le) echo "ppc64le" ;;
        s390x) echo "s390x" ;;
        riscv64) echo "riscv64" ;;
        *) return 1 ;;
    esac
}

ARCH=$(detect_architecture) || {
    echo "Error: Unsupported CPU architecture: $(uname -m)"
    exit 1
}
ASSET="tdz-linux-${ARCH}.tar.gz"

if [[ -n "${TDZ_RELEASE_BASE_URL:-}" ]]; then
    RELEASE_BASE="${TDZ_RELEASE_BASE_URL%/}"
elif [[ "$REQUESTED_VERSION" == "latest" ]]; then
    RELEASE_BASE="https://github.com/$REPOSITORY/releases/latest/download"
else
    RELEASE_BASE="https://github.com/$REPOSITORY/releases/download/$REQUESTED_VERSION"
fi

if [[ "${TDZ_INSTALLER_TEST_MODE:-0}" == "1" ]]; then
    return 0 2>/dev/null || exit 0
fi

WORK_DIR=$(mktemp -d /tmp/tdz-installer.XXXXXX)
LOG_FILE="$WORK_DIR/install.log"
ARCHIVE="$WORK_DIR/$ASSET"
CHECKSUMS="$WORK_DIR/checksums.txt"
EXTRACT_DIR="$WORK_DIR/extracted"
PAYLOAD_BINARY="$EXTRACT_DIR/tdz"
BACKUP_DIR="$WORK_DIR/rollback"
MODE="install"
FINISHED=false
CHANGED_SYSTEM=false

[[ -x "$TARGET_BINARY" || -e "$TARGET_MENU" || -f "$INSTALL_FLAG" || -f "$DATA_DIR/users.db" ]] && MODE="update"

declare -a DISPATCH_LINKS=(
    /usr/local/bin/tdz-limiter
    /usr/local/bin/tdz-trial-cleanup
    /usr/local/bin/tdz-auto-backup-bot
    /usr/local/bin/tdz-ws-ssh-bridge
    /usr/local/bin/tdz-openvpn-runtime
    /usr/local/bin/tdz-openvpn-gateway
    /usr/local/bin/tdz-openvpn-portal
    /usr/local/bin/tdz-openvpn-firewall
    /usr/local/bin/tdz-ssh-auth
    # Compatibility entrypoints for services/jobs made by source releases.
    /usr/local/bin/tdztunnel-limiter.sh
    /usr/local/bin/tdztunnel-trial-cleanup.sh
    /usr/local/bin/tdztunnel-auto-backup-bot.sh
    /usr/local/bin/tdz-ws-ssh-bridge.py
)

declare -a SNAPSHOT_PATHS=(
    "$TARGET_BINARY" "$TARGET_MENU" "${DISPATCH_LINKS[@]}"
    "$LEGACY_LIB_DIR" "$SSHD_CONFIG" "$SSHD_DROPIN" "$SSH_PAM_CONFIG"
    "$GUARD_SERVICE"
    /etc/systemd/system/multi-user.target.wants/tdz-ssh-branding-guard.service
    /etc/systemd/system/tdztunnel-limiter.service
    /etc/systemd/system/tdz-ws-ssh-bridge.service
    /etc/tdztunnel/openvpn/hooks
)
for unit in /etc/systemd/system/tdz-openvpn-*.service; do
    [[ -e "$unit" || -L "$unit" ]] && SNAPSHOT_PATHS+=("$unit")
done
declare -A SNAPSHOT_EXISTS=()

BOX_MAX_WIDTH=64
BOX_WIDTH=$BOX_MAX_WIDTH
if [[ -t 1 ]]; then
    terminal_columns=${COLUMNS:-}
    [[ "$terminal_columns" =~ ^[0-9]+$ ]] || terminal_columns=$(tput cols 2>/dev/null || true)
    if [[ "$terminal_columns" =~ ^[0-9]+$ ]]; then
        BOX_WIDTH=$((terminal_columns - 4))
        (( BOX_WIDTH > BOX_MAX_WIDTH )) && BOX_WIDTH=$BOX_MAX_WIDTH
        (( BOX_WIDTH < 24 )) && BOX_WIDTH=24
    fi
fi

cleanup() {
    find "$WORK_DIR" -depth -type f -delete 2>/dev/null || true
    find "$WORK_DIR" -depth -type l -delete 2>/dev/null || true
    find "$WORK_DIR" -depth -type d -empty -delete 2>/dev/null || true
}

restart_ssh() {
    systemctl restart sshd >/dev/null 2>&1 || systemctl restart ssh >/dev/null 2>&1
}

reload_system_state() {
    systemctl daemon-reload >/dev/null 2>&1 || true
    restart_ssh >/dev/null 2>&1 || true
    systemctl try-restart tdztunnel-limiter.service >/dev/null 2>&1 || true
    systemctl try-restart tdz-ws-ssh-bridge.service >/dev/null 2>&1 || true
}

backup_current_state() {
    local path destination
    mkdir -p "$BACKUP_DIR"
    for path in "${SNAPSHOT_PATHS[@]}"; do
        if [[ -e "$path" || -L "$path" ]]; then
            SNAPSHOT_EXISTS["$path"]=1
            destination="$BACKUP_DIR$path"
            mkdir -p "$(dirname "$destination")"
            cp -a "$path" "$destination"
        else
            SNAPSHOT_EXISTS["$path"]=0
        fi
    done
}

remove_path() {
    local path=$1
    if [[ -d "$path" && ! -L "$path" ]]; then
        find "$path" -depth -type f -delete 2>/dev/null || true
        find "$path" -depth -type l -delete 2>/dev/null || true
        find "$path" -depth -type d -empty -delete 2>/dev/null || true
        rmdir "$path" 2>/dev/null || true
    else
        unlink "$path" 2>/dev/null || true
    fi
}

rollback() {
    $FINISHED && return 0
    local path source
    for path in "${SNAPSHOT_PATHS[@]}"; do
        remove_path "$path"
        if [[ "${SNAPSHOT_EXISTS[$path]:-0}" == "1" ]]; then
            source="$BACKUP_DIR$path"
            mkdir -p "$(dirname "$path")"
            cp -a "$source" "$path" 2>/dev/null || true
        fi
    done
    reload_system_state
}

on_exit() {
    local rc=$?
    if (( rc != 0 )); then
        $CHANGED_SYSTEM && rollback
        mkdir -p /var/log 2>/dev/null || true
        cp "$LOG_FILE" /var/log/tdz-install-failed.log 2>/dev/null || true
        echo
        echo -e "  ${C_RED}${C_BOLD}Installation could not be completed.${C_RESET}"
        echo -e "  ${C_GRAY}Previous application files and saved data were preserved.${C_RESET}"
        echo -e "  ${C_GRAY}Diagnostic log: /var/log/tdz-install-failed.log${C_RESET}"
    fi
    cleanup
    exit "$rc"
}
trap on_exit EXIT

print_centered_line() {
    local clean_text=$1 styled_text=$2 left right
    if (( ${#clean_text} > BOX_WIDTH )); then clean_text="${clean_text:0:BOX_WIDTH}"; styled_text="$clean_text"; fi
    left=$(( (BOX_WIDTH - ${#clean_text}) / 2 )); (( left < 0 )) && left=0
    right=$((BOX_WIDTH - ${#clean_text} - left)); (( right < 0 )) && right=0
    printf "  ${C_CYAN}║${C_RESET}%*s%s%*s${C_CYAN}║${C_RESET}\n" "$left" "" "$styled_text" "$right" ""
}

show_header() {
    [[ -t 1 ]] && clear || true
    echo
    printf "  %s╔" "$C_CYAN"; printf '═%.0s' $(seq 1 "$BOX_WIDTH"); printf "╗%s\n" "$C_RESET"
    print_centered_line "TDZ SSH TUNNEL   •   SETUP" "${C_CYAN}TDZ SSH TUNNEL   •   SETUP${C_RESET}"
    print_centered_line "Powered By: t.me/TuhinBroh" "${C_GRAY}Powered By: t.me/TuhinBroh${C_RESET}"
    printf "  %s╚" "$C_CYAN"; printf '═%.0s' $(seq 1 "$BOX_WIDTH"); printf "╝%s\n" "$C_RESET"
    echo
    if [[ "$MODE" == "update" ]]; then
        echo -e "  ${C_YELLOW}${C_BOLD}● UPDATE MODE${C_RESET}"
        echo -e "  ${C_DIM}  Release $REQUESTED_VERSION • saved data will be preserved${C_RESET}"
    else
        echo -e "  ${C_GREEN}${C_BOLD}● INSTALL MODE${C_RESET}"
        echo -e "  ${C_DIM}  Release $REQUESTED_VERSION • architecture $ARCH${C_RESET}"
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
    filled=$((percent * width / 100)); empty=$((width - filled))
    (( filled > 0 )) && printf -v fill_bar '%*s' "$filled" '' && fill_bar=${fill_bar// /█}
    if (( empty > 0 )); then printf -v empty_bar '%*s' "$empty" ''; empty_bar=${empty_bar// /░}; fi
    printf '\r\033[2K  %s[%s%s%s%s]%s %s%3d%%%s  %s%s%s' \
        "$C_CYAN" "$fill_bar" "$C_GRAY" "$empty_bar" "$C_CYAN" "$C_RESET" \
        "$C_BOLD" "$percent" "$C_RESET" "$label" "$spinner" "$C_RESET"
}

run_step() {
    local label=$1 target_percent=$2 job_pid tick percent spinner_index=0
    shift 2
    local -a spinners=(' ◐' ' ◓' ' ◑' ' ◒')
    CURRENT_STEP=$((CURRENT_STEP + 1))
    if [[ ! -t 1 ]]; then
        printf '  [%d/%d] %-28s' "$CURRENT_STEP" "$TOTAL_STEPS" "$label"
        if "$@" >>"$LOG_FILE" 2>&1; then echo " DONE"; CURRENT_PERCENT=$target_percent; return 0; fi
        echo " FAILED"; return 1
    fi
    "$@" >>"$LOG_FILE" 2>&1 & job_pid=$!
    for ((tick=1; tick<=ANIMATION_TICKS; tick++)); do
        percent=$((CURRENT_PERCENT + (target_percent - CURRENT_PERCENT) * tick / ANIMATION_TICKS))
        (( percent >= target_percent )) && percent=$((target_percent - 1))
        draw_live_progress "$percent" "$label" "${spinners[$spinner_index]}"
        spinner_index=$(((spinner_index + 1) % ${#spinners[@]})); sleep 0.1
    done
    while kill -0 "$job_pid" 2>/dev/null; do
        draw_live_progress "$((target_percent - 1))" "$label" "${spinners[$spinner_index]}"
        spinner_index=$(((spinner_index + 1) % ${#spinners[@]})); sleep 0.1
    done
    if wait "$job_pid"; then printf '\r\033[2K  %s✓%s %s\n' "$C_GREEN" "$C_RESET" "$label"; CURRENT_PERCENT=$target_percent; return 0; fi
    printf '\r\033[2K  %s✗%s %s\n' "$C_RED" "$C_RESET" "$label"; return 1
}

download_file() {
    local url=$1 destination=$2
    if command -v curl >/dev/null 2>&1; then
        curl -4 -fLsS --retry 3 --connect-timeout 15 -o "$destination" "$url"
    elif command -v wget >/dev/null 2>&1; then
        wget -4 -q --tries=3 --timeout=30 -O "$destination" "$url"
    else
        return 1
    fi
}

prepare_payload() {
    mkdir -p "$EXTRACT_DIR"
    if [[ -n "${TDZ_RELEASE_DIR:-}" ]]; then
        cp "${TDZ_RELEASE_DIR%/}/$ASSET" "$ARCHIVE"
        cp "${TDZ_RELEASE_DIR%/}/checksums.txt" "$CHECKSUMS"
    else
        download_file "$RELEASE_BASE/$ASSET" "$ARCHIVE"
        download_file "$RELEASE_BASE/checksums.txt" "$CHECKSUMS"
    fi
    local expected actual archive_listing archive_size binary_size
    archive_size=$(stat -c '%s' "$ARCHIVE" 2>/dev/null || echo 0)
    [[ "$archive_size" =~ ^[0-9]+$ && "$archive_size" -gt 0 && "$archive_size" -le 67108864 ]] || return 1
    expected=$(awk -v asset="$ASSET" '$2 == asset || $2 == "*" asset { print $1; exit }' "$CHECKSUMS")
    [[ "$expected" =~ ^[a-fA-F0-9]{64}$ ]] || return 1
    actual=$(sha256sum "$ARCHIVE" | awk '{print $1}')
    [[ "${actual,,}" == "${expected,,}" ]] || return 1
    archive_listing=$(tar -tzf "$ARCHIVE")
    [[ "$archive_listing" == "tdz" ]] || return 1
    tar --no-same-owner -xzf "$ARCHIVE" -C "$EXTRACT_DIR"
    [[ -f "$PAYLOAD_BINARY" && ! -L "$PAYLOAD_BINARY" ]] || return 1
    binary_size=$(stat -c '%s' "$PAYLOAD_BINARY" 2>/dev/null || echo 0)
    [[ "$binary_size" =~ ^[0-9]+$ && "$binary_size" -gt 0 && "$binary_size" -le 67108864 ]] || return 1
    chmod 755 "$PAYLOAD_BINARY"
    local reported reported_version reported_arch
    reported=$("$PAYLOAD_BINARY" version --json)
    reported_version=$(sed -n 's/.*"version":"\([^"]*\)".*/\1/p' <<<"$reported")
    reported_arch=$(sed -n 's/.*"arch":"\([^"]*\)".*/\1/p' <<<"$reported")
    [[ "$reported_arch" == "$ARCH" ]] || return 1
    [[ "$REQUESTED_VERSION" == "latest" || "${reported_version%% *}" == "$REQUESTED_VERSION" ]] || return 1
    "$PAYLOAD_BINARY" self-test >/dev/null
}

install_core() {
    local link
    install -d -m 755 /usr/local/bin
    install -m 755 "$PAYLOAD_BINARY" "${TARGET_BINARY}.new"
    mv -f "${TARGET_BINARY}.new" "$TARGET_BINARY"
    for link in "$TARGET_MENU" "${DISPATCH_LINKS[@]}"; do
        if [[ -d "$link" && ! -L "$link" ]]; then return 1; fi
        unlink "$link" 2>/dev/null || true
        ln -s "$TARGET_BINARY" "$link"
    done
}

configure_ssh() {
    local sshd_bin
    sshd_bin=$(command -v sshd 2>/dev/null || true); [[ -n "$sshd_bin" ]] || sshd_bin=/usr/sbin/sshd
    [[ -x "$sshd_bin" && -f "$SSHD_CONFIG" ]] || return 1
    mkdir -p "$SSHD_DROPIN_DIR"
    sed -i \
        -e 's/^[[:space:]]*AddressFamily[[:space:]]\+any[[:space:]]*$/# TDZ disabled: AddressFamily any/' \
        -e 's/^[[:space:]]*ListenAddress[[:space:]]\+::[[:space:]]*$/# TDZ disabled: ListenAddress ::/' \
        "$SSHD_CONFIG"
    if ! grep -qE '^[[:space:]]*Include[[:space:]]+/etc/ssh/sshd_config\.d/\*\.conf' "$SSHD_CONFIG"; then
        printf '\n# TDZ SSH TUNNEL drop-ins\nInclude /etc/ssh/sshd_config.d/*.conf\n' >> "$SSHD_CONFIG"
    fi
    cat > "$SSHD_DROPIN" <<'EOF'
# TDZ SSH TUNNEL safe SSH settings
Port 22
DebianBanner no
VersionAddendum @TuhinBroh
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

install_guard_service() {
    cat > "$GUARD_SERVICE" <<EOF
[Unit]
Description=TDZ SSH Identification Integrity Guard
After=ssh.service sshd.service

[Service]
Type=simple
ExecStart=$TARGET_BINARY guard ssh-branding
Restart=always
RestartSec=2
NoNewPrivileges=true

[Install]
WantedBy=multi-user.target
EOF
    systemctl daemon-reload >/dev/null 2>&1
    systemctl enable tdz-ssh-branding-guard.service >/dev/null 2>&1
}

sync_runtime() {
    if [[ "$MODE" == "update" ]]; then "$TARGET_BINARY" --update-setup; else "$TARGET_BINARY" --install-setup; fi
}

verify_runtime() {
    "$TARGET_BINARY" self-test
    "$TARGET_BINARY" --source-only
    /usr/local/bin/tdz-openvpn-runtime --help >/dev/null
    "$TARGET_BINARY" guard ssh-branding --once
    restart_ssh
    systemctl restart tdz-ssh-branding-guard.service >/dev/null 2>&1
    systemctl is-active --quiet tdz-ssh-branding-guard.service
    mkdir -p "$DATA_DIR"; touch "$INSTALL_FLAG"
    # Plaintext source runtimes from older releases are no longer needed.
    remove_path "$LEGACY_LIB_DIR"
}

refresh_and_finish() {
    install_guard_service
    sync_runtime
    verify_runtime
}

if [[ "${TDZ_INSTALLER_VERIFY_ONLY:-0}" == "1" ]]; then
    prepare_payload
    FINISHED=true
    echo "Verified $ASSET for $REQUESTED_VERSION"
    exit 0
fi

show_header
run_step "Checking latest release" 20 prepare_payload
run_step "Saving current setup" 40 backup_current_state
CHANGED_SYSTEM=true
run_step "Updating core files" 60 install_core
run_step "Validating SSH setup" 80 configure_ssh
run_step "Refreshing services" 100 refresh_and_finish

FINISHED=true
echo
draw_live_progress 100 "Completed" ""
echo; echo
if [[ "$MODE" == "update" ]]; then
    echo -e "  ${C_GREEN}${C_BOLD}✓ UPDATE COMPLETED${C_RESET}"
    echo -e "  ${C_GRAY}  All accounts and settings were preserved.${C_RESET}"
else
    echo -e "  ${C_GREEN}${C_BOLD}✓ INSTALLATION COMPLETED${C_RESET}"
fi
echo -e "  ${C_CYAN}  Release: ${C_BOLD}$REQUESTED_VERSION${C_RESET}"
echo -e "  ${C_CYAN}  Run: ${C_BOLD}menu${C_RESET}"
echo
