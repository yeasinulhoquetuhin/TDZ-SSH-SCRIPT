#!/bin/bash
set -e

REPO="yeasinulhoquetuhin/TDZ-SSH-SCRIPT"
BIN_DIR="/usr/local/tdz"

RED="\033[1;31m"
GREEN="\033[1;32m"
CYAN="\033[1;36m"
NC="\033[0m"

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

# ── Check root ──
if [ "$(id -u)" != "0" ]; then
    echo -e "${RED}[ERROR] Must run as root!${NC}"
    exit 1
fi

ARCH=$(detect_arch)
URL="https://github.com/${REPO}/releases/latest/download/tdz-linux-${ARCH}.tar.gz"

echo ""
echo -e "${CYAN}============================================${NC}"
echo -e "${CYAN}   TDZ SSH TUNNEL - Binary Installer${NC}"
echo -e "${CYAN}   Architecture: ${ARCH}${NC}"
echo -e "${CYAN}============================================${NC}"
echo ""

# ── Download ──
echo -e "${GREEN}[1/3] Downloading binary...${NC}"
mkdir -p "${BIN_DIR}"
cd "${BIN_DIR}"
curl -fsSL -o tdz.tar.gz "${URL}"
tar xzf tdz.tar.gz
chmod +x tdz
rm -f tdz.tar.gz

# ── Symlinks ──
ln -sf "${BIN_DIR}/tdz" /usr/local/bin/menu 2>/dev/null || true
ln -sf "${BIN_DIR}/tdz" /usr/local/bin/tdz 2>/dev/null || true

echo -e "${GREEN}[2/3] Binary installed (${ARCH})${NC}"
echo ""

# ── Run TDZ setup ──
echo -e "${GREEN}[3/3] Running TDZ setup...${NC}"
echo ""
"${BIN_DIR}/tdz" install

echo ""
echo -e "${CYAN}============================================${NC}"
echo -e "${GREEN}   TDZ SSH TUNNEL Installed!${NC}"
echo -e "${CYAN}   Run: menu${NC}"
echo -e "${CYAN}============================================${NC}"
