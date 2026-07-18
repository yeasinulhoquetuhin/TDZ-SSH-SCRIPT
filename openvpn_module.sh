#!/bin/bash
# TDZ SSH TUNNEL optional OpenVPN protocol module.
# This file is sourced by menu.sh; it does not execute actions on its own.

TDZ_OVPN_MODULE_VERSION="2026-07-18.3"
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
TDZ_OVPN_PORTAL_PORT=1180
TDZ_OVPN_FIXED_SSL_PORT=446
TDZ_OVPN_FIXED_TCP_PORT=447
TDZ_OVPN_FIXED_UDP_PORT=448
TDZ_OVPN_FIXED_HTTP_PORT=449
TDZ_OVPN_FIXED_WSS_PORT=450
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
TDZ_OVPN_TCP_SUBNET="10.87.0.0"
TDZ_OVPN_UDP_SUBNET="10.88.0.0"
TDZ_OVPN_SERVICE_USER_CREATED=0
TDZ_OVPN_SERVICE_GROUP_CREATED=0

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
            TCP_PORT) TDZ_OVPN_TCP_PORT="$value" ;;
            UDP_PORT) TDZ_OVPN_UDP_PORT="$value" ;;
            HTTP_PORT) TDZ_OVPN_HTTP_PORT="$value" ;;
            WSS_PORT) TDZ_OVPN_WSS_PORT="$value" ;;
            SSL_PORT) TDZ_OVPN_SSL_PORT="$value" ;;
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
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_TCP_PORT" || return 1
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_UDP_PORT" || return 1
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_HTTP_PORT" || return 1
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_WSS_PORT" || return 1
    tdz_openvpn_valid_saved_port "$TDZ_OVPN_SSL_PORT" || return 1
    tdz_openvpn_valid_subnet "$TDZ_OVPN_TCP_SUBNET" || return 1
    tdz_openvpn_valid_subnet "$TDZ_OVPN_UDP_SUBNET" || return 1
    [[ "$TDZ_OVPN_TCP_SUBNET" != "$TDZ_OVPN_UDP_SUBNET" ]] || return 1
    [[ "$TDZ_OVPN_TCP_PORT" != "$TDZ_OVPN_UDP_PORT" &&
       "$TDZ_OVPN_TCP_PORT" != "$TDZ_OVPN_HTTP_PORT" &&
       "$TDZ_OVPN_TCP_PORT" != "$TDZ_OVPN_WSS_PORT" &&
       "$TDZ_OVPN_TCP_PORT" != "$TDZ_OVPN_SSL_PORT" &&
       "$TDZ_OVPN_UDP_PORT" != "$TDZ_OVPN_HTTP_PORT" &&
       "$TDZ_OVPN_UDP_PORT" != "$TDZ_OVPN_WSS_PORT" &&
       "$TDZ_OVPN_UDP_PORT" != "$TDZ_OVPN_SSL_PORT" &&
       "$TDZ_OVPN_HTTP_PORT" != "$TDZ_OVPN_WSS_PORT" &&
       "$TDZ_OVPN_HTTP_PORT" != "$TDZ_OVPN_SSL_PORT" &&
       "$TDZ_OVPN_WSS_PORT" != "$TDZ_OVPN_SSL_PORT" ]]
}

tdz_openvpn_needs_refresh() {
    tdz_openvpn_is_installed || return 1
    tdz_openvpn_load_state || return 0
    tdz_openvpn_ports_match_fixed_mapping || return 0
    [[ "$TDZ_OVPN_SAVED_VERSION" != "$TDZ_OVPN_MODULE_VERSION" ]]
}

tdz_openvpn_save_state() {
    local tmp
    mkdir -p "$TDZ_OVPN_ROOT"
    tmp="${TDZ_OVPN_STATE}.tmp"
    {
        printf 'VERSION=%s\n' "$TDZ_OVPN_MODULE_VERSION"
        printf 'HOST=%s\n' "$TDZ_OVPN_HOST"
        printf 'TCP_PORT=%s\n' "$TDZ_OVPN_TCP_PORT"
        printf 'UDP_PORT=%s\n' "$TDZ_OVPN_UDP_PORT"
        printf 'HTTP_PORT=%s\n' "$TDZ_OVPN_HTTP_PORT"
        printf 'WSS_PORT=%s\n' "$TDZ_OVPN_WSS_PORT"
        printf 'SSL_PORT=%s\n' "$TDZ_OVPN_SSL_PORT"
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
    case "$port" in
        "$TDZ_OVPN_FIXED_SSL_PORT"|"$TDZ_OVPN_FIXED_TCP_PORT"|"$TDZ_OVPN_FIXED_UDP_PORT"|\
        "$TDZ_OVPN_FIXED_HTTP_PORT"|"$TDZ_OVPN_FIXED_WSS_PORT") return 0 ;;
        *) tdz_openvpn_valid_generated_port "$port" ;;
    esac
}

tdz_openvpn_apply_fixed_port_mapping() {
    TDZ_OVPN_SSL_PORT="$TDZ_OVPN_FIXED_SSL_PORT"
    TDZ_OVPN_TCP_PORT="$TDZ_OVPN_FIXED_TCP_PORT"
    TDZ_OVPN_UDP_PORT="$TDZ_OVPN_FIXED_UDP_PORT"
    TDZ_OVPN_HTTP_PORT="$TDZ_OVPN_FIXED_HTTP_PORT"
    TDZ_OVPN_WSS_PORT="$TDZ_OVPN_FIXED_WSS_PORT"
}

tdz_openvpn_ports_match_fixed_mapping() {
    [[ "$TDZ_OVPN_SSL_PORT" == "$TDZ_OVPN_FIXED_SSL_PORT" &&
       "$TDZ_OVPN_TCP_PORT" == "$TDZ_OVPN_FIXED_TCP_PORT" &&
       "$TDZ_OVPN_UDP_PORT" == "$TDZ_OVPN_FIXED_UDP_PORT" &&
       "$TDZ_OVPN_HTTP_PORT" == "$TDZ_OVPN_FIXED_HTTP_PORT" &&
       "$TDZ_OVPN_WSS_PORT" == "$TDZ_OVPN_FIXED_WSS_PORT" ]]
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

tdz_openvpn_prepare_gateway_certificate() {
    local shared_cert=${SSL_CERT_CHAIN_FILE:-} shared_key=${SSL_CERT_KEY_FILE:-}
    local cert_hash key_hash host_check="-checkhost"
    cp "$TDZ_OVPN_PKI/server.crt" "$TDZ_OVPN_PKI/gateway.crt"
    cp "$TDZ_OVPN_PKI/server.key" "$TDZ_OVPN_PKI/gateway.key"

    if [[ -r "$shared_cert" && -r "$shared_key" ]]; then
        cert_hash=$(openssl x509 -in "$shared_cert" -pubkey -noout 2>/dev/null | openssl sha256 2>/dev/null || true)
        key_hash=$(openssl pkey -in "$shared_key" -pubout 2>/dev/null | openssl sha256 2>/dev/null || true)
        [[ "$TDZ_OVPN_HOST" =~ ^[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+$ ]] && host_check="-checkip"
        if [[ -n "$cert_hash" && "$cert_hash" == "$key_hash" ]] &&
           openssl x509 -in "$shared_cert" -checkend 86400 -noout >/dev/null 2>&1 &&
           openssl x509 -in "$shared_cert" "$host_check" "$TDZ_OVPN_HOST" -noout >/dev/null 2>&1; then
            cp "$shared_cert" "$TDZ_OVPN_PKI/gateway.crt"
            cp "$shared_key" "$TDZ_OVPN_PKI/gateway.key"
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
    local host_check="-checkhost"
    [[ "$TDZ_OVPN_HOST" =~ ^[0-9]+\.[0-9]+\.[0-9]+\.[0-9]+$ ]] && host_check="-checkip"
    [[ -s "$TDZ_OVPN_PKI/ca.crt" && -s "$TDZ_OVPN_PKI/ca.key" &&
       -s "$TDZ_OVPN_PKI/server.crt" && -s "$TDZ_OVPN_PKI/server.key" &&
       -s "$TDZ_OVPN_PKI/tls-crypt.key" ]] &&
        tdz_openvpn_cert_key_match "$TDZ_OVPN_PKI/ca.crt" "$TDZ_OVPN_PKI/ca.key" &&
        tdz_openvpn_cert_key_match "$TDZ_OVPN_PKI/server.crt" "$TDZ_OVPN_PKI/server.key" &&
        openssl verify -CAfile "$TDZ_OVPN_PKI/ca.crt" "$TDZ_OVPN_PKI/server.crt" >/dev/null 2>&1 &&
        openssl x509 -checkend 604800 -noout -in "$TDZ_OVPN_PKI/server.crt" >/dev/null 2>&1 &&
        openssl x509 -in "$TDZ_OVPN_PKI/server.crt" "$host_check" "$TDZ_OVPN_HOST" -noout >/dev/null 2>&1
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
}

tdz_openvpn_write_server_config() {
    local instance=$1 proto=$2 port=$3 subnet=$4 pam_plugin=$5 config
    config="$TDZ_OVPN_ROOT/server-${instance}.conf"
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
        echo "cipher AES-256-GCM"
        if tdz_openvpn_has_modern_cipher_option; then
            echo "data-ciphers AES-256-GCM:AES-128-GCM"
            echo "data-ciphers-fallback AES-256-GCM"
            echo "allow-compression no"
        else
            echo "ncp-ciphers AES-256-GCM:AES-128-GCM"
        fi
        echo "auth SHA256"
        echo "keepalive 10 60"
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
ExecStart=/usr/bin/python3 $TDZ_OVPN_PORTAL --listen 0.0.0.0 --port $TDZ_OVPN_PORTAL_PORT --root $TDZ_OVPN_PORTAL_BASE
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
CapabilityBoundingSet=
AmbientCapabilities=
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
filter_del() { while iptables -C "\$@" >/dev/null 2>&1; do iptables -D "\$@"; done; }
nat_del() { while iptables -t nat -C "\$@" >/dev/null 2>&1; do iptables -t nat -D "\$@"; done; }

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
    filter_add INPUT -i tun-tdz-tcp -j DROP
    filter_add INPUT -i tun-tdz-udp -j DROP
    for subnet in "\$TCP_SUBNET" "\$UDP_SUBNET"; do
        filter_add FORWARD -s "\$subnet" -j ACCEPT
        filter_add FORWARD -d "\$subnet" -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
        nat_add POSTROUTING -s "\$subnet" -j MASQUERADE
    done
    for source in "\$TCP_SUBNET" "\$UDP_SUBNET"; do
        for destination in "\$TCP_SUBNET" "\$UDP_SUBNET"; do
            filter_add FORWARD -s "\$source" -d "\$destination" -j DROP
        done
    done
    STARTING=0
else
    filter_del INPUT -p tcp -m multiport --dports "\$TCP_PORT,\$HTTP_PORT,\$WSS_PORT,\$SSL_PORT,\$PORTAL_PORT" -j ACCEPT
    filter_del INPUT -p udp --dport "\$UDP_PORT" -j ACCEPT
    filter_del INPUT -i tun-tdz-tcp -j DROP
    filter_del INPUT -i tun-tdz-udp -j DROP
    for subnet in "\$TCP_SUBNET" "\$UDP_SUBNET"; do
        filter_del FORWARD -s "\$subnet" -j ACCEPT
        filter_del FORWARD -d "\$subnet" -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT
        nat_del POSTROUTING -s "\$subnet" -j MASQUERADE
    done
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
    cat <<EOF
client
dev tun
setenv CLIENT_CERT 0
ignore-unknown-option data-ciphers data-ciphers-fallback block-ipv6
resolv-retry infinite
nobind
persist-key
persist-tun
remote-cert-tls server
verify-x509-name tdz-openvpn-server name
auth-user-pass
auth-retry interact
cipher AES-256-GCM
data-ciphers AES-256-GCM:AES-128-GCM
data-ciphers-fallback AES-256-GCM
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
    local file=$1 proto=$2 remote_port=$3 header=${4:-}
    {
        [[ -n "$header" ]] && printf '# %s\n' "$header"
        echo "proto $proto"
        echo "remote $TDZ_OVPN_HOST $remote_port"
        tdz_openvpn_profile_common
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
        tdz_openvpn_profile_common
    } > "$TDZ_OVPN_PROFILES/tdz-openvpn-http-connect.ovpn"
    chmod 644 "$TDZ_OVPN_PROFILES/tdz-openvpn-http-connect.ovpn"

    tdz_openvpn_write_profile "tdz-openvpn-ws-injector.ovpn" "tcp-client" "$TDZ_OVPN_HTTP_PORT" "Injector adapter required: HTTP Payload or WebSocket"
    tdz_openvpn_write_profile "tdz-openvpn-wss-injector.ovpn" "tcp-client" "$TDZ_OVPN_WSS_PORT" "Injector adapter required: TLS WebSocket; SNI is the portal host"
    tdz_openvpn_write_profile "tdz-openvpn-ssl-injector.ovpn" "tcp-client" "$TDZ_OVPN_SSL_PORT" "External SSL/TLS adapter required; SNI is the portal host"

    cp "$TDZ_OVPN_PKI/ca.crt" "$TDZ_OVPN_PROFILES/tdz-openvpn-ca.crt"
    cat > "$TDZ_OVPN_PROFILES/connection-guide.txt" <<EOF
TDZ SSH TUNNEL - OpenVPN Connection Guide

Server: $TDZ_OVPN_HOST
Portal: http://$TDZ_OVPN_HOST:$TDZ_OVPN_PORTAL_PORT/ovpn-configs/

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
If your VPS provider uses an external firewall or security group, allow TCP $TDZ_OVPN_PORTAL_PORT,
TCP $TDZ_OVPN_TCP_PORT/$TDZ_OVPN_HTTP_PORT/$TDZ_OVPN_WSS_PORT/$TDZ_OVPN_SSL_PORT, and UDP $TDZ_OVPN_UDP_PORT.
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

tdz_openvpn_generate_portal_html() {
    cat > "$TDZ_OVPN_PROFILES/index.html" <<EOF
<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1">
<title>TDZ OpenVPN Configs</title>
<style>
:root{color-scheme:dark;--bg:#05090c;--card:#0b141a;--line:#00d4ff;--green:#19f565;--muted:#91a0aa;--text:#edf9ff}
*{box-sizing:border-box}body{margin:0;background:radial-gradient(circle at 85% 0,#0b3040 0,transparent 35%),var(--bg);color:var(--text);font:16px ui-monospace,SFMono-Regular,Menlo,Consolas,monospace;line-height:1.55}
main{width:min(1040px,92vw);margin:0 auto;padding:54px 0 70px}.hero{border:1px solid var(--line);padding:34px;background:rgba(5,12,17,.82);box-shadow:0 0 35px #00d4ff18}.eyebrow{color:var(--green);letter-spacing:.18em;text-transform:uppercase}h1{font-size:clamp(2rem,6vw,4.2rem);line-height:1;margin:.45rem 0}h1 span{color:var(--line)}.lead{max-width:760px;color:#b8c6ce}.meta{display:flex;gap:12px;flex-wrap:wrap;margin-top:22px}.tag{border:1px solid #24414e;padding:7px 11px;color:#b8d2dd}
.grid{display:grid;grid-template-columns:repeat(2,minmax(0,1fr));gap:18px;margin-top:24px}.card{border:1px solid #173642;background:var(--card);padding:22px}.card h2{margin:0 0 5px;font-size:1.12rem}.port{color:var(--line)}.note{color:var(--muted);font-size:.9rem}.buttons{display:flex;flex-wrap:wrap;gap:10px;margin-top:16px}a.button{display:inline-block;padding:10px 13px;border:1px solid var(--line);color:var(--line);text-decoration:none}a.button:hover{background:var(--line);color:#001015}.primary{background:var(--green)!important;border-color:var(--green)!important;color:#001108!important}
.section{margin-top:34px}.policy{border-left:3px solid var(--green);padding:13px 16px;background:#09130e}.payload{white-space:pre-wrap;overflow-wrap:anywhere;background:#020506;border:1px solid #173642;padding:16px;color:#c4edf8}.footer{margin-top:38px;color:var(--muted)}
@media(max-width:720px){main{padding-top:25px}.hero{padding:23px}.grid{grid-template-columns:1fr}}
</style></head><body><main>
<section class="hero"><div class="eyebrow">TDZ SSH TUNNEL • OpenVPN</div><h1>One account.<br><span>Multiple transports.</span></h1><p class="lead">Download ready-to-import OpenVPN profiles for this server. Official clients work directly with UDP, TCP, and HTTP CONNECT. Payload, WebSocket, WSS, and SSL modes are available for compatible injector or external adapter apps.</p>
<div class="meta"><span class="tag">Server • $TDZ_OVPN_HOST</span><span class="tag">Portal • http://$TDZ_OVPN_HOST:$TDZ_OVPN_PORTAL_PORT/ovpn-configs/</span><span class="tag">Credentials • TDZ account</span></div><div class="buttons"><a class="button primary" href="openvpn-profiles.zip">Download all profiles</a><a class="button" href="connection-guide.txt">Connection guide</a><a class="button" href="tdz-openvpn-ca.crt">Download CA</a></div></section>
<section class="grid">
<article class="card"><h2>Direct UDP <span class="port">:$TDZ_OVPN_UDP_PORT</span></h2><p class="note">Best speed and latency. Works in official OpenVPN clients.</p><a class="button" href="tdz-openvpn-udp.ovpn">Download UDP</a></article>
<article class="card"><h2>Direct TCP <span class="port">:$TDZ_OVPN_TCP_PORT</span></h2><p class="note">Reliable direct transport. Works in official OpenVPN clients.</p><a class="button" href="tdz-openvpn-tcp.ovpn">Download TCP</a></article>
<article class="card"><h2>HTTP CONNECT <span class="port">:$TDZ_OVPN_HTTP_PORT</span></h2><p class="note">Native OpenVPN HTTP proxy mode through the fixed TDZ backend.</p><a class="button" href="tdz-openvpn-http-connect.ovpn">Download HTTP</a></article>
<article class="card"><h2>Payload / WS <span class="port">:$TDZ_OVPN_HTTP_PORT</span></h2><p class="note">For payload injectors and real WebSocket-capable adapters.</p><a class="button" href="tdz-openvpn-ws-injector.ovpn">Download WS</a></article>
<article class="card"><h2>WSS <span class="port">:$TDZ_OVPN_WSS_PORT</span></h2><p class="note">TLS WebSocket gateway. Use SNI <b>$TDZ_OVPN_HOST</b>; import the CA when the server uses its private certificate.</p><a class="button" href="tdz-openvpn-wss-injector.ovpn">Download WSS</a></article>
<article class="card"><h2>SSL <span class="port">:$TDZ_OVPN_SSL_PORT</span></h2><p class="note">Raw TLS gateway for SSL tunnel adapters. Use the server host as SNI; the CA is available above.</p><a class="button" href="tdz-openvpn-ssl-injector.ovpn">Download SSL</a></article>
</section>
<section class="section"><h2>Account policy</h2><div class="policy">Use the same username and password created in TDZ SSH TUNNEL. Account expiry, manual lock, maximum simultaneous connections, start-after-first-use, and the shared SSH + OpenVPN bandwidth quota are enforced automatically.</div></section>
<section class="section"><h2>Provider firewall</h2><div class="policy">The VPS firewall is configured automatically. If your hosting dashboard has a separate firewall or security group, also allow TCP $TDZ_OVPN_PORTAL_PORT, $TDZ_OVPN_TCP_PORT, $TDZ_OVPN_HTTP_PORT, $TDZ_OVPN_WSS_PORT and $TDZ_OVPN_SSL_PORT, plus UDP $TDZ_OVPN_UDP_PORT.</div></section>
<section class="section"><h2>Payload templates</h2><div class="payload">HTTP CONNECT
CONNECT [host_port] HTTP/1.1[crlf]Host: $TDZ_OVPN_HOST[crlf]Connection: keep-alive[crlf][crlf]

WebSocket
GET / HTTP/1.1[crlf]Host: $TDZ_OVPN_HOST[crlf]Upgrade: websocket[crlf]Connection: Upgrade[crlf][crlf]</div></section>
<p class="footer">Powered By: t.me/TuhinBroh • No account password is stored in any profile.</p>
</main></body></html>
EOF
    chmod 644 "$TDZ_OVPN_PROFILES/index.html"
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
        grep -q '^proto udp' "$TDZ_OVPN_ROOT/server-udp.conf" &&
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

    # Repairs and updater runs migrate legacy random-port installations to
    # the documented fixed mapping. The old state remains in the rollback
    # snapshot until every regenerated listener has passed validation.
    tdz_openvpn_apply_fixed_port_mapping

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
    if ! tdz_openvpn_load_state; then
        echo -e "${C_RED}[ERROR] OpenVPN is not installed.${C_RESET}"
        return 1
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
        tdz_detail "Download Portal" "http://${TDZ_OVPN_HOST}:${TDZ_OVPN_PORTAL_PORT}/ovpn-configs/" "$C_CYAN"
    else
        printf '  Server: %s\n  Portal: http://%s:%s/ovpn-configs/\n' \
            "$TDZ_OVPN_HOST" "$TDZ_OVPN_HOST" "$TDZ_OVPN_PORTAL_PORT"
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
    if tdz_openvpn_prepare_gateway_certificate &&
       tdz_openvpn_cert_key_match "$TDZ_OVPN_PKI/gateway.crt" "$TDZ_OVPN_PKI/gateway.key" &&
       systemctl restart tdz-openvpn-wss.service tdz-openvpn-ssl.service >/dev/null 2>&1; then
        sleep 1
        if systemctl is-active --quiet tdz-openvpn-wss.service &&
           systemctl is-active --quiet tdz-openvpn-ssl.service &&
           tdz_openvpn_port_listening "$TDZ_OVPN_WSS_PORT" tcp &&
           tdz_openvpn_port_listening "$TDZ_OVPN_SSL_PORT" tcp; then
            rm -rf "$backup"
            return 0
        fi
    fi
    [[ -f "$backup/gateway.crt" ]] && cp "$backup/gateway.crt" "$TDZ_OVPN_PKI/gateway.crt"
    [[ -f "$backup/gateway.key" ]] && cp "$backup/gateway.key" "$TDZ_OVPN_PKI/gateway.key"
    systemctl restart tdz-openvpn-wss.service tdz-openvpn-ssl.service >/dev/null 2>&1 || true
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
    tdz_openvpn_apply_fixed_port_mapping
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
        local status="Not Installed" status_color="$C_RED"
        if tdz_openvpn_is_active; then
            status="Active"; status_color="$C_GREEN"
        elif tdz_openvpn_is_installed; then
            status="Attention"; status_color="$C_YELLOW"
        fi
        show_banner
        echo
        tdz_box_top
        tdz_box_header "OPENVPN PROTOCOL SUITE"
        tdz_box_divider
        tdz_row2 "${C_GRAY}STATUS${C_RESET}" "${status_color}${C_BOLD}${status}${C_RESET}"
        tdz_box_divider
        tdz_menu1 "[ 1]" "Install or Repair OpenVPN"
        tdz_menu1 "[ 2]" "View Ports and Download Portal"
        tdz_menu1 "[ 3]" "Regenerate Download Profiles"
        tdz_menu1 "[ 4]" "Restart and Verify Services"
        tdz_menu1 "[ 5]" "Uninstall OpenVPN Suite"
        tdz_box_divider
        tdz_menu1 "[ 0]" "Return to Protocol Manager"
        tdz_box_bot
        echo
        read -r -p "$(echo -e "${C_PROMPT}  Select an option: ${C_RESET}")" choice || return
        case "$choice" in
            1) tdz_openvpn_install; press_enter ;;
            2) tdz_openvpn_show_details; press_enter ;;
            3)
                if tdz_openvpn_load_state && tdz_openvpn_generate_profiles &&
                   tdz_openvpn_apply_private_permissions && systemctl restart tdz-openvpn-portal; then
                    echo -e "${C_GREEN}[OK] Download profiles regenerated.${C_RESET}"
                    tdz_openvpn_show_details
                else
                    echo -e "${C_RED}[ERROR] OpenVPN must be installed first.${C_RESET}"
                fi
                press_enter ;;
            4)
                if tdz_openvpn_restart; then echo -e "${C_GREEN}[OK] All OpenVPN services are active.${C_RESET}"
                else echo -e "${C_RED}[ERROR] Service verification failed. Check the system journal.${C_RESET}"; fi
                press_enter ;;
            5) tdz_openvpn_uninstall; press_enter ;;
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
    local username=${1:-}
    [[ -x "$TDZ_OVPN_RUNTIME" && -n "$username" ]] || return 0
    "$TDZ_OVPN_RUNTIME" kill-user "$username" >/dev/null 2>&1 || true
}
