#!/bin/bash
set -e

REPO="yeasinulhoquetuhin/TDZ-SSH-SCRIPT"
VERSION="${1:-latest}"
BIN="/usr/local/tdz"

detect_arch() {
    case "$(uname -m)" in
        x86_64|amd64) echo "amd64" ;;
        aarch64|arm64) echo "arm64" ;;
        i386|i686)     echo "i386" ;;
        armv7l)        echo "arm" ;;
        *) echo "amd64" ;;
    esac
}

ARCH=$(detect_arch)
URL="https://github.com/${REPO}/releases/${VERSION}/download/tdz-linux-${ARCH}.tar.gz"

echo "[*] Installing TDZ SSH TUNNEL..."
echo "    Arch: ${ARCH}"

mkdir -p "${BIN}"
cd "${BIN}"

if [ "${VERSION}" = "latest" ]; then
    URL=$(curl -sL "https://github.com/${REPO}/releases/latest" | grep -o "download/tdz-linux-${ARCH}.tar.gz" | head -1)
    URL="https://github.com/${REPO}/releases/latest/${URL}"
fi

curl -L -o tdz.tar.gz "${URL}"
tar xzf tdz.tar.gz
chmod +x tdz
rm -f tdz.tar.gz

ln -sf "${BIN}/tdz" /usr/local/bin/menu
ln -sf "${BIN}/tdz" /usr/local/bin/tdz

echo ""
echo "TDZ SSH TUNNEL installed!"
echo "Run: menu"
