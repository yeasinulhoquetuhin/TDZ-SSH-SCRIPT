#!/bin/bash

C_RESET=$'\033[0m'
C_BOLD=$'\033[1m'
C_DIM=$'\033[2m'
C_UL=$'\033[4m'

# TDZ TUNNEL Premium Color Palette - Bright Cyan-Blue + Cyan Accent
# (Bright enough to read on black terminals; previous navy was invisible.)
C_RED=$'\033[38;5;196m'           # Bright Red
C_GREEN=$'\033[38;5;46m'          # Neon Green
C_YELLOW=$'\033[38;5;226m'        # Bright Yellow
C_NAVY=$'\033[38;5;39m'           # Bright cyan-blue (replaces too-dark #1e3a5f)
C_BLUE=$'\033[38;2;0;212;255m'    # Cyan #00d4ff  (brand accent)
C_PURPLE=$'\033[38;5;99m'         # Soft purple
C_CYAN=$'\033[38;2;0;212;255m'    # Cyan #00d4ff
C_WHITE=$'\033[38;5;255m'         # Bright White
C_GRAY=$'\033[38;5;245m'          # Gray
C_ORANGE=$'\033[38;5;208m'        # Orange

# Semantic Aliases
C_TITLE=$C_NAVY      # Navy for titles
C_CHOICE=$C_CYAN     # Cyan for choices
C_PROMPT=$C_BLUE     # Cyan for prompts
C_WARN=$C_YELLOW
C_DANGER=$C_RED
C_STATUS_A=$C_GREEN
C_STATUS_I=$C_GRAY
C_ACCENT=$C_CYAN     # Cyan accent (was Orange)

DB_DIR="/etc/tdztunnel"
DB_FILE="$DB_DIR/users.db"
INSTALL_FLAG_FILE="$DB_DIR/.install"
BADVPN_SERVICE_FILE="/etc/systemd/system/badvpn.service"
BADVPN_BUILD_DIR="/root/badvpn-build"
HAPROXY_CONFIG="/etc/haproxy/haproxy.cfg"
NGINX_CONFIG_FILE="/etc/nginx/sites-available/default"
SSL_CERT_DIR="/etc/tdztunnel/ssl"
TDZ_SSL_CERT_FILE="$SSL_CERT_DIR/tdztunnel.pem"
SSL_CERT_CHAIN_FILE="$SSL_CERT_DIR/tdztunnel.crt"
SSL_CERT_KEY_FILE="$SSL_CERT_DIR/tdztunnel.key"
EDGE_CERT_INFO_FILE="$DB_DIR/edge_cert.conf"
NGINX_PORTS_FILE="$DB_DIR/nginx_ports.conf"
EDGE_PORT_SETTINGS_FILE="$DB_DIR/edge_ports.conf"
DEFAULT_EDGE_PUBLIC_HTTP_PORT="2080"
DEFAULT_EDGE_PUBLIC_TLS_PORT="442"
EDGE_PUBLIC_HTTP_PORT="$DEFAULT_EDGE_PUBLIC_HTTP_PORT"
EDGE_PUBLIC_TLS_PORT="$DEFAULT_EDGE_PUBLIC_TLS_PORT"
NGINX_INTERNAL_HTTP_PORT="8770"
NGINX_INTERNAL_TLS_PORT="8442"
HAPROXY_INTERNAL_DECRYPT_PORT="10443"
# WebSocket-to-SSH bridge (DarkTunnel / HTTP Custom / NPV payload support)
WS_SSH_BRIDGE_SCRIPT="/usr/local/bin/tdz-ws-ssh-bridge.py"
WS_SSH_BRIDGE_SERVICE="/etc/systemd/system/tdz-ws-ssh-bridge.service"
WS_SSH_BRIDGE_PORT="8890"
SSH_BANNER_FILE="/etc/tdztunnel/bannerssh"
BANNER_IDENTITY_CONF="$DB_DIR/banner_identity.conf"
DEFAULT_BANNER_ADMIN_USERNAME="TUSTDZ"
DEFAULT_BANNER_CHANNEL_USERNAME="TuhinBroh"
DNSTT_SERVICE_FILE="/etc/systemd/system/dnstt.service"
DNSTT_BINARY="/usr/local/bin/dnstt-server"
DNSTT_KEYS_DIR="/etc/tdztunnel/dnstt"
DNSTT_CONFIG_FILE="$DB_DIR/dnstt_info.conf"
UDP_CUSTOM_DIR="/root/udp"
UDP_CUSTOM_SERVICE_FILE="/etc/systemd/system/udp-custom.service"
UDPGW_BINARY="/usr/local/bin/udpgw"
UDPGW_SERVICE_FILE="/etc/systemd/system/udpgw.service"
TDZPROXY_SERVICE_FILE="/etc/systemd/system/tdzproxy.service"
TDZPROXY_BINARY="/usr/local/bin/tdzproxy"
TDZPROXY_CONFIG_FILE="$DB_DIR/tdzproxy_config.conf"
LIMITER_SCRIPT="/usr/local/bin/tdztunnel-limiter.sh"
LIMITER_SERVICE="/etc/systemd/system/tdztunnel-limiter.service"
BANDWIDTH_DIR="$DB_DIR/bandwidth"
BANDWIDTH_SCRIPT="/usr/local/bin/tdztunnel-bandwidth.sh"
BANDWIDTH_SERVICE="/etc/systemd/system/tdztunnel-bandwidth.service"
LEGACY_BANDWIDTH_DIR="/usr/local/bin/tdztunnel-bandwidth"
TRIAL_CLEANUP_SCRIPT="/usr/local/bin/tdztunnel-trial-cleanup.sh"
LOGIN_INFO_SCRIPT="/usr/local/bin/tdztunnel-login-info.sh"
SSHD_TDZ_CONFIG="/etc/ssh/sshd_config.d/tdztunnel.conf"
AUTO_BACKUP_CONF="/etc/tdztunnel-auto-backup-bot.conf"
AUTO_BACKUP_SCRIPT="/usr/local/bin/tdztunnel-auto-backup-bot.sh"
AUTO_BACKUP_DIR="/root/tdztunnel-auto-backups"
AUTO_BACKUP_LOG="/var/log/tdztunnel-auto-backup.log"
AUTO_BACKUP_LAST_FILE="$AUTO_BACKUP_DIR/last-backup.tar.gz"
AUTO_BACKUP_PM2_NAME="tdz-auto-backup-bot"
XUI_PATCHED_TAG="v2.9.3-patched"
XUI_PATCHED_LABEL="v2.9.3 • Patched"
XUI_INSTALLER_COMMIT="89fb75da778db776e6ec0a7f735c2a55626229aa"
XUI_INSTALLER_SHA256="e3ae8c4d42e3f249ea5cad47d9d6b0e98daa675829daab57ffa214efce118186"

tdz_is_valid_port_number() {
    local port="$1"
    [[ "$port" =~ ^[0-9]+$ ]] && (( port >= 1 && port <= 65535 ))
}

tdz_is_reserved_edge_port() {
    local port="$1"
    case "$port" in
        22|"$NGINX_INTERNAL_HTTP_PORT"|"$NGINX_INTERNAL_TLS_PORT"|"$HAPROXY_INTERNAL_DECRYPT_PORT"|"$WS_SSH_BRIDGE_PORT") return 0 ;;
        *) return 1 ;;
    esac
}

load_edge_port_settings() {
    local saved_http="" saved_tls=""

    [[ -r "$EDGE_PORT_SETTINGS_FILE" ]] || return 0
    saved_http=$(awk -F= '$1 == "EDGE_PUBLIC_HTTP_PORT" {print $2}' "$EDGE_PORT_SETTINGS_FILE" 2>/dev/null | tail -n 1 | tr -d '\r')
    saved_tls=$(awk -F= '$1 == "EDGE_PUBLIC_TLS_PORT" {print $2}' "$EDGE_PORT_SETTINGS_FILE" 2>/dev/null | tail -n 1 | tr -d '\r')

    if tdz_is_valid_port_number "$saved_http" &&
       tdz_is_valid_port_number "$saved_tls" &&
       ! tdz_is_reserved_edge_port "$saved_http" &&
       ! tdz_is_reserved_edge_port "$saved_tls" &&
       [[ "$saved_http" != "$saved_tls" ]]; then
        EDGE_PUBLIC_HTTP_PORT="$saved_http"
        EDGE_PUBLIC_TLS_PORT="$saved_tls"
    fi
}

save_edge_port_settings() {
    local tmp_file
    mkdir -p "$DB_DIR" || return 1
    tmp_file="${EDGE_PORT_SETTINGS_FILE}.tmp"
    printf 'EDGE_PUBLIC_HTTP_PORT=%s\nEDGE_PUBLIC_TLS_PORT=%s\n' \
        "$EDGE_PUBLIC_HTTP_PORT" "$EDGE_PUBLIC_TLS_PORT" > "$tmp_file" || return 1
    chmod 600 "$tmp_file"
    mv -f "$tmp_file" "$EDGE_PORT_SETTINGS_FILE"
}

load_edge_port_settings

# --- ZiVPN Variables ---
ZIVPN_DIR="/etc/zivpn"
ZIVPN_BIN="/usr/local/bin/zivpn"
ZIVPN_SERVICE_FILE="/etc/systemd/system/zivpn.service"
ZIVPN_CONFIG_FILE="$ZIVPN_DIR/config.json"
ZIVPN_CERT_FILE="$ZIVPN_DIR/zivpn.crt"
ZIVPN_KEY_FILE="$ZIVPN_DIR/zivpn.key"

SELECTED_USER=""
UNINSTALL_MODE="interactive"
BANNER_CACHE_TTL=15
BANNER_CACHE_TS=0
BANNER_CACHE_OS_NAME=""
BANNER_CACHE_UP_TIME=""
BANNER_CACHE_RAM_USAGE=""
BANNER_CACHE_CPU_LOAD=""
BANNER_CACHE_ONLINE_USERS=0
BANNER_CACHE_TOTAL_USERS=0
# Dashboard info cache (location, ISP, IP, domain, uptime, cpu, ram)
DASH_CACHE_TTL=300          # 5 min — geo/IP lookup is rate-limited
DASH_CACHE_TS=0
DASH_CACHE_LOCATION="Unknown"
DASH_CACHE_ISP="Unknown"
DASH_CACHE_PUBLIC_IP="N/A"
DASH_CACHE_DOMAIN="None"
DASH_CACHE_OS_NAME="Linux"
DASH_CACHE_UPTIME="unknown"
DASH_CACHE_CPU_LOAD="0.00"
DASH_CACHE_CPU_CORES=1
DASH_CPU_PREV_IDLE=0
DASH_CPU_PREV_TOTAL=0
DASH_CACHE_RAM_PCT="0"
DASH_CACHE_RAM_USED="0M / 0M"
DASH_CACHE_DISK_PCT="0"
DASH_CACHE_TOTAL_USERS=0
DASH_CACHE_ONLINE_USERS=0
SSH_SESSION_CACHE_TTL=10
SSH_SESSION_CACHE_TS=0

# CPU percentage — uses vmstat with /proc/stat fallback.
# vmstat 1 2 samples twice with 1s delay; second sample is real-time %idle.
# If vmstat is unavailable, falls back to /proc/stat jiffy delta.
# Always returns integer 0..100.
compute_cpu_pct() {
    local idle pct line1 line2 cpu user nice system iowait irq softirq steal
    local total1 idle1 total2 idle2 diff_total diff_idle

    # Primary: vmstat (most reliable, one-shot real-time measurement)
    if command -v vmstat >/dev/null 2>&1; then
        idle=$(vmstat 1 2 2>/dev/null | tail -n1 | awk '{print $15}')
        if [[ "$idle" =~ ^[0-9]+$ ]]; then
            pct=$((100 - idle))
            (( pct < 0 )) && pct=0
            (( pct > 100 )) && pct=100
            echo "$pct"
            return
        fi
    fi

    # Fallback: /proc/stat jiffy delta (250ms sampling window)
    line1=$(head -n1 /proc/stat 2>/dev/null)
    [[ -z "$line1" ]] && { echo 0; return; }
    read -r cpu user nice system idle iowait irq softirq steal _rest <<< "$line1"
    user=${user:-0}; nice=${nice:-0}; system=${system:-0}; idle=${idle:-0}
    iowait=${iowait:-0}; irq=${irq:-0}; softirq=${softirq:-0}; steal=${steal:-0}
    idle1=$(( idle + iowait ))
    total1=$(( idle + iowait + user + nice + system + irq + softirq + steal ))

    sleep 0.25

    line2=$(head -n1 /proc/stat 2>/dev/null)
    [[ -z "$line2" ]] && { echo 0; return; }
    read -r cpu user nice system idle iowait irq softirq steal _rest <<< "$line2"
    user=${user:-0}; nice=${nice:-0}; system=${system:-0}; idle=${idle:-0}
    iowait=${iowait:-0}; irq=${irq:-0}; softirq=${softirq:-0}; steal=${steal:-0}
    idle2=$(( idle + iowait ))
    total2=$(( idle + iowait + user + nice + system + irq + softirq + steal ))

    diff_total=$(( total2 - total1 ))
    diff_idle=$(( idle2 - idle1 ))
    if (( diff_total <= 0 )); then
        echo 0
        return
    fi
    pct=$(( (diff_total - diff_idle) * 100 / diff_total ))
    (( pct < 0 )) && pct=0
    (( pct > 100 )) && pct=100
    echo "$pct"
}

# ── TDZ Dashboard Box-Layout Helpers (64-column interior) ──────────────────
TDZ_BOX_WIDTH=64

_tdz_strip_ansi() {
    printf '%s' "$1" | sed 's/\x1B\[[0-9;]*[a-zA-Z]//g'
}

# Visible character width (ANSI stripped, character count not byte count)
_tdz_w() {
    local s
    s=$(_tdz_strip_ansi "$1")
    printf '%s' "$s" | wc -m | tr -d ' '
}

# Keep every box row inside its fixed width. ANSI colors are preserved while
# the text fits; overlong text is safely shortened to plain text.
_tdz_fit() {
    local text="$1" max_width="$2"
    local width plain keep
    width=$(_tdz_w "$text")
    if (( width <= max_width )); then
        printf '%s' "$text"
        return
    fi
    plain=$(_tdz_strip_ansi "$text")
    if (( max_width <= 3 )); then
        printf '%s' "${plain:0:max_width}"
        return
    fi
    keep=$((max_width - 3))
    printf '%s...' "${plain:0:keep}"
}

tdz_box_top() {
    local color="${1:-$C_TITLE}"
    printf "  %s┌" "$color"
    printf '─%.0s' $(seq 1 $TDZ_BOX_WIDTH)
    printf "┐%s\n" "$C_RESET"
}

tdz_box_bot() {
    local color="${1:-$C_TITLE}"
    printf "  %s└" "$color"
    printf '─%.0s' $(seq 1 $TDZ_BOX_WIDTH)
    printf "┘%s\n" "$C_RESET"
}

tdz_box_divider() {
    local color="${1:-$C_TITLE}"
    printf "  %s├" "$color"
    printf '─%.0s' $(seq 1 $TDZ_BOX_WIDTH)
    printf "┤%s\n" "$C_RESET"
}

# Section header row: │ ▶ TITLE (padded) │
tdz_box_header() {
    local text="$1"
    local color="${2:-$C_TITLE}"
    local tcolor="$C_GREEN"
    [[ "$color" == "$C_DANGER" ]] && tcolor="$C_RED"
    text=$(_tdz_fit "$text" $((TDZ_BOX_WIDTH - 4)))
    local content=" ${C_BOLD}${tcolor}▶ ${text}${C_RESET} "
    local w
    w=$(_tdz_w "$content")
    local pad=$(( TDZ_BOX_WIDTH - w ))
    [[ $pad -lt 0 ]] && pad=0
    local padstr=""
    [[ $pad -gt 0 ]] && printf -v padstr "%${pad}s" ""
    printf "  %s│%s%s%s%s│%s\n" "$color" "$content" "$padstr" "$color" "" "$C_RESET"
}

# Single content row: │ content (padded) │
tdz_row() {
    local text="$1"
    local color="${2:-$C_TITLE}"
    text=$(_tdz_fit "$text" $((TDZ_BOX_WIDTH - 2)))
    local content=" $text "
    local w
    w=$(_tdz_w "$content")
    local pad=$(( TDZ_BOX_WIDTH - w ))
    [[ $pad -lt 0 ]] && pad=0
    local padstr=""
    [[ $pad -gt 0 ]] && printf -v padstr "%${pad}s" ""
    printf "  %s│%s%s%s%s│%s\n" "$color" "$content" "$padstr" "$color" "" "$C_RESET"
}

# Two-column row: │ left (pad) │ right (pad) │
tdz_row2() {
    local left="$1" right="$2"
    local color="${3:-$C_TITLE}"
    local half=$(( (TDZ_BOX_WIDTH - 1) / 2 ))
    left=$(_tdz_fit "$left" $((half - 1)))
    right=$(_tdz_fit "$right" $((half - 1)))
    local lw rw
    lw=$(_tdz_w "$left")
    rw=$(_tdz_w "$right")
    local lpad=$(( half - lw - 1 ))
    [[ $lpad -lt 0 ]] && lpad=0
    local rpad=$(( half - rw - 1 ))
    [[ $rpad -lt 0 ]] && rpad=0
    local lpadstr="" rpadstr=""
    [[ $lpad -gt 0 ]] && printf -v lpadstr "%${lpad}s" ""
    [[ $rpad -gt 0 ]] && printf -v rpadstr "%${rpad}s" ""
    printf "  %s│%s %s%s%s│%s %s%s %s│%s\n" \
        "$color" "$C_RESET" "$left" "$lpadstr" "$color" \
        "$C_RESET" "$right" "$rpadstr" "$color" "$C_RESET"
}

# Two-column label/value pairs: │ LABEL value (pad) │ LABEL value (pad) │
tdz_kv2() {
    local l_label="$1" l_val="$2" r_label="$3" r_val="$4"
    local color="${5:-$C_TITLE}"
    local left="${C_GRAY}${l_label}${C_RESET} ${C_WHITE}${l_val}${C_RESET}"
    local right="${C_GRAY}${r_label}${C_RESET} ${C_WHITE}${r_val}${C_RESET}"
    tdz_row2 "$left" "$right" "$color"
}

# Two-column menu row: │ [N] Text (pad) │ [N] Text (pad) │
tdz_menu2() {
    local l_num="$1" l_text="$2" r_num="$3" r_text="$4"
    local color="${5:-$C_TITLE}"
    local left="${C_CHOICE}${l_num}${C_RESET} ${C_WHITE}${l_text}${C_RESET}"
    local right="${C_CHOICE}${r_num}${C_RESET} ${C_WHITE}${r_text}${C_RESET}"
    tdz_row2 "$left" "$right" "$color"
}

# Visual progress bar: 10 segments, filled by pct.
# Usage: tdz_bar <0-100> [color]
tdz_bar() {
    local pct="${1:-0}"
    local color="${2:-$C_GREEN}"
    pct=${pct%.*}            # truncate any decimal
    [[ "$pct" -gt 100 ]] && pct=100
    [[ "$pct" -lt 0 ]] && pct=0
    local filled=$(( pct / 10 ))
    local empty=$(( 10 - filled ))
    local bar=""
    local i
    for ((i=0; i<filled; i++)); do bar+="█"; done
    for ((i=0; i<empty; i++)); do bar+="░"; done
    printf "%s%s%s" "$color" "$bar" "$C_RESET"
}

# Two-column key/value with progress bar:
# │ LABEL  [bar] pct% (extra)  │ LABEL  [bar] pct% (extra) │
tdz_kv_bar() {
    local l_label="$1" l_pct="$2" l_extra="$3"
    local r_label="$4" r_pct="$5" r_extra="$6"
    local l_bar_color="$C_GREEN"
    (( l_pct >= 70 )) && l_bar_color="$C_YELLOW"
    (( l_pct >= 90 )) && l_bar_color="$C_RED"
    local r_bar_color="$C_GREEN"
    (( r_pct >= 70 )) && r_bar_color="$C_YELLOW"
    (( r_pct >= 90 )) && r_bar_color="$C_RED"
    local l_padded l_extra_disp
    printf -v l_padded "%-9s" "$l_label"
    l_extra_disp="${l_extra:+ ${C_GRAY}${l_extra}${C_RESET}}"
    local r_padded r_extra_disp
    printf -v r_padded "%-9s" "$r_label"
    r_extra_disp="${r_extra:+ ${C_GRAY}${r_extra}${C_RESET}}"
    local left="${C_GRAY}${l_padded}${C_RESET}$(tdz_bar "$l_pct" "$l_bar_color") ${C_WHITE}${l_pct}%${C_RESET}${l_extra_disp}"
    local right="${C_GRAY}${r_padded}${C_RESET}$(tdz_bar "$r_pct" "$r_bar_color") ${C_WHITE}${r_pct}%${C_RESET}${r_extra_disp}"
    tdz_row2 "$left" "$right"
}

# Single-column menu row: │ [N] Text (pad) │
tdz_menu1() {
    local num="$1" text="$2"
    local color="${3:-$C_TITLE}"
    local content="${C_CHOICE}${num}${C_RESET} ${C_WHITE}${text}${C_RESET}"
    tdz_row "$content" "$color"
}

# Menu option with a compact, aligned status column.
tdz_menu_status() {
    local num="$1" text="$2" status="$3"
    local status_color="${4:-$C_GREEN}"
    local color="${5:-$C_TITLE}"
    local left="${C_CHOICE}${num}${C_RESET} ${C_WHITE}${text}${C_RESET}"
    local right="${status_color}${C_BOLD}${status}${C_RESET}"
    local available=$((TDZ_BOX_WIDTH - 2))
    local right_width left_width gap gap_text=""
    right=$(_tdz_fit "$right" 18)
    right_width=$(_tdz_w "$right")
    left=$(_tdz_fit "$left" $((available - right_width - 1)))
    left_width=$(_tdz_w "$left")
    gap=$((available - left_width - right_width))
    (( gap < 1 )) && gap=1
    printf -v gap_text "%${gap}s" ""
    tdz_row "${left}${gap_text}${right}" "$color"
}

# Compact title card for forms and action screens. Detailed/copyable content
# stays outside the box so long values remain easy to read and select.
tdz_screen_title() {
    local title="$1" description="${2:-}" border_color="${3:-$C_TITLE}"
    echo
    tdz_box_top "$border_color"
    tdz_box_header "$title" "$border_color"
    if [[ -n "$description" ]]; then
        tdz_box_divider "$border_color"
        tdz_row "${C_GRAY}${description}${C_RESET}" "$border_color"
    fi
    tdz_box_bot "$border_color"
    echo
}

# Open section heading for reports and copyable connection details.
tdz_section() {
    local title="$1" content width pad pad_text=""
    title=$(_tdz_fit "$title" $((TDZ_BOX_WIDTH - 4)))
    content="── ${title} "
    width=$(_tdz_w "$content")
    pad=$((TDZ_BOX_WIDTH - width))
    (( pad < 0 )) && pad=0
    (( pad > 0 )) && printf -v pad_text "%${pad}s" ""
    pad_text=${pad_text// /─}
    printf "  %s%s%s%s\n" "$C_TITLE" "$content" "$pad_text" "$C_RESET"
}

tdz_detail() {
    local label="$1" value="$2" value_color="${3:-$C_WHITE}"
    printf "  %s• %-19s%s %s%s%s\n" \
        "$C_GRAY" "${label}:" "$C_RESET" "$value_color" "$value" "$C_RESET"
}

tdz_message() {
    local kind="${1^^}" message="$2" color label
    case "$kind" in
        OK|SUCCESS) color="$C_GREEN"; label="OK" ;;
        WARNING|WARN) color="$C_YELLOW"; label="WARNING" ;;
        INFO) color="$C_BLUE"; label="INFO" ;;
        CANCELLED|CANCELED) color="$C_YELLOW"; label="CANCELLED" ;;
        *) color="$C_RED"; label="ERROR" ;;
    esac
    printf "\n  %s[%s]%s %s\n" "$color" "$label" "$C_RESET" "$message"
}

# Bandwidth values are stored as bytes for usage and GB for account limits.
# Keep every screen consistent and promote values to TB at 1024GB.
tdz_quota_is_unlimited() {
    local quota_gb="${1:-0}"
    [[ "$quota_gb" =~ ^[0-9]+\.?[0-9]*$ ]] || return 0
    awk -v value="$quota_gb" 'BEGIN { exit !(value == 0) }'
}

tdz_format_used_bytes() {
    local bytes="${1:-0}" unit="GB" divisor=1073741824 value
    [[ "$bytes" =~ ^[0-9]+$ ]] || bytes=0

    if (( bytes >= 1099511627776 )); then
        unit="TB"
        divisor=1099511627776
    fi

    value=$(awk -v bytes="$bytes" -v divisor="$divisor" \
        'BEGIN { printf "%.2f", bytes / divisor }')
    if [[ "$value" != "0.00" ]]; then
        value=${value%.00}
    fi
    printf '%s%s' "$value" "$unit"
}

tdz_format_quota_gb() {
    local quota_gb="${1:-0}" unit="GB" divisor=1 value
    if tdz_quota_is_unlimited "$quota_gb"; then
        printf 'Unlimited'
        return
    fi

    if awk -v value="$quota_gb" 'BEGIN { exit !(value >= 1024) }'; then
        unit="TB"
        divisor=1024
    fi

    value=$(awk -v quota="$quota_gb" -v divisor="$divisor" \
        'BEGIN { printf "%.2f", quota / divisor }')
    while [[ "$value" == *.* && "$value" == *0 ]]; do value=${value%0}; done
    value=${value%.}
    printf '%s%s' "$value" "$unit"
}

tdz_format_bandwidth_usage() {
    local used_display quota_display
    used_display=$(tdz_format_used_bytes "${1:-0}")
    quota_display=$(tdz_format_quota_gb "${2:-0}")

    # When both values share a unit, show it once at the end:
    # 0.21/1GB or 1.13/11TB. Mixed units stay explicit:
    # 35.91GB/11TB. Unlimited also keeps the used unit.
    case "${used_display}:${quota_display}" in
        *GB:*GB) used_display=${used_display%GB} ;;
        *TB:*TB) used_display=${used_display%TB} ;;
    esac
    printf '%s/%s' "$used_display" "$quota_display"
}

SSH_SESSION_CACHE_DB_MTIME=0
SSH_SESSION_TOTAL=0
APT_CACHE_READY=0
TDZ_USERS_GROUP="tdzusers"
declare -A SSH_SESSION_COUNTS=()
declare -A SSH_SESSION_PIDS=()

if [[ $EUID -ne 0 ]]; then
   echo -e "${C_RED}[ERROR] This script requires root privileges to run.${C_RESET}"
   exit 1
fi

get_ubuntu_codename() {
    local codename=""

    if [[ -r /etc/os-release ]]; then
        codename=$(awk -F= '/^(VERSION_CODENAME|UBUNTU_CODENAME)=/{gsub(/"/, "", $2); if ($2 != "") { print $2; exit }}' /etc/os-release 2>/dev/null)
    fi

    if [[ -z "$codename" ]] && command -v lsb_release &>/dev/null; then
        codename=$(lsb_release -sc 2>/dev/null)
    fi

    echo "$codename"
}

is_known_eol_ubuntu_codename() {
    case "$1" in
        yakkety|zesty|artful|cosmic|disco|eoan|groovy|hirsute|impish|kinetic|lunar|mantic|oracular|plucky)
            return 0
            ;;
        *)
            return 1
            ;;
    esac
}

rewrite_ubuntu_apt_sources() {
    local mode="$1"
    local os_id=""
    local changed=false
    local file backup_file
    local from_archive to_archive from_security to_security from_ports to_ports
    local -a source_files=("/etc/apt/sources.list" /etc/apt/sources.list.d/*.list /etc/apt/sources.list.d/*.sources)

    if [[ -r /etc/os-release ]]; then
        os_id=$(awk -F= '/^ID=/{gsub(/"/, "", $2); print $2; exit}' /etc/os-release 2>/dev/null)
    fi
    [[ "$os_id" == "ubuntu" ]] || return 1

    case "$mode" in
        primary)
            from_archive='https?://([A-Za-z0-9-]+\.)?archive\.ubuntu\.com/ubuntu'
            to_archive='http://archive.ubuntu.com/ubuntu'
            from_security='https?://security\.ubuntu\.com/ubuntu'
            to_security='http://security.ubuntu.com/ubuntu'
            from_ports='https?://ports\.ubuntu\.com/ubuntu-ports'
            to_ports='http://ports.ubuntu.com/ubuntu-ports'
            ;;
        old-releases)
            from_archive='https?://([A-Za-z0-9-]+\.)?archive\.ubuntu\.com/ubuntu'
            to_archive='http://old-releases.ubuntu.com/ubuntu'
            from_security='https?://security\.ubuntu\.com/ubuntu'
            to_security='http://old-releases.ubuntu.com/ubuntu'
            from_ports='https?://ports\.ubuntu\.com/ubuntu-ports'
            to_ports='http://old-releases.ubuntu.com/ubuntu'
            ;;
        *)
            return 1
            ;;
    esac

    for file in "${source_files[@]}"; do
        [[ -f "$file" ]] || continue
        if grep -Eq "$from_archive|$from_security|$from_ports" "$file" 2>/dev/null; then
            backup_file="${file}.bak.tdztunnel"
            [[ -f "$backup_file" ]] || cp "$file" "$backup_file" 2>/dev/null || true
            sed -i -E \
                -e "s|$from_archive|$to_archive|g" \
                -e "s|$from_security|$to_security|g" \
                -e "s|$from_ports|$to_ports|g" \
                "$file" 2>/dev/null
            changed=true
        fi
    done

    $changed
}

repair_ubuntu_apt_mirrors() {
    rewrite_ubuntu_apt_sources "primary"
}

switch_ubuntu_to_old_releases() {
    local codename
    codename=$(get_ubuntu_codename)
    [[ -n "$codename" ]] || return 1
    is_known_eol_ubuntu_codename "$codename" || return 1
    rewrite_ubuntu_apt_sources "old-releases"
}

# Repair broken Debian sources.list (e.g. when VPS migrated from Tencent Cloud
# where /etc/apt/sources.list still points to mirrors.tencentyun.com).
# Replaces any unreachable mirror with deb.debian.org. Also fixes /tmp perms
# (Tencent Cloud images often ship with /tmp = 700, which breaks apt-key).
repair_debian_apt_mirrors() {
    # Fix /tmp permissions first — apt-key needs 1777 to write temp config
    if [[ -d /tmp ]]; then
        local tmp_mode
        tmp_mode=$(stat -c '%a' /tmp 2>/dev/null || echo "")
        if [[ "$tmp_mode" != "1777" ]]; then
            echo -e "${C_YELLOW}[WARNING] /tmp permissions are $tmp_mode (should be 1777). Fixing...${C_RESET}"
            chmod 1777 /tmp 2>/dev/null
            chown root:root /tmp 2>/dev/null
        fi
        # Also ensure apt partial dir is writable by _apt user
        if [[ -d /var/cache/apt/archives/partial ]]; then
            chmod 755 /var/cache/apt/archives/partial 2>/dev/null
            chown _apt:root /var/cache/apt/archives/partial 2>/dev/null
        fi
    fi

    # Detect Debian
    if [[ ! -f /etc/debian_version ]]; then
        return 1
    fi

    local src="/etc/apt/sources.list"
    [[ -f "$src" ]] || return 1

    # Check if any broken mirror is referenced (Tencent, Aliyun, Huawei, etc.)
    local has_broken=0
    if grep -qE 'mirrors\.(tencentyun|aliyun|myhuaweicloud|cloud\.tencentova)\.com' "$src" 2>/dev/null; then
        has_broken=1
    fi

    # Also check if DNS fails for the configured mirror host
    if [[ $has_broken -eq 0 ]]; then
        local first_mirror
        first_mirror=$(grep -E '^deb ' "$src" 2>/dev/null | head -1 | awk '{print $2}' | sed -E 's|^(https?://)([^/]+)/.*|\2|')
        if [[ -n "$first_mirror" ]] && ! getent hosts "$first_mirror" >/dev/null 2>&1; then
            has_broken=1
        fi
    fi

    [[ $has_broken -eq 1 ]] || return 1

    local codename
    codename=$(sed -n 's/VERSION_CODENAME=//p' /etc/os-release 2>/dev/null | head -1)
    [[ -n "$codename" ]] || codename="bookworm"

    echo -e "${C_YELLOW}[WARNING] Debian apt sources reference an unreachable mirror. Switching to deb.debian.org ($codename)...${C_RESET}"

    # Backup
    cp "$src" "${src}.tdz-backup-$(date +%s)" 2>/dev/null

    cat > "$src" <<EOF
# TDZ TUNNEL — replaced broken mirror with public Debian mirror
deb http://deb.debian.org/debian ${codename} main contrib non-free non-free-firmware
deb http://deb.debian.org/debian ${codename}-updates main contrib non-free non-free-firmware
deb http://deb.debian.org/debian-security ${codename}-security main contrib non-free non-free-firmware
EOF

    return 0
}

tdz_apt_update() {
    local -a apt_opts=(
        -o Acquire::Retries=3
        -o Acquire::ForceIPv4=true
        -o Acquire::http::Timeout=20
        -o Acquire::https::Timeout=20
        -o Acquire::http::Pipeline-Depth=0
    )

    if (( APT_CACHE_READY == 1 )); then
        return 0
    fi

    if DEBIAN_FRONTEND=noninteractive apt-get "${apt_opts[@]}" update; then
        APT_CACHE_READY=1
        return 0
    fi

    if repair_debian_apt_mirrors; then
        echo -e "${C_YELLOW}[WARNING] Debian mirror unreachable. Switching to deb.debian.org and retrying...${C_RESET}"
        apt-get clean >/dev/null 2>&1 || true
        if DEBIAN_FRONTEND=noninteractive apt-get "${apt_opts[@]}" update; then
            APT_CACHE_READY=1
            return 0
        fi
    fi

    if repair_ubuntu_apt_mirrors; then
        echo -e "${C_YELLOW}[WARNING] APT mirror timed out. Switching Ubuntu sources to archive.ubuntu.com and retrying...${C_RESET}"
        apt-get clean >/dev/null 2>&1 || true
        if DEBIAN_FRONTEND=noninteractive apt-get "${apt_opts[@]}" update; then
            APT_CACHE_READY=1
            return 0
        fi
    fi

    if switch_ubuntu_to_old_releases; then
        echo -e "${C_YELLOW}[WARNING] Detected an end-of-life Ubuntu release. Switching APT sources to old-releases.ubuntu.com and retrying...${C_RESET}"
        apt-get clean >/dev/null 2>&1 || true
        if DEBIAN_FRONTEND=noninteractive apt-get "${apt_opts[@]}" update; then
            APT_CACHE_READY=1
            return 0
        fi
    fi

    echo -e "${C_RED}[ERROR] Failed to refresh package lists. Please check VPS network, DNS, or blocked Ubuntu mirrors.${C_RESET}"
    return 1
}

tdz_apt_install() {
    local -a packages=("$@")
    (( ${#packages[@]} > 0 )) || return 0

    tdz_apt_update || return 1
    DEBIAN_FRONTEND=noninteractive apt-get -y -o Dpkg::Use-Pty=0 install "${packages[@]}"
}

tdz_apt_purge() {
    local -a packages=("$@")
    (( ${#packages[@]} > 0 )) || return 0
    DEBIAN_FRONTEND=noninteractive apt-get -y -o Dpkg::Use-Pty=0 purge "${packages[@]}"
}

# Mandatory Dependency Check (Added jq and curl)
check_environment() {
    local missing_packages=()
    local cmd

    for cmd in bc jq curl wget; do
        if ! command -v "$cmd" &> /dev/null; then
            missing_packages+=("$cmd")
        fi
    done

    if (( ${#missing_packages[@]} > 0 )); then
        echo -e "${C_YELLOW}[WARNING] Installing missing dependencies: ${missing_packages[*]}${C_RESET}"
        tdz_apt_install "${missing_packages[@]}" >/dev/null 2>&1 || {
            echo -e "${C_RED}[ERROR] Failed to install required dependencies: ${missing_packages[*]}.${C_RESET}"
            exit 1
        }
    fi
}

ensure_tdztunnel_dirs() {
    mkdir -p "$DB_DIR" "$SSL_CERT_DIR" "$BANDWIDTH_DIR" /etc/ssh/sshd_config.d
    touch "$DB_FILE"
}

# Hardened sshd settings that complement the WS-bridge keepalive options.
# Without ClientAliveInterval, sshd never probes idle sessions and depends
# entirely on TCP keepalive (which we now enable on the bridge). Adding
# these gives sshd its own way to detect dead peers and reap them.
# UseDNS=no also speeds up login (no reverse DNS lookup) which helps with
# the "first connection feels slow" symptom on mobile networks.
harden_sshd_for_tunnel_stability() {
    local conf="/etc/ssh/sshd_config.d/tdztunnel-stability.conf"
    local need_reload=false
    local base_backup="/etc/ssh/sshd_config.tdz-ipv4-backup"

    mkdir -p /etc/ssh/sshd_config.d

    if [[ ! -f "$base_backup" ]]; then
        cp /etc/ssh/sshd_config "$base_backup" 2>/dev/null || true
    fi

    if grep -Eq '^[[:space:]]*(AddressFamily[[:space:]]+any|ListenAddress[[:space:]]+::)[[:space:]]*$' /etc/ssh/sshd_config 2>/dev/null; then
        sed -i \
            -e 's/^[[:space:]]*AddressFamily[[:space:]]\+any[[:space:]]*$/# TDZ disabled: AddressFamily any/' \
            -e 's/^[[:space:]]*ListenAddress[[:space:]]\+::[[:space:]]*$/# TDZ disabled: ListenAddress ::/' \
            /etc/ssh/sshd_config
        need_reload=true
    fi

    # Ensure main sshd_config includes the drop-in directory
    if ! grep -qE "^[[:space:]]*Include[[:space:]]+/etc/ssh/sshd_config.d/\*\.conf" /etc/ssh/sshd_config 2>/dev/null; then
        echo "Include /etc/ssh/sshd_config.d/*.conf" >> /etc/ssh/sshd_config
        need_reload=true
    fi

    local new_conf="# TDZ SSH TUNNEL - stability hardening (do not edit, managed by menu)\n"
    new_conf+="# Keep SSH reachable on IPv4-only VPS/client networks after reboot\n"
    new_conf+="Port 22\n"
    new_conf+="# Custom SSH protocol version suffix\n"
    new_conf+="DebianBanner no\n"
    new_conf+="VersionAddendum By: @TuhinBroh\n"
    new_conf+="AddressFamily inet\n"
    new_conf+="ListenAddress 0.0.0.0\n"
    new_conf+="PermitRootLogin yes\n"
    new_conf+="PasswordAuthentication yes\n"
    new_conf+="KbdInteractiveAuthentication yes\n"
    new_conf+="ChallengeResponseAuthentication yes\n"
    new_conf+="UsePAM yes\n"
    new_conf+="# Aggressive ClientAlive probes — server-side keepalive for SSH sessions\n"
    new_conf+="ClientAliveInterval 30\n"
    new_conf+="ClientAliveCountMax 3\n"
    new_conf+="# Skip slow reverse DNS lookup on login — speeds up mobile handshakes\n"
    new_conf+="UseDNS no\n"
    new_conf+="# Don't kick users off during slow auth on mobile networks\n"
    new_conf+="LoginGraceTime 60\n"
    new_conf+="# Allow enough unauthenticated connection slots for bursty reconnects\n"
    new_conf+="MaxStartups 30:30:100\n"
    new_conf+="TCPKeepAlive yes\n"
    new_conf+="PermitTunnel yes\n"
    new_conf+="AllowTcpForwarding yes\n"
    new_conf+="GatewayPorts yes\n"

    local current_conf
    current_conf=$(printf '%b' "$new_conf")
    if [[ ! -f "$conf" ]] || ! cmp -s <(printf '%b' "$new_conf") "$conf" 2>/dev/null; then
        printf '%b' "$new_conf" > "$conf"
        need_reload=true
    fi

    if $need_reload; then
        # Validate before reload so a bad config doesn't lock us out
        if sshd -t 2>/dev/null; then
            systemctl reload sshd 2>/dev/null || systemctl reload ssh 2>/dev/null || true
        else
            echo -e "${C_YELLOW}[WARNING] sshd config validation failed — keeping old config.${C_RESET}" >&2
            rm -f "$conf"
        fi
    fi
}

ensure_tdztunnel_system_group() {
    getent group "$TDZ_USERS_GROUP" >/dev/null 2>&1 || groupadd "$TDZ_USERS_GROUP" >/dev/null 2>&1 || true
}

db_has_user() {
    [[ -f "$DB_FILE" ]] || return 1
    awk -F: -v target="$1" '$1 == target { found=1; exit } END { exit(found ? 0 : 1) }' "$DB_FILE"
}

db_set_pending_validity() {
    local username="$1" validity_days="$2" tmp_file

    [[ -f "$DB_FILE" && "$validity_days" =~ ^[1-9][0-9]*$ ]] || return 1
    tmp_file=$(mktemp "${DB_FILE}.pending-validity.XXXXXX") || return 1

    if ! awk -F: -v OFS=: -v target="$username" -v days="$validity_days" '
        $1 == target && $6 == "pending" {
            $3 = "Never"
            $7 = days
            updated = 1
        }
        { print }
        END { if (!updated) exit 2 }
    ' "$DB_FILE" > "$tmp_file"; then
        rm -f "$tmp_file"
        return 1
    fi

    chmod --reference="$DB_FILE" "$tmp_file" 2>/dev/null || chmod 600 "$tmp_file"
    chown --reference="$DB_FILE" "$tmp_file" 2>/dev/null || true
    mv -f "$tmp_file" "$DB_FILE"
}

is_tdztunnel_orphan_user() {
    local username="$1"
    local passwd_line system_user _ uid _ home shell

    passwd_line=$(getent passwd "$username" 2>/dev/null) || return 1
    IFS=: read -r system_user _ uid _ _ home shell <<< "$passwd_line"
    [[ "$uid" =~ ^[0-9]+$ ]] || return 1
    db_has_user "$username" && return 1

    if id -nG "$username" 2>/dev/null | tr ' ' '\n' | grep -Fxq "$TDZ_USERS_GROUP"; then
        return 0
    fi

    (( uid >= 1000 )) || return 1
    [[ "$home" == "/home/$username" || "$home" == /home/* ]] || return 1

    case "$shell" in
        /usr/sbin/nologin|/usr/bin/false|/bin/false) return 0 ;;
    esac

    return 1
}

get_tdztunnel_orphan_users() {
    local username
    while IFS=: read -r username _rest; do
        [[ -n "$username" ]] || continue
        if is_tdztunnel_orphan_user "$username"; then
            echo "$username"
        fi
    done < /etc/passwd
}

get_tdztunnel_known_users() {
    local username
    local -A seen_users=()

    if [[ -f "$DB_FILE" ]]; then
        while IFS=: read -r username _rest; do
            [[ -n "$username" && "$username" != \#* ]] || continue
            seen_users["$username"]=1
        done < "$DB_FILE"
    fi

    while IFS= read -r username; do
        [[ -n "$username" ]] && seen_users["$username"]=1
    done < <(get_tdztunnel_orphan_users)

    (( ${#seen_users[@]} > 0 )) || return 0
    printf "%s\n" "${!seen_users[@]}" | sort
}

delete_tdztunnel_user_accounts() {
    local -a users_to_delete=("$@")
    local username

    [[ ${#users_to_delete[@]} -gt 0 ]] || return 0

    for username in "${users_to_delete[@]}"; do
        [[ -n "$username" ]] || continue
        killall -u "$username" -9 &>/dev/null
        if id "$username" &>/dev/null; then
            if userdel -r "$username" &>/dev/null; then
                echo -e " [OK] System user '${C_YELLOW}$username${C_RESET}' deleted."
            else
                echo -e " [ERROR] Failed to delete system user '${C_YELLOW}$username${C_RESET}'."
            fi
        else
            echo -e " [INFO] System user '${C_YELLOW}$username${C_RESET}' was already missing. Removing manager data only."
        fi
        rm -f "$BANDWIDTH_DIR/${username}.usage"
        rm -rf "$BANDWIDTH_DIR/pidtrack/${username}"
    done

    if [[ -f "$DB_FILE" ]]; then
        local db_tmp
        db_tmp=$(mktemp)
        awk -F: 'NR==FNR { drop[$1]=1; next } !($1 in drop)' <(printf "%s\n" "${users_to_delete[@]}") "$DB_FILE" > "$db_tmp" && mv "$db_tmp" "$DB_FILE"
        rm -f "$db_tmp" 2>/dev/null
    fi

    invalidate_banner_cache
    refresh_dynamic_banner_routing_if_enabled
}

require_interactive_terminal() {
    if [[ ! -t 0 || ! -t 1 ]]; then
        echo -e "${C_RED}[ERROR] The TDZ SSH TUNNEL menu must be run from an interactive terminal.${C_RESET}"
        exit 1
    fi
}

initial_setup() {
    echo -e "${C_BLUE}Initializing TDZ SSH TUNNEL setup...${C_RESET}"
    check_environment
    
    ensure_tdztunnel_dirs
    ensure_tdztunnel_system_group
    
    echo -e "${C_BLUE}Hardening sshd for TDZ SSH TUNNEL stability...${C_RESET}"
    harden_sshd_for_tunnel_stability

    echo -e "${C_BLUE}Configuring user limiter service...${C_RESET}"
    setup_limiter_service
    
    echo -e "${C_BLUE}Configuring bandwidth monitoring service...${C_RESET}"
    setup_bandwidth_service
    
    echo -e "${C_BLUE}Installing trial account cleanup script...${C_RESET}"
    setup_trial_cleanup_script
    
    echo -e "${C_BLUE}Cleaning legacy dynamic SSH banner hooks...${C_RESET}"
    disable_dynamic_ssh_banner_system
    systemctl reload sshd 2>/dev/null || systemctl reload ssh 2>/dev/null || true
    
    if [ ! -f "$INSTALL_FLAG_FILE" ]; then
        touch "$INSTALL_FLAG_FILE"
    fi
    echo -e "${C_GREEN}[OK] Setup finished.${C_RESET}"
}

_is_valid_ipv4() {
    local ip=$1
    if [[ $ip =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]]; then
        return 0
    else
        return 1
    fi
}

check_and_open_firewall_port() {
    local port="$1"
    local protocol="${2:-tcp}"
    local firewall_detected=false

    if command -v ufw &> /dev/null && ufw status | grep -q "Status: active"; then
        firewall_detected=true
        if ! ufw status | grep -qw "$port/$protocol"; then
            echo -e "${C_YELLOW}UFW firewall is active and port ${port}/${protocol} is closed.${C_RESET}"
            read -p "  Do you want to open this port now? (y/n): " confirm
            if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
                ufw allow "$port/$protocol"
                echo -e "${C_GREEN}[OK] Port ${port}/${protocol} has been opened in UFW.${C_RESET}"
            else
                echo -e "${C_RED}[WARNING] Port ${port}/${protocol} was not opened. The service may not work correctly.${C_RESET}"
                return 1
            fi
        else
             echo -e "${C_GREEN}[OK] Port ${port}/${protocol} is already open in UFW.${C_RESET}"
        fi
    fi

    if command -v firewall-cmd &> /dev/null && systemctl is-active --quiet firewalld; then
        firewall_detected=true
        if ! firewall-cmd --list-ports --permanent | grep -qw "$port/$protocol"; then
            echo -e "${C_YELLOW}firewalld is active and port ${port}/${protocol} is not open.${C_RESET}"
            read -p "  Do you want to open this port now? (y/n): " confirm
            if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
                firewall-cmd --add-port="$port/$protocol" --permanent
                firewall-cmd --reload
                echo -e "${C_GREEN}[OK] Port ${port}/${protocol} has been opened in firewalld.${C_RESET}"
            else
                echo -e "${C_RED}[WARNING] Port ${port}/${protocol} was not opened. The service may not work correctly.${C_RESET}"
                return 1
            fi
        else
            echo -e "${C_GREEN}[OK] Port ${port}/${protocol} is already open in firewalld.${C_RESET}"
        fi
    fi

    if ! $firewall_detected; then
        echo -e "${C_BLUE}[INFO] No active firewall (UFW or firewalld) detected. Assuming ports are open.${C_RESET}"
    fi
    return 0
}

check_and_open_firewall_port_range() {
    local port_range="$1"
    local protocol="${2:-tcp}"
    local firewall_detected=false

    if command -v ufw &> /dev/null && ufw status | grep -q "Status: active"; then
        firewall_detected=true
        if ! ufw status | grep -Fq "$port_range/$protocol"; then
            echo -e "${C_YELLOW}UFW firewall is active and range ${port_range}/${protocol} is closed.${C_RESET}"
            read -p "  Do you want to open this port range now? (y/n): " confirm
            if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
                ufw allow "$port_range/$protocol"
                echo -e "${C_GREEN}[OK] Range ${port_range}/${protocol} has been opened in UFW.${C_RESET}"
            else
                echo -e "${C_RED}[WARNING] Range ${port_range}/${protocol} was not opened. The service may not work correctly.${C_RESET}"
                return 1
            fi
        else
            echo -e "${C_GREEN}[OK] Range ${port_range}/${protocol} is already open in UFW.${C_RESET}"
        fi
    fi

    if command -v firewall-cmd &> /dev/null && systemctl is-active --quiet firewalld; then
        firewall_detected=true
        if ! firewall-cmd --quiet --query-port="$port_range/$protocol"; then
            echo -e "${C_YELLOW}firewalld is active and range ${port_range}/${protocol} is not open.${C_RESET}"
            read -p "  Do you want to open this port range now? (y/n): " confirm
            if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
                firewall-cmd --add-port="$port_range/$protocol" --permanent
                firewall-cmd --reload
                echo -e "${C_GREEN}[OK] Range ${port_range}/${protocol} has been opened in firewalld.${C_RESET}"
            else
                echo -e "${C_RED}[WARNING] Range ${port_range}/${protocol} was not opened. The service may not work correctly.${C_RESET}"
                return 1
            fi
        else
            echo -e "${C_GREEN}[OK] Range ${port_range}/${protocol} is already open in firewalld.${C_RESET}"
        fi
    fi

    if ! $firewall_detected; then
        echo -e "${C_BLUE}[INFO] No active firewall (UFW or firewalld) detected. Assuming range ${port_range}/${protocol} is open.${C_RESET}"
    fi
    return 0
}

check_and_free_ports() {
    local ports_to_check=("$@")
    for port in "${ports_to_check[@]}"; do
        echo -e "\n${C_BLUE}Checking if port $port is available...${C_RESET}"
        local conflicting_process_info
        conflicting_process_info=$(
            ss -H -lntp "( sport = :$port )" 2>/dev/null
            ss -H -lunp "( sport = :$port )" 2>/dev/null
        )
        
        if [[ -n "$conflicting_process_info" ]]; then
            local conflicting_pid
            conflicting_pid=$(echo "$conflicting_process_info" | grep -oP 'pid=\K[0-9]+' | head -n 1)
            local conflicting_name
            conflicting_name=$(echo "$conflicting_process_info" | grep -oP 'users:\(\("(\K[^"]+)' | head -n 1)
            
            echo -e "${C_YELLOW}[WARNING] Port $port is in use by process '${conflicting_name:-unknown}' (PID: ${conflicting_pid:-N/A}).${C_RESET}"
            read -p "  Do you want to attempt to stop this process? (y/n): " kill_confirm
            if [[ "$kill_confirm" == "y" || "$kill_confirm" == "Y" ]]; then
                if [[ -z "$conflicting_pid" ]]; then
                    echo -e "${C_RED}[ERROR] Could not determine which PID owns port $port. Please free it manually.${C_RESET}"
                    return 1
                fi
                echo -e "${C_GREEN}Stopping process PID $conflicting_pid...${C_RESET}"
                systemctl stop "$(ps -p "$conflicting_pid" -o comm=)" &>/dev/null || kill -9 "$conflicting_pid"
                sleep 2
                
                if ss -H -lntp "( sport = :$port )" 2>/dev/null | grep -q . || ss -H -lunp "( sport = :$port )" 2>/dev/null | grep -q .; then
                     echo -e "${C_RED}[ERROR] Failed to free port $port. Please handle it manually. Aborting.${C_RESET}"
                     return 1
                else
                     echo -e "${C_GREEN}[OK] Port $port has been successfully freed.${C_RESET}"
                fi
            else
                echo -e "${C_RED}[ERROR] Cannot proceed without freeing port $port. Aborting.${C_RESET}"
                return 1
            fi
        else
            echo -e "${C_GREEN}[OK] Port $port is free to use.${C_RESET}"
        fi
    done
    return 0
}

setup_limiter_service() {
    # Combined limiter + bandwidth monitoring
    cat > "$LIMITER_SCRIPT" << 'EOF'
#!/bin/bash
# TDZ SSH TUNNEL limiter version 2026-07-18.1
# Fixed: online detection now uses `who` + per-user process scan, not just `ps -C sshd`.
# This catches users connected via WS-bridge (whose sshd child already exec'd shell).
DB_FILE="/etc/tdztunnel/users.db"
BW_DIR="/etc/tdztunnel/bandwidth"
PID_DIR="$BW_DIR/pidtrack"
BANNER_DIR="/etc/tdztunnel/banners"
BANNER_IDENTITY_CONF="/etc/tdztunnel/banner_identity.conf"
ADMIN_USERNAME="TUSTDZ"
CHANNEL_USERNAME="TuhinBroh"
SCAN_INTERVAL=1

mkdir -p "$BW_DIR" "$PID_DIR"
shopt -s nullglob

write_banner_if_changed() {
    local user="$1"
    local content="$2"
    local banner_file="$BANNER_DIR/${user}.txt"
    local tmp_file="${banner_file}.tmp"

    printf "%s" "$content" > "$tmp_file"
    if ! cmp -s "$tmp_file" "$banner_file" 2>/dev/null; then
        mv "$tmp_file" "$banner_file"
    else
        rm -f "$tmp_file"
    fi
}

load_banner_identity() {
    local key value
    ADMIN_USERNAME="TUSTDZ"
    CHANNEL_USERNAME="TuhinBroh"

    if [[ -r "$BANNER_IDENTITY_CONF" ]]; then
        while IFS='=' read -r key value; do
            value=${value%$'\r'}
            case "$key" in
                ADMIN_USERNAME) ADMIN_USERNAME="$value" ;;
                CHANNEL_USERNAME) CHANNEL_USERNAME="$value" ;;
            esac
        done < "$BANNER_IDENTITY_CONF"
    fi

    [[ "$ADMIN_USERNAME" =~ ^[A-Za-z][A-Za-z0-9_]{4,31}$ ]] || ADMIN_USERNAME="TUSTDZ"
    [[ "$CHANNEL_USERNAME" =~ ^[A-Za-z][A-Za-z0-9_]{4,31}$ ]] || CHANNEL_USERNAME="TuhinBroh"
}

quota_is_unlimited() {
    local quota_gb="${1:-0}"
    [[ "$quota_gb" =~ ^[0-9]+\.?[0-9]*$ ]] || return 0
    awk -v value="$quota_gb" 'BEGIN { exit !(value == 0) }'
}

format_used_bytes() {
    local bytes="${1:-0}" unit="GB" divisor=1073741824 value
    [[ "$bytes" =~ ^[0-9]+$ ]] || bytes=0
    if (( bytes >= 1099511627776 )); then
        unit="TB"
        divisor=1099511627776
    fi
    value=$(awk -v bytes="$bytes" -v divisor="$divisor" \
        'BEGIN { printf "%.2f", bytes / divisor }')
    if [[ "$value" != "0.00" ]]; then
        value=${value%.00}
    fi
    printf '%s%s' "$value" "$unit"
}

format_quota_gb() {
    local quota_gb="${1:-0}" unit="GB" divisor=1 value
    if quota_is_unlimited "$quota_gb"; then
        printf 'Unlimited'
        return
    fi
    if awk -v value="$quota_gb" 'BEGIN { exit !(value >= 1024) }'; then
        unit="TB"
        divisor=1024
    fi
    value=$(awk -v quota="$quota_gb" -v divisor="$divisor" \
        'BEGIN { printf "%.2f", quota / divisor }')
    while [[ "$value" == *.* && "$value" == *0 ]]; do value=${value%0}; done
    value=${value%.}
    printf '%s%s' "$value" "$unit"
}

format_bandwidth_usage() {
    local used_display quota_display
    used_display=$(format_used_bytes "${1:-0}")
    quota_display=$(format_quota_gb "${2:-0}")

    case "${used_display}:${quota_display}" in
        *GB:*GB) used_display=${used_display%GB} ;;
        *TB:*TB) used_display=${used_display%TB} ;;
    esac
    printf '%s/%s' "$used_display" "$quota_display"
}

activate_pending_account() {
    local target_user="$1" duration_days="$2"
    local activated_expiry tmp_file

    [[ "$duration_days" =~ ^[1-9][0-9]*$ ]] || return 1
    activated_expiry=$(date -d "+${duration_days} days" +%Y-%m-%d 2>/dev/null) || return 1
    tmp_file=$(mktemp "${DB_FILE}.activate.XXXXXX") || return 1

    if ! chage -E "$activated_expiry" "$target_user" >/dev/null 2>&1; then
        rm -f "$tmp_file"
        return 1
    fi

    if ! awk -F: -v OFS=: -v target="$target_user" -v new_expiry="$activated_expiry" '
        $1 == target && $6 == "pending" {
            print $1, $2, new_expiry, $4, $5
            updated=1
            next
        }
        { print }
        END { if (!updated) exit 2 }
    ' "$DB_FILE" > "$tmp_file"; then
        chage -E -1 "$target_user" >/dev/null 2>&1 || true
        rm -f "$tmp_file"
        return 1
    fi

    chmod --reference="$DB_FILE" "$tmp_file" 2>/dev/null || chmod 600 "$tmp_file"
    chown --reference="$DB_FILE" "$tmp_file" 2>/dev/null || true
    if ! mv -f "$tmp_file" "$DB_FILE"; then
        chage -E -1 "$target_user" >/dev/null 2>&1 || true
        rm -f "$tmp_file"
        return 1
    fi

    logger -t tdztunnel-limiter "First-use activation: ${target_user} expires ${activated_expiry}"
    printf '%s' "$activated_expiry"
}

load_banner_identity

while true; do
    if [[ ! -s "$DB_FILE" ]]; then
        sleep "$SCAN_INTERVAL"
        continue
    fi

    current_ts=$(date +%s)
    dynamic_banners_enabled=false
    declare -A session_pids=()
    declare -A locked_users=()
    declare -A uid_to_user=()
    declare -A loginuid_pids=()
    declare -A sshd_session_pids=()
    declare -A who_online=()
    declare -A managed_user_lookup=()

    while IFS=: read -r managed_user _rest; do
        [[ -n "$managed_user" && "$managed_user" != \#* ]] && managed_user_lookup["$managed_user"]=1
    done < "$DB_FILE"

    while IFS=: read -r username _ uid _rest; do
        [[ -n "$username" && "$uid" =~ ^[0-9]+$ ]] && uid_to_user["$uid"]="$username"
    done < /etc/passwd

    # METHOD A: `who` — primary detector, catches all logged-in managed users
    # and counts their distinct login sessions.
    while read -r who_line; do
        who_user=$(echo "$who_line" | awk '{print $1}')
        [[ -z "$who_user" ]] && continue
        [[ -n "${managed_user_lookup[$who_user]+x}" ]] || continue
        who_online["$who_user"]=$(( ${who_online["$who_user"]:-0} + 1 ))
    done < <(who 2>/dev/null)

    # METHOD B: ps -C sshd — secondary, catches pre-shell sshd children
    while read -r ssh_pid ssh_owner; do
        [[ "$ssh_pid" =~ ^[0-9]+$ ]] || continue

        if [[ -n "$ssh_owner" && "$ssh_owner" != "root" && "$ssh_owner" != "sshd" && -n "${managed_user_lookup[$ssh_owner]+x}" ]]; then
            session_pids["$ssh_owner"]+="$ssh_pid "
            sshd_session_pids["$ssh_owner"]+="$ssh_pid "
        elif [[ -r "/proc/$ssh_pid/loginuid" ]]; then
            login_uid=""
            read -r login_uid < "/proc/$ssh_pid/loginuid" || login_uid=""
            if [[ "$login_uid" =~ ^[0-9]+$ && "$login_uid" != "4294967295" ]]; then
                candidate_user="${uid_to_user[$login_uid]}"
                if [[ -n "$candidate_user" && -n "${managed_user_lookup[$candidate_user]+x}" ]]; then
                    session_pids["$candidate_user"]+="$ssh_pid "
                    sshd_session_pids["$candidate_user"]+="$ssh_pid "
                fi
            fi
        fi
    done < <(ps -C sshd -o pid=,user= 2>/dev/null)

    # METHOD C: UID-based process scan catches ALL PIDs owned by managed users.
    # (bash, sftp-server, scp, etc.). Critical for bandwidth tracking because
    # the WS-bridge tunnel's sshd child exec's the shell early — `ps -C sshd`
    # misses it. Do not use ps user= here: long usernames are truncated.
    while read -r _uid _pid; do
        [[ "$_uid" =~ ^[0-9]+$ && "$_pid" =~ ^[0-9]+$ ]] || continue
        _u="${uid_to_user[$_uid]:-}"
        [[ -n "$_u" && -n "${managed_user_lookup[$_u]+x}" ]] || continue
        session_pids[$_u]="${session_pids[$_u]}$_pid "
    done < <(ps -eo uid=,pid= --no-headers 2>/dev/null)

    while read -r passwd_user passwd_status _rest; do
        [[ "$passwd_status" == "L" ]] && locked_users["$passwd_user"]=1
    done < <(passwd -Sa 2>/dev/null)

    if [[ -f "/etc/tdztunnel/banners_enabled" ]]; then
        mkdir -p "$BANNER_DIR"
        dynamic_banners_enabled=true
    fi

    while IFS=: read -r user pass expiry limit bandwidth_gb account_type activation_value _extra; do
        [[ -z "$user" || "$user" == \#* ]] && continue

        declare -A unique_pids=()
        pid_candidates="${session_pids[$user]:-}"
        for pid in $pid_candidates; do
            [[ "$pid" =~ ^[0-9]+$ ]] && unique_pids["$pid"]=1
        done

        # Online if `who` shows them OR they have live PIDs
        local_user_online=false
        if [[ -n "${who_online[$user]+x}" || ${#unique_pids[@]} -gt 0 ]]; then
            local_user_online=true
        fi

        declare -A unique_sshd_sessions=()
        for pid in ${sshd_session_pids[$user]:-}; do
            [[ "$pid" =~ ^[0-9]+$ ]] && unique_sshd_sessions["$pid"]=1
        done

        # Connection count: sshd sessions are authoritative for tunnel/no-PTY users.
        online_count=${who_online[$user]:-0}
        if (( ${#unique_sshd_sessions[@]} > online_count )); then
            online_count=${#unique_sshd_sessions[@]}
        fi
        if (( online_count == 0 )) && [[ "$local_user_online" == true ]]; then
            online_count=1
        fi

        pending_activation=false
        if [[ "$account_type" == "pending" ]]; then
            pending_activation=true
            if [[ "$local_user_online" == true && "$activation_value" =~ ^[1-9][0-9]*$ ]]; then
                activated_expiry=$(activate_pending_account "$user" "$activation_value")
                if [[ -n "$activated_expiry" ]]; then
                    expiry="$activated_expiry"
                    account_type=""
                    activation_value=""
                    pending_activation=false
                fi
            fi
        fi

        user_locked=false
        if [[ -n "${locked_users[$user]+x}" ]]; then
            user_locked=true
        fi

        expiry_ts=0
        is_expired=false
        if [[ "$expiry" != "Never" && -n "$expiry" ]]; then
            expiry_ts=$(date -d "$expiry" +%s 2>/dev/null || echo 0)
            if [[ "$expiry_ts" =~ ^[0-9]+$ ]] && (( expiry_ts > 0 && expiry_ts < current_ts )); then
                is_expired=true
            fi
        fi

        # --- Compute bandwidth info for every account, including unlimited ---
        usagefile="$BW_DIR/${user}.usage"
        accum_disp=0
        if [[ -f "$usagefile" ]]; then
            read -r accum_disp < "$usagefile"
            [[ "$accum_disp" =~ ^[0-9]+$ ]] || accum_disp=0
        fi
        bw_display=$(format_bandwidth_usage "$accum_disp" "$bandwidth_gb")
        traffic_exceeded=false
        if ! quota_is_unlimited "$bandwidth_gb"; then
            quota_bytes=$(awk "BEGIN {printf \"%.0f\", $bandwidth_gb * 1073741824}")
            if [[ "$accum_disp" =~ ^[0-9]+$ ]] && (( accum_disp >= quota_bytes )); then
                traffic_exceeded=true
            fi
        fi

        # --- Format expiration date (DD-MM-YYYY) ---
        if $pending_activation; then
            expiry_display="First use +${activation_value}d"
        elif [[ "$expiry" == "Never" || -z "$expiry" ]]; then
            expiry_display="Never"
        else
            expiry_display=$(date -d "$expiry" +%d-%m-%Y 2>/dev/null || echo "$expiry")
        fi

        # --- Generate dynamic banner based on status ---
        if $dynamic_banners_enabled; then
            SEP="---------------------------------"

            if $pending_activation; then
                STATUS_TEXT="Waiting for First Use"
                MSG_BLOCK=""
            elif $is_expired; then
                STATUS_TEXT="Expired"
                MSG_BLOCK="<font color=\"red\">Oops! Your account has expired.<br>Please buy a new account<br>Or contact </font><a href=\"https://t.me/${ADMIN_USERNAME}\">@${ADMIN_USERNAME}</a><font color=\"red\"> to renew<br>your access.</font>"
            elif $traffic_exceeded; then
                STATUS_TEXT="Traffic Ended"
                MSG_BLOCK="<font color=\"red\">Oops! Your data limit has been reached.<br>Please recharge your account<br>Or contact </font><a href=\"https://t.me/${ADMIN_USERNAME}\">@${ADMIN_USERNAME}</a><font color=\"red\"> to top-up<br>your data.</font>"
            elif $user_locked; then
                STATUS_TEXT="Locked"
                MSG_BLOCK="<font color=\"red\">Oops! Your account has been locked.<br>This is maybe billing or abuse issue —<br>please contact </font><a href=\"https://t.me/${ADMIN_USERNAME}\">@${ADMIN_USERNAME}</a><font color=\"red\"> directly<br>to unlock your access.</font>"
            else
                STATUS_TEXT="Active"
                MSG_BLOCK=""
            fi

            banner_content="<br><br>${SEP}<br><b>[!] ACCOUNT • DETAILS [!]</b><br>${SEP}<br>"
            banner_content+="<b>[-] Username:</b> $user<br>"
            banner_content+="<b>[-] Status:</b> ${STATUS_TEXT}<br>"
            banner_content+="<b>[-] Expiration:</b> $expiry_display<br>${SEP}<br>"
            banner_content+="<b>[-] Traffic Usage:</b> $bw_display<br>"
            banner_content+="<b>[-] Active Session:</b> $online_count/$limit<br>"

            if [[ -n "$MSG_BLOCK" ]]; then
                banner_content+="${SEP}<br>${MSG_BLOCK}<br>"
            fi

            banner_content+="${SEP}<br>"
            banner_content+="<b>[-] Admin:</b> <a href=\"https://t.me/${ADMIN_USERNAME}\">@${ADMIN_USERNAME}</a><br>"
            banner_content+="<b>[-] Channel:</b> <a href=\"https://t.me/${CHANNEL_USERNAME}\">@${CHANNEL_USERNAME}</a><br>${SEP}"

            write_banner_if_changed "$user" "$banner_content"
        fi

        # --- Lock expired users and skip ---
        if $is_expired; then
            if ! $user_locked; then
                usermod -L "$user" &>/dev/null
                killall -u "$user" -9 &>/dev/null
                locked_users["$user"]=1
            fi
            continue
        fi

        [[ "$limit" =~ ^[0-9]+$ ]] || limit=1
        if (( online_count > limit )); then
            excess=$((online_count - limit))
            killed=0
            for pid in $(printf "%s\n" "${!unique_sshd_sessions[@]}" | sort -nr); do
                [[ "$pid" =~ ^[0-9]+$ ]] || continue
                kill -TERM "$pid" &>/dev/null || true
                killed=$((killed + 1))
                (( killed >= excess )) && break
            done
            if (( killed == 0 )); then
                killall -u "$user" -9 &>/dev/null
            fi
        fi

        usagefile="$BW_DIR/${user}.usage"
        accumulated=0
        if [[ -f "$usagefile" ]]; then
            read -r accumulated < "$usagefile"
            [[ "$accumulated" =~ ^[0-9]+$ ]] || accumulated=0
        fi

        if [[ "$local_user_online" != true ]]; then
            rm -f "$PID_DIR/${user}__"*.last 2>/dev/null
            continue
        fi

        delta_total=0
        for pid in "${!unique_pids[@]}"; do
            io_file="/proc/$pid/io"
            cur=0
            if [[ -r "$io_file" ]]; then
                rchar=0
                wchar=0
                while read -r key value; do
                    case "$key" in
                        rchar:) rchar=${value:-0} ;;
                        wchar:) wchar=${value:-0} ;;
                    esac
                done < "$io_file"
                cur=$((rchar + wchar))
            fi

            pidfile="$PID_DIR/${user}__${pid}.last"
            if [[ -f "$pidfile" ]]; then
                read -r prev < "$pidfile"
                [[ "$prev" =~ ^[0-9]+$ ]] || prev=0
                if (( cur >= prev )); then
                    d=$((cur - prev))
                else
                    d=$cur
                fi
                delta_total=$((delta_total + d))
            fi
            printf "%s\n" "$cur" > "$pidfile"
        done

        for f in "$PID_DIR/${user}__"*.last; do
            [[ -f "$f" ]] || continue
            fpid=${f##*__}
            fpid=${fpid%.last}
            [[ -d "/proc/$fpid" ]] || rm -f "$f"
        done

        new_total=$((accumulated + delta_total))
        printf "%s\n" "$new_total" > "$usagefile"

        if ! quota_is_unlimited "$bandwidth_gb"; then
            quota_bytes=$(awk "BEGIN {printf \"%.0f\", $bandwidth_gb * 1073741824}")
            if [[ "$quota_bytes" =~ ^[0-9]+$ ]] && (( new_total >= quota_bytes )); then
                if ! $user_locked; then
                    usermod -L "$user" &>/dev/null
                    killall -u "$user" -9 &>/dev/null
                    locked_users["$user"]=1
                fi
            fi
        fi
    done < "$DB_FILE"

    sleep "$SCAN_INTERVAL"
done
EOF
    chmod +x "$LIMITER_SCRIPT"
    # Strip DOS line endings in case menu.sh was uploaded from Windows
    sed -i 's/\r$//' "$LIMITER_SCRIPT" 2>/dev/null

    cat > "$LIMITER_SERVICE" << EOF
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
    sed -i 's/\r$//' "$LIMITER_SERVICE" 2>/dev/null

    pkill -f "tdztunnel-limiter" 2>/dev/null

    if ! systemctl is-active --quiet tdztunnel-limiter; then
        systemctl daemon-reload
        systemctl enable tdztunnel-limiter &>/dev/null
        systemctl start tdztunnel-limiter --no-block &>/dev/null
        
    else
        systemctl restart tdztunnel-limiter --no-block &>/dev/null
        
    fi
}

sync_runtime_components_if_needed() {
    local limiter_marker="# TDZ SSH TUNNEL limiter version 2026-07-18.1"
    cleanup_legacy_bandwidth_runtime
    setup_trial_cleanup_script >/dev/null 2>&1
    # Ensure sshd is hardened (idempotent — only writes if config differs)
    harden_sshd_for_tunnel_stability
    if [[ ! -f "$LIMITER_SCRIPT" ]] || ! grep -Fqx "$limiter_marker" "$LIMITER_SCRIPT" 2>/dev/null; then
        setup_limiter_service >/dev/null 2>&1
    fi
    if [[ -f "$BADVPN_SERVICE_FILE" ]]; then
        ensure_badvpn_service_is_quiet
    fi
    if [[ -f "/etc/tdztunnel/banners_enabled" ]]; then
        update_ssh_banners_config
    elif [[ -f "$SSHD_TDZ_CONFIG" ]]; then
        disable_dynamic_ssh_banner_system
        systemctl reload sshd 2>/dev/null || systemctl reload ssh 2>/dev/null || true
    fi
}

setup_bandwidth_service() {
    mkdir -p "$BANDWIDTH_DIR"
    # Bandwidth monitoring is now integrated into the limiter service above.
    cleanup_legacy_bandwidth_runtime
}

cleanup_legacy_bandwidth_runtime() {
    local needs_reload=false

    systemctl stop tdztunnel-bandwidth &>/dev/null || true
    systemctl disable tdztunnel-bandwidth &>/dev/null || true
    pkill -f "tdztunnel-bandwidth" &>/dev/null || true

    if [[ -e "$BANDWIDTH_SERVICE" || -e "$BANDWIDTH_SCRIPT" || -e "$LEGACY_BANDWIDTH_DIR" ]]; then
        rm -f "$BANDWIDTH_SERVICE" "$BANDWIDTH_SCRIPT" 2>/dev/null
        rm -rf "$LEGACY_BANDWIDTH_DIR" 2>/dev/null
        needs_reload=true
    fi

    if $needs_reload; then
        systemctl daemon-reload &>/dev/null || true
    fi
}

setup_trial_cleanup_script() {
    cat > "$TRIAL_CLEANUP_SCRIPT" << 'TREOF'
#!/bin/bash
# TDZ SSH TUNNEL Trial Account Auto-Cleanup
# Usage (legacy): tdztunnel-trial-cleanup.sh <username>
# Usage (rename-safe): tdztunnel-trial-cleanup.sh --uid <uid> <expiry_epoch>
DB_FILE="/etc/tdztunnel/users.db"
BW_DIR="/etc/tdztunnel/bandwidth"

expected_expiry_epoch=""
if [[ "$1" == "--uid" ]]; then
    user_uid="$2"
    expected_expiry_epoch="$3"
    if ! [[ "$user_uid" =~ ^[0-9]+$ && "$expected_expiry_epoch" =~ ^[0-9]+$ ]]; then
        exit 1
    fi
    username=$(getent passwd "$user_uid" 2>/dev/null | cut -d: -f1)
else
    username="$1"
fi
if [[ -z "$username" ]]; then exit 0; fi

db_line=$(grep "^${username}:" "$DB_FILE" 2>/dev/null | head -n 1)
if [[ -z "$db_line" ]]; then exit 0; fi

IFS=: read -r _ _ _ _ _ trial_marker trial_expiry_epoch _rest <<< "$db_line"
if [[ "$trial_marker" != "trial" ]]; then
    exit 0
fi
if [[ -n "$expected_expiry_epoch" && "$trial_expiry_epoch" != "$expected_expiry_epoch" ]]; then
    # UID may have been reused after the original trial was deleted. Never
    # delete a different account unless its immutable trial token also matches.
    exit 0
fi

# Kill active sessions
killall -u "$username" -9 &>/dev/null
sleep 1

# Delete system user
userdel -r "$username" &>/dev/null

# Remove from DB
sed -i "/^${username}:/d" "$DB_FILE"

# Remove bandwidth tracking
rm -f "$BW_DIR/${username}.usage"
rm -rf "$BW_DIR/pidtrack/${username}"
TREOF
    chmod +x "$TRIAL_CLEANUP_SCRIPT"
}

disable_dynamic_ssh_banner_system() {
    rm -f "/etc/tdztunnel/banners_enabled" "$SSHD_TDZ_CONFIG" /usr/local/bin/tdztunnel-login-info.sh 2>/dev/null
    rm -rf "/etc/tdztunnel/banners" 2>/dev/null
    invalidate_banner_cache
}

disable_static_ssh_banner_in_sshd_config() {
    sed -i.bak -E "s|^[[:space:]]*Banner[[:space:]]+$SSH_BANNER_FILE[[:space:]]*$|# Banner $SSH_BANNER_FILE|" /etc/ssh/sshd_config 2>/dev/null
}

is_static_ssh_banner_enabled() {
    grep -q -E "^[[:space:]]*Banner[[:space:]]+$SSH_BANNER_FILE[[:space:]]*$" /etc/ssh/sshd_config 2>/dev/null && [ -f "$SSH_BANNER_FILE" ]
}

is_dynamic_ssh_banner_enabled() {
    [[ -f "/etc/tdztunnel/banners_enabled" && -f "$SSHD_TDZ_CONFIG" ]]
}

get_ssh_banner_mode() {
    if is_dynamic_ssh_banner_enabled; then
        echo "dynamic"
    elif is_static_ssh_banner_enabled; then
        echo "static"
    else
        echo "disabled"
    fi
}

refresh_dynamic_banner_routing_if_enabled() {
    if is_dynamic_ssh_banner_enabled; then
        update_ssh_banners_config
    fi
}

update_ssh_banners_config() {
    local tmp_conf

    if [[ ! -f "/etc/tdztunnel/banners_enabled" ]]; then
        if [[ -f "$SSHD_TDZ_CONFIG" ]]; then
            rm -f "$SSHD_TDZ_CONFIG" 2>/dev/null
            systemctl reload sshd 2>/dev/null || systemctl reload ssh 2>/dev/null
        fi
        return
    fi

    ensure_tdztunnel_dirs
    tmp_conf="/tmp/tdz_banners_new.conf"
    echo "# TDZ SSH TUNNEL - Dynamic per-user SSH banners" > "$tmp_conf"

    if [[ -f "$DB_FILE" ]]; then
        while IFS=: read -r u _rest; do
            [[ -z "$u" || "$u" == \#* ]] && continue
            echo "Match User $u" >> "$tmp_conf"
            echo "    Banner /etc/tdztunnel/banners/${u}.txt" >> "$tmp_conf"
        done < "$DB_FILE"
    fi

    if ! cmp -s "$tmp_conf" "$SSHD_TDZ_CONFIG" 2>/dev/null; then
        mv "$tmp_conf" "$SSHD_TDZ_CONFIG"
        if ! grep -q "^Include /etc/ssh/sshd_config.d/" /etc/ssh/sshd_config 2>/dev/null; then
            echo "Include /etc/ssh/sshd_config.d/*.conf" >> /etc/ssh/sshd_config
        fi
        systemctl reload sshd 2>/dev/null || systemctl reload ssh 2>/dev/null
    else
        rm -f "$tmp_conf"
    fi
}

setup_ssh_login_info() {
    ensure_tdztunnel_dirs || return 1
    if ! touch "/etc/tdztunnel/banners_enabled"; then
        echo -e "${C_RED}[ERROR] Failed to enable dynamic SSH banners.${C_RESET}"
        return 1
    fi
    disable_static_ssh_banner_in_sshd_config
    update_ssh_banners_config
    return 0
}


domain_cert_menu() {
    clear; show_banner
    load_edge_cert_info

    local cert_domain="${EDGE_DOMAIN:-Not configured}"
    local cert_mode="${EDGE_CERT_MODE:-None}"
    echo
    tdz_box_top
    tdz_box_header "DOMAIN & SSL"
    tdz_box_divider
    tdz_kv2 "DOMAIN" "$cert_domain" "MODE" "$cert_mode"
    if [[ -n "$EDGE_EMAIL" ]]; then
        tdz_row "${C_GRAY}EMAIL${C_RESET} ${C_WHITE}$EDGE_EMAIL${C_RESET}"
    fi
    tdz_box_divider
    tdz_menu1 "[ 1]" "Configure Let's Encrypt Certificate"
    tdz_menu1 "[ 2]" "Generate Self-Signed Certificate"
    tdz_menu1 "[ 3]" "Remove Current Certificate"
    tdz_box_divider
    tdz_menu1 "[ 0]" "Return"
    tdz_box_bot
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" dc_choice

    case "$dc_choice" in
        1)
            local domain_name email
            echo -e "\n${C_BLUE}[INFO] Before continuing, make sure your domain's A record points to this server's IP.${C_RESET}"
            echo -e "${C_BLUE}[INFO] Also make sure port 80 is open (certbot needs port 80 for Let's Encrypt validation).${C_RESET}"
            echo
            read -p "  Enter your domain (e.g. vpn.example.com): " domain_name
            if [[ -z "$domain_name" ]]; then
                echo -e "\n${C_RED}[ERROR] Domain cannot be empty.${C_RESET}"
                return 1
            fi
            if _is_valid_ipv4 "$domain_name"; then
                echo -e "\n${C_RED}[ERROR] Certbot requires a real domain name, not a raw IP.${C_RESET}"
                return 1
            fi
            read -p "  Enter your email for Let's Encrypt: " email
            if [[ -z "$email" ]]; then
                echo -e "\n${C_RED}[ERROR] Email cannot be empty.${C_RESET}"
                return 1
            fi
            obtain_certbot_edge_cert "$domain_name" "$email"
            ;;
        2)
            local common_name
            local preferred_host
            preferred_host=$(detect_preferred_host)
            read -p "  Enter certificate Common Name [$preferred_host]: " common_name
            common_name=${common_name:-$preferred_host}
            generate_self_signed_edge_cert "$common_name"
            ;;
        3)
            if [[ -z "$EDGE_DOMAIN" && ! -f "$TDZ_SSL_CERT_FILE" ]]; then
                echo -e "\n${C_YELLOW}[INFO] No certificate to remove.${C_RESET}"
                return
            fi
            read -p "  Confirm removal? (y/n): " confirm
            if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
                rm -f "$TDZ_SSL_CERT_FILE" "$SSL_CERT_CHAIN_FILE" "$SSL_CERT_KEY_FILE" "$EDGE_CERT_INFO_FILE"
                echo -e "\n${C_GREEN}[OK] Certificate removed.${C_RESET}"
            else
                tdz_message CANCELLED "Certificate removal cancelled."
            fi
            ;;
        0|"") return ;;
        *) echo -e "\n${C_RED}[ERROR] Invalid option.${C_RESET}" && sleep 1 ;;
    esac
}

_select_user_interface() {
    local title="$1"
    clear; show_banner
    if [[ ! -s $DB_FILE ]]; then
        echo
        tdz_box_top
        tdz_box_header "$title"
        tdz_box_divider
        tdz_row "${C_YELLOW}No users found in the database.${C_RESET}"
        tdz_box_bot
        SELECTED_USER="NO_USERS"; return
    fi

    local -a all_users=() users=()
    mapfile -t all_users < <(cut -d: -f1 "$DB_FILE" | sort)
    local -A all_user_lookup=()
    local username search_term user_number
    for username in "${all_users[@]}"; do
        all_user_lookup["$username"]=1
    done
    
    if [ ${#all_users[@]} -ge 15 ]; then
        read -r -p "$(echo -e "${C_PROMPT}  Search username (Enter = all): ${C_RESET}")" search_term
        if [[ -n "$search_term" ]]; then
            mapfile -t users < <(printf "%s\n" "${all_users[@]}" | grep -i "$search_term")
        else
            users=("${all_users[@]}")
        fi
    else
        users=("${all_users[@]}")
    fi

    if [ ${#users[@]} -eq 0 ]; then
        echo -e "\n${C_YELLOW}No users found matching your search.${C_RESET}"
        SELECTED_USER="NO_USERS"; return
    fi

    echo
    tdz_box_top
    tdz_box_header "$title"
    tdz_box_divider
    for i in "${!users[@]}"; do
        printf -v user_number "[%2d]" "$((i+1))"
        tdz_menu1 "$user_number" "${users[$i]}"
    done
    tdz_box_divider
    tdz_menu1 "[ 0]" "Cancel"
    tdz_row "${C_GRAY}Number or exact username is accepted.${C_RESET}"
    tdz_box_bot
    echo
    local choice
    while true; do
        if ! read -r -p "$(echo -e "${C_PROMPT}  Select a user: ${C_RESET}")" choice; then
            echo
            SELECTED_USER=""
            return
        fi
        if [[ "$choice" =~ ^[0-9]+$ ]] && [ "$choice" -ge 0 ] && [ "$choice" -le "${#users[@]}" ]; then
            if [ "$choice" -eq 0 ]; then
                SELECTED_USER=""; return
            else
                SELECTED_USER="${users[$((choice-1))]}"; return
            fi
        elif [[ -n "${all_user_lookup[$choice]+x}" ]]; then
            SELECTED_USER="$choice"; return
        else
            echo -e "${C_RED}[ERROR] Invalid selection. Please try again.${C_RESET}"
        fi
    done
}

_select_multi_user_interface() {
    local title="$1"
    local include_orphan_users="${2:-false}"
    clear; show_banner
    SELECTED_USERS=()
    local -a all_users=() users=()
    local -a orphan_users=()
    local -A all_user_lookup=()
    local -A orphan_user_lookup=()
    local username search_term user_number

    if [[ -s $DB_FILE ]]; then
        mapfile -t all_users < <(cut -d: -f1 "$DB_FILE" | sort)
    fi

    if [[ "$include_orphan_users" == "true" ]]; then
        mapfile -t orphan_users < <(get_tdztunnel_orphan_users)
        for username in "${orphan_users[@]}"; do
            orphan_user_lookup["$username"]=1
            if ! printf "%s\n" "${all_users[@]}" | grep -Fxq "$username"; then
                all_users+=("$username")
            fi
        done
        if [[ ${#all_users[@]} -gt 0 ]]; then
            mapfile -t all_users < <(printf "%s\n" "${all_users[@]}" | sort)
        fi
    fi

    if [[ ${#all_users[@]} -eq 0 ]]; then
        echo
        tdz_box_top
        tdz_box_header "$title"
        tdz_box_divider
        tdz_row "${C_YELLOW}No managed users were found.${C_RESET}"
        if [[ "$include_orphan_users" == "true" ]]; then
            tdz_row "${C_GRAY}No system-only accounts were found.${C_RESET}"
        fi
        tdz_box_bot
        SELECTED_USERS=("NO_USERS"); return
    fi

    for username in "${all_users[@]}"; do
        all_user_lookup["$username"]=1
    done
    
    if [ ${#all_users[@]} -ge 15 ]; then
        read -r -p "$(echo -e "${C_PROMPT}  Search username (Enter = all): ${C_RESET}")" search_term
        if [[ -n "$search_term" ]]; then
            mapfile -t users < <(printf "%s\n" "${all_users[@]}" | grep -i "$search_term")
        else
            users=("${all_users[@]}")
        fi
    else
        users=("${all_users[@]}")
    fi

    if [ ${#users[@]} -eq 0 ]; then
        echo -e "\n${C_YELLOW}No users found matching your search.${C_RESET}"
        SELECTED_USERS=("NO_USERS"); return
    fi

    echo
    tdz_box_top
    tdz_box_header "$title"
    tdz_box_divider
    for i in "${!users[@]}"; do
        local display_user="${users[$i]}"
        if [[ "$include_orphan_users" == "true" && -n "${orphan_user_lookup[${users[$i]}]+x}" ]]; then
            display_user="${display_user} (system-only)"
        fi
        printf -v user_number "[%2d]" "$((i+1))"
        tdz_menu1 "$user_number" "$display_user"
    done
    tdz_box_divider
    tdz_menu1 "[all]" "Select All Listed Users"
    tdz_menu1 "[ 0]" "Cancel"
    tdz_row "${C_GRAY}Examples: 1 3 5 | 1,3 | 1-4 | alice bob${C_RESET}"
    if [[ "$include_orphan_users" == "true" ]]; then
        tdz_row "${C_GRAY}(system-only) = account missing from users.db${C_RESET}"
    fi
    tdz_box_bot
    echo
    local choice
    while true; do
        if ! read -r -p "$(echo -e "${C_PROMPT}  Select users: ${C_RESET}")" choice; then
            echo
            SELECTED_USERS=()
            return
        fi
        choice=$(echo "$choice" | tr ',' ' ') # Replace commas with spaces
        
        if [[ -z "$choice" ]]; then
            echo -e "${C_RED}[ERROR] Invalid selection. Please try again.${C_RESET}"
            continue
        fi

        if [[ "$choice" == "0" ]]; then
            SELECTED_USERS=(); return
        fi
        
        if [[ "${choice,,}" == "all" ]]; then
            SELECTED_USERS=("${users[@]}")
            return
        fi
        
        local valid=true
        local selected_indices=()
        local selected_names=()
        for token in $choice; do
            if [[ "$token" =~ ^[0-9]+-[0-9]+$ ]]; then
                local start=${token%-*}
                local end=${token#*-}
                if [ "$start" -le "$end" ]; then
                    for (( idx=start; idx<=end; idx++ )); do
                        if [ "$idx" -ge 1 ] && [ "$idx" -le "${#users[@]}" ]; then
                            selected_indices+=($idx)
                        else
                            valid=false; break
                        fi
                    done
                else
                    valid=false; break
                fi
            elif [[ "$token" =~ ^[0-9]+$ ]]; then
                if [ "$token" -ge 1 ] && [ "$token" -le "${#users[@]}" ]; then
                    selected_indices+=($token)
                elif [[ -n "${all_user_lookup[$token]+x}" ]]; then
                    selected_names+=("$token")
                else
                    valid=false; break
                fi
            elif [[ -n "${all_user_lookup[$token]+x}" ]]; then
                selected_names+=("$token")
            else
                valid=false; break
            fi
        done
        
        if [[ "$valid" == true && ( ${#selected_indices[@]} -gt 0 || ${#selected_names[@]} -gt 0 ) ]]; then
            mapfile -t unique_indices < <(printf "%s\n" "${selected_indices[@]}" | sort -u -n)
            for idx in "${unique_indices[@]}"; do
                SELECTED_USERS+=("${users[$((idx-1))]}")
            done
            mapfile -t unique_names < <(printf "%s\n" "${selected_names[@]}" | sort -u)
            for username in "${unique_names[@]}"; do
                if ! printf "%s\n" "${SELECTED_USERS[@]}" | grep -Fxq "$username"; then
                    SELECTED_USERS+=("$username")
                fi
            done
            return
        else
            echo -e "${C_RED}[ERROR] Invalid selection. Please check your numbers or usernames.${C_RESET}"
            SELECTED_USERS=()
            selected_indices=()
            selected_names=()
        fi
    done
}

get_user_status() {
    local username="$1"
    if ! id "$username" &>/dev/null; then echo -e "${C_RED}Not Found${C_RESET}"; return; fi
    local user_line expiry_date account_type
    user_line=$(grep "^$username:" "$DB_FILE")
    expiry_date=$(echo "$user_line" | cut -d: -f3)
    account_type=$(echo "$user_line" | cut -d: -f6)
    if passwd -S "$username" 2>/dev/null | grep -q " L "; then echo -e "${C_YELLOW}Locked${C_RESET}"; return; fi
    if [[ "$account_type" == "pending" ]]; then echo -e "${C_CYAN}Waiting for First Use${C_RESET}"; return; fi
    if [[ "$expiry_date" == "Never" || -z "$expiry_date" ]]; then echo -e "${C_GREEN}Active${C_RESET}"; return; fi
    local expiry_ts=$(date -d "$expiry_date" +%s 2>/dev/null || echo 0)
    local current_ts=$(date +%s)
    if (( expiry_ts > 0 && expiry_ts < current_ts )); then echo -e "${C_RED}Expired${C_RESET}"; return; fi
    echo -e "${C_GREEN}Active${C_RESET}"
}

is_valid_tdztunnel_username() {
    local username="$1"
    [[ ${#username} -le 32 && "$username" =~ ^[A-Za-z_][A-Za-z0-9_-]{0,31}$ ]]
}

rollback_tdztunnel_user_rename() {
    local old_username="$1" new_username="$2"
    local old_home="$3" new_home="$4" move_home="$5"
    local group_renamed="$6" usage_moved="$7" banner_created="$8"
    local rollback_ok=true

    if [[ "$banner_created" == true ]]; then
        rm -f "$DB_DIR/banners/${new_username}.txt" 2>/dev/null || rollback_ok=false
    fi
    if [[ "$usage_moved" == true ]]; then
        mv -f "$BANDWIDTH_DIR/${new_username}.usage" \
            "$BANDWIDTH_DIR/${old_username}.usage" 2>/dev/null || rollback_ok=false
    fi
    if [[ "$group_renamed" == true ]] && getent group "$new_username" >/dev/null 2>&1; then
        groupmod -n "$old_username" "$new_username" >/dev/null 2>&1 || rollback_ok=false
    fi
    if id "$new_username" >/dev/null 2>&1; then
        if [[ "$move_home" == true ]]; then
            if [[ -d "$new_home" && ! -e "$old_home" ]]; then
                usermod -l "$old_username" -d "$old_home" -m "$new_username" >/dev/null 2>&1 || rollback_ok=false
            else
                usermod -l "$old_username" -d "$old_home" "$new_username" >/dev/null 2>&1 || rollback_ok=false
            fi
        else
            usermod -l "$old_username" "$new_username" >/dev/null 2>&1 || rollback_ok=false
        fi
    fi

    $rollback_ok
}

rename_tdztunnel_user() {
    local old_username="$1" new_username="$2"
    local passwd_entry account_type trial_expiry_epoch old_login old_password old_uid old_gid old_gecos old_home old_shell
    local primary_group new_home move_home=false
    local db_tmp="" db_backup="" banner_tmp=""
    local limiter_was_active=false group_renamed=false usage_moved=false banner_created=false
    local confirm active_process_count

    if ! db_has_user "$old_username" || ! id "$old_username" >/dev/null 2>&1; then
        echo -e "\n${C_RED}[ERROR] The current account is missing from the database or system.${C_RESET}"
        return 1
    fi
    if [[ "$new_username" == "$old_username" ]]; then
        echo -e "\n${C_YELLOW}[INFO] The username is already '${old_username}'. Nothing was changed.${C_RESET}"
        return 1
    fi
    if ! is_valid_tdztunnel_username "$new_username"; then
        echo -e "\n${C_RED}[ERROR] Invalid username.${C_RESET}"
        echo -e "${C_DIM}Use 1-32 letters, numbers, '_' or '-'; start with a letter or '_'.${C_RESET}"
        return 1
    fi
    if db_has_user "$new_username" || getent passwd "$new_username" >/dev/null 2>&1; then
        echo -e "\n${C_RED}[ERROR] Username '${new_username}' already exists.${C_RESET}"
        return 1
    fi

    # New trial cleanup jobs use UID + an immutable expiry token and remain
    # valid after a rename. Only pre-upgrade legacy trials lack that token.
    account_type=$(awk -F: -v target="$old_username" '$1 == target {print $6; exit}' "$DB_FILE")
    trial_expiry_epoch=$(awk -F: -v target="$old_username" '$1 == target {print $7; exit}' "$DB_FILE")
    if [[ "$account_type" == "trial" && ! "$trial_expiry_epoch" =~ ^[0-9]+$ ]]; then
        echo -e "\n${C_YELLOW}[WARNING] This legacy trial was scheduled by username before rename-safe cleanup existed.${C_RESET}"
        echo -e "${C_DIM}Create a new trial instead; current trial accounts can be renamed safely.${C_RESET}"
        return 1
    fi

    passwd_entry=$(getent passwd "$old_username" 2>/dev/null) || {
        echo -e "\n${C_RED}[ERROR] Could not read the system account.${C_RESET}"
        return 1
    }
    IFS=: read -r old_login old_password old_uid old_gid old_gecos old_home old_shell <<< "$passwd_entry"
    primary_group=$(getent group "$old_gid" 2>/dev/null | cut -d: -f1)
    if [[ -z "$primary_group" ]]; then
        echo -e "\n${C_RED}[ERROR] Could not resolve the account's primary group.${C_RESET}"
        return 1
    fi
    if [[ "$primary_group" == "$old_username" ]] && getent group "$new_username" >/dev/null 2>&1; then
        echo -e "\n${C_RED}[ERROR] Group '${new_username}' already exists; rename cancelled to avoid a group conflict.${C_RESET}"
        return 1
    fi

    new_home="$old_home"
    if [[ "$old_home" == "/home/${old_username}" ]]; then
        new_home="/home/${new_username}"
        move_home=true
        if [[ -e "$new_home" ]]; then
            echo -e "\n${C_RED}[ERROR] Home path '${new_home}' already exists.${C_RESET}"
            return 1
        fi
    fi
    if [[ -e "$BANDWIDTH_DIR/${new_username}.usage" ||
          -e "$DB_DIR/banners/${new_username}.txt" ]]; then
        echo -e "\n${C_RED}[ERROR] Stored data for '${new_username}' already exists; rename cancelled to prevent overwriting it.${C_RESET}"
        return 1
    fi

    db_backup=$(mktemp "${DB_FILE}.rename-backup.XXXXXX") || return 1
    db_tmp=$(mktemp "${DB_FILE}.rename-new.XXXXXX") || {
        rm -f "$db_backup"
        return 1
    }
    if ! cp -p "$DB_FILE" "$db_backup" ||
       ! awk -F: -v OFS=: -v old="$old_username" -v new="$new_username" '
            $1 == old { $1 = new; found = 1 }
            { print }
            END { if (!found) exit 3 }
        ' "$DB_FILE" > "$db_tmp"; then
        rm -f "$db_tmp" "$db_backup"
        echo -e "\n${C_RED}[ERROR] Could not prepare the database migration.${C_RESET}"
        return 1
    fi
    chmod --reference="$DB_FILE" "$db_tmp" 2>/dev/null || true
    chown --reference="$DB_FILE" "$db_tmp" 2>/dev/null || true

    if [[ -f "$DB_DIR/banners/${old_username}.txt" ]]; then
        banner_tmp=$(mktemp "$DB_DIR/banners/.rename.XXXXXX") || {
            rm -f "$db_tmp" "$db_backup"
            return 1
        }
        if ! awk -v old="$old_username" -v new="$new_username" '
                {
                    position = index($0, old)
                    if (position) {
                        $0 = substr($0, 1, position - 1) new substr($0, position + length(old))
                    }
                    print
                }
            ' "$DB_DIR/banners/${old_username}.txt" > "$banner_tmp"; then
            rm -f "$banner_tmp" "$db_tmp" "$db_backup"
            echo -e "\n${C_RED}[ERROR] Could not prepare the dynamic banner migration.${C_RESET}"
            return 1
        fi
        chmod --reference="$DB_DIR/banners/${old_username}.txt" "$banner_tmp" 2>/dev/null || true
        chown --reference="$DB_DIR/banners/${old_username}.txt" "$banner_tmp" 2>/dev/null || true
    fi

    echo -e "\n${C_YELLOW}The account will be renamed:${C_RESET}"
    echo -e "  • Username: ${C_WHITE}${old_username}${C_RESET} → ${C_GREEN}${new_username}${C_RESET}"
    read -r -p "  Type RENAME to confirm: " confirm
    if [[ "$confirm" != "RENAME" ]]; then
        rm -f "$banner_tmp" "$db_tmp" "$db_backup"
        tdz_message CANCELLED "Username change cancelled."
        return 1
    fi

    if systemctl is-active --quiet tdztunnel-limiter 2>/dev/null; then
        limiter_was_active=true
        if ! systemctl stop tdztunnel-limiter >/dev/null 2>&1; then
            rm -f "$banner_tmp" "$db_tmp" "$db_backup"
            echo -e "\n${C_RED}[ERROR] Could not pause the account worker safely; rename cancelled.${C_RESET}"
            return 1
        fi
    fi

    active_process_count=$(pgrep -u "$old_username" 2>/dev/null | wc -l)
    if (( active_process_count > 0 )); then
        echo -e "\n${C_YELLOW}[WARNING] ${active_process_count} active process(es) must be disconnected before renaming.${C_RESET}"
        read -r -p "  Disconnect them and continue? (y/n): " confirm
        if [[ "$confirm" != "y" && "$confirm" != "Y" ]]; then
            $limiter_was_active && systemctl start tdztunnel-limiter >/dev/null 2>&1 || true
            rm -f "$banner_tmp" "$db_tmp" "$db_backup"
            tdz_message CANCELLED "Username change cancelled."
            return 1
        fi
        pkill -TERM -u "$old_username" >/dev/null 2>&1 || true
        sleep 1
        pgrep -u "$old_username" >/dev/null 2>&1 && pkill -KILL -u "$old_username" >/dev/null 2>&1 || true
        sleep 1
        if pgrep -u "$old_username" >/dev/null 2>&1; then
            $limiter_was_active && systemctl start tdztunnel-limiter >/dev/null 2>&1 || true
            rm -f "$banner_tmp" "$db_tmp" "$db_backup"
            echo -e "\n${C_RED}[ERROR] Some account processes could not be stopped; rename cancelled.${C_RESET}"
            return 1
        fi
    fi

    if [[ "$move_home" == true ]]; then
        if [[ -d "$old_home" ]]; then
            usermod -l "$new_username" -d "$new_home" -m "$old_username" >/dev/null 2>&1
        else
            usermod -l "$new_username" -d "$new_home" "$old_username" >/dev/null 2>&1
        fi
    else
        usermod -l "$new_username" "$old_username" >/dev/null 2>&1
    fi
    if [[ $? -ne 0 ]]; then
        local partial_rollback_ok=true
        if id "$new_username" >/dev/null 2>&1 && ! id "$old_username" >/dev/null 2>&1; then
            rollback_tdztunnel_user_rename "$old_username" "$new_username" \
                "$old_home" "$new_home" "$move_home" false false false || partial_rollback_ok=false
        fi
        $limiter_was_active && systemctl start tdztunnel-limiter >/dev/null 2>&1 || true
        rm -f "$banner_tmp" "$db_tmp" "$db_backup"
        if $partial_rollback_ok; then
            echo -e "\n${C_RED}[ERROR] Linux account rename failed; the original account was preserved.${C_RESET}"
        else
            echo -e "\n${C_RED}[ERROR] Linux account rename failed and automatic rollback was incomplete.${C_RESET}"
            echo -e "${C_YELLOW}[WARNING] Do not close this SSH session; inspect the system account manually.${C_RESET}"
        fi
        return 1
    fi

    if [[ "$primary_group" == "$old_username" ]]; then
        if ! groupmod -n "$new_username" "$old_username" >/dev/null 2>&1; then
            rollback_tdztunnel_user_rename "$old_username" "$new_username" \
                "$old_home" "$new_home" "$move_home" false false false
            $limiter_was_active && systemctl start tdztunnel-limiter >/dev/null 2>&1 || true
            rm -f "$banner_tmp" "$db_tmp" "$db_backup"
            echo -e "\n${C_RED}[ERROR] Private group rename failed; the original username was restored.${C_RESET}"
            return 1
        fi
        group_renamed=true
    fi

    if [[ -f "$BANDWIDTH_DIR/${old_username}.usage" ]]; then
        if ! mv "$BANDWIDTH_DIR/${old_username}.usage" "$BANDWIDTH_DIR/${new_username}.usage"; then
            rollback_tdztunnel_user_rename "$old_username" "$new_username" \
                "$old_home" "$new_home" "$move_home" "$group_renamed" false false
            $limiter_was_active && systemctl start tdztunnel-limiter >/dev/null 2>&1 || true
            rm -f "$banner_tmp" "$db_tmp" "$db_backup"
            echo -e "\n${C_RED}[ERROR] Bandwidth data migration failed; the original username was restored.${C_RESET}"
            return 1
        fi
        usage_moved=true
    fi

    if [[ -n "$banner_tmp" ]]; then
        if ! mv "$banner_tmp" "$DB_DIR/banners/${new_username}.txt"; then
            rollback_tdztunnel_user_rename "$old_username" "$new_username" \
                "$old_home" "$new_home" "$move_home" "$group_renamed" "$usage_moved" false
            $limiter_was_active && systemctl start tdztunnel-limiter >/dev/null 2>&1 || true
            rm -f "$banner_tmp" "$db_tmp" "$db_backup"
            echo -e "\n${C_RED}[ERROR] Banner migration failed; the original username was restored.${C_RESET}"
            return 1
        fi
        banner_created=true
        banner_tmp=""
    fi

    if ! mv -f "$db_tmp" "$DB_FILE"; then
        rollback_tdztunnel_user_rename "$old_username" "$new_username" \
            "$old_home" "$new_home" "$move_home" "$group_renamed" "$usage_moved" "$banner_created"
        $limiter_was_active && systemctl start tdztunnel-limiter >/dev/null 2>&1 || true
        rm -f "$db_tmp" "$db_backup"
        echo -e "\n${C_RED}[ERROR] Database migration failed; the original username was restored.${C_RESET}"
        return 1
    fi

    if ! id "$new_username" >/dev/null 2>&1 || id "$old_username" >/dev/null 2>&1 ||
       ! db_has_user "$new_username" || db_has_user "$old_username"; then
        mv -f "$db_backup" "$DB_FILE" 2>/dev/null
        rollback_tdztunnel_user_rename "$old_username" "$new_username" \
            "$old_home" "$new_home" "$move_home" "$group_renamed" "$usage_moved" "$banner_created"
        $limiter_was_active && systemctl start tdztunnel-limiter >/dev/null 2>&1 || true
        echo -e "\n${C_RED}[ERROR] Post-rename verification failed; the original username was restored.${C_RESET}"
        return 1
    fi

    rm -f "$db_backup" "$DB_DIR/banners/${old_username}.txt"
    rm -rf "$BANDWIDTH_DIR/pidtrack/${old_username}" 2>/dev/null
    rm -f "$BANDWIDTH_DIR/pidtrack/${old_username}__"*.last 2>/dev/null
    if ! id -nG "$new_username" 2>/dev/null | tr ' ' '\n' | grep -Fxq "$TDZ_USERS_GROUP"; then
        usermod -aG "$TDZ_USERS_GROUP" "$new_username" >/dev/null 2>&1 || true
    fi

    invalidate_banner_cache
    refresh_dynamic_banner_routing_if_enabled
    if $limiter_was_active && ! systemctl start tdztunnel-limiter >/dev/null 2>&1; then
        echo -e "${C_YELLOW}[WARNING] Username changed, but the account worker must be restarted manually.${C_RESET}"
    fi

    echo -e "\n${C_GREEN}[OK] Username changed successfully: ${old_username} → ${new_username}${C_RESET}"
    return 0
}

create_user() {
    clear; show_banner
    tdz_screen_title "CREATE SSH USER" "Create a managed SSH account with limits and expiry."
    read -r -p "$(echo -e "${C_PROMPT}  Username (0 = cancel): ${C_RESET}")" username
    local adopt_existing=false
    if [[ "$username" == "0" ]]; then
        tdz_message CANCELLED "User creation cancelled."
        return
    fi
    if [[ -z "$username" ]]; then
        tdz_message ERROR "Username cannot be empty."
        return
    fi
    if db_has_user "$username"; then
        tdz_message ERROR "User '$username' already exists in TDZ SSH TUNNEL."
        return
    fi
    if id "$username" &>/dev/null; then
        if is_tdztunnel_orphan_user "$username"; then
            tdz_message WARNING "User '$username' exists on the system but is missing from users.db."
            echo -e "${C_DIM}This usually happens after uninstalling the script without deleting the SSH users.${C_RESET}"
            read -r -p "$(echo -e "${C_PROMPT}  Import and manage this account? [y/N]: ${C_RESET}")" adopt_confirm
            if [[ "$adopt_confirm" == "y" || "$adopt_confirm" == "Y" ]]; then
                adopt_existing=true
            else
                tdz_message CANCELLED "User creation cancelled."
                return
            fi
        else
            tdz_message ERROR "System user '$username' already exists and is not a TDZ-managed account."
            return
        fi
    fi
    local password=""
    while true; do
        read -r -p "$(echo -e "${C_PROMPT}  Password (Enter = auto-generate): ${C_RESET}")" password
        if [[ -z "$password" ]]; then
            password=$(head /dev/urandom | tr -dc 'A-Za-z0-9' | head -c 8)
            printf "  ${C_GRAY}Generated password:${C_RESET} ${C_YELLOW}%s${C_RESET}\n" "$password"
            break
        else
            break
        fi
    done
    local first_use_activation=false
    local first_use_choice validity_prompt
    read -r -p "$(echo -e "${C_PROMPT}  Start After First Use? [y/N]: ${C_RESET}")" first_use_choice
    [[ "$first_use_choice" == "y" || "$first_use_choice" == "Y" ]] && first_use_activation=true
    if $first_use_activation; then
        validity_prompt="Validity after first use (days) [30]"
    else
        validity_prompt="Validity from today (days) [30]"
    fi
    read -r -p "$(echo -e "${C_PROMPT}  ${validity_prompt}: ${C_RESET}")" days
    days=${days:-30}
    if ! [[ "$days" =~ ^[1-9][0-9]*$ ]]; then tdz_message ERROR "Validity must be at least 1 day."; return; fi
    read -r -p "$(echo -e "${C_PROMPT}  Connection limit [1]: ${C_RESET}")" limit
    limit=${limit:-1}
    if ! [[ "$limit" =~ ^[0-9]+$ ]]; then tdz_message ERROR "Connection limit must be a whole number."; return; fi
    read -r -p "$(echo -e "${C_PROMPT}  Bandwidth in GB (0 = unlimited) [0]: ${C_RESET}")" bandwidth_gb
    bandwidth_gb=${bandwidth_gb:-0}
    if ! [[ "$bandwidth_gb" =~ ^[0-9]+\.?[0-9]*$ ]]; then tdz_message ERROR "Bandwidth must be a valid number."; return; fi
    local expire_date stored_expiry metadata_suffix="" expiry_display activation_display="Immediately"
    expire_date=$(date -d "+$days days" +%Y-%m-%d)
    stored_expiry="$expire_date"
    expiry_display="$expire_date"
    if $first_use_activation; then
        stored_expiry="Never"
        metadata_suffix=":pending:${days}"
        expiry_display="${days} days after first use"
        activation_display="After First Use"
    fi
    ensure_tdztunnel_system_group
    if [[ "$adopt_existing" == "true" ]]; then
        usermod -s /usr/sbin/nologin "$username" &>/dev/null
    else
        useradd -m -s /usr/sbin/nologin "$username"
    fi
    usermod -aG "$TDZ_USERS_GROUP" "$username" 2>/dev/null
    echo "$username:$password" | chpasswd
    if $first_use_activation; then
        chage -E -1 "$username"
    else
        chage -E "$expire_date" "$username"
    fi
    echo "$username:$password:$stored_expiry:$limit:$bandwidth_gb$metadata_suffix" >> "$DB_FILE"
    
    local bw_display
    bw_display=$(tdz_format_quota_gb "$bandwidth_gb")
    
    clear; show_banner
    if [[ "$adopt_existing" == "true" ]]; then
        tdz_message OK "Existing system account imported successfully."
    else
        tdz_message OK "SSH account created successfully."
    fi
    echo
    tdz_section "ACCOUNT DETAILS"
    tdz_detail "Username" "$username" "$C_YELLOW"
    tdz_detail "Password" "$password" "$C_YELLOW"
    tdz_detail "Expires" "$expiry_display" "$C_YELLOW"
    tdz_detail "Expiry Starts" "$activation_display"
    tdz_detail "Connections" "$limit"
    tdz_detail "Bandwidth" "$bw_display"
    echo -e "  ${C_DIM}Limits are enforced automatically by the account worker.${C_RESET}"

    # Auto-ask for config generation
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Generate client configuration now? [y/N]: ${C_RESET}")" gen_conf
    if [[ "$gen_conf" == "y" || "$gen_conf" == "Y" ]]; then
        generate_client_config "$username" "$password"
    fi
    
    invalidate_banner_cache
    refresh_dynamic_banner_routing_if_enabled
}

delete_user() {
    _select_multi_user_interface "DELETE USERS" "true"
    if [[ ${#SELECTED_USERS[@]} -eq 0 || "${SELECTED_USERS[0]}" == "NO_USERS" ]]; then return; fi
    
    echo -e "\n${C_RED}[WARNING] You selected ${#SELECTED_USERS[@]} user(s) to delete: ${C_YELLOW}${SELECTED_USERS[*]}${C_RESET}"
    read -p "  Are you sure you want to PERMANENTLY delete them? (y/n): " confirm
    if [[ "$confirm" != "y" ]]; then tdz_message CANCELLED "Deletion cancelled."; return; fi
    
    echo -e "\n${C_BLUE}Deleting selected users...${C_RESET}"
    delete_tdztunnel_user_accounts "${SELECTED_USERS[@]}"
}

edit_user() {
    _select_user_interface "EDIT USER"
    local username=$SELECTED_USER
    if [[ "$username" == "NO_USERS" ]] || [[ -z "$username" ]]; then return; fi
    while true; do
        clear; show_banner
        
        # Show current user details
        local current_line; current_line=$(grep "^$username:" "$DB_FILE")
        local cur_pass; cur_pass=$(echo "$current_line" | cut -d: -f2)
        local cur_expiry; cur_expiry=$(echo "$current_line" | cut -d: -f3)
        local cur_limit; cur_limit=$(echo "$current_line" | cut -d: -f4)
        local cur_bw; cur_bw=$(echo "$current_line" | cut -d: -f5)
        local cur_metadata; cur_metadata=$(echo "$current_line" | cut -d: -f6-)
        local cur_metadata_suffix=""; [[ -n "$cur_metadata" ]] && cur_metadata_suffix=":$cur_metadata"
        [[ "$cur_limit" =~ ^[0-9]+$ ]] || cur_limit="1"
        [[ "$cur_bw" =~ ^[0-9]+\.?[0-9]*$ ]] || cur_bw="0"
        local cur_bw_display
        cur_bw_display=$(tdz_format_quota_gb "$cur_bw")
        local cur_expiry_display="$cur_expiry"
        local pending_first_use=false pending_validity_days=""
        if [[ "$cur_metadata" =~ ^pending:([1-9][0-9]*) ]]; then
            pending_first_use=true
            pending_validity_days="${BASH_REMATCH[1]}"
            cur_expiry_display="First use +${pending_validity_days}d"
        fi

        SSH_SESSION_CACHE_TS=0
        refresh_ssh_session_cache
        local cur_online="${SSH_SESSION_COUNTS[$username]:-0}"
        [[ "$cur_online" =~ ^[0-9]+$ ]] || cur_online="0"
        local cur_connections="${cur_online}/${cur_limit}"
        
        # Show bandwidth usage
        local bw_used_display="0.00GB"
        if [[ -f "$BANDWIDTH_DIR/${username}.usage" ]]; then
            local used_bytes; used_bytes=$(cat "$BANDWIDTH_DIR/${username}.usage" 2>/dev/null)
            [[ "$used_bytes" =~ ^[0-9]+$ ]] || used_bytes="0"
            bw_used_display=$(tdz_format_used_bytes "$used_bytes")
        fi
        
        echo
        tdz_box_top
        tdz_box_header "EDIT USER"
        tdz_box_divider
        tdz_kv2 "USER" "$username" "EXPIRES" "$cur_expiry_display"
        tdz_kv2 "PASS" "$cur_pass" "CONNS" "$cur_connections"
        tdz_kv2 "USED" "$bw_used_display" "LIMIT" "$cur_bw_display"
        tdz_box_divider
        tdz_menu1 "[ 1]" "Change Username"
        tdz_menu1 "[ 2]" "Change Password"
        if $pending_first_use; then
            tdz_menu1 "[ 3]" "Change Validity After First Use"
        else
            tdz_menu1 "[ 3]" "Change Validity from Today"
        fi
        tdz_menu1 "[ 4]" "Change Connection Limit"
        tdz_menu1 "[ 5]" "Change Bandwidth Limit"
        tdz_menu1 "[ 6]" "Reset Bandwidth Counter"
        tdz_box_divider
        tdz_menu1 "[ 0]" "Finish Editing"
        tdz_box_bot
        echo
        if ! read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" edit_choice; then
            echo
            return
        fi
        case $edit_choice in
            1)
               local new_username
               read -r -p "  Enter new username: " new_username
               if rename_tdztunnel_user "$username" "$new_username"; then
                   username="$new_username"
               fi
               ;;
            2)
               local new_pass=""
               read -p "  Enter new password (or press Enter for auto-generated): " new_pass
               if [[ -z "$new_pass" ]]; then
                   new_pass=$(head /dev/urandom | tr -dc 'A-Za-z0-9' | head -c 8)
                   echo -e "${C_GREEN}Auto-generated: ${C_YELLOW}$new_pass${C_RESET}"
               fi
               echo "$username:$new_pass" | chpasswd
                sed -i "s/^$username:.*/$username:$new_pass:$cur_expiry:$cur_limit:$cur_bw$cur_metadata_suffix/" "$DB_FILE"
               echo -e "\n${C_GREEN}[OK] Password for '$username' changed to: ${C_YELLOW}$new_pass${C_RESET}"
               ;;
            3)
               if $pending_first_use; then
                   read -r -p "  Validity after first use (days) [${pending_validity_days}]: " days
                   days=${days:-$pending_validity_days}
                   if [[ "$days" =~ ^[1-9][0-9]*$ ]]; then
                       if db_set_pending_validity "$username" "$days"; then
                           echo -e "\n${C_GREEN}[OK] '$username' will remain pending and expire ${C_YELLOW}${days} days after first use${C_RESET}."
                       else
                           echo -e "\n${C_RED}[ERROR] Pending validity could not be updated. The account may have activated already.${C_RESET}"
                       fi
                   else
                       echo -e "\n${C_RED}[ERROR] Validity must be at least 1 day.${C_RESET}"
                   fi
               else
                   read -r -p "  Validity from today (days) [30]: " days
                   days=${days:-30}
                   if [[ "$days" =~ ^[1-9][0-9]*$ ]]; then
                       local new_expire_date; new_expire_date=$(date -d "+$days days" +%Y-%m-%d)
                       chage -E "$new_expire_date" "$username"
                       sed -i "s/^$username:.*/$username:$cur_pass:$new_expire_date:$cur_limit:$cur_bw$cur_metadata_suffix/" "$DB_FILE"
                       echo -e "\n${C_GREEN}[OK] Validity for '$username' set to ${C_YELLOW}${days} days from today${C_RESET} (${new_expire_date})."
                   else
                       echo -e "\n${C_RED}[ERROR] Validity must be at least 1 day.${C_RESET}"
                   fi
               fi
               ;;
            4) read -p "  Enter new simultaneous connection limit: " new_limit
               if [[ "$new_limit" =~ ^[0-9]+$ ]]; then
                    sed -i "s/^$username:.*/$username:$cur_pass:$cur_expiry:$new_limit:$cur_bw$cur_metadata_suffix/" "$DB_FILE"
                   echo -e "\n${C_GREEN}[OK] Connection limit for '$username' set to ${C_YELLOW}$new_limit${C_RESET}."
               else echo -e "\n${C_RED}[ERROR] Invalid limit.${C_RESET}"; fi ;;
            5) read -p "  Enter new bandwidth limit in GB (0 = unlimited): " new_bw
               if [[ "$new_bw" =~ ^[0-9]+\.?[0-9]*$ ]]; then
                    sed -i "s/^$username:.*/$username:$cur_pass:$cur_expiry:$cur_limit:$new_bw$cur_metadata_suffix/" "$DB_FILE"
                   local bw_msg; bw_msg=$(tdz_format_quota_gb "$new_bw")
                   echo -e "\n${C_GREEN}[OK] Bandwidth limit for '$username' set to ${C_YELLOW}$bw_msg${C_RESET}."
                   # Unlock user if they were locked due to bandwidth
                   if tdz_quota_is_unlimited "$new_bw" || [[ -f "$BANDWIDTH_DIR/${username}.usage" ]]; then
                       local used_bytes; used_bytes=$(cat "$BANDWIDTH_DIR/${username}.usage" 2>/dev/null || echo 0)
                       local new_quota_bytes; new_quota_bytes=$(awk "BEGIN {printf \"%.0f\", $new_bw * 1073741824}")
                       if tdz_quota_is_unlimited "$new_bw" || [[ "$used_bytes" -lt "$new_quota_bytes" ]]; then
                           usermod -U "$username" &>/dev/null
                       fi
                   fi
               else echo -e "\n${C_RED}[ERROR] Invalid bandwidth value.${C_RESET}"; fi ;;
            6)
               echo "0" > "$BANDWIDTH_DIR/${username}.usage"
               # Unlock user if they were locked due to bandwidth
               usermod -U "$username" &>/dev/null
               echo -e "\n${C_GREEN}[OK] Bandwidth counter for '$username' has been reset to 0.${C_RESET}"
               ;;
            0) return ;;
            *) echo -e "\n${C_RED}[ERROR] Invalid option.${C_RESET}" ;;
        esac
        echo -e "\nPress ${C_YELLOW}[Enter]${C_RESET} to continue editing..." && read -r || return
    done
}

lock_user() {
    _select_multi_user_interface "LOCK ACCOUNTS"
    if [[ ${#SELECTED_USERS[@]} -eq 0 || "${SELECTED_USERS[0]}" == "NO_USERS" ]]; then return; fi
    
    echo -e "\n${C_BLUE}Locking selected users...${C_RESET}"
    for u in "${SELECTED_USERS[@]}"; do
        if ! id "$u" &>/dev/null; then
             echo -e " [ERROR] User '${C_YELLOW}$u${C_RESET}' does not exist on this system."
             continue
        fi
        
        usermod -L "$u"
        if [ $? -eq 0 ]; then
            killall -u "$u" -9 &>/dev/null
            echo -e " [OK] ${C_YELLOW}$u${C_RESET} locked and active sessions killed."
        else
            echo -e " [ERROR] Failed to lock ${C_YELLOW}$u${C_RESET}."
        fi
    done
}

unlock_user() {
    _select_multi_user_interface "UNLOCK ACCOUNTS"
    if [[ ${#SELECTED_USERS[@]} -eq 0 || "${SELECTED_USERS[0]}" == "NO_USERS" ]]; then return; fi
    
    echo -e "\n${C_BLUE}Unlocking selected users...${C_RESET}"
    for u in "${SELECTED_USERS[@]}"; do
        if ! id "$u" &>/dev/null; then
             echo -e " [ERROR] User '${C_YELLOW}$u${C_RESET}' does not exist on this system."
             continue
        fi
        
        usermod -U "$u"
        if [ $? -eq 0 ]; then
            echo -e " [OK] ${C_YELLOW}$u${C_RESET} unlocked."
        else
            echo -e " [ERROR] Failed to unlock ${C_YELLOW}$u${C_RESET}."
        fi
    done
}

list_users() {
    clear; show_banner
    local user_total=0
    if [[ -s "$DB_FILE" ]]; then
        user_total=$(awk -F: 'NF && $1 !~ /^#/ { count++ } END { print count + 0 }' "$DB_FILE")
    fi

    echo
    tdz_box_top
    tdz_box_header "MANAGED USERS"
    tdz_box_divider

    if (( user_total == 0 )); then
        tdz_row "${C_YELLOW}[INFO] No users are currently being managed.${C_RESET}"
        tdz_box_bot
        return
    fi

    local current_ts
    current_ts=$(date +%s)
    local -A system_user_lookup=()
    local -A locked_user_lookup=()
    local user_count=0 active_count=0 pending_count=0 attention_count=0
    local first_account=true

    while IFS=: read -r system_user _rest; do
        [[ -n "$system_user" ]] && system_user_lookup["$system_user"]=1
    done < /etc/passwd

    while read -r passwd_user passwd_status _rest; do
        [[ -z "$passwd_user" ]] && continue
        if [[ "$passwd_status" == "L" ]]; then
            locked_user_lookup["$passwd_user"]=1
        fi
    done < <(passwd -Sa 2>/dev/null)
    refresh_ssh_session_cache

    while IFS=: read -r user _password expiry limit bandwidth_gb account_type metadata_value _rest; do
        [[ -n "$user" && "$user" != \#* ]] || continue
        user_count=$((user_count + 1))

        local online_count="${SSH_SESSION_COUNTS[$user]:-0}"
        local connection_string="$online_count/${limit:-1}"
        local plain_status="ACTIVE" status_color="$C_GREEN"
        local quota_exceeded=false
        local pending_activation=false
        local used_bytes=0 data_display
        local expiry_display expiry_check=0 time_left="Unknown"
        local account_number display_user

        if ! [[ "$bandwidth_gb" =~ ^[0-9]+\.?[0-9]*$ ]]; then
            bandwidth_gb="0"
        fi
        if [[ -f "$BANDWIDTH_DIR/${user}.usage" ]]; then
            used_bytes=$(cat "$BANDWIDTH_DIR/${user}.usage" 2>/dev/null)
            [[ "$used_bytes" =~ ^[0-9]+$ ]] || used_bytes=0
        fi
        data_display=$(tdz_format_bandwidth_usage "$used_bytes" "$bandwidth_gb")
        if ! tdz_quota_is_unlimited "$bandwidth_gb"; then
            local quota_bytes
            quota_bytes=$(awk "BEGIN {printf \"%.0f\", $bandwidth_gb * 1073741824}")
            if [[ "$quota_bytes" =~ ^[0-9]+$ ]] && (( used_bytes >= quota_bytes )); then
                quota_exceeded=true
            fi
        fi

        if [[ "$account_type" == "pending" && "$metadata_value" =~ ^[1-9][0-9]*$ ]]; then
            pending_activation=true
            expiry_display="First use"
            time_left="${metadata_value}d after use"
        elif [[ "$account_type" == "trial" && "$metadata_value" =~ ^[0-9]+$ ]] &&
           (( metadata_value > 0 )); then
            expiry_display=$(LC_TIME=C date -d "@${metadata_value}" '+%d %b %Y • %H:%M' 2>/dev/null || echo "$expiry")
            expiry_check=$metadata_value
        elif [[ -n "$expiry" && "$expiry" != "Never" ]]; then
            expiry_display=$(LC_TIME=C date -d "$expiry" '+%d %b %Y' 2>/dev/null || echo "$expiry")
            expiry_check=$(date -d "$expiry" +%s 2>/dev/null || echo 0)
        else
            expiry_display="${expiry:-Unknown}"
        fi

        if $pending_activation; then
            :
        elif [[ "$expiry" == "Never" || -z "$expiry" ]]; then
            time_left="Never"
        elif [[ "$expiry_check" =~ ^[0-9]+$ ]] && (( expiry_check > 0 )); then
            time_left=$(format_trial_time_left "$expiry_check")
        fi

        if [[ -z "${system_user_lookup[$user]+x}" ]]; then
            plain_status="MISSING"
            status_color="$C_RED"
        elif [[ "$expiry_check" =~ ^[0-9]+$ ]] &&
             (( expiry_check > 0 && expiry_check < current_ts )); then
            plain_status="EXPIRED"
            status_color="$C_RED"
        elif $pending_activation; then
            plain_status="PENDING"
            status_color="$C_CYAN"
        fi

        if [[ ( "$plain_status" == "ACTIVE" || "$plain_status" == "PENDING" ) && "$quota_exceeded" == true ]]; then
            if [[ -n "${locked_user_lookup[$user]+x}" ]]; then
                plain_status="BW LOCKED"
            else
                plain_status="QUOTA EXCEEDED"
            fi
            status_color="$C_RED"
        elif [[ ( "$plain_status" == "ACTIVE" || "$plain_status" == "PENDING" ) && -n "${locked_user_lookup[$user]+x}" ]]; then
            plain_status="LOCKED"
            status_color="$C_YELLOW"
        fi

        if [[ "$plain_status" == "ACTIVE" ]]; then
            active_count=$((active_count + 1))
        elif [[ "$plain_status" == "PENDING" ]]; then
            pending_count=$((pending_count + 1))
        else
            attention_count=$((attention_count + 1))
        fi

        if [[ "$first_account" != true ]]; then
            tdz_box_divider
        fi
        first_account=false

        printf -v account_number "%02d" "$user_count"
        display_user="$user"
        if (( ${#display_user} > 22 )); then
            display_user="${display_user:0:19}..."
        fi
        expiry_display=$(_tdz_fit "$expiry_display" 20)
        time_left=$(_tdz_fit "$time_left" 20)
        connection_string=$(_tdz_fit "$connection_string" 20)
        data_display=$(_tdz_fit "$data_display" 20)

        tdz_row2 "${C_CHOICE}[${account_number}]${C_RESET} ${C_BOLD}${C_WHITE}${display_user}${C_RESET}" \
            "${status_color}${C_BOLD}[ ${plain_status} ]${C_RESET}"
        tdz_kv2 "EXPIRES" "$expiry_display" "LEFT" "$time_left"
        tdz_kv2 "CONNS" "$connection_string" "DATA" "$data_display"
    done < <(sort "$DB_FILE")

    tdz_box_divider
    tdz_row2 "${C_GRAY}TOTAL${C_RESET} ${C_BOLD}${C_WHITE}${user_count}${C_RESET}" \
        "${C_GREEN}ACTIVE ${active_count}${C_RESET} ${C_GRAY}/${C_RESET} ${C_CYAN}PENDING ${pending_count}${C_RESET}"
    if (( attention_count > 0 )); then
        tdz_row2 "" "${C_YELLOW}ATTENTION ${attention_count}${C_RESET}"
    fi
    tdz_box_bot
}

renew_user() {
    _select_multi_user_interface "RENEW ACCOUNTS"
    if [[ ${#SELECTED_USERS[@]} -eq 0 || "${SELECTED_USERS[0]}" == "NO_USERS" ]]; then return; fi
    read -p "  Enter number of days to extend the account(s): " days; if ! [[ "$days" =~ ^[1-9][0-9]*$ ]]; then echo -e "\n${C_RED}[ERROR] Days must be at least 1.${C_RESET}"; return; fi
    local new_expire_date; new_expire_date=$(date -d "+$days days" +%Y-%m-%d)
    
    echo -e "\n${C_BLUE}Renewing selected users for $days days...${C_RESET}"
    for u in "${SELECTED_USERS[@]}"; do
        local line record_user pass expiry limit bw account_type metadata_value metadata_rest
        line=$(grep "^$u:" "$DB_FILE")
        IFS=: read -r record_user pass expiry limit bw account_type metadata_value metadata_rest <<< "$line"
        [[ -z "$bw" ]] && bw="0"
        if [[ "$account_type" == "pending" && "$metadata_value" =~ ^[1-9][0-9]*$ ]]; then
            local extended_pending_days=$((metadata_value + days))
            chage -E -1 "$u"
            sed -i "s/^$u:.*/$u:$pass:Never:$limit:$bw:pending:$extended_pending_days/" "$DB_FILE"
            echo -e " [OK] ${C_YELLOW}$u${C_RESET} will remain valid for ${C_GREEN}${extended_pending_days} days${C_RESET} after first use."
        else
            local metadata_suffix=""
            [[ -n "$account_type" ]] && metadata_suffix=":$account_type"
            [[ -n "$metadata_value" ]] && metadata_suffix+=":$metadata_value"
            [[ -n "$metadata_rest" ]] && metadata_suffix+=":$metadata_rest"
            chage -E "$new_expire_date" "$u"
            sed -i "s/^$u:.*/$u:$pass:$new_expire_date:$limit:$bw$metadata_suffix/" "$DB_FILE"
            echo -e " [OK] ${C_YELLOW}$u${C_RESET} renewed until ${C_GREEN}${new_expire_date}${C_RESET}."
        fi
    done
}

cleanup_expired() {
    clear; show_banner
    tdz_screen_title "CLEANUP EXPIRED USERS" "Find and remove accounts whose expiry date has passed."
    
    local expired_users=()
    local current_ts
    current_ts=$(date +%s)

    if [[ ! -s "$DB_FILE" ]]; then
        echo -e "\n${C_GREEN}[OK] User database is empty. No expired users found.${C_RESET}"
        return
    fi
    
    while IFS=: read -r user pass expiry limit bandwidth_gb _extra; do
        local expiry_ts
        expiry_ts=$(date -d "$expiry" +%s 2>/dev/null || echo 0)
        
        if [[ $expiry_ts -lt $current_ts && $expiry_ts -ne 0 ]]; then
            expired_users+=("$user")
        fi
    done < "$DB_FILE"

    if [ ${#expired_users[@]} -eq 0 ]; then
        echo -e "\n${C_GREEN}[OK] No expired users found.${C_RESET}"
        return
    fi

    echo -e "\nThe following users have expired: ${C_RED}${expired_users[*]}${C_RESET}"
    read -p "  Do you want to delete all of them? (y/n): " confirm

    if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
        for user in "${expired_users[@]}"; do
            echo -e "  ${C_GRAY}•${C_RESET} Deleting ${C_YELLOW}$user${C_RESET}..."
            killall -u "$user" -9 &>/dev/null
            # Clean up bandwidth tracking
            rm -f "$BANDWIDTH_DIR/${user}.usage"
            rm -rf "$BANDWIDTH_DIR/pidtrack/${user}"
            userdel -r "$user" &>/dev/null
            sed -i "/^$user:/d" "$DB_FILE"
        done
        echo -e "\n${C_GREEN}[OK] Expired users have been cleaned up.${C_RESET}"
        invalidate_banner_cache
        refresh_dynamic_banner_routing_if_enabled
    else
        tdz_message CANCELLED "Cleanup cancelled."
    fi
}


create_user_backup_archive() {
    local backup_path="$1"
    if [ ! -d "$DB_DIR" ] || [ ! -s "$DB_FILE" ]; then
        return 2
    fi
    local temp_dir backup_root locks_file
    temp_dir=$(mktemp -d)
    backup_root="$temp_dir/tdz-user-data"
    locks_file="$backup_root/locks.db"

    mkdir -p "$(dirname "$backup_path")" "$backup_root/bandwidth"
    cp "$DB_FILE" "$backup_root/users.db"

    if [ -d "$BANDWIDTH_DIR" ]; then
        cp "$BANDWIDTH_DIR"/*.usage "$backup_root/bandwidth/" 2>/dev/null || true
    fi

    : > "$locks_file"
    while IFS=: read -r user _pass _expiry _limit _bandwidth_gb _extra; do
        [[ -z "$user" || "$user" == \#* ]] && continue
        local passwd_status="missing"
        if id "$user" &>/dev/null; then
            passwd_status=$(passwd -S "$user" 2>/dev/null | awk '{print $2}')
            [[ "$passwd_status" == "L" ]] && passwd_status="locked" || passwd_status="unlocked"
        fi
        printf '%s:%s\n' "$user" "$passwd_status" >> "$locks_file"
    done < "$DB_FILE"

    cat > "$backup_root/meta.txt" <<EOF
format=tdz-user-data
version=1
created_at=$(date '+%Y-%m-%d %H:%M:%S %z')
EOF

    tar -czf "$backup_path" -C "$temp_dir" "tdz-user-data"
    local rc=$?
    rm -rf "$temp_dir"
    return "$rc"
}

backup_user_data() {
    clear; show_banner
    tdz_screen_title "BACKUP USER DATA" "Create a portable archive of accounts and usage data."
    read -p "  Enter path for backup file [/root/tdztunnel_users.tar.gz]: " backup_path
    backup_path=${backup_path:-/root/tdztunnel_users.tar.gz}
    create_user_backup_archive "$backup_path"
    local rc=$?
    if [ "$rc" -ne 0 ]; then
        if [ "$rc" -eq 2 ]; then
            echo -e "\n${C_YELLOW}[INFO] No user data found to back up.${C_RESET}"
        else
            echo -e "\n${C_RED}[ERROR] Backup failed.${C_RESET}"
        fi
        return
    fi
    echo -e "\n${C_GREEN}[OK] User data backup created at ${C_YELLOW}$backup_path${C_RESET}"
}

restore_user_data() {
    clear; show_banner
    tdz_screen_title "RESTORE USER DATA" "Restore accounts, limits, expiry dates, and usage data."
    read -p "  Enter the full path to the user data backup file [/root/tdztunnel_users.tar.gz]: " backup_path
    backup_path=${backup_path:-/root/tdztunnel_users.tar.gz}
    if [ ! -f "$backup_path" ]; then
        echo -e "\n${C_RED}[ERROR] Backup file not found at '$backup_path'.${C_RESET}"
        return
    fi
    echo -e "\n${C_RED}${C_BOLD}[WARNING]${C_RESET} This will overwrite all current users and settings."
    echo -e "It will restore user accounts, passwords, limits, and expiration dates from the backup file."
    read -p "  Are you absolutely sure you want to proceed? (y/n): " confirm
    if [[ "$confirm" != "y" ]]; then tdz_message CANCELLED "Restore cancelled."; return; fi
    local temp_dir
    temp_dir=$(mktemp -d)
    echo -e "\n${C_BLUE}Extracting backup file to a temporary location...${C_RESET}"
    tar -xzf "$backup_path" -C "$temp_dir"
    if [ $? -ne 0 ]; then
        echo -e "\n${C_RED}[ERROR] Failed to extract backup file. Aborting.${C_RESET}"
        rm -rf "$temp_dir"
        return
    fi
    local restore_root="$temp_dir/tdz-user-data"
    if [ ! -f "$restore_root/users.db" ]; then
        # Backward compatibility: old full-folder backups are accepted, but only
        # user-related data is restored from them.
        restore_root="$temp_dir/tdztunnel"
    fi
    local restored_db_file="$restore_root/users.db"
    if [ ! -f "$restored_db_file" ]; then
        echo -e "\n${C_RED}[ERROR] users.db not found in the backup. Cannot restore user accounts.${C_RESET}"
        rm -rf "$temp_dir"
        return
    fi
    echo -e "${C_BLUE}Overwriting current user database and usage data...${C_RESET}"
    mkdir -p "$DB_DIR"
    cp "$restored_db_file" "$DB_FILE"
    mkdir -p "$BANDWIDTH_DIR"
    rm -f "$BANDWIDTH_DIR"/*.usage 2>/dev/null || true
    if [ -d "$restore_root/bandwidth" ]; then
        cp "$restore_root/bandwidth"/*.usage "$BANDWIDTH_DIR/" 2>/dev/null || true
    fi
    
    echo -e "${C_BLUE}Re-synchronizing system accounts with the restored database...${C_RESET}"
    ensure_tdztunnel_system_group
    
    while IFS=: read -r user pass expiry limit bandwidth_gb _extra; do
        echo -e "\n  ${C_GRAY}•${C_RESET} Account: ${C_YELLOW}$user${C_RESET}"
        if ! id "$user" &>/dev/null; then
            echo -e "    ${C_GRAY}System user:${C_RESET} Creating"
            useradd -m -s /usr/sbin/nologin "$user"
        else
            echo -e "    ${C_GRAY}System user:${C_RESET} Existing"
        fi
        usermod -aG "$TDZ_USERS_GROUP" "$user" 2>/dev/null
        echo -e "    ${C_GRAY}Password:${C_RESET} Restored"
        echo "$user:$pass" | chpasswd
        echo -e "    ${C_GRAY}Expiration:${C_RESET} ${expiry}"
        if [[ "$expiry" == "Never" || -z "$expiry" ]]; then
            chage -E -1 "$user"
        else
            chage -E "$expiry" "$user"
        fi
        echo -e "    ${C_GRAY}Connections:${C_RESET} ${limit} (account worker)"
    done < "$DB_FILE"

    if [ -f "$restore_root/locks.db" ]; then
        echo -e "${C_BLUE}Restoring account lock states...${C_RESET}"
        while IFS=: read -r lock_user lock_state _extra; do
            [[ -z "$lock_user" || "$lock_user" == \#* ]] && continue
            id "$lock_user" &>/dev/null || continue
            case "$lock_state" in
                locked) usermod -L "$lock_user" 2>/dev/null ;;
                unlocked) usermod -U "$lock_user" 2>/dev/null ;;
            esac
        done < "$restore_root/locks.db"
    fi
    rm -rf "$temp_dir"
    echo -e "\n${C_GREEN}[OK] User data restore completed.${C_RESET}"
    
    invalidate_banner_cache
    refresh_dynamic_banner_routing_if_enabled
}

auto_backup_load_conf() {
    if [ ! -f "$AUTO_BACKUP_CONF" ]; then
        return 1
    fi
    source "$AUTO_BACKUP_CONF" 2>/dev/null
    [[ -n "${BOT_TOKEN:-}" && -n "${CHAT_ID:-}" && -n "${INTERVAL_SECONDS:-}" ]] || return 1
    return 0
}

auto_backup_save_conf() {
    local bot_token="$1" chat_id="$2" interval_seconds="$3" interval_label="$4"
    printf 'BOT_TOKEN=%q\nCHAT_ID=%q\nINTERVAL_SECONDS=%q\nINTERVAL_LABEL=%q\n' \
        "$bot_token" "$chat_id" "$interval_seconds" "$interval_label" > "$AUTO_BACKUP_CONF"
    chmod 600 "$AUTO_BACKUP_CONF"
}

auto_backup_ensure_pm2() {
    if command -v pm2 &>/dev/null; then
        return 0
    fi
    echo -e "\n${C_BLUE}Installing Node.js and PM2...${C_RESET}"
    tdz_apt_install nodejs npm >/dev/null 2>&1 || {
        echo -e "${C_RED}Failed to install nodejs/npm.${C_RESET}"
        return 1
    }
    npm install -g pm2 >/dev/null 2>&1 || {
        echo -e "${C_RED}Failed to install PM2.${C_RESET}"
        return 1
    }
    pm2 startup systemd -u root --hp /root >/dev/null 2>&1 || true
    return 0
}

auto_backup_write_worker() {
    cat > "$AUTO_BACKUP_SCRIPT" << 'WORKER_EOF'
#!/usr/bin/env bash
set -uo pipefail
CONF="/etc/tdztunnel-auto-backup-bot.conf"
DB_DIR="/etc/tdztunnel"
DB_FILE="$DB_DIR/users.db"
BW_DIR="$DB_DIR/bandwidth"
BACKUP_DIR="/root/tdztunnel-auto-backups"
LAST_FILE="$BACKUP_DIR/last-backup.tar.gz"
LOG_FILE="/var/log/tdztunnel-auto-backup.log"
DOWNLOAD_DIR="/tmp/tdz-restore-downloads"
USERS_GROUP="tdzusers"
API="https://api.telegram.org/bot"
OFFSET=0
RESTORE_STATE="IDLE"
RESTORE_FILE=""
CONFIRM_MSG_ID=""
LAST_AUTO_BACKUP=0

log_msg() { echo "[$(date '+%Y-%m-%d %H:%M:%S')] $*" >> "$LOG_FILE"; }

if [ ! -f "$CONF" ]; then
    log_msg "ERROR: Config not found. Exiting."
    exit 1
fi
source "$CONF" 2>/dev/null
if [ -z "${BOT_TOKEN:-}" ] || [ -z "${CHAT_ID:-}" ] || [ -z "${INTERVAL_SECONDS:-}" ]; then
    log_msg "ERROR: Invalid config. Exiting."
    exit 1
fi

log_msg "Auto-backup bot started. Interval: ${INTERVAL_LABEL:-unknown}"

tg_send() {
    curl -s -o /dev/null \
        -d "chat_id=$CHAT_ID" \
        --data-urlencode "text=$1" \
        "${API}${BOT_TOKEN}/sendMessage" 2>>"$LOG_FILE"
}

tg_send_keyboard() {
    local kb='{"keyboard":[["\ud83d\udcbe Backup Now","\ud83d\udce5 Restore Backup"]],"resize_keyboard":true}'
    curl -s -o /dev/null \
        -d "chat_id=$CHAT_ID" \
        --data-urlencode "text=$1" \
        --data-urlencode "reply_markup=$kb" \
        "${API}${BOT_TOKEN}/sendMessage" 2>>"$LOG_FILE"
}

tg_send_inline() {
    curl -s \
        -d "chat_id=$CHAT_ID" \
        --data-urlencode "text=$1" \
        --data-urlencode "reply_markup=$2" \
        "${API}${BOT_TOKEN}/sendMessage" 2>>"$LOG_FILE" | jq -r '.result.message_id // empty'
}

tg_edit_inline() {
    curl -s \
        -d "chat_id=$1" \
        -d "message_id=$2" \
        --data-urlencode "text=$3" \
        --data-urlencode "reply_markup=$4" \
        "${API}${BOT_TOKEN}/editMessageText" 2>>"$LOG_FILE"
}

tg_answer_callback() {
    curl -s -o /dev/null \
        -d "callback_query_id=$1" \
        --data-urlencode "text=$2" \
        "${API}${BOT_TOKEN}/answerCallbackQuery" 2>>"$LOG_FILE"
}

tg_send_document() {
    curl -s -o /dev/null -w '%{http_code}' \
        -F "chat_id=$CHAT_ID" \
        -F "document=@$1" \
        -F "caption=$2" \
        "${API}${BOT_TOKEN}/sendDocument" 2>>"$LOG_FILE"
}

create_user_data_archive() {
    local archive="$1"
    local temp_dir root locks_file
    temp_dir=$(mktemp -d)
    root="$temp_dir/tdz-user-data"
    locks_file="$root/locks.db"

    mkdir -p "$(dirname "$archive")" "$root/bandwidth"
    cp "$DB_FILE" "$root/users.db"
    cp "$BW_DIR"/*.usage "$root/bandwidth/" 2>/dev/null || true

    : > "$locks_file"
    while IFS=: read -r user _pass _expiry _limit _bandwidth_gb _extra; do
        [ -z "$user" ] && continue
        state="missing"
        if id "$user" &>/dev/null; then
            state=$(passwd -S "$user" 2>/dev/null | awk '{print $2}')
            [ "$state" = "L" ] && state="locked" || state="unlocked"
        fi
        printf '%s:%s\n' "$user" "$state" >> "$locks_file"
    done < "$DB_FILE"

    cat > "$root/meta.txt" <<META_EOF
format=tdz-user-data
version=1
created_at=$(date '+%Y-%m-%d %H:%M:%S %z')
META_EOF

    tar -czf "$archive" -C "$temp_dir" "tdz-user-data" 2>>"$LOG_FILE"
    rc=$?
    rm -rf "$temp_dir"
    return "$rc"
}

do_backup() {
    if [ ! -d "$DB_DIR" ] || [ ! -s "$DB_FILE" ]; then
        tg_send "No user data found to backup."
        return 1
    fi
    local ts archive
    ts=$(date '+%Y%m%d-%H%M%S')
    archive="$BACKUP_DIR/backup-$ts.tar.gz"
    mkdir -p "$BACKUP_DIR"
    if ! create_user_data_archive "$archive"; then
        tg_send "Failed to create backup archive."
        return 1
    fi
    cp -f "$archive" "$LAST_FILE" 2>/dev/null
    mapfile -t oldfiles < <(find "$BACKUP_DIR" -maxdepth 1 -name 'backup-*.tar.gz' -printf '%T@ %p\n' 2>/dev/null | sort -rn | awk '{print $2}')
    count=0
    for f in "${oldfiles[@]}"; do
        ((count++))
        (( count > 5 )) && rm -f "$f" 2>/dev/null
    done
    local hc
    hc=$(tg_send_document "$archive" "TDZ Backup - $(date '+%Y-%m-%d %H:%M:%S')")
    if [ "$hc" = "200" ]; then
        log_msg "Backup sent: $archive"
        tg_send "Backup sent successfully!"
    else
        log_msg "ERROR: Send failed (HTTP $hc)"
        tg_send "Failed to send backup (HTTP $hc)."
    fi
}

do_restore() {
    local backup_file="$1"
    if [ ! -f "$backup_file" ]; then
        tg_send "Backup file not found."
        return 1
    fi
    if [ -d "$DB_DIR" ] && [ -s "$DB_FILE" ]; then
        local pre="$BACKUP_DIR/pre-restore-$(date '+%Y%m%d-%H%M%S').tar.gz"
        mkdir -p "$BACKUP_DIR"
        create_user_data_archive "$pre" >/dev/null 2>&1
        log_msg "Pre-restore backup: $pre"
    fi
    tg_send "Restoring backup... Please wait."
    local temp_dir
    temp_dir=$(mktemp -d)
    if ! tar -xzf "$backup_file" -C "$temp_dir" 2>>"$LOG_FILE"; then
        tg_send "Failed to extract backup file. Restore aborted."
        rm -rf "$temp_dir"
        return 1
    fi
    local restore_root="$temp_dir/tdz-user-data"
    if [ ! -f "$restore_root/users.db" ]; then
        restore_root="$temp_dir/tdztunnel"
    fi
    local restored_db="$restore_root/users.db"
    if [ ! -f "$restored_db" ]; then
        tg_send "users.db not found in backup. Cannot restore."
        rm -rf "$temp_dir"
        return 1
    fi
    mkdir -p "$DB_DIR"
    cp "$restored_db" "$DB_FILE"
    log_msg "users.db restored"
    mkdir -p "$BW_DIR"
    rm -f "$BW_DIR"/*.usage 2>/dev/null || true
    [ -d "$restore_root/bandwidth" ] && cp "$restore_root/bandwidth"/*.usage "$BW_DIR/" 2>/dev/null || true
    getent group "$USERS_GROUP" >/dev/null 2>&1 || groupadd "$USERS_GROUP"
    local uc=0
    while IFS=: read -r user pass expiry limit bandwidth_gb _extra; do
        [ -z "$user" ] && continue
        uc=$((uc + 1))
        if ! id "$user" &>/dev/null; then
            useradd -m -s /usr/sbin/nologin "$user" 2>/dev/null
            log_msg "Created user: $user"
        fi
        usermod -aG "$USERS_GROUP" "$user" 2>/dev/null
        echo "$user:$pass" | chpasswd 2>/dev/null
        if [[ "$expiry" == "Never" || -z "$expiry" ]]; then
            chage -E -1 "$user" 2>/dev/null
        else
            chage -E "$expiry" "$user" 2>/dev/null
        fi
        log_msg "Restored user: $user"
    done < "$DB_FILE"
    if [ -f "$restore_root/locks.db" ]; then
        while IFS=: read -r lock_user lock_state _extra; do
            [ -z "$lock_user" ] && continue
            id "$lock_user" &>/dev/null || continue
            case "$lock_state" in
                locked) usermod -L "$lock_user" 2>/dev/null ;;
                unlocked) usermod -U "$lock_user" 2>/dev/null ;;
            esac
        done < "$restore_root/locks.db"
    fi
    rm -rf "$temp_dir"
    rm -f /etc/tdztunnel/.banner_cache 2>/dev/null
    tg_send "Restore complete! $uc users restored.

All users re-synced with passwords, expiry, and limits.
Server services may need restart for full effect."
    log_msg "Restore complete. $uc users processed."
    return 0
}

check_auto_backup() {
    local now
    now=$(date +%s)
    if (( now - LAST_AUTO_BACKUP >= INTERVAL_SECONDS )); then
        LAST_AUTO_BACKUP=$now
        if [ ! -d "$DB_DIR" ] || [ ! -s "$DB_FILE" ]; then
            log_msg "No user data, skipping auto-backup."
            return
        fi
        local ts archive
        ts=$(date '+%Y%m%d-%H%M%S')
        archive="$BACKUP_DIR/backup-$ts.tar.gz"
        mkdir -p "$BACKUP_DIR"
        if ! create_user_data_archive "$archive"; then
            log_msg "ERROR: Auto-backup archive failed."
            return
        fi
        cp -f "$archive" "$LAST_FILE" 2>/dev/null
        mapfile -t oldfiles < <(find "$BACKUP_DIR" -maxdepth 1 -name 'backup-*.tar.gz' -printf '%T@ %p\n' 2>/dev/null | sort -rn | awk '{print $2}')
        count=0
        for f in "${oldfiles[@]}"; do
            ((count++))
            (( count > 5 )) && rm -f "$f" 2>/dev/null
        done
        local hc
        hc=$(tg_send_document "$archive" "TDZ Auto Backup - $(date '+%Y-%m-%d %H:%M:%S')")
        if [ "$hc" = "200" ]; then
            log_msg "Auto-backup sent: $archive"
        else
            log_msg "ERROR: Auto-backup send failed (HTTP $hc)"
        fi
    fi
}

LAST_AUTO_BACKUP=$(date +%s)

while true; do
    check_auto_backup

    updates=$(curl -s --max-time 5 "${API}${BOT_TOKEN}/getUpdates?offset=${OFFSET}&timeout=3" 2>>"$LOG_FILE")
    ok=$(echo "$updates" | jq -r '.ok // empty' 2>/dev/null)
    if [ "$ok" != "true" ]; then
        sleep 2
        continue
    fi

    rc=$(echo "$updates" | jq '.result | length' 2>/dev/null)
    if [ "$rc" = "0" ] || [ -z "$rc" ]; then
        continue
    fi

    for i in $(seq 0 $((rc - 1))); do
        uid=$(echo "$updates" | jq -r ".result[$i].update_id")
        OFFSET=$((uid + 1))

        is_callback=$(echo "$updates" | jq -r ".result[$i].callback_query | if . then \"yes\" else \"no\" end" 2>/dev/null)

        if [ "$is_callback" = "yes" ]; then
            cbid=$(echo "$updates" | jq -r ".result[$i].callback_query.id")
            cbdata=$(echo "$updates" | jq -r ".result[$i].callback_query.data")
            cid=$(echo "$updates" | jq -r ".result[$i].callback_query.message.chat.id // empty")
            log_msg "Callback: $cbdata (state: $RESTORE_STATE)"

            if [ "$cid" != "$CHAT_ID" ]; then
                log_msg "Unauthorized callback: chat_id=$cid"
                continue
            fi

            case "$cbdata" in
                "cb_confirm1")
                    if [ "$RESTORE_STATE" = "CONFIRM_1" ]; then
                        RESTORE_STATE="CONFIRM_2"
                        tg_answer_callback "$cbid" "Step 2/3"
                        kb='{"inline_keyboard":[[{"text":"\u2705 CONFIRM 2","callback_data":"cb_confirm2"}],[{"text":"\u274c Cancel","callback_data":"cb_cancel"}]]}'
                        tg_edit_inline "$CHAT_ID" "$CONFIRM_MSG_ID" "Step 2/3

This will OVERWRITE all current users, passwords, and settings." "$kb"
                    else
                        tg_answer_callback "$cbid" "Not expecting this"
                    fi
                    ;;
                "cb_confirm2")
                    if [ "$RESTORE_STATE" = "CONFIRM_2" ]; then
                        RESTORE_STATE="CONFIRM_3"
                        tg_answer_callback "$cbid" "Step 3/3 - Final"
                        kb='{"inline_keyboard":[[{"text":"\u26a0\ufe0f RESTORE NOW","callback_data":"cb_restore_now"}],[{"text":"\u274c Cancel","callback_data":"cb_cancel"}]]}'
                        tg_edit_inline "$CHAT_ID" "$CONFIRM_MSG_ID" "FINAL WARNING Step 3/3

This is your LAST chance to cancel!

Tap RESTORE NOW to proceed" "$kb"
                    else
                        tg_answer_callback "$cbid" "Not expecting this"
                    fi
                    ;;
                "cb_restore_now")
                    if [ "$RESTORE_STATE" = "CONFIRM_3" ]; then
                        RESTORE_STATE="RESTORING"
                        tg_answer_callback "$cbid" "Restoring..."
                        kb_remove='{"inline_keyboard":[]}'
                        tg_edit_inline "$CHAT_ID" "$CONFIRM_MSG_ID" "Restoring backup... Please wait." "$kb_remove"
                        do_restore "$RESTORE_FILE"
                        RESTORE_STATE="IDLE"
                        RESTORE_FILE=""
                        CONFIRM_MSG_ID=""
                        rm -f "$DOWNLOAD_DIR"/* 2>/dev/null
                    else
                        tg_answer_callback "$cbid" "Not expecting this"
                    fi
                    ;;
                "cb_cancel")
                    RESTORE_STATE="IDLE"
                    RESTORE_FILE=""
                    CONFIRM_MSG_ID=""
                    rm -f "$DOWNLOAD_DIR"/* 2>/dev/null
                    tg_answer_callback "$cbid" "Cancelled"
                    tg_send "Cancelled. Back to normal."
                    ;;
                *)
                    tg_answer_callback "$cbid" "Unknown action"
                    ;;
            esac
            continue
        fi

        mtype=$(echo "$updates" | jq -r ".result[$i].message | if .text then \"text\" elif .document then \"document\" else \"other\" end" 2>/dev/null)
        cid=$(echo "$updates" | jq -r ".result[$i].message.chat.id // empty" 2>/dev/null)

        if [ "$cid" != "$CHAT_ID" ]; then
            log_msg "Unauthorized: chat_id=$cid"
            continue
        fi

        if [ "$mtype" = "text" ]; then
            txt=$(echo "$updates" | jq -r ".result[$i].message.text")
            log_msg "Text: $txt (state: $RESTORE_STATE)"

            case "$txt" in
                "/start"|"/menu"|"Menu"|"menu")
                    RESTORE_STATE="IDLE"
                    tg_send_keyboard "TDZ Backup Bot ready.

Commands:
/backup - Create & send backup
/restore - Restore from file
/status - Show bot status
/cancel - Cancel restore

Auto-backup: ${INTERVAL_LABEL:-unknown}"
                    ;;
                "/backup"|"Backup Now"|*"Backup Now"*)
                    RESTORE_STATE="IDLE"
                    do_backup
                    ;;
                "/restore"|"Restore Backup"|*"Restore Backup"*)
                    RESTORE_STATE="WAITING_FILE"
                    tg_send "Please send the backup .tar.gz file now.

Send the backup file directly to this chat as a document.

Type /cancel to abort."
                    ;;
                "/status"|"Status"|*"Status"*)
                    RESTORE_STATE="IDLE"
                    local_count=$(ls -1 "$BACKUP_DIR"/*.tar.gz 2>/dev/null | wc -l)
                    tg_send "Bot Status
Interval: ${INTERVAL_LABEL:-unknown}
State: $RESTORE_STATE
Archives: $local_count files
Last backup: $(ls -lth "$LAST_FILE" 2>/dev/null | awk '{print $6,$7,$8}')"
                    ;;
                "/cancel"|"cancel"|"Cancel"|*"Cancel"*)
                    RESTORE_STATE="IDLE"
                    RESTORE_FILE=""
                    rm -f "$DOWNLOAD_DIR"/* 2>/dev/null
                    tg_send "Cancelled. Back to normal."
                    ;;
                *)
                    if [ "$RESTORE_STATE" = "WAITING_FILE" ]; then
                        tg_send "Please send the backup .tar.gz file as a document, not text.

Type /cancel to abort."
                    fi
                    ;;
            esac

        elif [ "$mtype" = "document" ]; then
            fid=$(echo "$updates" | jq -r ".result[$i].message.document.file_id")
            fname=$(echo "$updates" | jq -r ".result[$i].message.document.file_name // \"backup.tar.gz\"")

            if [ "$RESTORE_STATE" != "WAITING_FILE" ]; then
                tg_send "Received file: $fname

If you want to restore, use Restore Backup first."
                continue
            fi

            if [[ "$fname" != *.tar.gz && "$fname" != *.tgz ]]; then
                tg_send "File must be a .tar.gz backup file."
                continue
            fi

            mkdir -p "$DOWNLOAD_DIR"
            tg_send "Downloading: $fname ..."

            finfo=$(curl -s "${API}${BOT_TOKEN}/getFile?file_id=${fid}" 2>>"$LOG_FILE")
            fpath=$(echo "$finfo" | jq -r '.result.file_path // empty')

            if [ -z "$fpath" ]; then
                tg_send "Failed to get file path from Telegram."
                continue
            fi

            dl="$DOWNLOAD_DIR/$fname"
            curl -s -o "$dl" "https://api.telegram.org/file/bot${BOT_TOKEN}/${fpath}" 2>>"$LOG_FILE"

            if [ ! -f "$dl" ] || [ ! -s "$dl" ]; then
                tg_send "Failed to download backup file."
                continue
            fi

            if ! tar -tzf "$dl" >/dev/null 2>&1; then
                tg_send "File is not a valid tar.gz archive."
                rm -f "$dl"
                continue
            fi

            RESTORE_FILE="$dl"
            RESTORE_STATE="CONFIRM_1"
            fsize=$(du -h "$dl" | cut -f1)
            kb='{"inline_keyboard":[[{"text":"\u2705 CONFIRM 1","callback_data":"cb_confirm1"}],[{"text":"\u274c Cancel","callback_data":"cb_cancel"}]]}'
            CONFIRM_MSG_ID=$(tg_send_inline "Backup received: $fname ($fsize)

WARNING Step 1/3

This will OVERWRITE all current users and settings!

Tap CONFIRM 1 to continue" "$kb")
        else
            log_msg "Unsupported message type"
        fi
    done
done
WORKER_EOF
    chmod +x "$AUTO_BACKUP_SCRIPT"
}

auto_backup_choose_interval() {
    AUTO_BACKUP_SELECTED_SECONDS=""
    AUTO_BACKUP_SELECTED_LABEL=""

    echo
    tdz_box_top
    tdz_box_header "BACKUP INTERVAL"
    tdz_box_divider
    tdz_menu1 "[ 1]" "Every 10 Minutes"
    tdz_menu1 "[ 2]" "Every 30 Minutes"
    tdz_menu1 "[ 3]" "Every 1 Hour"
    tdz_menu1 "[ 4]" "Every 6 Hours"
    tdz_menu1 "[ 5]" "Every 12 Hours"
    tdz_menu1 "[ 6]" "Every 1 Day"
    tdz_menu1 "[ 7]" "Custom Interval (Minutes)"
    tdz_box_divider
    tdz_menu1 "[ 0]" "Cancel"
    tdz_box_bot
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Select an interval: ${C_RESET}")" int_choice
    case "$int_choice" in
        1) AUTO_BACKUP_SELECTED_SECONDS=600; AUTO_BACKUP_SELECTED_LABEL="10 minutes" ;;
        2) AUTO_BACKUP_SELECTED_SECONDS=1800; AUTO_BACKUP_SELECTED_LABEL="30 minutes" ;;
        3) AUTO_BACKUP_SELECTED_SECONDS=3600; AUTO_BACKUP_SELECTED_LABEL="1 hour" ;;
        4) AUTO_BACKUP_SELECTED_SECONDS=21600; AUTO_BACKUP_SELECTED_LABEL="6 hours" ;;
        5) AUTO_BACKUP_SELECTED_SECONDS=43200; AUTO_BACKUP_SELECTED_LABEL="12 hours" ;;
        6) AUTO_BACKUP_SELECTED_SECONDS=86400; AUTO_BACKUP_SELECTED_LABEL="1 day" ;;
        7)
            local custom_minutes
            read -r -p "  Enter interval in minutes (1-525600): " custom_minutes
            if ! [[ "$custom_minutes" =~ ^[1-9][0-9]*$ ]] || (( custom_minutes > 525600 )); then
                echo -e "\n${C_RED}Invalid interval. Enter 1 to 525600 minutes.${C_RESET}"
                return 1
            fi
            AUTO_BACKUP_SELECTED_SECONDS=$((custom_minutes * 60))
            if (( custom_minutes == 1 )); then
                AUTO_BACKUP_SELECTED_LABEL="1 minute"
            else
                AUTO_BACKUP_SELECTED_LABEL="${custom_minutes} minutes"
            fi
            ;;
        0) echo -e "${C_YELLOW}Cancelled.${C_RESET}"; return 1 ;;
        *) echo -e "\n${C_RED}Invalid choice.${C_RESET}"; return 1 ;;
    esac
    return 0
}

auto_backup_connect_bot() {
    clear; show_banner
    tdz_screen_title "CONNECT TELEGRAM BOT" "Configure automated backups and restore controls."
    read -r -p "  Enter Bot Token: " bot_token
    [[ -z "$bot_token" ]] && { echo -e "\n${C_RED}Token cannot be empty.${C_RESET}"; press_enter; return; }
    read -r -p "  Enter Chat ID: " chat_id
    [[ -z "$chat_id" ]] && { echo -e "\n${C_RED}Chat ID cannot be empty.${C_RESET}"; press_enter; return; }

    echo -e "\n${C_BLUE}Testing bot token...${C_RESET}"
    local test_resp
    test_resp=$(curl -s --max-time 10 "https://api.telegram.org/bot$bot_token/getMe" 2>/dev/null)
    if echo "$test_resp" | grep -q '"ok":true'; then
        local bot_user
        bot_user=$(echo "$test_resp" | grep -o '"username":"[^"]*"' | cut -d'"' -f4)
        echo -e "${C_GREEN}Connected to @${bot_user}${C_RESET}"
    else
        echo -e "${C_RED}Invalid bot token.${C_RESET}"
        press_enter
        return
    fi

    if ! auto_backup_choose_interval; then
        press_enter
        return
    fi
    local interval_seconds="$AUTO_BACKUP_SELECTED_SECONDS"
    local interval_label="$AUTO_BACKUP_SELECTED_LABEL"

    if ! auto_backup_save_conf "$bot_token" "$chat_id" "$interval_seconds" "$interval_label" ||
       ! auto_backup_write_worker; then
        echo -e "\n${C_RED}Could not save the bot configuration.${C_RESET}"
        press_enter
        return
    fi

    echo -e "\n${C_GREEN}Bot connected. Interval: $interval_label${C_RESET}"
    echo -e "${C_YELLOW}Use 'Start Bot' to begin auto-backups.${C_RESET}"
    press_enter
}

auto_backup_edit_interval() {
    clear; show_banner
    tdz_screen_title "EDIT BACKUP INTERVAL" "Change how often automatic backups are sent."
    if ! auto_backup_load_conf; then
        echo -e "${C_RED}Bot not configured. Use 'Connect Bot' first.${C_RESET}"
        press_enter
        return
    fi

    local saved_bot_token="$BOT_TOKEN"
    local saved_chat_id="$CHAT_ID"
    local bot_was_running=false
    echo -e "${C_WHITE}Current interval:${C_RESET} ${C_GREEN}${INTERVAL_LABEL:-unknown}${C_RESET}"

    if ! auto_backup_choose_interval; then
        press_enter
        return
    fi

    pm2 list 2>/dev/null | grep -q "$AUTO_BACKUP_PM2_NAME" && bot_was_running=true
    if ! auto_backup_save_conf "$saved_bot_token" "$saved_chat_id" \
        "$AUTO_BACKUP_SELECTED_SECONDS" "$AUTO_BACKUP_SELECTED_LABEL" ||
       ! auto_backup_write_worker; then
        echo -e "\n${C_RED}[ERROR] Could not save the new backup interval.${C_RESET}"
        press_enter
        return
    fi

    if [[ "$bot_was_running" == true ]]; then
        if pm2 restart "$AUTO_BACKUP_PM2_NAME" --update-env >/dev/null 2>&1; then
            pm2 save >/dev/null 2>&1 || true
            echo -e "\n${C_GREEN}[OK] Interval changed to ${AUTO_BACKUP_SELECTED_LABEL}; the bot was restarted.${C_RESET}"
        else
            echo -e "\n${C_RED}[ERROR] Interval was saved, but the bot could not be restarted.${C_RESET}"
        fi
    else
        echo -e "\n${C_GREEN}[OK] Interval changed to ${AUTO_BACKUP_SELECTED_LABEL}.${C_RESET}"
        echo -e "${C_DIM}The new interval will be used the next time the bot starts.${C_RESET}"
    fi
    press_enter
}

auto_backup_start() {
    clear; show_banner
    tdz_screen_title "START BACKUP BOT"
    if ! auto_backup_load_conf; then
        echo -e "${C_RED}Bot not configured. Use 'Connect Bot' first.${C_RESET}"
        press_enter; return
    fi
    auto_backup_ensure_pm2 || { press_enter; return; }
    auto_backup_write_worker
    pm2 delete "$AUTO_BACKUP_PM2_NAME" >/dev/null 2>&1 || true
    pm2 start "$AUTO_BACKUP_SCRIPT" --name "$AUTO_BACKUP_PM2_NAME" >/dev/null 2>&1
    pm2 save >/dev/null 2>&1
    echo -e "${C_GREEN}Auto-backup bot started. Interval: ${INTERVAL_LABEL:-unknown}${C_RESET}"
    press_enter
}

auto_backup_stop() {
    clear; show_banner
    tdz_screen_title "STOP BACKUP BOT"
    pm2 delete "$AUTO_BACKUP_PM2_NAME" >/dev/null 2>&1
    pm2 save >/dev/null 2>&1
    echo -e "${C_YELLOW}Auto-backup bot stopped.${C_RESET}"
    press_enter
}

auto_backup_restart() {
    clear; show_banner
    tdz_screen_title "RESTART BACKUP BOT"
    if pm2 list 2>/dev/null | grep -q "$AUTO_BACKUP_PM2_NAME"; then
        pm2 restart "$AUTO_BACKUP_PM2_NAME" >/dev/null 2>&1
        echo -e "${C_GREEN}Bot restarted.${C_RESET}"
    else
        auto_backup_start
        return
    fi
    press_enter
}

auto_backup_reset() {
    clear; show_banner
    tdz_screen_title "RESET BACKUP BOT" "Remove the current bot configuration and process." "$C_DANGER"
    echo -e "${C_RED}This will remove bot config and stop auto-backups.${C_RESET}"
    echo -e "${C_GREEN}Backup archives will be kept.${C_RESET}\n"
    read -r -p "  Are you sure? (y/n): " confirm
    [[ "$confirm" != "y" ]] && { echo -e "\n${C_YELLOW}Cancelled.${C_RESET}"; press_enter; return; }
    pm2 delete "$AUTO_BACKUP_PM2_NAME" >/dev/null 2>&1
    pm2 save >/dev/null 2>&1
    rm -f "$AUTO_BACKUP_CONF"
    rm -f "$AUTO_BACKUP_SCRIPT"
    rm -f "$AUTO_BACKUP_LOG"
    echo -e "\n${C_GREEN}Bot reset complete. Archives preserved.${C_RESET}"
    press_enter
}

auto_backup_send_now() {
    clear; show_banner
    tdz_screen_title "SEND BACKUP NOW"
    if ! auto_backup_load_conf; then
        echo -e "${C_RED}Bot not configured. Use 'Connect Bot' first.${C_RESET}"
        press_enter; return
    fi
    if [ ! -d "$DB_DIR" ] || [ ! -s "$DB_FILE" ]; then
        echo -e "${C_YELLOW}No user data found to back up.${C_RESET}"
        press_enter; return
    fi
    echo -e "${C_BLUE}Creating backup archive...${C_RESET}"
    local ts tmp_archive
    ts=$(date '+%Y%m%d-%H%M%S')
    tmp_archive="$AUTO_BACKUP_DIR/backup-$ts.tar.gz"
    mkdir -p "$AUTO_BACKUP_DIR"
    if ! create_user_backup_archive "$tmp_archive"; then
        echo -e "${C_RED}Failed to create backup archive.${C_RESET}"
        press_enter; return
    fi
    cp -f "$tmp_archive" "$AUTO_BACKUP_LAST_FILE" 2>/dev/null
    echo -e "${C_BLUE}Sending to Telegram...${C_RESET}"
    local http_code
    http_code=$(curl -s -o /dev/null -w '%{http_code}' \
        -F "chat_id=$CHAT_ID" \
        -F "document=@$tmp_archive" \
        -F "caption=TDZ Manual Backup - $(date '+%Y-%m-%d %H:%M:%S')" \
        "https://api.telegram.org/bot$BOT_TOKEN/sendDocument" 2>/dev/null)
    if [ "$http_code" = "200" ]; then
        echo -e "${C_GREEN}Backup sent successfully!${C_RESET}"
    else
        echo -e "${C_RED}Failed to send backup (HTTP $http_code).${C_RESET}"
    fi
    press_enter
}

auto_backup_status() {
    clear; show_banner
    tdz_screen_title "AUTO BACKUP BOT STATUS"
    if auto_backup_load_conf; then
        echo -e "${C_WHITE}Interval:${C_RESET} ${C_GREEN}${INTERVAL_LABEL:-unknown}${C_RESET}"
        echo -e "${C_WHITE}Chat ID:${C_RESET}  ${C_GREEN}$CHAT_ID${C_RESET}"
        echo -e "${C_WHITE}Token:${C_RESET}   ${C_GREEN}$(echo "$BOT_TOKEN" | cut -c1-8)...${C_RESET}"
    else
        echo -e "${C_YELLOW}Bot not configured. Use 'Connect Bot' first.${C_RESET}"
    fi
    echo
    if pm2 list 2>/dev/null | grep -q "$AUTO_BACKUP_PM2_NAME"; then
        echo -e "${C_WHITE}Status:${C_RESET}   ${C_STATUS_A}Running${C_RESET}"
        pm2 show "$AUTO_BACKUP_PM2_NAME" 2>/dev/null | grep -E 'status|uptime|cpu|memory' | sed 's/^/  /'
    else
        echo -e "${C_WHITE}Status:${C_RESET}   ${C_STATUS_I}Stopped${C_RESET}"
    fi
    echo
    echo -e "${C_WHITE}Archives:${C_RESET} ${C_GREEN}$AUTO_BACKUP_DIR${C_RESET}"
    if [ -d "$AUTO_BACKUP_DIR" ]; then
        ls -lth "$AUTO_BACKUP_DIR"/*.tar.gz 2>/dev/null | head -5 || echo "  (no archives yet)"
    fi
    press_enter
}

backup_data_menu() {
    while true; do
        clear; show_banner
        local pill_bot="Stopped" pill_color="$C_RED"
        if pm2 list 2>/dev/null | grep -q "$AUTO_BACKUP_PM2_NAME"; then
            pill_bot="Active"
            pill_color="$C_GREEN"
        fi

        echo
        tdz_box_top
        tdz_box_header "BACKUP & RESTORE"
        tdz_box_divider
        tdz_row2 "${C_GRAY}AUTO BACKUP BOT${C_RESET}" "${pill_color}${C_BOLD}${pill_bot}${C_RESET}"
        tdz_box_divider
        tdz_menu1 "[ 1]" "Backup User Data"
        tdz_menu1 "[ 2]" "Connect Telegram Bot"
        tdz_menu1 "[ 3]" "Start Backup Bot"
        tdz_menu1 "[ 4]" "Stop Backup Bot"
        tdz_menu1 "[ 5]" "Restart Backup Bot"
        tdz_menu1 "[ 6]" "Send Backup Now"
        tdz_menu1 "[ 7]" "View Bot Status"
        tdz_menu1 "[ 8]" "Edit Backup Interval"
        tdz_menu1 "[ 9]" "Reset Backup Bot"
        tdz_box_divider
        tdz_menu1 "[ 0]" "Return to Main Menu"
        tdz_box_bot
        echo
        read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" b_choice
        case $b_choice in
            1) backup_user_data ;;
            2) auto_backup_connect_bot ;;
            3) auto_backup_start ;;
            4) auto_backup_stop ;;
            5) auto_backup_restart ;;
            6) auto_backup_send_now ;;
            7) auto_backup_status ;;
            8) auto_backup_edit_interval ;;
            9) auto_backup_reset ;;
            0) return ;;
            *) invalid_option ;;
        esac
    done
}

_enable_banner_in_sshd_config() {
    echo -e "\n${C_BLUE}Applying SSH banner settings...${C_RESET}"
    disable_dynamic_ssh_banner_system
    sed -i.bak -E 's/^( *Banner *).*/#\1/' /etc/ssh/sshd_config
    if ! grep -q -E "^Banner $SSH_BANNER_FILE" /etc/ssh/sshd_config; then
        echo -e "\n# TDZ SSH TUNNEL SSH Banner\nBanner $SSH_BANNER_FILE" >> /etc/ssh/sshd_config
    fi
    echo -e "${C_GREEN}[OK] SSH banner settings updated.${C_RESET}"
}

_restart_ssh() {
    echo -e "\n${C_BLUE}Restarting SSH service to apply changes...${C_RESET}"
    local ssh_service_name=""
    if [ -f /lib/systemd/system/sshd.service ]; then
        ssh_service_name="sshd.service"
    elif [ -f /lib/systemd/system/ssh.service ]; then
        ssh_service_name="ssh.service"
    else
        echo -e "${C_RED}[ERROR] Could not find sshd.service or ssh.service. Cannot restart SSH.${C_RESET}"
        return 1
    fi

    systemctl restart "${ssh_service_name}"
    if [ $? -eq 0 ]; then
        echo -e "${C_GREEN}[OK] SSH service ('${ssh_service_name}') restarted successfully.${C_RESET}"
    else
        echo -e "${C_RED}[ERROR] Failed to restart SSH service ('${ssh_service_name}'). Please check 'journalctl -u ${ssh_service_name}' for errors.${C_RESET}"
    fi
}

is_valid_telegram_username() {
    [[ "$1" =~ ^[A-Za-z][A-Za-z0-9_]{4,31}$ ]]
}

load_banner_identity_config() {
    local key value
    BANNER_ADMIN_USERNAME="$DEFAULT_BANNER_ADMIN_USERNAME"
    BANNER_CHANNEL_USERNAME="$DEFAULT_BANNER_CHANNEL_USERNAME"

    if [[ -r "$BANNER_IDENTITY_CONF" ]]; then
        while IFS='=' read -r key value; do
            value=${value%$'\r'}
            case "$key" in
                ADMIN_USERNAME) BANNER_ADMIN_USERNAME="$value" ;;
                CHANNEL_USERNAME) BANNER_CHANNEL_USERNAME="$value" ;;
            esac
        done < "$BANNER_IDENTITY_CONF"
    fi

    is_valid_telegram_username "$BANNER_ADMIN_USERNAME" || BANNER_ADMIN_USERNAME="$DEFAULT_BANNER_ADMIN_USERNAME"
    is_valid_telegram_username "$BANNER_CHANNEL_USERNAME" || BANNER_CHANNEL_USERNAME="$DEFAULT_BANNER_CHANNEL_USERNAME"
}

save_banner_identity_config() {
    local admin_username="$1" channel_username="$2" tmp_file
    mkdir -p "$DB_DIR" || return 1
    tmp_file="${BANNER_IDENTITY_CONF}.tmp"
    printf 'ADMIN_USERNAME=%s\nCHANNEL_USERNAME=%s\n' \
        "$admin_username" "$channel_username" > "$tmp_file" || return 1
    chmod 600 "$tmp_file"
    mv -f "$tmp_file" "$BANNER_IDENTITY_CONF"
}

edit_dynamic_banner_contacts() {
    clear; show_banner
    tdz_screen_title "DYNAMIC BANNER CONTACTS" "Update the Telegram usernames shown to SSH users."
    load_banner_identity_config
    echo -e "${C_WHITE}Current Admin:${C_RESET}   ${C_GREEN}@${BANNER_ADMIN_USERNAME}${C_RESET}"
    echo -e "${C_WHITE}Current Channel:${C_RESET} ${C_GREEN}@${BANNER_CHANNEL_USERNAME}${C_RESET}"
    echo -e "${C_DIM}Enter Telegram usernames only. Links are generated automatically.${C_RESET}\n"

    local new_admin new_channel
    read -r -p "  Admin username [@${BANNER_ADMIN_USERNAME}]: " new_admin
    read -r -p "  Channel username [@${BANNER_CHANNEL_USERNAME}]: " new_channel
    new_admin=${new_admin#@}
    new_channel=${new_channel#@}
    new_admin=${new_admin:-$BANNER_ADMIN_USERNAME}
    new_channel=${new_channel:-$BANNER_CHANNEL_USERNAME}

    if ! is_valid_telegram_username "$new_admin"; then
        echo -e "\n${C_RED}[ERROR] Invalid Admin username. Use 5-32 letters, numbers, or underscores, starting with a letter.${C_RESET}"
        press_enter
        return
    fi
    if ! is_valid_telegram_username "$new_channel"; then
        echo -e "\n${C_RED}[ERROR] Invalid Channel username. Use 5-32 letters, numbers, or underscores, starting with a letter.${C_RESET}"
        press_enter
        return
    fi

    if ! save_banner_identity_config "$new_admin" "$new_channel"; then
        echo -e "\n${C_RED}[ERROR] Could not save the banner contacts.${C_RESET}"
        press_enter
        return
    fi

    local limiter_reloaded=true
    setup_limiter_service >/dev/null 2>&1 || limiter_reloaded=false
    refresh_dynamic_banner_routing_if_enabled
    echo -e "\n${C_GREEN}[OK] Dynamic banner contacts updated.${C_RESET}"
    echo -e "   • Admin: ${C_YELLOW}@${new_admin}${C_RESET}"
    echo -e "   • Channel: ${C_YELLOW}@${new_channel}${C_RESET}"
    if [[ "$limiter_reloaded" != true ]]; then
        echo -e "${C_YELLOW}[WARNING] Contacts were saved, but the banner worker could not be restarted.${C_RESET}"
    fi
    press_enter
}

set_ssh_banner_paste() {
    clear; show_banner
    tdz_screen_title "PASTE STATIC SSH BANNER" "Paste the banner, then press Ctrl+D on a new line to save."
    echo -e "  Paste your custom banner below. Press ${C_YELLOW}[Ctrl+D]${C_RESET} when finished."
    echo -e "${C_DIM}The current static banner (if any) will be overwritten.${C_RESET}"
    tdz_section "BANNER INPUT"
    cat > "$SSH_BANNER_FILE"
    chmod 644 "$SSH_BANNER_FILE"
    echo -e "\n${C_GREEN}[OK] Static banner content saved.${C_RESET}"
    _enable_banner_in_sshd_config
    _restart_ssh
    echo -e "\nPress ${C_YELLOW}[Enter]${C_RESET} to return..." && read -r
}

view_ssh_banner() {
    clear; show_banner
    tdz_screen_title "CURRENT STATIC SSH BANNER"
    if [ -f "$SSH_BANNER_FILE" ]; then
        tdz_section "BEGIN BANNER"
        cat "$SSH_BANNER_FILE"
        tdz_section "END BANNER"
    else
        echo -e "\n${C_YELLOW}[INFO] No static banner is configured.${C_RESET}"
    fi
    echo -e "\nPress ${C_YELLOW}[Enter]${C_RESET} to return..." && read -r
}

remove_ssh_banner() {
    clear; show_banner
    tdz_screen_title "DISABLE SSH BANNERS" "Disable both dynamic and static SSH login banners." "$C_DANGER"
    read -p "  Are you sure you want to disable all SSH banners? (y/n): " confirm
    if [[ "$confirm" != "y" ]]; then
        tdz_message CANCELLED "Action cancelled."
        echo -e "\nPress ${C_YELLOW}[Enter]${C_RESET} to return..." && read -r
        return
    fi
    if [ -f "$SSH_BANNER_FILE" ]; then
        rm -f "$SSH_BANNER_FILE"
        echo -e "\n${C_GREEN}[OK] Static banner removed.${C_RESET}"
    else
        echo -e "\n${C_YELLOW}[INFO] No static banner is configured.${C_RESET}"
    fi
    disable_dynamic_ssh_banner_system
    echo -e "\n${C_BLUE}Disabling SSH banner settings...${C_RESET}"
    disable_static_ssh_banner_in_sshd_config
    echo -e "${C_GREEN}[OK] SSH banner disabled.${C_RESET}"
    _restart_ssh
    echo -e "\nPress ${C_YELLOW}[Enter]${C_RESET} to return..." && read -r
}

preview_dynamic_ssh_banner() {
    if ! is_dynamic_ssh_banner_enabled; then
        echo -e "\n${C_RED}[ERROR] Dynamic banners are not enabled right now.${C_RESET}"
        press_enter
        return
    fi

    echo -e "${C_DIM}Refreshing dynamic banner worker...${C_RESET}"
    setup_limiter_service >/dev/null 2>&1
    _select_user_interface "PREVIEW DYNAMIC BANNER"
    local u=$SELECTED_USER
    if [[ -z "$u" || "$u" == "NO_USERS" ]]; then
        return
    fi

    echo
    tdz_section "DYNAMIC BANNER PREVIEW — $u"
    echo
    if [[ -f "/etc/tdztunnel/banners/${u}.txt" ]]; then
        cat "/etc/tdztunnel/banners/${u}.txt"
    else
        echo -e "${C_RED}Banner file not generated yet. Waiting up to 10s for the worker...${C_RESET}"
        sleep 5
        if ! cat "/etc/tdztunnel/banners/${u}.txt" 2>/dev/null; then
            echo -e "\n${C_RED}Still not generated. Here are the last limiter logs:${C_RESET}"
            tdz_section "LIMITER LOG"
            journalctl -u tdztunnel-limiter -n 15 --no-pager
        fi
    fi
    press_enter
}

install_udp_custom() {
    clear; show_banner
    tdz_screen_title "INSTALL UDP-CUSTOM" "Install the UDP transport service and udpgw helper."
    if [ -f "$UDP_CUSTOM_SERVICE_FILE" ] || [ -f "$UDPGW_SERVICE_FILE" ]; then
        echo -e "\n${C_YELLOW}[INFO] udp-custom is already installed.${C_RESET}"
        return
    fi

    check_and_free_ports 36712 7800 || return
    check_and_open_firewall_port 36712 udp || return

    echo -e "\n${C_GREEN}Creating directory for udp-custom...${C_RESET}"
    rm -rf "$UDP_CUSTOM_DIR"
    mkdir -p "$UDP_CUSTOM_DIR"

    echo -e "\n${C_GREEN}Detecting system architecture...${C_RESET}"
    local arch
    arch=$(uname -m)
    local binary_url=""
    if [[ "$arch" == "x86_64" ]]; then
        binary_url="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/raw/main/udp/udp-custom-linux-amd64"
        echo -e "${C_BLUE}[INFO] Detected x86_64 (amd64) architecture.${C_RESET}"
    elif [[ "$arch" == "aarch64" || "$arch" == "arm64" ]]; then
        binary_url="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/raw/main/udp/udp-custom-linux-arm"
        echo -e "${C_BLUE}[INFO] Detected ARM64 architecture.${C_RESET}"
    else
        echo -e "\n${C_RED}[ERROR] Unsupported architecture: $arch. Cannot install udp-custom.${C_RESET}"
        rm -rf "$UDP_CUSTOM_DIR"
        return
    fi

    echo -e "\n${C_GREEN}Downloading udp-custom binary...${C_RESET}"
    wget -q --show-progress -O "$UDP_CUSTOM_DIR/udp-custom" "$binary_url"
    if [ $? -ne 0 ]; then
        echo -e "\n${C_RED}[ERROR] Failed to download the udp-custom binary.${C_RESET}"
        rm -rf "$UDP_CUSTOM_DIR"
        return
    fi
    chmod +x "$UDP_CUSTOM_DIR/udp-custom"

    echo -e "\n${C_GREEN}Downloading udpgw helper...${C_RESET}"
    wget -q --show-progress -O "$UDPGW_BINARY" "https://raw.githubusercontent.com/http-custom/udp-custom/main/module/udpgw"
    if [ $? -ne 0 ]; then
        echo -e "\n${C_RED}[ERROR] Failed to download the udpgw helper binary.${C_RESET}"
        rm -rf "$UDP_CUSTOM_DIR"
        rm -f "$UDPGW_BINARY"
        return
    fi
    chmod +x "$UDPGW_BINARY"

    echo -e "\n${C_GREEN}Creating default config.json...${C_RESET}"
    cat > "$UDP_CUSTOM_DIR/config.json" <<EOF
{
  "listen": ":36712",
  "stream_buffer": 33554432,
  "receive_buffer": 83886080,
  "auth": {
    "mode": "passwords"
  }
}
EOF
    chmod 644 "$UDP_CUSTOM_DIR/config.json"

    echo -e "\n${C_GREEN}Creating udpgw systemd service file...${C_RESET}"
    cat > "$UDPGW_SERVICE_FILE" <<EOF
[Unit]
Description=TDZ SSH TUNNEL UDPGW Backend
After=network.target

[Service]
User=root
Type=simple
ExecStart=$UDPGW_BINARY --listen-addr 127.0.0.1:7800 --max-clients 1000 --max-connections-for-client 100
Restart=always
RestartSec=2s

[Install]
WantedBy=multi-user.target
EOF

    echo -e "\n${C_GREEN}Creating systemd service file...${C_RESET}"
    cat > "$UDP_CUSTOM_SERVICE_FILE" <<EOF
[Unit]
Description=UDP Custom by TDZ SSH TUNNEL
After=network.target

[Service]
User=root
Type=simple
ExecStart=$UDP_CUSTOM_DIR/udp-custom server
WorkingDirectory=$UDP_CUSTOM_DIR/
Restart=always
RestartSec=2s

[Install]
WantedBy=multi-user.target
EOF

    echo -e "\n${C_BLUE}[INFO] Enabling and starting udp-custom service...${C_RESET}"
    systemctl daemon-reload
    systemctl enable udpgw.service
    systemctl start udpgw.service
    systemctl enable udp-custom.service
    systemctl start udp-custom.service
    sleep 2
    if systemctl is-active --quiet udpgw && systemctl is-active --quiet udp-custom; then
        echo -e "\n${C_GREEN}[OK] udp-custom is installed and active.${C_RESET}"
    else
        echo -e "\n${C_RED}[ERROR] udp-custom service failed to start.${C_RESET}"
        echo -e "${C_YELLOW}[INFO] Displaying last 15 lines of the udp-custom and udpgw logs for diagnostics:${C_RESET}"
        journalctl -u udp-custom.service -n 15 --no-pager
        journalctl -u udpgw.service -n 15 --no-pager
    fi
}

uninstall_udp_custom() {
    tdz_screen_title "UNINSTALL UDP-CUSTOM"
    if [ ! -f "$UDP_CUSTOM_SERVICE_FILE" ] && [ ! -f "$UDPGW_SERVICE_FILE" ]; then
        echo -e "${C_YELLOW}[INFO] udp-custom is not installed, skipping.${C_RESET}"
        return
    fi
    echo -e "${C_GREEN}Stopping and disabling udpgw service...${C_RESET}"
    systemctl stop udpgw.service >/dev/null 2>&1
    systemctl disable udpgw.service >/dev/null 2>&1
    echo -e "${C_GREEN}Stopping and disabling udp-custom service...${C_RESET}"
    systemctl stop udp-custom.service >/dev/null 2>&1
    systemctl disable udp-custom.service >/dev/null 2>&1
    echo -e "${C_GREEN}Removing systemd service file...${C_RESET}"
    rm -f "$UDP_CUSTOM_SERVICE_FILE"
    rm -f "$UDPGW_SERVICE_FILE"
    systemctl daemon-reload
    echo -e "${C_GREEN}Removing udp-custom directory and files...${C_RESET}"
    rm -rf "$UDP_CUSTOM_DIR"
    rm -f "$UDPGW_BINARY"
    echo -e "${C_GREEN}[OK] udp-custom has been uninstalled successfully.${C_RESET}"
}


ensure_badvpn_service_is_quiet() {
    if [[ ! -f "$BADVPN_SERVICE_FILE" ]] || grep -q "^StandardOutput=null$" "$BADVPN_SERVICE_FILE" 2>/dev/null; then
        return
    fi

    local tmp_service
    tmp_service=$(mktemp)
    awk '
        /^\[Service\]$/ {
            print
            print "StandardOutput=null"
            print "StandardError=null"
            next
        }
        { print }
    ' "$BADVPN_SERVICE_FILE" > "$tmp_service" && mv "$tmp_service" "$BADVPN_SERVICE_FILE"
    rm -f "$tmp_service" 2>/dev/null
    systemctl daemon-reload
    systemctl restart badvpn.service >/dev/null 2>&1 || true
}

install_badvpn() {
    clear; show_banner
    tdz_screen_title "INSTALL BADVPN" "Build and enable the udpgw service on UDP port 7300."
    if [ -f "$BADVPN_SERVICE_FILE" ]; then
        echo -e "\n${C_YELLOW}[INFO] badvpn is already installed.${C_RESET}"
        return
    fi
    check_and_open_firewall_port 7300 udp || return
    echo -e "\n${C_GREEN}Updating package lists...${C_RESET}"
    tdz_apt_update || return
    echo -e "\n${C_GREEN}Installing all required packages...${C_RESET}"
    tdz_apt_install cmake g++ make screen git build-essential libssl-dev libnspr4-dev libnss3-dev pkg-config || {
        echo -e "${C_RED}[ERROR] Failed to install badvpn build dependencies.${C_RESET}"
        return
    }
    echo -e "\n${C_GREEN}Cloning badvpn from github...${C_RESET}"
    git clone https://github.com/ambrop72/badvpn.git "$BADVPN_BUILD_DIR"
    cd "$BADVPN_BUILD_DIR" || { echo -e "${C_RED}[ERROR] Failed to change directory to build folder.${C_RESET}"; return; }
    echo -e "\n${C_GREEN}Running CMake...${C_RESET}"
    cmake . || { echo -e "${C_RED}[ERROR] CMake configuration failed.${C_RESET}"; rm -rf "$BADVPN_BUILD_DIR"; return; }
    echo -e "\n${C_GREEN}Compiling source...${C_RESET}"
    make || { echo -e "${C_RED}[ERROR] Compilation (make) failed.${C_RESET}"; rm -rf "$BADVPN_BUILD_DIR"; return; }
    local badvpn_binary
    badvpn_binary=$(find "$BADVPN_BUILD_DIR" -name "badvpn-udpgw" -type f | head -n 1)
    if [[ -z "$badvpn_binary" || ! -f "$badvpn_binary" ]]; then
        echo -e "${C_RED}[ERROR] Could not find the compiled 'badvpn-udpgw' binary after compilation.${C_RESET}"
        rm -rf "$BADVPN_BUILD_DIR"
        return
    fi
    echo -e "${C_GREEN}[INFO] Found binary at: $badvpn_binary${C_RESET}"
    chmod +x "$badvpn_binary"
    echo -e "\n${C_GREEN}Creating systemd service file...${C_RESET}"
    cat > "$BADVPN_SERVICE_FILE" <<-EOF
[Unit]
Description=BadVPN UDP Gateway
After=network.target
[Service]
ExecStart=$badvpn_binary --listen-addr 0.0.0.0:7300 --max-clients 1000 --max-connections-for-client 8
User=root
Restart=always
RestartSec=3
StandardOutput=null
StandardError=null
[Install]
WantedBy=multi-user.target
EOF
    echo -e "\n${C_BLUE}[INFO] Enabling and starting badvpn service...${C_RESET}"
    systemctl daemon-reload
    systemctl enable badvpn.service
    systemctl start badvpn.service
    sleep 2
    if systemctl is-active --quiet badvpn; then
        echo -e "\n${C_GREEN}[OK] badvpn (udpgw) is installed and active on port 7300.${C_RESET}"
    else
        echo -e "\n${C_RED}[ERROR] badvpn service failed to start.${C_RESET}"
        echo -e "${C_YELLOW}[INFO] Displaying last 15 lines of the service log for diagnostics:${C_RESET}"
        journalctl -u badvpn.service -n 15 --no-pager
    fi
}

uninstall_badvpn() {
    tdz_screen_title "UNINSTALL BADVPN"
    if [ ! -f "$BADVPN_SERVICE_FILE" ]; then
        echo -e "${C_YELLOW}[INFO] badvpn is not installed, skipping.${C_RESET}"
        return
    fi
    echo -e "${C_GREEN}Stopping and disabling badvpn service...${C_RESET}"
    systemctl stop badvpn.service >/dev/null 2>&1
    systemctl disable badvpn.service >/dev/null 2>&1
    echo -e "${C_GREEN}Removing systemd service file...${C_RESET}"
    rm -f "$BADVPN_SERVICE_FILE"
    systemctl daemon-reload
    echo -e "${C_GREEN}Removing badvpn build directory...${C_RESET}"
    rm -rf "$BADVPN_BUILD_DIR"
    echo -e "${C_GREEN}[OK] badvpn has been uninstalled successfully.${C_RESET}"
}

load_edge_cert_info() {
    EDGE_CERT_MODE=""
    EDGE_DOMAIN=""
    EDGE_EMAIL=""
    if [ -f "$EDGE_CERT_INFO_FILE" ]; then
        source "$EDGE_CERT_INFO_FILE"
    fi
}

save_edge_cert_info() {
    local cert_mode="$1"
    local cert_domain="$2"
    local cert_email="$3"
    mkdir -p "$DB_DIR"
    cat > "$EDGE_CERT_INFO_FILE" <<EOF
EDGE_CERT_MODE="$cert_mode"
EDGE_DOMAIN="$cert_domain"
EDGE_EMAIL="$cert_email"
EOF
}

detect_preferred_host() {
    local host_domain=""
    load_edge_cert_info
    if [[ -n "$EDGE_DOMAIN" ]]; then
        host_domain="$EDGE_DOMAIN"
    fi
    if [[ -z "$host_domain" && -f "$NGINX_CONFIG_FILE" ]]; then
        local nginx_domain
        nginx_domain=$(grep -oP 'server_name \K[^\s;]+' "$NGINX_CONFIG_FILE" 2>/dev/null | head -n 1)
        if [[ "$nginx_domain" != "_" && -n "$nginx_domain" ]]; then
            host_domain="$nginx_domain"
        fi
    fi
    if [[ -z "$host_domain" ]]; then
        host_domain=$(curl -s -4 icanhazip.com)
    fi
    echo "$host_domain"
}

backup_edge_configs() {
    if [ -f "$NGINX_CONFIG_FILE" ] && [ ! -f "${NGINX_CONFIG_FILE}.bak.tdztunnel" ]; then
        cp "$NGINX_CONFIG_FILE" "${NGINX_CONFIG_FILE}.bak.tdztunnel" 2>/dev/null
    fi
    if [ -f "$HAPROXY_CONFIG" ] && [ ! -f "${HAPROXY_CONFIG}.bak.tdztunnel" ]; then
        cp "$HAPROXY_CONFIG" "${HAPROXY_CONFIG}.bak.tdztunnel" 2>/dev/null
    fi
}

ensure_edge_stack_packages() {
    local missing_packages=()
    command -v haproxy &> /dev/null || missing_packages+=("haproxy")
    command -v nginx &> /dev/null || missing_packages+=("nginx")
    command -v openssl &> /dev/null || missing_packages+=("openssl")
    command -v python3 &> /dev/null || missing_packages+=("python3")

    if (( ${#missing_packages[@]} > 0 )); then
        echo -e "\n${C_BLUE}Installing required packages: ${missing_packages[*]}${C_RESET}"
        tdz_apt_install "${missing_packages[@]}" || {
            echo -e "${C_RED}[ERROR] Failed to install the required packages.${C_RESET}"
            return 1
        }
    fi
    return 0
}

build_shared_tls_bundle() {
    if [ ! -s "$SSL_CERT_CHAIN_FILE" ] || [ ! -s "$SSL_CERT_KEY_FILE" ]; then
        echo -e "${C_RED}[ERROR] Certificate chain or key is missing.${C_RESET}"
        return 1
    fi
    cat "$SSL_CERT_CHAIN_FILE" "$SSL_CERT_KEY_FILE" > "$TDZ_SSL_CERT_FILE" || return 1
    chmod 644 "$SSL_CERT_CHAIN_FILE"
    chmod 600 "$SSL_CERT_KEY_FILE" "$TDZ_SSL_CERT_FILE"
    return 0
}

generate_self_signed_edge_cert() {
    local common_name="$1"
    mkdir -p "$SSL_CERT_DIR"
    echo -e "\n${C_GREEN}Generating a shared self-signed certificate...${C_RESET}"
    openssl req -x509 -newkey rsa:2048 -nodes -days 3650 \
        -keyout "$SSL_CERT_KEY_FILE" \
        -out "$SSL_CERT_CHAIN_FILE" \
        -subj "/CN=$common_name" \
        >/dev/null 2>&1 || {
            echo -e "${C_RED}[ERROR] Failed to generate the self-signed certificate.${C_RESET}"
            return 1
        }
    build_shared_tls_bundle || return 1
    save_edge_cert_info "self-signed" "$common_name" ""
    echo -e "${C_GREEN}[OK] Shared certificate created for ${C_YELLOW}$common_name${C_RESET}"
    return 0
}

_install_certbot() {
    if command -v certbot &> /dev/null; then
        echo -e "${C_GREEN}[OK] Certbot is already installed.${C_RESET}"
        return 0
    fi
    echo -e "${C_BLUE}Installing Certbot...${C_RESET}"
    tdz_apt_install certbot || {
        echo -e "${C_RED}[ERROR] Failed to install Certbot.${C_RESET}"
        return 1
    }
    echo -e "${C_GREEN}[OK] Certbot installed successfully.${C_RESET}"
    return 0
}

obtain_certbot_edge_cert() {
    local domain_name="$1"
    local email="$2"
    local restart_haproxy=0
    local restart_nginx=0

    mkdir -p "$SSL_CERT_DIR"
    _install_certbot || return 1

    if systemctl is-active --quiet haproxy; then restart_haproxy=1; fi
    if systemctl is-active --quiet nginx; then restart_nginx=1; fi

    echo -e "\n${C_BLUE}Stopping HAProxy and Nginx for Certbot validation...${C_RESET}"
    systemctl stop haproxy >/dev/null 2>&1
    systemctl stop nginx >/dev/null 2>&1
    sleep 2

    check_and_free_ports "$EDGE_PUBLIC_HTTP_PORT" "$EDGE_PUBLIC_TLS_PORT" || {
        [[ "$restart_nginx" -eq 1 ]] && systemctl start nginx >/dev/null 2>&1
        [[ "$restart_haproxy" -eq 1 ]] && systemctl start haproxy >/dev/null 2>&1
        return 1
    }

    echo -e "\n${C_BLUE}Requesting a Certbot certificate for ${C_YELLOW}$domain_name${C_RESET}"
    certbot certonly --standalone -d "$domain_name" --non-interactive --agree-tos -m "$email"
    if [ $? -ne 0 ]; then
        echo -e "\n${C_RED}[ERROR] Certbot failed to obtain a certificate.${C_RESET}"
        echo -e "${C_YELLOW}[INFO] Make sure the domain points to this server and port 80 is reachable.${C_RESET}"
        [[ "$restart_nginx" -eq 1 ]] && systemctl start nginx >/dev/null 2>&1
        [[ "$restart_haproxy" -eq 1 ]] && systemctl start haproxy >/dev/null 2>&1
        return 1
    fi

    local certbot_chain="/etc/letsencrypt/live/$domain_name/fullchain.pem"
    local certbot_key="/etc/letsencrypt/live/$domain_name/privkey.pem"
    if [ ! -f "$certbot_chain" ] || [ ! -f "$certbot_key" ]; then
        echo -e "\n${C_RED}[ERROR] Certbot completed, but the certificate files were not found.${C_RESET}"
        [[ "$restart_nginx" -eq 1 ]] && systemctl start nginx >/dev/null 2>&1
        [[ "$restart_haproxy" -eq 1 ]] && systemctl start haproxy >/dev/null 2>&1
        return 1
    fi

    cp "$certbot_chain" "$SSL_CERT_CHAIN_FILE"
    cp "$certbot_key" "$SSL_CERT_KEY_FILE"
    build_shared_tls_bundle || {
        [[ "$restart_nginx" -eq 1 ]] && systemctl start nginx >/dev/null 2>&1
        [[ "$restart_haproxy" -eq 1 ]] && systemctl start haproxy >/dev/null 2>&1
        return 1
    }
    save_edge_cert_info "certbot" "$domain_name" "$email"
    echo -e "${C_GREEN}[OK] Certbot certificate copied into ${C_YELLOW}$SSL_CERT_DIR${C_RESET}"
    return 0
}

select_edge_certificate() {
    local preferred_host
    local cert_choice
    local has_existing_cert=false

    preferred_host=$(detect_preferred_host)
    if [[ -z "$preferred_host" ]]; then
        preferred_host="tdztunnel.local"
    fi

    if [ -s "$TDZ_SSL_CERT_FILE" ] && [ -s "$SSL_CERT_CHAIN_FILE" ] && [ -s "$SSL_CERT_KEY_FILE" ]; then
        has_existing_cert=true
    fi

    load_edge_cert_info

    echo
    tdz_box_top
    tdz_box_header "SHARED TLS CERTIFICATE"
    tdz_box_divider
    if $has_existing_cert; then
        local existing_label="${EDGE_CERT_MODE:-existing}"
        if [[ -n "$EDGE_DOMAIN" ]]; then
            existing_label="$existing_label - $EDGE_DOMAIN"
        fi
        tdz_row "${C_GRAY}CURRENT${C_RESET} ${C_WHITE}${existing_label}${C_RESET}"
        tdz_box_divider
        tdz_menu1 "[ 1]" "Reuse Existing Certificate"
        tdz_menu1 "[ 2]" "Replace with Self-Signed Certificate"
        tdz_menu1 "[ 3]" "Replace with Certbot Certificate"
        tdz_box_bot
        echo
        read -r -p "$(echo -e "${C_PROMPT}  Select an option [1]: ${C_RESET}")" cert_choice
        cert_choice=${cert_choice:-1}
    else
        tdz_row "${C_GRAY}No shared certificate is currently configured.${C_RESET}"
        tdz_box_divider
        tdz_menu1 "[ 1]" "Generate Self-Signed Certificate"
        tdz_menu1 "[ 2]" "Use Certbot Certificate"
        tdz_box_bot
        echo
        read -r -p "$(echo -e "${C_PROMPT}  Select an option [1]: ${C_RESET}")" cert_choice
        cert_choice=${cert_choice:-1}
    fi

    case "$cert_choice" in
        1)
            if $has_existing_cert; then
                echo -e "${C_GREEN}[OK] Reusing the existing shared certificate.${C_RESET}"
                return 0
            fi
            local common_name
            read -p "  Enter the certificate Common Name / SNI label [$preferred_host]: " common_name
            common_name=${common_name:-$preferred_host}
            generate_self_signed_edge_cert "$common_name"
            ;;
        2)
            if $has_existing_cert; then
                local common_name
                read -p "  Enter the certificate Common Name / SNI label [$preferred_host]: " common_name
                common_name=${common_name:-$preferred_host}
                generate_self_signed_edge_cert "$common_name"
            else
                local default_domain=""
                local domain_name
                local email
                if ! _is_valid_ipv4 "$preferred_host"; then
                    default_domain="$preferred_host"
                fi
                if [[ -n "$default_domain" ]]; then
                    read -p "  Enter your domain name [$default_domain]: " domain_name
                    domain_name=${domain_name:-$default_domain}
                else
                    read -p "  Enter your domain name (e.g. vpn.example.com): " domain_name
                fi
                if [[ -z "$domain_name" ]]; then
                    echo -e "${C_RED}[ERROR] Domain name cannot be empty.${C_RESET}"
                    return 1
                fi
                if _is_valid_ipv4 "$domain_name"; then
                    echo -e "${C_RED}[ERROR] Certbot requires a real domain name, not a raw IP address.${C_RESET}"
                    return 1
                fi
                read -p "  Enter your email for Let's Encrypt: " email
                if [[ -z "$email" ]]; then
                    echo -e "${C_RED}[ERROR] Email cannot be empty.${C_RESET}"
                    return 1
                fi
                obtain_certbot_edge_cert "$domain_name" "$email"
            fi
            ;;
        3)
            if ! $has_existing_cert; then
                echo -e "${C_RED}[ERROR] Invalid option.${C_RESET}"
                return 1
            fi
            local default_domain=""
            local domain_name
            local email
            if [[ -n "$EDGE_DOMAIN" ]] && ! _is_valid_ipv4 "$EDGE_DOMAIN"; then
                default_domain="$EDGE_DOMAIN"
            fi
            if [[ -z "$default_domain" ]] && ! _is_valid_ipv4 "$preferred_host"; then
                default_domain="$preferred_host"
            fi
            if [[ -n "$default_domain" ]]; then
                read -p "  Enter your domain name [$default_domain]: " domain_name
                domain_name=${domain_name:-$default_domain}
            else
                read -p "  Enter your domain name (e.g. vpn.example.com): " domain_name
            fi
            if [[ -z "$domain_name" ]]; then
                echo -e "${C_RED}[ERROR] Domain name cannot be empty.${C_RESET}"
                return 1
            fi
            if _is_valid_ipv4 "$domain_name"; then
                echo -e "${C_RED}[ERROR] Certbot requires a real domain name, not a raw IP address.${C_RESET}"
                return 1
            fi
            read -p "  Enter your email for Let's Encrypt [${EDGE_EMAIL}]: " email
            email=${email:-$EDGE_EMAIL}
            if [[ -z "$email" ]]; then
                echo -e "${C_RED}[ERROR] Email cannot be empty.${C_RESET}"
                return 1
            fi
            obtain_certbot_edge_cert "$domain_name" "$email"
            ;;
        *)
            echo -e "${C_RED}[ERROR] Invalid option.${C_RESET}"
            return 1
            ;;
    esac
}

# ============================================================================
# WebSocket-to-SSH Bridge — accepts DarkTunnel-style WS upgrade payloads
# (GET wss://[cf] HTTP/1.1 ... Upgrade: websocket) and bridges raw TCP to SSH.
# Replaces nginx_cleartext for port 2080 because nginx returns 400 Bad Request
# on the non-standard wss:// absolute-URI form.
# ============================================================================
write_ws_ssh_bridge_script() {
    mkdir -p "$(dirname "$WS_SSH_BRIDGE_SCRIPT")"
    cat > "$WS_SSH_BRIDGE_SCRIPT" <<'PYEOF'
#!/usr/bin/env python3
"""TDZ SSH TUNNEL WebSocket-to-SSH Bridge v2 (with branding support)."""
import socket, select, threading, sys, os, signal, time

LISTEN_HOST = os.environ.get("TDZ_WS_BRIDGE_HOST", "127.0.0.1")
LISTEN_PORT = int(os.environ.get("TDZ_WS_BRIDGE_PORT", "8890"))
SSH_HOST    = os.environ.get("TDZ_WS_BRIDGE_SSH_HOST", "127.0.0.1")
SSH_PORT    = int(os.environ.get("TDZ_WS_BRIDGE_SSH_PORT", "22"))
BRANDING_FILE = os.environ.get("TDZ_WS_BRIDGE_BRANDING", "/etc/tdztunnel/ws_branding.conf")

SWITCHING_RESPONSE_BASE = (
b'HTTP/1.1 101 <b><font color="red" size="7">Script By:</font> <font color="#0057B7" size="7">tuhinbro.com</font></b>\r\n'
b"Upgrade: websocket\r\n"
b"Connection: Upgrade\r\n"
)
MAX_HEADER_BYTES = 65536
RECV_CHUNK = 256 * 1024
# Kernel socket buffers. Default Linux SO_RCVBUF is ~200KB which is WAY too
# small for high-BDP paths (BD <-> SG at 80ms RTT × 100Mbps = 1MB BDP).
# Without bigger buffers, the kernel throttles the sender via TCP window
# scale, capping throughput at ~20-30 Mbps even when both ends could go faster.
# 4MB lets the kernel buffer ~40MB of in-flight data per direction.
SOCKET_BUF_SIZE = 4 * 1024 * 1024  # 4 MB
BRANDING_CACHE_TTL = 30
# Tuned for stability over mobile / carrier-grade NAT (BD, SG, etc.)
#   - HANDSHAKE_TIMEOUT: increased from 10s to 30s for slow mobile handshakes
#   - SSH_CONNECT_TIMEOUT: increased from 5s to 10s
#   - BRIDGE_IDLE_TIMEOUT: reduced from 300s to 60s so dead peers are detected
#     faster. Combined with SO_KEEPALIVE (60s idle, 10s interval, 3 probes),
#     a silently-dropped connection is reaped within ~90s instead of staying
#     half-open for 5 minutes.
HANDSHAKE_TIMEOUT = 30
SSH_CONNECT_TIMEOUT = 10
BRIDGE_IDLE_TIMEOUT = 60
# TCP keepalive parameters (Linux specific) - fights NAT idle eviction
KEEPALIVE_IDLE = 60     # send first keepalive probe after 60s idle
KEEPALIVE_INTERVAL = 10 # then probe every 10s
KEEPALIVE_COUNT = 3     # after 3 failed probes (~90s), declare dead

_branding_cache = {"bytes": b"", "mtime": 0, "ts": 0}

def log(m):
    sys.stderr.write(f"[tdz-ws-bridge] {m}\n"); sys.stderr.flush()

def set_tcp_keepalive(sock):
    """Enable SO_KEEPALIVE + aggressive TCP_KEEPIDLE/INTVL/CNT.
    Critical for mobile/CGNAT environments where idle TCP connections get
    silently dropped by carrier NAT after ~5 minutes of inactivity.
    Without this, the tunnel "times out" periodically even though the
    server itself is fine."""
    try:
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_KEEPALIVE, 1)
    except OSError:
        return
    if hasattr(socket, "TCP_KEEPIDLE"):
        try: sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPIDLE, KEEPALIVE_IDLE)
        except OSError: pass
    if hasattr(socket, "TCP_KEEPINTVL"):
        try: sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPINTVL, KEEPALIVE_INTERVAL)
        except OSError: pass
    if hasattr(socket, "TCP_KEEPCNT"):
        try: sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_KEEPCNT, KEEPALIVE_COUNT)
        except OSError: pass

def set_nodelay(sock):
    """Disable Nagle's algorithm so small SSH packets are not buffered.
    Without this, interactive SSH feels laggy / stalls."""
    try: sock.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
    except OSError: pass

def set_large_buffers(sock):
    """Set SO_RCVBUF and SO_SNDBUF to SOCKET_BUF_SIZE (4MB).
    Default Linux socket buffers (~200KB) cap throughput at ~20-30 Mbps
    on long-RTT paths due to TCP window size limits. 4MB buffers let the
    kernel sustain ~400 Mbps over a 80ms RTT path."""
    try: sock.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, SOCKET_BUF_SIZE)
    except OSError: pass
    try: sock.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, SOCKET_BUF_SIZE)
    except OSError: pass

def load_branding_headers():
    now = time.time()
    try:
        st = os.stat(BRANDING_FILE)
    except (OSError, FileNotFoundError):
        _branding_cache["bytes"] = b""
        _branding_cache["mtime"] = 0
        _branding_cache["ts"] = now
        return b""
    if (now - _branding_cache["ts"] < BRANDING_CACHE_TTL
            and st.st_mtime == _branding_cache["mtime"]
            and _branding_cache["bytes"] is not None):
        return _branding_cache["bytes"]
    extra = []
    try:
        with open(BRANDING_FILE, "r", encoding="utf-8", errors="replace") as f:
            for line in f:
                line = line.rstrip("\r\n")
                if not line or line.lstrip().startswith("#"): continue
                if ":" not in line: continue
                if "\r" in line or "\n" in line: continue
                extra.append(line)
    except OSError:
        extra = []
    raw = "".join(h + "\r\n" for h in extra).encode("utf-8", errors="replace")
    _branding_cache["bytes"] = raw
    _branding_cache["mtime"] = st.st_mtime
    _branding_cache["ts"] = now
    return raw

def build_switching_response():
    return SWITCHING_RESPONSE_BASE + load_branding_headers() + b"\r\n"

def bridge_socks(c, s):
    """High-throughput bidirectional TCP bridge.
    Optimizations vs. naive version:
      - TCP_NODELAY on BOTH sockets (was client-only)
      - SO_KEEPALIVE + aggressive TCP_KEEPIDLE/INTVL/CNT on both
      - SO_RCVBUF/SO_SNDBUF 4MB on both (was kernel default ~200KB)
      - Pre-allocated 1MB bytearrays with recv_into() (was recv() allocating
        a new bytes object every call — ~10μs GC pressure per call × 100+ Hz
        = several % of CPU wasted on allocation alone)
      - sendall() is CPython-optimized internally; kept as-is.
    """
    set_nodelay(c)
    set_nodelay(s)
    set_tcp_keepalive(c)
    set_tcp_keepalive(s)
    set_large_buffers(c)
    set_large_buffers(s)
    # Pre-allocate recv buffers ONCE per connection, reuse across iterations.
    # Avoids ~10μs of allocation + GC per recv() call. At 100 Hz recv rate
    # that's 1ms/sec saved — sounds small but adds up under load.
    c_buf = bytearray(RECV_CHUNK)
    s_buf = bytearray(RECV_CHUNK)
    socks = [c, s]
    try:
        while True:
            r, _, _ = select.select(socks, [], [], BRIDGE_IDLE_TIMEOUT)
            if not r:
                # Idle cycle — keepalive will detect dead peers.
                # recv() on next loop will return empty if socket died.
                continue
            for sock in r:
                other = s if sock is c else c
                buf = c_buf if sock is c else s_buf
                try:
                    n = sock.recv_into(buf, RECV_CHUNK)
                except OSError:
                    return
                if not n:
                    return
                try:
                    # sendall with memoryview of exactly the bytes we got —
                    # avoids creating a sliced copy.
                    other.sendall(memoryview(buf)[:n])
                except OSError:
                    return
    finally:
        for sock in (c, s):
            try: sock.shutdown(socket.SHUT_RDWR)
            except OSError: pass
            try: sock.close()
            except OSError: pass

def handle(client, addr):
    try:
        # Increased handshake timeout: mobile networks (especially on first
        # TLS+WS handshake through HAProxy) can take 15-25s on slow links.
        client.settimeout(HANDSHAKE_TIMEOUT)
        buf = b""
        while b"\r\n\r\n" not in buf and len(buf) < MAX_HEADER_BYTES:
            try: chunk = client.recv(4096)
            except socket.timeout: return
            if not chunk: return
            buf += chunk
        if buf.startswith(b"SSH-"):
            client.settimeout(None)
            try: ssh = socket.create_connection((SSH_HOST, SSH_PORT), timeout=SSH_CONNECT_TIMEOUT)
            except Exception as e: log(f"ssh connect fail: {e}"); return
            ssh.sendall(buf)
            bridge_socks(client, ssh); return
        header, sep, leftover = buf.partition(b"\r\n\r\n")
        try: client.sendall(build_switching_response())
        except OSError: return
        try: ssh = socket.create_connection((SSH_HOST, SSH_PORT), timeout=SSH_CONNECT_TIMEOUT)
        except Exception as e: log(f"ssh connect fail: {e}"); return
        if leftover:
            try: ssh.sendall(leftover)
            except OSError: return
        client.settimeout(None)
        log(f"bridged {addr[0]}:{addr[1]} -> SSH {SSH_HOST}:{SSH_PORT}")
        bridge_socks(client, ssh)
    except Exception as e:
        log(f"err {addr}: {e}")
    finally:
        try: client.close()
        except OSError: pass

def main():
    log(f"starting on {LISTEN_HOST}:{LISTEN_PORT} -> SSH {SSH_HOST}:{SSH_PORT}")
    log(f"branding file: {BRANDING_FILE}")
    srv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    srv.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    try: srv.bind((LISTEN_HOST, LISTEN_PORT))
    except OSError as e: log(f"FATAL bind: {e}"); sys.exit(1)
    srv.listen(1024); log("listening")
    def stop(*_):
        try: srv.close()
        except: pass
        sys.exit(0)
    signal.signal(signal.SIGTERM, stop); signal.signal(signal.SIGINT, stop)
    while True:
        try: c, a = srv.accept()
        except OSError: break
        # Apply all stability + throughput socket options on accepted socket.
        # (keepalive + nodelay + large buffers — bridge_socks re-applies
        # them too, but setting them early means even the handshake benefits
        # from large buffers.)
        c.setsockopt(socket.IPPROTO_TCP, socket.TCP_NODELAY, 1)
        try: c.setsockopt(socket.SOL_SOCKET, socket.SO_RCVBUF, SOCKET_BUF_SIZE)
        except OSError: pass
        try: c.setsockopt(socket.SOL_SOCKET, socket.SO_SNDBUF, SOCKET_BUF_SIZE)
        except OSError: pass
        threading.Thread(target=handle, args=(c, a), daemon=True).start()

if __name__ == "__main__": main()
PYEOF
    chmod +x "$WS_SSH_BRIDGE_SCRIPT"
}

write_ws_ssh_bridge_service() {
    cat > "$WS_SSH_BRIDGE_SERVICE" <<EOF
[Unit]
Description=TDZ SSH TUNNEL WebSocket-to-SSH Bridge (DarkTunnel payload support)
After=network-online.target ssh.service
Wants=network-online.target

[Service]
Type=simple
Environment=TDZ_WS_BRIDGE_HOST=127.0.0.1
Environment=TDZ_WS_BRIDGE_PORT=${WS_SSH_BRIDGE_PORT}
Environment=TDZ_WS_BRIDGE_SSH_HOST=127.0.0.1
Environment=TDZ_WS_BRIDGE_SSH_PORT=22
ExecStart=${WS_SSH_BRIDGE_SCRIPT}
Restart=always
RestartSec=3
LimitNOFILE=65535
StandardOutput=journal
StandardError=journal

[Install]
WantedBy=multi-user.target
EOF
}

install_ws_ssh_bridge() {
    echo -e "${C_BLUE}Writing WS-to-SSH bridge script...${C_RESET}"
    write_ws_ssh_bridge_script
    write_ws_ssh_bridge_service
    systemctl daemon-reload >/dev/null 2>&1
    systemctl enable tdz-ws-ssh-bridge >/dev/null 2>&1
    systemctl restart tdz-ws-ssh-bridge || {
        echo -e "${C_RED}[ERROR] Failed to start WS-to-SSH bridge.${C_RESET}"
        systemctl status tdz-ws-ssh-bridge --no-pager
        return 1
    }
    sleep 1
    if systemctl is-active --quiet tdz-ws-ssh-bridge; then
        echo -e "${C_GREEN}[OK] WS-to-SSH bridge active on 127.0.0.1:${WS_SSH_BRIDGE_PORT}${C_RESET}"
    else
        echo -e "${C_RED}[ERROR] WS-to-SSH bridge is not active.${C_RESET}"
        return 1
    fi
}

uninstall_ws_ssh_bridge() {
    systemctl stop tdz-ws-ssh-bridge >/dev/null 2>&1
    systemctl disable tdz-ws-ssh-bridge >/dev/null 2>&1
    rm -f "$WS_SSH_BRIDGE_SERVICE" "$WS_SSH_BRIDGE_SCRIPT"
    systemctl daemon-reload >/dev/null 2>&1
}


write_internal_nginx_config() {
    local server_name="$1"
    [[ -z "$server_name" ]] && server_name="_"
    mkdir -p /etc/nginx/sites-available /etc/nginx/sites-enabled
    cat > "$NGINX_CONFIG_FILE" <<EOF
server {
    listen 127.0.0.1:${NGINX_INTERNAL_HTTP_PORT} default_server;
    listen 127.0.0.1:${NGINX_INTERNAL_TLS_PORT} ssl http2 default_server;
    server_tokens off;
    server_name ${server_name};

    ssl_certificate ${SSL_CERT_CHAIN_FILE};
    ssl_certificate_key ${SSL_CERT_KEY_FILE};
    ssl_protocols TLSv1.2 TLSv1.3;
    ssl_ciphers HIGH:!aNULL:!eNULL:!MD5:!DES:!RC4:!ADH:!SSLv3:!EXP:!PSK:!DSS;
    resolver 1.1.1.1 8.8.8.8 ipv6=off valid=300s;

    location ~ ^/(?<fwdport>\d+)/(?<fwdpath>.*)$ {
        client_max_body_size 0;
        client_body_timeout 1d;
        grpc_read_timeout 1d;
        grpc_socket_keepalive on;
        proxy_read_timeout 1d;
        proxy_http_version 1.1;
        proxy_buffering off;
        proxy_request_buffering off;
        proxy_socket_keepalive on;
        proxy_set_header Upgrade \$http_upgrade;
        proxy_set_header Connection "upgrade";
        proxy_set_header Host \$host;
        proxy_set_header X-Real-IP \$remote_addr;
        proxy_set_header X-Forwarded-For \$proxy_add_x_forwarded_for;
        if (\$content_type ~* "GRPC") { grpc_pass grpc://127.0.0.1:\$fwdport\$is_args\$args; break; }
        proxy_pass http://127.0.0.1:\$fwdport\$is_args\$args;
        break;
    }

    location / {
        proxy_read_timeout 3600s;
        proxy_buffering off;
        proxy_request_buffering off;
        proxy_http_version 1.1;
        proxy_socket_keepalive on;
        tcp_nodelay on;
        tcp_nopush off;
        proxy_pass http://127.0.0.1:8080;
        proxy_set_header Upgrade \$http_upgrade;
        proxy_set_header Connection "upgrade";
        proxy_set_header Host \$host;
        proxy_set_header X-Real-IP \$remote_addr;
        proxy_set_header X-Forwarded-For \$proxy_add_x_forwarded_for;
    }
}
EOF
    ln -sf "$NGINX_CONFIG_FILE" /etc/nginx/sites-enabled/default
}

write_haproxy_edge_config() {
    mkdir -p /etc/haproxy
    cat > "$HAPROXY_CONFIG" <<EOF
global
    log /dev/log local0
    log /dev/log local1 notice
    chroot /var/lib/haproxy
    stats socket /run/haproxy/admin.sock mode 660 level admin expose-fd listeners
    stats timeout 30s
    user haproxy
    group haproxy
    daemon
    # tune.* directives MUST live in 'global', not 'defaults' — HAProxy 2.6
    # rejects them in 'defaults' with 'unknown keyword'. Bumping buffer sizes
    # to 4MB lets HAProxy's TCP window match the bridge's 4MB buffers,
    # preventing backpressure stalls that cap throughput at ~20-30 Mbps.
    tune.bufsize 1048576
    tune.rcvbuf.client 4194304
    tune.rcvbuf.server 4194304
    tune.sndbuf.client 4194304
    tune.sndbuf.server 4194304

defaults
    log     global
    mode    tcp
    option  tcplog
    option  dontlognull
    # Increased from 5s -> 2s for faster failure detection on bad backends.
    timeout connect 2s
    timeout client  24h
    timeout server  24h

# ====================================================================
# TIER 1: PORT ${EDGE_PUBLIC_HTTP_PORT} (Cleartext WS Payloads & Raw SSH)
# DarkTunnel / HTTP Custom / NPV send "GET wss://[cf] HTTP/1.1 ... Upgrade: websocket"
# — nginx rejects wss:// absolute-URI with 400, so we route ALL HTTP on this port
# to the dedicated WS-to-SSH bridge which replies 101 + bridges to SSH.
# Raw SSH (SSH-2.0-...) goes direct to sshd.
# ====================================================================
frontend port_80_edge
    bind *:${EDGE_PUBLIC_HTTP_PORT}
    mode tcp
    # Reduced from 2s -> 500ms: DarkTunnel/HTTP Custom/NPV all send their
    # WS upgrade request in the very first packet, so 500ms is plenty of time
    # to identify the protocol. 2s was adding 1.5s of unnecessary latency to
    # every new connection.
    tcp-request inspect-delay 500ms

    acl is_ssh payload(0,7) -m bin 5353482d322e30

    tcp-request content accept if is_ssh
    tcp-request content accept if HTTP

    use_backend direct_ssh if is_ssh
    default_backend ws_ssh_bridge

# ====================================================================
# TIER 1: PORT ${EDGE_PUBLIC_TLS_PORT} (TLS v2ray, SSL Payloads, Raw SSH)
# ====================================================================
frontend port_443_edge
    bind *:${EDGE_PUBLIC_TLS_PORT}
    mode tcp
    tcp-request inspect-delay 500ms

    acl is_ssh payload(0,7) -m bin 5353482d322e30
    acl is_tls req.ssl_hello_type 1
    acl has_web_alpn req.ssl_alpn -m sub h2 http/1.1

    tcp-request content accept if is_ssh
    tcp-request content accept if HTTP
    tcp-request content accept if is_tls

    use_backend direct_ssh if is_ssh
    use_backend nginx_cleartext if HTTP
    use_backend nginx_tls if is_tls has_web_alpn
    default_backend loopback_ssl_terminator

# ====================================================================
# TIER 2: INTERNAL DECRYPTOR (Only for Any-SNI SSH-TLS)
# After TLS is stripped, the inner stream may be:
#   - Raw SSH banner -> direct_ssh
#   - HTTP WS upgrade payload (GET wss://... Upgrade: websocket) -> ws_ssh_bridge
# ====================================================================
frontend internal_decryptor
    bind 127.0.0.1:${HAPROXY_INTERNAL_DECRYPT_PORT} ssl crt ${TDZ_SSL_CERT_FILE}
    mode tcp
    tcp-request inspect-delay 500ms

    acl is_ssh payload(0,7) -m bin 5353482d322e30
    tcp-request content accept if is_ssh
    tcp-request content accept if HTTP

    use_backend direct_ssh if is_ssh
    default_backend ws_ssh_bridge

# ====================================================================
# DESTINATION BACKENDS (Clean handoffs, no proxy headers)
# ====================================================================
backend direct_ssh
    mode tcp
    server ssh_server 127.0.0.1:22

backend ws_ssh_bridge
    mode tcp
    # Removed `option tcp-check` + `check` keyword on server line.
    # These caused HAProxy to open a fresh TCP connection to the bridge every
    # 2 seconds for health checks. Each check made the bridge spawn a thread,
    # accept the conn, send the 101 Switching Protocols response, then try to
    # open an SSH connection that immediately closed. Wasted CPU + file
    # descriptors + created micro-bursts that interfered with active tunnels.
    # systemd already restarts the bridge if it crashes, so HAProxy health
    # checks are redundant here.
    server ws_bridge 127.0.0.1:${WS_SSH_BRIDGE_PORT}

backend nginx_cleartext
    mode tcp
    server nginx_http 127.0.0.1:${NGINX_INTERNAL_HTTP_PORT}

backend nginx_tls
    mode tcp
    server nginx_tls 127.0.0.1:${NGINX_INTERNAL_TLS_PORT}

backend loopback_ssl_terminator
    mode tcp
    server haproxy_ssl 127.0.0.1:${HAPROXY_INTERNAL_DECRYPT_PORT}
EOF
}

save_edge_ports_info() {
    cat > "$NGINX_PORTS_FILE" <<EOF
EDGE_HTTP_PORT="${EDGE_PUBLIC_HTTP_PORT}"
EDGE_TLS_PORT="${EDGE_PUBLIC_TLS_PORT}"
HTTP_PORTS="${NGINX_INTERNAL_HTTP_PORT}"
TLS_PORTS="${NGINX_INTERNAL_TLS_PORT}"
EOF
}

configure_edge_stack() {
    local server_name="$1"
    [[ -z "$server_name" ]] && server_name="_"

    backup_edge_configs

    echo -e "\n${C_BLUE}Writing internal Nginx config (127.0.0.1:${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT})...${C_RESET}"
    write_internal_nginx_config "$server_name"

    echo -e "${C_BLUE}Writing HAProxy edge config (${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT})...${C_RESET}"
    write_haproxy_edge_config

    echo -e "${C_BLUE}Installing WS-to-SSH bridge (DarkTunnel payload support)...${C_RESET}"
    install_ws_ssh_bridge || return 1

    echo -e "\n${C_BLUE}Validating Nginx configuration...${C_RESET}"
    if ! nginx -t >/dev/null 2>&1; then
        echo -e "${C_RED}[ERROR] Nginx configuration validation failed.${C_RESET}"
        nginx -t
        return 1
    fi

    echo -e "${C_BLUE}Validating HAProxy configuration...${C_RESET}"
    if ! haproxy -c -f "$HAPROXY_CONFIG" >/dev/null 2>&1; then
        echo -e "${C_RED}[ERROR] HAProxy configuration validation failed.${C_RESET}"
        haproxy -c -f "$HAPROXY_CONFIG"
        return 1
    fi

    systemctl daemon-reload
    systemctl enable nginx >/dev/null 2>&1
    systemctl enable haproxy >/dev/null 2>&1

    echo -e "\n${C_BLUE}[INFO] Restarting internal Nginx...${C_RESET}"
    systemctl restart nginx || {
        echo -e "${C_RED}[ERROR] Nginx failed to restart.${C_RESET}"
        systemctl status nginx --no-pager
        return 1
    }

    echo -e "${C_BLUE}[INFO] Restarting HAProxy edge...${C_RESET}"
    systemctl restart haproxy || {
        echo -e "${C_RED}[ERROR] HAProxy failed to restart.${C_RESET}"
        systemctl status haproxy --no-pager
        return 1
    }

    sleep 2
    if ! systemctl is-active --quiet nginx; then
        echo -e "${C_RED}[ERROR] Nginx is not active after restart.${C_RESET}"
        systemctl status nginx --no-pager
        return 1
    fi
    if ! systemctl is-active --quiet haproxy; then
        echo -e "${C_RED}[ERROR] HAProxy is not active after restart.${C_RESET}"
        systemctl status haproxy --no-pager
        return 1
    fi

    save_edge_ports_info
    save_edge_port_settings || {
        echo -e "${C_RED}[ERROR] Could not save the public edge port settings.${C_RESET}"
        return 1
    }
    return 0
}

tdz_tcp_port_in_use() {
    local port="$1"
    command -v ss >/dev/null 2>&1 || return 1
    ss -H -lnt "( sport = :$port )" 2>/dev/null | grep -q .
}

validate_edge_public_port() {
    local port="$1" label="$2"
    if ! tdz_is_valid_port_number "$port"; then
        echo -e "${C_RED}[ERROR] ${label} must be a number from 1 to 65535.${C_RESET}"
        return 1
    fi
    if tdz_is_reserved_edge_port "$port"; then
        echo -e "${C_RED}[ERROR] Port ${port} is reserved by an internal TDZ service.${C_RESET}"
        return 1
    fi
    return 0
}

restore_edge_stack_after_port_failure() {
    local rollback_dir="$1"
    local haproxy_was_active="$2" nginx_was_active="$3"
    local haproxy_was_enabled="$4" nginx_was_enabled="$5"

    systemctl stop haproxy nginx >/dev/null 2>&1 || true

    if [[ -f "$rollback_dir/haproxy.cfg" ]]; then
        cp -af "$rollback_dir/haproxy.cfg" "$HAPROXY_CONFIG"
    else
        rm -f "$HAPROXY_CONFIG"
    fi
    if [[ -f "$rollback_dir/nginx-default" ]]; then
        cp -af "$rollback_dir/nginx-default" "$NGINX_CONFIG_FILE"
    else
        rm -f "$NGINX_CONFIG_FILE"
    fi
    if [[ -f "$rollback_dir/nginx_ports.conf" ]]; then
        cp -af "$rollback_dir/nginx_ports.conf" "$NGINX_PORTS_FILE"
    else
        rm -f "$NGINX_PORTS_FILE"
    fi

    systemctl daemon-reload >/dev/null 2>&1 || true
    if [[ "$nginx_was_enabled" == true ]]; then
        systemctl enable nginx >/dev/null 2>&1 || true
    else
        systemctl disable nginx >/dev/null 2>&1 || true
    fi
    if [[ "$haproxy_was_enabled" == true ]]; then
        systemctl enable haproxy >/dev/null 2>&1 || true
    else
        systemctl disable haproxy >/dev/null 2>&1 || true
    fi
    [[ "$nginx_was_active" == true ]] && systemctl start nginx >/dev/null 2>&1 || true
    [[ "$haproxy_was_active" == true ]] && systemctl start haproxy >/dev/null 2>&1 || true
}

apply_edge_public_ports() {
    local new_http="$1" new_tls="$2" force_apply="${3:-false}"
    local old_http="$EDGE_PUBLIC_HTTP_PORT" old_tls="$EDGE_PUBLIC_TLS_PORT"
    local haproxy_was_active=false nginx_was_active=false
    local haproxy_was_enabled=false nginx_was_enabled=false
    local stack_ready=false rollback_dir server_name

    validate_edge_public_port "$new_http" "HTTP/WS port" || return 1
    validate_edge_public_port "$new_tls" "TLS/SSL port" || return 1
    if [[ "$new_http" == "$new_tls" ]]; then
        echo -e "${C_RED}[ERROR] HTTP/WS and TLS/SSL must use different ports.${C_RESET}"
        return 1
    fi

    if [[ "$new_http" == "$old_http" && "$new_tls" == "$old_tls" && "$force_apply" != true ]]; then
        echo -e "${C_YELLOW}[INFO] Those ports are already selected.${C_RESET}"
        return 0
    fi

    systemctl is-active --quiet haproxy && haproxy_was_active=true
    systemctl is-active --quiet nginx && nginx_was_active=true
    systemctl is-enabled --quiet haproxy 2>/dev/null && haproxy_was_enabled=true
    systemctl is-enabled --quiet nginx 2>/dev/null && nginx_was_enabled=true

    if command -v haproxy >/dev/null 2>&1 &&
       command -v nginx >/dev/null 2>&1 &&
       [[ -s "$HAPROXY_CONFIG" && -s "$NGINX_CONFIG_FILE" && -s "$TDZ_SSL_CERT_FILE" ]]; then
        stack_ready=true
    fi

    if [[ "$haproxy_was_active" == true || "$nginx_was_active" == true ]]; then
        if [[ "$stack_ready" != true ]]; then
            echo -e "${C_RED}[ERROR] The running edge stack is incomplete, so its ports cannot be changed safely.${C_RESET}"
            echo -e "${C_DIM}Repair or reinstall the HAProxy edge stack first.${C_RESET}"
            return 1
        fi

        rollback_dir=$(mktemp -d /tmp/tdz-edge-port-rollback.XXXXXX) || return 1
        cp -af "$HAPROXY_CONFIG" "$rollback_dir/haproxy.cfg"
        cp -af "$NGINX_CONFIG_FILE" "$rollback_dir/nginx-default"
        [[ -f "$NGINX_PORTS_FILE" ]] && cp -af "$NGINX_PORTS_FILE" "$rollback_dir/nginx_ports.conf"

        if [[ "$new_http" != "$old_http" ]] && tdz_tcp_port_in_use "$new_http"; then
            echo -e "${C_RED}[ERROR] Port ${new_http} is already in use. No changes were applied.${C_RESET}"
            rm -rf "$rollback_dir"
            return 1
        fi
        if [[ "$new_tls" != "$old_tls" ]] && tdz_tcp_port_in_use "$new_tls"; then
            echo -e "${C_RED}[ERROR] Port ${new_tls} is already in use. No changes were applied.${C_RESET}"
            rm -rf "$rollback_dir"
            return 1
        fi

        if ! check_and_open_firewall_port "$new_http" tcp || ! check_and_open_firewall_port "$new_tls" tcp; then
            rm -rf "$rollback_dir"
            return 1
        fi

        EDGE_PUBLIC_HTTP_PORT="$new_http"
        EDGE_PUBLIC_TLS_PORT="$new_tls"
        load_edge_cert_info
        server_name="${EDGE_DOMAIN:-$(detect_preferred_host)}"
        [[ -z "$server_name" ]] && server_name="_"

        if ! configure_edge_stack "$server_name"; then
            echo -e "${C_RED}[ERROR] The new configuration failed. Restoring the previous working ports...${C_RESET}"
            EDGE_PUBLIC_HTTP_PORT="$old_http"
            EDGE_PUBLIC_TLS_PORT="$old_tls"
            restore_edge_stack_after_port_failure "$rollback_dir" \
                "$haproxy_was_active" "$nginx_was_active" "$haproxy_was_enabled" "$nginx_was_enabled"
            rm -rf "$rollback_dir"
            return 1
        fi

        rm -rf "$rollback_dir"
        echo -e "${C_GREEN}[OK] Public ports changed and the edge stack restarted successfully.${C_RESET}"
    else
        EDGE_PUBLIC_HTTP_PORT="$new_http"
        EDGE_PUBLIC_TLS_PORT="$new_tls"
        if ! save_edge_port_settings; then
            EDGE_PUBLIC_HTTP_PORT="$old_http"
            EDGE_PUBLIC_TLS_PORT="$old_tls"
            echo -e "${C_RED}[ERROR] Could not save the new public ports.${C_RESET}"
            return 1
        fi
        echo -e "${C_GREEN}[OK] Public ports saved. They will be used when the edge stack is installed or reconfigured.${C_RESET}"
    fi

    echo -e "   • HTTP/WS: ${C_YELLOW}${EDGE_PUBLIC_HTTP_PORT}${C_RESET}"
    echo -e "   • TLS/SSL: ${C_YELLOW}${EDGE_PUBLIC_TLS_PORT}${C_RESET}"
    echo -e "   • Internal Nginx: ${C_YELLOW}${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}${C_RESET}"
    return 0
}

edge_public_port_menu() {
    while true; do
        clear; show_banner
        echo
        tdz_box_top
        tdz_box_header "PUBLIC PORT MANAGEMENT"
        tdz_box_divider
        tdz_kv2 "HTTP/WS" "$EDGE_PUBLIC_HTTP_PORT" "TLS/SSL" "$EDGE_PUBLIC_TLS_PORT"
        tdz_kv2 "DEFAULT" "${DEFAULT_EDGE_PUBLIC_HTTP_PORT}/${DEFAULT_EDGE_PUBLIC_TLS_PORT}" "BACKEND" "${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}"
        tdz_box_divider
        tdz_menu1 "[ 1]" "Change HTTP/WS Port"
        tdz_menu1 "[ 2]" "Change TLS/SSL Port"
        tdz_menu1 "[ 3]" "Change Both Public Ports"
        tdz_menu1 "[ 4]" "Restore Default Public Ports"
        tdz_menu1 "[ 5]" "Apply or Repair Current Port Layout"
        tdz_box_divider
        tdz_menu1 "[ 0]" "Return"
        tdz_box_bot
        echo
        read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" port_choice

        local new_http="$EDGE_PUBLIC_HTTP_PORT" new_tls="$EDGE_PUBLIC_TLS_PORT" force_apply=false
        case "$port_choice" in
            1) read -r -p "  New HTTP/WS port: " new_http ;;
            2) read -r -p "  New TLS/SSL port: " new_tls ;;
            3)
                read -r -p "  New HTTP/WS port: " new_http
                read -r -p "  New TLS/SSL port: " new_tls
                ;;
            4)
                new_http="$DEFAULT_EDGE_PUBLIC_HTTP_PORT"
                new_tls="$DEFAULT_EDGE_PUBLIC_TLS_PORT"
                ;;
            5) force_apply=true ;;
            0) return ;;
            *) invalid_option; continue ;;
        esac

        validate_edge_public_port "$new_http" "HTTP/WS port" || { press_enter; continue; }
        validate_edge_public_port "$new_tls" "TLS/SSL port" || { press_enter; continue; }
        if [[ "$new_http" == "$new_tls" ]]; then
            echo -e "${C_RED}[ERROR] HTTP/WS and TLS/SSL must use different ports.${C_RESET}"
            press_enter
            continue
        fi

        echo -e "\n${C_YELLOW}New public ports: HTTP/WS ${new_http}, TLS/SSL ${new_tls}.${C_RESET}"
        echo -e "${C_DIM}If the edge stack is running, active connections will briefly disconnect during restart.${C_RESET}"
        read -r -p "  Apply this configuration? (y/n): " confirm
        if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
            apply_edge_public_ports "$new_http" "$new_tls" "$force_apply"
        else
            echo -e "${C_YELLOW}Cancelled.${C_RESET}"
        fi
        press_enter
    done
}

install_ssl_tunnel() {
    clear; show_banner
    tdz_screen_title "INSTALL HAPROXY EDGE STACK" \
        "Public ${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT} → Nginx ${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}"
    echo -e "\n${C_CYAN}This installer will configure:${C_RESET}"
    echo -e "   • HAProxy on ${C_WHITE}${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT}${C_RESET}"
    echo -e "   • Internal Nginx on ${C_WHITE}${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}${C_RESET}"
    echo -e "   • Loopback SSL decryptor on ${C_WHITE}${HAPROXY_INTERNAL_DECRYPT_PORT}${C_RESET}"

    if [ -f "$HAPROXY_CONFIG" ] || [ -f "$NGINX_CONFIG_FILE" ]; then
        echo -e "\n${C_YELLOW}[WARNING] Existing HAProxy/Nginx configs will be replaced with the TDZ SSH TUNNEL edge layout.${C_RESET}"
        read -p "  Continue with the replacement? (y/n): " confirm_replace
        if [[ "$confirm_replace" != "y" && "$confirm_replace" != "Y" ]]; then
            tdz_message CANCELLED "Installation cancelled."
            return
        fi
    fi

    mkdir -p "$DB_DIR" "$SSL_CERT_DIR"

    ensure_edge_stack_packages || return

    systemctl stop haproxy >/dev/null 2>&1
    systemctl stop nginx >/dev/null 2>&1
    sleep 1

    check_and_free_ports \
        "$EDGE_PUBLIC_HTTP_PORT" \
        "$EDGE_PUBLIC_TLS_PORT" \
        "$NGINX_INTERNAL_HTTP_PORT" \
        "$NGINX_INTERNAL_TLS_PORT" \
        "$HAPROXY_INTERNAL_DECRYPT_PORT" || return

    check_and_open_firewall_port "$EDGE_PUBLIC_HTTP_PORT" tcp || return
    check_and_open_firewall_port "$EDGE_PUBLIC_TLS_PORT" tcp || return

    select_edge_certificate || return

    load_edge_cert_info
    local server_name="${EDGE_DOMAIN:-$(detect_preferred_host)}"
    [[ -z "$server_name" ]] && server_name="_"

    configure_edge_stack "$server_name" || return

    echo -e "\n${C_GREEN}[OK] HAProxy edge stack is active.${C_RESET}"
    echo -e "   • Public edge ports: ${C_YELLOW}${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT}${C_RESET}"
    echo -e "   • Internal Nginx ports: ${C_YELLOW}${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}${C_RESET}"
    echo -e "   • Shared certificate: ${C_YELLOW}${EDGE_CERT_MODE:-unknown}${C_RESET}"
}

uninstall_ssl_tunnel() {
    tdz_screen_title "UNINSTALL HAPROXY EDGE STACK"
    if ! command -v haproxy &> /dev/null; then
        echo -e "${C_YELLOW}[INFO] HAProxy is not installed, skipping service removal.${C_RESET}"
    else
        echo -e "${C_GREEN}Stopping and disabling HAProxy...${C_RESET}"
        systemctl stop haproxy >/dev/null 2>&1
        systemctl disable haproxy >/dev/null 2>&1
    fi

    if [ -f "$HAPROXY_CONFIG" ]; then
        cat > "$HAPROXY_CONFIG" <<EOF
global
    log /dev/log local0
    log /dev/log local1 notice

defaults
    log     global
EOF
    fi

    local delete_cert="n"
    if [[ "$UNINSTALL_MODE" == "silent" ]]; then
        delete_cert="y"
    elif [ -f "$TDZ_SSL_CERT_FILE" ] || [ -f "$SSL_CERT_CHAIN_FILE" ] || [ -f "$SSL_CERT_KEY_FILE" ]; then
        if systemctl is-active --quiet nginx; then
            echo -e "${C_YELLOW}[WARNING] The shared certificate is also used by the internal Nginx proxy.${C_RESET}"
        fi
        read -p "  Delete the shared TLS certificate too? (y/n): " delete_cert
    fi

    if [[ "$delete_cert" == "y" || "$delete_cert" == "Y" ]]; then
        if systemctl is-active --quiet nginx; then
            echo -e "${C_GREEN}Stopping Nginx because the shared certificate is being removed...${C_RESET}"
            systemctl stop nginx >/dev/null 2>&1
        fi
        rm -f "$TDZ_SSL_CERT_FILE" "$SSL_CERT_CHAIN_FILE" "$SSL_CERT_KEY_FILE" "$EDGE_CERT_INFO_FILE"
        rm -f "$NGINX_PORTS_FILE"
        echo -e "${C_GREEN}Shared certificate files removed.${C_RESET}"
    fi

    echo -e "${C_GREEN}[OK] HAProxy edge stack has been removed.${C_RESET}"
    echo -e "${C_GREEN}Stopping WS-to-SSH bridge...${C_RESET}"
    uninstall_ws_ssh_bridge
    if systemctl is-active --quiet nginx; then
        echo -e "${C_DIM}The internal Nginx proxy is still installed on ${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}.${C_RESET}"
    fi
}

show_dnstt_details() {
    if [ -f "$DNSTT_CONFIG_FILE" ]; then
        source "$DNSTT_CONFIG_FILE"
        echo
        tdz_section "DNSTT CONNECTION DETAILS"
        tdz_detail "Tunnel Domain" "$TUNNEL_DOMAIN" "$C_YELLOW"
        tdz_detail "Public Key" "$PUBLIC_KEY" "$C_YELLOW"
        if [[ -n "$FORWARD_DESC" ]]; then
            tdz_detail "Forwarding To" "$FORWARD_DESC"
        else
            tdz_detail "Forwarding To" "Unknown (config missing)" "$C_YELLOW"
        fi
        if [[ -n "$MTU_VALUE" ]]; then
            tdz_detail "MTU" "$MTU_VALUE" "$C_YELLOW"
        fi
        if [[ "$DNSTT_RECORDS_MANAGED" == "false" && -n "$NS_DOMAIN" ]]; then
            tdz_detail "NS Record" "$NS_DOMAIN" "$C_YELLOW"
        fi
        
        if [[ "$FORWARD_DESC" == *"V2Ray"* ]]; then
            tdz_detail "Action Required" "Run V2Ray (VLESS/VMess/Trojan) on port 8787 without TLS" "$C_YELLOW"
        elif [[ "$FORWARD_DESC" == *"SSH"* ]]; then
            tdz_detail "Action Required" "Configure the SSH client to use this DNS tunnel" "$C_YELLOW"
        fi
        
        echo -e "\n${C_DIM}Use these details in your client configuration.${C_RESET}"
    else
        echo -e "\n${C_YELLOW}[INFO] DNSTT configuration file not found. Details are unavailable.${C_RESET}"
    fi
}

install_dnstt() {
    clear; show_banner
    tdz_screen_title "INSTALL DNSTT" "Configure DNS tunnelling on UDP port 53."
    if [ -f "$DNSTT_SERVICE_FILE" ]; then
        echo -e "\n${C_YELLOW}[INFO] DNSTT is already installed.${C_RESET}"
        show_dnstt_details
        return
    fi
    
    # --- FIX: Force release of Port 53 / Disable systemd-resolved ---
    echo -e "${C_GREEN}Forcing release of Port 53 (stopping systemd-resolved)...${C_RESET}"
    systemctl stop systemd-resolved >/dev/null 2>&1
    systemctl disable systemd-resolved >/dev/null 2>&1
    rm -f /etc/resolv.conf
    echo "nameserver 8.8.8.8" | tee /etc/resolv.conf > /dev/null
    # ----------------------------------------------------------------
    
    echo -e "\n${C_BLUE}Checking if port 53 (UDP) is available...${C_RESET}"
    if ss -lunp | grep -q ':53\s'; then
        if [[ $(ps -p $(ss -lunp | grep ':53\s' | grep -oP 'pid=\K[0-9]+') -o comm=) == "systemd-resolve" ]]; then
            echo -e "${C_YELLOW}[WARNING] Port 53 is in use by 'systemd-resolved'.${C_RESET}"
            echo -e "${C_YELLOW}This is the system's DNS stub resolver. It must be disabled to run DNSTT.${C_RESET}"
            read -p "  Allow the script to automatically disable it and reconfigure DNS? (y/n): " resolve_confirm
            if [[ "$resolve_confirm" == "y" || "$resolve_confirm" == "Y" ]]; then
                echo -e "${C_GREEN}Stopping and disabling systemd-resolved to free port 53...${C_RESET}"
                systemctl stop systemd-resolved
                systemctl disable systemd-resolved
                chattr -i /etc/resolv.conf &>/dev/null
                rm -f /etc/resolv.conf
                echo "nameserver 8.8.8.8" > /etc/resolv.conf
                chattr +i /etc/resolv.conf
                echo -e "${C_GREEN}[OK] Port 53 has been freed and DNS set to 8.8.8.8.${C_RESET}"
            else
                echo -e "${C_RED}[ERROR] Cannot proceed without freeing port 53. Aborting.${C_RESET}"
                return
            fi
        else
            check_and_free_ports "53" || return
        fi
    else
        echo -e "${C_GREEN}[OK] Port 53 (UDP) is free to use.${C_RESET}"
    fi

    check_and_open_firewall_port 53 udp || return



    local forward_port=""
    local forward_desc=""
    echo
    tdz_box_top
    tdz_box_header "DNSTT FORWARD TARGET"
    tdz_box_divider
    tdz_menu1 "[ 1]" "Local SSH Service (Port 22)"
    tdz_menu1 "[ 2]" "Local V2Ray Backend (Port 8787)"
    tdz_box_bot
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Select a target [2]: ${C_RESET}")" fwd_choice
    fwd_choice=${fwd_choice:-2}
    if [[ "$fwd_choice" == "1" ]]; then
        forward_port="22"
        forward_desc="SSH (port 22)"
        echo -e "${C_GREEN}[INFO] DNSTT will forward to SSH on 127.0.0.1:22.${C_RESET}"
        

        
    elif [[ "$fwd_choice" == "2" ]]; then
        forward_port="8787"
        forward_desc="V2Ray (port 8787)"
        echo -e "${C_GREEN}[INFO] DNSTT will forward to V2Ray on 127.0.0.1:8787.${C_RESET}"
    else
        echo -e "${C_RED}[ERROR] Invalid choice. Aborting.${C_RESET}"
        return
    fi
    local FORWARD_TARGET="127.0.0.1:$forward_port"

    local NS_DOMAIN=""
    local TUNNEL_DOMAIN=""
    local DNSTT_RECORDS_MANAGED="false"

    echo -e "\n${C_BLUE}[INFO] DNSTT requires two DNS records that you must create yourself:${C_RESET}"
    echo -e "   ${C_CYAN}1.${C_RESET} An NS record pointing a tunnel subdomain to a nameserver subdomain"
    echo -e "   ${C_CYAN}2.${C_RESET} An A record pointing the nameserver subdomain to this server's IP"
    echo -e "   ${C_DIM}(The script will not create these for you — set them up at your DNS provider.)${C_RESET}"
    echo
    read -p "  Enter your full nameserver domain (e.g., ns1.yourdomain.com): " NS_DOMAIN
    if [[ -z "$NS_DOMAIN" ]]; then echo -e "\n${C_RED}[ERROR] Nameserver domain cannot be empty. Aborting.${C_RESET}"; return; fi
    read -p "  Enter your full tunnel domain (e.g., tun.yourdomain.com): " TUNNEL_DOMAIN
    if [[ -z "$TUNNEL_DOMAIN" ]]; then echo -e "\n${C_RED}[ERROR] Tunnel domain cannot be empty. Aborting.${C_RESET}"; return; fi

    read -p "  Enter MTU value (e.g., 512, 1200) or press [Enter] for default: " mtu_value
    local mtu_string=""
    if [[ "$mtu_value" =~ ^[0-9]+$ ]]; then
        mtu_string=" -mtu $mtu_value"
        echo -e "${C_GREEN}[INFO] Using MTU: $mtu_value${C_RESET}"
    else
        mtu_value=""
        echo -e "${C_YELLOW}[INFO] Using default MTU.${C_RESET}"
    fi

    echo -e "\n${C_BLUE}Downloading pre-compiled DNSTT server binary...${C_RESET}"
    local arch
    arch=$(uname -m)
    local binary_url=""
    if [[ "$arch" == "x86_64" ]]; then
        binary_url="https://dnstt.network/dnstt-server-linux-amd64"
        echo -e "${C_BLUE}[INFO] Detected x86_64 (amd64) architecture.${C_RESET}"
    elif [[ "$arch" == "aarch64" || "$arch" == "arm64" ]]; then
        binary_url="https://dnstt.network/dnstt-server-linux-arm64"
        echo -e "${C_BLUE}[INFO] Detected ARM64 architecture.${C_RESET}"
    else
        echo -e "\n${C_RED}[ERROR] Unsupported architecture: $arch. Cannot install DNSTT.${C_RESET}"
        return
    fi
    
    curl -sL "$binary_url" -o "$DNSTT_BINARY"
    if [ $? -ne 0 ]; then
        echo -e "\n${C_RED}[ERROR] Failed to download the DNSTT binary.${C_RESET}"
        return
    fi
    chmod +x "$DNSTT_BINARY"

    echo -e "${C_BLUE}Generating cryptographic keys...${C_RESET}"
    mkdir -p "$DNSTT_KEYS_DIR"
    "$DNSTT_BINARY" -gen-key -privkey-file "$DNSTT_KEYS_DIR/server.key" -pubkey-file "$DNSTT_KEYS_DIR/server.pub"
    if [[ ! -f "$DNSTT_KEYS_DIR/server.key" ]]; then echo -e "${C_RED}[ERROR] Failed to generate DNSTT keys.${C_RESET}"; return; fi
    
    local PUBLIC_KEY
    PUBLIC_KEY=$(cat "$DNSTT_KEYS_DIR/server.pub")
    
    echo -e "\n${C_BLUE}Creating systemd service...${C_RESET}"
    cat > "$DNSTT_SERVICE_FILE" <<-EOF
[Unit]
Description=DNSTT (DNS Tunnel) Server for $forward_desc
After=network.target
[Service]
Type=simple
User=root
ExecStart=$DNSTT_BINARY -udp :53$mtu_string -privkey-file $DNSTT_KEYS_DIR/server.key $TUNNEL_DOMAIN $FORWARD_TARGET
Restart=always
RestartSec=3
[Install]
WantedBy=multi-user.target
EOF
    echo -e "\n${C_BLUE}Saving configuration and starting service...${C_RESET}"
    cat > "$DNSTT_CONFIG_FILE" <<-EOF
NS_SUBDOMAIN="$NS_SUBDOMAIN"
TUNNEL_SUBDOMAIN="$TUNNEL_SUBDOMAIN"
NS_DOMAIN="$NS_DOMAIN"
TUNNEL_DOMAIN="$TUNNEL_DOMAIN"
PUBLIC_KEY="$PUBLIC_KEY"
FORWARD_DESC="$forward_desc"
DNSTT_RECORDS_MANAGED="$DNSTT_RECORDS_MANAGED"
HAS_IPV6="$HAS_IPV6"
MTU_VALUE="$mtu_value"
EOF
    systemctl daemon-reload
    systemctl enable dnstt.service
    systemctl start dnstt.service
    sleep 2
    if systemctl is-active --quiet dnstt.service; then
        echo -e "\n${C_GREEN}[OK] DNSTT has been installed and started!${C_RESET}"
        show_dnstt_details
    else
        echo -e "\n${C_RED}[ERROR] DNSTT service failed to start.${C_RESET}"
        journalctl -u dnstt.service -n 15 --no-pager
    fi
}

uninstall_dnstt() {
    tdz_screen_title "UNINSTALL DNSTT"
    if [ ! -f "$DNSTT_SERVICE_FILE" ]; then
        echo -e "${C_YELLOW}[INFO] DNSTT does not appear to be installed, skipping.${C_RESET}"
        return
    fi
    local confirm="y"
    if [[ "$UNINSTALL_MODE" != "silent" ]]; then
        read -p "  Are you sure you want to uninstall DNSTT? (y/n): " confirm
    fi
    if [[ "$confirm" != "y" ]]; then
        tdz_message CANCELLED "Uninstallation cancelled."
        return
    fi
    echo -e "${C_BLUE}Stopping and disabling DNSTT service...${C_RESET}"
    systemctl stop dnstt.service > /dev/null 2>&1
    systemctl disable dnstt.service > /dev/null 2>&1
    if [ -f "$DNSTT_CONFIG_FILE" ]; then
        source "$DNSTT_CONFIG_FILE"
        echo -e "${C_YELLOW}[WARNING] DNS records (NS + A) for $NS_DOMAIN / $TUNNEL_DOMAIN were configured manually.${C_RESET}"
        echo -e "${C_YELLOW}   Please delete them at your DNS provider if no longer needed.${C_RESET}"
    fi
    echo -e "${C_BLUE}Removing service files and binaries...${C_RESET}"
    rm -f "$DNSTT_SERVICE_FILE"
    rm -f "$DNSTT_BINARY"
    rm -rf "$DNSTT_KEYS_DIR"
    rm -f "$DNSTT_CONFIG_FILE"
    systemctl daemon-reload
    
    echo -e "${C_YELLOW}[INFO] Making /etc/resolv.conf writable again...${C_RESET}"
    chattr -i /etc/resolv.conf &>/dev/null

    echo -e "\n${C_GREEN}[OK] DNSTT has been successfully uninstalled.${C_RESET}"
}

install_tdz_proxy() {
    clear; show_banner
    tdz_screen_title "INSTALL TDZ PROXY" "Install the WebSocket and SOCKS proxy service."
    
    if [ -f "$TDZPROXY_SERVICE_FILE" ]; then
        echo -e "\n${C_YELLOW}[INFO] TDZ Proxy is already installed.${C_RESET}"
        if [ -f "$TDZPROXY_CONFIG_FILE" ]; then
            source "$TDZPROXY_CONFIG_FILE"
            echo -e "   It is configured to run on port(s): ${C_YELLOW}$PORTS${C_RESET}"
            echo -e "   Installed Version: ${C_YELLOW}${INSTALLED_VERSION:-Unknown}${C_RESET}"
        fi
        read -p "  Do you want to reinstall/update? (y/n): " confirm_reinstall
        if [[ "$confirm_reinstall" != "y" ]]; then return; fi
    fi

    echo -e "\n${C_BLUE}Fetching available versions from GitHub...${C_RESET}"
    local releases_json=$(curl -s "https://api.github.com/repos/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/releases")
    if [[ -z "$releases_json" || "$releases_json" == "[]" ]]; then
        echo -e "${C_RED}[ERROR] Could not fetch releases. Check internet or API limits.${C_RESET}"
        return
    fi

    # Extract tag names
    mapfile -t versions < <(echo "$releases_json" | jq -r '.[].tag_name')
    
    if [ ${#versions[@]} -eq 0 ]; then
        echo -e "${C_RED}[ERROR] No releases found in the repository.${C_RESET}"
        return
    fi

    local choice version_number
    echo
    tdz_box_top
    tdz_box_header "TDZ PROXY VERSION"
    tdz_box_divider
    for i in "${!versions[@]}"; do
        printf -v version_number "[%2d]" "$((i+1))"
        tdz_menu1 "$version_number" "${versions[$i]}"
    done
    tdz_box_divider
    tdz_menu1 "[ 0]" "Cancel"
    tdz_box_bot
    echo

    while true; do
        if ! read -r -p "$(echo -e "${C_PROMPT}  Select a version [1]: ${C_RESET}")" choice; then
            echo
            return
        fi
        choice=${choice:-1}
        if [[ "$choice" == "0" ]]; then return; fi
        if [[ "$choice" =~ ^[0-9]+$ ]] && [ "$choice" -le "${#versions[@]}" ]; then
            SELECTED_VERSION="${versions[$((choice-1))]}"
            break
        else
            echo -e "${C_RED}[ERROR] Invalid selection.${C_RESET}"
        fi
    done

    local ports
    read -p "  Enter port(s) for TDZ Proxy (e.g., 8080 or 8080 8888) [8080]: " ports
    ports=${ports:-8080}

    local port_array=($ports)
    for port in "${port_array[@]}"; do
        if ! [[ "$port" =~ ^[0-9]+$ ]] || [ "$port" -lt 1 ] || [ "$port" -gt 65535 ]; then
            echo -e "\n${C_RED}[ERROR] Invalid port number: $port. Aborting.${C_RESET}"
            return
        fi
        check_and_free_ports "$port" || return
        check_and_open_firewall_port "$port" tcp || return
    done

    echo -e "\n${C_GREEN}Detecting system architecture...${C_RESET}"
    local arch=$(uname -m)
    local binary_name=""
    if [[ "$arch" == "x86_64" ]]; then
        binary_name="tdzproxy"
        echo -e "${C_BLUE}[INFO] Detected x86_64 (amd64) architecture.${C_RESET}"
    elif [[ "$arch" == "aarch64" || "$arch" == "arm64" ]]; then
        binary_name="tdzproxyarm"
        echo -e "${C_BLUE}[INFO] Detected ARM64 architecture.${C_RESET}"
    else
        echo -e "\n${C_RED}[ERROR] Unsupported architecture: $arch. Cannot install TDZ Proxy.${C_RESET}"
        return
    fi
    
    # Construct download URL based on selected version
    local download_url="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/releases/download/$SELECTED_VERSION/$binary_name"

    echo -e "\n${C_GREEN}Downloading TDZ Proxy $SELECTED_VERSION ($binary_name)...${C_RESET}"
    wget -q --show-progress -O "$TDZPROXY_BINARY" "$download_url"
    if [ $? -ne 0 ]; then
        echo -e "\n${C_RED}[ERROR] Failed to download the binary. Please ensure version $SELECTED_VERSION has asset '$binary_name'.${C_RESET}"
        return
    fi
    chmod +x "$TDZPROXY_BINARY"

    echo -e "\n${C_GREEN}Creating systemd service file...${C_RESET}"
    cat > "$TDZPROXY_SERVICE_FILE" <<EOF
[Unit]
Description=TDZ Proxy ($SELECTED_VERSION)
After=network.target

[Service]
User=root
Type=simple
ExecStart=$TDZPROXY_BINARY -p $ports
Restart=always
RestartSec=2s

[Install]
WantedBy=default.target
EOF

    echo -e "\n${C_GREEN}Saving configuration...${C_RESET}"
    cat > "$TDZPROXY_CONFIG_FILE" <<EOF
PORTS="$ports"
INSTALLED_VERSION="$SELECTED_VERSION"
EOF

    echo -e "\n${C_BLUE}[INFO] Enabling and starting TDZ Proxy service...${C_RESET}"
    systemctl daemon-reload
    systemctl enable tdzproxy.service
    systemctl restart tdzproxy.service
    sleep 2
    
    if systemctl is-active --quiet tdzproxy; then
        echo -e "\n${C_GREEN}[OK] TDZ Proxy $SELECTED_VERSION is installed and active.${C_RESET}"
        echo -e "   Listening on port(s): ${C_YELLOW}$ports${C_RESET}"
    else
        echo -e "\n${C_RED}[ERROR] TDZ Proxy service failed to start.${C_RESET}"
        echo -e "${C_YELLOW}[INFO] Displaying last 15 lines of the service log for diagnostics:${C_RESET}"
        journalctl -u tdzproxy.service -n 15 --no-pager
    fi
}

uninstall_tdz_proxy() {
    tdz_screen_title "UNINSTALL TDZ PROXY"
    if [ ! -f "$TDZPROXY_SERVICE_FILE" ]; then
        echo -e "${C_YELLOW}[INFO] TDZ Proxy is not installed, skipping.${C_RESET}"
        return
    fi
    echo -e "${C_GREEN}Stopping and disabling TDZ Proxy service...${C_RESET}"
    systemctl stop tdzproxy.service >/dev/null 2>&1
    systemctl disable tdzproxy.service >/dev/null 2>&1
    echo -e "${C_GREEN}Removing service file...${C_RESET}"
    rm -f "$TDZPROXY_SERVICE_FILE"
    systemctl daemon-reload
    echo -e "${C_GREEN}Removing binary and config files...${C_RESET}"
    rm -f "$TDZPROXY_BINARY"
    rm -f "$TDZPROXY_CONFIG_FILE"
    echo -e "${C_GREEN}[OK] TDZ Proxy has been uninstalled successfully.${C_RESET}"
}

# --- ZiVPN Installation Logic ---
install_zivpn() {
    clear; show_banner
    tdz_screen_title "INSTALL ZIVPN" "Configure the UDP VPN service on port 5667."
    
    if [ -f "$ZIVPN_SERVICE_FILE" ]; then
        echo -e "\n${C_YELLOW}[INFO] ZiVPN is already installed.${C_RESET}"
        return
    fi

    check_and_free_ports 5667 || return
    check_and_open_firewall_port 5667 udp || return
    check_and_open_firewall_port_range "6000:19999" udp || return

    echo -e "\n${C_GREEN}Checking system architecture...${C_RESET}"
    local arch=$(uname -m)
    local zivpn_url=""
    
    if [[ "$arch" == "x86_64" ]]; then
        zivpn_url="https://github.com/zahidbd2/udp-zivpn/releases/download/udp-zivpn_1.4.9/udp-zivpn-linux-amd64"
        echo -e "${C_BLUE}[INFO] Detected AMD64/x86_64 architecture.${C_RESET}"
    elif [[ "$arch" == "aarch64" ]]; then
        zivpn_url="https://github.com/zahidbd2/udp-zivpn/releases/download/udp-zivpn_1.4.9/udp-zivpn-linux-arm64"
        echo -e "${C_BLUE}[INFO] Detected ARM64 architecture.${C_RESET}"
    elif [[ "$arch" == "armv7l" || "$arch" == "arm" ]]; then
         zivpn_url="https://github.com/zahidbd2/udp-zivpn/releases/download/udp-zivpn_1.4.9/udp-zivpn-linux-arm"
         echo -e "${C_BLUE}[INFO] Detected ARM architecture.${C_RESET}"
    else
        echo -e "${C_RED}[ERROR] Unsupported architecture: $arch${C_RESET}"
        return
    fi

    echo -e "\n${C_GREEN}Downloading ZiVPN binary...${C_RESET}"
    if ! wget -q --show-progress -O "$ZIVPN_BIN" "$zivpn_url"; then
        echo -e "${C_RED}[ERROR] Download failed. Check internet connection.${C_RESET}"
        return
    fi
    chmod +x "$ZIVPN_BIN"

    echo -e "\n${C_GREEN}Configuring ZIVPN...${C_RESET}"
    mkdir -p "$ZIVPN_DIR"
    
    # Generate Certificates
    echo -e "${C_BLUE}Generating self-signed certificates...${C_RESET}"
    if ! command -v openssl &>/dev/null; then
        tdz_apt_install openssl >/dev/null 2>&1 || {
            echo -e "${C_RED}[ERROR] Failed to install openssl for ZiVPN certificate generation.${C_RESET}"
            return
        }
    fi
    
    openssl req -new -newkey rsa:4096 -days 365 -nodes -x509 \
        -subj "/C=US/ST=California/L=Los Angeles/O=Example Corp/OU=IT Department/CN=zivpn" \
        -keyout "$ZIVPN_KEY_FILE" -out "$ZIVPN_CERT_FILE" 2>/dev/null

    if [ ! -f "$ZIVPN_CERT_FILE" ]; then
        echo -e "${C_RED}[ERROR] Failed to generate certificates.${C_RESET}"
        return
    fi

    # System Tuning
    echo -e "${C_BLUE}Tuning system network parameters...${C_RESET}"
    sysctl -w net.core.rmem_max=16777216 >/dev/null
    sysctl -w net.core.wmem_max=16777216 >/dev/null

    # Create Service
    echo -e "${C_BLUE}Creating systemd service file...${C_RESET}"
    cat <<EOF > "$ZIVPN_SERVICE_FILE"
[Unit]
Description=zivpn VPN Server
After=network.target

[Service]
Type=simple
User=root
WorkingDirectory=$ZIVPN_DIR
ExecStart=$ZIVPN_BIN server -c $ZIVPN_CONFIG_FILE
Restart=always
RestartSec=3
Environment=ZIVPN_LOG_LEVEL=info
CapabilityBoundingSet=CAP_NET_ADMIN CAP_NET_BIND_SERVICE CAP_NET_RAW
AmbientCapabilities=CAP_NET_ADMIN CAP_NET_BIND_SERVICE CAP_NET_RAW
NoNewPrivileges=true

[Install]
WantedBy=multi-user.target
EOF

    # Configure Passwords
    echo -e "\n${C_YELLOW}ZiVPN Password Setup${C_RESET}"
    read -p "  Enter passwords separated by commas (e.g., user1,user2) [Default: 'zi']: " input_config
    
    if [ -n "$input_config" ]; then
        IFS=',' read -r -a config_array <<< "$input_config"
        # Ensure array format for JSON
        json_passwords=$(printf '"%s",' "${config_array[@]}")
        json_passwords="[${json_passwords%,}]"
    else
        json_passwords='["zi"]'
    fi

    # Create Config File
    cat <<EOF > "$ZIVPN_CONFIG_FILE"
{
  "listen": ":5667",
   "cert": "$ZIVPN_CERT_FILE",
   "key": "$ZIVPN_KEY_FILE",
   "obfs":"zivpn",
   "auth": {
    "mode": "passwords", 
    "config": $json_passwords
  }
}
EOF

    echo -e "\n${C_GREEN}Starting ZiVPN Service...${C_RESET}"
    systemctl daemon-reload
    systemctl enable zivpn.service
    systemctl start zivpn.service

    # Port Forwarding / Firewall
    echo -e "${C_BLUE}Configuring Firewall Rules (Redirecting 6000-19999 -> 5667)...${C_RESET}"
    
    # Determine primary interface
    local iface=$(ip -4 route ls | grep default | grep -Po '(?<=dev )(\S+)' | head -1)
    
    if [ -n "$iface" ]; then
        iptables -t nat -C PREROUTING -i "$iface" -p udp --dport 6000:19999 -j DNAT --to-destination :5667 2>/dev/null || \
            iptables -t nat -A PREROUTING -i "$iface" -p udp --dport 6000:19999 -j DNAT --to-destination :5667
        # Note: IPTables rules are not persistent by default without iptables-persistent package
    else
        echo -e "${C_YELLOW}[WARNING] Could not detect default interface for IPTables redirection.${C_RESET}"
    fi

    # Cleanup
    rm -f zi.sh zi2.sh 2>/dev/null

    if systemctl is-active --quiet zivpn.service; then
        tdz_message OK "ZiVPN installed and started successfully."
        echo
        tdz_section "ZIVPN CONNECTION DETAILS"
        tdz_detail "Direct UDP Port" "5667"
        tdz_detail "Forwarded Ports" "6000-19999"
    else
        echo -e "\n${C_RED}[ERROR] ZiVPN Service failed to start. Check logs: journalctl -u zivpn.service${C_RESET}"
    fi
}

uninstall_zivpn() {
    clear; show_banner
    tdz_screen_title "UNINSTALL ZIVPN"
    
    if [ ! -f "$ZIVPN_SERVICE_FILE" ] && [ ! -f "$ZIVPN_BIN" ]; then
        echo -e "\n${C_YELLOW}[INFO] ZiVPN does not appear to be installed.${C_RESET}"
        return
    fi

    read -p "  Are you sure you want to uninstall ZiVPN? (y/n): " confirm
    if [[ "$confirm" != "y" ]]; then echo -e "${C_YELLOW}Cancelled.${C_RESET}"; return; fi

    echo -e "\n${C_BLUE}Stopping services...${C_RESET}"
    systemctl stop zivpn.service 2>/dev/null
    systemctl disable zivpn.service 2>/dev/null

    local iface
    iface=$(ip -4 route ls | grep default | grep -Po '(?<=dev )(\S+)' | head -1)
    if [ -n "$iface" ]; then
        iptables -t nat -D PREROUTING -i "$iface" -p udp --dport 6000:19999 -j DNAT --to-destination :5667 2>/dev/null || true
    fi
    
    echo -e "${C_BLUE}Removing files...${C_RESET}"
    rm -f "$ZIVPN_SERVICE_FILE"
    rm -rf "$ZIVPN_DIR"
    rm -f "$ZIVPN_BIN"
    
    systemctl daemon-reload
    
    # Clean cache (from original uninstall script logic)
    echo -e "${C_BLUE}Cleaning memory cache...${C_RESET}"
    sync; echo 3 > /proc/sys/vm/drop_caches

    echo -e "\n${C_GREEN}[OK] ZiVPN Uninstalled Successfully.${C_RESET}"
}

purge_nginx() {
    local mode="$1"
    if [[ "$mode" != "silent" ]]; then
        clear; show_banner
        tdz_screen_title "PURGE INTERNAL NGINX" "Remove Nginx and its TDZ edge configuration." "$C_DANGER"
        if ! command -v nginx &> /dev/null; then
            rm -f "$NGINX_PORTS_FILE"
            echo -e "\n${C_YELLOW}[INFO] Nginx is not installed. Nothing to do.${C_RESET}"
            return
        fi
        echo -e "\n${C_YELLOW}[WARNING] This removes the internal Nginx proxy on ${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}.${C_RESET}"
        if systemctl is-active --quiet haproxy; then
            echo -e "${C_YELLOW}[WARNING] HAProxy will stay installed, but web payload routing from ${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT} will stop until you reinstall the stack.${C_RESET}"
        fi
        read -p "  Continue and purge Nginx? (y/n): " confirm
        if [[ "$confirm" != "y" && "$confirm" != "Y" ]]; then
            tdz_message CANCELLED "Uninstallation cancelled."
            return
        fi
    fi
    echo -e "\n${C_BLUE}Stopping Nginx service...${C_RESET}"
    systemctl stop nginx >/dev/null 2>&1
    systemctl disable nginx >/dev/null 2>&1
    echo -e "\n${C_BLUE}Purging Nginx packages...${C_RESET}"
    tdz_apt_purge nginx nginx-common >/dev/null 2>&1
    apt-get autoremove -y >/dev/null 2>&1
    echo -e "\n${C_BLUE}Removing leftover files...${C_RESET}"
    rm -f /etc/ssl/certs/nginx-selfsigned.pem
    rm -f /etc/ssl/private/nginx-selfsigned.key
    rm -rf /etc/nginx
    rm -f "${NGINX_CONFIG_FILE}.bak"
    rm -f "${NGINX_CONFIG_FILE}.bak.certbot"
    rm -f "${NGINX_CONFIG_FILE}.bak.selfsigned"
    rm -f "${NGINX_CONFIG_FILE}.bak.tdztunnel"
    rm -f "$NGINX_PORTS_FILE"
    if [[ "$mode" != "silent" ]]; then
        echo -e "\n${C_GREEN}[OK] Internal Nginx proxy purged. Shared TDZ SSH TUNNEL certificates were kept.${C_RESET}"
    fi
}

install_nginx_proxy() {
    clear; show_banner
    tdz_screen_title "CONFIGURE INTERNAL NGINX" \
        "Backend ports: ${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}"
    echo -e "\n${C_CYAN}This keeps HAProxy on ${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT} and rewrites the internal Nginx proxy on ${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}.${C_RESET}"

    if [ ! -s "$TDZ_SSL_CERT_FILE" ] || [ ! -s "$SSL_CERT_CHAIN_FILE" ] || [ ! -s "$SSL_CERT_KEY_FILE" ]; then
        echo -e "\n${C_YELLOW}[WARNING] No shared TDZ SSH TUNNEL certificate was found.${C_RESET}"
        echo -e "${C_DIM}Running the full HAProxy edge installer so the certificate and both services stay aligned.${C_RESET}"
        install_ssl_tunnel
        return
    fi

    mkdir -p "$DB_DIR" "$SSL_CERT_DIR"
    ensure_edge_stack_packages || return

    systemctl stop haproxy >/dev/null 2>&1
    systemctl stop nginx >/dev/null 2>&1
    sleep 1

    check_and_free_ports \
        "$EDGE_PUBLIC_HTTP_PORT" \
        "$EDGE_PUBLIC_TLS_PORT" \
        "$NGINX_INTERNAL_HTTP_PORT" \
        "$NGINX_INTERNAL_TLS_PORT" \
        "$HAPROXY_INTERNAL_DECRYPT_PORT" || return

    check_and_open_firewall_port "$EDGE_PUBLIC_HTTP_PORT" tcp || return
    check_and_open_firewall_port "$EDGE_PUBLIC_TLS_PORT" tcp || return

    load_edge_cert_info
    local server_name="${EDGE_DOMAIN:-$(detect_preferred_host)}"
    [[ -z "$server_name" ]] && server_name="_"

    configure_edge_stack "$server_name" || return

    echo -e "\n${C_GREEN}[OK] Internal Nginx proxy reconfigured successfully.${C_RESET}"
    echo -e "   • Public HAProxy edge: ${C_YELLOW}${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT}${C_RESET}"
    echo -e "   • Internal Nginx: ${C_YELLOW}${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}${C_RESET}"
}

request_certbot_ssl() {
    clear; show_banner
    tdz_screen_title "SHARED CERTBOT CERTIFICATE" "Apply one certificate to HAProxy and internal Nginx."
    echo -e "\n${C_DIM}This will replace the shared certificate used by HAProxy on ${EDGE_PUBLIC_TLS_PORT} and internal Nginx on ${NGINX_INTERNAL_TLS_PORT}.${C_RESET}"

    mkdir -p "$DB_DIR" "$SSL_CERT_DIR"
    ensure_edge_stack_packages || return
    load_edge_cert_info

    local preferred_host
    local default_domain=""
    local domain_name
    local email

    preferred_host=$(detect_preferred_host)
    if [[ -n "$EDGE_DOMAIN" ]] && ! _is_valid_ipv4 "$EDGE_DOMAIN"; then
        default_domain="$EDGE_DOMAIN"
    elif [[ -n "$preferred_host" ]] && ! _is_valid_ipv4 "$preferred_host"; then
        default_domain="$preferred_host"
    fi

    if [[ -n "$default_domain" ]]; then
        read -p "  Enter your domain name [$default_domain]: " domain_name
        domain_name=${domain_name:-$default_domain}
    else
        read -p "  Enter your domain name (e.g. vpn.example.com): " domain_name
    fi
    if [[ -z "$domain_name" ]]; then
        echo -e "\n${C_RED}[ERROR] Domain name cannot be empty.${C_RESET}"
        return
    fi
    if _is_valid_ipv4 "$domain_name"; then
        echo -e "\n${C_RED}[ERROR] Certbot requires a real domain name, not a raw IP address.${C_RESET}"
        return
    fi

    read -p "  Enter your email for Let's Encrypt [${EDGE_EMAIL}]: " email
    email=${email:-$EDGE_EMAIL}
    if [[ -z "$email" ]]; then
        echo -e "\n${C_RED}[ERROR] Email address cannot be empty.${C_RESET}"
        return
    fi

    check_and_open_firewall_port "$EDGE_PUBLIC_HTTP_PORT" tcp || return
    check_and_open_firewall_port "$EDGE_PUBLIC_TLS_PORT" tcp || return

    obtain_certbot_edge_cert "$domain_name" "$email" || return
    configure_edge_stack "$domain_name" || return

    echo -e "\n${C_GREEN}[OK] Shared Certbot certificate applied successfully.${C_RESET}"
    echo -e "   • Domain: ${C_YELLOW}${domain_name}${C_RESET}"
    echo -e "   • Public edge: ${C_YELLOW}${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT}${C_RESET}"
}

nginx_proxy_menu() {
    clear; show_banner
    local nginx_status="Inactive" nginx_color="$C_RED"
    local haproxy_status="Inactive" haproxy_color="$C_RED"
    if systemctl is-active --quiet nginx; then
        nginx_status="Active"
        nginx_color="$C_GREEN"
    fi
    if systemctl is-active --quiet haproxy; then
        haproxy_status="Active"
        haproxy_color="$C_GREEN"
    fi

    load_edge_cert_info
    local cert_info="${EDGE_CERT_MODE:-Not configured}"
    if [[ -n "$EDGE_DOMAIN" ]]; then
        cert_info="${cert_info} - ${EDGE_DOMAIN}"
    fi

    echo
    tdz_box_top
    tdz_box_header "INTERNAL NGINX PROXY"
    tdz_box_divider
    tdz_row2 "${C_GRAY}NGINX${C_RESET} ${nginx_color}${nginx_status}${C_RESET}" \
        "${C_GRAY}HAPROXY${C_RESET} ${haproxy_color}${haproxy_status}${C_RESET}"
    tdz_kv2 "PUBLIC" "${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT}" "INTERNAL" "${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}"
    tdz_row "${C_GRAY}CERTIFICATE${C_RESET} ${C_WHITE}${cert_info}${C_RESET}"
    tdz_box_divider
    if systemctl is-active --quiet nginx; then
         tdz_menu1 "[ 1]" "Stop Nginx Service"
         tdz_menu1 "[ 2]" "Restart HAProxy and Nginx Stack"
         tdz_menu1 "[ 3]" "Reinstall or Reconfigure Edge Stack"
         tdz_menu1 "[ 4]" "Switch or Renew Shared SSL"
         tdz_menu1 "[ 5]" "Uninstall and Purge Nginx"
    else
         tdz_menu1 "[ 1]" "Start Nginx Service"
         tdz_menu1 "[ 3]" "Install or Configure Edge Stack"
         tdz_menu1 "[ 4]" "Switch or Renew Shared SSL"
         tdz_menu1 "[ 5]" "Uninstall and Purge Nginx"
    fi
    tdz_box_divider
    tdz_menu1 "[ 0]" "Return to Previous Menu"
    tdz_box_bot
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" choice
    
    case $choice in
        1) 
            if systemctl is-active --quiet nginx; then
                echo -e "\n${C_BLUE}Stopping Nginx...${C_RESET}"
                systemctl stop nginx
                echo -e "${C_GREEN}[OK] Nginx stopped.${C_RESET}"
                if systemctl is-active --quiet haproxy; then
                    echo -e "${C_YELLOW}[WARNING] HAProxy is still running, but web traffic that depends on internal Nginx will not work until Nginx starts again.${C_RESET}"
                fi
            else
                echo -e "\n${C_BLUE}[INFO] Starting Nginx...${C_RESET}"
                systemctl start nginx
                if systemctl is-active --quiet nginx; then
                    echo -e "${C_GREEN}[OK] Nginx started.${C_RESET}"
                else
                    echo -e "${C_RED}[ERROR] Failed to start Nginx.${C_RESET}"
                fi
            fi
            press_enter
            ;;
        2)
            echo -e "\n${C_BLUE}Restarting Nginx and HAProxy...${C_RESET}"
            local restart_ok=true
            systemctl restart nginx || restart_ok=false
            if command -v haproxy &> /dev/null; then
                systemctl restart haproxy || restart_ok=false
            else
                restart_ok=false
            fi
            if $restart_ok && systemctl is-active --quiet nginx && systemctl is-active --quiet haproxy; then
                echo -e "${C_GREEN}[OK] HAProxy + Nginx stack restarted.${C_RESET}"
            else
                echo -e "${C_RED}[ERROR] One or more services failed to restart.${C_RESET}"
            fi
            press_enter
            ;;
        3) 
             install_nginx_proxy; press_enter
             ;;
        4)
             request_certbot_ssl; press_enter
             ;;
        5)
             purge_nginx; press_enter
             ;;
        0) return ;;
        *) invalid_option ;;
    esac
}

install_xui_panel() {
    clear; show_banner
    echo
    tdz_box_top
    tdz_box_header "INSTALL X-UI PANEL"
    tdz_box_divider
    tdz_row "${C_GRAY}VERSION${C_RESET} ${C_WHITE}${XUI_PATCHED_LABEL}${C_RESET}"
    tdz_box_divider
    tdz_menu1 "[ 1]" "Install Patched X-UI"
    tdz_menu1 "[ 0]" "Cancel Installation"
    tdz_box_bot
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" choice
    case $choice in
        1)
            local installer_file installer_hash installer_url
            installer_file=$(mktemp /tmp/tdz-xui-installer.XXXXXX.sh) || {
                echo -e "\n${C_RED}[ERROR] Could not create a temporary installer file.${C_RESET}"
                return 1
            }
            installer_url="https://raw.githubusercontent.com/yeasinulhoquetuhin/x-ui/${XUI_INSTALLER_COMMIT}/install.sh"
            echo -e "\n${C_BLUE}Downloading ${XUI_PATCHED_LABEL} installer...${C_RESET}"
            if ! curl -fLsS --retry 3 --connect-timeout 10 -o "$installer_file" "$installer_url"; then
                rm -f "$installer_file"
                echo -e "${C_RED}[ERROR] Failed to download the patched installer.${C_RESET}"
                return 1
            fi

            installer_hash=$(sha256sum "$installer_file" 2>/dev/null | awk '{print $1}')
            if [[ "$installer_hash" != "$XUI_INSTALLER_SHA256" ]]; then
                rm -f "$installer_file"
                echo -e "${C_RED}[ERROR] Installer integrity check failed. Installation stopped.${C_RESET}"
                return 1
            fi

            # The tagged upstream installer still points fallback files at a
            # non-existent "main" branch. Pin every fallback to the same commit.
            sed -i "s|raw.githubusercontent.com/yeasinulhoquetuhin/x-ui/main/|raw.githubusercontent.com/yeasinulhoquetuhin/x-ui/${XUI_INSTALLER_COMMIT}/|g" "$installer_file"

            echo -e "${C_BLUE}Installing ${XUI_PATCHED_LABEL}...${C_RESET}"
            if bash "$installer_file" "$XUI_PATCHED_TAG"; then
                echo -e "\n${C_GREEN}[OK] ${XUI_PATCHED_LABEL} installed successfully.${C_RESET}"
            else
                echo -e "\n${C_RED}[ERROR] X-UI installation failed.${C_RESET}"
            fi
            rm -f "$installer_file"
            ;;
        0)
            tdz_message CANCELLED "Installation cancelled."
            ;;
        *)
            echo -e "\n${C_RED}[ERROR] Invalid option.${C_RESET}"
            ;;
    esac
}

uninstall_xui_panel() {
    clear; show_banner
    tdz_screen_title "UNINSTALL X-UI PANEL" "Remove the patched panel and its installed files." "$C_DANGER"
    if ! command -v x-ui &> /dev/null; then
        echo -e "\n${C_YELLOW}[INFO] X-UI does not appear to be installed.${C_RESET}"
        return
    fi
    read -p "  Are you sure you want to thoroughly uninstall X-UI? (y/n): " confirm
    if [[ "$confirm" == "y" ]]; then
        echo -e "\n${C_BLUE}Running the default X-UI uninstaller first...${C_RESET}"
        x-ui uninstall >/dev/null 2>&1
        echo -e "\n${C_BLUE}Performing a full cleanup to ensure complete removal...${C_RESET}"
        echo " - Stopping and disabling x-ui service..."
        systemctl stop x-ui >/dev/null 2>&1
        systemctl disable x-ui >/dev/null 2>&1
        echo " - Removing x-ui files and directories..."
        rm -f /etc/systemd/system/x-ui.service
        rm -f /usr/local/bin/x-ui
        rm -rf /usr/local/x-ui/
        rm -rf /etc/x-ui/
        echo " - Reloading systemd daemon..."
        systemctl daemon-reload
        echo -e "\n${C_GREEN}[OK] X-UI has been thoroughly uninstalled.${C_RESET}"
    else
        tdz_message CANCELLED "Uninstallation cancelled."
    fi
}

refresh_ssh_session_cache() {
    local now db_mtime
    now=$(date +%s)
    db_mtime=$(stat -c %Y "$DB_FILE" 2>/dev/null || echo 0)

    if (( SSH_SESSION_CACHE_TS > 0 && now - SSH_SESSION_CACHE_TS < SSH_SESSION_CACHE_TTL && db_mtime == SSH_SESSION_CACHE_DB_MTIME )); then
        return
    fi

    SSH_SESSION_COUNTS=()
    SSH_SESSION_PIDS=()
    SSH_SESSION_TOTAL=0
    SSH_SESSION_CACHE_DB_MTIME=$db_mtime

    if [[ ! -s "$DB_FILE" ]]; then
        SSH_SESSION_CACHE_TS=$now
        return
    fi

    local -A managed_user_lookup=()
    local -A uid_user_lookup=()
    local -A session_pids=()
    local -A loginuid_pids=()
    local -A sshd_session_pids=()
    local -A who_online=()
    local managed_user system_user system_uid ssh_pid ssh_owner candidate_user login_uid

    while IFS=: read -r managed_user _rest; do
        [[ -n "$managed_user" && "$managed_user" != \#* ]] && managed_user_lookup["$managed_user"]=1
    done < "$DB_FILE"

    while IFS=: read -r system_user _ system_uid _rest; do
        [[ -n "$system_user" && "$system_uid" =~ ^[0-9]+$ ]] && uid_user_lookup["$system_uid"]="$system_user"
    done < /etc/passwd

    # ── METHOD A: `who` — catches ALL logged-in users (records utmp).
    # Works for direct-SSH, WS-bridge, HAProxy — any session sshd logged in.
    # This is the primary detector and the most reliable.
    # Also counts distinct login sessions per user (for connection-limit enforcement).
    local who_line
    while read -r who_line; do
        # who output: "username pts/0 2026-06-25 12:34 (1.2.3.4)"
        who_user=$(echo "$who_line" | awk '{print $1}')
        [[ -z "$who_user" ]] && continue
        [[ -n "${managed_user_lookup[$who_user]+x}" ]] || continue
        who_online["$who_user"]=$(( ${who_online["$who_user"]:-0} + 1 ))
    done < <(who 2>/dev/null)

    # ── METHOD B: ps -C sshd — catches pre-shell sshd children owned by user.
    # Backward-compatible secondary detector. Misses users whose shell already exec'd
    # (process is no longer named "sshd"), but Method A covers that.
    while read -r ssh_pid ssh_owner; do
        [[ "$ssh_pid" =~ ^[0-9]+$ ]] || continue

        if [[ -n "$ssh_owner" && "$ssh_owner" != "root" && "$ssh_owner" != "sshd" && -n "${managed_user_lookup[$ssh_owner]+x}" ]]; then
            session_pids["$ssh_owner"]+="$ssh_pid "
            sshd_session_pids["$ssh_owner"]+="$ssh_pid "
        elif [[ -r "/proc/$ssh_pid/loginuid" ]]; then
            login_uid=""
            read -r login_uid < "/proc/$ssh_pid/loginuid" || login_uid=""
            if [[ "$login_uid" =~ ^[0-9]+$ && "$login_uid" != "4294967295" ]]; then
                candidate_user="${uid_user_lookup[$login_uid]}"
                if [[ -n "$candidate_user" && -n "${managed_user_lookup[$candidate_user]+x}" ]]; then
                    loginuid_pids["$candidate_user"]+="$ssh_pid "
                    sshd_session_pids["$candidate_user"]+="$ssh_pid "
                fi
            fi
        fi
    done < <(ps -C sshd -o pid=,user= 2>/dev/null)

    # ── METHOD C: UID-based process scan catches ALL PIDs owned by managed users
    # (bash, sftp-server, scp, etc.). Needed for bandwidth tracking via /proc/$pid/io
    # because Method A (`who`) gives us no PIDs, and Method B misses post-exec shells.
    # Do not use ps user= here: long usernames are truncated by procps.
    local _uid _u _pid
    while read -r _uid _pid; do
        [[ "$_uid" =~ ^[0-9]+$ && "$_pid" =~ ^[0-9]+$ ]] || continue
        _u="${uid_user_lookup[$_uid]:-}"
        [[ -n "$_u" && -n "${managed_user_lookup[$_u]+x}" ]] || continue
        session_pids[$_u]="${session_pids[$_u]}$_pid "
    done < <(ps -eo uid=,pid= --no-headers 2>/dev/null)

    local user pid pid_candidates
    for user in "${!managed_user_lookup[@]}"; do
        declare -A unique_pids=()
        if [[ -n "${session_pids[$user]}" ]]; then
            pid_candidates="${session_pids[$user]}"
        else
            pid_candidates="${loginuid_pids[$user]}"
        fi

        for pid in $pid_candidates; do
            [[ "$pid" =~ ^[0-9]+$ ]] && unique_pids["$pid"]=1
        done

        declare -A unique_sshd_sessions=()
        for pid in ${sshd_session_pids[$user]:-}; do
            [[ "$pid" =~ ^[0-9]+$ ]] && unique_sshd_sessions["$pid"]=1
        done

        # Mark online if `who` shows them OR they have live PIDs
        if [[ -n "${who_online[$user]+x}" || ${#unique_pids[@]} -gt 0 ]]; then
            # CONNS count: sshd sessions are authoritative for tunnel/no-PTY users.
            local _conns=${who_online[$user]:-0}
            if (( ${#unique_sshd_sessions[@]} > _conns )); then
                _conns=${#unique_sshd_sessions[@]}
            fi
            (( _conns == 0 )) && _conns=1
            SSH_SESSION_COUNTS["$user"]=$_conns
            for pid in "${!unique_pids[@]}"; do
                SSH_SESSION_PIDS["$user"]+="$pid "
            done
            SSH_SESSION_TOTAL=$((SSH_SESSION_TOTAL + 1))
        fi
    done

    SSH_SESSION_CACHE_TS=$now
}

count_managed_online_sessions() {
    refresh_ssh_session_cache
    echo "$SSH_SESSION_TOTAL"
}

invalidate_banner_cache() {
    BANNER_CACHE_TS=0
    SSH_SESSION_CACHE_TS=0
    DASH_CACHE_TS=0
}

get_clean_os_name() {
    local os_release_file="${1:-/etc/os-release}"
    local os_name
    os_name=$(awk -F= '
        $1 == "PRETTY_NAME" {
            sub(/^[^=]*=/, "")
            gsub(/^"|"$/, "")
            print
            exit
        }
    ' "$os_release_file" 2>/dev/null)
    os_name=$(printf '%s' "$os_name" | sed -E 's/[[:space:]]+\([^()]*\)[[:space:]]*$//')
    printf '%s\n' "${os_name:-Linux}"
}

refresh_banner_cache() {
    local now
    now=$(date +%s)
    if (( BANNER_CACHE_TS > 0 && now - BANNER_CACHE_TS < BANNER_CACHE_TTL )); then
        return
    fi

    if [[ -z "$BANNER_CACHE_OS_NAME" ]]; then
        BANNER_CACHE_OS_NAME=$(get_clean_os_name)
    fi
    BANNER_CACHE_UP_TIME=$(uptime -p 2>/dev/null | sed 's/up //' || echo "unknown")
    BANNER_CACHE_RAM_USAGE=$(free -m | awk '/^Mem:/{if($2>0){printf "%.2f", $3*100/$2}else{print "0.00"}}')
    BANNER_CACHE_CPU_LOAD=$(awk '{print $1}' /proc/loadavg 2>/dev/null)
    if [[ -s "$DB_FILE" ]]; then
        BANNER_CACHE_TOTAL_USERS=$(grep -c . "$DB_FILE")
    else
        BANNER_CACHE_TOTAL_USERS=0
    fi
    BANNER_CACHE_ONLINE_USERS=$(count_managed_online_sessions)
    BANNER_CACHE_TS=$now
}

# ── Refresh dashboard info cache (location/ISP/IP/domain/perf) ──────────────
# Uses ip-api.com (free, no key, 45 req/min) with a 5-minute cache.
refresh_dashboard_cache() {
    local now
    now=$(date +%s)
    if (( DASH_CACHE_TS > 0 && now - DASH_CACHE_TS < DASH_CACHE_TTL )); then
        return
    fi

    # OS + uptime (local, fast)
    DASH_CACHE_OS_NAME=$(get_clean_os_name | cut -c1-28)
    DASH_CACHE_UPTIME=$(uptime -p 2>/dev/null | sed 's/up //' | cut -c1-20 || echo "unknown")

    # CPU load (1-min avg) + core count (1 core / N cores)
    DASH_CACHE_CPU_LOAD=$(awk '{printf "%.2f", $1}' /proc/loadavg 2>/dev/null || echo "0.00")
    local _cores
    _cores=$(nproc 2>/dev/null || echo 1)
    [[ -z "$_cores" || "$_cores" -lt 1 ]] && _cores=1
    DASH_CACHE_CPU_CORES=$_cores

    # RAM
    local ram_pct ram_used
    ram_pct=$(free | awk '/^Mem:/{if($2>0){printf "%.0f", $3*100/$2}else{print "0"}}')
    ram_used=$(free -h | awk '/^Mem:/{print $3 " / " $2}' 2>/dev/null)
    [[ -z "$ram_pct" ]] && ram_pct="0"
    [[ -z "$ram_used" ]] && ram_used="0 / 0"
    DASH_CACHE_RAM_PCT="$ram_pct"
    DASH_CACHE_RAM_USED="$ram_used"

    # Disk
    DASH_CACHE_DISK_PCT=$(df / 2>/dev/null | awk 'NR==2{gsub(/%/,""); print $5}' || echo "0")

    # User counts
    if [[ -s "$DB_FILE" ]]; then
        DASH_CACHE_TOTAL_USERS=$(grep -c . "$DB_FILE")
    else
        DASH_CACHE_TOTAL_USERS=0
    fi
    DASH_CACHE_ONLINE_USERS=$(count_managed_online_sessions)

    # Custom domain (from edge_cert.conf, set by Domain & SSL menu)
    local domain=""
    if [[ -f "$EDGE_CERT_INFO_FILE" ]]; then
        domain=$(grep -E '^EDGE_DOMAIN=' "$EDGE_CERT_INFO_FILE" 2>/dev/null | head -1 | sed -E 's/^EDGE_DOMAIN=//; s/^"//; s/"$//')
    fi
    [[ -z "$domain" ]] && domain="None"
    DASH_CACHE_DOMAIN="$domain"

    # Location / ISP / Public IP — fetch from ip-api.com (line mode, 4 fields)
    # Fallback to ifconfig.me for IP only if ip-api fails
    local api_data
    api_data=$(curl -s --max-time 4 "http://ip-api.com/line/?fields=country,city,isp,query" 2>/dev/null)
    if [[ -n "$api_data" && $(echo "$api_data" | wc -l) -ge 4 ]]; then
        local country city isp pubip
        country=$(echo "$api_data" | sed -n '1p')
        city=$(echo "$api_data" | sed -n '2p')
        isp=$(echo "$api_data" | sed -n '3p' | cut -c1-28)
        pubip=$(echo "$api_data" | sed -n '4p')
        [[ -n "$country" && -n "$city" ]] && DASH_CACHE_LOCATION="${country}, ${city}"
        [[ -n "$isp" ]] && DASH_CACHE_ISP="$isp"
        [[ -n "$pubip" ]] && DASH_CACHE_PUBLIC_IP="$pubip"
    else
        # Fallback: just get public IP
        local pubip
        pubip=$(curl -4 -s --max-time 4 ifconfig.me 2>/dev/null || echo "N/A")
        DASH_CACHE_PUBLIC_IP="$pubip"
    fi

    DASH_CACHE_TS=$now
}

show_banner() {
    refresh_banner_cache
    refresh_dashboard_cache
    [[ -t 1 ]] && clear
    echo
    # ╔══ Top double-border banner ══╗  (inner width 64)
    echo -e "  ${C_CYAN}╔════════════════════════════════════════════════════════════════╗${C_RESET}"
    # Title line — centered, 64 visible chars
    local title_content="${C_BOLD}${C_CYAN}TDZ SSH TUNNEL${C_RESET} ${C_YELLOW}v0.0.1 BETA${C_RESET}"
    local title_clean="TDZ SSH TUNNEL v0.0.1 BETA"
    local title_pad=$(( (64 - ${#title_clean}) / 2 ))
    [[ $title_pad -lt 0 ]] && title_pad=0
    local title_lpad="" title_rpad=""
    [[ $title_pad -gt 0 ]] && printf -v title_lpad "%${title_pad}s" ""
    local title_rpad_len=$(( 64 - ${#title_clean} - title_pad ))
    [[ $title_rpad_len -lt 0 ]] && title_rpad_len=0
    [[ $title_rpad_len -gt 0 ]] && printf -v title_rpad "%${title_rpad_len}s" ""
    printf "  ${C_CYAN}║${C_RESET}%s%s%s${C_CYAN}║${C_RESET}\n" "$title_lpad" "$title_content" "$title_rpad"
    # Subtitle line — centered
    local sub_content="${C_GRAY}Powered By: @TuhinBroh${C_RESET}"
    local sub_clean="Powered By: @TuhinBroh"
    local sub_pad=$(( (64 - ${#sub_clean}) / 2 ))
    [[ $sub_pad -lt 0 ]] && sub_pad=0
    local sub_lpad="" sub_rpad=""
    [[ $sub_pad -gt 0 ]] && printf -v sub_lpad "%${sub_pad}s" ""
    local sub_rpad_len=$(( 64 - ${#sub_clean} - sub_pad ))
    [[ $sub_rpad_len -lt 0 ]] && sub_rpad_len=0
    [[ $sub_rpad_len -gt 0 ]] && printf -v sub_rpad "%${sub_rpad_len}s" ""
    printf "  ${C_CYAN}║${C_RESET}%s%s%s${C_CYAN}║${C_RESET}\n" "$sub_lpad" "$sub_content" "$sub_rpad"
    echo -e "  ${C_CYAN}╚════════════════════════════════════════════════════════════════╝${C_RESET}"
}

protocol_menu() {
    while true; do
        show_banner
        local badvpn_status="Inactive" badvpn_color="$C_RED"
        local zivpn_status="Inactive" zivpn_color="$C_RED"
        local ssl_tunnel_status="Inactive" ssl_tunnel_color="$C_RED"
        local dnstt_status="Inactive" dnstt_color="$C_RED"
        local nginx_status="Inactive" nginx_color="$C_RED"
        local xui_status="Not Installed" xui_color="$C_RED"
        if systemctl is-active --quiet badvpn; then badvpn_status="Active"; badvpn_color="$C_GREEN"; fi
        if systemctl is-active --quiet zivpn.service; then zivpn_status="Active"; zivpn_color="$C_GREEN"; fi
        if systemctl is-active --quiet haproxy; then
            ssl_tunnel_status="Active"
            ssl_tunnel_color="$C_GREEN"
        fi
        if systemctl is-active --quiet dnstt.service; then dnstt_status="Active"; dnstt_color="$C_GREEN"; fi
        if systemctl is-active --quiet nginx; then nginx_status="Active"; nginx_color="$C_GREEN"; fi
        if command -v x-ui &> /dev/null; then xui_status="Installed"; xui_color="$C_GREEN"; fi

        echo
        tdz_box_top
        tdz_box_header "PROTOCOL & PANEL MANAGEMENT"
        tdz_box_divider
        tdz_row "${C_GRAY}TUNNELLING PROTOCOLS${C_RESET}"
        tdz_menu_status "[ 1]" "Install badvpn (UDP 7300)" "$badvpn_status" "$badvpn_color"
        tdz_menu1 "[ 2]" "Uninstall badvpn"
        tdz_menu_status "[ 3]" "Install HAProxy (${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT})" "$ssl_tunnel_status" "$ssl_tunnel_color"
        tdz_menu1 "[ 4]" "Uninstall HAProxy Edge Stack"
        tdz_menu_status "[ 5]" "Install or View DNSTT (Port 53)" "$dnstt_status" "$dnstt_color"
        tdz_menu1 "[ 6]" "Uninstall DNSTT"
        tdz_menu_status "[ 7]" "Manage Nginx (${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT})" "$nginx_status" "$nginx_color"
        tdz_menu_status "[ 8]" "Install ZiVPN (UDP 5667)" "$zivpn_status" "$zivpn_color"
        tdz_menu1 "[ 9]" "Uninstall ZiVPN"
        tdz_box_divider
        tdz_row "${C_GRAY}MANAGEMENT PANELS${C_RESET}"
        tdz_menu_status "[10]" "Install X-UI ${XUI_PATCHED_LABEL}" "$xui_status" "$xui_color"
        tdz_menu1 "[11]" "Uninstall X-UI Panel"
        tdz_box_divider
        tdz_menu1 "[ 0]" "Return to Main Menu"
        tdz_box_bot
        echo
        if ! read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" choice; then
            echo
            return
        fi
        case $choice in
            1) install_badvpn; press_enter ;; 2) uninstall_badvpn; press_enter ;;
            3) install_ssl_tunnel; press_enter ;; 4) uninstall_ssl_tunnel; press_enter ;;
            5) install_dnstt; press_enter ;; 6) uninstall_dnstt; press_enter ;;
            7) nginx_proxy_menu ;;
            8) install_zivpn; press_enter ;; 9) uninstall_zivpn; press_enter ;;
            10) install_xui_panel; press_enter ;; 11) uninstall_xui_panel; press_enter ;;
            0) return ;;
            *) invalid_option ;;
        esac
    done
}

uninstall_script() {
    clear; show_banner
    tdz_screen_title "UNINSTALL TDZ SSH TUNNEL" \
        "Permanently remove the script, services, and configuration." "$C_DANGER"
    tdz_section "ITEMS TO REMOVE"
    tdz_detail "Main Command" "$(command -v menu)"
    tdz_detail "Configuration" "$DB_DIR"
    tdz_detail "Limiter Service" "$LIMITER_SERVICE"
    tdz_detail "Components" "HAProxy, Nginx, DNSTT, badvpn, udp-custom"
    tdz_message WARNING "This action cannot be undone."
    read -p "  Type 'yes' to confirm and proceed with uninstallation: " confirm
    if [[ "$confirm" != "yes" ]]; then
        tdz_message CANCELLED "Uninstallation cancelled."
        return
    fi
    local -a removable_users=()
    local remove_users_confirm
    local remove_users_on_uninstall=false
    mapfile -t removable_users < <(get_tdztunnel_known_users)
    if [[ ${#removable_users[@]} -gt 0 ]]; then
        echo -e "\n${C_YELLOW}TDZ SSH TUNNEL SSH users detected on this VPS:${C_RESET} ${removable_users[*]}"
        read -p "  Do you also want to permanently delete these SSH users before uninstalling? (y/n): " remove_users_confirm
        if [[ "$remove_users_confirm" == "y" || "$remove_users_confirm" == "Y" ]]; then
            remove_users_on_uninstall=true
        fi
    fi
    export UNINSTALL_MODE="silent"
    echo
    tdz_section "UNINSTALLATION PROGRESS"
    
    if [[ "$remove_users_on_uninstall" == "true" ]]; then
        echo -e "\n${C_BLUE}Removing TDZ SSH TUNNEL SSH users before uninstall...${C_RESET}"
        delete_tdztunnel_user_accounts "${removable_users[@]}"
    fi
    
    echo -e "\n${C_BLUE}Removing active limiter service...${C_RESET}"
    systemctl stop tdztunnel-limiter &>/dev/null
    systemctl disable tdztunnel-limiter &>/dev/null
    rm -f "$LIMITER_SERVICE"
    rm -f "$LIMITER_SCRIPT"
    
    echo -e "\n${C_BLUE}Removing bandwidth monitoring service...${C_RESET}"
    systemctl stop tdztunnel-bandwidth &>/dev/null
    systemctl disable tdztunnel-bandwidth &>/dev/null
    rm -f "$BANDWIDTH_SERVICE"
    rm -f "$BANDWIDTH_SCRIPT"
    rm -rf "$LEGACY_BANDWIDTH_DIR"
    rm -f "$TRIAL_CLEANUP_SCRIPT"
    
    echo -e "\n${C_BLUE}Removing SSH login banner...${C_RESET}"
    rm -f "$LOGIN_INFO_SCRIPT"
    rm -f "$SSHD_TDZ_CONFIG"
    systemctl reload sshd 2>/dev/null || systemctl reload ssh 2>/dev/null
    
    chattr -i /etc/resolv.conf &>/dev/null

    purge_nginx "silent"
    uninstall_dnstt
    uninstall_badvpn
    uninstall_udp_custom
    uninstall_ssl_tunnel
    uninstall_tdz_proxy
    uninstall_zivpn

    echo -e "\n${C_BLUE}Reloading systemd daemon...${C_RESET}"
    systemctl daemon-reload
    
    echo -e "\n${C_BLUE}Removing script and configuration files...${C_RESET}"
    rm -rf "$BADVPN_BUILD_DIR"
    rm -rf "$UDP_CUSTOM_DIR"
    rm -rf "$DB_DIR"
    rm -f "$(command -v menu)"
    
    tdz_message OK "TDZ SSH TUNNEL was removed successfully."
    echo -e "  ${C_DIM}All associated files and services were removed. The 'menu' command is no longer available.${C_RESET}"
    exit 0
}

# --- NEW FEATURES ---

create_trial_account() {
    clear; show_banner
    
    # Ensure 'at' daemon is available
    if ! command -v at &>/dev/null; then
        echo -e "${C_YELLOW}[WARNING] 'at' command not found. Installing...${C_RESET}"
        tdz_apt_install at >/dev/null 2>&1 || {
            echo -e "${C_RED}[ERROR] Failed to install 'at'. Cannot schedule auto-expiry.${C_RESET}"
            return
        }
        systemctl enable atd &>/dev/null
        systemctl start atd &>/dev/null
    fi
    
    # Ensure atd is running
    if ! systemctl is-active --quiet atd; then
        systemctl start atd &>/dev/null
    fi
    
    echo
    tdz_box_top
    tdz_box_header "CREATE TRIAL"
    tdz_box_divider
    tdz_menu1 "[ 1]" "1 Hour"
    tdz_menu1 "[ 2]" "2 Hours"
    tdz_menu1 "[ 3]" "3 Hours"
    tdz_menu1 "[ 4]" "6 Hours"
    tdz_menu1 "[ 5]" "12 Hours"
    tdz_menu1 "[ 6]" "1 Day"
    tdz_menu1 "[ 7]" "3 Days"
    tdz_menu1 "[ 8]" "Custom Duration (Hours)"
    tdz_box_divider
    tdz_menu1 "[ 0]" "Cancel"
    tdz_box_bot
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Select a duration: ${C_RESET}")" dur_choice
    
    local duration_hours=0
    local duration_label=""
    case $dur_choice in
        1) duration_hours=1;   duration_label="1 Hour" ;;
        2) duration_hours=2;   duration_label="2 Hours" ;;
        3) duration_hours=3;   duration_label="3 Hours" ;;
        4) duration_hours=6;   duration_label="6 Hours" ;;
        5) duration_hours=12;  duration_label="12 Hours" ;;
        6) duration_hours=24;  duration_label="1 Day" ;;
        7) duration_hours=72;  duration_label="3 Days" ;;
        8) read -r -p "$(echo -e "${C_PROMPT}  Custom duration in hours: ${C_RESET}")" custom_hours
           if ! [[ "$custom_hours" =~ ^[0-9]+$ ]] || [[ "$custom_hours" -lt 1 ]]; then
               echo -e "\n${C_RED}[ERROR] Invalid number of hours.${C_RESET}"; return
           fi
           duration_hours=$custom_hours
           duration_label="$custom_hours Hours"
           ;;
        0) tdz_message CANCELLED "Trial creation cancelled."; return ;;
        *) echo -e "\n${C_RED}[ERROR] Invalid option.${C_RESET}"; return ;;
    esac
    
    # Username
    local rand_suffix=$(head /dev/urandom | tr -dc 'a-z0-9' | head -c 5)
    local default_username="trial_${rand_suffix}"
    read -r -p "$(echo -e "${C_PROMPT}  Username [${default_username}]: ${C_RESET}")" username
    username=${username:-$default_username}
    
    if id "$username" &>/dev/null || grep -q "^$username:" "$DB_FILE"; then
        echo -e "\n${C_RED}[ERROR] User '$username' already exists.${C_RESET}"; return
    fi
    
    # Password
    local password=$(head /dev/urandom | tr -dc 'A-Za-z0-9' | head -c 8)
    read -r -p "$(echo -e "${C_PROMPT}  Password [${password}]: ${C_RESET}")" custom_pass
    password=${custom_pass:-$password}
    
    # Connection limit
    read -r -p "$(echo -e "${C_PROMPT}  Connection limit [1]: ${C_RESET}")" limit
    limit=${limit:-1}
    if ! [[ "$limit" =~ ^[0-9]+$ ]]; then echo -e "\n${C_RED}[ERROR] Invalid number.${C_RESET}"; return; fi
    
    # Bandwidth limit
    read -r -p "$(echo -e "${C_PROMPT}  Bandwidth in GB (0 = unlimited) [0]: ${C_RESET}")" bandwidth_gb
    bandwidth_gb=${bandwidth_gb:-0}
    if ! [[ "$bandwidth_gb" =~ ^[0-9]+\.?[0-9]*$ ]]; then echo -e "\n${C_RED}[ERROR] Invalid number.${C_RESET}"; return; fi
    
    # Calculate expiry
    local expire_date
    if [[ "$duration_hours" -ge 24 ]]; then
        local days=$((duration_hours / 24))
        expire_date=$(date -d "+$days days" +%Y-%m-%d)
    else
        # For sub-day durations, set expiry to tomorrow to be safe (at job does the real cleanup)
        expire_date=$(date -d "+1 day" +%Y-%m-%d)
    fi
    local expiry_epoch expiry_timestamp
    expiry_epoch=$(date -d "+${duration_hours} hours" +%s)
    expiry_timestamp=$(date -d "@${expiry_epoch}" '+%Y-%m-%d %H:%M:%S')
    
    # Create the system user
    ensure_tdztunnel_system_group
    useradd -m -s /usr/sbin/nologin "$username"
    usermod -aG "$TDZ_USERS_GROUP" "$username" 2>/dev/null
    echo "$username:$password" | chpasswd
    chage -E "$expire_date" "$username"
    echo "$username:$password:$expire_date:$limit:$bandwidth_gb:trial:$expiry_epoch" >> "$DB_FILE"
    
    # Schedule by UID + immutable expiry token so changing the username later
    # does not detach the automatic cleanup job. The token prevents UID-reuse
    # from ever deleting a different account.
    local trial_uid
    trial_uid=$(id -u "$username")
    echo "$TRIAL_CLEANUP_SCRIPT --uid $trial_uid $expiry_epoch" | at now + ${duration_hours} hours 2>/dev/null
    
    local bw_display
    bw_display=$(tdz_format_quota_gb "$bandwidth_gb")
    
    clear; show_banner
    tdz_message OK "Trial account created successfully."
    echo
    tdz_section "TRIAL ACCOUNT DETAILS"
    tdz_detail "Username" "$username" "$C_YELLOW"
    tdz_detail "Password" "$password" "$C_YELLOW"
    tdz_detail "Duration" "$duration_label"
    tdz_detail "Auto Expires" "$expiry_timestamp" "$C_RED"
    tdz_detail "Connections" "$limit"
    tdz_detail "Bandwidth" "$bw_display"
    echo -e "  ${C_DIM}This account is removed automatically when its trial expires.${C_RESET}"
    
    # Auto-ask for config generation
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Generate client configuration now? [y/N]: ${C_RESET}")" gen_conf
    if [[ "$gen_conf" == "y" || "$gen_conf" == "Y" ]]; then
        generate_client_config "$username" "$password"
    fi
    
    invalidate_banner_cache
    refresh_dynamic_banner_routing_if_enabled
}

format_trial_time_left() {
    local expiry_epoch="$1" now remaining days hours minutes
    if ! [[ "$expiry_epoch" =~ ^[0-9]+$ ]] || (( expiry_epoch <= 0 )); then
        printf "Unknown"
        return
    fi

    now=$(date +%s)
    remaining=$((expiry_epoch - now))
    if (( remaining <= 0 )); then
        printf "Expired"
    elif (( remaining >= 86400 )); then
        days=$((remaining / 86400))
        hours=$(((remaining % 86400) / 3600))
        printf "%dd %dh" "$days" "$hours"
    elif (( remaining >= 3600 )); then
        hours=$((remaining / 3600))
        minutes=$(((remaining % 3600) / 60))
        printf "%dh %dm" "$hours" "$minutes"
    else
        minutes=$((remaining / 60))
        (( minutes < 1 )) && minutes=1
        printf "%dm" "$minutes"
    fi
}

list_trial_accounts() {
    clear; show_banner
    local trial_total=0
    if [[ -s "$DB_FILE" ]]; then
        trial_total=$(awk -F: '$6 == "trial" { count++ } END { print count + 0 }' "$DB_FILE")
    fi

    echo
    tdz_box_top
    tdz_box_header "TRIAL ACCOUNTS"
    tdz_box_divider

    if (( trial_total == 0 )); then
        tdz_row "${C_YELLOW}[INFO] No trial accounts found.${C_RESET}"
        tdz_box_bot
        return
    fi

    refresh_ssh_session_cache
    local now trial_count=0 first_account=true
    now=$(date +%s)

    while IFS=: read -r user _password expiry limit bandwidth_gb account_type trial_expiry_epoch _rest; do
        [[ "$account_type" == "trial" ]] || continue
        trial_count=$((trial_count + 1))

        local expiry_display time_left online_count connection_string
        local used_bytes=0 bandwidth_display status status_color
        local expiry_check=0 passwd_state account_number display_user

        online_count="${SSH_SESSION_COUNTS[$user]:-0}"
        connection_string="${online_count}/${limit:-1}"

        if [[ "$trial_expiry_epoch" =~ ^[0-9]+$ ]] && (( trial_expiry_epoch > 0 )); then
            expiry_display=$(LC_TIME=C date -d "@${trial_expiry_epoch}" '+%d %b %Y • %H:%M' 2>/dev/null || echo "$expiry")
            time_left=$(format_trial_time_left "$trial_expiry_epoch")
            expiry_check=$trial_expiry_epoch
        else
            expiry_display=$(LC_TIME=C date -d "$expiry" '+%d %b %Y' 2>/dev/null || echo "$expiry")
            time_left="Unknown"
            expiry_check=$(date -d "$expiry" +%s 2>/dev/null || echo 0)
        fi

        if [[ -f "$BANDWIDTH_DIR/${user}.usage" ]]; then
            read -r used_bytes < "$BANDWIDTH_DIR/${user}.usage" || used_bytes=0
            [[ "$used_bytes" =~ ^[0-9]+$ ]] || used_bytes=0
        fi
        bandwidth_display=$(tdz_format_bandwidth_usage "$used_bytes" "$bandwidth_gb")

        passwd_state=$(passwd -S "$user" 2>/dev/null | awk '{print $2}')
        if ! id "$user" >/dev/null 2>&1; then
            status="MISSING"
            status_color="$C_RED"
        elif (( expiry_check > 0 && expiry_check <= now )); then
            status="EXPIRED"
            status_color="$C_RED"
        elif [[ "$passwd_state" == "L" ]]; then
            status="LOCKED"
            status_color="$C_YELLOW"
        else
            status="ACTIVE"
            status_color="$C_GREEN"
        fi

        if [[ "$first_account" != true ]]; then
            tdz_box_divider
        fi
        first_account=false

        printf -v account_number "%02d" "$trial_count"
        display_user="$user"
        if (( ${#display_user} > 22 )); then
            display_user="${display_user:0:19}..."
        fi
        tdz_row2 "${C_CHOICE}[${account_number}]${C_RESET} ${C_BOLD}${C_WHITE}${display_user}${C_RESET}" \
            "${status_color}● ${C_BOLD}${status}${C_RESET}"
        tdz_kv2 "EXPIRES" "$expiry_display" "LEFT" "$time_left"
        tdz_kv2 "CONNS" "$connection_string" "DATA" "$bandwidth_display"
    done < <(sort "$DB_FILE")

    tdz_box_divider
    tdz_row2 "${C_GRAY}TOTAL${C_RESET} ${C_BOLD}${C_WHITE}${trial_count}${C_RESET}" \
        "${C_GREEN}● ${C_BOLD}AUTO-CLEANUP${C_RESET}"
    tdz_box_bot
}

view_user_bandwidth() {
    _select_user_interface "VIEW USER BANDWIDTH"
    local u=$SELECTED_USER
    if [[ "$u" == "NO_USERS" || -z "$u" ]]; then return; fi
    
    clear; show_banner
    tdz_screen_title "BANDWIDTH USAGE" "Account: $u"
    
    local line; line=$(grep "^$u:" "$DB_FILE")
    local bandwidth_gb; bandwidth_gb=$(echo "$line" | cut -d: -f5)
    [[ -z "$bandwidth_gb" ]] && bandwidth_gb="0"
    
    local used_bytes=0
    if [[ -f "$BANDWIDTH_DIR/${u}.usage" ]]; then
        used_bytes=$(cat "$BANDWIDTH_DIR/${u}.usage" 2>/dev/null)
        [[ -z "$used_bytes" ]] && used_bytes=0
    fi
    
    [[ "$used_bytes" =~ ^[0-9]+$ ]] || used_bytes=0
    local used_display
    used_display=$(tdz_format_used_bytes "$used_bytes")
    
    tdz_section "USAGE SUMMARY"
    tdz_detail "Data Used" "$used_display"
    
    if tdz_quota_is_unlimited "$bandwidth_gb"; then
        tdz_detail "Bandwidth Limit" "Unlimited" "$C_GREEN"
        tdz_detail "Status" "No quota restriction" "$C_GREEN"
    else
        local quota_bytes; quota_bytes=$(awk "BEGIN {printf \"%.0f\", $bandwidth_gb * 1073741824}")
        local percentage; percentage=$(awk "BEGIN {printf \"%.1f\", ($used_bytes / $quota_bytes) * 100}")
        local remaining_bytes; remaining_bytes=$((quota_bytes - used_bytes))
        if [[ "$remaining_bytes" -lt 0 ]]; then remaining_bytes=0; fi
        local remaining_display quota_display
        remaining_display=$(tdz_format_used_bytes "$remaining_bytes")
        quota_display=$(tdz_format_quota_gb "$bandwidth_gb")
        
        tdz_detail "Bandwidth Limit" "$quota_display" "$C_YELLOW"
        tdz_detail "Remaining" "$remaining_display"
        tdz_detail "Usage" "${percentage}%"
        
        # Progress bar
        local bar_width=30
        local filled; filled=$(awk "BEGIN {printf \"%.0f\", ($percentage / 100) * $bar_width}")
        if [[ "$filled" -gt "$bar_width" ]]; then filled=$bar_width; fi
        local empty=$((bar_width - filled))
        local bar_color="$C_GREEN"
        if (( $(awk "BEGIN {print ($percentage > 80)}" ) )); then bar_color="$C_RED"
        elif (( $(awk "BEGIN {print ($percentage > 50)}" ) )); then bar_color="$C_YELLOW"
        fi
        printf "  ${C_GRAY}• %-19s${C_RESET} ${bar_color}[" "Progress:"
        for ((i=0; i<filled; i++)); do printf "█"; done
        for ((i=0; i<empty; i++)); do printf "░"; done
        printf "]${C_RESET} ${percentage}%%\n"
        
        if [[ "$used_bytes" -ge "$quota_bytes" ]]; then
            tdz_message WARNING "Bandwidth quota exceeded; the account is locked."
        fi
    fi
}

bulk_create_users() {
    clear; show_banner
    tdz_screen_title "BULK CREATE USERS" "Create up to 100 managed accounts with shared limits."
    
    read -p "  Enter username prefix (e.g., 'user'): " prefix
    if [[ -z "$prefix" ]]; then echo -e "\n${C_RED}[ERROR] Prefix cannot be empty.${C_RESET}"; return; fi
    
    read -p "  How many users to create? " count
    if ! [[ "$count" =~ ^[0-9]+$ ]] || [[ "$count" -lt 1 ]] || [[ "$count" -gt 100 ]]; then
        echo -e "\n${C_RED}[ERROR] Invalid count (1-100).${C_RESET}"; return
    fi
    
    local first_use_activation=false first_use_choice validity_prompt
    read -r -p "  Start After First Use? [y/N]: " first_use_choice
    [[ "$first_use_choice" == "y" || "$first_use_choice" == "Y" ]] && first_use_activation=true
    if $first_use_activation; then
        validity_prompt="Validity after first use (days) [30]"
    else
        validity_prompt="Validity from today (days) [30]"
    fi
    read -r -p "  ${validity_prompt}: " days
    days=${days:-30}
    if ! [[ "$days" =~ ^[1-9][0-9]*$ ]]; then echo -e "\n${C_RED}[ERROR] Validity must be at least 1 day.${C_RESET}"; return; fi
    
    read -p "  Connection limit per user [1]: " limit
    limit=${limit:-1}
    if ! [[ "$limit" =~ ^[0-9]+$ ]]; then echo -e "\n${C_RED}[ERROR] Invalid number.${C_RESET}"; return; fi
    
    read -p "  Bandwidth limit in GB per user (0 = unlimited) [0]: " bandwidth_gb
    bandwidth_gb=${bandwidth_gb:-0}
    if ! [[ "$bandwidth_gb" =~ ^[0-9]+\.?[0-9]*$ ]]; then echo -e "\n${C_RED}[ERROR] Invalid number.${C_RESET}"; return; fi

    local expire_date stored_expiry metadata_suffix="" table_expiry activation_display="Immediately"
    expire_date=$(date -d "+$days days" +%Y-%m-%d)
    stored_expiry="$expire_date"
    table_expiry="$expire_date"
    if $first_use_activation; then
        stored_expiry="Never"
        metadata_suffix=":pending:${days}"
        table_expiry="FIRST USE"
        activation_display="After First Use"
    fi
    local bw_display
    bw_display=$(tdz_format_quota_gb "$bandwidth_gb")
    ensure_tdztunnel_system_group
    
    echo
    tdz_section "CREATED ACCOUNTS"
    printf "${C_BOLD}${C_WHITE}%-20s | %-15s | %-12s${C_RESET}\n" "USERNAME" "PASSWORD" "EXPIRES"
    echo -e "${C_GRAY}─────────────────────┼─────────────────┼─────────────${C_RESET}"
    
    local created=0
    for ((i=1; i<=count; i++)); do
        local username="${prefix}${i}"
        if id "$username" &>/dev/null || grep -q "^$username:" "$DB_FILE"; then
            echo -e "${C_RED}  [WARNING] Skipping '$username' — already exists${C_RESET}"
            continue
        fi
        local password=$(head /dev/urandom | tr -dc 'A-Za-z0-9' | head -c 8)
        useradd -m -s /usr/sbin/nologin "$username"
        usermod -aG "$TDZ_USERS_GROUP" "$username" 2>/dev/null
        echo "$username:$password" | chpasswd
        if $first_use_activation; then
            chage -E -1 "$username"
        else
            chage -E "$expire_date" "$username"
        fi
        echo "$username:$password:$stored_expiry:$limit:$bandwidth_gb$metadata_suffix" >> "$DB_FILE"
        printf "  ${C_GREEN}%-20s${C_RESET} | ${C_YELLOW}%-15s${C_RESET} | ${C_CYAN}%-12s${C_RESET}\n" "$username" "$password" "$table_expiry"
        created=$((created + 1))
    done
    
    tdz_message OK "Created $created account(s). Connections: ${limit}; bandwidth: ${bw_display}; expiry starts: ${activation_display}."
    
    invalidate_banner_cache
    refresh_dynamic_banner_routing_if_enabled
}

generate_client_config() {
    local user=$1
    local pass=$2

    local host_ip
    host_ip=$(curl -fsS -4 --max-time 5 icanhazip.com 2>/dev/null | tr -d '[:space:]')
    if [[ -z "$host_ip" ]]; then
        host_ip=$(hostname -I 2>/dev/null | awk '{print $1}')
    fi
    [[ -z "$host_ip" ]] && host_ip="Not detected"
    local host_domain
    host_domain=$(detect_preferred_host)
    [[ -z "$host_domain" ]] && host_domain="$host_ip"

    clear; show_banner
    echo
    tdz_section "CLIENT CONNECTION CONFIGURATION"
    echo -e "  ${C_DIM}Copy the required values for your client application.${C_RESET}"

    echo
    tdz_section "ACCOUNT"
    tdz_detail "Username" "$user" "$C_YELLOW"
    tdz_detail "Password" "$pass" "$C_YELLOW"
    tdz_detail "Host / IP" "$host_domain"

    # 1. SSH Direct
    echo
    tdz_section "SSH DIRECT"
    tdz_detail "Host" "$host_domain"
    tdz_detail "Port" "22"
    tdz_detail "Payload" "Standard SSH"

    # 2. HAProxy edge stack
    if systemctl is-active --quiet haproxy; then
        echo
        tdz_section "HAPROXY EDGE STACK"
        tdz_detail "Host" "$host_domain"
        tdz_detail "HTTP / Raw SSH" "$EDGE_PUBLIC_HTTP_PORT"
        tdz_detail "TLS / SNI / SSL" "$EDGE_PUBLIC_TLS_PORT"
        tdz_detail "Internal Backend" "Nginx ${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}"
        tdz_detail "SNI / Bug Host" "$host_domain"
    elif systemctl is-active --quiet nginx; then
        echo
        tdz_section "INTERNAL NGINX PROXY"
        tdz_detail "Internal Ports" "${NGINX_INTERNAL_HTTP_PORT}/${NGINX_INTERNAL_TLS_PORT}"
        tdz_detail "Public Edge" "HAProxy ${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT}"
    fi

    # 3. UDP Custom
    if systemctl is-active --quiet udp-custom; then
        echo
        tdz_section "UDP CUSTOM"
        tdz_detail "Numeric IP" "$host_ip"
        tdz_detail "Port Range" "1-65535 (except 53 and 5300)"
        tdz_detail "Obfuscation" "None / Plain"
    fi

    # 4. DNSTT
    if systemctl is-active --quiet dnstt; then
        if [ -f "$DNSTT_CONFIG_FILE" ]; then
            source "$DNSTT_CONFIG_FILE"
            echo
            tdz_section "DNSTT / SLOWDNS"
            tdz_detail "Nameserver" "$TUNNEL_DOMAIN"
            tdz_detail "Public Key" "$PUBLIC_KEY"
            tdz_detail "DNS Resolver" "1.1.1.1 / 8.8.8.8"
        fi
    fi

    # 5. ZiVPN
    if systemctl is-active --quiet zivpn; then
        echo
        tdz_section "ZIVPN"
        tdz_detail "UDP Port" "5667"
        tdz_detail "Forwarded Ports" "6000-19999"
    fi

    press_enter
}

client_config_menu() {
    _select_user_interface "CLIENT CONFIG"
    local u=$SELECTED_USER
    if [[ "$u" == "NO_USERS" || -z "$u" ]]; then return; fi
    
    # We need to find the password. It's in the DB.
    local pass=$(grep "^$u:" "$DB_FILE" | cut -d: -f2)
    generate_client_config "$u" "$pass"
}

format_rate_from_kbps() {
    local kbps=${1:-0}
    if (( kbps >= 1024 )); then
        printf "%d.%02d MB/s" $((kbps / 1024)) $((((kbps % 1024) * 100) / 1024))
    else
        printf "%d KB/s" "$kbps"
    fi
}

# Lightweight Bash Monitor (No vnStat required)
simple_live_monitor() {
    local iface=$1
    local rx_file="/sys/class/net/$iface/statistics/rx_bytes"
    local tx_file="/sys/class/net/$iface/statistics/tx_bytes"
    local interval=2
    local stop_monitor=0
    local rx1 tx1 rx2 tx2 rx_diff tx_diff rx_kbs tx_kbs rx_fmt tx_fmt

    if [[ -z "$iface" || ! -r "$rx_file" || ! -r "$tx_file" ]]; then
        echo -e "\n${C_RED}[ERROR] Could not read interface statistics for '${iface:-unknown}'.${C_RESET}"
        return
    fi

    echo -e "\n${C_BLUE}Starting Lightweight Traffic Monitor for $iface...${C_RESET}"
    echo -e "${C_DIM}Press [Ctrl+C] to stop.${C_RESET}\n"

    read -r rx1 < "$rx_file"
    read -r tx1 < "$tx_file"

    tdz_section "LIVE TRANSFER RATE"
    printf "  %-15s | %-15s\n" "DOWNLOAD" "UPLOAD"

    trap 'stop_monitor=1' INT TERM
    while (( ! stop_monitor )); do
        sleep "$interval"
        read -r rx2 < "$rx_file" || break
        read -r tx2 < "$tx_file" || break

        rx_diff=$((rx2 - rx1))
        tx_diff=$((tx2 - tx1))
        (( rx_diff < 0 )) && rx_diff=0
        (( tx_diff < 0 )) && tx_diff=0

        rx_kbs=$((rx_diff / 1024 / interval))
        tx_kbs=$((tx_diff / 1024 / interval))
        rx_fmt=$(format_rate_from_kbps "$rx_kbs")
        tx_fmt=$(format_rate_from_kbps "$tx_kbs")

        printf "\r%-15s | %-15s" "$rx_fmt" "$tx_fmt"

        rx1=$rx2
        tx1=$tx2
    done
    trap - INT TERM
    echo
}

traffic_monitor_menu() {
    clear; show_banner
    # Find active interface
    local iface
    iface=$(ip -4 route ls | grep default | grep -Po '(?<=dev )(\S+)' | head -1)

    echo
    tdz_box_top
    tdz_box_header "NETWORK TRAFFIC MONITOR"
    tdz_box_divider
    tdz_row "${C_GRAY}INTERFACE${C_RESET} ${C_WHITE}${iface:-Not detected}${C_RESET}"
    tdz_box_divider
    tdz_menu1 "[ 1]" "Live Monitor (No Installation)"
    tdz_menu1 "[ 2]" "Total Traffic Since Boot"
    tdz_menu1 "[ 3]" "Daily and Monthly Logs (vnStat)"
    tdz_box_divider
    tdz_menu1 "[ 0]" "Return"
    tdz_box_bot
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" t_choice

    if [[ "$t_choice" != "0" && -z "$iface" ]]; then
        echo -e "\n${C_RED}No active default network interface was detected.${C_RESET}"
        press_enter
        return
    fi
    case $t_choice in
        1) 
           simple_live_monitor "$iface"
           ;;
        2)
            local rx_total=$(cat /sys/class/net/$iface/statistics/rx_bytes)
            local tx_total=$(cat /sys/class/net/$iface/statistics/tx_bytes)
            local rx_mb=$((rx_total / 1024 / 1024))
            local tx_mb=$((tx_total / 1024 / 1024))
            echo -e "\n${C_BLUE}Total Traffic (Since Boot):${C_RESET}"
            echo -e "   Download: ${C_WHITE}${rx_mb} MB${C_RESET}"
            echo -e "   Upload:   ${C_WHITE}${tx_mb} MB${C_RESET}"
            press_enter
            ;;
        3) 
           # vnStat Logic
           if ! command -v vnstat &> /dev/null; then
               echo -e "\n${C_YELLOW}[WARNING] vnStat is not installed.${C_RESET}"
               echo -e "   This tool provides persistent history (Daily/Monthly reports)."
               echo -e "   It is lightweight but requires installation."
               read -p "  Install vnStat now? (y/n): " confirm
                if [[ "$confirm" == "y" || "$confirm" == "Y" ]]; then
                     echo -e "\n${C_BLUE}Installing vnStat...${C_RESET}"
                     tdz_apt_install vnstat >/dev/null 2>&1 || {
                         echo -e "${C_RED}[ERROR] Failed to install vnStat.${C_RESET}"
                         sleep 1
                         return
                     }
                     systemctl enable vnstat >/dev/null 2>&1
                     systemctl restart vnstat >/dev/null 2>&1
                    local default_iface=$(ip -4 route ls | grep default | grep -Po '(?<=dev )(\S+)' | head -1)
                    vnstat --add -i "$default_iface" >/dev/null 2>&1
                    echo -e "${C_GREEN}[OK] Installed.${C_RESET}"
                    sleep 1
               else
                    return
               fi
           fi
           echo
           vnstat -i "$iface"
           echo -e "\n${C_DIM}Run 'vnstat -d' or 'vnstat -m' manually for specific views.${C_RESET}"
           press_enter
           ;;
        *) return ;;
    esac
}

torrent_block_menu() {
    clear; show_banner
    # Check status
    local torrent_status="Disabled" torrent_color="$C_RED"
    if iptables -L FORWARD | grep -q "ipp2p"; then
         torrent_status="Enabled"; torrent_color="$C_GREEN"
    elif iptables -L OUTPUT | grep -q "BitTorrent"; then
         # Fallback check for string matching
         torrent_status="Enabled"; torrent_color="$C_GREEN"
    fi

    echo
    tdz_box_top
    tdz_box_header "TORRENT BLOCKING"
    tdz_box_divider
    tdz_row2 "${C_GRAY}STATUS${C_RESET}" "${torrent_color}${C_BOLD}${torrent_status}${C_RESET}"
    tdz_box_divider
    tdz_menu1 "[ 1]" "Enable Torrent Blocking"
    tdz_menu1 "[ 2]" "Disable Torrent Blocking"
    tdz_box_divider
    tdz_menu1 "[ 0]" "Return"
    tdz_box_bot
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" b_choice
    
    case $b_choice in
        1)
            echo -e "\n${C_BLUE}Applying Anti-Torrent rules...${C_RESET}"
            # Clean old rules first to avoid duplicates
            _flush_torrent_rules
            
            # Block Common Torrent Ports/Keywords
            # String matching using iptables extension
            iptables -A FORWARD -m string --string "BitTorrent" --algo bm -j DROP
            iptables -A FORWARD -m string --string "BitTorrent protocol" --algo bm -j DROP
            iptables -A FORWARD -m string --string "peer_id=" --algo bm -j DROP
            iptables -A FORWARD -m string --string ".torrent" --algo bm -j DROP
            iptables -A FORWARD -m string --string "announce.php?passkey=" --algo bm -j DROP
            iptables -A FORWARD -m string --string "torrent" --algo bm -j DROP
            iptables -A FORWARD -m string --string "info_hash" --algo bm -j DROP
            iptables -A FORWARD -m string --string "get_peers" --algo bm -j DROP
            iptables -A FORWARD -m string --string "find_node" --algo bm -j DROP
            
            # Same for OUTPUT to be safe
            iptables -A OUTPUT -m string --string "BitTorrent" --algo bm -j DROP
            iptables -A OUTPUT -m string --string "BitTorrent protocol" --algo bm -j DROP
            iptables -A OUTPUT -m string --string "peer_id=" --algo bm -j DROP
            iptables -A OUTPUT -m string --string ".torrent" --algo bm -j DROP
            iptables -A OUTPUT -m string --string "announce.php?passkey=" --algo bm -j DROP
            iptables -A OUTPUT -m string --string "torrent" --algo bm -j DROP
            iptables -A OUTPUT -m string --string "info_hash" --algo bm -j DROP
            iptables -A OUTPUT -m string --string "get_peers" --algo bm -j DROP
            iptables -A OUTPUT -m string --string "find_node" --algo bm -j DROP
            
            # Attempt to save if iptables-persistent exists
            if dpkg -s iptables-persistent &>/dev/null; then
                netfilter-persistent save &>/dev/null
            fi
            
            echo -e "${C_GREEN}[OK] Torrent Blocking Enabled.${C_RESET}"
            press_enter
            ;;
        2)
            echo -e "\n${C_BLUE}Removing Anti-Torrent rules...${C_RESET}"
            _flush_torrent_rules
            if dpkg -s iptables-persistent &>/dev/null; then
                netfilter-persistent save &>/dev/null
            fi
            echo -e "${C_GREEN}[OK] Torrent Blocking Disabled.${C_RESET}"
            press_enter
            ;;
        *) return ;;
    esac
}

_flush_torrent_rules() {
    # Helper to remove rules containing specific strings
    # This is a bit brute-force but effective for this script's scope
    iptables -D FORWARD -m string --string "BitTorrent" --algo bm -j DROP 2>/dev/null
    iptables -D FORWARD -m string --string "BitTorrent protocol" --algo bm -j DROP 2>/dev/null
    iptables -D FORWARD -m string --string "peer_id=" --algo bm -j DROP 2>/dev/null
    iptables -D FORWARD -m string --string ".torrent" --algo bm -j DROP 2>/dev/null
    iptables -D FORWARD -m string --string "announce.php?passkey=" --algo bm -j DROP 2>/dev/null
    iptables -D FORWARD -m string --string "torrent" --algo bm -j DROP 2>/dev/null
    iptables -D FORWARD -m string --string "info_hash" --algo bm -j DROP 2>/dev/null
    iptables -D FORWARD -m string --string "get_peers" --algo bm -j DROP 2>/dev/null
    iptables -D FORWARD -m string --string "find_node" --algo bm -j DROP 2>/dev/null

    iptables -D OUTPUT -m string --string "BitTorrent" --algo bm -j DROP 2>/dev/null
    iptables -D OUTPUT -m string --string "BitTorrent protocol" --algo bm -j DROP 2>/dev/null
    iptables -D OUTPUT -m string --string "peer_id=" --algo bm -j DROP 2>/dev/null
    iptables -D OUTPUT -m string --string ".torrent" --algo bm -j DROP 2>/dev/null
    iptables -D OUTPUT -m string --string "announce.php?passkey=" --algo bm -j DROP 2>/dev/null
    iptables -D OUTPUT -m string --string "torrent" --algo bm -j DROP 2>/dev/null
    iptables -D OUTPUT -m string --string "info_hash" --algo bm -j DROP 2>/dev/null
    iptables -D OUTPUT -m string --string "get_peers" --algo bm -j DROP 2>/dev/null
    iptables -D OUTPUT -m string --string "find_node" --algo bm -j DROP 2>/dev/null
}

ssh_banner_menu() {
    while true; do
        show_banner
        local banner_mode
        local banner_status banner_color
        banner_mode=$(get_ssh_banner_mode)
        case "$banner_mode" in
            dynamic) banner_status="Dynamic"; banner_color="$C_GREEN" ;;
            static) banner_status="Static"; banner_color="$C_GREEN" ;;
            *) banner_status="Disabled"; banner_color="$C_RED" ;;
        esac

        echo
        tdz_box_top
        tdz_box_header "SSH BANNER MANAGEMENT"
        tdz_box_divider
        tdz_row2 "${C_GRAY}CURRENT MODE${C_RESET}" "${banner_color}${C_BOLD}${banner_status}${C_RESET}"
        tdz_box_divider
        tdz_menu1 "[ 1]" "Enable Dynamic Account Banner"
        tdz_menu1 "[ 2]" "Paste or Replace Static Banner"
        tdz_menu1 "[ 3]" "View Current Static Banner"
        tdz_menu1 "[ 4]" "Preview Dynamic Banner"
        tdz_menu1 "[ 5]" "Edit Dynamic Banner Contacts"
        tdz_menu1 "[ 6]" "Disable All SSH Banners"
        tdz_box_divider
        tdz_menu1 "[ 0]" "Return to Main Menu"
        tdz_box_bot
        echo
        if ! read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" choice; then
            echo
            return
        fi
        case $choice in
            1)
                if setup_ssh_login_info; then
                    echo -e "\n${C_GREEN}[OK] Dynamic account banner enabled.${C_RESET}"
                    echo -e "${C_DIM}Users will now see their account info banner instead of the static banner.${C_RESET}"
                fi
                press_enter
                ;;
            2) set_ssh_banner_paste ;;
            3) view_ssh_banner ;;
            4) preview_dynamic_ssh_banner ;;
            5) edit_dynamic_banner_contacts ;;
            6) remove_ssh_banner ;;
            0) return ;;
            *) echo -e "\n${C_RED}[ERROR] Invalid option.${C_RESET}" && sleep 1 ;;
        esac
    done
}

auto_reboot_menu() {
    clear; show_banner
    # Check status
    local cron_check
    cron_check=$(crontab -l 2>/dev/null | grep "systemctl reboot")
    local status="Disabled" status_color="$C_RED"
    if [[ -n "$cron_check" ]]; then
        status="Active (Midnight)"
        status_color="$C_GREEN"
    fi

    echo
    tdz_box_top
    tdz_box_header "AUTO-REBOOT MANAGEMENT"
    tdz_box_divider
    tdz_row2 "${C_GRAY}STATUS${C_RESET}" "${status_color}${C_BOLD}${status}${C_RESET}"
    tdz_box_divider
    tdz_menu1 "[ 1]" "Enable Daily Reboot (00:00)"
    tdz_menu1 "[ 2]" "Disable Auto-Reboot"
    tdz_box_divider
    tdz_menu1 "[ 0]" "Return"
    tdz_box_bot
    echo
    read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" r_choice
    
    case $r_choice in
        1)
            # Remove existing to prevent duplicates
            (crontab -l 2>/dev/null | grep -v "systemctl reboot") | crontab -
            # Add new job
            (crontab -l 2>/dev/null; echo "0 0 * * * systemctl reboot") | crontab -
            echo -e "\n${C_GREEN}[OK] Auto-reboot scheduled for every day at 00:00.${C_RESET}"
            press_enter
            ;;
        2)
            (crontab -l 2>/dev/null | grep -v "systemctl reboot") | crontab -
            echo -e "\n${C_GREEN}[OK] Auto-reboot disabled.${C_RESET}"
            press_enter
            ;;
        *) return ;;
    esac
}


press_enter() {
    echo -e "\nPress ${C_YELLOW}[Enter]${C_RESET} to return to the menu..." && read -r || true
}
invalid_option() {
    echo -e "\n${C_RED}[ERROR] Invalid option.${C_RESET}" && sleep 1
}

main_menu() {
    while true; do
        export UNINSTALL_MODE="interactive"
        show_banner

        # ── Refresh caches ─────────────────────────────────────────────
        refresh_dashboard_cache

        # ── Service status pills (● = running, ○ = stopped) ───────────
        local pill_haprx="${C_STATUS_I}○${C_RESET}"  pill_nginx="${C_STATUS_I}○${C_RESET}"
        local pill_ws="${C_STATUS_I}○${C_RESET}"     pill_badvpn="${C_STATUS_I}○${C_RESET}"
        local pill_udpgw="${C_STATUS_I}○${C_RESET}"  pill_dnstt="${C_STATUS_I}○${C_RESET}"
        systemctl is-active --quiet haproxy            && pill_haprx="${C_STATUS_A}●${C_RESET}"
        systemctl is-active --quiet nginx              && pill_nginx="${C_STATUS_A}●${C_RESET}"
        systemctl is-active --quiet tdz-ws-ssh-bridge  && pill_ws="${C_STATUS_A}●${C_RESET}"
        systemctl is-active --quiet badvpn              && pill_badvpn="${C_STATUS_A}●${C_RESET}"
        systemctl is-active --quiet udpgw               && pill_udpgw="${C_STATUS_A}●${C_RESET}"
        systemctl is-active --quiet dnstt               && pill_dnstt="${C_STATUS_A}●${C_RESET}"

        # ── SECTION 1: SERVER PROFILE ──
        # Layout (per user request, 2026-06-25):
        #   LOC | IP        (left = identity / right = address)
        #   ISP | DOMAIN    (left = identity / right = address)
        #   OS  | UPTIME
        #   CPU | RAM       (both shown as % like RAM)
        #   ACCT | ONLINE
        # CPU usage shown as percentage + core count (e.g. "53% (2 CORES)").
        # Percentage is real-time (vmstat with /proc/stat fallback), capped 0..100.
        local _cpu_core_word="CORE"
        (( DASH_CACHE_CPU_CORES > 1 )) && _cpu_core_word="CORES"
        local _cpu_pct
        _cpu_pct=$(compute_cpu_pct)
        local _cpu_val="${_cpu_pct}% (${DASH_CACHE_CPU_CORES} ${_cpu_core_word})"
        local _ram_val="${DASH_CACHE_RAM_PCT}% (${DASH_CACHE_RAM_USED})"
        echo
        tdz_box_top
        tdz_box_header "SERVER PROFILE"
        tdz_box_divider
        tdz_kv2 "LOC"    "${DASH_CACHE_LOCATION:0:22}"  "IP"     "${DASH_CACHE_PUBLIC_IP:0:24}"
        tdz_kv2 "ISP"    "${DASH_CACHE_ISP:0:22}"       "DOMAIN" "${DASH_CACHE_DOMAIN:0:24}"
        tdz_box_divider
        tdz_kv2 "OS"     "${DASH_CACHE_OS_NAME:0:22}"   "UPTIME" "${DASH_CACHE_UPTIME:0:24}"
        tdz_kv2 "CPU"    "${_cpu_val:0:22}"             "RAM"    "${_ram_val:0:24}"
        tdz_box_divider
        tdz_kv2 "ACCT"   "${DASH_CACHE_TOTAL_USERS} total" "ONLINE" "${DASH_CACHE_ONLINE_USERS} now"
        tdz_box_bot

        # ── SECTION 2: SERVICE STATUS (live pills) ────────────────────
        echo
        tdz_box_top
        tdz_box_header "SERVICE STATUS"
        tdz_box_divider
        tdz_row "${pill_haprx} HAProxy ${EDGE_PUBLIC_HTTP_PORT}/${EDGE_PUBLIC_TLS_PORT}   ${pill_nginx} Nginx ${NGINX_INTERNAL_TLS_PORT}   ${pill_ws} WS-Bridge ${WS_SSH_BRIDGE_PORT}"
        tdz_box_bot

        # ── SECTION 3: USER MANAGEMENT ────────────────────────────────
        echo
        tdz_box_top
        tdz_box_header "USER MANAGEMENT"
        tdz_box_divider
        tdz_menu2 "[ 1]" "Create User"      "[ 7]" "List Users"
        tdz_menu2 "[ 2]" "Delete User"      "[ 8]" "Client Config"
        tdz_menu2 "[ 3]" "Renew Account"    "[ 9]" "Create Trial"
        tdz_menu2 "[ 4]" "Lock User"        "[10]" "Trial Accounts"
        tdz_menu2 "[ 5]" "Unlock Account"   "[11]" "Bandwidth Usage"
        tdz_menu2 "[ 6]" "Edit Details"     "[12]" "Bulk Create"
        tdz_box_bot

        # ── SECTION 4: VPN & PROTOCOLS ────────────────────────────────
        echo
        tdz_box_top
        tdz_box_header "VPN & PROTOCOLS"
        tdz_box_divider
        tdz_menu2 "[13]" "Protocol Manager" "[15]" "Block Torrent"
        tdz_menu2 "[14]" "Port Management"  "[16]" "Traffic Monitor"
        tdz_box_bot

        # ── SECTION 5: SYSTEM & MAINTENANCE ───────────────────────────
        echo
        tdz_box_top
        tdz_box_header "SYSTEM & MAINTENANCE"
        tdz_box_divider
        tdz_menu2 "[17]" "Domain & SSL Cert" "[20]" "Backup Data"
        tdz_menu2 "[18]" "SSH Banner"        "[21]" "Restore Data"
        tdz_menu2 "[19]" "Auto-Reboot Task"  "[22]" "Cleanup Expired"
        tdz_box_bot

        # ── SECTION 6: DANGER ZONE (red) ──────────────────────────────
        echo
        tdz_box_top "$C_DANGER"
        tdz_box_header "DANGER ZONE" "$C_DANGER"
        tdz_box_divider "$C_DANGER"
        tdz_menu2 "[99]" "Uninstall Script" "[ 0]" "Exit" "$C_DANGER"
        tdz_box_bot "$C_DANGER"

        echo
        if ! read -r -p "$(echo -e ${C_PROMPT}"  Select an option: "${C_RESET})" choice; then
            echo
            exit 0
        fi
        case $choice in
            1) create_user; press_enter ;;
            2) delete_user; press_enter ;;
            3) renew_user; press_enter ;;
            4) lock_user; press_enter ;;
            5) unlock_user; press_enter ;;
            6) edit_user; press_enter ;;
            7) list_users; press_enter ;;
            8) client_config_menu; press_enter ;;
            9) create_trial_account; press_enter ;;
            10) list_trial_accounts; press_enter ;;
            11) view_user_bandwidth; press_enter ;;
            12) bulk_create_users; press_enter ;;

            13) protocol_menu ;;
            14) edge_public_port_menu ;;
            15) torrent_block_menu ;;
            16) traffic_monitor_menu ;;

            17) domain_cert_menu; press_enter ;;
            18) ssh_banner_menu ;;
            19) auto_reboot_menu ;;
            20) backup_data_menu ;;
            21) restore_user_data; press_enter ;;
            22) cleanup_expired; press_enter ;;

            99) uninstall_script ;;
            0) exit 0 ;;
            *) invalid_option ;;
        esac
    done
}

if [[ "$1" == "--install-setup" ]]; then
    initial_setup
    exit 0
fi

# --source-only: source the script (define all functions) without running main_menu.
# Useful for programmatic installation and testing.
if [[ "$1" == "--source-only" ]]; then
    return 0 2>/dev/null || exit 0
fi

require_interactive_terminal
sync_runtime_components_if_needed
main_menu
