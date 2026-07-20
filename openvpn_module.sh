#!/bin/bash
# TDZ SSH TUNNEL optional OpenVPN protocol module.
# This file is sourced by menu.sh; it does not execute actions on its own.

TDZ_OVPN_MODULE_VERSION="2026-07-20.3"
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
Portal (HTTP): http://$TDZ_OVPN_HOST:$TDZ_OVPN_PORTAL_PORT$TDZ_OVPN_PUBLIC_PATH/
Online documentation: https://$TDZ_OVPN_HOST:$TDZ_OVPN_PORTAL_PORT$TDZ_OVPN_PUBLIC_PATH/docs
Download page: https://$TDZ_OVPN_HOST:$TDZ_OVPN_PORTAL_PORT$TDZ_OVPN_PUBLIC_PATH/download
Account and support: @$TDZ_OVPN_SUPPORT_USERNAME (https://t.me/$TDZ_OVPN_SUPPORT_USERNAME)

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

Import a profile, then enter the same TDZ account username and password.
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
      <span class="site-logo site-logo-header" aria-hidden="true"><img src="$TDZ_OVPN_PUBLIC_PATH/assets/tdz-logo.jpg" alt=""></span>
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
  <div class="support-orb" aria-hidden="true"><span>✦</span></div>
  <div class="support-copy">
    <div class="kicker">Account &amp; support</div>
    <h2 id="account-support-title">No TDZ account yet? Start here.</h2>
    <p>An active SSH/OVPN account is required to sign in after importing a profile. Message the server support contact to request an account or get connection help.</p>
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
      <a class="footer-brand" href="$TDZ_OVPN_PUBLIC_PATH/"><span class="site-logo site-logo-footer" aria-hidden="true"><img src="$TDZ_OVPN_PUBLIC_PATH/assets/tdz-logo.jpg" alt=""></span><span><strong>TDZ</strong> OVPN PORTAL</span></a>
      <p>Six OpenVPN transport paths, one TDZ identity, and a focused setup experience for every device.</p>
    </section>
    <section class="footer-column">
      <h2>Portal</h2>
      <a href="$TDZ_OVPN_PUBLIC_PATH/">Overview</a>
      <a href="$TDZ_OVPN_PUBLIC_PATH/docs">Setup guide</a>
      <a href="$TDZ_OVPN_PUBLIC_PATH/download">Downloads</a>
    </section>
    <section class="footer-column">
      <h2>Need an account?</h2>
      <a class="footer-support-link" href="https://t.me/$TDZ_OVPN_SUPPORT_USERNAME" target="_blank" rel="noopener noreferrer">Telegram @$TDZ_OVPN_SUPPORT_USERNAME ↗</a>
      <p class="footer-note">Account requests and connection support.</p>
    </section>
    <section class="footer-column footer-developer">
      <h2>Project</h2>
      <p class="developer-line"><span>Developed By:</span><a class="developer-link" href="https://tuhinbro.com/" target="_blank" rel="noopener noreferrer">Yeasinul Hoque Tuhin</a></p>
      <p class="developer-line"><span>Telegram:</span><a class="developer-link" href="https://t.me/TuhinBroh" target="_blank" rel="noopener noreferrer">@TuhinBroh</a></p>
    </section>
  </div>
  <div class="shell footer-bottom"><a class="footer-repo" href="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT" target="_blank" rel="noopener noreferrer">TDZ SSH TUNNEL <span>•</span> OpenVPN Suite</a><span>Private routes. Clear setup.</span></div>
</footer>
EOF
}

tdz_openvpn_portal_write_assets() {
    # Keep the official TDZ artwork self-contained so portal branding does not
    # depend on GitHub being reachable from the visitor's network.
    base64 --decode > "$TDZ_OVPN_PROFILES/tdz-logo.jpg" <<'TDZ_OVPN_LOGO_EOF' || return 1
/9j/4QF4RXhpZgAATU0AKgAAAAgABgEAAAMAAAABBDgAAAEBAAMAAAABCSQAAAExAAIAAAAmAAAA
VodpAAQAAAABAAAAkAESAAMAAAABAAEAAAEyAAIAAAAUAAAAfAAAAABBbmRyb2lkIFJQMUEuMjAw
NzIwLjAxMi5NNDA1RkREUzJDV0YzADIwMjU6MDY6MDMgMDE6MTY6NDAAAAWQAwACAAAAFAAAANKS
kQACAAAABDQ0MACQEAACAAAABwAAAOaQEQACAAAABwAAAO2SCAADAAAAAQAAAAAAAAAAMjAyNTow
NjowMyAwMToxNjo0MAArMDY6MDAAKzA2OjAwAAAFAQAAAwAAAAEEOAAAAQEAAwAAAAEJJAAAATEA
AgAAACYAAAE2ARIAAwAAAAEAAQAAATIAAgAAABQAAAFcAAAAAEFuZHJvaWQgUlAxQS4yMDA3MjAu
MDEyLk00MDVGRERTMkNXRjMAMjAyNTowNjowMyAwMToxNjo0MAD/4AAQSkZJRgABAQAAAQABAAD/
4gIoSUNDX1BST0ZJTEUAAQEAAAIYAAAAAAIQAABtbnRyUkdCIFhZWiAAAAAAAAAAAAAAAABhY3Nw
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAQAA9tYAAQAAAADTLQAAAAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAlkZXNjAAAA8AAAAHRyWFlaAAABZAAA
ABRnWFlaAAABeAAAABRiWFlaAAABjAAAABRyVFJDAAABoAAAAChnVFJDAAABoAAAAChiVFJDAAAB
oAAAACh3dHB0AAAByAAAABRjcHJ0AAAB3AAAADxtbHVjAAAAAAAAAAEAAAAMZW5VUwAAAFgAAAAc
AHMAUgBHAEIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAFhZWiAAAAAAAABvogAAOPUAAAOQWFlaIAAA
AAAAAGKZAAC3hQAAGNpYWVogAAAAAAAAJKAAAA+EAAC2z3BhcmEAAAAAAAQAAAACZmYAAPKnAAAN
WQAAE9AAAApbAAAAAAAAAABYWVogAAAAAAAA9tYAAQAAAADTLW1sdWMAAAAAAAAAAQAAAAxlblVT
AAAAIAAAABwARwBvAG8AZwBsAGUAIABJAG4AYwAuACAAMgAwADEANv/bAEMAAgEBAgEBAgICAgIC
AgIDBQMDAwMDBgQEAwUHBgcHBwYHBwgJCwkICAoIBwcKDQoKCwwMDAwHCQ4PDQwOCwwMDP/bAEMB
AgICAwMDBgMDBgwIBwgMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwMDAwM
DAwMDAwMDP/AABEIA2cDbQMBIgACEQEDEQH/xAAeAAEAAQUAAwEAAAAAAAAAAAAABwUGCAkKAQME
Av/EAGoQAAEDAgMCCAoDBwwOBwQLAAABAgMEBQYHEQgSCQoYITE3VbITNkFRcnSEkpOzFCJhFTJC
cXaBtBojODlSV2J1kaG10xYZMzRTVoKUlZaxwdLUJDVYc3ei0RclR/AmKClDRlSDhaO24f/EAB0B
AQACAgMBAQAAAAAAAAAAAAAFBgcIAgMEAQn/xABBEQEAAgEDAQUDCQMJCQAAAAAAAQIDBAUREgYH
ITFBE2FxCCIyUYGRobHRFCTBFjU3QlJic8PwFSMzY3KCorLC/9oADAMBAAIRAxEAPwDbjasK/wBm
eZtTbll8B4epnXf0103d53+4vTkzJ2mvwyhZY9eftFT3ZCdAIo5Mydpr8McmZO01+GSuAIo5Mydp
r8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSu
AIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8Mcm
ZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5M
ydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+
GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8
McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAI
o5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO01+GSuAIo5Mydpr8McmZO
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
uHCcbc+F9i7C19nsuXmF3U2Js4b1Sv54olVrqW2N0++mfvRubHousk0K6aRuAhjJXJDG/GfNri5Z
xZsz3jCeyBl1cJIcK2BZVpfu+6NdFe5ejVW88sv4CO8Exdd9xs32MdnHArs+n5k4CwTY8GYFwnhq
XBGDVt9Ayk+7VNPUQVNbXcyIr4XS0tMyJ79XP8FNIiq2VrnfrZBteV2deG7xl3husghwrk5VswzU
YAgoZbdFaN1qOibXRytbLOsjE3/rIkb99+8kv3xPFdnzg/DWc1LlxUXSmocUTYfmxHT0L2rG11vg
mZBLK12m7pG+SNFTXVEe1ehQL1BCeD+EMymxztEWnKygxN/9MsQ2l98s1LPSywx3qjY56PlpZXNR
kyIkb1XcVfqtVegvnPPaHwNszYGqMS4/xVY8JWOm+/rLnVsp49fMiuXnVfMgF5gg7JnhDstc+Zrc
/D9RiNbXeZmU1tvFbYKyjtdxle7dYyGqljbFI5zlRERrl1VUROkqm3VtnYQ4P/ZcxXmpjWpSK0Ya
pVfHTtciTXGpd9WGmiRemSR6tanm1VV5kVQNfvGY+FIzM2N7Tl5lhkbiVtJmtmXXIyK32+2JW3Jl
Ho6NHsV2qMfJO6JjGrG7eRkqoqbpnBwXmVua2T2w3gSzZ24qqcX5nLSPrL3WTozfp5JpHStpVcxE
Rywte2NXJ0qxelNFMQOBf4PO/ZzZlV22xtE291ZnPmY5a/DFoqkV0GCrQ5ulMyJjvvZVhVNFVEVr
Xa/fvcqZu7S23xlHsiVdDR4+xvZ7Ldrq5GUNr8J4a41qrzIkVOzWR6/iaBMII8yY2ncM55Vj6S2R
YgtdyZT/AExKC+WeptVXLBvNaszIp2Nc6PVzU3kTT6zfOhTNqfbhyn2KMKNvOaOOsP4Po5dfANr6
prJqpf3Mcf3z1+xEUCVgQdsx8ItlTtcUtvmwfe67cvLpW2v7qWyoti3bwSayLTJOxnhkanOqs15u
ck7M/New5O4YddsQVzaOl8I2GJqNWSaplcqNZFFG3Vz3uVURGtRVVVAuMEU7Je2xlvtvYBuuJcuM
QMvVtsNzms1zSSB9NPbqyJGukhmjkRHMciPauip0KWls/Zi482lc6KvMGzYosUGRcH0m02a1x210
tbiKWF6xSXH6Sr0SOHw7JGxtax2+yNH66SJoGQYAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
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
5S9w7OpPfcOUvcOzqT33AAOUvcOzqT33DlL3Ds6k99wADlL3Ds6k99w5S9w7OpPfcAA5S9w7OpPf
cOUvcOzqT33AAOUvcOzqT33DlL3Ds6k99wADlL3Ds6k99w5S9w7OpPfcAA5S9w7OpPfcOUvcOzqT
33AAOUvcOzqT33DlL3Ds6k99wADlL3Ds6k99w5S9w7OpPfcAA5S9w7OpPfcOUvcOzqT33AAOUvcO
zqT33DlL3Ds6k99wADlL3Ds6k99w5S9w7OpPfcAA5S9w7OpPfcOUvcOzqT33AAOUvcOzqT33DlL3
Ds6k99wADlL3Ds6k99w5S9w7OpPfcAA5S9w7OpPfcOUvcOzqT33AAOUvcOzqT33DlL3Ds6k99wAD
lL3Ds6k99w5S9w7OpPfcAA5S9w7OpPfcOUvcOzqT33AAOUvcOzqT33DlL3Ds6k99wADlL3Ds6k99
w5S9w7OpPfcAA5S9w7OpPfcOUvcOzqT33AAUTHucNVj6ysop6SCBjJkm3mOVV1RFTTn/ABko5E9W
Nv8ASl+Y4AD/2QAAoQsYAAAAUGhvdG9FZGl0b3JfUmVfRWRpdF9EYXRheyJvcmlnaW5hbFBhdGgi
OiJcL2RhdGFcL3NlY1wvcGhvdG9lZGl0b3JcLzBcL3N0b3JhZ2VcL2VtdWxhdGVkXC8wXC9EQ0lN
XC9TY3JlZW5zaG90c1wvU2NyZWVuc2hvdF8yMDI1MDYwMy0wMTE2NDBfVmlhLmpwZyIsImNsaXBJ
bmZvVmFsdWUiOiJ7XCJtQ2VudGVyWFwiOjAuNTAyMzIxNzc5NzI3OTM1OCxcIm1DZW50ZXJZXCI6
MC40NzU1NzczMjQ2Mjg4Mjk5NixcIm1XaWR0aFwiOjAuODExODA0NTkyNjA5NDA1NSxcIm1IZWln
aHRcIjowLjM3MjAxMTM5MzMwODYzOTUsXCJtUm90YXRpb25cIjowLFwibVJvdGF0ZVwiOjAsXCJt
SEZsaXBcIjowLFwibVZGbGlwXCI6MCxcIm1Sb3RhdGlvbkVmZmVjdFwiOjAsXCJtUm90YXRlRWZm
ZWN0XCI6MCxcIm1IRmxpcEVmZmVjdFwiOjAsXCJtVkZsaXBFZmZlY3RcIjowfSIsInRvbmVWYWx1
ZSI6IntcImJyaWdodG5lc3NcIjoxMDAsXCJleHBvc3VyZVwiOjEwMCxcImNvbnRyYXN0XCI6MTAw
LFwic2F0dXJhdGlvblwiOjEwMCxcImh1ZVwiOjEwMCxcIndiTW9kZVwiOi0xLFwid2JUZW1wZXJh
dHVyZVwiOjEwMCxcInRpbnRcIjoxMDAsXCJzaGFkb3dcIjoxMDAsXCJoaWdobGlnaHRcIjoxMDB9
IiwiZWZmZWN0VmFsdWUiOiJ7XCJmaWx0ZXJJbmRpY2F0aW9uXCI6NDA5NyxcImZpbHRlclR5cGVc
IjowLFwiYWxwaGFWYWx1ZVwiOjEwMH0iLCJpc0JsZW5kaW5nIjp0cnVlLCJpc05vdFJlRWRpdCI6
ZmFsc2UsInNlcFZlcnNpb24iOiIxMjAxMDAiLCJyZVNpemUiOjQsInJvdGF0aW9uIjoxLCJhZGp1
c3RtZW50VmFsdWUiOiJ7XCJtQ3JvcFN0YXRlXCI6MTMxMDc2fSIsImlzQXBwbHlTaGFwZUNvcnJl
Y3Rpb24iOmZhbHNlfQAAoQsWAAAAT3JpZ2luYWxfUGF0aF9IYXNoX0tleTczYWJlMTM2NGY0Zjc2
MGZhOWQwZjk4MzA2MjRlNzc4ZWE3ODk5NTI1MzEwN2E3ZDBhOTc1NmI3MDllMjkxZjAvMTU0Mzcw
U0VGSGoAAAACAAAAAAChC78DAABaAwAAAAChC2UAAABlAAAAJAAAAFNFRlQ=
TDZ_OVPN_LOGO_EOF
    {
        printf '%s' '<svg xmlns="http://www.w3.org/2000/svg" viewBox="130 315 240 240"><image width="877" height="871" href="data:image/jpeg;base64,'
        base64 -w 0 "$TDZ_OVPN_PROFILES/tdz-logo.jpg" || return 1
        printf '%s\n' '"/></svg>'
    } > "$TDZ_OVPN_PROFILES/tdz-favicon.svg" || return 1
    cat > "$TDZ_OVPN_PROFILES/portal.css" <<'EOF'
:root{
  color-scheme:light;
  --bg:#eef1f5;--bg-elevated:#f7f8fa;--panel:rgba(255,255,255,.78);--panel-solid:#fff;
  --panel-soft:#f3f5f8;--header:rgba(248,250,252,.76);--text:#11151d;--text-soft:#3d4655;
  --muted:#70798a;--line:rgba(19,28,42,.12);--line-strong:rgba(19,28,42,.2);
  --accent:#ef4050;--accent-hover:#d92d3e;--accent-soft:rgba(239,64,80,.1);--accent-glow:rgba(239,64,80,.22);
  --blue:#2878ff;--blue-hover:#1263e6;--blue-soft:rgba(40,120,255,.11);--green:#18a875;
  --code:#10141b;--code-text:#e8edf5;--shadow:0 24px 70px rgba(21,32,49,.12);
  --shadow-soft:0 10px 30px rgba(21,32,49,.08);--grid:rgba(40,54,75,.055);
  --button-text:#fff;--radius:18px;--radius-lg:28px
}
:root[data-theme="dark"]{
  color-scheme:dark;
  --bg:#090d13;--bg-elevated:#0d121a;--panel:rgba(18,24,34,.78);--panel-solid:#121822;
  --panel-soft:#171f2b;--header:rgba(13,18,26,.76);--text:#f5f7fb;--text-soft:#c3cad5;
  --muted:#8791a1;--line:rgba(225,233,245,.11);--line-strong:rgba(225,233,245,.19);
  --accent:#ff5262;--accent-hover:#ff6e7b;--accent-soft:rgba(255,82,98,.12);--accent-glow:rgba(255,82,98,.24);
  --blue:#4d8dff;--blue-hover:#75a7ff;--blue-soft:rgba(77,141,255,.13);--green:#45d3a0;
  --code:#070a0f;--code-text:#e8edf5;--shadow:0 28px 80px rgba(0,0,0,.42);
  --shadow-soft:0 12px 34px rgba(0,0,0,.27);--grid:rgba(184,202,229,.045);--button-text:#fff
}
@media(prefers-color-scheme:dark){
  :root:not([data-theme]){color-scheme:dark;--bg:#090d13;--bg-elevated:#0d121a;--panel:rgba(18,24,34,.78);--panel-solid:#121822;--panel-soft:#171f2b;--header:rgba(13,18,26,.76);--text:#f5f7fb;--text-soft:#c3cad5;--muted:#8791a1;--line:rgba(225,233,245,.11);--line-strong:rgba(225,233,245,.19);--accent:#ff5262;--accent-hover:#ff6e7b;--accent-soft:rgba(255,82,98,.12);--accent-glow:rgba(255,82,98,.24);--blue:#4d8dff;--blue-hover:#75a7ff;--blue-soft:rgba(77,141,255,.13);--green:#45d3a0;--code:#070a0f;--code-text:#e8edf5;--shadow:0 28px 80px rgba(0,0,0,.42);--shadow-soft:0 12px 34px rgba(0,0,0,.27);--grid:rgba(184,202,229,.045)}
}
*{box-sizing:border-box}
html{scroll-behavior:smooth;background:var(--bg)}
body{
  margin:0;min-height:100vh;color:var(--text);
  background:radial-gradient(circle at 82% -8%,var(--accent-glow),transparent 30rem),radial-gradient(circle at -8% 35%,var(--blue-soft),transparent 32rem),linear-gradient(var(--grid) 1px,transparent 1px),linear-gradient(90deg,var(--grid) 1px,transparent 1px),var(--bg);
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
.site-logo{position:relative;display:block;flex:0 0 auto;overflow:hidden;border:1px solid rgba(19,28,42,.12);border-radius:10px;background:#fff;box-shadow:0 7px 20px rgba(16,24,38,.1)}
.site-logo img{position:absolute;top:50%;left:50%;display:block;max-width:none;height:auto;transform:translate(-50%,-50%)}
.site-logo-header{width:82px;height:36px}.site-logo-header img{width:118px}
.site-logo-footer{width:108px;height:43px}.site-logo-footer img{width:155px}
.site-logo-project{width:172px;height:72px;border-radius:15px;box-shadow:0 14px 34px rgba(16,24,38,.13)}.site-logo-project img{width:247px}
.brand-copy{display:grid;line-height:1.05}.brand-copy strong{font-size:1.02rem;letter-spacing:.2em}.brand-copy small{margin-top:5px;color:var(--muted);font-size:.63rem;font-weight:800;letter-spacing:.13em}
.nav-links{display:flex;justify-content:center;align-items:center;gap:4px}
.nav-link{border:1px solid transparent;border-radius:11px;color:var(--muted);padding:8px 11px;font-size:.87rem;font-weight:680;text-decoration:none;transition:.18s ease}
.nav-link:hover,.nav-link.active{border-color:var(--line);background:var(--panel);color:var(--text)}
.nav-link.active{box-shadow:inset 0 -2px var(--accent)}
.nav-tools{display:flex;align-items:center;justify-content:flex-end}
.theme-switch{display:flex;align-items:center;border:1px solid var(--line);border-radius:13px;background:var(--panel-soft);padding:3px}
.theme-option{display:inline-flex;align-items:center;gap:4px;min-height:31px;border:0;border-radius:9px;background:transparent;color:var(--muted);padding:4px 8px;font-size:.72rem;cursor:pointer;transition:.18s ease}
.theme-option span{font-size:.83rem}.theme-option b{font-weight:700}
.theme-option:hover{color:var(--text)}.theme-option[aria-pressed="true"]{background:var(--panel-solid);color:var(--text);box-shadow:0 4px 12px rgba(15,24,38,.12)}
main{padding:36px 0 88px}
.hero{position:relative;display:grid;grid-template-columns:minmax(0,1.12fr) minmax(340px,.88fr);align-items:stretch;min-height:570px;overflow:hidden;border:1px solid var(--line-strong);border-radius:var(--radius-lg);background:linear-gradient(135deg,var(--panel-solid),var(--panel));box-shadow:var(--shadow)}
.hero:before{content:"";position:absolute;inset:0;background:radial-gradient(circle at 80% 16%,var(--accent-glow),transparent 30%),linear-gradient(120deg,var(--blue-soft),transparent 36%);pointer-events:none}
.hero-copy{position:relative;z-index:2;display:flex;flex-direction:column;justify-content:center;padding:clamp(36px,6vw,74px)}
.eyebrow,.kicker,.label{color:var(--accent);font-size:.72rem;font-weight:850;letter-spacing:.15em;text-transform:uppercase}
.eyebrow{display:flex;align-items:center;gap:9px}.eyebrow-dot{width:7px;height:7px;border-radius:50%;background:var(--green);box-shadow:0 0 0 5px rgba(24,168,117,.1)}
.hero h1{max-width:720px;margin:.75rem 0 1.15rem;font-size:clamp(3rem,6.4vw,5.85rem);font-weight:780;letter-spacing:-.064em;line-height:.94}
.hero h1 span{color:var(--accent)}.lead{max-width:670px;margin:0;color:var(--text-soft);font-size:clamp(1rem,1.35vw,1.16rem)}
.actions{display:flex;flex-wrap:wrap;gap:10px;margin-top:27px}
.button{display:inline-flex;align-items:center;justify-content:center;gap:8px;min-height:46px;border:1px solid var(--line-strong);border-radius:12px;background:var(--panel-solid);color:var(--text);padding:9px 16px;font-size:.88rem;font-weight:780;text-decoration:none;box-shadow:var(--shadow-soft);transition:.18s ease}
.button:hover{border-color:var(--accent);color:var(--accent);transform:translateY(-1px)}
.button.primary{border-color:var(--accent);background:var(--accent);color:var(--button-text);box-shadow:0 12px 30px var(--accent-glow)}
.button.primary:hover{background:var(--accent-hover);color:var(--button-text)}
.button.telegram{border-color:var(--blue);background:var(--blue);color:#fff;box-shadow:0 12px 28px var(--blue-soft);white-space:nowrap}.button.telegram:hover{background:var(--blue-hover);color:#fff}
.hero-badges{display:flex;flex-wrap:wrap;gap:8px;margin-top:28px}.hero-badge{border:1px solid var(--line);border-radius:999px;background:var(--panel);color:var(--muted);padding:6px 10px;font-size:.76rem;font-weight:650}
.signal-panel{position:relative;z-index:2;display:flex;flex-direction:column;justify-content:center;overflow:hidden;margin:18px;border:1px solid var(--line);border-radius:22px;background:linear-gradient(160deg,var(--panel-soft),var(--panel));padding:24px;box-shadow:inset 0 1px rgba(255,255,255,.07)}
.signal-head{display:flex;align-items:center;justify-content:space-between;gap:12px;color:var(--muted);font-size:.72rem;font-weight:800;letter-spacing:.1em;text-transform:uppercase}
.live-state{display:flex;align-items:center;gap:7px;color:var(--green)}.live-state i{width:7px;height:7px;border-radius:50%;background:var(--green);box-shadow:0 0 14px var(--green)}
.radar{position:relative;display:grid;place-items:center;width:min(250px,76vw);aspect-ratio:1;margin:26px auto}.radar:before,.radar:after{content:"";position:absolute;border:1px solid var(--line);border-radius:50%}
.radar:before{inset:0;background:repeating-radial-gradient(circle,transparent 0 28px,var(--line) 29px 30px)}.radar:after{inset:18%;border-color:var(--accent);box-shadow:0 0 42px var(--accent-glow)}
.radar-ring{position:absolute;inset:7%;border-radius:50%;background:conic-gradient(from 220deg,transparent 0 13%,var(--accent) 15% 35%,#ff9e65 43%,transparent 55%);-webkit-mask:radial-gradient(circle,transparent 62%,#000 63% 69%,transparent 70%);mask:radial-gradient(circle,transparent 62%,#000 63% 69%,transparent 70%);filter:drop-shadow(0 0 10px var(--accent-glow))}
.radar-core{position:relative;z-index:2;display:grid;place-items:center;width:112px;height:112px;border:1px solid var(--line-strong);border-radius:50%;background:var(--panel-solid);box-shadow:var(--shadow-soft);text-align:center}
.radar-core strong{font-size:2.35rem;line-height:1}.radar-core span{color:var(--muted);font-size:.64rem;font-weight:850;letter-spacing:.15em;text-transform:uppercase}
.signal-wave{position:absolute;right:-5%;bottom:23%;width:110%;color:var(--accent);opacity:.17}.signal-wave polyline{fill:none;stroke:currentColor;stroke-width:2}
.endpoint-grid{position:relative;z-index:2;display:grid;grid-template-columns:repeat(2,minmax(0,1fr));gap:9px}.endpoint{border:1px solid var(--line);border-radius:12px;background:var(--panel);padding:10px}.endpoint span{display:block;color:var(--muted);font-size:.65rem;font-weight:750;text-transform:uppercase}.endpoint strong{display:block;margin-top:2px;font-size:.83rem;overflow-wrap:anywhere}.endpoint strong.online{color:var(--green)}
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
.support-banner{position:relative;display:grid;grid-template-columns:auto minmax(0,1fr) auto;align-items:center;gap:24px;overflow:hidden;border:1px solid rgba(40,120,255,.28);border-radius:var(--radius-lg);background:linear-gradient(120deg,var(--blue-soft),var(--panel) 55%);margin-top:68px;padding:30px 32px;box-shadow:var(--shadow)}
.support-banner:after{content:"";position:absolute;right:15%;bottom:-90px;width:220px;height:220px;border-radius:50%;background:var(--blue-soft);filter:blur(10px);pointer-events:none}.support-orb{position:relative;z-index:1;display:grid;place-items:center;width:58px;height:58px;border:1px solid rgba(40,120,255,.28);border-radius:18px;background:var(--panel-solid);color:var(--blue);box-shadow:0 12px 28px var(--blue-soft);font-size:1.45rem}.support-copy,.support-banner .button{position:relative;z-index:1}.support-copy h2{font-size:clamp(1.4rem,2.6vw,2rem)}.support-copy p{max-width:680px;margin:.55rem 0 0;color:var(--muted)}
.project-spotlight{position:relative;display:grid;grid-template-columns:auto minmax(0,1fr) auto;align-items:center;gap:26px;overflow:hidden;border:1px solid rgba(239,64,80,.3);border-radius:var(--radius-lg);background:linear-gradient(125deg,var(--accent-soft),var(--panel) 46%,var(--blue-soft));padding:30px 32px;box-shadow:var(--shadow)}
.project-spotlight:after{content:"";position:absolute;right:7%;bottom:-100px;width:220px;height:220px;border-radius:50%;background:var(--accent-glow);filter:blur(14px);pointer-events:none}.project-spotlight>*{position:relative;z-index:1}.project-content h2{max-width:650px;margin:.3rem 0 .55rem;font-size:clamp(1.45rem,2.7vw,2.1rem);letter-spacing:-.035em;line-height:1.08}.project-content p{max-width:700px;margin:0;color:var(--text-soft)}
.project-points{display:flex;flex-wrap:wrap;gap:7px;margin-top:15px}.project-points span{border:1px solid var(--line);border-radius:999px;background:var(--panel);color:var(--muted);padding:5px 9px;font-size:.72rem;font-weight:750}.project-action{min-width:190px;border-color:var(--accent);background:var(--accent);color:var(--button-text);box-shadow:0 12px 30px var(--accent-glow)}.project-action:hover{background:var(--accent-hover);color:var(--button-text)}
.page-intro{position:relative;overflow:hidden;border:1px solid var(--line-strong);border-radius:var(--radius-lg);background:linear-gradient(135deg,var(--panel-solid),var(--panel));padding:clamp(30px,5vw,58px);box-shadow:var(--shadow)}
.page-intro:after{content:"";position:absolute;right:-8%;top:-45%;width:380px;height:380px;border-radius:50%;background:var(--accent-glow);filter:blur(18px);pointer-events:none}.page-intro>*{position:relative;z-index:1}.page-intro h1{max-width:850px;margin:.55rem 0 .85rem;font-size:clamp(2.55rem,6vw,5.2rem);font-weight:780;letter-spacing:-.06em;line-height:.96}.page-intro h1 span{color:var(--accent)}.page-intro p{max-width:790px;margin:0;color:var(--text-soft);font-size:1.06rem}
.inline-account{display:inline-flex;align-items:center;gap:7px;margin-top:20px;color:var(--blue);font-weight:780;text-decoration:none}.inline-account:hover{text-decoration:underline;text-underline-offset:4px}
.docs-layout{display:grid;grid-template-columns:minmax(0,1fr) 255px;gap:38px;align-items:start}.article{min-width:0}.toc{position:sticky;top:108px;border:1px solid var(--line);border-radius:15px;background:var(--panel);padding:16px}.toc-title{margin-bottom:8px;color:var(--text);font-size:.75rem;font-weight:850;letter-spacing:.1em;text-transform:uppercase}.toc a{display:block;border-radius:8px;color:var(--muted);padding:7px 8px;font-size:.84rem;text-decoration:none}.toc a:hover{background:var(--accent-soft);color:var(--accent)}
.content-section{margin-top:54px;scroll-margin-top:110px}.content-section>p{color:var(--text-soft)}
.table-wrap{overflow:auto;border:1px solid var(--line);border-radius:var(--radius);background:var(--panel);box-shadow:var(--shadow-soft)}table{width:100%;min-width:760px;border-collapse:collapse}th,td{border-bottom:1px solid var(--line);padding:14px 16px;text-align:left;vertical-align:top}tr:last-child td{border-bottom:0}th{background:var(--panel-soft);color:var(--muted);font-size:.7rem;font-weight:850;letter-spacing:.08em;text-transform:uppercase}td{color:var(--text-soft)}td:first-child{color:var(--text);font-weight:680}td code{color:var(--accent)}
.payload-card{display:flex;flex-direction:column}.payload-head{display:flex;align-items:center;justify-content:space-between;gap:12px}.copy-button{border:1px solid var(--line);border-radius:9px;background:var(--panel-soft);color:var(--text);padding:6px 10px;font-size:.75rem;font-weight:800;cursor:pointer}.copy-button:hover,.copy-button.is-copied{border-color:var(--accent);background:var(--accent);color:#fff}.payload{min-height:140px;white-space:pre-wrap;overflow-wrap:anywhere;border-radius:12px;background:var(--code);color:var(--code-text);margin:12px 0 0;padding:17px;font-size:.81rem;line-height:1.65;user-select:text}
.note,.muted{color:var(--muted)}.note{font-size:.89rem}.callout{display:flex;gap:14px;border:1px solid var(--line);border-radius:var(--radius);background:var(--panel);padding:19px}.callout-mark{flex:0 0 auto;display:grid;place-items:center;width:32px;height:32px;border-radius:10px;background:var(--accent-soft);color:var(--accent);font-size:.7rem;font-weight:900}.callout strong{display:block}.callout p{margin:3px 0 0;color:var(--muted)}
.download-card{display:flex;flex-direction:column;min-height:280px}.download-card .filename{margin-top:auto;color:var(--text-soft);font-size:.76rem;overflow-wrap:anywhere}.download-card .button{margin-top:11px}.bundle{display:grid;grid-template-columns:minmax(0,1.2fr) minmax(280px,.8fr);gap:14px}.panel{display:flex;flex-direction:column;align-items:flex-start;min-height:205px;padding:26px}.panel p{color:var(--muted)}.panel .button{margin-top:auto}
.footer{border-top:1px solid var(--line);background:var(--bg-elevated);padding:52px 0 24px}.footer-grid{display:grid;grid-template-columns:1.3fr .6fr .9fr 1fr;gap:38px}.footer-brand{font-weight:780}.footer-brand strong{letter-spacing:.14em}.footer-profile p,.footer-column p{margin:.75rem 0 0;color:var(--muted);font-size:.88rem}.footer-column h2{margin:0 0 12px;color:var(--text);font-size:.72rem;font-weight:850;letter-spacing:.12em;text-transform:uppercase}.footer-column>a{display:block;width:max-content;max-width:100%;margin:6px 0;color:var(--text-soft);font-size:.88rem;text-decoration:none}.footer-column>a:hover{color:var(--accent)}.footer-support-link{color:var(--blue)!important;font-weight:760}.footer-note{max-width:220px}.developer-line{display:flex;align-items:baseline;flex-wrap:wrap;gap:0 5px;margin:4px 0!important}.developer-line span{color:var(--text);font-weight:720}.developer-line .developer-link{display:inline;margin:0;color:var(--blue);font-weight:680;text-decoration:underline;text-decoration-color:transparent;text-underline-offset:3px}.developer-line .developer-link:hover{text-decoration-color:currentColor}.footer-bottom{display:flex;align-items:center;justify-content:space-between;gap:20px;border-top:1px solid var(--line);margin-top:38px;padding-top:20px;color:var(--muted);font-size:.79rem}.footer-repo{display:inline-flex;gap:6px;color:var(--text-soft);font-weight:700;text-decoration:none}.footer-repo span{color:var(--accent)}.footer-repo:hover{color:var(--accent)}
.theme-option:focus-visible,.nav-link:focus-visible,.button:focus-visible,.copy-button:focus-visible,.toc a:focus-visible,a:focus-visible{outline:3px solid var(--blue-soft);outline-offset:3px}
@media(max-width:1020px){.nav-shell{grid-template-columns:auto 1fr}.nav-links{grid-column:1/-1;grid-row:2;justify-content:flex-start}.nav-tools{justify-self:end}.hero{grid-template-columns:1fr}.signal-panel{margin:0 20px 20px;min-height:430px}.quick-grid,.policy-strip{grid-template-columns:repeat(2,minmax(0,1fr))}.quick-step:nth-child(2),.policy-item:nth-child(2){border-right:0}.quick-step:nth-child(-n+2),.policy-item:nth-child(-n+2){border-bottom:1px solid var(--line)}.quick-step:nth-child(2):after{display:none}.docs-layout{grid-template-columns:1fr}.toc{position:static;display:flex;gap:4px;overflow:auto;order:-1}.toc-title{display:none}.toc a{flex:0 0 auto}.footer-grid{grid-template-columns:repeat(2,minmax(0,1fr))}}
@media(max-width:760px){.shell{width:min(100% - 24px,1180px)}.site-header{padding-top:7px}.nav-shell{gap:10px;padding:9px 10px 8px 12px;border-radius:18px}.site-logo-header{width:68px;height:31px}.site-logo-header img{width:98px}.brand-copy small{display:none}.theme-option b{display:none}.theme-option{width:31px;justify-content:center;padding:4px}.nav-links{justify-content:space-between;gap:2px}.nav-link{flex:1;padding:7px 5px;text-align:center;font-size:.78rem}main{padding:22px 0 62px}.hero{min-height:0}.hero-copy{padding:36px 23px}.hero h1{font-size:clamp(2.85rem,14vw,4.3rem)}.signal-panel{margin:0 10px 10px;padding:18px}.endpoint-grid{grid-template-columns:1fr 1fr}.section{margin-top:52px}.section-head{display:block}.section-head p{margin-top:10px}.grid,.grid.two,.bundle{grid-template-columns:1fr}.support-banner{grid-template-columns:1fr;margin-top:52px;padding:25px 22px}.support-orb{width:50px;height:50px}.support-banner .button{width:100%}.project-spotlight{grid-template-columns:1fr;padding:25px 22px}.project-action{width:100%}.page-intro{padding:34px 23px}.card,.panel{padding:20px}.footer-grid{grid-template-columns:1fr;gap:28px}.footer-bottom{display:block}.footer-bottom>span{display:block;margin-top:8px}.payload-head{align-items:flex-start}}
@media(max-width:480px){.brand-copy{display:none}.site-logo-header{width:64px;height:30px}.site-logo-header img{width:92px}.hero-badges{display:grid;grid-template-columns:1fr 1fr}.quick-grid,.policy-strip{grid-template-columns:1fr}.quick-step,.policy-item{border-right:0;border-bottom:1px solid var(--line)}.quick-step:nth-child(2){border-bottom:1px solid var(--line)}.quick-step:not(:last-child):after{content:"⌄";right:50%;top:auto;bottom:-12px;transform:translateX(50%)}.policy-item:nth-child(2){border-bottom:1px solid var(--line)}.endpoint-grid{grid-template-columns:1fr}.radar{width:220px}.radar-core{width:100px;height:100px}}
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
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="theme-color" content="#0d121a"><meta name="description" content="TDZ SSH TUNNEL OpenVPN transport portal"><title>TDZ • OVPN PORTAL</title><link rel="icon" type="image/svg+xml" href="$TDZ_OVPN_PUBLIC_PATH/assets/tdz-favicon.svg"><script src="$TDZ_OVPN_PUBLIC_PATH/assets/portal.js"></script><link rel="stylesheet" href="$TDZ_OVPN_PUBLIC_PATH/assets/portal.css"></head><body>
EOF
        tdz_openvpn_portal_write_header overview
        cat <<EOF
<main class="shell">
  <section class="hero">
    <div class="hero-copy">
      <div class="eyebrow"><span class="eyebrow-dot" aria-hidden="true"></span>TDZ SSH TUNNEL • OpenVPN suite</div>
      <h1>Fast when it can be.<br><span>Flexible when it must.</span></h1>
      <p class="lead">One clean portal for direct OpenVPN, HTTP, WebSocket and TLS adapter profiles—with the same trusted TDZ account across every route.</p>
      <div class="actions"><a class="button primary" href="$TDZ_OVPN_PUBLIC_PATH/download">Download profiles <span aria-hidden="true">↓</span></a><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/docs">Open setup guide <span aria-hidden="true">→</span></a></div>
      <div class="hero-badges"><span class="hero-badge">6 connection modes</span><span class="hero-badge">No stored password</span><span class="hero-badge">Shared account policy</span></div>
    </div>
    <aside class="signal-panel" aria-label="Configured gateway summary">
      <div class="signal-head"><span>Gateway signal</span><span class="live-state"><i aria-hidden="true"></i>Portal ready</span></div>
      <div class="radar"><span class="radar-ring" aria-hidden="true"></span><div class="radar-core"><strong>6</strong><span>routes ready</span></div></div>
      <svg class="signal-wave" viewBox="0 0 600 100" preserveAspectRatio="none" aria-hidden="true"><polyline points="0,62 65,62 92,38 122,82 158,54 203,54 230,18 258,76 292,48 330,48 358,67 390,28 424,72 458,48 600,48"></polyline></svg>
      <div class="endpoint-grid"><div class="endpoint"><span>Server</span><strong>$TDZ_OVPN_HOST</strong></div><div class="endpoint"><span>Access</span><strong class="online">HTTP + HTTPS</strong></div><div class="endpoint"><span>Identity</span><strong>TDZ account</strong></div><div class="endpoint"><span>Credentials</span><strong>Entered in client</strong></div></div>
    </aside>
  </section>

  <section class="section" aria-labelledby="quick-start-title">
    <div class="section-head"><div><div class="kicker">Quick start</div><h2 id="quick-start-title">From zero to connected in four steps</h2></div><p>New visitors can request an account first. Existing users can jump straight to the right profile.</p></div>
    <div class="quick-grid">
      <article class="quick-step"><b>01</b><strong>Get an account</strong><p>Contact support if you do not already have an active TDZ login.</p></article>
      <article class="quick-step"><b>02</b><strong>Pick a profile</strong><p>Start with direct UDP, then use TCP or an adapter when needed.</p></article>
      <article class="quick-step"><b>03</b><strong>Import it</strong><p>Open the profile in your compatible OpenVPN or injector client.</p></article>
      <article class="quick-step"><b>04</b><strong>Sign in</strong><p>Enter the same TDZ username and password when the client asks.</p></article>
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
    <div class="section-head"><div><div class="kicker">One account policy</div><h2 id="policy-title">The route changes. Your rules do not.</h2></div><p>OpenVPN participates in the same TDZ account lifecycle instead of creating a second identity system.</p></div>
    <div class="policy-strip"><article class="policy-item"><span>01</span><strong>Expiry</strong><p>Expired accounts are rejected.</p></article><article class="policy-item"><span>02</span><strong>Connection limit</strong><p>Concurrent sessions share the limit.</p></article><article class="policy-item"><span>03</span><strong>Traffic quota</strong><p>Usage returns to the TDZ counter.</p></article><article class="policy-item"><span>04</span><strong>Lock state</strong><p>Locked accounts cannot authenticate.</p></article></div>
  </section>
EOF
        tdz_openvpn_portal_write_support
        cat <<EOF
  <section class="section project-spotlight" aria-labelledby="tdz-project-title">
    <span class="site-logo site-logo-project" aria-hidden="true"><img src="$TDZ_OVPN_PUBLIC_PATH/assets/tdz-logo.jpg" alt=""></span>
    <div class="project-content"><div class="kicker">The open-source project behind this portal</div><h2 id="tdz-project-title">TDZ SSH TUNNEL powers both SSH and OpenVPN.</h2><p>This OpenVPN portal, its downloadable profiles, the OpenVPN services and the SSH account manager all belong to the same TDZ SSH TUNNEL server project. Want this complete system on your own VPS? Use the official GitHub repository for installation, source code and updates.</p><div class="project-points"><span>SSH account manager</span><span>OpenVPN suite</span><span>Server installer</span></div></div>
    <a class="button project-action" href="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT" target="_blank" rel="noopener noreferrer">Get TDZ SSH TUNNEL ↗</a>
  </section>
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
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="theme-color" content="#0d121a"><meta name="description" content="TDZ OpenVPN setup guide"><title>TDZ • OVPN PORTAL</title><link rel="icon" type="image/svg+xml" href="$TDZ_OVPN_PUBLIC_PATH/assets/tdz-favicon.svg"><script src="$TDZ_OVPN_PUBLIC_PATH/assets/portal.js"></script><link rel="stylesheet" href="$TDZ_OVPN_PUBLIC_PATH/assets/portal.css"></head><body>
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

      <section class="content-section" id="policy"><div class="kicker">Account policy</div><h2>Your existing TDZ login applies</h2><div class="grid two"><div class="callout"><span class="callout-mark">ID</span><div><strong>Username and password</strong><p>Profiles never contain credentials. Enter the active TDZ account after import.</p></div></div><div class="callout"><span class="callout-mark">BW</span><div><strong>Shared usage accounting</strong><p>OpenVPN traffic is reconciled against the same bandwidth quota.</p></div></div><div class="callout"><span class="callout-mark">EX</span><div><strong>Expiry and first use</strong><p>Pending activation and expiry follow the shared lifecycle.</p></div></div><div class="callout"><span class="callout-mark">CN</span><div><strong>Connection admission</strong><p>Session limits are checked before a connection is admitted.</p></div></div></div></section>

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
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="theme-color" content="#0d121a"><meta name="description" content="Download TDZ OpenVPN profiles"><title>TDZ • OVPN PORTAL</title><link rel="icon" type="image/svg+xml" href="$TDZ_OVPN_PUBLIC_PATH/assets/tdz-favicon.svg"><script src="$TDZ_OVPN_PUBLIC_PATH/assets/portal.js"></script><link rel="stylesheet" href="$TDZ_OVPN_PUBLIC_PATH/assets/portal.css"></head><body>
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
        "$TDZ_OVPN_PROFILES/portal.js" "$TDZ_OVPN_PROFILES/tdz-logo.jpg" \
        "$TDZ_OVPN_PROFILES/tdz-favicon.svg"
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
        tdz_detail "Account / Support" "@${TDZ_OVPN_SUPPORT_USERNAME} / https://t.me/${TDZ_OVPN_SUPPORT_USERNAME}" "$C_CYAN"
    else
        printf '  Server: %s\n  Portal: https://%s:%s%s/\n  Account / Support: @%s\n' \
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
        tdz_section "ACCOUNT AND SUPPORT CONTACT"
    fi
    echo -e "${C_DIM}Visitors without an account will see this Telegram contact on every portal page.${C_RESET}"
    if ! read -r -p "$(echo -e "${C_PROMPT}  Telegram username [@${current}]: ${C_RESET}")" input; then
        return 1
    fi
    input=${input:-$current}
    input=${input#@}
    if ! tdz_openvpn_valid_telegram_username "$input"; then
        echo -e "${C_RED}[ERROR] Use a valid Telegram username: 5-32 letters, numbers, or underscores; start with a letter.${C_RESET}"
        return 1
    fi
    if [[ "$input" == "$current" ]]; then
        echo -e "${C_YELLOW}[INFO] Support contact is already @${current}. Nothing was changed.${C_RESET}"
        return 0
    fi

    previous="$current"
    TDZ_OVPN_SUPPORT_USERNAME="$input"
    if tdz_openvpn_save_state && tdz_openvpn_generate_profiles &&
       tdz_openvpn_apply_private_permissions; then
        echo -e "${C_GREEN}[OK] Portal account/support contact changed to @${TDZ_OVPN_SUPPORT_USERNAME}.${C_RESET}"
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
    [[ "$mode" == "silent" ]] || echo -e "${C_GREEN}[OK] OpenVPN suite removed. TDZ accounts were preserved.${C_RESET}"
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
            tdz_row2 "${C_GRAY}SUPPORT${C_RESET}" "${C_CYAN}@${TDZ_OVPN_SUPPORT_USERNAME}${C_RESET}"
        fi
        tdz_box_divider
        tdz_menu1 "[ 1]" "Install or Repair OpenVPN"
        tdz_menu1 "[ 2]" "View Ports and Download Portal"
        tdz_menu1 "[ 3]" "Change Portal and Method Ports"
        tdz_menu1 "[ 4]" "Restore Default Ports (1180, 446-450)"
        tdz_menu1 "[ 5]" "Regenerate Download Profiles"
        tdz_menu1 "[ 6]" "Restart and Verify Services"
        tdz_menu1 "[ 7]" "Uninstall OpenVPN Suite"
        tdz_menu1 "[ 8]" "Change Account / Support Contact"
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
    echo -e "  ${C_DIM}Use the same TDZ username and password shown above.${C_RESET}"
}

tdz_openvpn_kill_user() {
    local username=${1:-} reason=${2:-policy}
    [[ -x "$TDZ_OVPN_RUNTIME" && -n "$username" ]] || return 0
    "$TDZ_OVPN_RUNTIME" kill-user "$username" "$reason" >/dev/null 2>&1 || true
}
