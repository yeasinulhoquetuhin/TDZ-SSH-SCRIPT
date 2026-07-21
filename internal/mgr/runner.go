package mgr

import (
    "embed"
    "fmt"
    "os"
    "os/exec"
    "os/signal"
    "path/filepath"
    "syscall"
    "tdz/internal/crypto"
)

//go:embed scripts/*
var encFS embed.FS

type Runner struct {
    bindir string
    tmpdir string
}

func New(bindir string) *Runner {
    return &Runner{bindir: bindir}
}

func (r *Runner) extract() {
    d, _ := os.MkdirTemp("/dev/shm", "tdz_*")
    r.tmpdir = d
    entries, _ := encFS.ReadDir("scripts")
    for _, e := range entries {
        if e.IsDir() { continue }
        data, _ := encFS.ReadFile("scripts/" + e.Name())
        dec, err := crypto.Decrypt(string(data))
        if err != nil { continue }
        os.WriteFile(filepath.Join(d, e.Name()), dec, 0700)
    }
}

func (r *Runner) cleanup() {
    if r.tmpdir != "" { os.RemoveAll(r.tmpdir) }
}

func (r *Runner) runBash(scriptPath string) {
    cmd := exec.Command("/bin/bash", scriptPath)
    cmd.Stdout = os.Stdout
    cmd.Stderr = os.Stderr
    cmd.Stdin = os.Stdin
    cmd.Env = append(os.Environ(),
        "TDZ_BIN="+r.bindir,
        "TDZ_RAM="+r.tmpdir,
    )
    cmd.Run()
}

func (r *Runner) Menu() {
    r.extract()
    defer r.cleanup()

    sig := make(chan os.Signal, 1)
    signal.Notify(sig, os.Interrupt, syscall.SIGTERM)
    go func() { <-sig; r.cleanup(); os.Exit(0) }()

    r.runBash(filepath.Join(r.tmpdir, "menu.sh"))
}

func (r *Runner) Install() {
    data, _ := encFS.ReadFile("scripts/install.sh")
    script, _ := crypto.Decrypt(string(data))

    cmd := exec.Command("/bin/bash", "-s")
    cmd.Stdout = os.Stdout
    cmd.Stderr = os.Stderr
    cmd.Env = append(os.Environ(), "TDZ_BIN="+r.bindir)
    cmd.Dir = r.bindir
    p, _ := cmd.StdinPipe()
    cmd.Start()
    p.Write(script)
    p.Close()
    cmd.Wait()

    for _, t := range []string{"/usr/local/bin/menu", "/usr/local/bin/tdz"} {
        os.Remove(t)
        os.Symlink(filepath.Join(r.bindir, "tdz"), t)
    }
    fmt.Println("\nTDZ installed! Run: menu")
}
