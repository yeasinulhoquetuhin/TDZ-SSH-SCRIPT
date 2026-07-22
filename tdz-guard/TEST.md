# tdz-guard — VPS-e druto test (5 min)

Ei package tomar repo/install.sh kichu na chhuye alada-bhabe test korar jonno.
Test koro ekta **OpenSSH** host-e (Dropbear-e na)।

## 1) Binary boshaO (tomar arch onujayi)
```sh
uname -m                       # x86_64 -> amd64, aarch64 -> arm64, armv7l -> armv7 ...
install -m 755 tdz-guard-linux-amd64 /usr/local/bin/tdz-guard
tdz-guard --version
```

## 2) Ek-bar test (kono kichu install na kore) — restore kaj kore kina
```sh
# ekhon je credit ache dekho:
grep VersionAddendum /etc/ssh/sshd_config.d/tdztunnel.conf

# icche kore tamper koro:
sed -i 's/By: @TuhinBroh/By: @ChorBatpar/' /etc/ssh/sshd_config.d/tdztunnel.conf
grep VersionAddendum /etc/ssh/sshd_config.d/tdztunnel.conf   # tampered dekhabe

# guard ek-bar chalao:
tdz-guard --once

# abar dekho -> abar @TuhinBroh hoye jabe:
grep VersionAddendum /etc/ssh/sshd_config.d/tdztunnel.conf
```
Notun SSH connection e `ssh -v` korle banner-e `By: @TuhinBroh` dekhbe.

## 3) Service hisebe boshaO (always-on auto-restore)
```sh
install -m 644 tdz-guard.service /etc/systemd/system/tdz-guard.service
systemctl daemon-reload
systemctl enable --now tdz-guard
systemctl status tdz-guard --no-pager
tail -f /var/log/tdz-guard.log     # tamper korle restore log dekhbe
```
Ebar jekono keu credit bodlale koyek second-er moddhe guard nijei thik kore dibe.

## 4) Off korte (test sheshe)
```sh
systemctl disable --now tdz-guard
chattr -i /etc/ssh/sshd_config.d/tdztunnel.conf 2>/dev/null || true
```

Safe: guard sshd `restart` kore na (reload), `sshd -t` fail korle rollback kore —
ssh kokhono bhange na.
