package main

import (
    "os"
    "path/filepath"
    "tdz/internal/mgr"
)

func main() {
    bindir, _ := filepath.Abs(filepath.Dir(os.Args[0]))
    r := mgr.New(bindir)

    cmd := ""
    if len(os.Args) >= 2 {
        cmd = os.Args[1]
    }
    if filepath.Base(os.Args[0]) == "menu" && cmd == "" {
        cmd = "menu"
    }

    switch cmd {
    case "install", "i":
        r.Install()
    default:
        r.Menu()
    }
}
