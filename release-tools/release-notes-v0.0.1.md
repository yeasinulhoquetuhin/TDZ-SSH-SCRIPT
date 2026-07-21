## TDZ SSH TUNNEL v0.0.1 BETA

The first official packed-binary release keeps the complete management
experience while replacing editable installed runtime sources with one verified
`tdz` executable.

### Highlights

- Eight Linux CPU builds: amd64, arm64, armv7, armv6, 386, ppc64le, s390x, and riscv64
- Automatic architecture selection and SHA-256 archive verification
- Version-pinned installation and rollback to any published release tag
- Preserved accounts, quotas, traffic data, banners, certificates, backups, and OpenVPN settings during updates
- Packed menu, account workers, Telegram backup worker, WebSocket bridge, OpenVPN services, portal, and SSH authentication helper
- Compatibility aliases migrate workers and services installed by older source releases
- Automatic restoration of the managed `@TuhinBroh` OpenSSH identification
- Built-in payload authentication and runtime self-test before system changes

### Install

```bash
bash <(curl -Ls https://raw.githubusercontent.com/yeasinulhoquetuhin/TDZ-SSH-SCRIPT/master/install.sh) v0.0.1
```

After installation, run `menu`.
