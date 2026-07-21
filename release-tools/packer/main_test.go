package main

import "testing"

func TestHeredocExtraction(t *testing.T) {
	source := "before\ncat > target << 'END'\nfirst\nsecond\nEND\nafter\n"
	got, err := heredoc(source, "cat > target << 'END'", "END")
	if err != nil {
		t.Fatal(err)
	}
	if got != "first\nsecond\n" {
		t.Fatalf("unexpected heredoc: %q", got)
	}
}

func TestReplaceSection(t *testing.T) {
	got, err := replaceSection("before START old END after", "START", "END", "new")
	if err != nil {
		t.Fatal(err)
	}
	if got != "before new after" {
		t.Fatalf("unexpected replacement: %q", got)
	}
}

func TestFirewallRejectsEmptySubnets(t *testing.T) {
	needle := `[ -n "$TCP_SUBNET" ] && [ -n "$UDP_SUBNET" ] || exit 1`
	if !contains(openVPNFirewall, needle) {
		t.Fatalf("packed firewall does not validate both subnets")
	}
}

func contains(value, part string) bool {
	for i := 0; i+len(part) <= len(value); i++ {
		if value[i:i+len(part)] == part {
			return true
		}
	}
	return false
}
