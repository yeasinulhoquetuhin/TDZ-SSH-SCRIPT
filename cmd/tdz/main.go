package main

import (
    "fmt"
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
    case "run":
        if len(os.Args) < 3 {
            fmt.Fprintf(os.Stderr, "Usage: tdz run <script>\n")
            os.Exit(1)
        }
        r.Run(os.Args[2])
    default:
        r.Menu()
    }
}
