#!/bin/bash
set -e

RED="\033[1;31m"; GREEN="\033[1;32m"; CYAN="\033[1;36m"; NC="\033[0m"

if [ "$(id -u)" != "0" ]; then
    echo -e "${RED}[ERROR] Must run as root!${NC}"
    exit 1
fi

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
BIN_DIR="/usr/local/tdz"
URL="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/releases/latest/download/tdz-linux-${ARCH}.tar.gz"

echo ""
echo -e "${CYAN}TDZ SSH TUNNEL - Binary Installer${NC}"
echo ""

mkdir -p "${BIN_DIR}"
cd "${BIN_DIR}"
curl -fsSL -o tdz.tar.gz "${URL}"
tar xzf tdz.tar.gz
chmod +x tdz
rm -f tdz.tar.gz

ln -sf "${BIN_DIR}/tdz" /usr/local/bin/menu 2>/dev/null || true
ln -sf "${BIN_DIR}/tdz" /usr/local/bin/tdz 2>/dev/null || true

"${BIN_DIR}/tdz" install

echo ""
echo -e "${GREEN}Done! Type: menu${NC}"
echo ""
