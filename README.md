<p align="center">
  <img src="https://img.shields.io/badge/TDZ-SSH--SCRIPT-00d4ff?style=for-the-badge&logo=linux&logoColor=black" alt="TDZ SSH SCRIPT">
  <img src="https://img.shields.io/badge/Version-2.0-green?style=for-the-badge" alt="Version">
  <img src="https://img.shields.io/badge/Platform-Linux-blue?style=for-the-badge&logo=linux" alt="Platform">
  <img src="https://img.shields.io/badge/Shell-Bash-4EAA25?style=for-the-badge&logo=gnubash&logoColor=white" alt="Bash">
</p>

<h1 align="center">TDZ SSH TUNNEL</h1>

<p align="center">
  <b>Advanced SSH Tunnel Management System for Linux VPS</b><br>
  Developed & maintained by <a href="https://tuhinbro.com"><b>Yeasinul Hoque Tuhin</b></a>
</p>

<p align="center">
  <a href="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/stargazers"><img src="https://img.shields.io/github/stars/yeasinulhoquetuhin/TDZ-SSH-SCRIPT?style=social" alt="Stars"></a>
  <a href="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/releases"><img src="https://img.shields.io/badge/Release-Stable-brightgreen" alt="Release"></a>
  <a href="https://t.me/TuhinBroh"><img src="https://img.shields.io/badge/Telegram-@TuhinBroh-2CA5E0?style=flat-square&logo=telegram" alt="Telegram"></a>
  <a href="https://t.me/TUSTDZ"><img src="https://img.shields.io/badge/Support-@TUSTDZ-2CA5E0?style=flat-square&logo=telegram" alt="Support"></a>
</p>

---

## Overview

TDZ SSH TUNNEL is a comprehensive, bash-based SSH tunnel management system designed for Linux VPS servers. It provides a full-featured CLI dashboard for managing SSH tunnel users, monitoring bandwidth, controlling access, and deploying multiple tunnel protocols — all from a single interactive menu.

Built from scratch by **Yeasinul Hoque Tuhin**, this project represents a complete, ground-up implementation of a modern SSH tunnel management solution, independently developed with advanced features including dynamic HTML banners, per-user traffic accounting, multi-protocol support, and automated user lifecycle management.

---

## Features

### User Management
- **Create / Delete / Edit users** — full CRUD operations with password, expiry, session limit, and bandwidth controls
- **Bulk user creation** — generate multiple accounts at once with shared or individual settings
- **Trial accounts** — auto-expiring demo users with configurable duration (1h to 72h) and automatic cleanup
- **Account locking / unlocking** — manually lock or unlock any user account instantly
- **Account renewal** — extend expiry, adjust limits, or reset passwords for existing users
- **Expired user cleanup** — one-click removal of all expired accounts
- **User list with live status** — view all users with real-time online status, bandwidth usage, and remaining quota

### Bandwidth & Traffic
- **Per-user bandwidth tracking** — real-time I/O monitoring via `/proc/<pid>/io` with per-PID delta calculation
- **Data quotas** — set per-user bandwidth limits in GB; users exceeding quota are automatically locked
- **Live traffic monitor** — real-time dashboard showing per-user data consumption
- **Torrent blocking** — automatically block BitTorrent traffic per user

### Dynamic HTML Banners (DarkTunnel Compatible)
- **Status-aware banners** — automatically shows different messages based on account state:
  - **Active** — account details with usage info
  - **Expired** — renewal prompt with contact link
  - **Traffic Ended** — data top-up prompt with contact link
  - **Locked** — unlock request message with contact link
- **DarkTunnel optimized** — HTML banners render perfectly in DarkTunnel and similar SSH client apps
- **Auto-updating** — banners refresh every second to reflect current session counts and bandwidth

### Tunnel Protocols
- **SSH (Direct)** — standard SSH tunnel on port 22
- **stunnel4 TLS** — TLS-wrapped SSH on port 2288 for firewall bypass
- **WebSocket NTLS** — non-TLS WebSocket payload on port 2289
- **BadVPN / UDPGW** — UDP game tunneling on port 7300
- **DNSTT** — DNS-based tunneling on port 5300
- **ZiVPN** — additional tunnel protocol support

### Network & Proxy
- **HAProxy** — reverse-proxy edge server on ports 2080 (HTTP) and 442 (HTTPS)
- **Nginx SSL termination** — internal proxy with shared TLS certificates
- **WS-to-SSH bridge** — DarkTunnel-compatible WebSocket bridge that accepts non-standard payloads and bridges to SSH
- **SSL/TLS certificates** — Let's Encrypt (certbot) and self-signed certificate management

### Branding & Customization
- **Rainbow ANSI banners** — colorful SSH login banners with per-character coloring
- **Premium CLI theme** — professional color-coded terminal interface with Navy + Cyan theme

### Backup & Recovery
- **Full user data backup** — archive all user configurations and data
- **Auto backup to Telegram** — scheduled automatic backups sent directly to your Telegram bot
- **Data restore** — restore user data from backup archives
- **Edge config backup** — backup HAProxy, Nginx, and SSL configurations

### System & Monitoring
- **Auto-reboot scheduler** — configure automatic VPS reboots at set intervals
- **Connection limit enforcement** — automatically kill excess SSH sessions beyond per-user limits
- **Service management** — start/stop/restart all TDZ services from the menu
- **X-UI panel integration** — optional X-UI panel installation for advanced proxy management

---

## Installation

**One-line install (as root):**

```bash
bash <(curl -Ls https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/install.sh)
```

**Manual install:**

```bash
curl -LO https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/install.sh
chmod +x install.sh
./install.sh
```

After installation, type **`menu`** to launch the management interface.

---

## Repository Structure

```
TDZ-SSH-SCRIPT/
├── install.sh           # One-shot installer
├── menu.sh              # Main management script (all features)
├── ssh                  # Hardened sshd configuration
├── ws_ssh_bridge.py     # DarkTunnel WS-to-SSH bridge
├── .github/             # GitHub workflows
└── README.md            # Documentation
```


## Default Ports

| Port | Protocol | Purpose |
|---|---|---|
| 22 | SSH | Primary SSH access |
| 2288 | TLS | stunnel4-wrapped SSH |
| 2289 | WS | WebSocket NTLS payload |
| 7300 | UDP | BadVPN / UDPGW |
| 5300 | DNS | DNSTT tunnel |
| 2080 | HTTP | HAProxy edge (HTTP) |
| 442 | HTTPS | HAProxy edge (TLS) |
| 8880 | HTTP | Nginx internal proxy |
| 8442 | HTTPS | Nginx internal TLS proxy |
| 8890 | TCP | WS-to-SSH bridge |

## Supported Platforms

| Platform | Architecture |
|---|---|
| Ubuntu 20.04 / 22.04 / 24.04 | amd64, arm64 |
| Debian 11 / 12 | amd64, arm64 |
| Other Debian-based distros | amd64 |

> **Note:** Root access is required for installation and operation.

## Uninstall

```
menu → 0) Uninstall
```

Or directly:

```bash
bash /usr/local/bin/menu --uninstall
```

## Credits & License

- **Developer:** [Yeasinul Hoque Tuhin](https://tuhinbro.com)
- **Project:** TDZ SSH TUNNEL — independently developed from scratch
- **Third-party components:** BadVPN, DNSTT, stunnel4, HAProxy, Nginx, certbot (each retains its own license)

---

<p align="center">
  <b>TDZ SSH TUNNEL</b> — Developed with dedication by <a href="https://t.me/TuhinBroh"><b>Yeasinul Hoque Tuhin</b></a><br>
  <i>For support, contact <a href="https://t.me/TUSTDZ">🇹‌🇺‌🇸‌</a> on Telegram</i>
</p>
