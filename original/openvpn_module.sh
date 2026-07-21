#!/bin/bash
# TDZ SSH TUNNEL optional OpenVPN protocol module.
# This file is sourced by menu.sh; it does not execute actions on its own.

TDZ_OVPN_MODULE_VERSION="2026-07-20.8"
TDZ_OVPN_ROOT="${TDZ_OVPN_ROOT:-/etc/tdztunnel/openvpn}"
TDZ_OVPN_STATE="${TDZ_OVPN_STATE:-$TDZ_OVPN_ROOT/state.conf}"
TDZ_OVPN_PKI="${TDZ_OVPN_PKI:-$TDZ_OVPN_ROOT/pki}"
TDZ_OVPN_RUN="${TDZ_OVPN_RUN:-$TDZ_OVPN_ROOT/run}"
TDZ_OVPN_HOOKS="${TDZ_OVPN_HOOKS:-$TDZ_OVPN_ROOT/hooks}"
TDZ_OVPN_PORTAL_BASE="${TDZ_OVPN_PORTAL_BASE:-/var/lib/tdz-openvpn-portal}"
TDZ_OVPN_PROFILES="${TDZ_OVPN_PROFILES:-$TDZ_OVPN_PORTAL_BASE/ovpn-configs}"
TDZ_OVPN_LIB="${TDZ_OVPN_LIB:-/usr/local/lib/tdz-ssh-tunnel}"
TDZ_OVPN_RUNTIME="${TDZ_OVPN_RUNTIME:-$TDZ_OVPN_LIB/tdz_openvpn_runtime.py}"
TDZ_OVPN_GATEWAY="${TDZ_OVPN_GATEWAY:-$TDZ_OVPN_LIB/tdz_openvpn_gateway.py}"
TDZ_OVPN_PORTAL="${TDZ_OVPN_PORTAL:-$TDZ_OVPN_LIB/tdz_openvpn_portal.py}"
TDZ_OVPN_PUBLIC_PATH="/openvpn"
TDZ_OVPN_LOGO_URL="https://raw.githubusercontent.com/yeasinulhoquetuhin/Tuhin-Droid-Zone/master/Screenshot_20260720-074518_Via.png"
TDZ_OVPN_FIXED_PORTAL_PORT=1180
TDZ_OVPN_FIXED_SSL_PORT=446
TDZ_OVPN_FIXED_TCP_PORT=447
TDZ_OVPN_FIXED_UDP_PORT=448
TDZ_OVPN_FIXED_HTTP_PORT=449
TDZ_OVPN_FIXED_WSS_PORT=450
TDZ_OVPN_FIXED_SUPPORT_USERNAME="TUSTDZ"
TDZ_OVPN_PORTAL_PORT="$TDZ_OVPN_FIXED_PORTAL_PORT"
TDZ_OVPN_TCP_TUN_MTU=1400
TDZ_OVPN_TCP_QUEUE_LIMIT=128
# External injector modes add a second TCP/TLS/WebSocket queue in front of
# OpenVPN.  Keep the inner OpenVPN socket large enough for a fast mobile link,
# but bounded so it cannot accumulate the multi-megabyte backlog seen in
# HTTP Custom under load. Direct TCP/HTTP/UDP profiles remain untouched.
TDZ_OVPN_ADAPTER_SOCKET_BUFFER=524288
TDZ_OVPN_SYSTEMD_DIR="${TDZ_OVPN_SYSTEMD_DIR:-/etc/systemd/system}"
TDZ_OVPN_PAM_SERVICE="${TDZ_OVPN_PAM_SERVICE:-/etc/pam.d/tdz-openvpn}"
TDZ_OVPN_SYSCTL="${TDZ_OVPN_SYSCTL:-/etc/sysctl.d/99-tdz-openvpn.conf}"
TDZ_OVPN_FIREWALL="${TDZ_OVPN_FIREWALL:-/usr/local/libexec/tdz-openvpn-firewall}"
TDZ_OVPN_SERVICE_USER="${TDZ_OVPN_SERVICE_USER:-tdzopenvpn}"
TDZ_OVPN_BIN="${TDZ_OVPN_BIN:-/usr/sbin/openvpn}"

TDZ_OVPN_HOST=""
TDZ_OVPN_SAVED_VERSION=""
TDZ_OVPN_TCP_PORT=""
TDZ_OVPN_UDP_PORT=""
TDZ_OVPN_HTTP_PORT=""
TDZ_OVPN_WSS_PORT=""
TDZ_OVPN_SSL_PORT=""
TDZ_OVPN_SUPPORT_USERNAME="$TDZ_OVPN_FIXED_SUPPORT_USERNAME"
TDZ_OVPN_TCP_SUBNET="10.87.0.0"
TDZ_OVPN_UDP_SUBNET="10.88.0.0"
TDZ_OVPN_SERVICE_USER_CREATED=0
TDZ_OVPN_SERVICE_GROUP_CREATED=0
TDZ_OVPN_GATEWAY_CERT_SOURCE="private"
TDZ_OVPN_GATEWAY_CERT_NOTE=""

tdz_openvpn_is_installed() {
    [[ -s "$TDZ_OVPN_STATE" && -s "$TDZ_OVPN_PKI/ca.crt" && -s "$TDZ_OVPN_PKI/server.key" ]]
}

tdz_openvpn_is_active() {
    local unit
    tdz_openvpn_is_installed || return 1
    for unit in tdz-openvpn-network tdz-openvpn-tcp tdz-openvpn-udp \
        tdz-openvpn-http tdz-openvpn-wss tdz-openvpn-ssl \
        tdz-openvpn-portal tdz-openvpn-accounting; do
        systemctl is-active --quiet "$unit.service" || return 1
    done
    return 0
}

tdz_openvpn_load_state() {
    local key value
    [[ -r "$TDZ_OVPN_STATE" ]] || return 1
    TDZ_OVPN_SAVED_VERSION=""; TDZ_OVPN_HOST=""
    # Defaults added after the first public release are assigned before parsing
    # so legacy state files migrate without losing their installation.
    TDZ_OVPN_PORTAL_PORT="$TDZ_OVPN_FIXED_PORTAL_PORT"
    TDZ_OVPN_SUPPORT_USERNAME="$TDZ_OVPN_FIXED_SUPPORT_USERNAME"
    TDZ_OVPN_TCP_PORT=""; TDZ_OVPN_UDP_PORT=""; TDZ_OVPN_HTTP_PORT=""
    TDZ_OVPN_WSS_PORT=""; TDZ_OVPN_SSL_PORT=""
    TDZ_OVPN_TCP_SUBNET=""; TDZ_OVPN_UDP_SUBNET=""
    TDZ_OVPN_SERVICE_USER_CREATED=0
    TDZ_OVPN_SERVICE_GROUP_CREATED=0
    while IFS='=' read -r key value; do
        value=${value%$'\r'}
        case "$key" in
            VERSION) TDZ_OVPN_SAVED_VERSION="$value" ;;
            HOST) TDZ_OVPN_HOST="$value" ;;
            PORTAL_PORT) TDZ_OVPN_PORTAL_PORT="$value" ;;
            TCP_PORT) TDZ_OVPN_TCP_PORT="$value" ;;
            UDP_PORT) TDZ_OVPN_UDP_PORT="$value" ;;
            HTTP_PORT) TDZ_OVPN_HTTP_PORT="$value" ;;
            WSS_PORT) TDZ_OVPN_WSS_PORT="$value" ;;
            SSL_PORT) TDZ_OVPN_SSL_PORT="$value" ;;
            SUPPORT_USERNAME) TDZ_OVPN_SUPPORT_USERNAME="$value" ;;
            TCP_SUBNET) TDZ_OVPN_TCP_SUBNET="$value" ;;
            UDP_SUBNET) TDZ_OVPN_UDP_SUBNET="$value" ;;
            SERVICE_USER_CREATED)
                [[ "$value" == "1" ]] && TDZ_OVPN_SERVICE_USER_CREATED=1 || TDZ_OVPN_SERVICE_USER_CREATED=0
                ;;
            SERVICE_GROUP_CREATED)
                [[ "$value" == "1" ]] && TDZ_OVPN_SERVICE_GROUP_CREATED=1 || TDZ_OVPN_SERVICE_GROUP_CREATED=0
                ;;
        esac
    done < "$TDZ_OVPN_STATE"
    tdz_openvpn_valid_host "$TDZ_OVPN_HOST" || return 1
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_PORTAL_PORT" || return 1
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_TCP_PORT" || return 1
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_UDP_PORT" || return 1
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_HTTP_PORT" || return 1
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_WSS_PORT" || return 1
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_SSL_PORT" || return 1
    tdz_openvpn_valid_telegram_username "$TDZ_OVPN_SUPPORT_USERNAME" || return 1
    tdz_openvpn_valid_subnet "$TDZ_OVPN_TCP_SUBNET" || return 1
    tdz_openvpn_valid_subnet "$TDZ_OVPN_UDP_SUBNET" || return 1
    [[ "$TDZ_OVPN_TCP_SUBNET" != "$TDZ_OVPN_UDP_SUBNET" ]] || return 1
    tdz_openvpn_ports_are_distinct
}

tdz_openvpn_needs_refresh() {
    tdz_openvpn_is_installed || return 1
    tdz_openvpn_load_state || return 0
    [[ "$TDZ_OVPN_SAVED_VERSION" != "$TDZ_OVPN_MODULE_VERSION" ]]
}

tdz_openvpn_save_state() {
    local tmp
    mkdir -p "$TDZ_OVPN_ROOT"
    tmp="${TDZ_OVPN_STATE}.tmp"
    {
        printf 'VERSION=%s\n' "$TDZ_OVPN_MODULE_VERSION"
        printf 'HOST=%s\n' "$TDZ_OVPN_HOST"
        printf 'PORTAL_PORT=%s\n' "$TDZ_OVPN_PORTAL_PORT"
        printf 'TCP_PORT=%s\n' "$TDZ_OVPN_TCP_PORT"
        printf 'UDP_PORT=%s\n' "$TDZ_OVPN_UDP_PORT"
        printf 'HTTP_PORT=%s\n' "$TDZ_OVPN_HTTP_PORT"
        printf 'WSS_PORT=%s\n' "$TDZ_OVPN_WSS_PORT"
        printf 'SSL_PORT=%s\n' "$TDZ_OVPN_SSL_PORT"
        printf 'SUPPORT_USERNAME=%s\n' "$TDZ_OVPN_SUPPORT_USERNAME"
        printf 'TCP_SUBNET=%s\n' "$TDZ_OVPN_TCP_SUBNET"
        printf 'UDP_SUBNET=%s\n' "$TDZ_OVPN_UDP_SUBNET"
        printf 'SERVICE_USER_CREATED=%s\n' "$TDZ_OVPN_SERVICE_USER_CREATED"
        printf 'SERVICE_GROUP_CREATED=%s\n' "$TDZ_OVPN_SERVICE_GROUP_CREATED"
    } > "$tmp"
    chmod 600 "$tmp"
    mv -f "$tmp" "$TDZ_OVPN_STATE"
}

tdz_openvpn_valid_host() {
    local value=${1:-} octet label
    local -a _tdz_host_octets=() _tdz_host_labels=()
    [[ -n "$value" && ${#value} -le 253 ]] || return 1
    if [[ "$value" =~ ^[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+$ ]]; then
        IFS=. read -r -a _tdz_host_octets <<< "$value"
        (( ${#_tdz_host_octets[@]} == 4 )) || return 1
        for octet in "${_tdz_host_octets[@]}"; do
            [[ "$octet" =~ ^[0-9]+$ ]] && (( 10#$octet <= 255 )) || return 1
        done
        return 0
    fi
    [[ "$value" =~ ^[A-Za-z0-9.-]+$ && "$value" != *..* &&
       "$value" != .* && "$value" != *. ]] || return 1
    IFS=. read -r -a _tdz_host_labels <<< "$value"
    for label in "${_tdz_host_labels[@]}"; do
        [[ -n "$label" && ${#label} -le 63 && "$label" != -* && "$label" != *- ]] || return 1
    done
    return 0
}

tdz_openvpn_valid_telegram_username() {
    local value=${1:-}
    [[ "$value" =~ ^[A-Za-z][A-Za-z0-9_]{4,31}$ ]]
}

tdz_openvpn_forbidden_port() {
    local port=${1:-} reserved
    case "$port" in
        22|53|80|442|443|1080|1180|2053|2080|2086|2096|2288|2289|5300|5667|7300|8080|8443|8880|8888|8770|8442|8890|10443) return 0 ;;
        *) ;;
    esac
    for reserved in "${EDGE_PUBLIC_HTTP_PORT:-}" "${EDGE_PUBLIC_TLS_PORT:-}" \
        "${NGINX_INTERNAL_HTTP_PORT:-}" "${NGINX_INTERNAL_TLS_PORT:-}" \
        "${HAPROXY_INTERNAL_DECRYPT_PORT:-}" "${WS_SSH_BRIDGE_PORT:-}"; do
        [[ -n "$reserved" && "$port" == "$reserved" ]] && return 0
    done
    return 1
}

tdz_openvpn_valid_generated_port() {
    local port=${1:-}
    [[ "$port" =~ ^[0-9]+$ ]] && (( port >= 20000 && port <= 31999 )) &&
        ! tdz_openvpn_forbidden_port "$port"
}

tdz_openvpn_valid_saved_port() {
    local port=${1:-}
    [[ "$port" =~ ^[1-9][0-9]{0,4}$ ]] || return 1
    (( 10#$port >= 1 && 10#$port <= 65535 ))
}

tdz_openvpn_valid_configurable_port() {
    local port=${1:-}
    tdz_openvpn_valid_saved_port "$port" || return 1
    case "$port" in
        "$TDZ_OVPN_FIXED_PORTAL_PORT"|"$TDZ_OVPN_FIXED_SSL_PORT"|"$TDZ_OVPN_FIXED_TCP_PORT"|"$TDZ_OVPN_FIXED_UDP_PORT"|\
        "$TDZ_OVPN_FIXED_HTTP_PORT"|"$TDZ_OVPN_FIXED_WSS_PORT") return 0 ;;
        *) ! tdz_openvpn_forbidden_port "$port" ;;
    esac
}

tdz_openvpn_ports_are_distinct() {
    local port
    local -A seen=()
    for port in "$TDZ_OVPN_PORTAL_PORT" "$TDZ_OVPN_SSL_PORT" "$TDZ_OVPN_TCP_PORT" \
        "$TDZ_OVPN_UDP_PORT" "$TDZ_OVPN_HTTP_PORT" "$TDZ_OVPN_WSS_PORT"; do
        tdz_openvpn_valid_saved_port "$port" || return 1
        [[ -z "${seen[$port]+x}" ]] || return 1
        seen["$port"]=1
    done
}

tdz_openvpn_requested_ports_valid() {
    local port
    local -A seen=()
    (( $# == 6 )) || return 1
    for port in "$@"; do
        tdz_openvpn_valid_configurable_port "$port" || return 1
        [[ -z "${seen[$port]+x}" ]] || return 1
        seen["$port"]=1
    done
}

tdz_openvpn_ports_match_layout() {
    (( $# == 6 )) || return 1
    [[ "$1" == "$TDZ_OVPN_PORTAL_PORT" &&
       "$2" == "$TDZ_OVPN_SSL_PORT" &&
       "$3" == "$TDZ_OVPN_TCP_PORT" &&
       "$4" == "$TDZ_OVPN_UDP_PORT" &&
       "$5" == "$TDZ_OVPN_HTTP_PORT" &&
       "$6" == "$TDZ_OVPN_WSS_PORT" ]]
}

tdz_openvpn_apply_fixed_port_mapping() {
    TDZ_OVPN_PORTAL_PORT="$TDZ_OVPN_FIXED_PORTAL_PORT"
    TDZ_OVPN_SSL_PORT="$TDZ_OVPN_FIXED_SSL_PORT"
    TDZ_OVPN_TCP_PORT="$TDZ_OVPN_FIXED_TCP_PORT"
    TDZ_OVPN_UDP_PORT="$TDZ_OVPN_FIXED_UDP_PORT"
    TDZ_OVPN_HTTP_PORT="$TDZ_OVPN_FIXED_HTTP_PORT"
    TDZ_OVPN_WSS_PORT="$TDZ_OVPN_FIXED_WSS_PORT"
}

tdz_openvpn_ports_match_fixed_mapping() {
    tdz_openvpn_ports_match_layout "$TDZ_OVPN_FIXED_PORTAL_PORT" "$TDZ_OVPN_FIXED_SSL_PORT" \
        "$TDZ_OVPN_FIXED_TCP_PORT" "$TDZ_OVPN_FIXED_UDP_PORT" \
        "$TDZ_OVPN_FIXED_HTTP_PORT" "$TDZ_OVPN_FIXED_WSS_PORT"
}

tdz_openvpn_valid_subnet() {
    local subnet=${1:-} a b c d
    IFS=. read -r a b c d <<< "$subnet"
    [[ "$a" == "10" && "$b" =~ ^[0-9]+$ && "$c" =~ ^[0-9]+$ && "$d" == "0" ]] &&
        (( 10#$b >= 64 && 10#$b <= 223 && 10#$c >= 0 && 10#$c <= 255 ))
}

tdz_openvpn_random_subnet() {
    local second third subnet attempt route_match
    for ((attempt=0; attempt<300; attempt++)); do
        second=$((64 + RANDOM % 160))
        third=$((RANDOM % 256))
        subnet="10.${second}.${third}.0"
        [[ "$subnet" == "$TDZ_OVPN_TCP_SUBNET" || "$subnet" == "$TDZ_OVPN_UDP_SUBNET" ]] && continue
        route_match=$(ip -4 route show match "${subnet}/24" 2>/dev/null || true)
        if [[ -n "$route_match" ]] && grep -Evq '^[[:space:]]*default([[:space:]]|$)' <<< "$route_match"; then
            continue
        fi
        printf '%s' "$subnet"
        return 0
    done
    return 1
}

tdz_openvpn_port_listening() {
    local port=$1 proto=${2:-any}
    case "$proto" in
        tcp) ss -H -lnt "sport = :$port" 2>/dev/null | grep -q . ;;
        udp) ss -H -lnu "sport = :$port" 2>/dev/null | grep -q . ;;
        *) { ss -H -lnt "sport = :$port" 2>/dev/null; ss -H -lnu "sport = :$port" 2>/dev/null; } | grep -q . ;;
    esac
}

tdz_openvpn_detect_host() {
    local detected=""
    if declare -F detect_preferred_host >/dev/null 2>&1; then
        detected=$(detect_preferred_host 2>/dev/null || true)
    fi
    if ! tdz_openvpn_valid_host "$detected"; then
        detected=$(curl -4 -fsS --max-time 5 icanhazip.com 2>/dev/null | tr -d '[:space:]' || true)
    fi
    if ! tdz_openvpn_valid_host "$detected"; then
        detected=$(hostname -I 2>/dev/null | awk '{print $1}')
    fi
    if ! tdz_openvpn_valid_host "$detected"; then
        detected=$(hostname -f 2>/dev/null || true)
    fi
    tdz_openvpn_valid_host "$detected" || detected=""
    printf '%s' "$detected"
}

tdz_openvpn_install_packages() {
    export DEBIAN_FRONTEND=noninteractive
    if declare -F tdz_apt_install >/dev/null 2>&1; then
        tdz_apt_install openvpn openssl libpam-modules iptables iproute2 util-linux python3 zip >/dev/null 2>&1
    else
        apt-get update -y >/dev/null 2>&1 &&
            apt-get install -y openvpn openssl libpam-modules iptables iproute2 util-linux python3 zip >/dev/null 2>&1
    fi
}

tdz_openvpn_resolve_binary() {
    local detected
    [[ -x "$TDZ_OVPN_BIN" ]] && return 0
    detected=$(command -v openvpn 2>/dev/null || true)
    [[ -n "$detected" && -x "$detected" ]] || return 1
    TDZ_OVPN_BIN="$detected"
}

tdz_openvpn_python_supported() {
    command -v python3 >/dev/null 2>&1 &&
        python3 -c 'import sys; raise SystemExit(sys.version_info < (3, 7))' >/dev/null 2>&1
}

tdz_openvpn_find_pam_plugin() {
    local plugin=""
    plugin=$(find /usr/lib /usr/lib64 -type f -name 'openvpn-plugin-auth-pam.so' -print -quit 2>/dev/null || true)
    [[ -n "$plugin" && -r "$plugin" ]] || return 1
    printf '%s' "$plugin"
}

tdz_openvpn_ensure_service_user() {
    local uid shell
    if id "$TDZ_OVPN_SERVICE_USER" >/dev/null 2>&1; then
        uid=$(id -u "$TDZ_OVPN_SERVICE_USER" 2>/dev/null || echo 65535)
        shell=$(getent passwd "$TDZ_OVPN_SERVICE_USER" | cut -d: -f7)
        (( uid < 1000 )) && [[ "$shell" == */nologin || "$shell" == */false ]] &&
            getent group "$TDZ_OVPN_SERVICE_USER" >/dev/null 2>&1 &&
            id -nG "$TDZ_OVPN_SERVICE_USER" 2>/dev/null | tr ' ' '\n' | grep -Fxq "$TDZ_OVPN_SERVICE_USER"
        return
    fi
    if ! getent group "$TDZ_OVPN_SERVICE_USER" >/dev/null 2>&1; then
        groupadd --system "$TDZ_OVPN_SERVICE_USER" >/dev/null 2>&1 || return 1
        TDZ_OVPN_SERVICE_GROUP_CREATED=1
    fi
    useradd --system --gid "$TDZ_OVPN_SERVICE_USER" --home-dir /nonexistent \
        --shell /usr/sbin/nologin "$TDZ_OVPN_SERVICE_USER" >/dev/null 2>&1 || {
            if [[ "$TDZ_OVPN_SERVICE_GROUP_CREATED" == "1" ]]; then
                groupdel "$TDZ_OVPN_SERVICE_USER" >/dev/null 2>&1 || true
                TDZ_OVPN_SERVICE_GROUP_CREATED=0
            fi
            return 1
        }
    TDZ_OVPN_SERVICE_USER_CREATED=1
}

tdz_openvpn_apply_private_permissions() {
    # The transport gateways need only the copied outer-TLS certificate/key.
    # The OpenVPN server key, CA key, tls-crypt key, configs, hooks, and state
    # remain root-only even though the gateway account can traverse the PKI.
    chown root:"$TDZ_OVPN_SERVICE_USER" "$TDZ_OVPN_ROOT" "$TDZ_OVPN_PKI"
    chmod 750 "$TDZ_OVPN_ROOT" "$TDZ_OVPN_PKI"
    chown root:root "$TDZ_OVPN_RUN" "$TDZ_OVPN_HOOKS"
    chmod 700 "$TDZ_OVPN_RUN" "$TDZ_OVPN_HOOKS"

    chown -R root:"$TDZ_OVPN_SERVICE_USER" "$TDZ_OVPN_PORTAL_BASE"
    find "$TDZ_OVPN_PORTAL_BASE" -type d -exec chmod 750 {} +
    find "$TDZ_OVPN_PORTAL_BASE" -type f -exec chmod 640 {} +
}

tdz_openvpn_has_modern_cipher_option() {
    local version major minor
    version=$("$TDZ_OVPN_BIN" --version 2>/dev/null | awk 'NR==1 {print $2}')
    IFS=. read -r major minor _rest <<< "$version"
    [[ "$major" =~ ^[0-9]+$ && "$minor" =~ ^[0-9]+$ ]] || return 1
    (( major > 2 || (major == 2 && minor >= 5) ))
}

tdz_openvpn_generate_pki() {
    local san
    mkdir -p "$TDZ_OVPN_PKI"
    if [[ ! -s "$TDZ_OVPN_PKI/ca.crt" || ! -s "$TDZ_OVPN_PKI/ca.key" ]] ||
       ! tdz_openvpn_cert_key_match "$TDZ_OVPN_PKI/ca.crt" "$TDZ_OVPN_PKI/ca.key"; then
        rm -f "$TDZ_OVPN_PKI/ca.srl"
        openssl req -x509 -newkey rsa:3072 -sha256 -nodes -days 3650 \
            -subj "/CN=TDZ OpenVPN Private CA" \
            -addext "basicConstraints=critical,CA:TRUE" \
            -addext "keyUsage=critical,keyCertSign,cRLSign" \
            -addext "subjectKeyIdentifier=hash" \
            -keyout "$TDZ_OVPN_PKI/ca.key" -out "$TDZ_OVPN_PKI/ca.crt" >/dev/null 2>&1
    fi
    if [[ "$TDZ_OVPN_HOST" =~ ^[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+$ ]]; then
        san="IP:${TDZ_OVPN_HOST}"
    else
        san="DNS:${TDZ_OVPN_HOST}"
    fi
    openssl req -new -newkey rsa:3072 -sha256 -nodes \
        -subj "/CN=tdz-openvpn-server" \
        -keyout "$TDZ_OVPN_PKI/server.key.new" -out "$TDZ_OVPN_PKI/server.csr" >/dev/null 2>&1
    {
        echo "basicConstraints=CA:FALSE"
        echo "keyUsage=digitalSignature,keyEncipherment"
        echo "extendedKeyUsage=serverAuth"
        echo "subjectAltName=${san}"
    } > "$TDZ_OVPN_PKI/server.ext"
    openssl x509 -req -in "$TDZ_OVPN_PKI/server.csr" \
        -CA "$TDZ_OVPN_PKI/ca.crt" -CAkey "$TDZ_OVPN_PKI/ca.key" -CAcreateserial \
        -days 825 -sha256 -extfile "$TDZ_OVPN_PKI/server.ext" \
        -out "$TDZ_OVPN_PKI/server.crt.new" >/dev/null 2>&1
    mv -f "$TDZ_OVPN_PKI/server.key.new" "$TDZ_OVPN_PKI/server.key"
    mv -f "$TDZ_OVPN_PKI/server.crt.new" "$TDZ_OVPN_PKI/server.crt"
    rm -f "$TDZ_OVPN_PKI/server.csr" "$TDZ_OVPN_PKI/server.ext"
    if [[ ! -s "$TDZ_OVPN_PKI/tls-crypt.key" ]]; then
        "$TDZ_OVPN_BIN" --genkey secret "$TDZ_OVPN_PKI/tls-crypt.key" >/dev/null 2>&1 ||
            "$TDZ_OVPN_BIN" --genkey --secret "$TDZ_OVPN_PKI/tls-crypt.key" >/dev/null 2>&1
    fi
    chmod 600 "$TDZ_OVPN_PKI"/*.key
    chmod 644 "$TDZ_OVPN_PKI"/*.crt
    openssl verify -CAfile "$TDZ_OVPN_PKI/ca.crt" "$TDZ_OVPN_PKI/server.crt" >/dev/null 2>&1
    openssl x509 -checkend 86400 -noout -in "$TDZ_OVPN_PKI/server.crt" >/dev/null 2>&1
}

tdz_openvpn_certificate_covers_host() {
    local certificate=$1 host=$2 host_check="-checkhost" result
    [[ "$host" =~ ^[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+$ ]] && host_check="-checkip"
    # Some OpenSSL 3 builds report "does NOT match" while still exiting 0,
    # so require the affirmative result instead of trusting only the status.
    result=$(LC_ALL=C openssl x509 -in "$certificate" "$host_check" "$host" -noout 2>&1) || return 1
    [[ "$result" == *" does match certificate" ]]
}

tdz_openvpn_prepare_gateway_certificate() {
    local shared_cert=${SSL_CERT_CHAIN_FILE:-} shared_key=${SSL_CERT_KEY_FILE:-}
    local cert_hash key_hash
    TDZ_OVPN_GATEWAY_CERT_SOURCE="private"
    TDZ_OVPN_GATEWAY_CERT_NOTE=""
    cp "$TDZ_OVPN_PKI/server.crt" "$TDZ_OVPN_PKI/gateway.crt"
    cp "$TDZ_OVPN_PKI/server.key" "$TDZ_OVPN_PKI/gateway.key"

    if [[ -n "$shared_cert" || -n "$shared_key" ]]; then
        if [[ ! -r "$shared_cert" || ! -r "$shared_key" ]]; then
            TDZ_OVPN_GATEWAY_CERT_NOTE="shared-files-unavailable"
        else
            cert_hash=$(openssl x509 -in "$shared_cert" -pubkey -noout 2>/dev/null | openssl sha256 2>/dev/null || true)
            key_hash=$(openssl pkey -in "$shared_key" -pubout 2>/dev/null | openssl sha256 2>/dev/null || true)
            if [[ -z "$cert_hash" || "$cert_hash" != "$key_hash" ]] ||
               ! openssl x509 -in "$shared_cert" -checkend 86400 -noout >/dev/null 2>&1; then
                TDZ_OVPN_GATEWAY_CERT_NOTE="shared-certificate-invalid"
            elif ! tdz_openvpn_certificate_covers_host "$shared_cert" "$TDZ_OVPN_HOST"; then
                TDZ_OVPN_GATEWAY_CERT_NOTE="shared-host-mismatch"
            else
                cp "$shared_cert" "$TDZ_OVPN_PKI/gateway.crt"
                cp "$shared_key" "$TDZ_OVPN_PKI/gateway.key"
                TDZ_OVPN_GATEWAY_CERT_SOURCE="shared"
            fi
        fi
    fi
    chmod 644 "$TDZ_OVPN_PKI/gateway.crt"
    chmod 640 "$TDZ_OVPN_PKI/gateway.key"
    chown root:"$TDZ_OVPN_SERVICE_USER" "$TDZ_OVPN_PKI/gateway.key"
    openssl x509 -checkend 86400 -noout -in "$TDZ_OVPN_PKI/gateway.crt" >/dev/null 2>&1
}

tdz_openvpn_cert_key_match() {
    local certificate=$1 private_key=$2 cert_hash key_hash
    cert_hash=$(openssl x509 -in "$certificate" -pubkey -noout 2>/dev/null | openssl sha256 2>/dev/null) || return 1
    key_hash=$(openssl pkey -in "$private_key" -pubout 2>/dev/null | openssl sha256 2>/dev/null) || return 1
    [[ -n "$cert_hash" && "$cert_hash" == "$key_hash" ]]
}

tdz_openvpn_server_certificate_current() {
    [[ -s "$TDZ_OVPN_PKI/ca.crt" && -s "$TDZ_OVPN_PKI/ca.key" &&
       -s "$TDZ_OVPN_PKI/server.crt" && -s "$TDZ_OVPN_PKI/server.key" &&
       -s "$TDZ_OVPN_PKI/tls-crypt.key" ]] &&
        tdz_openvpn_cert_key_match "$TDZ_OVPN_PKI/ca.crt" "$TDZ_OVPN_PKI/ca.key" &&
        tdz_openvpn_cert_key_match "$TDZ_OVPN_PKI/server.crt" "$TDZ_OVPN_PKI/server.key" &&
        openssl verify -CAfile "$TDZ_OVPN_PKI/ca.crt" "$TDZ_OVPN_PKI/server.crt" >/dev/null 2>&1 &&
        openssl x509 -checkend 604800 -noout -in "$TDZ_OVPN_PKI/server.crt" >/dev/null 2>&1 &&
        tdz_openvpn_certificate_covers_host "$TDZ_OVPN_PKI/server.crt" "$TDZ_OVPN_HOST"
}

tdz_openvpn_ensure_pki() {
    tdz_openvpn_server_certificate_current && return 0
    tdz_openvpn_generate_pki
}

tdz_openvpn_write_hooks() {
    mkdir -p "$TDZ_OVPN_HOOKS" "$TDZ_OVPN_RUN"
    local instance action
    for instance in tcp udp; do
        for action in connect disconnect; do
            printf '#!/bin/sh\nexport TDZ_OVPN_INSTANCE=%s\nexec %s %s\n' \
                "$instance" "$TDZ_OVPN_RUNTIME" "$action" > "$TDZ_OVPN_HOOKS/${action}-${instance}"
            chmod 700 "$TDZ_OVPN_HOOKS/${action}-${instance}"
        done
    done
    cat > "$TDZ_OVPN_HOOKS/up-tcp" <<'EOF'
#!/bin/sh
# Fair-queue inner flows before they enter the single OpenVPN TCP stream.  This
# keeps DNS, SSH and ping responsive during a bulk transfer.  The tunnel must
# remain usable on kernels without fq_codel, so tuning is deliberately optional.
if [ -n "${dev:-}" ] && command -v tc >/dev/null 2>&1; then
    tc qdisc replace dev "$dev" root fq_codel \
        limit 1024 flows 1024 target 5ms interval 100ms >/dev/null 2>&1 || true
fi
exit 0
EOF
    chmod 700 "$TDZ_OVPN_HOOKS/up-tcp"
}

tdz_openvpn_write_server_config() {
    local instance=$1 proto=$2 port=$3 subnet=$4 pam_plugin=$5 config cipher_order
    config="$TDZ_OVPN_ROOT/server-${instance}.conf"
    cipher_order="AES-256-GCM:AES-128-GCM"
    [[ "$proto" == "tcp-server" ]] && cipher_order="AES-128-GCM:AES-256-GCM"
    {
        echo "port $port"
        echo "proto $proto"
        echo "dev tun-tdz-${instance}"
        echo "topology subnet"
        echo "server $subnet 255.255.255.0"
        echo "ca $TDZ_OVPN_PKI/ca.crt"
        echo "cert $TDZ_OVPN_PKI/server.crt"
        echo "key $TDZ_OVPN_PKI/server.key"
        echo "dh none"
        echo "ecdh-curve prime256v1"
        echo "tls-crypt $TDZ_OVPN_PKI/tls-crypt.key"
        echo "tls-version-min 1.2"
        echo "verify-client-cert none"
        echo "username-as-common-name"
        echo "duplicate-cn"
        echo "max-clients 250"
        echo "plugin $pam_plugin tdz-openvpn"
        echo "script-security 2"
        echo "client-connect $TDZ_OVPN_HOOKS/connect-${instance}"
        echo "client-disconnect $TDZ_OVPN_HOOKS/disconnect-${instance}"
        [[ "$proto" == "tcp-server" ]] && echo "up $TDZ_OVPN_HOOKS/up-tcp"
        # Android injector VPN services commonly expose a 1400-byte TUN.  The
        # TCP backend must use the same value or it can send 1401-1500 byte
        # packets that those clients visibly drop as "tun packet too large".
        [[ "$proto" == "tcp-server" ]] && echo "tun-mtu $TDZ_OVPN_TCP_TUN_MTU"
        echo "cipher AES-256-GCM"
        if tdz_openvpn_has_modern_cipher_option; then
            # Modern clients negotiate AES-128-GCM first for lower mobile CPU
            # cost. AES-256-GCM remains available and is the legacy fallback.
            echo "data-ciphers $cipher_order"
            echo "data-ciphers-fallback AES-256-GCM"
            echo "allow-compression no"
        else
            echo "ncp-ciphers $cipher_order"
        fi
        echo "auth SHA256"
        echo "keepalive 10 60"
        # Linux can skip a redundant readiness poll before UDP writes. This
        # does not change the wire protocol or any client requirement.
        [[ "$proto" == "udp" ]] && echo "fast-io"
        # All adapter modes ultimately use the TCP OpenVPN backend. Disabling
        # Nagle on both peers prevents small interactive packets from waiting
        # behind an additional TCP aggregation delay.
        [[ "$proto" == "tcp-server" ]] && echo "tcp-nodelay"
        # The default queue of 64 packets is easy to exhaust on a variable 4G
        # path, after which OpenVPN drops tunnel packets before TCP can deliver
        # them.  Doubling it absorbs short bursts without creating a huge FIFO.
        [[ "$proto" == "tcp-server" ]] && echo "tcp-queue-limit $TDZ_OVPN_TCP_QUEUE_LIMIT"
        echo "persist-key"
        echo "persist-tun"
        echo "push \"redirect-gateway def1 bypass-dhcp\""
        echo "push \"dhcp-option DNS 1.1.1.1\""
        echo "push \"dhcp-option DNS 8.8.8.8\""
        echo "push \"block-ipv6\""
        echo "sndbuf 0"
        echo "rcvbuf 0"
        echo "push \"sndbuf 0\""
        echo "push \"rcvbuf 0\""
        echo "status $TDZ_OVPN_RUN/status-${instance}.tsv 1"
        echo "status-version 3"
        echo "management $TDZ_OVPN_RUN/management-${instance}.sock unix"
        echo "management-client-user root"
        echo "management-client-group root"
        [[ "$proto" == "udp" ]] && echo "explicit-exit-notify 1"
        echo "verb 3"
        echo "mute 20"
    } > "$config"
    chmod 600 "$config"
}

tdz_openvpn_write_pam() {
    mkdir -p "$(dirname "$TDZ_OVPN_PAM_SERVICE")"
    {
        echo '# TDZ managed OpenVPN authentication'
        echo 'auth required pam_unix.so'
        # DB expiry is checked by the TDZ client-connect hook through the end
        # of the displayed date.  pam_permit avoids shadow's start-of-day
        # expiry interpretation while pam_unix authentication still enforces
        # password locks.
        echo 'account required pam_permit.so'
    } > "$TDZ_OVPN_PAM_SERVICE"
    chmod 644 "$TDZ_OVPN_PAM_SERVICE"
}

tdz_openvpn_write_systemd_units() {
    local instance gateway_args
    mkdir -p "$TDZ_OVPN_SYSTEMD_DIR"
    for instance in tcp udp; do
        cat > "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-${instance}.service" <<EOF
[Unit]
Description=TDZ OpenVPN ${instance^^} Server
After=network-online.target tdz-openvpn-network.service
Wants=network-online.target
Requires=tdz-openvpn-network.service

[Service]
Type=simple
ExecStartPre=/usr/bin/rm -f $TDZ_OVPN_RUN/management-${instance}.sock
ExecStart=$TDZ_OVPN_BIN --config $TDZ_OVPN_ROOT/server-${instance}.conf
Restart=on-failure
RestartSec=3
LimitNOFILE=65536

[Install]
WantedBy=multi-user.target
EOF
    done

    tdz_openvpn_write_gateway_unit "http" "$TDZ_OVPN_HTTP_PORT" "http" ""
    tdz_openvpn_write_gateway_unit "wss" "$TDZ_OVPN_WSS_PORT" "http" "--tls-cert $TDZ_OVPN_PKI/gateway.crt --tls-key $TDZ_OVPN_PKI/gateway.key"
    tdz_openvpn_write_gateway_unit "ssl" "$TDZ_OVPN_SSL_PORT" "raw" "--tls-cert $TDZ_OVPN_PKI/gateway.crt --tls-key $TDZ_OVPN_PKI/gateway.key"

    cat > "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-portal.service" <<EOF
[Unit]
Description=TDZ OpenVPN Profile Portal
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
ExecStart=/usr/bin/python3 $TDZ_OVPN_PORTAL --listen 0.0.0.0 --port $TDZ_OVPN_PORTAL_PORT --public-host $TDZ_OVPN_HOST --allow-http --root $TDZ_OVPN_PORTAL_BASE --tls-cert $TDZ_OVPN_PKI/gateway.crt --tls-key $TDZ_OVPN_PKI/gateway.key
Restart=on-failure
RestartSec=3
User=$TDZ_OVPN_SERVICE_USER
Group=$TDZ_OVPN_SERVICE_USER
NoNewPrivileges=true
PrivateTmp=true
ProtectHome=true
ProtectSystem=strict
PrivateDevices=true
ProtectKernelTunables=true
ProtectKernelModules=true
ProtectControlGroups=true
RestrictSUIDSGID=true
LockPersonality=true
RestrictAddressFamilies=AF_INET AF_INET6
CapabilityBoundingSet=CAP_NET_BIND_SERVICE
AmbientCapabilities=CAP_NET_BIND_SERVICE
MemoryDenyWriteExecute=true
RestrictRealtime=true

[Install]
WantedBy=multi-user.target
EOF

    cat > "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-accounting.service" <<EOF
[Unit]
Description=TDZ OpenVPN Account and Usage Enforcement
After=tdz-openvpn-tcp.service tdz-openvpn-udp.service
Wants=tdz-openvpn-tcp.service tdz-openvpn-udp.service

[Service]
Type=simple
ExecStart=/usr/bin/python3 $TDZ_OVPN_RUNTIME watch --interval 1
Restart=always
RestartSec=2
Nice=10

[Install]
WantedBy=multi-user.target
EOF
}

tdz_openvpn_write_gateway_unit() {
    local name=$1 port=$2 mode=$3 extra=$4
    cat > "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-${name}.service" <<EOF
[Unit]
Description=TDZ OpenVPN ${name^^} Gateway
After=network-online.target tdz-openvpn-tcp.service
Wants=network-online.target
Requires=tdz-openvpn-tcp.service

[Service]
Type=simple
ExecStart=/usr/bin/python3 $TDZ_OVPN_GATEWAY --listen 0.0.0.0 --port $port --backend-host 127.0.0.1 --backend-port $TDZ_OVPN_TCP_PORT --mode $mode $extra
Restart=on-failure
RestartSec=2
LimitNOFILE=65536
User=$TDZ_OVPN_SERVICE_USER
Group=$TDZ_OVPN_SERVICE_USER
NoNewPrivileges=true
PrivateTmp=true
ProtectHome=true
ProtectSystem=strict
PrivateDevices=true
ProtectKernelTunables=true
ProtectKernelModules=true
ProtectControlGroups=true
RestrictSUIDSGID=true
LockPersonality=true
RestrictAddressFamilies=AF_INET AF_INET6
CapabilityBoundingSet=CAP_NET_BIND_SERVICE
AmbientCapabilities=CAP_NET_BIND_SERVICE
MemoryDenyWriteExecute=true
RestrictRealtime=true

[Install]
WantedBy=multi-user.target
EOF
}

tdz_openvpn_write_network_service() {
    mkdir -p "$(dirname "$TDZ_OVPN_FIREWALL")"
    mkdir -p "$TDZ_OVPN_SYSTEMD_DIR" "$(dirname "$TDZ_OVPN_SYSCTL")"
    cat > "$TDZ_OVPN_FIREWALL" <<EOF
#!/bin/sh
set -eu
action=\${1:-start}
TCP_SUBNET="$TDZ_OVPN_TCP_SUBNET/24"
UDP_SUBNET="$TDZ_OVPN_UDP_SUBNET/24"
TCP_PORT="$TDZ_OVPN_TCP_PORT"
UDP_PORT="$TDZ_OVPN_UDP_PORT"
HTTP_PORT="$TDZ_OVPN_HTTP_PORT"
WSS_PORT="$TDZ_OVPN_WSS_PORT"
SSL_PORT="$TDZ_OVPN_SSL_PORT"
PORTAL_PORT="$TDZ_OVPN_PORTAL_PORT"

filter_add() { iptables -C "\$@" >/dev/null 2>&1 || iptables -I "\$@"; }
nat_add() { iptables -t nat -C "\$@" >/dev/null 2>&1 || iptables -t nat -I "\$@"; }
mangle_add() { iptables -t mangle -C "\$@" >/dev/null 2>&1 || iptables -t mangle -I "\$@"; }
filter_del() { while iptables -C "\$@" >/dev/null 2>&1; do iptables -D "\$@"; done; }
nat_del() { while iptables -t nat -C "\$@" >/dev/null 2>&1; do iptables -t nat -D "\$@"; done; }
mangle_del() { while iptables -t mangle -C "\$@" >/dev/null 2>&1; do iptables -t mangle -D "\$@"; done; }

STARTING=0
rollback_partial_start() {
    rc=\$?
    trap - 0
    if [ "\$STARTING" = 1 ] && [ "\$rc" -ne 0 ]; then
        "\$0" stop >/dev/null 2>&1 || true
    fi
    exit "\$rc"
}
trap rollback_partial_start 0

if [ "\$action" = start ]; then
    STARTING=1
    sysctl -w net.ipv4.ip_forward=1 >/dev/null
    filter_add INPUT -p tcp -m multiport --dports "\$TCP_PORT,\$HTTP_PORT,\$WSS_PORT,\$SSL_PORT,\$PORTAL_PORT" -j ACCEPT
    filter_add INPUT -p udp --dport "\$UDP_PORT" -j ACCEPT
    for subnet in "\$TCP_SUBNET" "\$UDP_SUBNET"; do
        filter_add FORWARD -s "\$subnet" -j ACCEPT
        filter_add FORWARD -d "\$subnet" -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
        nat_add POSTROUTING -s "\$subnet" -j MASQUERADE
    done
    # Clamp inner TCP handshakes to the routed 1400-byte tunnel PMTU.  This is
    # independent of OpenVPN's UDP-only mssfix option and prevents oversized
    # return packets on Android injector clients.
    mangle_add FORWARD -s "\$TCP_SUBNET" -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
    mangle_add FORWARD -d "\$TCP_SUBNET" -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
    for source in "\$TCP_SUBNET" "\$UDP_SUBNET"; do
        for destination in "\$TCP_SUBNET" "\$UDP_SUBNET"; do
            filter_add FORWARD -s "\$source" -d "\$destination" -j DROP
        done
    done
    STARTING=0
else
    filter_del INPUT -p tcp -m multiport --dports "\$TCP_PORT,\$HTTP_PORT,\$WSS_PORT,\$SSL_PORT,\$PORTAL_PORT" -j ACCEPT
    filter_del INPUT -p udp --dport "\$UDP_PORT" -j ACCEPT
    for subnet in "\$TCP_SUBNET" "\$UDP_SUBNET"; do
        filter_del FORWARD -s "\$subnet" -j ACCEPT
        filter_del FORWARD -d "\$subnet" -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
        nat_del POSTROUTING -s "\$subnet" -j MASQUERADE
    done
    mangle_del FORWARD -s "\$TCP_SUBNET" -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
    mangle_del FORWARD -d "\$TCP_SUBNET" -p tcp --tcp-flags SYN,RST SYN -j TCPMSS --clamp-mss-to-pmtu
    for source in "\$TCP_SUBNET" "\$UDP_SUBNET"; do
        for destination in "\$TCP_SUBNET" "\$UDP_SUBNET"; do
            filter_del FORWARD -s "\$source" -d "\$destination" -j DROP
        done
    done
fi
EOF
    chmod 700 "$TDZ_OVPN_FIREWALL"
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
}

tdz_openvpn_profile_common() {
    local compatibility=${1:-modern}
    local cipher_order=${2:-AES-256-GCM:AES-128-GCM}
    local cipher_compatibility
    if [[ "$compatibility" == "adapter" ]]; then
        # Embedded OpenVPN cores in injector apps can identify themselves as
        # 2.5 while still rejecting data-ciphers. Keep their profile on the
        # negotiated AES-256-GCM cipher without emitting unsupported options.
        cipher_compatibility='ignore-unknown-option pull-filter block-ipv6'
    else
        cipher_compatibility='ignore-unknown-option data-ciphers data-ciphers-fallback block-ipv6'
    fi
    cat <<EOF
client
dev tun
setenv CLIENT_CERT 0
$cipher_compatibility
resolv-retry infinite
nobind
persist-key
persist-tun
remote-cert-tls server
verify-x509-name tdz-openvpn-server name
auth-user-pass
auth-retry interact
EOF
    if [[ "$compatibility" == "adapter" ]]; then
        cat <<EOF
# Prevent an external injector and OpenVPN from each holding several MB of
# queued TCP data. This cap applies only to WS/WSS/SSL adapter profiles.
pull-filter ignore "sndbuf"
pull-filter ignore "rcvbuf"
sndbuf $TDZ_OVPN_ADAPTER_SOCKET_BUFFER
rcvbuf $TDZ_OVPN_ADAPTER_SOCKET_BUFFER
EOF
    fi
    cat <<EOF
cipher AES-256-GCM
EOF
    if [[ "$compatibility" != "adapter" ]]; then
        cat <<EOF
data-ciphers $cipher_order
data-ciphers-fallback AES-256-GCM
EOF
    fi
    cat <<EOF
auth SHA256
tls-version-min 1.2
connect-timeout 15
connect-retry 3 15
verb 3
<ca>
$(cat "$TDZ_OVPN_PKI/ca.crt")
</ca>
<tls-crypt>
$(cat "$TDZ_OVPN_PKI/tls-crypt.key")
</tls-crypt>
EOF
}

tdz_openvpn_write_profile() {
    local file=$1 proto=$2 remote_port=$3 header=${4:-} compatibility=${5:-modern}
    local protect_outer_route=${6:-false}
    local cipher_order="AES-256-GCM:AES-128-GCM"
    [[ "$proto" == "tcp-client" ]] && cipher_order="AES-128-GCM:AES-256-GCM"
    {
        [[ -n "$header" ]] && printf '# %s\n' "$header"
        echo "proto $proto"
        echo "remote $TDZ_OVPN_HOST $remote_port"
        [[ "$proto" == "tcp-client" ]] && echo "tun-mtu $TDZ_OVPN_TCP_TUN_MTU"
        if [[ "$protect_outer_route" == "true" ]]; then
            # Injector apps create an outer WS/TLS socket before OpenVPN adds
            # its default route. Pin that public endpoint to the original
            # gateway so the carrier socket cannot be routed back into tun.
            echo "route $TDZ_OVPN_HOST 255.255.255.255 net_gateway"
        fi
        tdz_openvpn_profile_common "$compatibility" "$cipher_order"
    } > "$TDZ_OVPN_PROFILES/$file"
    chmod 644 "$TDZ_OVPN_PROFILES/$file"
}

tdz_openvpn_generate_profiles_into() {
    mkdir -p "$TDZ_OVPN_PROFILES"
    rm -f "$TDZ_OVPN_PROFILES"/*.ovpn "$TDZ_OVPN_PROFILES"/*.zip \
        "$TDZ_OVPN_PROFILES"/*.txt "$TDZ_OVPN_PROFILES"/*.crt 2>/dev/null || true

    tdz_openvpn_write_profile "tdz-openvpn-udp.ovpn" "udp" "$TDZ_OVPN_UDP_PORT" "Official OpenVPN clients: direct UDP"
    tdz_openvpn_write_profile "tdz-openvpn-tcp.ovpn" "tcp-client" "$TDZ_OVPN_TCP_PORT" "Official OpenVPN clients: direct TCP"
    {
        echo "proto tcp-client"
        echo "remote $TDZ_OVPN_HOST $TDZ_OVPN_TCP_PORT"
        echo "http-proxy $TDZ_OVPN_HOST $TDZ_OVPN_HTTP_PORT"
        echo "http-proxy-option VERSION 1.1"
        echo "tun-mtu $TDZ_OVPN_TCP_TUN_MTU"
        tdz_openvpn_profile_common modern "AES-128-GCM:AES-256-GCM"
    } > "$TDZ_OVPN_PROFILES/tdz-openvpn-http-connect.ovpn"
    chmod 644 "$TDZ_OVPN_PROFILES/tdz-openvpn-http-connect.ovpn"

    tdz_openvpn_write_profile "tdz-openvpn-ws-injector.ovpn" "tcp-client" "$TDZ_OVPN_HTTP_PORT" "Injector adapter required: HTTP Payload or WebSocket" "adapter" "true"
    tdz_openvpn_write_profile "tdz-openvpn-wss-injector.ovpn" "tcp-client" "$TDZ_OVPN_WSS_PORT" "Injector adapter required: TLS WebSocket; SNI is the portal host" "adapter" "true"
    tdz_openvpn_write_profile "tdz-openvpn-ssl-injector.ovpn" "tcp-client" "$TDZ_OVPN_SSL_PORT" "External SSL/TLS adapter required; SNI is the portal host" "adapter" "true"

    cp "$TDZ_OVPN_PKI/ca.crt" "$TDZ_OVPN_PROFILES/tdz-openvpn-ca.crt"
    cat > "$TDZ_OVPN_PROFILES/connection-guide.txt" <<EOF
TDZ SSH TUNNEL - OpenVPN Connection Guide

Server: $TDZ_OVPN_HOST
Portal: https://$TDZ_OVPN_HOST:$TDZ_OVPN_PORTAL_PORT$TDZ_OVPN_PUBLIC_PATH/
Online documentation: https://$TDZ_OVPN_HOST:$TDZ_OVPN_PORTAL_PORT$TDZ_OVPN_PUBLIC_PATH/docs
Download page: https://$TDZ_OVPN_HOST:$TDZ_OVPN_PORTAL_PORT$TDZ_OVPN_PUBLIC_PATH/download
Contact for account/support: @$TDZ_OVPN_SUPPORT_USERNAME (https://t.me/$TDZ_OVPN_SUPPORT_USERNAME)

Official OpenVPN compatible
- UDP: $TDZ_OVPN_UDP_PORT
- TCP: $TDZ_OVPN_TCP_PORT
- HTTP CONNECT: $TDZ_OVPN_HTTP_PORT

Injector / external adapter modes
- HTTP Payload + WS: $TDZ_OVPN_HTTP_PORT
- WSS: $TDZ_OVPN_WSS_PORT (SNI: $TDZ_OVPN_HOST)
- SSL: $TDZ_OVPN_SSL_PORT (SNI: $TDZ_OVPN_HOST)

HTTP payload
CONNECT [host_port] HTTP/1.1[crlf]Host: $TDZ_OVPN_HOST[crlf]Connection: keep-alive[crlf][crlf]

WebSocket payload
GET / HTTP/1.1[crlf]Host: $TDZ_OVPN_HOST[crlf]Upgrade: websocket[crlf]Connection: Upgrade[crlf][crlf]

Import a profile, then enter the same SSH/OVPN account username and password.
Expiry, lock, connection limit, first-use activation, and shared bandwidth quota apply.
HTTPS is recommended for downloading profiles because public HTTP is not encrypted.
Adapter profiles keep the public carrier endpoint outside the tunnel so the outer
WS, WSS, or SSL connection cannot route back into itself.
EOF
    chmod 644 "$TDZ_OVPN_PROFILES/connection-guide.txt" "$TDZ_OVPN_PROFILES/tdz-openvpn-ca.crt"
    (
        cd "$TDZ_OVPN_PROFILES"
        zip -q -9 openvpn-profiles.zip ./*.ovpn ./connection-guide.txt ./tdz-openvpn-ca.crt
    )
    chmod 644 "$TDZ_OVPN_PROFILES/openvpn-profiles.zip"
    tdz_openvpn_generate_portal_html
}

tdz_openvpn_generate_profiles() {
    local target="$TDZ_OVPN_PROFILES" parent staging retired=""
    parent=${target%/*}
    mkdir -p "$parent" || return 1
    staging=$(mktemp -d "$parent/.ovpn-configs.new.XXXXXX") || return 1

    TDZ_OVPN_PROFILES="$staging"
    if ! tdz_openvpn_generate_profiles_into; then
        TDZ_OVPN_PROFILES="$target"
        rm -rf "$staging"
        return 1
    fi
    TDZ_OVPN_PROFILES="$target"

    if [[ -e "$target" ]]; then
        retired=$(mktemp -d "$parent/.ovpn-configs.old.XXXXXX") || {
            rm -rf "$staging"
            return 1
        }
        rmdir "$retired" || { rm -rf "$staging" "$retired"; return 1; }
        mv "$target" "$retired" || {
            rm -rf "$staging"
            return 1
        }
    fi
    if ! mv "$staging" "$target"; then
        [[ -n "$retired" && -d "$retired" ]] && mv "$retired" "$target" 2>/dev/null || true
        rm -rf "$staging"
        return 1
    fi
    [[ -n "$retired" && -d "$retired" ]] && rm -rf "$retired"
    return 0
}

tdz_openvpn_portal_write_header() {
    local active=$1 overview_class="" docs_class="" download_class=""
    local overview_current="" docs_current="" download_current=""
    case "$active" in
        overview) overview_class="active"; overview_current='aria-current="page"' ;;
        docs) docs_class="active"; docs_current='aria-current="page"' ;;
        download) download_class="active"; download_current='aria-current="page"' ;;
    esac
    cat <<EOF
<header class="site-header">
  <div class="shell nav-shell">
    <a class="brand" href="$TDZ_OVPN_PUBLIC_PATH/" aria-label="TDZ OpenVPN Portal home">
      <span class="site-logo site-logo-header" aria-hidden="true"><img src="$TDZ_OVPN_LOGO_URL" alt=""></span>
      <span class="brand-copy"><strong>TDZ</strong><small>OVPN PORTAL</small></span>
    </a>
    <nav class="nav-links" aria-label="Portal navigation">
      <a class="nav-link $overview_class" $overview_current href="$TDZ_OVPN_PUBLIC_PATH/">Overview</a>
      <a class="nav-link $docs_class" $docs_current href="$TDZ_OVPN_PUBLIC_PATH/docs">Setup guide</a>
      <a class="nav-link $download_class" $download_current href="$TDZ_OVPN_PUBLIC_PATH/download">Downloads</a>
    </nav>
    <div class="nav-tools">
      <div class="theme-switch" role="group" aria-label="Color theme">
        <button class="theme-option" type="button" data-theme-option="light" aria-label="Use light theme" aria-pressed="false"><span aria-hidden="true">☀</span><b>Light</b></button>
        <button class="theme-option" type="button" data-theme-option="system" aria-label="Use system theme" aria-pressed="true"><span aria-hidden="true">◐</span><b>Auto</b></button>
        <button class="theme-option" type="button" data-theme-option="dark" aria-label="Use dark theme" aria-pressed="false"><span aria-hidden="true">☾</span><b>Dark</b></button>
      </div>
    </div>
  </div>
</header>
EOF
}

tdz_openvpn_portal_write_support() {
    cat <<EOF
<section class="support-banner" aria-labelledby="account-support-title">
  <div class="support-orb" aria-hidden="true"><svg viewBox="0 0 496 512" focusable="false"><path fill="currentColor" d="M248 8C111 8 0 119 0 256s111 248 248 248 248-111 248-248S385 8 248 8Zm114 170-40 189c-3 13-11 17-22 10l-62-45-29 29c-3 3-6 6-12 6l4-62 113-102c5-4-1-7-8-2L167 289l-60-19c-13-4-13-13 3-19l235-91c11-4 20 3 17 18Z"/></svg></div>
  <div class="support-copy">
    <div class="kicker">Get Account or Support</div>
    <h2 id="account-support-title">No SSH/OVPN account yet? Start here.</h2>
    <p>An active SSH/OVPN account is required to sign in after importing a profile. Message the contact to request an account or get connection help.</p>
  </div>
  <a class="button telegram" href="https://t.me/$TDZ_OVPN_SUPPORT_USERNAME" target="_blank" rel="noopener noreferrer"><span>Message @$TDZ_OVPN_SUPPORT_USERNAME</span><i aria-hidden="true">↗</i></a>
</section>
EOF
}

tdz_openvpn_portal_write_footer() {
    cat <<EOF
<footer class="footer">
  <div class="shell footer-grid">
    <section class="footer-profile">
      <a class="footer-brand" href="$TDZ_OVPN_PUBLIC_PATH/"><span class="site-logo site-logo-footer" aria-hidden="true"><img src="$TDZ_OVPN_LOGO_URL" alt=""></span><span><strong>TDZ</strong> OVPN PORTAL</span></a>
      <p>Six OpenVPN transport paths, one SSH/OVPN account, and a focused setup experience for every device.</p>
    </section>
    <section class="footer-column">
      <h2>Portal</h2>
      <a href="$TDZ_OVPN_PUBLIC_PATH/">Overview</a>
      <a href="$TDZ_OVPN_PUBLIC_PATH/docs">Setup guide</a>
      <a href="$TDZ_OVPN_PUBLIC_PATH/download">Downloads</a>
    </section>
    <section class="footer-column">
      <h2>Need an account?</h2>
      <p class="developer-line footer-contact-line"><span>Contact:</span><a class="developer-link" href="https://t.me/$TDZ_OVPN_SUPPORT_USERNAME" target="_blank" rel="noopener noreferrer">@$TDZ_OVPN_SUPPORT_USERNAME</a></p>
      <p class="footer-note">Account requests and connection support.</p>
    </section>
    <section class="footer-column footer-developer">
      <h2>Project</h2>
      <p class="developer-line"><span>Developed By:</span><a class="developer-link" href="https://tuhinbro.com/" target="_blank" rel="noopener noreferrer">Yeasinul Hoque Tuhin</a></p>
      <p class="developer-line"><span>Telegram:</span><a class="developer-link" href="https://t.me/TuhinBroh" target="_blank" rel="noopener noreferrer">@TuhinBroh</a></p>
    </section>
  </div>
  <div class="shell footer-bottom"><a class="footer-repo" href="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT" target="_blank" rel="noopener noreferrer">TDZ SSH TUNNEL <span>•</span> OpenVPN Suite</a></div>
</footer>
EOF
}

tdz_openvpn_portal_write_assets() {
    cat > "$TDZ_OVPN_PROFILES/portal.css" <<'EOF'
:root{
  color-scheme:light;
  --bg:#edf7f2;--bg-elevated:#f5faf7;--panel:rgba(255,255,255,.8);--panel-solid:#fff;
  --panel-soft:#f0f7f3;--header:rgba(247,252,249,.78);--text:#101713;--text-soft:#3d4c45;
  --muted:#6f7e76;--line:rgba(4,80,61,.12);--line-strong:rgba(4,80,61,.2);
  --accent:#047857;--accent-hover:#065f46;--accent-soft:rgba(4,120,87,.11);--accent-glow:rgba(4,120,87,.2);
  --code:#0d1712;--code-text:#e8f5ee;--shadow:0 24px 70px rgba(4,70,52,.12);
  --shadow-soft:0 10px 30px rgba(4,70,52,.08);--grid:rgba(4,120,87,.065);
  --button-text:#fff;--radius:18px;--radius-lg:28px
}
:root[data-theme="dark"]{
  color-scheme:dark;
  --bg:#07110d;--bg-elevated:#0a1712;--panel:rgba(14,29,23,.8);--panel-solid:#101e18;
  --panel-soft:#13251d;--header:rgba(9,24,18,.78);--text:#f2f8f5;--text-soft:#c2d2ca;
  --muted:#84978d;--line:rgba(209,250,229,.11);--line-strong:rgba(209,250,229,.19);
  --accent:#34d399;--accent-hover:#6ee7b7;--accent-soft:rgba(52,211,153,.12);--accent-glow:rgba(52,211,153,.24);
  --code:#050d09;--code-text:#e4f3eb;--shadow:0 28px 80px rgba(0,0,0,.42);
  --shadow-soft:0 12px 34px rgba(0,0,0,.27);--grid:rgba(110,231,183,.05);--button-text:#052e21
}
@media(prefers-color-scheme:dark){
  :root:not([data-theme]){color-scheme:dark;--bg:#07110d;--bg-elevated:#0a1712;--panel:rgba(14,29,23,.8);--panel-solid:#101e18;--panel-soft:#13251d;--header:rgba(9,24,18,.78);--text:#f2f8f5;--text-soft:#c2d2ca;--muted:#84978d;--line:rgba(209,250,229,.11);--line-strong:rgba(209,250,229,.19);--accent:#34d399;--accent-hover:#6ee7b7;--accent-soft:rgba(52,211,153,.12);--accent-glow:rgba(52,211,153,.24);--code:#050d09;--code-text:#e4f3eb;--shadow:0 28px 80px rgba(0,0,0,.42);--shadow-soft:0 12px 34px rgba(0,0,0,.27);--grid:rgba(110,231,183,.05);--button-text:#052e21}
}
*{box-sizing:border-box}
html{scroll-behavior:smooth;background:var(--bg)}
body{
  margin:0;min-height:100vh;color:var(--text);
  background:radial-gradient(circle at 82% -8%,var(--accent-glow),transparent 30rem),radial-gradient(circle at -8% 35%,var(--accent-soft),transparent 32rem),linear-gradient(var(--grid) 1px,transparent 1px),linear-gradient(90deg,var(--grid) 1px,transparent 1px),var(--bg);
  background-size:auto,auto,48px 48px,48px 48px,auto;
  font:16px/1.68 Inter,ui-sans-serif,-apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif;
  -webkit-font-smoothing:antialiased;text-rendering:optimizeLegibility
}
a{color:inherit}button{font:inherit}svg{display:block}
code,.mono,.filename,.payload{font-family:"SFMono-Regular",Consolas,"Liberation Mono",monospace}
.shell{width:min(1180px,calc(100% - 40px));margin-inline:auto}
.site-header{position:sticky;z-index:50;top:0;padding:14px 0 0;pointer-events:none}
.nav-shell{
  min-height:72px;display:grid;grid-template-columns:auto minmax(0,1fr) auto;align-items:center;gap:22px;
  border:1px solid var(--line-strong);border-radius:22px;background:var(--header);padding:10px 12px 10px 16px;
  box-shadow:0 14px 40px rgba(16,24,38,.12);-webkit-backdrop-filter:blur(26px) saturate(155%);backdrop-filter:blur(26px) saturate(155%);pointer-events:auto
}
.brand,.footer-brand{display:inline-flex;align-items:center;gap:10px;text-decoration:none;white-space:nowrap}
.site-logo{display:block;flex:0 0 auto;overflow:hidden;border:1px solid rgba(19,28,42,.14);border-radius:13px;background:#fff;padding:2px;box-shadow:0 7px 20px rgba(16,24,38,.12)}
.site-logo img{display:block;width:100%;height:100%;border-radius:10px;object-fit:contain}
.site-logo-header{width:42px;height:42px}.site-logo-footer{width:40px;height:40px;border-radius:12px}
.brand-copy{display:grid;line-height:1.05}.brand-copy strong{font-size:1.02rem;letter-spacing:.2em}.brand-copy small{margin-top:5px;color:var(--muted);font-size:.63rem;font-weight:800;letter-spacing:.13em}
.nav-links{display:flex;justify-content:center;align-items:center;gap:4px}
.nav-link{border:1px solid transparent;border-radius:11px;color:var(--muted);padding:8px 11px;font-size:.87rem;font-weight:680;text-decoration:none;transition:.18s ease}
.nav-link:hover,.nav-link.active{border-color:var(--line);background:var(--panel);color:var(--text)}
.nav-tools{display:flex;align-items:center;justify-content:flex-end}
.theme-switch{display:flex;align-items:center;border:1px solid var(--line);border-radius:13px;background:var(--panel-soft);padding:3px}
.theme-option{display:inline-flex;align-items:center;gap:4px;min-height:31px;border:0;border-radius:9px;background:transparent;color:var(--muted);padding:4px 8px;font-size:.72rem;cursor:pointer;transition:.18s ease}
.theme-option span{font-size:.83rem}.theme-option b{font-weight:700}
.theme-option:hover{color:var(--text)}.theme-option[aria-pressed="true"]{background:var(--panel-solid);color:var(--text);box-shadow:0 4px 12px rgba(15,24,38,.12)}
main{padding:36px 0 88px}
.hero{position:relative;display:grid;grid-template-columns:1fr;align-items:stretch;min-height:500px;overflow:hidden;border:1px solid var(--line-strong);border-radius:var(--radius-lg);background:linear-gradient(135deg,var(--panel-solid),var(--panel));box-shadow:var(--shadow)}
.hero:before{content:"";position:absolute;inset:0;background:radial-gradient(circle at 80% 16%,var(--accent-glow),transparent 30%),linear-gradient(120deg,var(--accent-soft),transparent 36%);pointer-events:none}
.hero-copy{position:relative;z-index:2;display:flex;flex-direction:column;justify-content:center;padding:clamp(36px,6vw,74px)}
.eyebrow,.kicker,.label{color:var(--accent);font-size:.72rem;font-weight:850;letter-spacing:.15em;text-transform:uppercase}
.eyebrow{display:flex;align-items:center;gap:9px}.eyebrow-dot{width:7px;height:7px;border-radius:50%;background:var(--accent);box-shadow:0 0 0 5px var(--accent-soft)}
.hero h1{max-width:720px;margin:.75rem 0 1.15rem;font-size:clamp(3rem,6.4vw,5.85rem);font-weight:780;letter-spacing:-.064em;line-height:.94}
.hero h1 span{color:var(--accent)}.lead{max-width:670px;margin:0;color:var(--text-soft);font-size:clamp(1rem,1.35vw,1.16rem)}
.actions{display:flex;flex-wrap:wrap;gap:10px;margin-top:27px}
.button{display:inline-flex;align-items:center;justify-content:center;gap:8px;min-height:46px;border:1px solid var(--line-strong);border-radius:12px;background:var(--panel-solid);color:var(--text);padding:9px 16px;font-size:.88rem;font-weight:780;text-decoration:none;box-shadow:var(--shadow-soft);transition:.18s ease}
.button:hover{border-color:var(--accent);color:var(--accent);transform:translateY(-1px)}
.button.primary{border-color:var(--accent);background:var(--accent);color:var(--button-text);box-shadow:0 12px 30px var(--accent-glow)}
.button.primary:hover{background:var(--accent-hover);color:var(--button-text)}
.button.telegram{border-color:var(--accent);background:var(--accent);color:var(--button-text);box-shadow:0 12px 28px var(--accent-glow);white-space:nowrap}.button.telegram:hover{background:var(--accent-hover);color:var(--button-text)}
.hero-badges{display:flex;flex-wrap:wrap;gap:8px;margin-top:28px}.hero-badge{border:1px solid var(--line);border-radius:999px;background:var(--panel);color:var(--muted);padding:6px 10px;font-size:.76rem;font-weight:650}
.quick-grid{display:grid;grid-template-columns:repeat(4,minmax(0,1fr));overflow:hidden;border:1px solid var(--line-strong);border-radius:var(--radius);background:var(--panel);box-shadow:var(--shadow-soft)}
.quick-step{position:relative;padding:24px;border-right:1px solid var(--line)}.quick-step:last-child{border-right:0}.quick-step b{display:block;color:var(--accent);font-size:.7rem;letter-spacing:.13em}.quick-step strong{display:block;margin:7px 0 4px;font-size:1rem}.quick-step p{margin:0;color:var(--muted);font-size:.86rem}.quick-step:not(:last-child):after{content:"›";position:absolute;right:-8px;top:50%;z-index:2;transform:translateY(-50%);background:var(--panel-solid);color:var(--accent);padding:0 3px;font-size:1.2rem}
.section{margin-top:68px}.section-head{display:flex;align-items:flex-end;justify-content:space-between;gap:40px;margin-bottom:22px}.section-head h2,.content-section h2,.support-copy h2,.panel h2{margin:.35rem 0 0;font-size:clamp(1.55rem,3vw,2.3rem);letter-spacing:-.035em;line-height:1.14}.section-head p{max-width:570px;margin:0;color:var(--muted)}
.grid{display:grid;grid-template-columns:repeat(3,minmax(0,1fr));gap:14px}.grid.two{grid-template-columns:repeat(2,minmax(0,1fr))}
.card,.panel{border:1px solid var(--line);border-radius:var(--radius);background:var(--panel);box-shadow:var(--shadow-soft)}
.card{position:relative;padding:23px;transition:.18s ease}.card:hover{border-color:var(--line-strong);background:var(--panel-solid);transform:translateY(-2px)}.card h3{margin:9px 0 5px;font-size:1.07rem;letter-spacing:-.015em}.card p{margin:.4rem 0;color:var(--muted)}
.card-index{display:grid;place-items:center;width:35px;height:35px;border:1px solid var(--line);border-radius:10px;background:var(--panel-soft);color:var(--accent);font:800 .72rem/1 "SFMono-Regular",Consolas,monospace}
.status{display:inline-flex;align-items:center;gap:6px;color:var(--accent);font-size:.69rem;font-weight:850;letter-spacing:.1em;text-transform:uppercase}.status:before{content:"";width:6px;height:6px;border-radius:50%;background:currentColor}
.port{float:right;border:1px solid var(--line);border-radius:999px;background:var(--panel-soft);color:var(--text-soft);padding:2px 8px;font:700 .73rem/1.65 "SFMono-Regular",Consolas,monospace}
.policy-strip{display:grid;grid-template-columns:repeat(4,minmax(0,1fr));overflow:hidden;border:1px solid var(--line);border-radius:var(--radius);background:var(--panel)}.policy-item{padding:21px;border-right:1px solid var(--line)}.policy-item:last-child{border:0}.policy-item span{color:var(--accent);font-size:.7rem;font-weight:850}.policy-item strong{display:block;margin-top:5px}.policy-item p{margin:4px 0 0;color:var(--muted);font-size:.83rem}
.support-banner{position:relative;display:grid;grid-template-columns:auto minmax(0,1fr) auto;align-items:center;gap:24px;overflow:hidden;border:1px solid var(--line-strong);border-radius:var(--radius-lg);background:linear-gradient(120deg,var(--accent-soft),var(--panel) 55%);margin-top:68px;padding:30px 32px;box-shadow:var(--shadow)}
.support-banner:after{content:"";position:absolute;right:15%;bottom:-90px;width:220px;height:220px;border-radius:50%;background:var(--accent-soft);filter:blur(10px);pointer-events:none}.support-orb{position:relative;z-index:1;display:grid;place-items:center;width:58px;height:58px;border:1px solid var(--line-strong);border-radius:18px;background:var(--panel-solid);color:var(--accent);box-shadow:0 12px 28px var(--accent-glow)}.support-orb svg{width:29px;height:29px}.support-copy,.support-banner .button{position:relative;z-index:1}.support-copy h2{font-size:clamp(1.4rem,2.6vw,2rem)}.support-copy p{max-width:680px;margin:.55rem 0 0;color:var(--muted)}
.project-spotlight{display:grid;grid-template-columns:minmax(0,1fr) auto;align-items:center;gap:28px;border:1px solid var(--line);border-radius:var(--radius);background:var(--panel);padding:28px 30px}.project-spotlight h2{margin:.3rem 0 .55rem;font-size:clamp(1.35rem,2.6vw,1.9rem);letter-spacing:-.025em}.project-spotlight p{margin:0;color:var(--muted)}
.page-intro{position:relative;overflow:hidden;border:1px solid var(--line-strong);border-radius:var(--radius-lg);background:linear-gradient(135deg,var(--panel-solid),var(--panel));padding:clamp(30px,5vw,58px);box-shadow:var(--shadow)}
.page-intro:after{content:"";position:absolute;right:-8%;top:-45%;width:380px;height:380px;border-radius:50%;background:var(--accent-glow);filter:blur(28px);opacity:.4;pointer-events:none}.page-intro>*{position:relative;z-index:1}.page-intro h1{max-width:850px;margin:.55rem 0 .85rem;font-size:clamp(2.55rem,6vw,5.2rem);font-weight:780;letter-spacing:-.06em;line-height:.96}.page-intro h1 span{color:var(--accent)}.page-intro p{max-width:790px;margin:0;color:var(--text-soft);font-size:1.06rem}
.inline-account{display:inline-flex;align-items:center;gap:7px;margin-top:20px;color:var(--accent);font-weight:780;text-decoration:none}.inline-account:hover{text-decoration:underline;text-underline-offset:4px}
.docs-layout{display:grid;grid-template-columns:minmax(0,1fr) 255px;gap:38px;align-items:start}.article{min-width:0}.toc{position:sticky;top:108px;border:1px solid var(--line);border-radius:15px;background:var(--panel);padding:16px}.toc-title{margin-bottom:8px;color:var(--text);font-size:.75rem;font-weight:850;letter-spacing:.1em;text-transform:uppercase}.toc a{display:block;border-radius:8px;color:var(--muted);padding:7px 8px;font-size:.84rem;text-decoration:none}.toc a:hover{background:var(--accent-soft);color:var(--accent)}
.content-section{margin-top:54px;scroll-margin-top:110px}.content-section>p{color:var(--text-soft)}
.table-wrap{overflow:auto;border:1px solid var(--line);border-radius:var(--radius);background:var(--panel);box-shadow:var(--shadow-soft)}table{width:100%;min-width:760px;border-collapse:collapse}th,td{border-bottom:1px solid var(--line);padding:14px 16px;text-align:left;vertical-align:top}tr:last-child td{border-bottom:0}th{background:var(--panel-soft);color:var(--muted);font-size:.7rem;font-weight:850;letter-spacing:.08em;text-transform:uppercase}td{color:var(--text-soft)}td:first-child{color:var(--text);font-weight:680}td code{color:var(--accent)}
.payload-card{display:flex;flex-direction:column}.payload-head{display:flex;align-items:center;justify-content:space-between;gap:12px}.copy-button{border:1px solid var(--line);border-radius:9px;background:var(--panel-soft);color:var(--text);padding:6px 10px;font-size:.75rem;font-weight:800;cursor:pointer}.copy-button:hover,.copy-button.is-copied{border-color:var(--accent);background:var(--accent);color:#fff}.payload{min-height:140px;white-space:pre-wrap;overflow-wrap:anywhere;border-radius:12px;background:var(--code);color:var(--code-text);margin:12px 0 0;padding:17px;font-size:.81rem;line-height:1.65;user-select:text}
.note,.muted{color:var(--muted)}.note{font-size:.89rem}.callout{display:flex;gap:14px;border:1px solid var(--line);border-radius:var(--radius);background:var(--panel);padding:19px}.callout-mark{flex:0 0 auto;display:grid;place-items:center;width:32px;height:32px;border-radius:10px;background:var(--accent-soft);color:var(--accent);font-size:.7rem;font-weight:900}.callout strong{display:block}.callout p{margin:3px 0 0;color:var(--muted)}
.download-card{display:flex;flex-direction:column;min-height:280px}.download-card .filename{margin-top:auto;color:var(--text-soft);font-size:.76rem;overflow-wrap:anywhere}.download-card .button{margin-top:11px}.bundle{display:grid;grid-template-columns:minmax(0,1.2fr) minmax(280px,.8fr);gap:14px}.panel{display:flex;flex-direction:column;align-items:flex-start;min-height:205px;padding:26px}.panel p{color:var(--muted)}.panel .button{margin-top:auto}
.footer{border-top:1px solid var(--line);background:var(--bg-elevated);padding:52px 0 24px}.footer-grid{display:grid;grid-template-columns:1.3fr .6fr .9fr 1fr;gap:38px}.footer-brand{font-weight:780}.footer-brand strong{letter-spacing:.14em}.footer-profile p,.footer-column p{margin:.75rem 0 0;color:var(--muted);font-size:.88rem}.footer-column h2{margin:0 0 12px;color:var(--text);font-size:.72rem;font-weight:850;letter-spacing:.12em;text-transform:uppercase}.footer-column>a{display:block;width:max-content;max-width:100%;margin:6px 0;color:var(--text-soft);font-size:.88rem;text-decoration:none}.footer-column>a:hover{color:var(--accent)}.footer-note{max-width:220px}.developer-line{display:flex;align-items:baseline;flex-wrap:wrap;gap:0 5px;margin:4px 0!important}.developer-line span{color:var(--text);font-weight:720}.developer-line .developer-link{display:inline;margin:0;color:var(--accent);font-weight:680;text-decoration:underline;text-decoration-color:transparent;text-underline-offset:3px}.developer-line .developer-link:hover{text-decoration-color:currentColor}.footer-bottom{display:flex;align-items:center;border-top:1px solid var(--line);margin-top:38px;padding-top:20px;color:var(--muted);font-size:.79rem}.footer-repo{display:inline-flex;gap:6px;color:var(--text-soft);font-weight:700;text-decoration:none}.footer-repo span{color:var(--accent)}.footer-repo:hover{color:var(--accent)}
.theme-option:focus-visible,.nav-link:focus-visible,.button:focus-visible,.copy-button:focus-visible,.toc a:focus-visible,a:focus-visible{outline:3px solid var(--accent-soft);outline-offset:3px}
@media(max-width:1020px){.nav-shell{grid-template-columns:auto 1fr}.nav-links{grid-column:1/-1;grid-row:2;justify-content:flex-start}.nav-tools{justify-self:end}.quick-grid,.policy-strip{grid-template-columns:repeat(2,minmax(0,1fr))}.quick-step:nth-child(2),.policy-item:nth-child(2){border-right:0}.quick-step:nth-child(-n+2),.policy-item:nth-child(-n+2){border-bottom:1px solid var(--line)}.quick-step:nth-child(2):after{display:none}.docs-layout{grid-template-columns:1fr}.toc{position:static;display:flex;gap:4px;overflow:auto;order:-1}.toc-title{display:none}.toc a{flex:0 0 auto}.footer-grid{grid-template-columns:repeat(2,minmax(0,1fr))}}
@media(max-width:760px){.shell{width:min(100% - 24px,1180px)}.site-header{padding-top:7px}.nav-shell{gap:10px;padding:9px 10px 8px 12px;border-radius:18px}.site-logo-header{width:40px;height:40px}.brand-copy small{display:none}.theme-option b{display:none}.theme-option{width:31px;justify-content:center;padding:4px}.nav-links{justify-content:space-between;gap:2px}.nav-link{flex:1;padding:7px 5px;text-align:center;font-size:.78rem}main{padding:22px 0 62px}.hero{min-height:0}.hero-copy{padding:36px 23px}.hero h1{font-size:clamp(2.85rem,14vw,4.3rem)}.section{margin-top:52px}.section-head{display:block}.section-head p{margin-top:10px}.grid,.grid.two,.bundle{grid-template-columns:1fr}.support-banner{grid-template-columns:1fr;margin-top:52px;padding:25px 22px}.support-orb{width:50px;height:50px}.support-orb svg{width:25px;height:25px}.support-banner .button{width:100%}.project-spotlight{grid-template-columns:1fr;padding:24px 22px}.page-intro{padding:34px 23px}.card,.panel{padding:20px}.footer-grid{grid-template-columns:1fr;gap:28px}.footer-bottom{display:block}.payload-head{align-items:flex-start}}
@media(max-width:480px){.brand-copy strong{font-size:.9rem}.hero-badges{display:grid;grid-template-columns:1fr 1fr}.quick-grid,.policy-strip{grid-template-columns:1fr}.quick-step,.policy-item{border-right:0;border-bottom:1px solid var(--line)}.quick-step:nth-child(2){border-bottom:1px solid var(--line)}.quick-step:not(:last-child):after{content:"⌄";right:50%;top:auto;bottom:-12px;transform:translateX(50%)}.policy-item:nth-child(2){border-bottom:1px solid var(--line)}}
@media(prefers-reduced-motion:reduce){html{scroll-behavior:auto}*{animation:none!important;transition:none!important}}
EOF

    cat > "$TDZ_OVPN_PROFILES/portal.js" <<'EOF'
(function () {
    "use strict";

    var storageKey = "tdz-ovpn-theme";
    var modes = ["light", "system", "dark"];
    var media = window.matchMedia ? window.matchMedia("(prefers-color-scheme: dark)") : null;

    function readTheme() {
        try {
            var stored = window.localStorage.getItem(storageKey);
            return modes.indexOf(stored) === -1 ? "system" : stored;
        } catch (error) {
            return "system";
        }
    }

    var activeTheme = readTheme();

    function resolvedTheme(mode) {
        if (mode === "system") return media && media.matches ? "dark" : "light";
        return mode;
    }

    function applyTheme(mode) {
        document.documentElement.setAttribute("data-theme", resolvedTheme(mode));
        document.documentElement.setAttribute("data-theme-mode", mode);
    }

    function saveTheme(mode) {
        try {
            window.localStorage.setItem(storageKey, mode);
        } catch (error) {
            return;
        }
    }

    function updateThemeControls() {
        document.querySelectorAll("[data-theme-option]").forEach(function (button) {
            button.setAttribute("aria-pressed", button.getAttribute("data-theme-option") === activeTheme ? "true" : "false");
        });
    }

    applyTheme(activeTheme);

    function fallbackCopy(text) {
        var field = document.createElement("textarea");
        field.value = text;
        field.setAttribute("readonly", "");
        field.style.position = "fixed";
        field.style.opacity = "0";
        document.body.appendChild(field);
        field.select();
        var copied = document.execCommand("copy");
        field.remove();
        if (!copied) throw new Error("Copy command was rejected");
    }

    function copyText(text) {
        if (window.isSecureContext && navigator.clipboard && navigator.clipboard.writeText) {
            return navigator.clipboard.writeText(text);
        }
        return new Promise(function (resolve, reject) {
            try {
                fallbackCopy(text);
                resolve();
            } catch (error) {
                reject(error);
            }
        });
    }

    function showCopyResult(button, message, success) {
        window.clearTimeout(button._tdzResetTimer);
        button.textContent = message;
        button.classList.toggle("is-copied", success);
        button._tdzResetTimer = window.setTimeout(function () {
            button.textContent = "Copy";
            button.classList.remove("is-copied");
        }, 1600);
    }

    function ready() {
        updateThemeControls();
        document.addEventListener("click", function (event) {
            var themeButton = event.target.closest("[data-theme-option]");
            if (themeButton) {
                activeTheme = themeButton.getAttribute("data-theme-option");
                if (modes.indexOf(activeTheme) === -1) activeTheme = "system";
                applyTheme(activeTheme);
                saveTheme(activeTheme);
                updateThemeControls();
                return;
            }

            var copyButton = event.target.closest("[data-copy-target]");
            if (!copyButton) return;
            var target = document.getElementById(copyButton.getAttribute("data-copy-target"));
            if (!target) {
                showCopyResult(copyButton, "Unavailable", false);
                return;
            }
            copyText(target.textContent.trim()).then(function () {
                showCopyResult(copyButton, "Copied", true);
            }).catch(function () {
                showCopyResult(copyButton, "Copy failed", false);
            });
        });
    }

    function systemThemeChanged() {
        if (activeTheme === "system") applyTheme(activeTheme);
    }

    if (media) {
        if (media.addEventListener) media.addEventListener("change", systemThemeChanged);
        else if (media.addListener) media.addListener(systemThemeChanged);
    }

    if (document.readyState === "loading") document.addEventListener("DOMContentLoaded", ready);
    else ready();
}());
EOF
}

tdz_openvpn_portal_write_index() {
    {
        cat <<EOF
<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="theme-color" content="#0d121a"><meta name="description" content="TDZ SSH TUNNEL OpenVPN transport portal"><title>TDZ • OVPN PORTAL</title><link rel="icon" type="image/png" href="$TDZ_OVPN_LOGO_URL"><script src="$TDZ_OVPN_PUBLIC_PATH/assets/portal.js"></script><link rel="stylesheet" href="$TDZ_OVPN_PUBLIC_PATH/assets/portal.css"></head><body>
EOF
        tdz_openvpn_portal_write_header overview
        cat <<EOF
<main class="shell">
  <section class="hero">
    <div class="hero-copy">
      <div class="eyebrow"><span class="eyebrow-dot" aria-hidden="true"></span>TDZ SSH TUNNEL • OpenVPN suite</div>
      <h1>Fast when it can be.<br><span>Flexible when it must.</span></h1>
      <p class="lead">One clean portal for direct OpenVPN, HTTP, WebSocket and TLS adapter profiles—with the same SSH/OVPN account across every route.</p>
      <div class="actions"><a class="button primary" href="$TDZ_OVPN_PUBLIC_PATH/download">Download profiles <span aria-hidden="true">↓</span></a><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/docs">Open setup guide <span aria-hidden="true">→</span></a></div>
      <div class="hero-badges"><span class="hero-badge">6 connection modes</span><span class="hero-badge">No stored password</span><span class="hero-badge">Shared account policy</span></div>
    </div>
  </section>

  <section class="section" aria-labelledby="quick-start-title">
    <div class="section-head"><div><div class="kicker">Quick start</div><h2 id="quick-start-title">From zero to connected in four steps</h2></div><p>New visitors can request an account first. Existing users can jump straight to the right profile.</p></div>
    <div class="quick-grid">
      <article class="quick-step"><b>01</b><strong>Get an account</strong><p>Contact support if you do not already have an active SSH/OVPN account.</p></article>
      <article class="quick-step"><b>02</b><strong>Pick a profile</strong><p>Start with direct UDP, then use TCP or an adapter when needed.</p></article>
      <article class="quick-step"><b>03</b><strong>Import it</strong><p>Open the profile in your compatible OpenVPN or injector client.</p></article>
      <article class="quick-step"><b>04</b><strong>Sign in</strong><p>Enter your SSH/OVPN username and password when the client asks.</p></article>
    </div>
  </section>

  <section class="section" aria-labelledby="routes-title">
    <div class="section-head"><div><div class="kicker">Connection matrix</div><h2 id="routes-title">Six paths. One destination.</h2></div><p>Official profiles work directly in OpenVPN clients. WS, WSS and SSL profiles need a compatible external adapter.</p></div>
    <div class="grid">
      <article class="card"><span class="status">Official client</span><span class="port">UDP $TDZ_OVPN_UDP_PORT</span><h3>Direct UDP</h3><p>Lowest overhead and the best starting point on normal mobile or Wi-Fi networks.</p></article>
      <article class="card"><span class="status">Official client</span><span class="port">TCP $TDZ_OVPN_TCP_PORT</span><h3>Direct TCP</h3><p>A standard TCP route when UDP is blocked, unstable or unavailable.</p></article>
      <article class="card"><span class="status">Official client</span><span class="port">HTTP $TDZ_OVPN_HTTP_PORT</span><h3>HTTP CONNECT</h3><p>Native OpenVPN proxy configuration without a separate payload app.</p></article>
      <article class="card"><span class="status">Injector mode</span><span class="port">WS $TDZ_OVPN_HTTP_PORT</span><h3>HTTP Payload / WS</h3><p>Custom CONNECT or WebSocket transport for supported injector clients.</p></article>
      <article class="card"><span class="status">TLS adapter</span><span class="port">WSS $TDZ_OVPN_WSS_PORT</span><h3>WSS / SNI</h3><p>WebSocket inside TLS using the configured server hostname as SNI.</p></article>
      <article class="card"><span class="status">TLS adapter</span><span class="port">SSL $TDZ_OVPN_SSL_PORT</span><h3>SSL / SNI</h3><p>Raw outer TLS for clients that expose an SSL tunnel adapter.</p></article>
    </div>
  </section>

  <section class="section" aria-labelledby="policy-title">
    <div class="section-head"><div><div class="kicker">One account policy</div><h2 id="policy-title">The route changes. Your rules do not.</h2></div><p>OpenVPN uses the same SSH/OVPN account lifecycle instead of creating a second identity system.</p></div>
    <div class="policy-strip"><article class="policy-item"><span>01</span><strong>Expiry</strong><p>Expired accounts are rejected.</p></article><article class="policy-item"><span>02</span><strong>Connection limit</strong><p>Concurrent sessions share the limit.</p></article><article class="policy-item"><span>03</span><strong>Traffic quota</strong><p>Usage returns to the shared quota counter.</p></article><article class="policy-item"><span>04</span><strong>Lock state</strong><p>Locked accounts cannot authenticate.</p></article></div>
  </section>
EOF
        tdz_openvpn_portal_write_support
        cat <<EOF
  <section class="section project-spotlight"><div><div class="kicker">Open source project</div><h2>Part of TDZ SSH TUNNEL.</h2><p>The portal, profiles and OpenVPN services are generated and managed by the same server-side project.</p></div><a class="button" href="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT" target="_blank" rel="noopener noreferrer">View GitHub repository ↗</a></section>
</main>
EOF
        tdz_openvpn_portal_write_footer
        printf '%s\n' '</body></html>'
    } > "$TDZ_OVPN_PROFILES/index.html"
}

tdz_openvpn_portal_write_docs() {
    {
        cat <<EOF
<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="theme-color" content="#0d121a"><meta name="description" content="TDZ OpenVPN setup guide"><title>TDZ • OVPN PORTAL</title><link rel="icon" type="image/png" href="$TDZ_OVPN_LOGO_URL"><script src="$TDZ_OVPN_PUBLIC_PATH/assets/portal.js"></script><link rel="stylesheet" href="$TDZ_OVPN_PUBLIC_PATH/assets/portal.css"></head><body>
EOF
        tdz_openvpn_portal_write_header docs
        cat <<EOF
<main class="shell">
  <header class="page-intro"><div class="eyebrow"><span class="eyebrow-dot" aria-hidden="true"></span>Setup guide</div><h1>Connect with <span>confidence.</span></h1><p>Choose the shortest compatible route first, then add HTTP, WebSocket or outer TLS only when the network requires it.</p><a class="inline-account" href="https://t.me/$TDZ_OVPN_SUPPORT_USERNAME" target="_blank" rel="noopener noreferrer">Need an account? Message @$TDZ_OVPN_SUPPORT_USERNAME ↗</a></header>
  <div class="docs-layout section">
    <article class="article">
      <section class="content-section" id="modes"><div class="kicker">Mode-by-mode setup</div><h2>Choose the client before the port</h2><p>Direct modes import into official OpenVPN-compatible clients. Adapter modes require a client that can create the outer HTTP, WebSocket or TLS connection.</p><div class="table-wrap"><table><thead><tr><th>Mode</th><th>Public endpoint</th><th>Client requirement</th></tr></thead><tbody><tr><td>Direct UDP</td><td><code>$TDZ_OVPN_HOST:$TDZ_OVPN_UDP_PORT</code></td><td>Official OpenVPN-compatible client</td></tr><tr><td>Direct TCP</td><td><code>$TDZ_OVPN_HOST:$TDZ_OVPN_TCP_PORT</code></td><td>Official OpenVPN-compatible client</td></tr><tr><td>HTTP CONNECT</td><td><code>$TDZ_OVPN_HOST:$TDZ_OVPN_HTTP_PORT</code></td><td>Official client with native HTTP proxy support</td></tr><tr><td>HTTP Payload / WS</td><td><code>$TDZ_OVPN_HOST:$TDZ_OVPN_HTTP_PORT</code></td><td>HTTP Payload or WebSocket injector</td></tr><tr><td>WSS / SNI</td><td><code>$TDZ_OVPN_HOST:$TDZ_OVPN_WSS_PORT</code></td><td>TLS WebSocket adapter; SNI <code>$TDZ_OVPN_HOST</code></td></tr><tr><td>SSL / SNI</td><td><code>$TDZ_OVPN_HOST:$TDZ_OVPN_SSL_PORT</code></td><td>Raw TLS adapter; SNI <code>$TDZ_OVPN_HOST</code></td></tr></tbody></table></div></section>

      <section class="content-section" id="certificates"><div class="kicker">Certificate layers</div><h2>Two certificates, two different jobs</h2><div class="grid two"><div class="callout"><span class="callout-mark">VPN</span><div><strong>Private OpenVPN CA</strong><p>Embedded in every generated profile and used to verify the OpenVPN server.</p></div></div><div class="callout"><span class="callout-mark">TLS</span><div><strong>Outer TLS certificate</strong><p>Used only by WSS and SSL adapters and by HTTPS portal delivery.</p></div></div></div></section>

      <section class="content-section" id="payloads"><div class="kicker">Payload reference</div><h2>Use the gateway and backend correctly</h2><div class="grid two"><article class="card payload-card"><div class="payload-head"><span class="label">HTTP CONNECT payload</span><button class="copy-button" type="button" data-copy-target="http-connect-payload">Copy</button></div><div class="payload" id="http-connect-payload">CONNECT $TDZ_OVPN_HOST:$TDZ_OVPN_TCP_PORT HTTP/1.1[crlf]Host: $TDZ_OVPN_HOST[crlf]Connection: keep-alive[crlf][crlf]</div><p class="note">Gateway: $TDZ_OVPN_HOST:$TDZ_OVPN_HTTP_PORT • Backend: $TDZ_OVPN_HOST:$TDZ_OVPN_TCP_PORT</p></article><article class="card payload-card"><div class="payload-head"><span class="label">WebSocket payload</span><button class="copy-button" type="button" data-copy-target="websocket-payload">Copy</button></div><div class="payload" id="websocket-payload">GET / HTTP/1.1[crlf]Host: $TDZ_OVPN_HOST[crlf]Upgrade: websocket[crlf]Connection: Upgrade[crlf][crlf]</div><p class="note">Use port $TDZ_OVPN_HTTP_PORT for WS or $TDZ_OVPN_WSS_PORT for WSS with SNI.</p></article></div></section>

      <section class="content-section" id="verification"><div class="kicker">Verification order</div><h2>Test one layer at a time</h2><div class="grid"><article class="card"><div class="card-index">01</div><h3>Direct TCP / UDP</h3><p>Confirms the OpenVPN core, profile and TDZ authentication.</p></article><article class="card"><div class="card-index">02</div><h3>HTTP CONNECT / WS</h3><p>Confirms the HTTP adapter after direct authentication works.</p></article><article class="card"><div class="card-index">03</div><h3>SSL / WSS</h3><p>Confirms outer TLS, correct SNI and adapter compatibility.</p></article></div></section>

      <section class="content-section" id="policy"><div class="kicker">Account policy</div><h2>Your existing SSH/OVPN login applies</h2><div class="grid two"><div class="callout"><span class="callout-mark">ID</span><div><strong>Username and password</strong><p>Profiles never contain credentials. Enter the active SSH/OVPN account after import.</p></div></div><div class="callout"><span class="callout-mark">BW</span><div><strong>Shared usage accounting</strong><p>OpenVPN traffic is reconciled against the same bandwidth quota.</p></div></div><div class="callout"><span class="callout-mark">EX</span><div><strong>Expiry and first use</strong><p>Pending activation and expiry follow the shared lifecycle.</p></div></div><div class="callout"><span class="callout-mark">CN</span><div><strong>Connection admission</strong><p>Session limits are checked before a connection is admitted.</p></div></div></div></section>

      <section class="content-section" id="troubleshooting"><div class="kicker">Troubleshooting</div><h2>Read the client log in layers</h2><div class="table-wrap"><table><thead><tr><th>Log or symptom</th><th>Meaning</th><th>What to check</th></tr></thead><tbody><tr><td><code>AUTH_FAILED</code></td><td>The transport reached OpenVPN, but account authentication failed.</td><td>Username, password, expiry, lock, quota and connection limit</td></tr><tr><td><code>Connection refused</code></td><td>The selected method is not reachable.</td><td>Import the matching profile again; then contact support if it still fails</td></tr><tr><td><code>TLS Error</code></td><td>The endpoint answered, but TLS or profile validation failed.</td><td>Profile, SNI, CA and device time</td></tr><tr><td><code>HTTP 200</code> or <code>101</code></td><td>The HTTP or WS adapter accepted the request.</td><td>Continue to the later OpenVPN authentication lines</td></tr><tr><td>Higher WS/WSS latency</td><td>TCP, WebSocket and optional TLS add overhead.</td><td>Use Direct UDP when possible</td></tr></tbody></table></div></section>
    </article>
    <aside class="toc" aria-label="On this page"><div class="toc-title">On this page</div><a href="#modes">Mode-by-mode setup</a><a href="#certificates">Certificate layers</a><a href="#payloads">Payload reference</a><a href="#verification">Verification order</a><a href="#policy">Account policy</a><a href="#troubleshooting">Troubleshooting</a></aside>
  </div>
EOF
        tdz_openvpn_portal_write_support
        printf '%s\n' '</main>'
        tdz_openvpn_portal_write_footer
        printf '%s\n' '</body></html>'
    } > "$TDZ_OVPN_PROFILES/docs.html"
}

tdz_openvpn_portal_write_downloads() {
    {
        cat <<EOF
<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="theme-color" content="#0d121a"><meta name="description" content="Download TDZ OpenVPN profiles"><title>TDZ • OVPN PORTAL</title><link rel="icon" type="image/png" href="$TDZ_OVPN_LOGO_URL"><script src="$TDZ_OVPN_PUBLIC_PATH/assets/portal.js"></script><link rel="stylesheet" href="$TDZ_OVPN_PUBLIC_PATH/assets/portal.css"></head><body>
EOF
        tdz_openvpn_portal_write_header download
        cat <<EOF
<main class="shell">
  <header class="page-intro"><div class="eyebrow"><span class="eyebrow-dot" aria-hidden="true"></span>Profile downloads</div><h1>Pick a route.<br><span>Keep moving.</span></h1><p>Choose one transport or download the complete package. Profiles contain certificates and routing details, never your username or password.</p><div class="actions"><a class="button primary" href="$TDZ_OVPN_PUBLIC_PATH/download/openvpn-profiles.zip">Download complete ZIP ↓</a><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/docs">Read setup guide →</a></div><a class="inline-account" href="https://t.me/$TDZ_OVPN_SUPPORT_USERNAME" target="_blank" rel="noopener noreferrer">No account yet? Message @$TDZ_OVPN_SUPPORT_USERNAME ↗</a></header>

  <section class="section"><div class="section-head"><div><div class="kicker">Official clients</div><h2>Direct OpenVPN profiles</h2></div><p>Import these directly into a standard OpenVPN-compatible client without an external payload adapter.</p></div><div class="grid">
    <article class="card download-card"><span class="status">UDP • $TDZ_OVPN_UDP_PORT</span><h3>Direct UDP</h3><p class="note">Recommended first for speed and low latency.</p><p class="filename">tdz-openvpn-udp.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-udp.ovpn">Download UDP ↓</a></article>
    <article class="card download-card"><span class="status">TCP • $TDZ_OVPN_TCP_PORT</span><h3>Direct TCP</h3><p class="note">Standard TCP for networks where UDP cannot pass.</p><p class="filename">tdz-openvpn-tcp.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-tcp.ovpn">Download TCP ↓</a></article>
    <article class="card download-card"><span class="status">HTTP • $TDZ_OVPN_HTTP_PORT</span><h3>HTTP CONNECT</h3><p class="note">Native HTTP proxy profile for compatible official clients.</p><p class="filename">tdz-openvpn-http-connect.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-http-connect.ovpn">Download HTTP ↓</a></article>
  </div></section>

  <section class="section"><div class="section-head"><div><div class="kicker">Adapter clients</div><h2>Payload, WebSocket and TLS</h2></div><p>Use these only with a client that explicitly supports the matching outer adapter mode.</p></div><div class="grid">
    <article class="card download-card"><span class="status">WS • $TDZ_OVPN_HTTP_PORT</span><h3>HTTP Payload / WS</h3><p class="note">For a compatible OpenVPN injector or WebSocket adapter.</p><p class="filename">tdz-openvpn-ws-injector.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-ws-injector.ovpn">Download WS ↓</a></article>
    <article class="card download-card"><span class="status">WSS • $TDZ_OVPN_WSS_PORT</span><h3>WSS / SNI</h3><p class="note">TLS WebSocket adapter; SNI is $TDZ_OVPN_HOST.</p><p class="filename">tdz-openvpn-wss-injector.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-wss-injector.ovpn">Download WSS ↓</a></article>
    <article class="card download-card"><span class="status">SSL • $TDZ_OVPN_SSL_PORT</span><h3>SSL / SNI</h3><p class="note">Raw TLS adapter; SNI is $TDZ_OVPN_HOST.</p><p class="filename">tdz-openvpn-ssl-injector.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-ssl-injector.ovpn">Download SSL ↓</a></article>
  </div></section>

  <section class="section bundle"><article class="panel"><span class="label">Complete package</span><h2>Everything in one archive</h2><p>All six profiles, the private server CA and an offline connection guide.</p><a class="button primary" href="$TDZ_OVPN_PUBLIC_PATH/download/openvpn-profiles.zip">Download complete ZIP ↓</a></article><article class="panel"><span class="label">Server CA</span><h2>Certificate authority</h2><p>Already embedded in each profile and also available separately.</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-ca.crt">Download CA ↓</a></article></section>

  <section class="section"><div class="section-head"><div><div class="kicker">Selection guide</div><h2>Which profile comes first?</h2></div></div><div class="table-wrap"><table><thead><tr><th>Network condition</th><th>Start with</th><th>Why</th></tr></thead><tbody><tr><td>Normal mobile or Wi-Fi</td><td><code>Direct UDP</code></td><td>Lowest overhead and usually best performance</td></tr><tr><td>UDP blocked or unstable</td><td><code>Direct TCP</code></td><td>Uses a standard TCP connection</td></tr><tr><td>HTTP proxy required</td><td><code>HTTP CONNECT</code></td><td>Uses the native OpenVPN proxy directive</td></tr><tr><td>Custom payload client</td><td><code>Payload / WS</code></td><td>Matches the external HTTP or WebSocket adapter</td></tr><tr><td>TLS adapter with SNI</td><td><code>WSS or SSL</code></td><td>Matches the selected outer-TLS client mode</td></tr></tbody></table></div></section>
EOF
        tdz_openvpn_portal_write_support
        printf '%s\n' '</main>'
        tdz_openvpn_portal_write_footer
        printf '%s\n' '</body></html>'
    } > "$TDZ_OVPN_PROFILES/download.html"
}

tdz_openvpn_generate_portal_html() {
    tdz_openvpn_portal_write_assets &&
        tdz_openvpn_portal_write_index &&
        tdz_openvpn_portal_write_docs &&
        tdz_openvpn_portal_write_downloads || return 1
    chmod 644 "$TDZ_OVPN_PROFILES/index.html" "$TDZ_OVPN_PROFILES/docs.html" \
        "$TDZ_OVPN_PROFILES/download.html" "$TDZ_OVPN_PROFILES/portal.css" \
        "$TDZ_OVPN_PROFILES/portal.js"
}

tdz_openvpn_stop_services() {
    local unit
    for unit in tdz-openvpn-accounting tdz-openvpn-portal tdz-openvpn-http \
        tdz-openvpn-wss tdz-openvpn-ssl tdz-openvpn-tcp tdz-openvpn-udp tdz-openvpn-network; do
        systemctl stop "$unit.service" >/dev/null 2>&1 || true
    done
}

tdz_openvpn_managed_runtime_files() {
    printf '%s\n' \
        "$TDZ_OVPN_PAM_SERVICE" "$TDZ_OVPN_SYSCTL" "$TDZ_OVPN_FIREWALL" \
        "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-network.service" \
        "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-tcp.service" \
        "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-udp.service" \
        "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-http.service" \
        "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-wss.service" \
        "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-ssl.service" \
        "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-portal.service" \
        "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-accounting.service"
}

tdz_openvpn_snapshot_runtime() {
    local destination=$1 file basename item
    mkdir -p "$destination/files"
    if [[ -d "$TDZ_OVPN_ROOT" ]]; then
        mkdir -p "$destination/openvpn"
        for item in state.conf pki hooks server-tcp.conf server-udp.conf; do
            [[ -e "$TDZ_OVPN_ROOT/$item" ]] && cp -a "$TDZ_OVPN_ROOT/$item" "$destination/openvpn/"
        done
    fi
    [[ -d "$TDZ_OVPN_PORTAL_BASE" ]] && cp -a "$TDZ_OVPN_PORTAL_BASE" "$destination/portal"
    : > "$destination/manifest"
    while IFS= read -r file; do
        [[ -e "$file" ]] || continue
        basename=${file##*/}
        cp -a "$file" "$destination/files/$basename"
        printf '%s|%s\n' "$file" "$basename" >> "$destination/manifest"
    done < <(tdz_openvpn_managed_runtime_files)
}

tdz_openvpn_restore_snapshot() {
    local source=$1 file basename
    tdz_openvpn_stop_services
    rm -rf "$TDZ_OVPN_ROOT" "$TDZ_OVPN_PORTAL_BASE"
    [[ -d "$source/openvpn" ]] && cp -a "$source/openvpn" "$TDZ_OVPN_ROOT"
    [[ -d "$source/portal" ]] && cp -a "$source/portal" "$TDZ_OVPN_PORTAL_BASE"
    mkdir -p "$TDZ_OVPN_RUN"
    tdz_openvpn_apply_private_permissions 2>/dev/null || return 1
    while IFS= read -r file; do rm -f "$file"; done < <(tdz_openvpn_managed_runtime_files)
    if [[ -f "$source/manifest" ]]; then
        while IFS='|' read -r file basename; do
            [[ -n "$file" && -f "$source/files/$basename" ]] || continue
            cp -a "$source/files/$basename" "$file"
        done < "$source/manifest"
    fi
    systemctl daemon-reload >/dev/null 2>&1 || true
    tdz_openvpn_load_state >/dev/null 2>&1 || return 1
    tdz_openvpn_start_services
}

tdz_openvpn_start_services() {
    local unit attempt all_active
    systemctl daemon-reload
    systemctl enable tdz-openvpn-network.service >/dev/null 2>&1
    systemctl restart tdz-openvpn-network.service >/dev/null 2>&1
    for unit in tdz-openvpn-tcp tdz-openvpn-udp tdz-openvpn-http tdz-openvpn-wss \
        tdz-openvpn-ssl tdz-openvpn-portal tdz-openvpn-accounting; do
        systemctl enable "$unit.service" >/dev/null 2>&1
        systemctl restart "$unit.service" >/dev/null 2>&1
    done
    for ((attempt=0; attempt<15; attempt++)); do
        all_active=true
        for unit in tdz-openvpn-network tdz-openvpn-tcp tdz-openvpn-udp tdz-openvpn-http tdz-openvpn-wss \
            tdz-openvpn-ssl tdz-openvpn-portal tdz-openvpn-accounting; do
            systemctl is-active --quiet "$unit.service" || all_active=false
        done
        if $all_active &&
           tdz_openvpn_port_listening "$TDZ_OVPN_TCP_PORT" tcp &&
           tdz_openvpn_port_listening "$TDZ_OVPN_UDP_PORT" udp &&
           tdz_openvpn_port_listening "$TDZ_OVPN_HTTP_PORT" tcp &&
           tdz_openvpn_port_listening "$TDZ_OVPN_WSS_PORT" tcp &&
           tdz_openvpn_port_listening "$TDZ_OVPN_SSL_PORT" tcp &&
           tdz_openvpn_port_listening "$TDZ_OVPN_PORTAL_PORT" tcp; then
            return 0
        fi
        sleep 1
    done
    return 1
}

tdz_openvpn_validate_runtime_files() {
    python3 -m py_compile "$TDZ_OVPN_RUNTIME" "$TDZ_OVPN_GATEWAY" "$TDZ_OVPN_PORTAL" &&
        openssl verify -CAfile "$TDZ_OVPN_PKI/ca.crt" "$TDZ_OVPN_PKI/server.crt" >/dev/null 2>&1 &&
        tdz_openvpn_cert_key_match "$TDZ_OVPN_PKI/server.crt" "$TDZ_OVPN_PKI/server.key" &&
        tdz_openvpn_cert_key_match "$TDZ_OVPN_PKI/gateway.crt" "$TDZ_OVPN_PKI/gateway.key" &&
        grep -q '^proto tcp' "$TDZ_OVPN_ROOT/server-tcp.conf" &&
        grep -q "^port $TDZ_OVPN_TCP_PORT$" "$TDZ_OVPN_ROOT/server-tcp.conf" &&
        grep -q '^proto udp' "$TDZ_OVPN_ROOT/server-udp.conf" &&
        grep -q "^port $TDZ_OVPN_UDP_PORT$" "$TDZ_OVPN_ROOT/server-udp.conf" &&
        grep -q -- "--port $TDZ_OVPN_HTTP_PORT " "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-http.service" &&
        grep -q -- "--port $TDZ_OVPN_WSS_PORT " "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-wss.service" &&
        grep -q -- "--port $TDZ_OVPN_SSL_PORT " "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-ssl.service" &&
        grep -q -- "--port $TDZ_OVPN_PORTAL_PORT " "$TDZ_OVPN_SYSTEMD_DIR/tdz-openvpn-portal.service" &&
        grep -q '^<tls-crypt>$' "$TDZ_OVPN_PROFILES/tdz-openvpn-tcp.ovpn"
}

tdz_openvpn_prepare_ports() {
    TDZ_OVPN_TCP_SUBNET=""; TDZ_OVPN_UDP_SUBNET=""
    tdz_openvpn_apply_fixed_port_mapping
    TDZ_OVPN_TCP_SUBNET=$(tdz_openvpn_random_subnet) || return 1
    TDZ_OVPN_UDP_SUBNET=$(tdz_openvpn_random_subnet) || return 1
}

tdz_openvpn_portal_available() {
    if tdz_openvpn_port_listening "$TDZ_OVPN_PORTAL_PORT" tcp; then
        systemctl is-active --quiet tdz-openvpn-portal.service
    else
        return 0
    fi
}

tdz_openvpn_selected_ports_free() {
    ! tdz_openvpn_port_listening "$TDZ_OVPN_TCP_PORT" tcp &&
        ! tdz_openvpn_port_listening "$TDZ_OVPN_UDP_PORT" udp &&
        ! tdz_openvpn_port_listening "$TDZ_OVPN_HTTP_PORT" tcp &&
        ! tdz_openvpn_port_listening "$TDZ_OVPN_WSS_PORT" tcp &&
        ! tdz_openvpn_port_listening "$TDZ_OVPN_SSL_PORT" tcp &&
        ! tdz_openvpn_port_listening "$TDZ_OVPN_PORTAL_PORT" tcp
}

tdz_openvpn_progress_begin() {
    local current=$1 total=$2 label=$3
    printf '  %b[%s/%s]%b %-42s' "$C_CYAN" "$current" "$total" "$C_RESET" "$label"
}

tdz_openvpn_progress_done() {
    printf ' %bDONE%b\n' "$C_GREEN" "$C_RESET"
}

tdz_openvpn_progress_failed() {
    printf ' %bFAILED%b\n' "$C_RED" "$C_RESET"
}

tdz_openvpn_install() {
    local repair=false default_host input_host pam_plugin backup=""
    if tdz_openvpn_is_installed; then
        repair=true
        tdz_openvpn_load_state || {
            echo -e "${C_RED}[ERROR] Saved OpenVPN settings are invalid.${C_RESET}"
            return 1
        }
        echo
        read -r -p "$(echo -e "${C_PROMPT}  Public VPS IP or domain [${TDZ_OVPN_HOST}]: ${C_RESET}")" input_host
        input_host=${input_host:-$TDZ_OVPN_HOST}
        if ! tdz_openvpn_valid_host "$input_host"; then
            echo -e "${C_RED}[ERROR] Enter a valid IPv4 address or domain name.${C_RESET}"
            return 1
        fi
        TDZ_OVPN_HOST="$input_host"
    else
        TDZ_OVPN_SUPPORT_USERNAME="$TDZ_OVPN_FIXED_SUPPORT_USERNAME"
        default_host=$(tdz_openvpn_detect_host)
        echo
        if [[ -n "$default_host" ]]; then
            read -r -p "$(echo -e "${C_PROMPT}  Public VPS IP or domain [${default_host}]: ${C_RESET}")" input_host
            input_host=${input_host:-$default_host}
        else
            read -r -p "$(echo -e "${C_PROMPT}  Public VPS IP or domain: ${C_RESET}")" input_host
        fi
        if ! tdz_openvpn_valid_host "$input_host"; then
            echo -e "${C_RED}[ERROR] Enter a valid IPv4 address or domain name.${C_RESET}"
            return 1
        fi
        TDZ_OVPN_HOST="$input_host"
        tdz_openvpn_prepare_ports || {
            echo -e "${C_RED}[ERROR] Could not prepare the OpenVPN network layout.${C_RESET}"
            return 1
        }
    fi

    if ! tdz_openvpn_portal_available; then
        echo -e "${C_RED}[ERROR] The required public portal port ${TDZ_OVPN_PORTAL_PORT} is already used by another service.${C_RESET}"
        return 1
    fi

    echo
    if declare -F tdz_section >/dev/null 2>&1; then
        tdz_section "$($repair && printf 'REPAIR' || printf 'INSTALL') OPENVPN SUITE"
    else
        echo -e "${C_BLUE}Preparing the OpenVPN protocol suite${C_RESET}"
    fi

    tdz_openvpn_progress_begin 1 6 "Checking packages and PAM authentication"
    if ! tdz_openvpn_install_packages || ! tdz_openvpn_resolve_binary; then
        tdz_openvpn_progress_failed
        echo -e "${C_RED}[ERROR] Required packages could not be installed.${C_RESET}"
        return 1
    fi
    if ! tdz_openvpn_python_supported; then
        tdz_openvpn_progress_failed
        echo -e "${C_RED}[ERROR] OpenVPN Suite requires Python 3.7 or newer.${C_RESET}"
        return 1
    fi
    pam_plugin=$(tdz_openvpn_find_pam_plugin) || {
        tdz_openvpn_progress_failed
        echo -e "${C_RED}[ERROR] The system OpenVPN PAM authentication plugin is unavailable.${C_RESET}"
        return 1
    }
    tdz_openvpn_progress_done

    backup=$(mktemp -d /tmp/tdz-openvpn-rollback.XXXXXX) || return 1
    local failed=false

    tdz_openvpn_progress_begin 2 6 "Preserving the current TDZ configuration"
    if $repair; then
        tdz_openvpn_snapshot_runtime "$backup" || {
            tdz_openvpn_progress_failed
            rm -rf "$backup"
            return 1
        }
    fi
    tdz_openvpn_stop_services
    if ! mkdir -p "$TDZ_OVPN_ROOT" "$TDZ_OVPN_RUN" "$TDZ_OVPN_HOOKS" "$TDZ_OVPN_PROFILES" ||
       ! chmod 700 "$TDZ_OVPN_ROOT" "$TDZ_OVPN_RUN" "$TDZ_OVPN_HOOKS" ||
       ! tdz_openvpn_selected_ports_free || ! tdz_openvpn_ensure_service_user ||
       ! tdz_openvpn_save_state; then
        failed=true
        tdz_openvpn_progress_failed
    else
        tdz_openvpn_progress_done
    fi

    if ! $failed; then
        tdz_openvpn_progress_begin 3 6 "Creating secure keys and account bridge"
        if tdz_openvpn_ensure_pki &&
           tdz_openvpn_prepare_gateway_certificate &&
           tdz_openvpn_write_hooks &&
           tdz_openvpn_write_pam &&
           tdz_openvpn_write_server_config tcp tcp-server "$TDZ_OVPN_TCP_PORT" "$TDZ_OVPN_TCP_SUBNET" "$pam_plugin" &&
           tdz_openvpn_write_server_config udp udp "$TDZ_OVPN_UDP_PORT" "$TDZ_OVPN_UDP_SUBNET" "$pam_plugin"; then
            tdz_openvpn_progress_done
        else
            failed=true
            tdz_openvpn_progress_failed
        fi
    fi

    if ! $failed; then
        tdz_openvpn_progress_begin 4 6 "Generating downloadable connection profiles"
        if tdz_openvpn_generate_profiles && tdz_openvpn_apply_private_permissions; then
            tdz_openvpn_progress_done
        else
            failed=true
            tdz_openvpn_progress_failed
        fi
    fi

    if ! $failed; then
        tdz_openvpn_progress_begin 5 6 "Applying isolated network and service rules"
        if tdz_openvpn_write_network_service && tdz_openvpn_write_systemd_units; then
            tdz_openvpn_progress_done
        else
            failed=true
            tdz_openvpn_progress_failed
        fi
    fi

    if ! $failed; then
        tdz_openvpn_progress_begin 6 6 "Starting and verifying every listener"
        if tdz_openvpn_validate_runtime_files && tdz_openvpn_start_services; then
            tdz_openvpn_progress_done
        else
            failed=true
            tdz_openvpn_progress_failed
        fi
    fi

    if $failed; then
        echo -e "${C_RED}[ERROR] OpenVPN validation failed; restoring the previous state.${C_RESET}"
        tdz_openvpn_stop_services
        if $repair && [[ -d "$backup/openvpn" ]]; then
            tdz_openvpn_restore_snapshot "$backup" >/dev/null 2>&1 || true
        else
            tdz_openvpn_uninstall silent >/dev/null 2>&1 || true
        fi
        rm -rf "$backup"
        return 1
    fi
    rm -rf "$backup"
    echo -e "${C_GREEN}[OK] OpenVPN suite is active and verified.${C_RESET}"
    tdz_openvpn_show_details
}

tdz_openvpn_show_details() {
    local tls_label="Private OpenVPN certificate" shared_fingerprint="" gateway_fingerprint=""
    if ! tdz_openvpn_load_state; then
        echo -e "${C_RED}[ERROR] OpenVPN is not installed.${C_RESET}"
        return 1
    fi
    if [[ -r "${SSL_CERT_CHAIN_FILE:-}" && -r "$TDZ_OVPN_PKI/gateway.crt" ]]; then
        shared_fingerprint=$(openssl x509 -in "$SSL_CERT_CHAIN_FILE" -noout -fingerprint -sha256 2>/dev/null || true)
        gateway_fingerprint=$(openssl x509 -in "$TDZ_OVPN_PKI/gateway.crt" -noout -fingerprint -sha256 2>/dev/null || true)
    fi
    if [[ -n "$shared_fingerprint" && "$shared_fingerprint" == "$gateway_fingerprint" ]]; then
        tls_label="Shared certificate from Domain & SSL"
    fi
    echo
    if declare -F tdz_section >/dev/null 2>&1; then
        tdz_section "OPENVPN CONNECTIONS"
        tdz_detail "Server" "$TDZ_OVPN_HOST"
        tdz_detail "UDP / Official" "$TDZ_OVPN_UDP_PORT"
        tdz_detail "TCP / Official" "$TDZ_OVPN_TCP_PORT"
        tdz_detail "HTTP / WS" "$TDZ_OVPN_HTTP_PORT"
        tdz_detail "WSS / SNI" "$TDZ_OVPN_WSS_PORT / $TDZ_OVPN_HOST"
        tdz_detail "SSL / SNI" "$TDZ_OVPN_SSL_PORT / $TDZ_OVPN_HOST"
        tdz_detail "Outer TLS" "$tls_label"
        tdz_detail "Download Portal" "https://${TDZ_OVPN_HOST}:${TDZ_OVPN_PORTAL_PORT}${TDZ_OVPN_PUBLIC_PATH}/" "$C_CYAN"
        tdz_detail "Contact" "@${TDZ_OVPN_SUPPORT_USERNAME} / https://t.me/${TDZ_OVPN_SUPPORT_USERNAME}" "$C_CYAN"
    else
        printf '  Server: %s\n  Portal: https://%s:%s%s/\n  Contact: @%s\n' \
            "$TDZ_OVPN_HOST" "$TDZ_OVPN_HOST" "$TDZ_OVPN_PORTAL_PORT" "$TDZ_OVPN_PUBLIC_PATH" \
            "$TDZ_OVPN_SUPPORT_USERNAME"
    fi
}

tdz_openvpn_restart() {
    tdz_openvpn_is_installed || return 1
    tdz_openvpn_load_state && tdz_openvpn_start_services
}

tdz_openvpn_refresh_gateway_tls() {
    tdz_openvpn_is_installed || return 0
    tdz_openvpn_load_state || return 1
    local backup
    backup=$(mktemp -d /tmp/tdz-openvpn-tls.XXXXXX) || return 1
    [[ -f "$TDZ_OVPN_PKI/gateway.crt" ]] && cp "$TDZ_OVPN_PKI/gateway.crt" "$backup/gateway.crt"
    [[ -f "$TDZ_OVPN_PKI/gateway.key" ]] && cp "$TDZ_OVPN_PKI/gateway.key" "$backup/gateway.key"
    if tdz_openvpn_prepare_gateway_certificate; then
        if [[ -n "${SSL_CERT_CHAIN_FILE:-}" || -n "${SSL_CERT_KEY_FILE:-}" ]] &&
           [[ "$TDZ_OVPN_GATEWAY_CERT_SOURCE" != "shared" ]]; then
            [[ -f "$backup/gateway.crt" ]] && cp "$backup/gateway.crt" "$TDZ_OVPN_PKI/gateway.crt"
            [[ -f "$backup/gateway.key" ]] && cp "$backup/gateway.key" "$TDZ_OVPN_PKI/gateway.key"
            rm -rf "$backup"
            return 2
        fi
    else
        [[ -f "$backup/gateway.crt" ]] && cp "$backup/gateway.crt" "$TDZ_OVPN_PKI/gateway.crt"
        [[ -f "$backup/gateway.key" ]] && cp "$backup/gateway.key" "$TDZ_OVPN_PKI/gateway.key"
        rm -rf "$backup"
        return 1
    fi
    if tdz_openvpn_cert_key_match "$TDZ_OVPN_PKI/gateway.crt" "$TDZ_OVPN_PKI/gateway.key" &&
       systemctl restart tdz-openvpn-wss.service tdz-openvpn-ssl.service tdz-openvpn-portal.service >/dev/null 2>&1; then
        sleep 1
        if systemctl is-active --quiet tdz-openvpn-wss.service &&
           systemctl is-active --quiet tdz-openvpn-ssl.service &&
           systemctl is-active --quiet tdz-openvpn-portal.service &&
           tdz_openvpn_port_listening "$TDZ_OVPN_WSS_PORT" tcp &&
           tdz_openvpn_port_listening "$TDZ_OVPN_SSL_PORT" tcp &&
           tdz_openvpn_port_listening "$TDZ_OVPN_PORTAL_PORT" tcp; then
            rm -rf "$backup"
            return 0
        fi
    fi
    [[ -f "$backup/gateway.crt" ]] && cp "$backup/gateway.crt" "$TDZ_OVPN_PKI/gateway.crt"
    [[ -f "$backup/gateway.key" ]] && cp "$backup/gateway.key" "$TDZ_OVPN_PKI/gateway.key"
    systemctl restart tdz-openvpn-wss.service tdz-openvpn-ssl.service tdz-openvpn-portal.service >/dev/null 2>&1 || true
    rm -rf "$backup"
    return 1
}

tdz_openvpn_refresh_runtime() {
    tdz_openvpn_is_installed || return 0
    tdz_openvpn_load_state || return 1
    local pam_plugin backup failed=false
    tdz_openvpn_python_supported || return 1
    tdz_openvpn_resolve_binary || return 1
    pam_plugin=$(tdz_openvpn_find_pam_plugin) || return 1
    tdz_openvpn_ensure_service_user || return 1
    backup=$(mktemp -d /tmp/tdz-openvpn-refresh.XXXXXX) || return 1
    tdz_openvpn_snapshot_runtime "$backup" || { rm -rf "$backup"; return 1; }
    tdz_openvpn_stop_services
    tdz_openvpn_selected_ports_free || failed=true
    $failed || tdz_openvpn_save_state || failed=true
    $failed || tdz_openvpn_ensure_pki || failed=true
    $failed || tdz_openvpn_write_hooks || failed=true
    $failed || tdz_openvpn_prepare_gateway_certificate || failed=true
    $failed || tdz_openvpn_write_pam || failed=true
    $failed || tdz_openvpn_write_server_config tcp tcp-server "$TDZ_OVPN_TCP_PORT" "$TDZ_OVPN_TCP_SUBNET" "$pam_plugin" || failed=true
    $failed || tdz_openvpn_write_server_config udp udp "$TDZ_OVPN_UDP_PORT" "$TDZ_OVPN_UDP_SUBNET" "$pam_plugin" || failed=true
    $failed || tdz_openvpn_generate_profiles || failed=true
    $failed || tdz_openvpn_apply_private_permissions || failed=true
    $failed || tdz_openvpn_write_network_service || failed=true
    $failed || tdz_openvpn_write_systemd_units || failed=true
    $failed || tdz_openvpn_validate_runtime_files || failed=true
    $failed || tdz_openvpn_start_services || failed=true
    if $failed; then
        tdz_openvpn_restore_snapshot "$backup" >/dev/null 2>&1 || true
        rm -rf "$backup"
        return 1
    fi
    rm -rf "$backup"
    return 0
}

tdz_openvpn_apply_port_layout() {
    local requested_portal=${1:-} requested_ssl=${2:-} requested_tcp=${3:-}
    local requested_udp=${4:-} requested_http=${5:-} requested_wss=${6:-}
    local pam_plugin backup failed=false rollback_ok=true

    tdz_openvpn_is_installed || {
        echo -e "${C_RED}[ERROR] Install OpenVPN Suite before changing its ports.${C_RESET}"
        return 1
    }
    tdz_openvpn_load_state || {
        echo -e "${C_RED}[ERROR] Saved OpenVPN settings are invalid.${C_RESET}"
        return 1
    }
    if ! tdz_openvpn_requested_ports_valid "$requested_portal" "$requested_ssl" \
        "$requested_tcp" "$requested_udp" "$requested_http" "$requested_wss"; then
        echo -e "${C_RED}[ERROR] Ports must be unique numbers from 1-65535 and must not conflict with TDZ system ports.${C_RESET}"
        return 1
    fi
    if tdz_openvpn_ports_match_layout "$requested_portal" "$requested_ssl" \
        "$requested_tcp" "$requested_udp" "$requested_http" "$requested_wss"; then
        echo -e "${C_YELLOW}[INFO] The OpenVPN port layout is already unchanged.${C_RESET}"
        return 0
    fi

    tdz_openvpn_python_supported || {
        echo -e "${C_RED}[ERROR] Python 3.7 or newer is required.${C_RESET}"
        return 1
    }
    tdz_openvpn_resolve_binary || {
        echo -e "${C_RED}[ERROR] The OpenVPN binary is unavailable.${C_RESET}"
        return 1
    }
    pam_plugin=$(tdz_openvpn_find_pam_plugin) || {
        echo -e "${C_RED}[ERROR] The OpenVPN PAM plugin is unavailable.${C_RESET}"
        return 1
    }
    tdz_openvpn_ensure_service_user || {
        echo -e "${C_RED}[ERROR] The OpenVPN service account is unavailable.${C_RESET}"
        return 1
    }

    backup=$(mktemp -d /tmp/tdz-openvpn-ports.XXXXXX) || return 1
    if ! tdz_openvpn_snapshot_runtime "$backup"; then
        rm -rf "$backup"
        echo -e "${C_RED}[ERROR] Could not create the rollback snapshot.${C_RESET}"
        return 1
    fi

    echo -e "${C_BLUE}[INFO] Rebuilding OpenVPN listeners, firewall rules, profiles, and portal...${C_RESET}"
    tdz_openvpn_stop_services
    TDZ_OVPN_PORTAL_PORT="$requested_portal"
    TDZ_OVPN_SSL_PORT="$requested_ssl"
    TDZ_OVPN_TCP_PORT="$requested_tcp"
    TDZ_OVPN_UDP_PORT="$requested_udp"
    TDZ_OVPN_HTTP_PORT="$requested_http"
    TDZ_OVPN_WSS_PORT="$requested_wss"

    tdz_openvpn_selected_ports_free || failed=true
    $failed || tdz_openvpn_save_state || failed=true
    $failed || tdz_openvpn_ensure_pki || failed=true
    $failed || tdz_openvpn_write_hooks || failed=true
    $failed || tdz_openvpn_prepare_gateway_certificate || failed=true
    $failed || tdz_openvpn_write_pam || failed=true
    $failed || tdz_openvpn_write_server_config tcp tcp-server "$TDZ_OVPN_TCP_PORT" "$TDZ_OVPN_TCP_SUBNET" "$pam_plugin" || failed=true
    $failed || tdz_openvpn_write_server_config udp udp "$TDZ_OVPN_UDP_PORT" "$TDZ_OVPN_UDP_SUBNET" "$pam_plugin" || failed=true
    $failed || tdz_openvpn_generate_profiles || failed=true
    $failed || tdz_openvpn_apply_private_permissions || failed=true
    $failed || tdz_openvpn_write_network_service || failed=true
    $failed || tdz_openvpn_write_systemd_units || failed=true
    $failed || tdz_openvpn_validate_runtime_files || failed=true
    $failed || tdz_openvpn_start_services || failed=true

    if $failed; then
        echo -e "${C_RED}[ERROR] The new ports could not be activated; restoring the previous working layout.${C_RESET}"
        tdz_openvpn_restore_snapshot "$backup" >/dev/null 2>&1 || rollback_ok=false
        rm -rf "$backup"
        if ! $rollback_ok; then
            echo -e "${C_RED}[CRITICAL] Automatic rollback also failed. Run OpenVPN repair from this menu.${C_RESET}"
        fi
        return 1
    fi

    rm -rf "$backup"
    echo -e "${C_GREEN}[OK] Every OpenVPN port, service, firewall rule, profile, and portal page was updated.${C_RESET}"
    tdz_openvpn_show_details
}

TDZ_OVPN_PROMPT_PORT=""
tdz_openvpn_prompt_port() {
    local label=$1 current=$2 input
    if ! read -r -p "$(echo -e "${C_PROMPT}  ${label} [${current}]: ${C_RESET}")" input; then
        return 1
    fi
    input=${input:-$current}
    if ! tdz_openvpn_valid_configurable_port "$input"; then
        echo -e "${C_RED}[ERROR] Invalid or reserved port: ${input}.${C_RESET}"
        return 1
    fi
    TDZ_OVPN_PROMPT_PORT="$input"
}

tdz_openvpn_configure_ports() {
    local new_portal new_ssl new_tcp new_udp new_http new_wss confirm
    tdz_openvpn_is_installed || {
        echo -e "${C_RED}[ERROR] OpenVPN must be installed first.${C_RESET}"
        return 1
    }
    tdz_openvpn_load_state || {
        echo -e "${C_RED}[ERROR] Saved OpenVPN settings are invalid. Run OpenVPN repair first.${C_RESET}"
        return 1
    }
    echo
    if declare -F tdz_section >/dev/null 2>&1; then
        tdz_section "CHANGE OPENVPN PORTS"
    fi
    echo -e "${C_DIM}Press Enter to keep a current value. All six ports must be unique.${C_RESET}"

    tdz_openvpn_prompt_port "Download Portal" "$TDZ_OVPN_PORTAL_PORT" || return 1
    new_portal="$TDZ_OVPN_PROMPT_PORT"
    tdz_openvpn_prompt_port "SSL / SNI method" "$TDZ_OVPN_SSL_PORT" || return 1
    new_ssl="$TDZ_OVPN_PROMPT_PORT"
    tdz_openvpn_prompt_port "TCP / Official method" "$TDZ_OVPN_TCP_PORT" || return 1
    new_tcp="$TDZ_OVPN_PROMPT_PORT"
    tdz_openvpn_prompt_port "UDP / Official method" "$TDZ_OVPN_UDP_PORT" || return 1
    new_udp="$TDZ_OVPN_PROMPT_PORT"
    tdz_openvpn_prompt_port "HTTP / WS method" "$TDZ_OVPN_HTTP_PORT" || return 1
    new_http="$TDZ_OVPN_PROMPT_PORT"
    tdz_openvpn_prompt_port "WSS / SNI method" "$TDZ_OVPN_WSS_PORT" || return 1
    new_wss="$TDZ_OVPN_PROMPT_PORT"

    if ! tdz_openvpn_requested_ports_valid "$new_portal" "$new_ssl" "$new_tcp" \
        "$new_udp" "$new_http" "$new_wss"; then
        echo -e "${C_RED}[ERROR] Ports must be unique and cannot overlap TDZ system services.${C_RESET}"
        return 1
    fi
    if tdz_openvpn_ports_match_layout "$new_portal" "$new_ssl" "$new_tcp" \
        "$new_udp" "$new_http" "$new_wss"; then
        echo -e "\n${C_YELLOW}[INFO] No port changes were entered. Existing OpenVPN ports were kept.${C_RESET}"
        return 0
    fi
    echo
    printf '  Portal %-5s  SSL %-5s  TCP %-5s  UDP %-5s  HTTP %-5s  WSS %-5s\n' \
        "$new_portal" "$new_ssl" "$new_tcp" "$new_udp" "$new_http" "$new_wss"
    echo -e "${C_YELLOW}[WARNING] Applying changed ports restarts OpenVPN and disconnects active OpenVPN sessions.${C_RESET}"
    if ! read -r -p "$(echo -e "${C_PROMPT}  Apply this layout? Type yes: ${C_RESET}")" confirm; then
        confirm=""
    fi
    [[ "$confirm" == "yes" ]] || {
        echo -e "${C_YELLOW}[CANCELLED] Existing OpenVPN ports were kept.${C_RESET}"
        return 0
    }
    tdz_openvpn_apply_port_layout "$new_portal" "$new_ssl" "$new_tcp" \
        "$new_udp" "$new_http" "$new_wss"
}

tdz_openvpn_restore_default_ports() {
    local confirm
    tdz_openvpn_is_installed || {
        echo -e "${C_RED}[ERROR] OpenVPN must be installed first.${C_RESET}"
        return 1
    }
    tdz_openvpn_load_state || {
        echo -e "${C_RED}[ERROR] Saved OpenVPN settings are invalid. Run OpenVPN repair first.${C_RESET}"
        return 1
    }
    if tdz_openvpn_ports_match_fixed_mapping; then
        echo -e "${C_YELLOW}[INFO] Default OpenVPN ports are already active. Nothing was changed.${C_RESET}"
        return 0
    fi
    echo -e "${C_YELLOW}[WARNING] Restoring default ports restarts OpenVPN and disconnects active OpenVPN sessions.${C_RESET}"
    if ! read -r -p "$(echo -e "${C_PROMPT}  Restore Portal 1180 and methods 446-450? Type yes: ${C_RESET}")" confirm; then
        confirm=""
    fi
    [[ "$confirm" == "yes" ]] || {
        echo -e "${C_YELLOW}[CANCELLED] Existing OpenVPN ports were kept.${C_RESET}"
        return 0
    }
    tdz_openvpn_apply_port_layout "$TDZ_OVPN_FIXED_PORTAL_PORT" "$TDZ_OVPN_FIXED_SSL_PORT" \
        "$TDZ_OVPN_FIXED_TCP_PORT" "$TDZ_OVPN_FIXED_UDP_PORT" \
        "$TDZ_OVPN_FIXED_HTTP_PORT" "$TDZ_OVPN_FIXED_WSS_PORT"
}

tdz_openvpn_configure_support_contact() {
    local current input previous
    tdz_openvpn_is_installed || {
        echo -e "${C_RED}[ERROR] OpenVPN must be installed first.${C_RESET}"
        return 1
    }
    tdz_openvpn_load_state || {
        echo -e "${C_RED}[ERROR] Saved OpenVPN settings are invalid. Run OpenVPN repair first.${C_RESET}"
        return 1
    }
    current="$TDZ_OVPN_SUPPORT_USERNAME"
    echo
    if declare -F tdz_section >/dev/null 2>&1; then
        tdz_section "CONTACT USERNAME"
    fi
    echo -e "${C_DIM}This contact username is shown for account requests and support on every portal page.${C_RESET}"
    if ! read -r -p "$(echo -e "${C_PROMPT}  Contact username [@${current}]: ${C_RESET}")" input; then
        return 1
    fi
    input=${input:-$current}
    input=${input#@}
    if ! tdz_openvpn_valid_telegram_username "$input"; then
        echo -e "${C_RED}[ERROR] Use a valid contact username: 5-32 letters, numbers, or underscores; start with a letter.${C_RESET}"
        return 1
    fi
    if [[ "$input" == "$current" ]]; then
        echo -e "${C_YELLOW}[INFO] Contact is already @${current}. Nothing was changed.${C_RESET}"
        return 0
    fi

    previous="$current"
    TDZ_OVPN_SUPPORT_USERNAME="$input"
    if tdz_openvpn_save_state && tdz_openvpn_generate_profiles &&
       tdz_openvpn_apply_private_permissions; then
        echo -e "${C_GREEN}[OK] Portal contact changed to @${TDZ_OVPN_SUPPORT_USERNAME}.${C_RESET}"
        echo -e "${C_DIM}OpenVPN listeners and active VPN sessions were not restarted.${C_RESET}"
        return 0
    fi

    TDZ_OVPN_SUPPORT_USERNAME="$previous"
    tdz_openvpn_save_state >/dev/null 2>&1 || true
    tdz_openvpn_generate_profiles >/dev/null 2>&1 || true
    tdz_openvpn_apply_private_permissions >/dev/null 2>&1 || true
    echo -e "${C_RED}[ERROR] Could not rebuild the portal. The previous contact @${previous} was restored.${C_RESET}"
    return 1
}

tdz_openvpn_uninstall() {
    local mode=${1:-interactive} confirm=""
    # Load ownership metadata before state is removed. Legacy installations
    # without the flag intentionally leave an unknown pre-existing account
    # untouched rather than deleting it on a guess.
    [[ -r "$TDZ_OVPN_STATE" ]] && tdz_openvpn_load_state >/dev/null 2>&1 || true
    if [[ "$mode" != "silent" ]]; then
        echo
        read -r -p "$(echo -e "${C_PROMPT}  Remove the optional OpenVPN suite? Type 'yes': ${C_RESET}")" confirm
        [[ "$confirm" == "yes" ]] || {
            echo -e "${C_YELLOW}[CANCELLED] OpenVPN was kept.${C_RESET}"
            return 0
        }
    fi
    tdz_openvpn_stop_services
    local unit
    for unit in tdz-openvpn-accounting tdz-openvpn-portal tdz-openvpn-http tdz-openvpn-wss \
        tdz-openvpn-ssl tdz-openvpn-tcp tdz-openvpn-udp tdz-openvpn-network; do
        systemctl disable "$unit.service" >/dev/null 2>&1 || true
        rm -f "$TDZ_OVPN_SYSTEMD_DIR/${unit}.service"
    done
    [[ -x "$TDZ_OVPN_FIREWALL" ]] && "$TDZ_OVPN_FIREWALL" stop >/dev/null 2>&1 || true
    rm -f "$TDZ_OVPN_FIREWALL" "$TDZ_OVPN_PAM_SERVICE" "$TDZ_OVPN_SYSCTL"
    rm -rf "$TDZ_OVPN_ROOT" "$TDZ_OVPN_PORTAL_BASE"
    if [[ "$TDZ_OVPN_SERVICE_USER_CREATED" == "1" ]] && id "$TDZ_OVPN_SERVICE_USER" >/dev/null 2>&1; then
        userdel "$TDZ_OVPN_SERVICE_USER" >/dev/null 2>&1 || true
    fi
    if [[ "$TDZ_OVPN_SERVICE_GROUP_CREATED" == "1" ]] &&
       getent group "$TDZ_OVPN_SERVICE_USER" >/dev/null 2>&1; then
        groupdel "$TDZ_OVPN_SERVICE_USER" >/dev/null 2>&1 || true
    fi
    systemctl daemon-reload >/dev/null 2>&1 || true
    systemctl reset-failed >/dev/null 2>&1 || true
    [[ "$mode" == "silent" ]] || echo -e "${C_GREEN}[OK] OpenVPN suite removed. Existing SSH user accounts were preserved.${C_RESET}"
}

tdz_openvpn_menu() {
    while true; do
        local status="Not Installed" status_color="$C_RED" state_loaded=false
        if tdz_openvpn_is_active; then
            status="Active"; status_color="$C_GREEN"
        elif tdz_openvpn_is_installed; then
            status="Attention"; status_color="$C_YELLOW"
        fi
        if tdz_openvpn_is_installed && tdz_openvpn_load_state; then
            state_loaded=true
        fi
        show_banner
        echo
        tdz_box_top
        tdz_box_header "OPENVPN PROTOCOL SUITE"
        tdz_box_divider
        tdz_row2 "${C_GRAY}STATUS${C_RESET}" "${status_color}${C_BOLD}${status}${C_RESET}"
        if $state_loaded; then
            tdz_kv2 "PORTAL" ":${TDZ_OVPN_PORTAL_PORT}${TDZ_OVPN_PUBLIC_PATH}" \
                "SSL / TCP" "${TDZ_OVPN_SSL_PORT} / ${TDZ_OVPN_TCP_PORT}"
            tdz_kv2 "UDP / HTTP" "${TDZ_OVPN_UDP_PORT} / ${TDZ_OVPN_HTTP_PORT}" \
                "WSS" "$TDZ_OVPN_WSS_PORT"
            tdz_row2 "${C_GRAY}CONTACT${C_RESET}" "${C_CYAN}@${TDZ_OVPN_SUPPORT_USERNAME}${C_RESET}"
        fi
        tdz_box_divider
        tdz_menu1 "[ 1]" "Install or Repair OpenVPN"
        tdz_menu1 "[ 2]" "View Ports and Download Portal"
        tdz_menu1 "[ 3]" "Change Portal and Method Ports"
        tdz_menu1 "[ 4]" "Restore Default Ports (1180, 446-450)"
        tdz_menu1 "[ 5]" "Regenerate Download Profiles"
        tdz_menu1 "[ 6]" "Restart and Verify Services"
        tdz_menu1 "[ 7]" "Uninstall OpenVPN Suite"
        tdz_menu1 "[ 8]" "Change Contact Username"
        tdz_box_divider
        tdz_menu1 "[ 0]" "Return to Protocol Manager"
        tdz_box_bot
        echo
        read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" choice || return
        case "$choice" in
            1) tdz_openvpn_install; press_enter ;;
            2) tdz_openvpn_show_details; press_enter ;;
            3) tdz_openvpn_configure_ports; press_enter ;;
            4) tdz_openvpn_restore_default_ports; press_enter ;;
            5)
                if tdz_openvpn_load_state && tdz_openvpn_generate_profiles &&
                   tdz_openvpn_apply_private_permissions && systemctl restart tdz-openvpn-portal; then
                    echo -e "${C_GREEN}[OK] Download profiles regenerated.${C_RESET}"
                    tdz_openvpn_show_details
                else
                    echo -e "${C_RED}[ERROR] OpenVPN must be installed first.${C_RESET}"
                fi
                press_enter ;;
            6)
                if tdz_openvpn_restart; then echo -e "${C_GREEN}[OK] All OpenVPN services are active.${C_RESET}"
                else echo -e "${C_RED}[ERROR] Service verification failed. Check the system journal.${C_RESET}"; fi
                press_enter ;;
            7) tdz_openvpn_uninstall; press_enter ;;
            8) tdz_openvpn_configure_support_contact; press_enter ;;
            0) return ;;
            *) invalid_option ;;
        esac
    done
}

tdz_openvpn_append_client_details() {
    tdz_openvpn_is_installed || return 0
    tdz_openvpn_show_details
    echo -e "  ${C_DIM}Use the same SSH username and password shown above.${C_RESET}"
}

tdz_openvpn_kill_user() {
    local username=${1:-} reason=${2:-policy}
    [[ -x "$TDZ_OVPN_RUNTIME" && -n "$username" ]] || return 0
    "$TDZ_OVPN_RUNTIME" kill-user "$username" "$reason" >/dev/null 2>&1 || true
}
