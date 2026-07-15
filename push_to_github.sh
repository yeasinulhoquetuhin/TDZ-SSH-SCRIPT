#!/bin/bash
#
# TDZ-SSH-SCRIPT — One-click GitHub push helper
# =================================================
#
# Usage:
#   1) Create an empty repo on GitHub:  github.com/new
#      Owner: yeasinulhoquetuhin
#      Name : TDZ-SSH-SCRIPT
#      (DO NOT add README/.gitignore/license on GitHub — they already exist locally)
#
#   2) Create a Personal Access Token (classic) at:
#      https://github.com/settings/tokens/new?scopes=repo
#      Copy the token (starts with `ghp_`).
#
#   3) Run this script from inside the repo dir:
#        cd /home/z/my-project/download/TDZ-SSH-SCRIPT
#        bash push_to_github.sh
#      When prompted, paste your PAT. It is stored in plaintext at
#      ~/.git-credentials for future pushes (delete that file to forget).
#
# What this script does:
#   - Adds the GitHub remote (HTTPS URL)
#   - Configures credential storage so you only paste the token ONCE
#   - Pushes main branch with --set-upstream
#   - Verifies the push by fetching the install.sh raw URL
#

set -e

REPO_OWNER="yeasinulhoquetuhin"
REPO_NAME="TDZ-SSH-SCRIPT"
REMOTE_URL="https://github.com/${REPO_OWNER}/${REPO_NAME}.git"
RAW_INSTALL_URL="https://raw.githubusercontent.com/${REPO_OWNER}/${REPO_NAME}/main/install.sh"

# Colors
C_RESET=$'\033[0m'
C_RED=$'\033[38;5;196m'
C_GREEN=$'\033[38;5;46m'
C_YELLOW=$'\033[38;5;226m'
C_BLUE=$'\033[38;2;0;212;255m'

echo -e "${C_BLUE}════════════════════════════════════════════════════${C_RESET}"
echo -e "${C_BLUE}  TDZ-SSH-SCRIPT → GitHub Push Helper${C_RESET}"
echo -e "${C_BLUE}════════════════════════════════════════════════════${C_RESET}"
echo

# 1) Sanity checks
if [ ! -d .git ]; then
    echo -e "${C_RED}❌ Not in a git repo. Run this script from inside TDZ-SSH-SCRIPT/ .${C_RESET}"
    exit 1
fi
if ! git remote get-url origin >/dev/null 2>&1; then
    echo -e "${C_BLUE}➕ Adding remote: ${REMOTE_URL}${C_RESET}"
    git remote add origin "${REMOTE_URL}"
else
    echo -e "${C_YELLOW}ℹ️  Remote 'origin' already set to: $(git remote get-url origin)${C_RESET}"
    # If it's set to SSH or a different URL, ask user
    read -r -p "   Replace with HTTPS URL? (y/n) [n]: " replace_remote
    if [[ "$replace_remote" == "y" || "$replace_remote" == "Y" ]]; then
        git remote set-url origin "${REMOTE_URL}"
        echo -e "${C_GREEN}✅ Remote URL updated.${C_RESET}"
    fi
fi

# 2) Enable credential storage so token is cached
git config --global credential.helper store

# 3) Check if we already have stored credentials
if [ -f ~/.git-credentials ] && grep -q "github.com" ~/.git-credentials 2>/dev/null; then
    echo -e "${C_GREEN}✅ Found stored GitHub credentials in ~/.git-credentials${C_RESET}"
    echo -e "${C_YELLOW}   (Delete that file to force re-auth next time.)${C_RESET}"
    HAS_CREDS=1
else
    HAS_CREDS=0
fi

# 4) Show pending commits
echo
echo -e "${C_BLUE}📋 Commits to be pushed:${C_RESET}"
git log --oneline origin/main..HEAD 2>/dev/null || git log --oneline | head -5
echo

# 5) Push
echo -e "${C_BLUE}🚀 Pushing to GitHub...${C_RESET}"
if [[ "$HAS_CREDS" -eq 0 ]]; then
    echo -e "${C_YELLOW}   You will be asked for your GitHub username + PAT (use token as password).${C_RESET}"
fi
if git push -u origin main; then
    echo
    echo -e "${C_GREEN}════════════════════════════════════════════════════${C_RESET}"
    echo -e "${C_GREEN}  ✅ PUSH SUCCEEDED!${C_RESET}"
    echo -e "${C_GREEN}════════════════════════════════════════════════════${C_RESET}"
    echo
    echo -e "${C_BLUE}🌐 Repo:   https://github.com/${REPO_OWNER}/${REPO_NAME}${C_RESET}"
    echo -e "${C_BLUE}📄 Raw:    ${RAW_INSTALL_URL}${C_RESET}"
    echo
    echo -e "${C_BLUE}🔍 Verifying raw install.sh is reachable...${C_RESET}"
    HTTP_CODE=$(curl -s -o /dev/null -w "%{http_code}" "${RAW_INSTALL_URL}")
    if [[ "$HTTP_CODE" == "200" ]]; then
        echo -e "${C_GREEN}✅ install.sh is publicly reachable (HTTP 200)${C_RESET}"
        echo
        echo -e "${C_GREEN}🎉 Anyone can now install TDZ TUNNEL Manager with:${C_RESET}"
        echo
        echo -e "    ${C_YELLOW}bash <(curl -Ls ${RAW_INSTALL_URL})${C_RESET}"
        echo
    else
        echo -e "${C_YELLOW}⚠️  install.sh returned HTTP $HTTP_CODE (may take a minute to propagate)${C_RESET}"
        echo -e "${C_YELLOW}   Wait 30 seconds and try: curl -I ${RAW_INSTALL_URL}${C_RESET}"
    fi
else
    echo
    echo -e "${C_RED}════════════════════════════════════════════════════${C_RESET}"
    echo -e "${C_RED}  ❌ PUSH FAILED${C_RESET}"
    echo -e "${C_RED}════════════════════════════════════════════════════${C_RESET}"
    echo
    echo -e "${C_YELLOW}Common fixes:${C_RESET}"
    echo -e "  1. Make sure the repo exists: https://github.com/new"
    echo -e "     Owner: ${REPO_OWNER}   Name: ${REPO_NAME}"
    echo -e "  2. Use a Personal Access Token (PAT) as the password — not your GitHub password."
    echo -e "     Create one at: https://github.com/settings/tokens/new?scopes=repo"
    echo -e "  3. If using 2FA, the PAT is mandatory."
    echo -e "  4. To reset stored credentials: rm -f ~/.git-credentials"
    exit 1
fi
