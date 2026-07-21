#!/bin/bash
set -e
cd /root/tdz-build

# cleanup
rm -rf cmd internal go.mod go.sum tdz

# ---- go.mod ----
cat > go.mod << 'GOMOD'
module tdz
go 1.21
GOMOD

mkdir -p cmd/{tdz,encrypt} internal/{crypto,mgr/scripts}

# ---- internal/crypto/aes.go ----
cat > internal/crypto/aes.go << 'CRYPTO'
package crypto

import (
    "crypto/aes"
    "crypto/cipher"
    "crypto/rand"
    "encoding/hex"
    "fmt"
    "io"
)

var key = []byte("TDZ-SuperSecure-32byteKey!2024!!")

func Encrypt(plaintext []byte) (string, error) {
    block, _ := aes.NewCipher(key)
    c := make([]byte, aes.BlockSize+len(plaintext))
    iv := c[:aes.BlockSize]
    io.ReadFull(rand.Reader, iv)
    stream := cipher.NewCFBEncrypter(block, iv)
    stream.XORKeyStream(c[aes.BlockSize:], plaintext)
    return hex.EncodeToString(c), nil
}

func Decrypt(hexData string) ([]byte, error) {
    data, _ := hex.DecodeString(hexData)
    block, _ := aes.NewCipher(key)
    if len(data) < aes.BlockSize {
        return nil, fmt.Errorf("too short")
    }
    iv := data[:aes.BlockSize]
    data = data[aes.BlockSize:]
    stream := cipher.NewCFBDecrypter(block, iv)
    stream.XORKeyStream(data, data)
    return data, nil
}
CRYPTO

# ---- cmd/encrypt/main.go ----
cat > cmd/encrypt/main.go << 'ENCRYPT'
package main

import (
    "fmt"
    "os"
    "path/filepath"
    "tdz/internal/crypto"
)

func main() {
    src := "/root/tdz-build/original"
    dst := "/root/tdz-build/internal/mgr/scripts"
    os.RemoveAll(dst)
    os.MkdirAll(dst, 0755)

    sh, _ := filepath.Glob(src + "/*.sh")
    py, _ := filepath.Glob(src + "/*.py")
    files := append(sh, py...)

    for _, f := range files {
        data, _ := os.ReadFile(f)
        enc, _ := crypto.Encrypt(data)
        out := filepath.Join(dst, filepath.Base(f))
        os.WriteFile(out, []byte(enc), 0644)
        fmt.Printf("OK %s (%dB)\n", filepath.Base(f), len(data))
    }
}
ENCRYPT

# ---- internal/mgr/runner.go ----
cat > internal/mgr/runner.go << 'RUNNER'
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
RUNNER

# ---- cmd/tdz/main.go ----
cat > cmd/tdz/main.go << 'MAIN'
package main

import (
    "fmt"
    "os"
    "path/filepath"
    "tdz/internal/mgr"
)

func main() {
    if len(os.Args) < 2 {
        fmt.Println("TDZ SSH TUNNEL")
        fmt.Println("  tdz menu      Start management menu")
        fmt.Println("  tdz install   Install TDZ")
        os.Exit(0)
    }
    bindir, _ := filepath.Abs(filepath.Dir(os.Args[0]))
    r := mgr.New(bindir)
    switch os.Args[1] {
    case "menu", "m":
        r.Menu()
    case "install", "i":
        r.Install()
    default:
        fmt.Println("Unknown:", os.Args[1])
    }
}
MAIN

echo "=== All files created ==="

# ---- Step 1: Copy original scripts ----
echo "[1/4] Copying original scripts..."
rm -rf /root/tdz-build/original
mkdir -p /root/tdz-build/original
for f in /root/tdz-build/*.sh /root/tdz-build/*.py; do
    [ -f "$f" ] && cp "$f" /root/tdz-build/original/
done
cp /root/tdz-build/ssh /root/tdz-build/original/ 2>/dev/null || true

# ---- Step 2: Encrypt scripts ----
echo "[2/4] Encrypting scripts..."
go run cmd/encrypt/main.go

# ---- Step 3: Build binary ----
echo "[3/4] Building binary..."
CGO_ENABLED=0 go build -ldflags="-s -w" -o tdz cmd/tdz/main.go

# ---- Step 4: Summary ----
echo ""
echo "[4/4] BUILD COMPLETE!"
ls -lh tdz
file tdz
echo ""
echo "Test with: ./tdz"
