// tdz-guard — TDZ SSH TUNNEL integrity service.
//
// Purpose: keep the project's authorship credit in place. The canonical values
// are compiled into this native binary, so they cannot be changed by editing a
// script. If someone tampers with the credit on a running machine, the guard
// detects it and restores it automatically.
//
// v0.0.1 BETA scope:
//   * ACTIVE enforcement of the SSH VersionAddendum credit
//     (the "SSH-2.0-OpenSSH ... By: @TuhinBroh" banner). Safe by design:
//     validate with `sshd -t`, apply with `reload` (never `restart`, so live
//     sessions are not dropped), and roll back if validation fails — the guard
//     never leaves sshd in a broken state.
//   * DETECT + LOG only for the WebSocket/portal credit that currently lives in
//     interpreted daemon files. True auto-restore of those comes when the
//     daemons are compiled (the string then lives inside the binary and cannot
//     be line-edited). We do NOT risk rewriting live .py/.sh source lines here.
//
// Everything is best-effort and fail-safe: the guard must never crash the box.
package main

import (
	"flag"
	"fmt"
	"os"
	"os/exec"
	"os/signal"
	"path/filepath"
	"regexp"
	"strings"
	"syscall"
	"time"
)

// Version is stamped at build time via -ldflags "-X main.Version=v0.0.1".
var Version = "v0.0.1-beta"

// ---- Canonical credit, baked into the binary (cannot be edited in a script) ----
const (
	creditVersionAddendum = "By: @TuhinBroh" // sshd VersionAddendum value
)

// Network-visible credit markers we monitor in interpreted daemon files.
var creditMarkers = []string{"tuhinbro.com", "@TuhinBroh"}

// Defaults (overridable via env for testing / non-standard layouts).
const (
	defSSHDConf  = "/etc/ssh/sshd_config.d/tdztunnel.conf"
	defSSHDTest  = "sshd -t"
	defReloadCmd = "systemctl reload ssh 2>/dev/null || systemctl reload sshd 2>/dev/null || true"
	defInterval  = "15s"
	defLog       = "/var/log/tdz-guard.log"
)

func env(k, def string) string {
	if v := os.Getenv(k); v != "" {
		return v
	}
	return def
}

// root prefix lets tests relocate absolute daemon paths under a temp dir.
var rootPrefix = os.Getenv("TDZ_GUARD_ROOT")

func underRoot(p string) string {
	if rootPrefix == "" {
		return p
	}
	return filepath.Join(rootPrefix, p)
}

var logFile string

func logln(format string, a ...interface{}) {
	line := fmt.Sprintf("%s  %s\n", time.Now().UTC().Format(time.RFC3339), fmt.Sprintf(format, a...))
	if logFile != "" {
		if f, err := os.OpenFile(logFile, os.O_CREATE|os.O_WRONLY|os.O_APPEND, 0o600); err == nil {
			_, _ = f.WriteString(line)
			_ = f.Close()
		}
	}
	fmt.Print(line)
}

// sh runs a command string through /bin/sh -c and returns success + output.
func sh(cmd string) (bool, string) {
	out, err := exec.Command("/bin/sh", "-c", cmd).CombinedOutput()
	return err == nil, strings.TrimSpace(string(out))
}

// setImmutable toggles the chattr +i flag best-effort (no-op where unavailable).
func setImmutable(path string, on bool) {
	if env("TDZ_GUARD_IMMUTABLE", "1") != "1" {
		return
	}
	flag := "-i"
	if on {
		flag = "+i"
	}
	_, _ = sh(fmt.Sprintf("chattr %s %q 2>/dev/null", flag, path))
}

var versionAddendumRe = regexp.MustCompile(`(?m)^[ \t]*VersionAddendum[ \t]+.*$`)

// enforceSSHDVersionAddendum makes sure the drop-in carries the canonical
// VersionAddendum. Returns true if it changed the file. Fail-safe: validates
// before reloading and rolls back if `sshd -t` fails.
func enforceSSHDVersionAddendum() (changed bool) {
	confPath := env("TDZ_GUARD_SSHD_CONF", defSSHDConf)
	desired := "VersionAddendum " + creditVersionAddendum

	orig, err := os.ReadFile(confPath)
	if err != nil {
		logln("[ssh] cannot read %s (%v) — skipping this pass", confPath, err)
		return false
	}
	content := string(orig)

	var updated string
	if versionAddendumRe.MatchString(content) {
		current := versionAddendumRe.FindString(content)
		if strings.TrimSpace(current) == desired {
			return false // already correct
		}
		updated = versionAddendumRe.ReplaceAllString(content, desired)
	} else {
		// Directive missing entirely — append it.
		if !strings.HasSuffix(content, "\n") {
			content += "\n"
		}
		updated = content + desired + "\n"
	}

	logln("[ssh] credit tampering detected in %s — restoring", confPath)
	setImmutable(confPath, false)
	// Write via temp+rename for atomicity, preserving mode 0600.
	tmp := confPath + ".tdz.tmp"
	if err := os.WriteFile(tmp, []byte(updated), 0o600); err != nil {
		logln("[ssh] write temp failed: %v", err)
		setImmutable(confPath, true)
		return false
	}
	if err := os.Rename(tmp, confPath); err != nil {
		logln("[ssh] rename failed: %v", err)
		_ = os.Remove(tmp)
		setImmutable(confPath, true)
		return false
	}

	// Validate the whole sshd config; roll back on failure so we NEVER break ssh.
	if ok, out := sh(env("TDZ_GUARD_SSHD_TEST_CMD", defSSHDTest)); !ok {
		logln("[ssh] sshd validation FAILED after restore (%s) — rolling back", out)
		_ = os.WriteFile(confPath, orig, 0o600)
		setImmutable(confPath, true)
		return false
	}
	setImmutable(confPath, true)

	if ok, out := sh(env("TDZ_GUARD_RELOAD_CMD", defReloadCmd)); !ok {
		logln("[ssh] reload reported an issue: %s", out)
	}
	logln("[ssh] restored: %s", desired)
	return true
}

// checkDaemonCredit is DETECT+LOG only (BETA). It never edits live source.
func checkDaemonCredit() {
	files := []string{
		"/usr/local/bin/tdz-ws-ssh-bridge.py",
		"/usr/local/lib/tdz-ssh-tunnel/tdz_openvpn_gateway.py",
		"/usr/local/bin/menu",
	}
	for _, f := range files {
		p := underRoot(f)
		b, err := os.ReadFile(p)
		if err != nil {
			continue // not installed / not readable — skip quietly
		}
		s := string(b)
		present := false
		for _, m := range creditMarkers {
			if strings.Contains(s, m) {
				present = true
				break
			}
		}
		if !present {
			logln("[daemon] WARNING: credit marker missing in %s (will be enforced once daemons are compiled)", p)
		}
	}
}

func onePass() {
	enforceSSHDVersionAddendum()
	checkDaemonCredit()
}

func main() {
	once := flag.Bool("once", false, "run a single enforcement pass and exit")
	showVer := flag.Bool("version", false, "print version and exit")
	flag.Parse()
	if *showVer {
		fmt.Println("tdz-guard", Version)
		return
	}

	logFile = env("TDZ_GUARD_LOG", defLog)
	// Best-effort log dir.
	_ = os.MkdirAll(filepath.Dir(logFile), 0o755)

	if *once {
		onePass()
		return
	}

	interval, err := time.ParseDuration(env("TDZ_GUARD_INTERVAL", defInterval))
	if err != nil || interval < time.Second {
		interval = 15 * time.Second
	}

	logln("tdz-guard %s started (interval %s)", Version, interval)

	// Clean shutdown on SIGTERM/SIGINT (systemd stop).
	stop := make(chan os.Signal, 1)
	signal.Notify(stop, syscall.SIGTERM, syscall.SIGINT)

	ticker := time.NewTicker(interval)
	defer ticker.Stop()

	onePass() // immediate first pass
	for {
		select {
		case <-ticker.C:
			onePass()
		case <-stop:
			logln("tdz-guard stopping")
			return
		}
	}
}
