#!/bin/bash
set -e

REPO="yeasinulhoquetuhin/TDZ-SSH-SCRIPT"
BIN="/usr/local/tdz"

detect_arch() {
    case "$(uname -m)" in
        x86_64|amd64) echo "amd64" ;;
        aarch64|arm64) echo "arm64" ;;
        i386|i686)     echo "i386" ;;
        armv7l)        echo "armv7" ;;
        armv6l)        echo "armv6" ;;
        armv5*)        echo "armv5" ;;
        s390x)         echo "s390x" ;;
        mips64*)       echo "mips64" ;;
        riscv64*)      echo "riscv64" ;;
        *) echo "amd64" ;;
    esac
}

ARCH=$(detect_arch)
URL="https://github.com/${REPO}/releases/latest/download/tdz-linux-${ARCH}.tar.gz"

echo "[*] TDZ SSH TUNNEL Installer"
echo "    Arch: ${ARCH}"
echo "    Downloading..."

mkdir -p "${BIN}"
cd "${BIN}"

curl -fsSL -o tdz.tar.gz "${URL}"
tar xzf tdz.tar.gz
chmod +x tdz
rm -f tdz.tar.gz

ln -sf "${BIN}/tdz" /usr/local/bin/menu
ln -sf "${BIN}/tdz" /usr/local/bin/tdz

echo ""
echo "[OK] TDZ SSH TUNNEL installed!"
echo "     Run: menu"
