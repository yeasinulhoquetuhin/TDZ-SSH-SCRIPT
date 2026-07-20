#!/bin/bash
# TDZ SSH TUNNEL optional OpenVPN protocol module.
# This file is sourced by menu.sh; it does not execute actions on its own.

TDZ_OVPN_MODULE_VERSION="2026-07-20.4"
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
Telegram contact for account/support: @$TDZ_OVPN_SUPPORT_USERNAME (https://t.me/$TDZ_OVPN_SUPPORT_USERNAME)

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
      <span class="site-logo site-logo-header" aria-hidden="true"><img src="$TDZ_OVPN_PUBLIC_PATH/assets/tdz-logo.png" alt=""></span>
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
    <div class="kicker">Account &amp; support</div>
    <h2 id="account-support-title">No SSH/OVPN account yet? Start here.</h2>
    <p>An active SSH/OVPN account is required to sign in after importing a profile. Message the Telegram contact to request an account or get connection help.</p>
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
      <a class="footer-brand" href="$TDZ_OVPN_PUBLIC_PATH/"><span class="site-logo site-logo-footer" aria-hidden="true"><img src="$TDZ_OVPN_PUBLIC_PATH/assets/tdz-logo.png" alt=""></span><span><strong>TDZ</strong> OVPN PORTAL</span></a>
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
    base64 --decode > "$TDZ_OVPN_PROFILES/tdz-logo.png" <<'TDZ_OVPN_LOGO_EOF' || return 1
iVBORw0KGgoAAAANSUhEUgAABAcAAAQHCAYAAACAxABCAAAABHNCSVQICAgIfAhkiAAAAStpQ0NQ
U2tpYQAAKJF9kD9Lw0AYxn+Wgv8H0dEhYxelKuigLlUsOkmNYHVK0zQVmhiSlCK4+QX8EIKzowi6
CjoIgpvgRxAH1/qkQdIlvsd797vnHu7ufaEwhqJYBs+Pw1q1YhzVj43RT0Y0BmHZUUB+yPXznnrf
Fv7x5cV404lsrV/KZqjHdaUpnnNTbifcSPki4V4cxOKrhEOztiW+FpfcIW4MsR2Eif9FvOF1unb2
b6Yc//BA645ynm1OiQjoYHGOwT4rmqvaeXSJxT05YtqiiJpOKiKTUA5fSgtHTNK/9InLD9h86Pf7
95m29wi3azBxl2mldZiZhKfnTMt6GlihNZCKykKrBd83MF2H2Vfdc/LXyJzajEFtVc40XNXmSNnV
f20WRcuUWWL1Fx+iTfksoSHdAAAgAElEQVR4nOzd+XPc9YHn/1e3ZJ22LMv3jcHEGBtIBggwCcUm
2cxMEoZkqmZrd2qmav+A/X/21+/s7NRmh93N7rLk2k0YAhMOExsbbLDxfduyZd23uj/fH1pSDJgE
GxvJ/jweVV0tyXL7o7bU6s+z30fl/fffLwIAAACUVvP171Sr1bS2tqa5uTmVSmWhjgkAAAC4A4qi
yPT0dKamplKv1+c//rE40NzcnJ6enrS1tX3pBwgAAADceUNDQ+nv7//sODA3ckAcAAAAgHvT+Ph4
qtXqxz7W/MlPmptOYFoBAAAA3HtudL5fvcHnAQAAACUiDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAA
ACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUn
DgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAA
AEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJ
iQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMA
AABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQ
cuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIA
AAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAA
lJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4
AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAA
ACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUn
DgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAA
AEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJ
iQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMA
AABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQ
cuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIA
AAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAA
lJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4
AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAA
ACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUn
DgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAA
AEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJ
iQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMA
AABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQ
cuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIA
AAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAA
lJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4
AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAA
ACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUn
DgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAA
AEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJ
iQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMA
AABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQ
cuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIA
AAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAA
lJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4
AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAA
ACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUnDgAAAEDJiQMAAABQcuIAAAAAlJw4AAAAACUn
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
d4OR0Zn5xQibmipZu6Y1j+7uyhNPrMhXH+3KA9s6s359W7qXL0nz/Cvvn34F/tae31fS0pJ0djal
KJZk1cqWnD4znu7lN3418PPo6WnJ7t1d2fnQssbtVJKbP7TGcSVJkeGkei6p7kiqD6dI4yR/7tXH
oaGh9Pb25vjx43nvvfeyd+/eHDhwIOfPn7/nFiWkXK5evZrf/e53OXLkyC1vybl06dI8/vjj+Xf/
7t/lL/7iL7Jx48Y0NzcvmlfS545j7rqpqSk9PT1ZsWJF7rvvviSNUUCjo6Pp6+vL+fPnc/r06Zw4
cSKnTp3KiRMncvTo0Vy5ciUzM78PmtdPLejr6xMHAK4jDlACk0n9eFJ/O8npJJ9/+CEspJGRmVy6
PJHlXUvyVz9cn2e/sTJ/8tXuPLi9Myu6l2TJkrmhvnf2OCqVZMmSarq6mrOsa0mam6uZmbn5kTet
LZUsW9qclpbqbaVMJoUAACAASURBVDnmSiaT4lRS35tUVqRS3ZFU2pI0TiRWrVqVVatWZceOHfnG
N76RkydP5sCBA/mXf/mXvP/++7l8+bJFCbnrTE1N5fTp09m3b18uX758S7fR2dmZJ598Mv/+3//7
/MVf/EVWr149P3Vgsbt+REO1Wk13d3eWL1+ebdu25ZlnnpkfFXTu3LkcOXIk7733Xvbv358PP/ww
g4ODSRpTCw4ePJjLly9n8+bNC/nlACwq4gD3uHpSXElq+5L6R9YZ4K4yMVnPqlWt+bu/2ZxvPNOT
HV/pTGdnc6rVzzc//3Zra23K8mXNaWmpZOYWZhY0NVXS0vL5pxB8LsVoko+SYlWS5Uk2Ze5X29wJ
RHNzc1auXJmenp7s3LkzTz/9dF5//fUMDQ1lZmYm09PTnzk/+m5gS7ZyGRkZybFjx3Lq1KmMj4/f
0m2sW7cu3/ve9/Ld7343a9asWTSjBW7VXDCoVqtZsWJFuru7s3379jz99NO5dOlSDh8+nPfeey8H
DhzIgQMHcvbs2Rw7diwnT57Mrl270t7evtBfAsCiIA5wbyuGG9MJ6vtn1xnwJJq7x5rVrfnen69J
z4qWrFrZkubmhX0CX60mzc2Vz72o4SdVKpU0VSu3MJXgD6knuZbUDyWVtUm1O6l0f+a/39nZmZ07
d2bt2rW5du1ali1bdluPBu60oaGhnDx5MteuXbulv79ixYo8/fTTefbZZ++JMHAjc7Ggo6Mj27Zt
y5YtW/Knf/qnOXv2bPbv35/XX399fp2Cvr6+bNq0aaEPGWBREAe4h00kxdGktqexS0FsBcfdZWVP
S1b2NCbY34PP32+fYjrJ2aS2N8nKpLo7qXz2K4HVanV+JEFRFLc8nHp6ejpDQ0O5du1arly5kqtX
r2ZoaCiTk5OZmprKxMRExsbGMjo6mqIo0tnZmc7OzrS3t6etrS0dHR1ZsWJFVq5cmZUrV6a7uztL
ly5NU1PTrd0P3POKosi1a9dy9OjR9PX13dJtrF27Nt/85jfz4IMPlmIbz0qlkubm5nR3d6erqysP
PPBAnnzyyRw+fHh+scMvS1EU848bQ0NDGRkZ+dhlbGwsk5OTmZyczPj4eMbGxjI2NpZ6vZ7W1ta0
trZmyZIlaW5uTlNTU5YsWZKmpqb59+c+1tbWlqVLl6azs3P+uqOjY/66TI8x9Xo9AwMD6e3tTV9f
X0ZGRjI6Ojq/G8bg4GDGx8ezbNmy9PT0ZOnSpVm6dGk6OjrS3d2dtWvXZvXq1WmZW+wG7nH3/m8F
SqrWWHiwti8pTiaZWugDgpsmCNyEYjzJ8cYoocqKpLI1yWdPFbiVldinpqbS29s7v9DZiRMncuXK
lQwMDMxfRkdHMzU1lenp6UxNTWV8fHx+6Hd7e3va29vT2tqalpaWtLe3Z9myZfNzplesWJFNmzZl
x44d2bFjRzZt2pSlS5d+6a/sFkWRycnJjIyMZGrKY2fSWNV/2bJlC36CUKvVMjg4mN7e3oyNjd30
369Wq1m+fHk2b96c5cuX34EjXNyq1Wo6OjqyY8eObN26NaOjo3d0QcKZmZn09fXlzJkzOX/+fM6f
P5+zZ8+mr68vo6OjGRsb+1gEmJiYyNTUVKampjI5OZmJiYlMTEykXq+npaUlLS0tn4oBc5dqtTr/
Z62trWlvb09HR8d8jJx7/Ons7MzKlSuzZs2arFq1KmvWrMnq1auzcuXKeyJOzt3nc7tYHD9+PKdO
ncrly5fnQ8D19/nIyEgmJibS2dmZrq6udHR0pKOjYz6wrFmzJtu2bcvOnTvzla98JZs3b05XV9dd
fz/BZxEHuDcVw0n9YONSDMd0AiiDoaQ4nNQ3JJWexuULGh8fz/nz53P48OEcOnQoR44cyenTp3Pm
zJlcvHhxfqX46/dqv971709OTs4viDbn+hXZm5qa0t3dnS1btmTr1q3Zvn17/uRP/iSPP/54Nm3a
lNbW1hse4+2OB7VaLYcPH87LL7+cY8eO3fBrudG/+cmv/Y99zq38+ULcxurVq/Pss8/mm9/8Zlau
XHnD2/uyTE9PzweoW9He3p7169enp6enFKMGPkulUpk/ab4TPz9zozsOHDiQ999/P6dOnUpvb+/8
CKO5rRav/z670QiG6z8293//eY/3+s+7/u3m5ub5V8m7u7vnd4Do6enJhg0bsm3btmzdujUbN27M
6tWr097evuinntTr9QwNDeXo0aPZt29fDhw4kNOnT+fSpUs5f/58+vv7P7ZjxY3u9/Hx8Vy9ejXJ
x++vpqamdHV1ZfPmzdm6dWu2bt2aJ598Mk8//XS2bNmy4MEQbrfy/mbgHjaRFMcaQ4yLy7FtIZRE
MZPkQlJ/N6msTqqP/MHpBZ+lXq+nv78/H374Yfbs2ZMDBw7MR4Fr165lZmbmlocj/6F4UKvVcuXK
lVy5ciX79u3L0qVLc//99+eJJ57Is88+m6effjpbt279zEhwu9Tr9Zw/fz6//OUv8+abb97Rf2ux
a29vz5/+6Z/mm9/85h2/3z+Per2eycnJj53o3Iz29vasWbPGWhuzbudJb61WS29vb/bu3ZvXXnst
Bw4cyLFjx3Lx4sVMTk5+ZkC8WZ/373/W59VqtUxNTaWvr+9TcbKrqyvr16/PunXrsmbNmmzYsCG7
du3Krl278sADD2T58uWLaleL6enpnD9/Pvv27cvbb7+dgwcP5siRI7lw4cJN3+efFWrmtr68du1a
3nvvvbS2tubXv/51nnjiiXzrW9/KN77xDZGAe4o4wD1mbneCd00ngDIqxpOcSOrvJZVVSWVLPu+v
urmT83feeSevvfZa9u/fnyNHjqS3tzfT09Nfyvzk65/MDg0NzZ9gvP322/n617+eP/uzP8s3vvGN
rFu37o4Oay2KIvV6PbVaeeNqU1NTtmzZkj/7sz/LE088kc7OzoU+pNRqtczMzKRev/mtRLkz5mLi
O++8k//3//5f3nzzzRw+fDiDg4Nf+poGn9eNTpprtVr6+vrS19eXQ4cOpVKppLW1NVu2bMn999+f
Rx55JC+88EK+9rWvLfjuDvV6PdeuXctbb72Vn//853n77bdz9OjRjIyM3LH7fO52x8fH88EHH+TE
iRP53e9+l1dffTV/+Zd/meeee27BRxbB7SAOcG8pRhqrltcPNt42nQDKpxhK6keSyubZ6QU33r3g
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
5bHHHsvXvva1bN26NcuWLUtbW9vHHounpqYyNjaW8fHxDA8P59y5czl48GDef//9vPfeezl27Ngt
R5Xp6ekcOXIkL774YrZu3ZqnnnoqLS0tt3Rb8GXzW4C7WzHcmFNcPzE7hBjgE4rxJCdTrx3OyZMD
+dnPfpa33norg4ODt3yT3d3d+epXv5rnnnsuTz/99PwQ7Y6Ojk/NMb1++G1LS0s6Ozs/9YpjURSZ
nJzMuXPnsnfv3vzqV7/Ka6+9ltOnTy+KkQGtra1Zs2ZNNm/enHXr1mXZsmXp6Oj42Kuacycw1799
p4ceX716NXv27Mm77757y6/4tba2ZteuXfmrv/qrPPPMM+nq6rrNR3l7LV26NBs3bvzCr0aOjo7m
3XffzcDAQD788MM8//zz+frXv56enp5FN51iMRgfH8/Ro0dz8ODBDAwM3PTfb2pqypo1a/Lss8/m
e9/7Xp5++uls2bIlbW1tN/w5+ayfnU+eZN5o9ML1H6vVavOvkg8NDeXatWs5f/58jh8/ntOnT+fM
mTPzb/+xk+Hx8fGcOHEi/f39Wbt27ef5sm/Z6Oho3nvvvU99PTfS2tqahx56KM8880yeeuqpPPLI
I9m2bVu6uro+9nh8/X3a1tb2scC2a9euPPvsszl79mwOHjyY//t//29+9rOf5eLFi7d0/OPj43n7
7bfzy1/+Mvfdd5/pBdw1xAHuYpONrQvrB2cXIbw79xUG7rR6kr70X3snb71Zz+uvv5Le3t5buqWO
jo7s2LEj3/nOd/Ld7343jz32WFauXHnTJ8Kf/NxKpZL29vZs3749GzduzO7du7N79+689NJL2bt3
7xce6nor2tvb85WvfCW7du3KQw89lAcffDCbN2/OypUr09nZOT/0ubm5OdVqdT4MXH+5k3FgeHg4
r776ag4dOnTL26tVq9Vs2bIlzz//fP71v/7XWb169W0+ytuvra0t27Zty8MPP5zDhw+nv7//lm9r
fHw8H374YS5cuJBDhw7lueeey3PPPZdHHnlk/vuahoGBgezfvz8XLly46b+7ZMmSPPDAA/nRj36U
H/3oR9m1a1c6Oztvy8/HHwsL1Wo1S5YsSWdn5/wJfb1ez8TERPr6+nLx4sWcPn06R48ezbFjx3Ls
2LEcPXo0V69e/dQUp5GRkRw6dCiXLl3Kjh077nj8+2NRoFqtZs2aNXnuuefywx/+ME899VQ2bNgw
v2DnH3P95zQ1NWXZsmXZuXNnHnjggezcuTNbtmzJ//gf/yOHDx++6UhbFEX6+/vzq1/9Kv/qX/2r
rF+/3sgc7gq+S7l7FUONUQPFmSSLd4EaYOHVaxM5dfL9/Oa18zl69NQtLWq1dOnSPPXUU/mbv/mb
fPvb387GjRuzZMmS2/oEuVKppKOjIw8//HDWrFmT+++/Pz/5yU/yyiuv5MKFCze1HsEXsXHjxvz1
X/912tvb88gjj2Tz5s1Zvnx5mpubP/b1LtRCdnNbh/3v//2/s2fPnoyMjNzS7axZsybf/e538/3v
fz+bN2++K14xr1ar2bhxY55++uns2bPnC8WBpHESMzAwkDfeeCNHjhzJa6+9lkcffTRf/epX8+ij
j87Phy9zKKjVarl06VIOHDhw02Fx7v/r3/ybf5O//du/zf33358lS5bcoSP9bJ88Ee7s7JxfJ+Xx
xx/P2NhYent7c/r06Rw5ciQHDhzI3r17c+TIkfmfr6mpqVy4cCFnz57N+Pj4gm7z2dbWlkcffTTP
P/98vve972Xnzp3p6Oj4wo9JlUolra2t2blzZ1asWJHNmzfnxz/+cd56662bXuNjeno6J0+ezLvv
vpvHHnvsroiPIA5wl5poTCWofdCYWmDrQuAPGBqazsFDvXn/vXMZHLz5E8m2trY89thj+du//dv8
4Ac/yOrVq+/oifHcK2Lf+c53snbt2qxcuTI/+clPcvr06Tu+Onpzc3MefPDBbNmyJR0dHZ857Hmh
1Gq1nDp1Ki+//HL++Z//OVevXr2l2+nq6sozzzyTH/7wh9m5c+eCnLDdqq6urjz66KP52te+lrNn
z97SMPdPmpmZyeXLl9Pb25t33nknmzZtyvbt27N9+/bs2rUrO3fuzKZNm+ZHjpQpFkz9/+zd53Nb
Z5rn/e9BzoEEwCgmiVSyRMnKwZJjyzl2T83U7szuVE3VVu2fs6/23TxVz7O7tV1dttqy1bbl0G25
JVlWzqIoUswkQJDIGec8LyhgZFu2BYgUAOr6VLElU43DGyB4eO7fue7rzuUIhULMzc1VvI2e2+3m
0KFDvPnmmzULBn5J6efaYDDgcrlwOp309fWxf/9+pqenuXbtGufOnePs2bOcP3+ecDhMOp1mfHyc
SCRSs3DAZrOxb98+/uVf/oWXX36ZlpaWZX8/GgwG2tvbeffdd/F4PORyOc6cOUM2m63oOPF4nO++
+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
ybTqewoHRERERERERAKIRhmKiIiIiIiIyCoKB0REREREREQCiI4ViIiIiIiIiAQ4HSsQERERERER
kVUUDoiIiIiIiIgEOIUDIiIiIiIiIgFO4YCIiIiIiIhIAFFDQhERERERERFZReGAiIiIiIiISADR
tAIRERERERERWUXhgIiIiIiIiEiAUzggIiIiIiIiEuAUDoiIiIiIiIgEOIUDIiIiIiIiIgFO4YCI
iIiIiIhIADGZTKu+p3BAREREREREJIBolKGIiIiIiIiIrKJwQERERERERCSA6FiBiIiIiIiISIDT
sQIRERERERERWUXhgIiIiIiIiEiAUzggIiIiIiIiEuAUDoiIiIiIiIgEOIUDIiIiIiIiIgFO4YCI
iIiIiIhIgFM4ICIiIiIiIhLgFA6IiIiIiIiIBDiFAyIiIiIiIiIBTuGAiIiIiIiISIBTOCAiIiIi
IiIS4BQOiIiIiIiIiAQ4hQMiIiIiIiIiAcRkMq36nsIBERERERERkQDi8/lWfU/hgIiIiIiIiEgA
UeWAiIiIiIiISIBT5YCIiIiIiIiIrKJwQERERERERCTAKRwQERERERERCXAKB0REREREREQCnMIB
ERERERERkQCncEBEREREREQkwCkcEBEREREREQlwCgdEREREREREApzCAREREREREZEAp3BARERE
REREJMApHBAREREREREJcAoHRERERERERAKcwgERERERERGRAGIymVZ9T+GAiIiIiIiISADx+Xyr
vqdwQERERERERCSAqHJAREREREREJMCpckBEREREREREVlE4ICIiIiIiIhLgFA6IiIiIiIiIBDiF
AyIiIiIiIiIBTuGAiIiIiIiISADRtAIRERERERERWUXhgIiIiIiIiEgA0ShDEREREREREVlF4YCI
iIiIiIhIgFM4ICIiIiIiIhLgFA6IiIiIiIiIBDiFAyIiIiIiIiIBTuGAiIiIiIiISAAxmUyrvqdw
QERERERERCSAaJShiIiIiIiISIBT5YCIiIiIiIhIgFPlgIiIiIiIiEiAU+WAiIiIiIiISIBT5YCI
iIiIiIiIrKJwQERERERERCSA6FiBiIiIiIiISIDTsQIRERERERERWUXhgIiIiIiIiEiAUzggIiIi
IiIiEkDUc0BEREREREQkwKnngIiIiIiIiIisonBAREREREREJMApHBAREREREREJIOo5ICIiIiIi
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
TDZ_OVPN_LOGO_EOF
    {
        printf '%s' '<svg xmlns="http://www.w3.org/2000/svg" viewBox="0 0 350 350"><defs><clipPath id="icon"><rect width="350" height="350" rx="88"/></clipPath></defs><g clip-path="url(#icon)"><image x="-155" y="-330" width="1031" height="1031" href="data:image/png;base64,'
        base64 -w 0 "$TDZ_OVPN_PROFILES/tdz-logo.png" || return 1
        printf '%s\n' '"/></g></svg>'
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
.site-logo{position:relative;display:block;flex:0 0 auto;overflow:hidden;border:1px solid rgba(19,28,42,.14);border-radius:13px;background:#fff;box-shadow:0 7px 20px rgba(16,24,38,.12)}
.site-logo img{position:absolute;top:50%;left:50%;display:block;width:124px;max-width:none;height:auto;transform:translate(-32%,-50%)}
.site-logo-header{width:42px;height:42px}.site-logo-footer{width:40px;height:40px;border-radius:12px}.site-logo-footer img{width:118px}
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
.support-banner:after{content:"";position:absolute;right:15%;bottom:-90px;width:220px;height:220px;border-radius:50%;background:var(--blue-soft);filter:blur(10px);pointer-events:none}.support-orb{position:relative;z-index:1;display:grid;place-items:center;width:58px;height:58px;border:1px solid rgba(40,120,255,.28);border-radius:18px;background:var(--panel-solid);color:var(--blue);box-shadow:0 12px 28px var(--blue-soft)}.support-orb svg{width:29px;height:29px}.support-copy,.support-banner .button{position:relative;z-index:1}.support-copy h2{font-size:clamp(1.4rem,2.6vw,2rem)}.support-copy p{max-width:680px;margin:.55rem 0 0;color:var(--muted)}
.project-spotlight{display:grid;grid-template-columns:minmax(0,1fr) auto;align-items:center;gap:28px;border:1px solid var(--line);border-radius:var(--radius);background:var(--panel);padding:28px 30px}.project-spotlight h2{margin:.3rem 0 .55rem;font-size:clamp(1.35rem,2.6vw,1.9rem);letter-spacing:-.025em}.project-spotlight p{margin:0;color:var(--muted)}
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
@media(max-width:1020px){.nav-shell{grid-template-columns:auto 1fr}.nav-links{grid-column:1/-1;grid-row:2;justify-content:flex-start}.nav-tools{justify-self:end}.quick-grid,.policy-strip{grid-template-columns:repeat(2,minmax(0,1fr))}.quick-step:nth-child(2),.policy-item:nth-child(2){border-right:0}.quick-step:nth-child(-n+2),.policy-item:nth-child(-n+2){border-bottom:1px solid var(--line)}.quick-step:nth-child(2):after{display:none}.docs-layout{grid-template-columns:1fr}.toc{position:static;display:flex;gap:4px;overflow:auto;order:-1}.toc-title{display:none}.toc a{flex:0 0 auto}.footer-grid{grid-template-columns:repeat(2,minmax(0,1fr))}}
@media(max-width:760px){.shell{width:min(100% - 24px,1180px)}.site-header{padding-top:7px}.nav-shell{gap:10px;padding:9px 10px 8px 12px;border-radius:18px}.site-logo-header{width:40px;height:40px}.site-logo-header img{width:118px}.brand-copy small{display:none}.theme-option b{display:none}.theme-option{width:31px;justify-content:center;padding:4px}.nav-links{justify-content:space-between;gap:2px}.nav-link{flex:1;padding:7px 5px;text-align:center;font-size:.78rem}main{padding:22px 0 62px}.hero{min-height:0}.hero-copy{padding:36px 23px}.hero h1{font-size:clamp(2.85rem,14vw,4.3rem)}.section{margin-top:52px}.section-head{display:block}.section-head p{margin-top:10px}.grid,.grid.two,.bundle{grid-template-columns:1fr}.support-banner{grid-template-columns:1fr;margin-top:52px;padding:25px 22px}.support-orb{width:50px;height:50px}.support-orb svg{width:25px;height:25px}.support-banner .button{width:100%}.project-spotlight{grid-template-columns:1fr;padding:24px 22px}.page-intro{padding:34px 23px}.card,.panel{padding:20px}.footer-grid{grid-template-columns:1fr;gap:28px}.footer-bottom{display:block}.footer-bottom>span{display:block;margin-top:8px}.payload-head{align-items:flex-start}}
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
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="theme-color" content="#0d121a"><meta name="description" content="TDZ SSH TUNNEL OpenVPN transport portal"><title>TDZ • OVPN PORTAL</title><link rel="icon" type="image/svg+xml" href="$TDZ_OVPN_PUBLIC_PATH/assets/tdz-favicon.svg"><script src="$TDZ_OVPN_PUBLIC_PATH/assets/portal.js"></script><link rel="stylesheet" href="$TDZ_OVPN_PUBLIC_PATH/assets/portal.css"></head><body>
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
        "$TDZ_OVPN_PROFILES/portal.js" "$TDZ_OVPN_PROFILES/tdz-logo.png" \
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
        tdz_detail "Telegram Contact" "@${TDZ_OVPN_SUPPORT_USERNAME} / https://t.me/${TDZ_OVPN_SUPPORT_USERNAME}" "$C_CYAN"
    else
        printf '  Server: %s\n  Portal: https://%s:%s%s/\n  Telegram Contact: @%s\n' \
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
        tdz_section "TELEGRAM CONTACT USERNAME"
    fi
    echo -e "${C_DIM}This Telegram username is shown for account requests and support on every portal page.${C_RESET}"
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
        echo -e "${C_YELLOW}[INFO] Telegram contact is already @${current}. Nothing was changed.${C_RESET}"
        return 0
    fi

    previous="$current"
    TDZ_OVPN_SUPPORT_USERNAME="$input"
    if tdz_openvpn_save_state && tdz_openvpn_generate_profiles &&
       tdz_openvpn_apply_private_permissions; then
        echo -e "${C_GREEN}[OK] Portal Telegram contact changed to @${TDZ_OVPN_SUPPORT_USERNAME}.${C_RESET}"
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
            tdz_row2 "${C_GRAY}TELEGRAM${C_RESET}" "${C_CYAN}@${TDZ_OVPN_SUPPORT_USERNAME}${C_RESET}"
        fi
        tdz_box_divider
        tdz_menu1 "[ 1]" "Install or Repair OpenVPN"
        tdz_menu1 "[ 2]" "View Ports and Download Portal"
        tdz_menu1 "[ 3]" "Change Portal and Method Ports"
        tdz_menu1 "[ 4]" "Restore Default Ports (1180, 446-450)"
        tdz_menu1 "[ 5]" "Regenerate Download Profiles"
        tdz_menu1 "[ 6]" "Restart and Verify Services"
        tdz_menu1 "[ 7]" "Uninstall OpenVPN Suite"
        tdz_menu1 "[ 8]" "Change Telegram Contact Username"
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
