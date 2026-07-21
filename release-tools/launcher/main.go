// TDZ SSH TUNNEL binary runtime launcher.
//
// Official builds inject an encrypted, authenticated runtime payload and its
// per-release key. Runtime sources are opened through deleted file descriptors,
// so they are never installed as ordinary source files.
package main

import (
	"bytes"
	"compress/gzip"
	"crypto/aes"
	"crypto/cipher"
	_ "embed"
	"encoding/hex"
	"encoding/json"
	"errors"
	"fmt"
	"io"
	"os"
	"os/exec"
	"os/signal"
	"path/filepath"
	"regexp"
	"runtime"
	"strings"
	"syscall"
	"time"
)

const (
	productName      = "TDZ SSH TUNNEL"
	releaseName      = "v0.0.1 BETA"
	brandingLine     = "VersionAddendum @TuhinBroh"
	sshdDropIn       = "/etc/ssh/sshd_config.d/tdztunnel.conf"
	brandingLockFile = "/run/tdz-ssh-branding.lock"
	managedSSHDropIn = `# TDZ SSH TUNNEL safe SSH settings
Port 22
DebianBanner no
VersionAddendum @TuhinBroh
AddressFamily inet
ListenAddress 0.0.0.0
PermitRootLogin yes
PasswordAuthentication yes
KbdInteractiveAuthentication yes
ChallengeResponseAuthentication yes
UsePAM yes
X11Forwarding yes
PrintMotd no
AcceptEnv LANG LC_*
ClientAliveInterval 30
ClientAliveCountMax 3
UseDNS no
LoginGraceTime 60
MaxStartups 30:30:100
TCPKeepAlive yes
PermitTunnel yes
AllowTcpForwarding yes
GatewayPorts yes
`
)

var (
	// Set only for official builds with: -X main.payloadKeyHex=<64 hex chars>.
	payloadKeyHex = ""
	buildCommit   = "unknown"
	buildTime     = "unknown"

	//go:embed payload.enc
	encryptedPayload []byte

	versionDirective = regexp.MustCompile(`(?i)^\s*VersionAddendum(?:\s+.*)?$`)
)

type payloadMap map[string][]byte

type dispatchSpec struct {
	resource    string
	interpreter string
	prefix      []string
}

var dispatchByName = map[string]dispatchSpec{
	"tdz-limiter":                  {"limiter.sh", "/bin/bash", nil},
	"tdztunnel-limiter.sh":         {"limiter.sh", "/bin/bash", nil},
	"tdz-trial-cleanup":            {"trial-cleanup.sh", "/bin/bash", nil},
	"tdztunnel-trial-cleanup.sh":   {"trial-cleanup.sh", "/bin/bash", nil},
	"tdz-auto-backup-bot":          {"auto-backup.sh", "/bin/bash", nil},
	"tdztunnel-auto-backup-bot.sh": {"auto-backup.sh", "/bin/bash", nil},
	"tdz-ws-ssh-bridge":            {"ws-ssh-bridge.py", "python3", []string{"-B"}},
	"tdz-ws-ssh-bridge.py":         {"ws-ssh-bridge.py", "python3", []string{"-B"}},
	"tdz-openvpn-runtime":          {"openvpn-runtime.py", "python3", []string{"-B"}},
	"tdz-openvpn-gateway":          {"openvpn-gateway.py", "python3", []string{"-B"}},
	"tdz-openvpn-portal":           {"openvpn-portal.py", "python3", []string{"-B"}},
	"tdz-openvpn-firewall":         {"openvpn-firewall.sh", "/bin/sh", nil},
	"tdz-ssh-auth":                 {"ssh-auth-session.py", "python3", []string{"-B"}},
}

func main() {
	code, err := run()
	if err != nil {
		fmt.Fprintf(os.Stderr, "tdz: %v\n", err)
		if code == 0 {
			code = 1
		}
	}
	os.Exit(code)
}

func run() (int, error) {
	name := filepath.Base(os.Args[0])
	args := os.Args[1:]
	if spec, ok := dispatchByName[name]; ok {
		return dispatch(spec, args)
	}

	if len(args) > 0 {
		switch args[0] {
		case "version", "--version", "-v":
			return printVersion(args[1:]), nil
		case "self-test":
			return selfTest()
		case "guard":
			return runGuard(args[1:])
		case "runtime":
			if len(args) < 2 {
				return 2, errors.New("runtime name is required")
			}
			spec, ok := dispatchByName[args[1]]
			if !ok {
				return 2, fmt.Errorf("unknown runtime %q", args[1])
			}
			return dispatch(spec, args[2:])
		case "menu":
			args = args[1:]
		}
	}

	// Repair an accidental branding edit before any interactive/setup action.
	if os.Geteuid() == 0 {
		_, _ = repairSSHBranding(false)
	}
	return dispatch(dispatchSpec{"menu.sh", "/bin/bash", nil}, args)
}

func printVersion(args []string) int {
	if len(args) > 0 && args[0] == "--json" {
		_ = json.NewEncoder(os.Stdout).Encode(map[string]string{
			"product": productName,
			"version": releaseName,
			"commit":  buildCommit,
			"built":   buildTime,
			"os":      runtime.GOOS,
			"arch":    runtime.GOARCH,
		})
		return 0
	}
	fmt.Printf("%s %s (%s/%s)\n", productName, releaseName, runtime.GOOS, runtime.GOARCH)
	fmt.Printf("Powered By: t.me/TuhinBroh\nBuild: %s %s\n", buildCommit, buildTime)
	return 0
}

func selfTest() (int, error) {
	payload, err := decodePayload()
	if err != nil {
		return 1, err
	}
	required := []string{
		"menu.sh", "limiter.sh", "trial-cleanup.sh", "auto-backup.sh",
		"ws-ssh-bridge.py", "openvpn-runtime.py", "openvpn-gateway.py",
		"openvpn-portal.py", "openvpn-firewall.sh", "ssh-auth-session.py",
	}
	for _, name := range required {
		if len(payload[name]) == 0 {
			return 1, fmt.Errorf("runtime payload %q is missing", name)
		}
	}
	fmt.Printf("%s %s: self-test passed (%d packed runtimes)\n", productName, releaseName, len(required))
	return 0, nil
}

func decodePayload() (payloadMap, error) {
	key, err := hex.DecodeString(payloadKeyHex)
	if err != nil || len(key) != 32 {
		return nil, errors.New("official runtime key is missing or invalid")
	}
	block, err := aes.NewCipher(key)
	if err != nil {
		return nil, fmt.Errorf("payload cipher: %w", err)
	}
	gcm, err := cipher.NewGCM(block)
	if err != nil {
		return nil, fmt.Errorf("payload authentication: %w", err)
	}
	if len(encryptedPayload) <= gcm.NonceSize() {
		return nil, errors.New("runtime payload is empty")
	}
	nonce := encryptedPayload[:gcm.NonceSize()]
	plain, err := gcm.Open(nil, nonce, encryptedPayload[gcm.NonceSize():], []byte(releaseName))
	if err != nil {
		return nil, errors.New("runtime payload failed authentication")
	}
	reader, err := gzip.NewReader(bytes.NewReader(plain))
	if err != nil {
		return nil, fmt.Errorf("payload compression: %w", err)
	}
	decompressed, err := io.ReadAll(io.LimitReader(reader, 16<<20))
	closeErr := reader.Close()
	if err != nil {
		return nil, fmt.Errorf("payload read: %w", err)
	}
	if closeErr != nil {
		return nil, fmt.Errorf("payload close: %w", closeErr)
	}
	var payload payloadMap
	if err := json.Unmarshal(decompressed, &payload); err != nil {
		return nil, fmt.Errorf("payload format: %w", err)
	}
	return payload, nil
}

func dispatch(spec dispatchSpec, args []string) (int, error) {
	payload, err := decodePayload()
	if err != nil {
		return 1, err
	}
	script := payload[spec.resource]
	if len(script) == 0 {
		return 1, fmt.Errorf("packed runtime %q is unavailable", spec.resource)
	}
	interpreter, err := exec.LookPath(spec.interpreter)
	if err != nil {
		return 1, fmt.Errorf("required interpreter %q was not found", spec.interpreter)
	}

	file, err := os.CreateTemp("", ".tdz-runtime-*")
	if err != nil {
		return 1, fmt.Errorf("create private runtime: %w", err)
	}
	name := file.Name()
	defer file.Close()
	if err := file.Chmod(0700); err != nil {
		_ = os.Remove(name)
		return 1, err
	}
	if _, err := file.Write(script); err != nil {
		_ = os.Remove(name)
		return 1, err
	}
	if err := file.Sync(); err != nil {
		_ = os.Remove(name)
		return 1, err
	}
	if _, err := file.Seek(0, io.SeekStart); err != nil {
		_ = os.Remove(name)
		return 1, err
	}
	// Keep only the open descriptor; no ordinary source path remains.
	if err := os.Remove(name); err != nil {
		return 1, fmt.Errorf("unlink private runtime: %w", err)
	}

	childArgs := append([]string{}, spec.prefix...)
	childArgs = append(childArgs, "/proc/self/fd/3")
	childArgs = append(childArgs, args...)
	cmd := exec.Command(interpreter, childArgs...)
	cmd.Stdin, cmd.Stdout, cmd.Stderr = os.Stdin, os.Stdout, os.Stderr
	cmd.Env = append(os.Environ(), "TDZ_PACKED_RUNTIME=1")
	cmd.ExtraFiles = []*os.File{file}
	cmd.SysProcAttr = &syscall.SysProcAttr{Setpgid: true, Pdeathsig: syscall.SIGTERM}
	if err := cmd.Start(); err != nil {
		return 1, fmt.Errorf("start %s: %w", spec.resource, err)
	}

	signals := make(chan os.Signal, 4)
	signal.Notify(signals, syscall.SIGTERM, syscall.SIGINT, syscall.SIGHUP)
	done := make(chan struct{})
	go func() {
		defer close(done)
		for sig := range signals {
			if value, ok := sig.(syscall.Signal); ok && cmd.Process != nil {
				_ = syscall.Kill(-cmd.Process.Pid, value)
			}
		}
	}()
	err = cmd.Wait()
	signal.Stop(signals)
	close(signals)
	<-done
	if err == nil {
		return 0, nil
	}
	var exitErr *exec.ExitError
	if errors.As(err, &exitErr) {
		return exitErr.ExitCode(), nil
	}
	return 1, err
}

func runGuard(args []string) (int, error) {
	if len(args) == 0 || args[0] != "ssh-branding" {
		return 2, errors.New("usage: tdz guard ssh-branding [--once]")
	}
	if os.Geteuid() != 0 {
		return 1, errors.New("SSH branding guard requires root")
	}
	once := len(args) > 1 && args[1] == "--once"
	for {
		changed, err := repairSSHBranding(true)
		if err != nil {
			fmt.Fprintf(os.Stderr, "tdz branding guard: %v\n", err)
		} else if changed {
			fmt.Fprintln(os.Stderr, "tdz branding guard: restored official SSH identification")
		}
		if once {
			if err != nil {
				return 1, err
			}
			return 0, nil
		}
		time.Sleep(2 * time.Second)
	}
}

func repairSSHBranding(reload bool) (bool, error) {
	lock, err := os.OpenFile(brandingLockFile, os.O_CREATE|os.O_RDWR, 0600)
	if err != nil {
		return false, err
	}
	defer lock.Close()
	if err := syscall.Flock(int(lock.Fd()), syscall.LOCK_EX); err != nil {
		return false, err
	}
	defer syscall.Flock(int(lock.Fd()), syscall.LOCK_UN)

	info, err := os.Lstat(sshdDropIn)
	if errors.Is(err, os.ErrNotExist) {
		if err := os.MkdirAll(filepath.Dir(sshdDropIn), 0755); err != nil {
			return false, err
		}
		if err := writeSSHDropIn(nil, []byte(managedSSHDropIn), reload); err != nil {
			return false, err
		}
		return true, nil
	}
	if err != nil {
		return false, err
	}
	if info.Mode()&os.ModeSymlink != 0 || !info.Mode().IsRegular() {
		return false, errors.New("managed SSH drop-in is not a regular file")
	}
	original, err := os.ReadFile(sshdDropIn)
	if err != nil {
		return false, err
	}
	repaired := canonicalSSHBranding(original)
	if bytes.Equal(original, repaired) {
		return false, nil
	}
	if err := writeSSHDropIn(original, repaired, reload); err != nil {
		return false, err
	}
	return true, nil
}

func canonicalSSHBranding(original []byte) []byte {
	lines := strings.Split(strings.ReplaceAll(string(original), "\r\n", "\n"), "\n")
	result := make([]string, 0, len(lines)+1)
	found := false
	for _, line := range lines {
		if versionDirective.MatchString(line) {
			if !found {
				result = append(result, brandingLine)
				found = true
			}
			continue
		}
		result = append(result, line)
	}
	if !found {
		for len(result) > 0 && result[len(result)-1] == "" {
			result = result[:len(result)-1]
		}
		result = append(result, brandingLine, "")
	}
	return []byte(strings.Join(result, "\n"))
}

func writeSSHDropIn(original, repaired []byte, reload bool) error {
	dir := filepath.Dir(sshdDropIn)
	temp, err := os.CreateTemp(dir, ".tdztunnel.conf.*")
	if err != nil {
		return err
	}
	tempName := temp.Name()
	defer os.Remove(tempName)
	if _, err := temp.Write(repaired); err != nil {
		temp.Close()
		return err
	}
	if err := temp.Chmod(0600); err != nil {
		temp.Close()
		return err
	}
	if err := temp.Sync(); err != nil {
		temp.Close()
		return err
	}
	if err := temp.Close(); err != nil {
		return err
	}
	if err := os.Rename(tempName, sshdDropIn); err != nil {
		return err
	}

	if err := validateSSHD(); err != nil {
		if original == nil {
			_ = os.Remove(sshdDropIn)
		} else {
			_ = os.WriteFile(sshdDropIn, original, 0600)
		}
		return fmt.Errorf("repaired SSH config was rejected: %w", err)
	}
	if reload {
		_ = reloadSSHD()
	}
	return nil
}

func validateSSHD() error {
	path, err := exec.LookPath("sshd")
	if err != nil {
		if _, statErr := os.Stat("/usr/sbin/sshd"); statErr != nil {
			return err
		}
		path = "/usr/sbin/sshd"
	}
	output, err := exec.Command(path, "-t").CombinedOutput()
	if err != nil {
		return fmt.Errorf("%s: %s", err, strings.TrimSpace(string(output)))
	}
	return nil
}

func reloadSSHD() error {
	if _, err := exec.LookPath("systemctl"); err == nil {
		if exec.Command("systemctl", "reload", "sshd").Run() == nil {
			return nil
		}
		return exec.Command("systemctl", "reload", "ssh").Run()
	}
	return errors.New("systemctl is unavailable")
}
