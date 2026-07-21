package main

import (
    "fmt"
    "os"
    "path/filepath"
    "tdz/internal/crypto"
)

func main() {
    // Find project root (where go.mod is)
    dir, _ := os.Getwd()
    for {
        if _, err := os.Stat(filepath.Join(dir, "go.mod")); err == nil {
            break
        }
        parent := filepath.Dir(dir)
        if parent == dir { fmt.Println("go.mod not found"); os.Exit(1) }
        dir = parent
    }

    src := filepath.Join(dir, "original")
    dst := filepath.Join(dir, "internal", "mgr", "scripts")
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
    fmt.Println("Encryption done:", len(files), "files")
}
