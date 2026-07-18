#!/bin/bash
# TDZ SSH TUNNEL optional OpenVPN protocol module.
# This file is sourced by menu.sh; it does not execute actions on its own.

TDZ_OVPN_MODULE_VERSION="2026-07-18.12"
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
TDZ_OVPN_PUBLIC_PATH="/openvpn"
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
        # All adapter modes ultimately use the TCP OpenVPN backend. Disabling
        # Nagle on both peers prevents small interactive packets from waiting
        # behind an additional TCP aggregation delay.
        [[ "$proto" == "tcp-server" ]] && echo "tcp-nodelay"
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
ExecStart=/usr/bin/python3 $TDZ_OVPN_PORTAL --listen 0.0.0.0 --port $TDZ_OVPN_PORTAL_PORT --public-host $TDZ_OVPN_HOST --root $TDZ_OVPN_PORTAL_BASE --tls-cert $TDZ_OVPN_PKI/gateway.crt --tls-key $TDZ_OVPN_PKI/gateway.key
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
SSH_PORT=22

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
    # filter_add inserts at the head of INPUT, so these SSH exceptions are
    # intentionally added after the blanket tunnel-interface drops. Clients
    # can manage this VPS through its VPN gateway address without exposing
    # any other local service to the VPN subnets.
    filter_add INPUT -i tun-tdz-tcp -p tcp --dport "\$SSH_PORT" -j ACCEPT
    filter_add INPUT -i tun-tdz-udp -p tcp --dport "\$SSH_PORT" -j ACCEPT
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
    filter_del INPUT -i tun-tdz-tcp -p tcp --dport "\$SSH_PORT" -j ACCEPT
    filter_del INPUT -i tun-tdz-udp -p tcp --dport "\$SSH_PORT" -j ACCEPT
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
    local compatibility=${1:-modern}
    local cipher_compatibility
    if [[ "$compatibility" == "adapter" ]]; then
        # Embedded OpenVPN cores in injector apps can identify themselves as
        # 2.5 while still rejecting data-ciphers. Keep their profile on the
        # negotiated AES-256-GCM cipher without emitting unsupported options.
        cipher_compatibility='ignore-unknown-option block-ipv6'
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
cipher AES-256-GCM
EOF
    if [[ "$compatibility" != "adapter" ]]; then
        cat <<EOF
data-ciphers AES-256-GCM:AES-128-GCM
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
    {
        [[ -n "$header" ]] && printf '# %s\n' "$header"
        echo "proto $proto"
        echo "remote $TDZ_OVPN_HOST $remote_port"
        if [[ "$protect_outer_route" == "true" ]]; then
            # Injector apps create an outer WS/TLS socket before OpenVPN adds
            # its default route. Pin that public endpoint to the original
            # gateway so the carrier socket cannot be routed back into tun.
            echo "route $TDZ_OVPN_HOST 255.255.255.255 net_gateway"
        fi
        tdz_openvpn_profile_common "$compatibility"
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
To access this VPS over the VPN itself, connect SSH port 22 to the ROUTE_GATEWAY
address shown in the client log. The public adapter endpoint remains outside the tunnel.
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
    cat > "$TDZ_OVPN_PROFILES/portal.css" <<'EOF'
:root{color-scheme:light;--bg:#efeee9;--surface:#fff;--surface-soft:#f6f6f2;--glass:#fff;--glass-strong:#fff;--border:rgba(17,31,23,.13);--border-strong:rgba(17,31,23,.23);--accent:#12b98f;--accent-hover:#079f79;--accent-soft:rgba(18,185,143,.10);--accent-line:rgba(18,185,143,.48);--text:#101611;--text-soft:#344038;--muted:#626d66;--green:#0c9d73;--yellow:#a8740c;--red:#c94855;--nav:rgba(255,255,255,.96);--footer:#f7f7f3;--control:#fff;--code-bg:#e7e8e3;--code-text:#17211b;--hero-bg:linear-gradient(135deg,#fff,#f8faf7);--hero-side:#f3f7f4;--stat-bg:#f5f7f4;--table-head:#f0f3f0;--button-on-accent:#fff;--glow-a:rgba(18,185,143,.13);--glow-b:rgba(58,128,102,.08);--inset:rgba(255,255,255,.92);--radius:12px;--radius-lg:22px;--shadow:0 20px 60px rgba(27,46,36,.12);--card-shadow:0 8px 24px rgba(27,46,36,.07)}
:root[data-theme="dark"]{color-scheme:dark;--bg:#101310;--surface:#191e1a;--surface-soft:#202620;--glass:#191e1a;--glass-strong:#1c221d;--border:rgba(232,244,237,.14);--border-strong:rgba(232,244,237,.24);--accent:#3bd7ae;--accent-hover:#66e6c2;--accent-soft:rgba(59,215,174,.11);--accent-line:rgba(59,215,174,.48);--text:#f2f5f2;--text-soft:#c5cdc7;--muted:#98a29b;--green:#55e6a5;--yellow:#f2c76a;--red:#ff7b84;--nav:rgba(20,24,21,.96);--footer:#141814;--control:#202621;--code-bg:#0b0e0c;--code-text:#dde5df;--hero-bg:linear-gradient(135deg,#1c221d,#151a16);--hero-side:#151b17;--stat-bg:#202620;--table-head:#202620;--button-on-accent:#07110d;--glow-a:rgba(59,215,174,.10);--glow-b:rgba(34,99,77,.10);--inset:rgba(255,255,255,.035);--shadow:0 24px 72px rgba(0,0,0,.38);--card-shadow:0 10px 28px rgba(0,0,0,.22)}
@media(prefers-color-scheme:dark){:root:not([data-theme="light"]){color-scheme:dark;--bg:#101310;--surface:#191e1a;--surface-soft:#202620;--glass:#191e1a;--glass-strong:#1c221d;--border:rgba(232,244,237,.14);--border-strong:rgba(232,244,237,.24);--accent:#3bd7ae;--accent-hover:#66e6c2;--accent-soft:rgba(59,215,174,.11);--accent-line:rgba(59,215,174,.48);--text:#f2f5f2;--text-soft:#c5cdc7;--muted:#98a29b;--green:#55e6a5;--yellow:#f2c76a;--red:#ff7b84;--nav:rgba(20,24,21,.96);--footer:#141814;--control:#202621;--code-bg:#0b0e0c;--code-text:#dde5df;--hero-bg:linear-gradient(135deg,#1c221d,#151a16);--hero-side:#151b17;--stat-bg:#202620;--table-head:#202620;--button-on-accent:#07110d;--glow-a:rgba(59,215,174,.10);--glow-b:rgba(34,99,77,.10);--inset:rgba(255,255,255,.035);--shadow:0 24px 72px rgba(0,0,0,.38);--card-shadow:0 10px 28px rgba(0,0,0,.22)}}
*{box-sizing:border-box}
html{scroll-behavior:smooth;background:var(--bg)}
body{margin:0;min-height:100vh;background:radial-gradient(circle at 100% 0,var(--glow-a),transparent 32rem),radial-gradient(circle at 0 100%,var(--glow-b),transparent 28rem),var(--bg);color:var(--text);font:16px/1.7 Inter,"Inter Fallback",ui-sans-serif,-apple-system,BlinkMacSystemFont,"Segoe UI",sans-serif;-webkit-font-smoothing:antialiased}
a{color:inherit}
button{font:inherit}
code,.mono,.filename,.payload{font-family:"SFMono-Regular",Consolas,"Liberation Mono",monospace}
.shell{width:min(1440px,calc(100% - 48px));margin-inline:auto}
.site-header{position:sticky;top:0;z-index:20;border-bottom:1px solid var(--border-strong);background:var(--nav);box-shadow:0 5px 22px rgba(20,38,29,.06);-webkit-backdrop-filter:blur(14px) saturate(120%);backdrop-filter:blur(14px) saturate(120%)}
.nav{min-height:76px;display:flex;align-items:center;justify-content:space-between;gap:28px}
.brand{display:inline-flex;align-items:center;gap:8px;color:var(--text);font-size:.93rem;font-weight:760;letter-spacing:.045em;text-decoration:none;white-space:nowrap}
.brand-main{color:var(--accent);font-size:1.08rem;font-weight:880;letter-spacing:.14em}
.brand-dot{color:var(--accent)}
.nav-links{display:flex;align-items:center;gap:6px;flex-wrap:wrap;margin-left:auto}
.nav-links a{border:1px solid transparent;border-radius:8px;color:var(--muted);padding:8px 12px;text-decoration:none;transition:background .16s,color .16s,border-color .16s}
.nav-links a:hover,.nav-links a.active{border-color:var(--border);background:var(--accent-soft);color:var(--accent)}
.theme-toggle{display:inline-flex;align-items:center;gap:5px;min-height:32px;border:1px solid var(--border-strong);border-radius:8px;background:var(--control);color:var(--text-soft);padding:4px 8px;font-size:.78rem;font-weight:660;line-height:1;cursor:pointer;box-shadow:0 4px 14px rgba(27,46,36,.08);transition:border-color .16s,background .16s,color .16s}
.theme-toggle:hover{border-color:var(--accent-line);background:var(--accent-soft);color:var(--accent)}
.theme-glyph{display:grid;place-items:center;width:14px;height:14px;color:var(--accent);font-size:.75rem;line-height:1}.theme-glyph:before{content:"◐"}.theme-toggle[data-theme-mode="light"] .theme-glyph:before{content:"○"}.theme-toggle[data-theme-mode="dark"] .theme-glyph:before{content:"●"}
main{padding:46px 0 96px}
.hero{position:relative;display:grid;grid-template-columns:minmax(0,1.45fr) minmax(330px,.55fr);min-height:540px;overflow:hidden;border:1px solid var(--border-strong);border-radius:var(--radius-lg);background:var(--hero-bg);box-shadow:var(--shadow)}
.hero:before{content:"";position:absolute;inset:0;background:radial-gradient(circle at 78% 16%,var(--glow-a),transparent 32%),linear-gradient(120deg,var(--accent-soft),transparent 34%);pointer-events:none}
.hero-copy{position:relative;z-index:1;display:flex;flex-direction:column;justify-content:center;padding:clamp(38px,6vw,88px)}
.hero-side{position:relative;z-index:1;margin:18px;display:flex;flex-direction:column;justify-content:center;gap:12px;border:1px solid var(--border-strong);border-radius:14px;background:var(--hero-side);padding:24px;box-shadow:var(--card-shadow)}
.eyebrow,.kicker,.label{color:var(--accent);font-size:.76rem;font-weight:750;letter-spacing:.15em;text-transform:uppercase}
.hero h1{max-width:900px;margin:.72rem 0 1.25rem;font-size:clamp(3rem,7vw,6.35rem);font-weight:760;letter-spacing:-.065em;line-height:.94}
.hero h1 span{color:var(--accent);text-shadow:0 0 34px var(--accent-soft)}
.lead{max-width:790px;margin:0;color:var(--text-soft);font-size:clamp(1rem,1.5vw,1.22rem)}
.actions,.chips{display:flex;flex-wrap:wrap;gap:10px}
.actions{margin-top:28px}
.button{display:inline-flex;align-items:center;justify-content:center;min-height:44px;border:1px solid var(--border-strong);border-radius:8px;background:var(--control);color:var(--text);padding:9px 15px;font-size:.92rem;font-weight:700;text-decoration:none;box-shadow:var(--card-shadow);transition:background .16s,border-color .16s,color .16s}
.button:hover{border-color:var(--accent-line);background:var(--accent-soft);color:var(--accent)}
.button.primary{border-color:var(--accent-line);background:var(--accent);color:var(--button-on-accent);box-shadow:0 10px 32px var(--accent-soft)}
.button.primary:hover{background:var(--accent-hover);color:var(--button-on-accent)}
.status-head{display:flex;align-items:center;justify-content:space-between;gap:12px;margin-bottom:8px;color:var(--text-soft);font-size:.78rem;text-transform:uppercase;letter-spacing:.1em}
.live-dot{display:inline-block;width:8px;height:8px;border-radius:999px;background:var(--green);box-shadow:0 0 14px rgba(85,230,165,.65)}
.status-row{display:grid;grid-template-columns:95px minmax(0,1fr);gap:12px;border-top:1px solid var(--border);padding:13px 0;color:var(--muted)}
.status-row strong{color:var(--text);font-weight:600;overflow-wrap:anywhere}
.status-row code{color:var(--accent)}
.hero-stats{display:grid;grid-template-columns:repeat(3,minmax(0,1fr));gap:10px;margin-top:30px}
.stat{border:1px solid var(--border);border-radius:10px;background:var(--stat-bg);padding:14px}
.stat strong{display:block;color:var(--text);font-size:1.2rem}.stat span{color:var(--muted);font-size:.78rem}
.section{margin-top:76px;scroll-margin-top:100px}
.section-head{display:flex;align-items:end;justify-content:space-between;gap:28px;margin-bottom:24px}
.section-head h2,.content-section h2{margin:.22rem 0 0;font-size:clamp(1.65rem,3vw,2.45rem);font-weight:700;letter-spacing:-.035em;line-height:1.16}
.section-head p{max-width:620px;margin:0;color:var(--muted)}
.grid{display:grid;grid-template-columns:repeat(3,minmax(0,1fr));gap:14px}
.grid.two{grid-template-columns:repeat(2,minmax(0,1fr))}
.glass,.card,.panel{border:1px solid var(--border-strong);border-radius:var(--radius);background:var(--surface);box-shadow:inset 0 1px var(--inset),var(--card-shadow)}
.card{position:relative;min-width:0;padding:24px;transition:border-color .18s,box-shadow .18s}
.card:hover{border-color:var(--accent-line);box-shadow:inset 0 1px var(--inset),0 10px 30px rgba(20,70,48,.10)}
.card h3{margin:8px 0 6px;font-size:1.04rem;font-weight:680}.card p{margin:.45rem 0;color:var(--muted)}
.card-index{display:grid;place-items:center;width:34px;height:34px;border:1px solid var(--border);border-radius:8px;background:var(--surface-soft);color:var(--accent);font:700 .78rem/1 "SFMono-Regular",Consolas,monospace}
.status{color:var(--accent);font-size:.72rem;font-weight:720;letter-spacing:.09em;text-transform:uppercase}
.port{float:right;border:1px solid var(--border);border-radius:999px;background:var(--stat-bg);color:var(--text-soft);padding:2px 8px;font:600 .76rem/1.6 "SFMono-Regular",Consolas,monospace}
.note,.muted{color:var(--muted)}.note{font-size:.91rem}
.panel{padding:26px}.panel p:last-child{margin-bottom:0}
.policy{border-left:2px solid var(--green)}.warning{border-left:2px solid var(--yellow)}.danger{border-left:2px solid var(--red)}
.flow{display:grid;grid-template-columns:repeat(4,minmax(0,1fr));gap:0;overflow:hidden}
.flow-step{position:relative;border-right:1px solid var(--border);padding:25px}.flow-step:last-child{border-right:0}.flow-step strong{display:block;margin-bottom:5px}.flow-step span{color:var(--muted);font-size:.88rem}.flow-step:not(:last-child):after{content:"›";position:absolute;z-index:2;right:-8px;top:50%;transform:translateY(-50%);color:var(--accent);background:var(--surface);padding:0 3px;font-size:1.3rem}
.docs-layout{display:grid;grid-template-columns:minmax(0,1fr) 280px;gap:38px;align-items:start}
.article{min-width:0}
.page-intro{border-bottom:1px solid var(--border);padding:18px 0 34px}.page-intro h1{margin:.4rem 0 .85rem;font-size:clamp(2.3rem,5vw,4.5rem);font-weight:740;letter-spacing:-.055em;line-height:1}.page-intro h1 span{color:var(--accent)}.page-intro p{max-width:850px;margin:0;color:var(--text-soft);font-size:1.08rem}
.toc{position:sticky;top:102px;border-left:1px solid var(--border);padding:6px 0 6px 20px}.toc-title{margin-bottom:10px;color:var(--text-soft);font-size:.82rem;font-weight:680}.toc a{display:block;border-left:1px solid transparent;color:var(--muted);margin-left:-21px;padding:6px 0 6px 20px;font-size:.87rem;text-decoration:none}.toc a:hover{border-left-color:var(--accent);color:var(--accent)}
.content-section{margin-top:54px;scroll-margin-top:100px}.content-section>p{color:var(--text-soft)}
.chips{margin-top:22px}.chip{border:1px solid var(--border);border-radius:8px;background:var(--glass);color:var(--muted);padding:8px 11px;font-size:.84rem}.chip strong{color:var(--accent);margin-right:5px}
.table-wrap{overflow:auto;border:1px solid var(--border);border-radius:var(--radius);background:var(--glass)}
table{width:100%;min-width:800px;border-collapse:collapse}th,td{border-bottom:1px solid var(--border);padding:14px 16px;text-align:left;vertical-align:top}tr:last-child td{border-bottom:0}th{background:var(--table-head);color:var(--text-soft);font-size:.75rem;font-weight:720;letter-spacing:.07em;text-transform:uppercase}td{color:var(--text-soft)}td:first-child{color:var(--text);font-weight:620}td code{color:var(--accent)}
.payload-card{display:flex;flex-direction:column}.payload-head{display:flex;align-items:center;justify-content:space-between;gap:14px}.copy-button{flex:0 0 auto;border:1px solid var(--accent-line);border-radius:8px;background:var(--accent-soft);color:var(--accent);padding:6px 11px;font-size:.78rem;font-weight:740;cursor:pointer;transition:background .16s,color .16s,border-color .16s}.copy-button:hover,.copy-button.is-copied{border-color:var(--accent);background:var(--accent);color:var(--button-on-accent)}.copy-button:focus-visible,.theme-toggle:focus-visible,.button:focus-visible,.nav-links a:focus-visible{outline:3px solid var(--accent-line);outline-offset:2px}
.payload{min-height:142px;white-space:pre-wrap;overflow-wrap:anywhere;border:1px solid var(--border);border-radius:9px;background:var(--code-bg);color:var(--code-text);margin:12px 0 0;padding:17px;font-size:.83rem;line-height:1.65;user-select:text}
.callout{display:flex;gap:15px;border:1px solid var(--border);border-radius:var(--radius);background:var(--glass);padding:20px}.callout-mark{flex:0 0 auto;display:grid;place-items:center;width:30px;height:30px;border:1px solid var(--accent-line);border-radius:8px;background:var(--accent-soft);color:var(--accent);font-size:.78rem;font-weight:800}.callout strong{display:block;margin-bottom:3px}.callout p{margin:0;color:var(--muted)}.spaced-panel{margin-top:14px}
.download-card{display:flex;flex-direction:column;min-height:270px}.download-card .filename{margin-top:auto;color:var(--text-soft);font-size:.78rem;overflow-wrap:anywhere}.download-card .button{margin-top:12px}
.bundle{display:grid;grid-template-columns:minmax(0,1.25fr) minmax(280px,.75fr);gap:14px}.bundle .panel{min-height:190px;display:flex;flex-direction:column;align-items:flex-start}.bundle .button{margin-top:auto}
.footer{border-top:1px solid var(--border);background:var(--footer);color:var(--muted);padding:54px 0 24px}.footer-grid{display:grid;grid-template-columns:minmax(0,1.45fr) minmax(150px,.55fr) minmax(230px,.7fr);gap:58px}.footer-profile p,.footer-column p{max-width:510px;margin:.85rem 0 0}.footer-brand{display:inline-flex;align-items:center;gap:8px;color:var(--text);font-weight:760;letter-spacing:.045em;text-decoration:none}.footer-column h2{margin:0 0 12px;color:var(--text);font-size:.78rem;font-weight:760;letter-spacing:.13em;text-transform:uppercase}.footer-column a{display:block;width:max-content;max-width:100%;color:var(--text-soft);margin:6px 0;text-decoration:none}.footer a:hover{color:var(--accent)}.developer-line{color:var(--muted);margin:0!important}.developer-line a{display:inline;color:var(--text);font-size:1.04rem;font-weight:680}.footer-bottom{display:flex;align-items:center;justify-content:space-between;gap:20px;border-top:1px solid var(--border);margin-top:42px;padding-top:20px;font-size:.82rem}.footer-bottom span:last-child{color:var(--text-soft)}
.footer-developer{padding-top:1px}.developer-line{display:flex;align-items:baseline;flex-wrap:wrap;gap:0 6px;line-height:1.55}.developer-line+.developer-line{margin-top:5px!important}.developer-line .developer-link{display:inline;width:auto;margin:0;color:#1267d6;font-size:1rem;font-weight:720;text-decoration:underline;text-decoration-color:rgba(18,103,214,.34);text-underline-offset:3px}.developer-line .developer-link:hover{color:#074fae;text-decoration-color:currentColor}.developer-note{max-width:360px!important;margin-top:14px!important;color:var(--text-soft);font-size:.9rem;line-height:1.6}:root[data-theme="dark"] .developer-line .developer-link{color:#72a7ff}:root[data-theme="dark"] .developer-line .developer-link:hover{color:#9bc2ff}
@media(prefers-color-scheme:dark){:root:not([data-theme="light"]) .developer-line .developer-link{color:#72a7ff}:root:not([data-theme="light"]) .developer-line .developer-link:hover{color:#9bc2ff}}
@media(max-width:1060px){.hero{grid-template-columns:1fr;min-height:0}.hero-side{margin:0 24px 24px}.docs-layout{grid-template-columns:1fr}.toc{position:static;display:flex;gap:6px;overflow:auto;border:0;border-bottom:1px solid var(--border);padding:0 0 14px;order:-1}.toc-title{display:none}.toc a{flex:0 0 auto;margin:0;border:1px solid var(--border);border-radius:8px;padding:6px 10px}.grid{grid-template-columns:repeat(2,minmax(0,1fr))}.flow{grid-template-columns:repeat(2,minmax(0,1fr))}.flow-step:nth-child(2){border-right:0}.flow-step:nth-child(-n+2){border-bottom:1px solid var(--border)}.flow-step:nth-child(2):after{display:none}}
@media(max-width:900px){.nav{display:grid;grid-template-columns:minmax(0,1fr) auto;padding:15px 0;gap:12px}.nav-links{grid-column:1/-1;grid-row:2;margin-left:0}.theme-toggle{grid-column:2;grid-row:1}.footer-grid{grid-template-columns:1.25fr .75fr;gap:36px}.footer-column:last-child{grid-column:1/-1}}
@media(max-width:680px){body{font-size:15px}.shell{width:min(100% - 24px,1440px)}.site-header{position:static}.nav{min-height:0;padding:14px 0}.nav-links{gap:5px}.nav-links a{padding:7px 9px;font-size:.85rem}.theme-toggle{min-height:36px;padding:5px 9px}main{padding:24px 0 68px}.hero-copy{padding:34px 24px}.hero h1{font-size:clamp(2.65rem,15vw,4rem)}.hero-side{margin:0 12px 12px;padding:18px}.hero-stats{grid-template-columns:1fr}.section{margin-top:52px}.section-head{display:block}.section-head p{margin-top:10px}.grid,.grid.two,.bundle{grid-template-columns:1fr}.flow{grid-template-columns:1fr}.flow-step{border-right:0;border-bottom:1px solid var(--border)}.flow-step:last-child{border-bottom:0}.flow-step:not(:last-child):after{content:"⌄";display:block;right:50%;top:auto;bottom:-13px;transform:translateX(50%)}.page-intro{padding-top:4px}.card,.panel{padding:20px}.status-row{grid-template-columns:82px minmax(0,1fr)}.footer{padding-top:42px}.footer-grid{grid-template-columns:1fr;gap:30px}.footer-column:last-child{grid-column:auto}.footer-bottom{margin-top:32px}.payload-head{align-items:flex-start}.copy-button{margin-top:-3px}}
@media(max-width:680px){.theme-toggle{min-height:30px;padding:3px 7px;font-size:.74rem}.theme-glyph{width:13px;height:13px;font-size:.7rem}}
@media(prefers-reduced-motion:reduce){html{scroll-behavior:auto}.card,.button{transition:none}}
EOF

    cat > "$TDZ_OVPN_PROFILES/portal.js" <<'EOF'
(function () {
    "use strict";

    var storageKey = "tdz-ovpn-theme";
    var modes = ["system", "light", "dark"];

    function readTheme() {
        try {
            var stored = window.localStorage.getItem(storageKey);
            return modes.indexOf(stored) === -1 ? "system" : stored;
        } catch (error) {
            return "system";
        }
    }

    function applyTheme(mode) {
        if (mode === "light" || mode === "dark") {
            document.documentElement.setAttribute("data-theme", mode);
        } else {
            document.documentElement.removeAttribute("data-theme");
        }
    }

    var activeTheme = readTheme();
    applyTheme(activeTheme);

    function saveTheme(mode) {
        try {
            window.localStorage.setItem(storageKey, mode);
        } catch (error) {
            return;
        }
    }

    function updateThemeControls() {
        var labels = { system: "System", light: "Light", dark: "Dark" };
        document.querySelectorAll("[data-theme-toggle]").forEach(function (button) {
            button.setAttribute("data-theme-mode", activeTheme);
            button.setAttribute("aria-label", "Theme: " + labels[activeTheme] + ". Select next theme.");
            var label = button.querySelector("[data-theme-label]");
            if (label) label.textContent = labels[activeTheme];
        });
    }

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
            var themeButton = event.target.closest("[data-theme-toggle]");
            if (themeButton) {
                activeTheme = modes[(modes.indexOf(activeTheme) + 1) % modes.length];
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

    if (document.readyState === "loading") {
        document.addEventListener("DOMContentLoaded", ready);
    } else {
        ready();
    }
}());
EOF

    cat > "$TDZ_OVPN_PROFILES/index.html" <<EOF
<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="description" content="TDZ SSH TUNNEL OpenVPN transport portal"><title>TDZ • OVPN PORTAL</title><script src="$TDZ_OVPN_PUBLIC_PATH/assets/portal.js"></script><link rel="stylesheet" href="$TDZ_OVPN_PUBLIC_PATH/assets/portal.css"></head><body>
<header class="site-header"><div class="shell nav"><a class="brand" href="$TDZ_OVPN_PUBLIC_PATH/"><span class="brand-main">TDZ</span><span class="brand-dot">•</span><span>OVPN PORTAL</span></a><nav class="nav-links" aria-label="Portal navigation"><a class="active" href="$TDZ_OVPN_PUBLIC_PATH/">Overview</a><a href="$TDZ_OVPN_PUBLIC_PATH/docs">Documentation</a><a href="$TDZ_OVPN_PUBLIC_PATH/download">Downloads</a></nav><button class="theme-toggle" type="button" data-theme-toggle data-theme-mode="system"><span class="theme-glyph" aria-hidden="true"></span><span data-theme-label>System</span></button></div></header>
<main class="shell">
<section class="hero"><div class="hero-copy"><div class="eyebrow">TDZ SSH TUNNEL • OpenVPN transport suite</div><h1>TDZ <span>•</span><br>OVPN PORTAL</h1><p class="lead">A focused OpenVPN hub for TDZ SSH TUNNEL—six connection modes, ready-to-import profiles, clear setup references and one shared account policy.</p><div class="actions"><a class="button primary" href="$TDZ_OVPN_PUBLIC_PATH/download">Download profiles</a><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/docs">Open documentation</a></div><div class="hero-stats"><div class="stat"><strong>6</strong><span>connection modes</span></div><div class="stat"><strong>1</strong><span>shared TDZ account</span></div><div class="stat"><strong>TLS</strong><span>protected portal</span></div></div></div>
<aside class="hero-side"><div class="status-head"><span>Current gateway</span><span><i class="live-dot"></i> Ready</span></div><div class="status-row"><span>Server</span><strong>$TDZ_OVPN_HOST</strong></div><div class="status-row"><span>Delivery</span><strong>HTTPS protected</strong></div><div class="status-row"><span>Identity</span><strong>Existing TDZ account</strong></div><div class="status-row"><span>Policies</span><strong>Expiry • quota • limit • lock</strong></div><div class="status-row"><span>Profiles</span><strong>No embedded credentials</strong></div></aside></section>

<section class="section"><div class="section-head"><div><div class="kicker">Unified access</div><h2>One identity across every transport</h2></div><p>The same TDZ account controls SSH and OpenVPN. Changing the transport does not create a second user database or bypass an existing limit.</p></div><div class="grid">
<article class="card"><div class="card-index">01</div><h3>Shared expiry</h3><p>Expired accounts are rejected consistently, regardless of the selected OpenVPN path.</p></article>
<article class="card"><div class="card-index">02</div><h3>First-use activation</h3><p>Pending accounts activate through the same protected first-use workflow.</p></article>
<article class="card"><div class="card-index">03</div><h3>Connection limits</h3><p>Concurrent OpenVPN sessions participate in the account connection policy.</p></article>
<article class="card"><div class="card-index">04</div><h3>Shared traffic quota</h3><p>OpenVPN usage is reconciled into the same bandwidth counter used by TDZ.</p></article>
<article class="card"><div class="card-index">05</div><h3>Lock enforcement</h3><p>Manual locks, quota locks and expired states stop new authentication.</p></article>
<article class="card"><div class="card-index">06</div><h3>Private profiles</h3><p>Profiles contain transport material only—never a username or password.</p></article>
</div></section>

<section class="section"><div class="section-head"><div><div class="kicker">Connection matrix</div><h2>Six paths for different network conditions</h2></div><p>Use direct profiles with standard OpenVPN clients. Payload, WebSocket and outer-TLS modes require a compatible adapter client.</p></div><div class="grid">
<article class="card"><span class="status">Official client</span><span class="port">UDP $TDZ_OVPN_UDP_PORT</span><h3>Direct UDP</h3><p>Low overhead and strong performance when the network permits UDP.</p></article>
<article class="card"><span class="status">Official client</span><span class="port">TCP $TDZ_OVPN_TCP_PORT</span><h3>Direct TCP</h3><p>A clean TCP route for networks where UDP is unavailable or unstable.</p></article>
<article class="card"><span class="status">Official client</span><span class="port">HTTP $TDZ_OVPN_HTTP_PORT</span><h3>HTTP CONNECT</h3><p>A native OpenVPN HTTP proxy profile with a fixed, validated backend.</p></article>
<article class="card"><span class="status">Injector mode</span><span class="port">WS $TDZ_OVPN_HTTP_PORT</span><h3>HTTP Payload / WS</h3><p>CONNECT payload or WebSocket upgrade for compatible injector apps.</p></article>
<article class="card"><span class="status">TLS adapter</span><span class="port">WSS $TDZ_OVPN_WSS_PORT</span><h3>WSS / SNI</h3><p>WebSocket carried inside TLS with the configured server host as SNI.</p></article>
<article class="card"><span class="status">TLS adapter</span><span class="port">SSL $TDZ_OVPN_SSL_PORT</span><h3>SSL / SNI</h3><p>A raw TLS wrapper for clients that provide an external SSL adapter.</p></article>
</div></section>

<section class="section"><div class="section-head"><div><div class="kicker">How it fits together</div><h2>Transport changes; account rules stay intact</h2></div></div><div class="glass flow"><div class="flow-step"><strong>Client app</strong><span>Imports the selected TDZ profile.</span></div><div class="flow-step"><strong>Transport gateway</strong><span>Handles direct, HTTP, WS, WSS or SSL traffic.</span></div><div class="flow-step"><strong>OpenVPN core</strong><span>Builds the encrypted tunnel and requests authentication.</span></div><div class="flow-step"><strong>TDZ policy</strong><span>Applies account status, quota and session limits.</span></div></div></section>

<section class="section grid two"><div class="panel policy"><span class="label">Start here</span><h3>Test direct transport first</h3><p>Confirm Direct TCP or UDP before testing payload and TLS adapter modes. This keeps transport errors separate from account errors.</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/docs">Read the complete setup guide</a></div><div class="panel warning"><span class="label">Certificate note</span><h3>One trusted outer certificate</h3><p>Domain &amp; SSL automatically reuses a matching certificate for this portal, WSS and SSL. The private OpenVPN CA remains embedded in every profile for the inner tunnel.</p></div></section>
</main>
<footer class="footer"><div class="shell footer-grid"><section class="footer-profile"><a class="footer-brand" href="$TDZ_OVPN_PUBLIC_PATH/"><span class="brand-main">TDZ</span><span class="brand-dot">•</span><span>OVPN PORTAL</span></a><p>Secure OpenVPN transport access for TDZ SSH TUNNEL, with unified account policy and ready-to-import profiles.</p></section><section class="footer-column"><h2>Explore</h2><a href="$TDZ_OVPN_PUBLIC_PATH/">Overview</a><a href="$TDZ_OVPN_PUBLIC_PATH/docs">Documentation</a><a href="$TDZ_OVPN_PUBLIC_PATH/download">Downloads</a></section><section class="footer-column footer-developer"><p class="developer-line"><span>Developed By:</span><a class="developer-link" href="https://tuhinbro.com/" target="_blank" rel="noopener noreferrer">Yeasinul Hoque Tuhin</a></p><p class="developer-line"><span>Telegram:</span><a class="developer-link" href="https://t.me/TuhinBroh" target="_blank" rel="noopener noreferrer">@TuhinBroh</a></p><p class="developer-note">Reliable OpenVPN access, thoughtfully crafted for the TDZ SSH TUNNEL ecosystem.</p></section></div><div class="shell footer-bottom"><span>TDZ SSH TUNNEL • OpenVPN Suite</span></div></footer>
</body></html>
EOF

    cat > "$TDZ_OVPN_PROFILES/docs.html" <<EOF
<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="description" content="TDZ OpenVPN configuration documentation"><title>TDZ • OVPN PORTAL</title><script src="$TDZ_OVPN_PUBLIC_PATH/assets/portal.js"></script><link rel="stylesheet" href="$TDZ_OVPN_PUBLIC_PATH/assets/portal.css"></head><body>
<header class="site-header"><div class="shell nav"><a class="brand" href="$TDZ_OVPN_PUBLIC_PATH/"><span class="brand-main">TDZ</span><span class="brand-dot">•</span><span>OVPN PORTAL</span></a><nav class="nav-links" aria-label="Portal navigation"><a href="$TDZ_OVPN_PUBLIC_PATH/">Overview</a><a class="active" href="$TDZ_OVPN_PUBLIC_PATH/docs">Documentation</a><a href="$TDZ_OVPN_PUBLIC_PATH/download">Downloads</a></nav><button class="theme-toggle" type="button" data-theme-toggle data-theme-mode="system"><span class="theme-glyph" aria-hidden="true"></span><span data-theme-label>System</span></button></div></header>
<main class="shell docs-layout"><article class="article"><header class="page-intro"><div class="eyebrow">TDZ • OVPN PORTAL</div><h1>Configuration <span>guide.</span></h1><p>Every field, payload, SNI value and verification step in one place. All modes authenticate with the same TDZ username and password.</p><div class="chips"><span class="chip"><strong>HOST</strong>$TDZ_OVPN_HOST</span><span class="chip"><strong>ACCOUNT</strong>Existing TDZ login</span><span class="chip"><strong>SNI</strong>$TDZ_OVPN_HOST</span></div></header>

<section class="content-section" id="modes"><div class="kicker">Client fields</div><h2>Mode-by-mode setup</h2><p>Select the profile and client mode as one pair. Mixing a direct profile with an adapter mode will not create a valid connection.</p><div class="table-wrap"><table><thead><tr><th>Profile</th><th>Client mode</th><th>Host</th><th>Port</th><th>Extra setting</th></tr></thead><tbody>
<tr><td>Direct UDP</td><td><code>DIRECT</code></td><td>$TDZ_OVPN_HOST</td><td><code>$TDZ_OVPN_UDP_PORT / UDP</code></td><td>No payload or proxy</td></tr>
<tr><td>Direct TCP</td><td><code>DIRECT</code></td><td>$TDZ_OVPN_HOST</td><td><code>$TDZ_OVPN_TCP_PORT / TCP</code></td><td>No payload or proxy</td></tr>
<tr><td>HTTP CONNECT</td><td><code>HTTP</code></td><td>$TDZ_OVPN_HOST</td><td><code>$TDZ_OVPN_HTTP_PORT</code></td><td>Use the CONNECT payload below; proxy fields remain empty</td></tr>
<tr><td>Payload / WS</td><td><code>HTTP</code></td><td>$TDZ_OVPN_HOST</td><td><code>$TDZ_OVPN_HTTP_PORT</code></td><td>Use the WebSocket payload below</td></tr>
<tr><td>WSS</td><td><code>HTTPS / WSS</code></td><td>$TDZ_OVPN_HOST</td><td><code>$TDZ_OVPN_WSS_PORT</code></td><td>SNI: $TDZ_OVPN_HOST; use the WebSocket payload</td></tr>
<tr><td>SSL</td><td><code>SSL/TLS</code></td><td>$TDZ_OVPN_HOST</td><td><code>$TDZ_OVPN_SSL_PORT</code></td><td>SNI: $TDZ_OVPN_HOST; payload and proxy remain empty</td></tr>
</tbody></table></div></section>

<section class="content-section" id="certificates"><div class="kicker">Certificate layers</div><h2>Domain &amp; SSL also protects the adapters</h2><div class="grid two"><div class="callout"><span class="callout-mark">TLS</span><div><strong>Portal, WSS and SSL</strong><p>A valid certificate from Domain &amp; SSL is applied automatically when it covers $TDZ_OVPN_HOST. This is the certificate an outer TLS/SNI client sees.</p></div></div><div class="callout"><span class="callout-mark">VPN</span><div><strong>OpenVPN private CA</strong><p>The inner tunnel keeps its dedicated private CA and server identity. It is already embedded in each generated profile and should not be replaced with a web certificate.</p></div></div></div></section>

<section class="content-section" id="payloads"><div class="kicker">Payload reference</div><h2>Use the gateway and backend correctly</h2><div class="grid two"><article class="card payload-card"><div class="payload-head"><span class="label">HTTP CONNECT payload</span><button class="copy-button" type="button" data-copy-target="http-connect-payload">Copy</button></div><div class="payload" id="http-connect-payload">CONNECT $TDZ_OVPN_HOST:$TDZ_OVPN_TCP_PORT HTTP/1.1[crlf]Host: $TDZ_OVPN_HOST[crlf]Connection: keep-alive[crlf][crlf]</div><p class="note">Gateway: $TDZ_OVPN_HOST:$TDZ_OVPN_HTTP_PORT • Backend: $TDZ_OVPN_HOST:$TDZ_OVPN_TCP_PORT</p></article><article class="card payload-card"><div class="payload-head"><span class="label">WebSocket payload</span><button class="copy-button" type="button" data-copy-target="websocket-payload">Copy</button></div><div class="payload" id="websocket-payload">GET / HTTP/1.1[crlf]Host: $TDZ_OVPN_HOST[crlf]Upgrade: websocket[crlf]Connection: Upgrade[crlf][crlf]</div><p class="note">Use port $TDZ_OVPN_HTTP_PORT for WS or $TDZ_OVPN_WSS_PORT for WSS with SNI.</p></article></div></section>

<section class="content-section" id="verification"><div class="kicker">Verification order</div><h2>Test without mixing failure layers</h2><p>Start with the shortest route. Add the HTTP or TLS adapter only after direct OpenVPN authentication succeeds.</p><div class="grid"><article class="card"><div class="card-index">01</div><h3>Direct TCP / UDP</h3><p>Confirms the OpenVPN core, certificate and TDZ authentication.</p></article><article class="card"><div class="card-index">02</div><h3>HTTP CONNECT / WS</h3><p>Confirms the HTTP adapter listening on port $TDZ_OVPN_HTTP_PORT.</p></article><article class="card"><div class="card-index">03</div><h3>SSL / WSS</h3><p>Confirms outer TLS, SNI and the selected adapter client.</p></article></div></section>

<section class="content-section" id="policy"><div class="kicker">Account policy</div><h2>What the same TDZ login enforces</h2><div class="grid two"><div class="callout"><span class="callout-mark">ID</span><div><strong>One username and password</strong><p>Profiles never contain credentials. Enter the existing TDZ account after import.</p></div></div><div class="callout"><span class="callout-mark">BW</span><div><strong>Shared usage accounting</strong><p>OpenVPN traffic is reconciled against the account bandwidth limit.</p></div></div><div class="callout"><span class="callout-mark">EX</span><div><strong>Expiry and first use</strong><p>Pending activation and expiry follow the same account lifecycle.</p></div></div><div class="callout"><span class="callout-mark">CN</span><div><strong>Connection admission</strong><p>Session limits are checked atomically before a connection is admitted.</p></div></div></div></section>

<section class="content-section" id="troubleshooting"><div class="kicker">Troubleshooting</div><h2>Understand the client log</h2><div class="table-wrap"><table><thead><tr><th>Log or symptom</th><th>Meaning</th><th>Check</th></tr></thead><tbody><tr><td><code>AUTH_FAILED</code></td><td>The transport reached OpenVPN, but account authentication failed.</td><td>Username/password, expiry, lock, quota and connection limit</td></tr><tr><td><code>Connection refused</code></td><td>No listener is reachable on that port.</td><td>Selected mode, VPS service and provider firewall/security group</td></tr><tr><td><code>TLS Error</code></td><td>The endpoint answered, but TLS or profile validation failed.</td><td>Correct profile, SNI, CA and device time</td></tr><tr><td><code>HTTP 200</code> or <code>101</code></td><td>The HTTP or WS adapter accepted the request.</td><td>Continue to the later OpenVPN authentication lines</td></tr><tr><td>SSH to this VPS while connected</td><td>The public adapter endpoint stays outside the VPN to prevent a routing loop.</td><td>Use the <code>ROUTE_GATEWAY</code> address from the client log with SSH port 22</td></tr></tbody></table></div><div class="panel warning spaced-panel"><span class="label">External firewall</span><p>The installer opens the local VPS firewall. If the provider has a separate firewall or security group, allow TCP $TDZ_OVPN_SSL_PORT, $TDZ_OVPN_TCP_PORT, $TDZ_OVPN_HTTP_PORT and $TDZ_OVPN_WSS_PORT, plus UDP $TDZ_OVPN_UDP_PORT.</p></div></section>
</article>
<aside class="toc" aria-label="On this page"><div class="toc-title">On this page</div><a href="#modes">Mode-by-mode setup</a><a href="#certificates">Certificate layers</a><a href="#payloads">Payload reference</a><a href="#verification">Verification order</a><a href="#policy">Account policy</a><a href="#troubleshooting">Troubleshooting</a></aside>
</main>
<footer class="footer"><div class="shell footer-grid"><section class="footer-profile"><a class="footer-brand" href="$TDZ_OVPN_PUBLIC_PATH/"><span class="brand-main">TDZ</span><span class="brand-dot">•</span><span>OVPN PORTAL</span></a><p>Secure OpenVPN transport access for TDZ SSH TUNNEL, with unified account policy and ready-to-import profiles.</p></section><section class="footer-column"><h2>Explore</h2><a href="$TDZ_OVPN_PUBLIC_PATH/">Overview</a><a href="$TDZ_OVPN_PUBLIC_PATH/docs">Documentation</a><a href="$TDZ_OVPN_PUBLIC_PATH/download">Downloads</a></section><section class="footer-column footer-developer"><p class="developer-line"><span>Developed By:</span><a class="developer-link" href="https://tuhinbro.com/" target="_blank" rel="noopener noreferrer">Yeasinul Hoque Tuhin</a></p><p class="developer-line"><span>Telegram:</span><a class="developer-link" href="https://t.me/TuhinBroh" target="_blank" rel="noopener noreferrer">@TuhinBroh</a></p><p class="developer-note">Reliable OpenVPN access, thoughtfully crafted for the TDZ SSH TUNNEL ecosystem.</p></section></div><div class="shell footer-bottom"><span>TDZ SSH TUNNEL • OpenVPN Suite</span></div></footer>
</body></html>
EOF

    cat > "$TDZ_OVPN_PROFILES/download.html" <<EOF
<!doctype html>
<html lang="en"><head><meta charset="utf-8"><meta name="viewport" content="width=device-width,initial-scale=1"><meta name="description" content="Download TDZ OpenVPN profiles"><title>TDZ • OVPN PORTAL</title><script src="$TDZ_OVPN_PUBLIC_PATH/assets/portal.js"></script><link rel="stylesheet" href="$TDZ_OVPN_PUBLIC_PATH/assets/portal.css"></head><body>
<header class="site-header"><div class="shell nav"><a class="brand" href="$TDZ_OVPN_PUBLIC_PATH/"><span class="brand-main">TDZ</span><span class="brand-dot">•</span><span>OVPN PORTAL</span></a><nav class="nav-links" aria-label="Portal navigation"><a href="$TDZ_OVPN_PUBLIC_PATH/">Overview</a><a href="$TDZ_OVPN_PUBLIC_PATH/docs">Documentation</a><a class="active" href="$TDZ_OVPN_PUBLIC_PATH/download">Downloads</a></nav><button class="theme-toggle" type="button" data-theme-toggle data-theme-mode="system"><span class="theme-glyph" aria-hidden="true"></span><span data-theme-label>System</span></button></div></header>
<main class="shell"><header class="page-intro"><div class="eyebrow">TDZ • OVPN PORTAL</div><h1>Profile <span>downloads.</span></h1><p>Choose one transport or take the complete package. After import, sign in with the existing TDZ account—no credential is embedded in a profile.</p><div class="actions"><a class="button primary" href="$TDZ_OVPN_PUBLIC_PATH/download/openvpn-profiles.zip">Download complete ZIP</a><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/docs">Read configuration guide</a></div></header>

<section class="section"><div class="section-head"><div><div class="kicker">Official clients</div><h2>Direct OpenVPN profiles</h2></div><p>These profiles import directly into standard OpenVPN-compatible clients without an external payload adapter.</p></div><div class="grid">
<article class="card download-card"><span class="status">UDP • $TDZ_OVPN_UDP_PORT</span><h3>Direct UDP</h3><p class="note">Recommended for speed and low latency.</p><p class="filename">tdz-openvpn-udp.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-udp.ovpn">Download UDP</a></article>
<article class="card download-card"><span class="status">TCP • $TDZ_OVPN_TCP_PORT</span><h3>Direct TCP</h3><p class="note">Reliable standard TCP transport.</p><p class="filename">tdz-openvpn-tcp.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-tcp.ovpn">Download TCP</a></article>
<article class="card download-card"><span class="status">HTTP • $TDZ_OVPN_HTTP_PORT</span><h3>HTTP CONNECT</h3><p class="note">Native HTTP proxy profile for compatible official clients.</p><p class="filename">tdz-openvpn-http-connect.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-http-connect.ovpn">Download HTTP</a></article>
</div></section>

<section class="section"><div class="section-head"><div><div class="kicker">Adapter clients</div><h2>Payload, WebSocket and TLS profiles</h2></div><p>Use these with a client that explicitly supports the matching HTTP, WebSocket or outer-TLS tunnel mode.</p></div><div class="grid">
<article class="card download-card"><span class="status">WS • $TDZ_OVPN_HTTP_PORT</span><h3>HTTP Payload / WS</h3><p class="note">Requires a compatible OpenVPN injector.</p><p class="filename">tdz-openvpn-ws-injector.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-ws-injector.ovpn">Download WS</a></article>
<article class="card download-card"><span class="status">WSS • $TDZ_OVPN_WSS_PORT</span><h3>WSS / SNI</h3><p class="note">TLS WebSocket adapter; SNI is $TDZ_OVPN_HOST.</p><p class="filename">tdz-openvpn-wss-injector.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-wss-injector.ovpn">Download WSS</a></article>
<article class="card download-card"><span class="status">SSL • $TDZ_OVPN_SSL_PORT</span><h3>SSL / SNI</h3><p class="note">Raw TLS adapter; SNI is $TDZ_OVPN_HOST.</p><p class="filename">tdz-openvpn-ssl-injector.ovpn</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-ssl-injector.ovpn">Download SSL</a></article>
</div></section>

<section class="section bundle"><article class="panel policy"><span class="label">Complete package</span><h2>Everything in one archive</h2><p>All six profiles, the server CA and a small offline reference for use when this portal is unavailable.</p><a class="button primary" href="$TDZ_OVPN_PUBLIC_PATH/download/openvpn-profiles.zip">Download complete ZIP</a></article><article class="panel warning"><span class="label">Server CA</span><h2>Certificate authority</h2><p>Included inside every profile and also available separately for compatible clients.</p><a class="button" href="$TDZ_OVPN_PUBLIC_PATH/download/tdz-openvpn-ca.crt">Download CA</a></article></section>

<section class="section"><div class="section-head"><div><div class="kicker">Choose confidently</div><h2>Which file should you start with?</h2></div></div><div class="table-wrap"><table><thead><tr><th>Network condition</th><th>Start with</th><th>Why</th></tr></thead><tbody><tr><td>Normal mobile or Wi-Fi</td><td><code>Direct UDP</code></td><td>Lowest overhead and usually the best performance</td></tr><tr><td>UDP blocked or unstable</td><td><code>Direct TCP</code></td><td>Uses a standard TCP OpenVPN connection</td></tr><tr><td>HTTP proxy client required</td><td><code>HTTP CONNECT</code></td><td>Contains the native OpenVPN HTTP proxy directive</td></tr><tr><td>Injector with custom payload</td><td><code>Payload / WS</code></td><td>Designed for the external HTTP or WebSocket adapter</td></tr><tr><td>TLS adapter with SNI</td><td><code>WSS or SSL</code></td><td>Matches the selected outer-TLS client mode</td></tr></tbody></table></div></section>
</main>
<footer class="footer"><div class="shell footer-grid"><section class="footer-profile"><a class="footer-brand" href="$TDZ_OVPN_PUBLIC_PATH/"><span class="brand-main">TDZ</span><span class="brand-dot">•</span><span>OVPN PORTAL</span></a><p>Secure OpenVPN transport access for TDZ SSH TUNNEL, with unified account policy and ready-to-import profiles.</p></section><section class="footer-column"><h2>Explore</h2><a href="$TDZ_OVPN_PUBLIC_PATH/">Overview</a><a href="$TDZ_OVPN_PUBLIC_PATH/docs">Documentation</a><a href="$TDZ_OVPN_PUBLIC_PATH/download">Downloads</a></section><section class="footer-column footer-developer"><p class="developer-line"><span>Developed By:</span><a class="developer-link" href="https://tuhinbro.com/" target="_blank" rel="noopener noreferrer">Yeasinul Hoque Tuhin</a></p><p class="developer-line"><span>Telegram:</span><a class="developer-link" href="https://t.me/TuhinBroh" target="_blank" rel="noopener noreferrer">@TuhinBroh</a></p><p class="developer-note">Reliable OpenVPN access, thoughtfully crafted for the TDZ SSH TUNNEL ecosystem.</p></section></div><div class="shell footer-bottom"><span>TDZ SSH TUNNEL • OpenVPN Suite</span></div></footer>
</body></html>
EOF
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
    else
        printf '  Server: %s\n  Portal: https://%s:%s%s/\n' \
            "$TDZ_OVPN_HOST" "$TDZ_OVPN_HOST" "$TDZ_OVPN_PORTAL_PORT" "$TDZ_OVPN_PUBLIC_PATH"
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
    local username=${1:-} reason=${2:-policy}
    [[ -x "$TDZ_OVPN_RUNTIME" && -n "$username" ]] || return 0
    "$TDZ_OVPN_RUNTIME" kill-user "$username" "$reason" >/dev/null 2>&1 || true
}
