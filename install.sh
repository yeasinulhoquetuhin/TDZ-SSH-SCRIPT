#!/bin/bash
set -e

# Must be root
if [[ $EUID -ne 0 ]]; then
   echo "Error: This script must be run as root."
   exit 1
fi

echo "Installing TDZ SSH TUNNEL..."

# Install from the current folder when the script is uploaded/copied to a VPS.
# Remote URLs can still be overridden by environment variables if needed.
SCRIPT_DIR="$(CDPATH= cd -- "$(dirname -- "$0")" && pwd)"
MENU_URL="${MENU_URL:-https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/menu.sh}"

# Install menu
if [[ -f "$SCRIPT_DIR/menu.sh" ]]; then
    cp "$SCRIPT_DIR/menu.sh" /usr/local/bin/menu
elif [[ -n "$MENU_URL" ]]; then
    wget -4 -q -O /usr/local/bin/menu "$MENU_URL"
else
    echo "ERROR: menu.sh not found beside install.sh and MENU_URL is not set."
    exit 1
fi
chmod +x /usr/local/bin/menu

if [[ -f "$SCRIPT_DIR/ws_ssh_bridge.py" ]]; then
    cp "$SCRIPT_DIR/ws_ssh_bridge.py" /usr/local/bin/tdz-ws-ssh-bridge.py
    chmod +x /usr/local/bin/tdz-ws-ssh-bridge.py
fi

echo "Applying TDZ SSH TUNNEL SSH configuration..."

SSHD_CONFIG="/etc/ssh/sshd_config"
SSHD_DROPIN_DIR="/etc/ssh/sshd_config.d"
SSHD_DROPIN="$SSHD_DROPIN_DIR/tdztunnel.conf"
BACKUP="$SSHD_CONFIG.backup.$(date +%F-%H%M%S)"

# Backup current SSH config
cp "$SSHD_CONFIG" "$BACKUP"
mkdir -p "$SSHD_DROPIN_DIR"

# OpenSSH keeps the first global AddressFamily/ListenAddress value it sees.
# If the provider base config says AddressFamily any + ListenAddress ::,
# a later drop-in cannot force IPv4-only reliably, so disable only those
# conflicting IPv6/global lines in the base file after backing it up.
sed -i \
    -e 's/^[[:space:]]*AddressFamily[[:space:]]\+any[[:space:]]*$/# TDZ disabled: AddressFamily any/' \
    -e 's/^[[:space:]]*ListenAddress[[:space:]]\+::[[:space:]]*$/# TDZ disabled: ListenAddress ::/' \
    "$SSHD_CONFIG"

# Keep the provider's base SSH config intact. Replacing the whole file can
# remove distro/provider networking hooks and lock the VPS out after reboot.
if ! grep -qE '^[[:space:]]*Include[[:space:]]+/etc/ssh/sshd_config\.d/\*\.conf' "$SSHD_CONFIG" 2>/dev/null; then
    printf '\n# TDZ SSH TUNNEL drop-ins\nInclude /etc/ssh/sshd_config.d/*.conf\n' >> "$SSHD_CONFIG"
fi

cat > "$SSHD_DROPIN" <<'EOF'
# TDZ SSH TUNNEL safe SSH settings
Port 22
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

# Validate SSH config (silent)
if ! sshd -t 2>/dev/null; then
    echo "ERROR: SSH configuration is invalid!"
    echo "Restoring previous configuration..."
    cp "$BACKUP" "$SSHD_CONFIG"
    rm -f "$SSHD_DROPIN"
    exit 1
fi

echo "SSH configuration validated."

# Restart SSH quietly and safely
restart_ssh() {
    if command -v systemctl >/dev/null 2>&1; then
        systemctl restart sshd 2>/dev/null \
        || systemctl restart ssh 2>/dev/null \
        || return 1
    elif command -v service >/dev/null 2>&1; then
        service sshd restart 2>/dev/null \
        || service ssh restart 2>/dev/null \
        || return 1
    elif command -v rc-service >/dev/null 2>&1; then
        rc-service sshd restart 2>/dev/null \
        || rc-service ssh restart 2>/dev/null \
        || return 1
    elif [ -x /etc/init.d/sshd ]; then
        /etc/init.d/sshd restart >/dev/null 2>&1
    elif [ -x /etc/init.d/ssh ]; then
        /etc/init.d/ssh restart >/dev/null 2>&1
    else
        return 1
    fi
}

if restart_ssh; then
    echo "SSH service restarted."
else
    echo "WARNING: SSH restart not supported on this system."
    echo "SSH config applied but service was not restarted automatically."
fi

# Run TDZ SSH TUNNEL setup
bash /usr/local/bin/menu --install-setup

echo "Installation complete!"
echo "Type 'menu' to start."
