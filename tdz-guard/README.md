# TDZ SSH TUNNEL — `tdz-guard` (v0.0.1 BETA)

Native **integrity / credit-protection** service for TDZ SSH TUNNEL.

The project's authorship credit (the SSH banner **`... By: @TuhinBroh`**) is
**compiled into this binary** — it cannot be changed by editing a script. On a
running machine the guard watches the live SSH config and, if anyone tampers
with the credit, **restores it automatically** — safely.

> Powered By: t.me/TuhinBroh · tuhinbro.com

---

## What it does (v0.0.1 BETA)

- ✅ **Active:** keeps the SSH `VersionAddendum By: @TuhinBroh` in
  `/etc/ssh/sshd_config.d/tdztunnel.conf`. If changed/removed → rewrites it,
  runs `sshd -t`, and `reload`s sshd. **Never `restart`** (live sessions stay
  up) and **rolls back** if validation fails, so sshd is never left broken.
  Best-effort `chattr +i` makes casual edits fail outright.
- 👀 **Detect + log:** warns if the WebSocket/portal credit
  (`tuhinbro.com` / `@TuhinBroh`) is stripped from the daemon files.
  Full auto-restore of those arrives when the daemons are compiled (the string
  will then live inside the binary — no fragile source-patching).

## Supported architectures (Linux)

`amd64` · `arm64` · `armv7` · `386` · `mips64le` · `mipsle` · `ppc64le` ·
`riscv64` · `s390x`  — verify with `SHA256SUMS.txt`.

## Install (systemd)

```sh
install -m 755 tdz-guard-linux-<arch> /usr/local/bin/tdz-guard
install -m 644 tdz-guard.service /etc/systemd/system/tdz-guard.service
systemctl daemon-reload
systemctl enable --now tdz-guard
```

## Version-pinned install (planned, x-ui style)

```sh
bash <(curl -Ls https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/install.sh) v0.0.3
```

## Honest security note

This raises the bar a lot — casual credit-theft by editing files stops working,
and the credit self-restores. But the machine owner has **root**, so a
determined person can still disable any service. No script or binary (not even
3X-UI) is 100% tamper-proof. Goal: make rebranding costly enough that ~all
casual thieves fail.

*BETA — test on an OpenSSH host before production.*
