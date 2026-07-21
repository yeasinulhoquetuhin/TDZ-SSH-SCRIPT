#!/bin/bash
set -Eeuo pipefail

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
TARGET_LIB_DIR="/usr/local/lib/tdz-ssh-tunnel"
DATA_DIR="/etc/tdztunnel"
INSTALL_FLAG="$DATA_DIR/.install"
SSHD_CONFIG="/etc/ssh/sshd_config"
SSHD_DROPIN_DIR="/etc/ssh/sshd_config.d"
SSHD_DROPIN="$SSHD_DROPIN_DIR/tdztunnel.conf"

# ── Source dir (set by binary, or use GitHub URLs as fallback) ──
if [[ -n "${TDZ_RAM:-}" && -d "${TDZ_RAM}" ]]; then
    SRC_DIR="${TDZ_RAM}"
else
    SRC_DIR="$(CDPATH= cd -- "$(dirname -- "$0")" 2>/dev/null && pwd || true)"
fi

WORK_DIR="$(mktemp -d /tmp/tdz-installer.XXXXXX)"
LOG_FILE="$WORK_DIR/install.log"

# Copy scripts from SRC_DIR if available, otherwise download from GitHub
load_script() {
    local name="$1"
    local dest="$2"
    local url="$3"
    
    if [[ -f "${SRC_DIR}/${name}" ]]; then
        cp "${SRC_DIR}/${name}" "${dest}"
        echo "  (local) ${name}"
    else
        curl -fsSL -o "${dest}" "${url}" || return 1
        echo "  (download) ${name}"
    fi
}

MODE="install"
if [[ -x "$TARGET_MENU" || -f "$INSTALL_FLAG" || -f "$DATA_DIR/users.db" ||
      -f "$DATA_DIR/banners_enabled" ]]; then
    MODE="update"
fi

trap 'rm -rf "$WORK_DIR"' EXIT

echo ""
echo "${C_CYAN}${C_BOLD}============================================${C_RESET}"
echo "${C_CYAN}${C_BOLD}   TDZ SSH TUNNEL - ${MODE^}${C_RESET}"
echo "${C_CYAN}${C_BOLD}============================================${C_RESET}"
echo ""

# ── Load scripts ──
echo "${C_GREEN}[*] Loading scripts...${C_RESET}"

load_script "menu.sh" "$WORK_DIR/menu.sh" \
    "https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/menu.sh"

load_script "openvpn_module.sh" "$WORK_DIR/openvpn_module.sh" \
    "https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/openvpn_module.sh"

load_script "tdz_ssh_auth_session.py" "$WORK_DIR/tdz_ssh_auth_session.py" \
    "https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/tdz_ssh_auth_session.py"

load_script "ws_ssh_bridge.py" "$WORK_DIR/ws_ssh_bridge.py" \
    "https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/ws_ssh_bridge.py"

load_script "tdz_openvpn_gateway.py" "$WORK_DIR/tdz_openvpn_gateway.py" \
    "https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/tdz_openvpn_gateway.py"

load_script "tdz_openvpn_portal.py" "$WORK_DIR/tdz_openvpn_portal.py" \
    "https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/tdz_openvpn_portal.py"

load_script "tdz_openvpn_runtime.py" "$WORK_DIR/tdz_openvpn_runtime.py" \
    "https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/tdz_openvpn_runtime.py"

load_script "ssh" "$WORK_DIR/ssh" \
    "https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/ssh"

chmod +x "$WORK_DIR"/*.sh "$WORK_DIR"/*.py "$WORK_DIR"/ssh 2>/dev/null || true

# ── Install dependencies ──
echo ""
echo "${C_GREEN}[*] Installing dependencies...${C_RESET}"

if command -v apt-get >/dev/null 2>&1; then
    export DEBIAN_FRONTEND=noninteractive
    apt-get update -qq
    apt-get install -y -qq openssh-server curl wget python3 python3-pip \
        stunnel4 haproxy nginx certbot net-tools iptables bc jq \
        dropbear openvpn easy-rsa 2>/dev/null || true
elif command -v yum >/dev/null 2>&1; then
    yum install -y openssh-server curl wget python3 python3-pip \
        stunnel haproxy nginx certbot net-tools iptables bc jq \
        openvpn easy-rsa 2>/dev/null || true
elif command -v apk >/dev/null 2>&1; then
    apk add --no-cache openssh curl wget python3 py3-pip \
        stunnel haproxy nginx certbot iptables bc jq \
        openvpn easy-rsa 2>/dev/null || true
fi

# ── Set up directories ──
echo "${C_GREEN}[*] Setting up directories...${C_RESET}"
mkdir -p "${TARGET_LIB_DIR}" "${DATA_DIR}"

# ── Install scripts ──
echo "${C_GREEN}[*] Installing scripts...${C_RESET}"
cp "$WORK_DIR/menu.sh" "${TARGET_LIB_DIR}/menu.sh"
cp "$WORK_DIR/openvpn_module.sh" "${TARGET_LIB_DIR}/openvpn_module.sh"
cp "$WORK_DIR/tdz_ssh_auth_session.py" "${TARGET_LIB_DIR}/tdz_ssh_auth_session.py"
cp "$WORK_DIR/ws_ssh_bridge.py" "${TARGET_LIB_DIR}/ws_ssh_bridge.py"
cp "$WORK_DIR/tdz_openvpn_gateway.py" "${TARGET_LIB_DIR}/tdz_openvpn_gateway.py"
cp "$WORK_DIR/tdz_openvpn_portal.py" "${TARGET_LIB_DIR}/tdz_openvpn_portal.py"
cp "$WORK_DIR/tdz_openvpn_runtime.py" "${TARGET_LIB_DIR}/tdz_openvpn_runtime.py"
cp "$WORK_DIR/ssh" "${TARGET_LIB_DIR}/ssh" 2>/dev/null || true
chmod +x "${TARGET_LIB_DIR}"/*

# ── Symlink menu ──
ln -sf "${TARGET_LIB_DIR}/menu.sh" "${TARGET_MENU}"
ln -sf "${TARGET_LIB_DIR}/ws_ssh_bridge.py" "/usr/local/bin/tdz-ws-ssh-bridge.py"
chmod +x "${TARGET_MENU}" 2>/dev/null || true

# ── Mark installed ──
touch "${INSTALL_FLAG}"

# ── Enable SSH ──
if command -v systemctl >/dev/null 2>&1; then
    systemctl enable sshd >/dev/null 2>&1 || systemctl enable ssh >/dev/null 2>&1 || true
    systemctl restart sshd >/dev/null 2>&1 || systemctl restart ssh >/dev/null 2>&1 || true
fi

echo ""
echo "${C_GREEN}${C_BOLD}============================================${C_RESET}"
echo "${C_GREEN}${C_BOLD}   TDZ SSH TUNNEL ${MODE^} COMPLETE!${C_RESET}"
echo "${C_GREEN}${C_BOLD}   Run: menu${C_RESET}"
echo "${C_GREEN}${C_BOLD}============================================${C_RESET}"
echo ""
