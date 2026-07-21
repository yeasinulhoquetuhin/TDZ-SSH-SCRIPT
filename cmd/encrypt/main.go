package main

import (
    "fmt"
    "os"
    "path/filepath"
    "tdz/internal/crypto"
)

func main() {
    dir, _ := os.Getwd()
    for {
        if _, err := os.Stat(filepath.Join(dir, "go.mod")); err == nil { break }
        parent := filepath.Dir(dir)
        if parent == dir { fmt.Println("go.mod not found"); os.Exit(1) }
        dir = parent
    }

    src := filepath.Join(dir, "original")
    dst := filepath.Join(dir, "internal", "mgr", "scripts")
    os.RemoveAll(dst)
    os.MkdirAll(dst, 0755)

    // Only TDZ scripts (not build/install helpers)
    tdzFiles := []string{
        "menu.sh", "openvpn_module.sh", "install.sh",
        "tdz_openvpn_gateway.py", "tdz_openvpn_portal.py",
        "tdz_openvpn_runtime.py", "tdz_ssh_auth_session.py",
        "ws_ssh_bridge.py", "ssh",
    }

    for _, name := range tdzFiles {
        f := filepath.Join(src, name)
        data, err := os.ReadFile(f)
        if err != nil { fmt.Printf("SKIP %s\n", name); continue }
        enc, _ := crypto.Encrypt(data)
        out := filepath.Join(dst, name)
        os.WriteFile(out, []byte(enc), 0644)
        fmt.Printf("OK %s (%dB)\n", name, len(data))
    }
    fmt.Println("Encryption done:", len(tdzFiles), "files")
}
