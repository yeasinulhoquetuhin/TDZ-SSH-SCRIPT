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
