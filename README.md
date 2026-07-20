<p align="center">
  <img src="https://img.shields.io/badge/TDZ-SSH--SCRIPT-00d4ff?style=for-the-badge&logo=linux&logoColor=black" alt="TDZ SSH SCRIPT">
  <img src="https://img.shields.io/badge/Version-0.0.1-green?style=for-the-badge" alt="Version">
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

## Screenshots

### Main Dashboard

<p align="center">
  <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/main-dashboard.png" alt="TDZ SSH TUNNEL main dashboard" width="430">
</p>

The live dashboard brings server information, service health, user management, protocols, maintenance tools, and the danger zone into one organized terminal interface.

### Managed Accounts

<p align="center">
  <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/managed-users.png" alt="TDZ SSH TUNNEL managed user list" width="760">
</p>

Account status, expiration, remaining validity, active connections, and compact GB/TB traffic usage are displayed together for quick monitoring.

### Management Screens

<table>
  <tr>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/public-port-management.png" alt="Public port management" height="170"><br>
      <b>Public Ports</b>
    </td>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/edit-user.png" alt="Edit SSH user" height="170"><br>
      <b>Edit User</b>
    </td>
  </tr>
  <tr>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/domain-ssl.png" alt="Domain and SSL certificate management" height="170"><br>
      <b>Domain &amp; SSL</b>
    </td>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/backup-restore.png" alt="Telegram backup and restore" height="170"><br>
      <b>Backup &amp; Restore</b>
    </td>
  </tr>
  <tr>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/protocol-panel-management.png" alt="Protocol and panel management" height="170"><br>
      <b>Protocols &amp; Panels</b>
    </td>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/ssh-banner-management.png" alt="SSH banner management" height="170"><br>
      <b>SSH Banners</b>
    </td>
  </tr>
</table>

---

## Features

### User Management
- **Create / Delete / Edit users** — full CRUD operations with safe username changes, password, expiry, session limit, and bandwidth controls
- **Bulk user creation** — generate multiple accounts at once with shared or individual settings
- **Start After First Use** — optionally keep a new or bulk-created account's validity paused until its first successful SSH connection; disabled by default. Editing a pending account changes its post-connection validity without starting the expiry clock
- **Trial accounts** — create 1h-to-72h auto-expiring demo users with automatic cleanup and a dedicated list for remaining time, usage, connections, and status
- **Account locking / unlocking** — manually lock or unlock any user account instantly
- **Account renewal** — extend expiry, adjust limits, or reset passwords for existing users
- **Expired user cleanup** — one-click removal of all expired accounts
- **User list with live status** — view all users with real-time online status, bandwidth usage, and remaining quota

### Bandwidth & Traffic
- **Per-user bandwidth tracking** — real-time I/O monitoring via `/proc/<pid>/io` with per-PID delta calculation
- **Data quotas** — set per-user bandwidth limits in GB; exhausted accounts are denied and disconnected without being confused with an administrator lock
- **Live traffic monitor** — real-time dashboard showing per-user data consumption
- **Torrent blocking** — automatically block BitTorrent traffic per user

### Dynamic HTML Banners
- **Status-aware banners** — automatically shows different messages based on account state:
  - **Active** — account details with usage info
  - **Expired** — renewal prompt with contact link
  - **Traffic Ended** — data top-up prompt with contact link
  - **Locked** — unlock request message with contact link
- **DarkTunnel optimized** — HTML banners render perfectly in DarkTunnel and similar SSH client apps
- **Authenticated live banners** — account details are delivered only after successful SSH authentication; failed attempts receive no private account data and never enter the session count
- **Immediate session lifecycle** — the successful connection is included in its own banner, while PID plus process-start-time tracking removes disconnected sessions and rejects stale PID reuse
- **Reason-aware denial** — a correct password for an expired, quota-ended, or manually locked account receives its private reason banner and is then denied; an incorrect password receives neither the banner nor a session marker
- **Reconnect-loop guard** — after that private denial banner, immediate valid-password retries become a normal authentication failure instead of repeatedly reopening and redisplaying the denied connection
- **Auto-updating data** — generated banner data refreshes every second to reflect current bandwidth and established SSH/OpenVPN sessions
- **Custom Admin & Channel usernames** — replace the default Telegram usernames with your own in the Dynamic Banner; matching `t.me/` links are generated automatically

### Tunnel Protocols
- **SSH (Direct)** — standard SSH tunnel on port 22
- **OpenVPN protocol suite** — optional direct UDP/TCP, native HTTP CONNECT, HTTP Payload/WebSocket, WSS/SNI, and SSL/SNI transports with downloadable profiles
- **stunnel4 TLS** — TLS-wrapped SSH on port 2288 for firewall bypass
- **WebSocket NTLS** — non-TLS WebSocket payload on port 2289
- **BadVPN / UDPGW** — UDP game tunneling on port 7300
- **DNSTT** — DNS-based tunneling on port 5300
- **ZiVPN** — additional tunnel protocol support

### Network & Proxy
- **HAProxy** — reverse-proxy edge server on configurable public ports (defaults: 2080 HTTP, 442 HTTPS)
- **Nginx SSL termination** — internal proxy with shared TLS certificates
- **WS-to-SSH bridge** — DarkTunnel-compatible WebSocket bridge that accepts non-standard payloads and bridges to SSH
- **SSL/TLS certificates** — issue or renew Let's Encrypt certificates, generate self-signed certificates, reuse existing Certbot certificates, or import a custom fullchain and private key
- **Customizable public ports** — change the public HTTP/WS and TLS/SSL ports from the menu with validation and automatic rollback

### Branding & Customization
- **Rainbow ANSI banners** — colorful SSH login banners with per-character coloring
- **Premium CLI theme** — professional color-coded terminal interface with Navy + Cyan theme

### Backup & Recovery
- **Full user data backup** — archive all user configurations, usage data, and explicit manual-lock policy
- **Auto backup to Telegram** — scheduled automatic backups sent directly to your Telegram bot
- **Data restore** — restore user data from backup archives
- **Edge config backup** — backup HAProxy, Nginx, and SSL configurations

### System & Monitoring
- **Auto-reboot scheduler** — configure automatic VPS reboots at set intervals
- **Connection limit enforcement** — automatically kill excess SSH sessions beyond per-user limits
- **Filtered account views** — List Users provides All, Expired, Quota Ended, and Online views from the same live policy state used by enforcement
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

## OpenVPN Protocol Suite

Open **`menu → 13) Protocol Manager → 10) OpenVPN Protocol Suite`** to install or manage OpenVPN. The component is optional: installing or removing it does not remove TDZ users or change the existing SSH, HAProxy, Nginx, DNSTT, BadVPN, ZiVPN, banner, certificate, or backup configuration.

During first installation, TDZ asks for the public VPS IP or domain. It starts with portal port `1180` and transport ports `446–450`, creates fresh server cryptographic material, applies isolated VPN subnets, starts the required services, and verifies that every listener is active. These are defaults rather than permanent restrictions. From the OpenVPN Suite menu, **Change Portal and Method Ports** can update the portal, SSL, TCP, UDP, HTTP/WS, and WSS ports together. The saved layout survives installer updates and repairs. Every change transactionally rebuilds the server configs, systemd listeners, firewall rules, downloadable profiles, ZIP, portal pages, and displayed connection details; if validation fails, the last working layout is restored automatically.

The optional suite requires Python 3.7 or newer. On an older distribution the core TDZ SSH features remain available, while OpenVPN installation stops safely without changing the existing setup.

| Mode | Client support | Profile / setup |
|---|---|---|
| **Direct UDP** | Official OpenVPN clients | Ready-to-import `.ovpn` profile |
| **Direct TCP** | Official OpenVPN clients | Ready-to-import `.ovpn` profile |
| **HTTP CONNECT** | Official OpenVPN clients | Native OpenVPN HTTP proxy profile |
| **HTTP Payload / WebSocket** | Compatible injector or WebSocket adapter | Injector profile plus payload template |
| **WSS / SNI** | Compatible TLS WebSocket adapter | Injector profile; use the configured host as SNI |
| **SSL / SNI** | Compatible external SSL/TLS adapter | Injector profile; use the configured host as SNI |

The OpenVPN portal is generated automatically:

```text
http://VPS-IP-OR-HOST:1180/openvpn/
https://VPS-IP-OR-HOST:1180/openvpn/
```

The responsive portal uses a glass navigation header, a three-way **Light / Auto / Dark** theme control, a guided first-connection flow, and focused overview, setup, and download pages. Full client fields, copyable payloads, SNI values, verification order, and client-focused troubleshooting are available at `/openvpn/docs`; individual profiles, the complete ZIP, and the server CA are available at `/openvpn/download`. The managed portal accepts both HTTP and HTTPS on its configured port (`1180` by default); HTTPS is strongly recommended when downloading profiles because HTTP cannot prevent network-side tampering. The offline text guide remains inside the ZIP but is no longer required to understand the setup. Profiles never contain an account username or password. Users import a profile and sign in with the same SSH/OVPN account credentials.

Visitors who do not yet have an SSH/OVPN account see a clear account/support contact action on every portal page. The default contact is **`@TUSTDZ`**. Change it from **`menu → 13) Protocol Manager → 10) OpenVPN Protocol Suite → 8) Change Contact Username`**; the saved contact is validated, propagated to the portal and offline guide, and updated without restarting OpenVPN listeners or disconnecting active VPN sessions.

The portal uses the same validated outer certificate as WSS and SSL. A matching certificate applied through **Domain & SSL Cert** is reused automatically across all three services; if it does not cover the saved OpenVPN host, the last working adapter certificate is preserved and the menu reports the mismatch. The private OpenVPN CA remains separate and embedded in every profile.

### Shared account enforcement

- SSH and OpenVPN use the same TDZ user database and Linux password
- Manual lock and account deletion terminate both SSH and OpenVPN sessions
- Manual locks are stored separately from expiry and quota state, so the Unlock menu contains only accounts an administrator deliberately locked
- Expiry and **Start After First Use** apply to the first successful SSH or OpenVPN login
- The configured connection limit is shared across active SSH and OpenVPN sessions
- Bandwidth usage from both transports is added to the same per-user quota without double counting
- Expired or quota-exhausted accounts are disconnected and denied automatically, while renewing or topping up restores access without changing an independent manual lock
- VPN clients are isolated from one another and cannot use the transport gateway as an open proxy

Direct UDP, direct TCP, and HTTP CONNECT work in current official OpenVPN clients. Payload, WS, WSS, and SSL are adapter transports and therefore require an app that implements the corresponding outer payload or TLS/WebSocket layer. Adapter profiles omit newer cipher directives rejected by several embedded Android OpenVPN cores; modern TCP adapter clients prefer AES-128-GCM for lower mobile CPU cost while AES-256-GCM remains available as the compatibility fallback. Direct UDP retains AES-256-GCM priority.

Compatibility follows the official OpenVPN transport model: the core protocol runs over TCP or UDP, while HTTP proxy mode uses TCP. Session status and forced disconnects use the local OpenVPN management interface. See the [OpenVPN protocol reference](https://openvpn.net/community-docs/openvpn-protocol.html), [HTTP proxy guide](https://openvpn.net/community-docs/connecting-to-an-openvpn-server-via-an-http-proxy.html), and [management interface reference](https://openvpn.net/community-docs/management-interface.html).

---

## SSL Certificate — Menu 17

Open **`menu → 17) Domain & SSL Cert`** to manage the shared certificate used by the TDZ edge stack.

| Option | Action |
|---|---|
| **1** | Issue a new Let's Encrypt certificate or renew one for a domain |
| **2** | Generate a self-signed certificate |
| **3** | List existing Certbot certificates with remaining validity, then apply an existing certificate or renew and apply it |
| **4** | Import a custom certificate by entering the paths to its `fullchain.pem` and matching `privkey.pem` |
| **5** | Remove the currently selected shared certificate |

For custom import, provide both files when prompted:

```text
Fullchain file path: /path/to/fullchain.pem
Private key file path: /path/to/privkey.pem
```

Before applying a certificate, TDZ verifies that the fullchain is valid and that its public key matches the private key. It then validates the active Nginx and HAProxy configuration. If validation or service restart fails, the previous working certificate is restored automatically.

---



## Default Ports

| Port | Protocol | Purpose |
|---|---|---|
| 22 | SSH | Primary SSH access |
| 2288 | TLS | stunnel4-wrapped SSH |
| 2289 | WS | WebSocket NTLS payload |
| 7300 | UDP | BadVPN / UDPGW |
| 5300 | DNS | DNSTT tunnel |
| 2080 | HTTP | HAProxy edge (HTTP, configurable default) |
| 442 | HTTPS | HAProxy edge (TLS, configurable default) |
| 8770 | HTTP | Nginx internal proxy |
| 8442 | HTTPS | Nginx internal TLS proxy |
| 8890 | TCP | WS-to-SSH bridge |
| 446 | TLS | OpenVPN SSL / SNI adapter (configurable default) |
| 447 | TCP | OpenVPN direct TCP backend (configurable default) |
| 448 | UDP | OpenVPN direct UDP transport (configurable default) |
| 449 | HTTP / WS | OpenVPN HTTP CONNECT, HTTP Payload, and WebSocket gateway (configurable default) |
| 450 | WSS | OpenVPN TLS WebSocket / SNI gateway (configurable default) |
| 1180 | HTTP / HTTPS | OpenVPN documentation and profile portal; configurable default, both protocols are accepted |

## Supported Platforms

TDZ SSH TUNNEL is designed for Debian-family VPS systems that use **APT** and **systemd**. It is not limited to only the versions shown in the old compatibility table.

| Distribution / family | Versions | Support level |
|---|---|---|
| **Ubuntu Server** | 18.04, 20.04, 22.04, 24.04 and newer releases | Compatible; current LTS releases are recommended |
| **Debian** | 10, 11, 12, 13 and newer releases | Compatible; current stable releases are recommended |
| **Kali Linux** | Current rolling releases | Compatible when running with systemd |
| **Linux Mint / LMDE** | Current Debian- or Ubuntu-based releases | Compatible when the required server packages are available |
| **Armbian** | Current Debian- or Ubuntu-based releases | Compatible; optional protocol availability depends on CPU architecture |
| **Other Debian/Ubuntu-based systems** | Current APT-based releases | Expected to work when Bash, OpenSSH, APT and systemd are available |

### CPU Architectures

| Architecture name | Common aliases | Support |
|---|---|---|
| **64-bit Intel/AMD** | `amd64`, `x86_64` | Full core support and the widest optional protocol support |
| **64-bit ARM** | `arm64`, `aarch64` | Full core support; most optional protocol components are available |
| **32-bit ARM** | `armv7l`, `armhf`, `arm` | Core management features can run; some prebuilt optional protocol components may be unavailable |

The installer automatically detects an existing installation, operating environment and CPU architecture. If a particular optional protocol has no binary for the detected CPU, only that component is skipped—the main TDZ menu, SSH user management, limits, banners, backup and restore features remain available.

> **Note:** Root access is required for installation and operation.

## Uninstall

```
menu → 99) Uninstall
```

## Credits & License

- **Developer:** [Yeasinul Hoque Tuhin](https://tuhinbro.com)
- **Project:** TDZ SSH TUNNEL — independently developed from scratch
- **Third-party components:** OpenVPN Community Edition, BadVPN, DNSTT, stunnel4, HAProxy, Nginx, certbot (each retains its own license)

---

<p align="center">
  <b>TDZ SSH TUNNEL</b> — Developed with dedication by <a href="https://t.me/TuhinBroh"><b>ᴛᴜʜɪɴ • ʙʀᴏ</b></a><br>
  <i>For support, contact <a href="https://t.me/Yeasinul_Hoque_Tuhin">Yeasinul Hoque Tuhin</a> on Telegram</i>
</p>
