// Package tdz contains public project metadata used by repository assets.
package tdz

const (
	Name    = "TDZ SSH TUNNEL"
	Version = "v0.0.1 BETA"
)

// LinuxArchitectures lists the CPU families used by TDZ deployments.
var LinuxArchitectures = []string{
	"amd64",
	"arm64",
	"armv7",
	"armv6",
	"386",
	"ppc64le",
	"s390x",
	"riscv64",
}
