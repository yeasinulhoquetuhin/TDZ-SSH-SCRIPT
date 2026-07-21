package main

import (
	"strings"
	"testing"
)

func TestCanonicalSSHBrandingReplacesDuplicates(t *testing.T) {
	input := []byte("Port 22\nVersionAddendum someone\nVersionAddendum another\nUsePAM yes\n")
	got := string(canonicalSSHBranding(input))
	if strings.Count(got, brandingLine) != 1 {
		t.Fatalf("expected one official branding line, got %q", got)
	}
	if strings.Contains(got, "someone") || strings.Contains(got, "another") {
		t.Fatalf("unofficial branding survived: %q", got)
	}
}

func TestCanonicalSSHBrandingAddsMissingLine(t *testing.T) {
	got := string(canonicalSSHBranding([]byte("Port 22\nUsePAM yes\n")))
	if !strings.HasSuffix(got, brandingLine+"\n") {
		t.Fatalf("official branding was not appended: %q", got)
	}
}

func TestLegacyDispatchAliasesStayAvailable(t *testing.T) {
	aliases := []string{
		"tdztunnel-limiter.sh",
		"tdztunnel-trial-cleanup.sh",
		"tdztunnel-auto-backup-bot.sh",
		"tdz-ws-ssh-bridge.py",
	}
	for _, alias := range aliases {
		if _, ok := dispatchByName[alias]; !ok {
			t.Errorf("missing migration alias %q", alias)
		}
	}
}
