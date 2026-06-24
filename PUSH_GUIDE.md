# How to push TDZ-SSH-SCRIPT to your GitHub

This guide walks you through pushing the rebranded **TDZ TUNNEL Manager** to your
own GitHub account at `github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT`.

> **⚡ Fast path:** Skip to **Step 3** and run `bash push_to_github.sh` —
> the included helper does everything for you in one command.

---

## Step 0 — Prerequisites

1. A GitHub account (`yeasinulhoquetuhin`).
2. `git` installed locally (`git --version`).
3. SSH key registered with GitHub, OR a Personal Access Token (PAT) for HTTPS
   authentication. (GitHub no longer accepts password auth over HTTPS.)

If you don't have an SSH key yet:
```bash
ssh-keygen -t ed25519 -C "yeasinulhoquetuhin" -f ~/.ssh/id_ed25519 -N ""
cat ~/.ssh/id_ed25519.pub
```
Paste the output into **GitHub → Settings → SSH and GPG keys → New SSH key**.

---

## Step 1 — Create the empty repo on GitHub

1. Go to: <https://github.com/new>
2. **Owner:** `yeasinulhoquetuhin`
3. **Repository name:** `TDZ-SSH-SCRIPT`
4. **Visibility:** Public (recommended — `install.sh` uses `raw.githubusercontent.com`
   which works for both public and private, but public is simpler)
5. **DO NOT** tick "Add a README", ".gitignore", or "license" — we already have
   these locally.
6. Click **Create repository**.

GitHub will show you the empty repo page with clone URLs. Note the SSH URL:
```
git@github.com:yeasinulhoquetuhin/TDZ-SSH-SCRIPT.git
```

---

## Step 2 — Initialize the local repo

The repo files live at `/home/z/my-project/download/TDZ-SSH-SCRIPT/` on this
sandbox. Run:

```bash
cd /home/z/my-project/download/TDZ-SSH-SCRIPT

# Initialize git
git init -b main

# Stage all files
git add .

# Verify what will be committed
git status

# First commit
git commit -m "feat: initial release of TDZ TUNNEL Manager v4.0.0

Rebranded from FirewallFalcon Manager:
- All 'FirewallFalcon' references -> 'TDZ Tunnel' (display)
- All 'firewallfalcon' references -> 'tdztunnel' (paths/identifiers)
- FalconProxy -> TDZProxy (binary, service, config)
- /etc/firewallfalcon -> /etc/tdztunnel
- /etc/bannerssh -> /etc/tdztunnel/bannerssh
- firewallfalcons/FirewallFalcon-Manager -> yeasinulhoquetuhin/TDZ-SSH-SCRIPT
- manager.firewallfalcon.qzz.io -> manager.tdz-tunnel.qzz.io
- ffusers -> tdzusers, FF_USERS_GROUP -> TDZ_USERS_GROUP
- SSHD_FF_CONFIG -> SSHD_TDZ_CONFIG
- ff_ function prefix -> tdz_
- Color palette: Purple -> Navy #1e3a5f + Cyan #00d4ff
- All systemd service files renamed firewallfalcon-*.service -> tdztunnel-*.service
- All /usr/local/bin/firewallfalcon-* -> /usr/local/bin/tdztunnel-*

Files:
- install.sh: one-shot installer, pulls from your GitHub
- menu.sh: full management menu (~4700 lines)
- ssh: hardened sshd_config with TDZ banner
- README.md, .gitignore, PUSH_GUIDE.md"
```

---

## Step 3 — Add the remote and push

### Option 0 — Fast path (one command, recommended)

A helper script is included that does everything for you:

```bash
cd /home/z/my-project/download/TDZ-SSH-SCRIPT
bash push_to_github.sh
```

When prompted:
- **Username:** `yeasinulhoquetuhin`
- **Password:** paste your **Personal Access Token** (NOT your GitHub password)

The script will:
1. Add the remote
2. Configure credential storage (so you only paste the token once)
3. Push the `main` branch
4. Verify the `install.sh` raw URL is publicly reachable

If you don't have a PAT yet, create one at:
<https://github.com/settings/tokens/new?scopes=repo>

---

### Option A — SSH (recommended if you set up an SSH key)

```bash
git remote add origin git@github.com:yeasinulhoquetuhin/TDZ-SSH-SCRIPT.git
git push -u origin main
```

### Option B — HTTPS with Personal Access Token

Generate a PAT at: **GitHub → Settings → Developer settings →
Personal access tokens → Tokens (classic) → Generate new token**
with the `repo` scope.

```bash
git remote add origin https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT.git
git push -u origin main
# Username: yeasinulhoquetuhin
# Password: <paste your PAT>
```

To cache the PAT so you don't have to re-enter it:
```bash
git config --global credential.helper store
```

---

## Step 4 — Verify the push

1. Visit: <https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT>
2. You should see `install.sh`, `menu.sh`, `ssh`, `README.md`, `PUSH_GUIDE.md`, `.gitignore`.
3. Verify the raw URL works (paste in browser):
   ```
   https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/main/install.sh
   ```
   You should see the contents of `install.sh` with `echo "Installing TDZ Tunnel Manager..."`.

---

## Step 5 — Test the install on a fresh VPS

On a clean Ubuntu 22.04/24.04 VPS as root:

```bash
bash <(curl -Ls https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/main/install.sh)
```

You should see:
```
Installing TDZ Tunnel Manager...
Applying TDZ Tunnel SSH configuration...
SSH configuration validated.
SSH service restarted.
...
Installation complete!
Type 'menu' to start.
```

Then run `menu` to confirm the new Navy+Cyan branded menu loads.

---

## Optional — Tag a release

Once everything works, tag the first release:

```bash
cd /home/z/my-project/download/TDZ-SSH-SCRIPT
git tag -a v4.0.0 -m "TDZ TUNNEL Manager v4.0.0 - Initial branded release"
git push origin v4.0.0
```

Then on GitHub: **Releases → Draft a new release** → choose tag `v4.0.0` →
upload any binary assets (e.g. `tdzproxy-linux-amd64`) if you have them.
This is needed because `menu.sh` looks up GitHub Releases for the TDZProxy binary
via:
```
https://api.github.com/repos/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/releases
```

If no releases exist yet, the TDZProxy install option in the menu will fail
gracefully — you can either upload a binary or skip that menu option.

---

## Updating the repo later

When you change `menu.sh` / `install.sh` / `ssh` and want to push the new version:

```bash
cd /home/z/my-project/download/TDZ-SSH-SCRIPT
git add -A
git commit -m "fix: <describe what changed>"
git push
```

The `install.sh` URL on GitHub will automatically point to the latest version
on the `main` branch.

---

## Troubleshooting

| Problem | Fix |
|---|---|
| `git push` asks for password | Use SSH remote (Step 3 Option A) or generate a PAT |
| `fatal: remote origin already exists` | `git remote remove origin` then re-add |
| `raw.githubusercontent.com` returns 404 | Repo must be PUBLIC, or use a token in the URL |
| `install.sh` works but `menu` not found | `chmod +x /usr/local/bin/menu` (already done by install.sh) |
| TDZProxy install fails | You haven't uploaded a release yet — see Step 5 |
| Bash color codes look broken | Use a terminal with 256-color / truecolor support (`xterm-256color`) |

---

## Done!

Your TDZ TUNNEL Manager is now live at:
**<https://github.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT>**

Anyone (including yourself on a new VPS) can install it with:
```bash
bash <(curl -Ls https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/main/install.sh)
```
