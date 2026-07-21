<p align="center">
  <img src="https://img.shields.io/badge/TDZ-SSH--SCRIPT-00d4ff?style=for-the-badge&logo=linux&logoColor=black" alt="TDZ SSH SCRIPT">
  <img src="https://img.shields.io/badge/Release-v0.0.1_BETA-green?style=for-the-badge" alt="Release">
  <img src="https://img.shields.io/badge/Platform-Linux-blue?style=for-the-badge&logo=linux" alt="Platform">
  <img src="https://img.shields.io/badge/Runtime-Go_Binary-00ADD8?style=for-the-badge&logo=go&logoColor=white" alt="Go binary runtime">
</p>

<h1 align="center">TDZ SSH TUNNEL</h1>

<p align="center">
  <b>Advanced SSH Tunnel Management System for Linux VPS</b><br>
  Developed & maintained by <a href="https://tuhinbro.com"><b>Yeasinul Hoque Tuhin</b></a>
</p>

<p align="center">
  <a href="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/stargazers"><img src="https://img.shields.io/github/stars/yeasinulhoquetuhin/TDZ-SSH-SCRIPT?style=social" alt="Stars"></a>
  <a href="https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/releases"><img src="https://img.shields.io/badge/Release-v0.0.1_BETA-brightgreen" alt="Release"></a>
  <a href="https://t.me/TuhinBroh"><img src="https://img.shields.io/badge/Telegram-@TuhinBroh-2CA5E0?style=flat-square&logo=telegram" alt="Telegram"></a>
  <a href="https://t.me/TUSTDZ"><img src="https://img.shields.io/badge/Support-@TUSTDZ-2CA5E0?style=flat-square&logo=telegram" alt="Support"></a>
</p>

---

## Overview

TDZ SSH TUNNEL is a binary-distributed SSH tunnel management system designed for Linux VPS servers. It provides a full-featured CLI dashboard for managing SSH tunnel users, monitoring bandwidth, controlling access, and deploying multiple tunnel protocols — all from a single interactive menu.

Built from scratch by **Yeasinul Hoque Tuhin**, this project represents a complete, ground-up implementation of a modern SSH tunnel management solution, independently developed with advanced features including dynamic HTML banners, per-user traffic accounting, multi-protocol support, and automated user lifecycle management.

## v0.0.1 BETA Release

The official installer selects the correct architecture-specific package,
verifies its checksum, and safely installs or updates TDZ SSH TUNNEL.

- **Eight Linux builds:** `amd64`, `arm64`, `armv7`, `armv6`, `386`, `ppc64le`, `s390x`, and `riscv64`
- **Checksummed downloads:** the installer verifies each archive against the release `checksums.txt`
- **Safe updates:** accounts, quotas, usage, banners, certificates, OpenVPN state, and operator settings are preserved
- **Version pinning:** every published tag remains directly installable
- **Compatibility migration:** services and scheduled jobs created by earlier source releases are redirected to the packed runtime
- **Login safety:** administrator access remains independent from managed account policy checks
- **Responsive menus:** shared menu rendering and live service/session checks are bounded so every management screen opens promptly

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
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/protocol-panel-management.png" alt="Protocol management" height="170"><br>
      <b>Protocols</b>
    </td>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/ssh-banner-management.png" alt="SSH banner management" height="170"><br>
      <b>SSH Banners</b>
    </td>
  </tr>
</table>

### OpenVPN Web Portal

The optional OpenVPN suite includes a responsive portal for connection guidance,
profile downloads, SNI/payload details, and account support. The four mobile
screens below follow the normal user journey: overview, support, downloads, and
setup verification.

<table>
  <tr>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/Screenshot_20260720-233748_Via.png" alt="OpenVPN portal overview" width="360"><br>
      <b>Portal Overview</b>
    </td>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/Screenshot_20260720-233821_Via.png" alt="OpenVPN account support and project links" width="360"><br>
      <b>Account Support</b>
    </td>
  </tr>
  <tr>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/Screenshot_20260720-233912_Via.png" alt="OpenVPN profile download cards" width="360"><br>
      <b>Profile Downloads</b>
    </td>
    <td align="center" valign="top" width="50%">
      <img src="https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/screenshot/Screenshot_20260720-233955_Via.png" alt="OpenVPN setup guide and WebSocket payload" width="360"><br>
      <b>Setup &amp; Verification</b>
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
  - **Session Full** — the rejected extra connection receives clear guidance without entering the live count
- **DarkTunnel optimized** — HTML banners render perfectly in DarkTunnel and similar SSH client apps
- **Authenticated live banners** — account details are delivered only after successful SSH authentication; failed attempts receive no private account data and never enter the session count
- **Immediate session lifecycle** — the successful connection is included in its own banner, while PID plus process-start-time tracking removes disconnected sessions and rejects stale PID reuse
- **Reason-aware denial** — a correct password for an expired, quota-ended, or manually locked account receives its private reason banner and is then denied; an incorrect password receives neither the banner nor a session marker
- **Reconnect-loop guard** — after a private expiry, quota, lock, or connection-limit denial banner, immediate valid-password retries become a normal authentication failure instead of repeatedly reopening and redisplaying the denied connection; connection-limit retries are allowed immediately when a shared slot opens
- **Static-banner direct denial** — after the public static banner, a correct password for a locked, expired, quota-ended, or full account is rejected in the same SSH attempt; wrong passwords keep the standard static-banner behavior
- **Auto-updating data** — generated banner data refreshes every second to reflect current bandwidth and established SSH/OpenVPN sessions
- **Custom Admin & Channel usernames** — replace the default Telegram usernames with your own in the Dynamic Banner; matching `t.me/` links are generated automatically

### Tunnel Protocols
- **SSH (Direct)** — standard SSH tunnel on port 22
- **OpenVPN protocol suite** — optional direct UDP/TCP, native HTTP CONNECT, HTTP Payload/WebSocket, WSS/SNI, and SSL/SNI transports with downloadable profiles
- **BadVPN / UDPGW** — UDP game tunneling on port 7300
- **DNSTT** — DNS-based tunneling on UDP port 53 with SSH or V2Ray forwarding
- **ZiVPN** — UDP transport on port 5667 with the optional 6000–19999 forwarding range

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
- **Auto-reboot scheduler** — enable or disable the managed daily midnight reboot
- **Connection limit enforcement** — atomically rejects a new SSH/OpenVPN connection when the shared per-user limit is full, without evicting an established session
- **Filtered account views** — List Users provides All, Expired, Quota Ended, and Online views from the same live policy state used by enforcement
- **Service management** — start/stop/restart managed services from the menu

### Current Support

| Area | Current status |
|---|---|
| SSH user lifecycle, expiry, locks, trials, limits, quotas and backups | **Supported** |
| Direct SSH, HAProxy/Nginx edge, WebSocket-to-SSH bridge | **Supported** |
| Direct OpenVPN UDP/TCP and HTTP CONNECT | **Supported** |
| OpenVPN WS, WSS and SSL adapter profiles | **Supported with a compatible external injector/adapter** |
| BadVPN, DNSTT and ZiVPN | **Optional and supported on an available CPU build** |

### Requirements

- Root access, APT, Bash, OpenSSH and systemd are required.
- OpenVPN needs Python 3.7 or newer and a compatible PAM plugin.
- DNSTT needs exclusive access to UDP port 53 and may replace the VPS resolver
  service configuration.
- The installer keeps recoverable account credentials in
  `/etc/tdztunnel/users.db` for account display and backup/restore. The database
  remains root-only (`0600`); protect all root backups accordingly.

---

## Installation

**One-line install (as root):**

```bash
bash <(curl -Ls https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/install.sh)
```

The command above installs the default `v0.0.1` release. To install or return to
any published version, add its exact tag:

```bash
bash <(curl -Ls https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/install.sh) v0.0.1
```

For example, after `v0.0.5` is released, `... install.sh) v0.0.3` will still
download the `v0.0.3` binary and checksum from that immutable GitHub release.

**Manual install:**

```bash
curl -LO https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/install.sh
chmod +x install.sh
./install.sh
```

The installer detects the CPU architecture, validates the archive checksum,
checks the embedded release metadata, and rolls application files back if setup
verification fails. After installation, type **`menu`** to launch the management
interface.

---

## OpenVPN Protocol Suite

Open **`menu → 13) Protocol Manager → 10) OpenVPN Protocol Suite`** to install or manage OpenVPN. The component is optional: installing or removing it does not remove managed users or change the existing SSH, HAProxy, Nginx, DNSTT, BadVPN, ZiVPN, banner, certificate, or backup configuration.

During first installation, the suite asks for the public VPS IP or domain. It starts with portal port `1180` and transport ports `446–450`, creates fresh server cryptographic material, applies isolated VPN subnets, starts the required services, and verifies that every listener is active. These are defaults rather than permanent restrictions. From the OpenVPN Suite menu, **Change Portal and Method Ports** can update the portal, SSL, TCP, UDP, HTTP/WS, and WSS ports together. The saved layout survives installer updates and repairs. Every change transactionally rebuilds the server configs, systemd listeners, firewall rules, downloadable profiles, ZIP, portal pages, and displayed connection details; if validation fails, the last working layout is restored automatically.

The optional suite requires Python 3.7 or newer. On an older distribution the core SSH features remain available, while OpenVPN installation stops safely without changing the existing setup.

| Mode | Client support | Profile / setup |
|---|---|---|
| **Direct UDP** | Official OpenVPN clients | Ready-to-import `.ovpn` profile |
| **Direct TCP** | Official OpenVPN clients | Ready-to-import `.ovpn` profile |
| **HTTP CONNECT** | OpenVPN/HTTP Custom-compatible clients | Native proxy profile with custom CONNECT headers |
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

- SSH and OpenVPN use the same managed user database and Linux password
- Manual lock and account deletion terminate both SSH and OpenVPN sessions
- Manual locks are stored separately from expiry and quota state, so the Unlock menu contains only accounts an administrator deliberately locked
- Expiry and **Start After First Use** apply to the first successful SSH or OpenVPN login
- The configured connection limit is shared across SSH and OpenVPN with first-admitted-wins ordering: the later attempt is rejected without evicting an established session
- Bandwidth usage from both transports is added to the same per-user quota without double counting
- Expired or quota-exhausted accounts are disconnected and denied automatically, while renewing or topping up restores access without changing an independent manual lock
- VPN clients are isolated from one another and cannot use the transport gateway as an open proxy

Direct UDP and direct TCP work in current official OpenVPN clients. The HTTP CONNECT profile follows the supplied HTTP Custom-compatible template with custom CONNECT headers, AES-256-GCM, DNS routing, `setenv CLIENT_CERT 0`, and embedded CA/tls-crypt material. Payload, WS, WSS, and SSL are adapter transports and therefore require an app that implements the corresponding outer payload or TLS/WebSocket layer. Adapter profiles omit newer cipher directives rejected by several embedded Android OpenVPN cores. Direct UDP retains AES-256-GCM priority.

Compatibility follows the official OpenVPN transport model: the core protocol runs over TCP or UDP, while HTTP proxy mode uses TCP. Session status and forced disconnects use the local OpenVPN management interface. See the [OpenVPN protocol reference](https://openvpn.net/community-docs/openvpn-protocol.html), [HTTP proxy guide](https://openvpn.net/community-docs/connecting-to-an-openvpn-server-via-an-http-proxy.html), and [management interface reference](https://openvpn.net/community-docs/management-interface.html).

---

## SSL Certificate — Menu 17

Open **`menu → 17) Domain & SSL Cert`** to manage the certificate shared by the edge stack.

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

Before applying a certificate, the installer verifies that the fullchain is valid and that its public key matches the private key. It then validates the active Nginx and HAProxy configuration. If validation or service restart fails, the previous working certificate is restored automatically.

---



## Default Ports

| Port | Protocol | Purpose |
|---|---|---|
| 22 | SSH | Primary SSH access |
| 7300 | UDP | BadVPN / UDPGW |
| 53 | UDP / DNS | DNSTT tunnel |
| 5667 | UDP | ZiVPN direct listener |
| 6000–19999 | UDP | Optional ZiVPN forwarded range |
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
| **32-bit ARM v7** | `armv7`, `armv7l`, `armhf` | Official binary release; some optional third-party protocol components may be unavailable |
| **32-bit ARM v6** | `armv6`, `armv6l` | Official binary release; some optional third-party protocol components may be unavailable |
| **32-bit Intel/AMD** | `386`, `i386`–`i686` | Official binary release |
| **POWER little-endian** | `ppc64le` | Official binary release |
| **IBM Z** | `s390x` | Official binary release |
| **64-bit RISC-V** | `riscv64` | Official binary release |

The installer automatically detects an existing installation, operating environment and CPU architecture. If a particular optional protocol has no binary for the detected CPU, that component remains unavailable; the main menu, SSH user management, limits, banners, backup and restore features remain available.

> **Note:** Root access is required for installation and operation.

## Uninstall

```text
menu → 99) Uninstall
```

The full uninstaller uses a compact six-stage progress view. It stops and
disables managed background services, removes optional protocol
components, restores resolver and SSH integration, removes only firewall rules
recorded by the installer, clears application files and logs, reloads systemd,
and performs a final leftover-path verification before reporting success.
Legacy files from the retired UDP Custom and proxy downloaders are cleaned as
part of this verification. Managed Linux SSH accounts are deleted only when
you explicitly approve the separate account-removal prompt.

## Credits & License

- **Developer:** [Yeasinul Hoque Tuhin](https://tuhinbro.com)
- **Project:** TDZ SSH TUNNEL — independently developed from scratch
- **Project code and official binaries:** Copyright © Yeasinul Hoque Tuhin. All rights reserved unless separate written permission is provided
- **Third-party components:** OpenVPN Community Edition, BadVPN, DNSTT, ZiVPN, HAProxy, Nginx and Certbot (each retains its own license)

---

<p align="center">
  <b>TDZ SSH TUNNEL</b> — Developed with dedication by <a href="https://t.me/TuhinBroh"><b>ᴛᴜʜɪɴ • ʙʀᴏ</b></a><br>
  <i>For support, contact <a href="https://t.me/Yeasinul_Hoque_Tuhin">Yeasinul Hoque Tuhin</a> on Telegram</i>
</p>
