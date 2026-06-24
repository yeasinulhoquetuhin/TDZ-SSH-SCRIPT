# TDZ TUNNEL Manager

> Premium SSH tunnel management suite — branded & maintained by **TDZ TUNNEL**.
> Original project: FirewallFalcon Manager (now offline — forked from a preserved local copy).

TDZ TUNNEL Manager is a self-hosted bash-based control panel for managing
SSH-based tunnel users on a Linux VPS. It supports per-user bandwidth tracking,
multiple tunnel protocols (TLS, WebSocket, UDP, DNS), and a CLI menu that runs
directly on the server.

---

## Features

- **SSH user management** — create / delete / reset users, set expiry & data limits
- **Per-user bandwidth tracking** — daily / monthly quotas with auto-disable
- **Trial accounts** — auto-expiring demo users with cleanup service
- **stunnel4 TLS** — port `2288` for TLS-wrapped SSH (firewall bypass)
- **WebSocket NTLS payload** — port `2289` for non-TLS WS payloads
- **BadVPN / UDPGW** — UDP game tunneling support
- **DNSTT** — DNS-based tunneling (manual NS + tunnel domain input)
- **HAProxy + Nginx SSL termination** — reverse-proxy edge with shared certs
- **Let's Encrypt (certbot)** — automatic TLS certificate via Domain & SSL menu
- **Dynamic per-user SSH banners** — login banner rotation
- **Premium UI** — Navy `#1e3a5f` + Cyan `#00d4ff` color theme

---

## Installation

One-line install (as root):

```bash
bash <(curl -Ls https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/main/install.sh)
```

Or download and run manually:

```bash
curl -LO https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/main/install.sh
chmod +x install.sh
./install.sh
```

After install, type `menu` to launch the management interface.

---

## Repository layout

```
TDZ-SSH-SCRIPT/
├── install.sh      # One-shot installer (downloads menu.sh + ssh config)
├── menu.sh         # Main management menu (~4700 lines, all features)
├── ssh             # Hardened sshd_config (Banner /etc/tdztunnel/bannerssh)
├── README.md       # This file
├── PUSH_GUIDE.md   # Step-by-step guide to push this repo to your GitHub
└── .gitignore
```

---

## Filesystem layout (after install)

| Path | Purpose |
|---|---|
| `/etc/tdztunnel/` | Main DB dir (users.db, banners, ssl, configs) |
| `/etc/tdztunnel/bannerssh` | Global SSH banner |
| `/etc/tdztunnel/bandwidth/` | Per-user bandwidth counters |
| `/etc/tdztunnel/ssl/` | Shared TLS certs (tdztunnel.pem / .crt / .key) |
| `/usr/local/bin/menu` | Menu entrypoint |
| `/usr/local/bin/tdzproxy` | TDZProxy binary |
| `/usr/local/bin/tdztunnel-limiter.sh` | Active-user limiter script |
| `/usr/local/bin/tdztunnel-bandwidth.sh` | Bandwidth counter script |
| `/usr/local/bin/tdztunnel-trial-cleanup.sh` | Trial expiry daemon |
| `/usr/local/bin/tdztunnel-login-info.sh` | Per-user login info hook |
| `/etc/systemd/system/tdztunnel-*.service` | Systemd units |
| `/etc/systemd/system/tdzproxy.service` | TDZProxy systemd unit |
| `/etc/ssh/sshd_config.d/tdztunnel.conf` | Drop-in sshd config |
| `/etc/bannerssh` → `/etc/tdztunnel/bannerssh` | Banner path |

---

## Configuration

DNS / Domain management is **fully manual**. From the menu:

```
Main Menu → 15) 🌐 Domain & SSL Certificate
```

You will be prompted for:
1. Your own domain (e.g. `vpn.example.com`)
2. Your email (for Let's Encrypt)

The script then runs `certbot certonly --standalone -d <domain>` and copies the
issued cert into `/etc/tdztunnel/ssl/` for HAProxy / Nginx to use.

**Pre-requisites for certbot:**
- The domain's A record must already point to this server's public IP
- Port 80 must be reachable from the internet
- The script will temporarily stop HAProxy/Nginx to free port 80

You can also generate a self-signed certificate (no domain needed) from the
same menu — useful for internal testing.

---

## Default ports

| Port | Protocol | Purpose |
|---|---|---|
| 22 | SSH | Primary SSH (after install) |
| 2288 | TLS | stunnel4-wrapped SSH |
| 2289 | WS | WebSocket NTLS payload |
| 7300 | UDP | UDPGW (BadVPN) |
| 5300 | DNS | DNSTT server |
| 80 / 443 | HTTP/S | HAProxy / Nginx edge |

---

## Compatibility

- **OS:** Ubuntu 20.04 / 22.04 / 24.04 (also tested on Debian 11/12)
- **Arch:** amd64, arm64
- **Access:** root required

---

## Uninstall

From the menu:

```
menu → 0 (or "Uninstall")
```

Or directly:

```bash
bash /usr/local/bin/menu --uninstall
```

The uninstaller removes all users, services, configs and the DB dir.

---

## Credits

- **Branding & maintenance:** TDZ TUNNEL
- **Original codebase:** FirewallFalcon Manager (repo now offline; forked from a
  preserved local snapshot)
- **Third-party components:** BadVPN, DNSTT, UDPGW, ZiVPN, stunnel4, HAProxy, Nginx

---

## License

This project is distributed for personal & commercial use. The original
FirewallFalcon Manager did not include an explicit license file; all third-party
components retain their original licenses. Use at your own risk.
