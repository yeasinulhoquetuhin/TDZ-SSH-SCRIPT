#!/bin/bash
set -Eeuo pipefail

# Build the official, checksummed Linux release archives. Core runtime source
# is packed separately; this script never prints or stores the payload key in
# an archive.

RELEASE_TAG="${TDZ_RELEASE_TAG:-v0.0.1}"
RELEASE_NAME="${TDZ_RELEASE_NAME:-v0.0.1 BETA}"
GO_BIN="${GO_BIN:-go}"
OUT_DIR="${TDZ_RELEASE_OUT:-.release-work/dist/$RELEASE_TAG}"
KEY_FILE="${TDZ_PAYLOAD_KEY_FILE:-.release-work/payload.key}"
PAYLOAD_FILE="release-tools/launcher/payload.enc"

[[ "$RELEASE_TAG" =~ ^v[0-9]+\.[0-9]+\.[0-9]+([.-][A-Za-z0-9.-]+)?$ ]] || {
    echo "Invalid release tag: $RELEASE_TAG" >&2
    exit 1
}
[[ "$RELEASE_NAME" == "$RELEASE_TAG"* ]] || {
    echo "Release name must begin with $RELEASE_TAG" >&2
    exit 1
}
case "$OUT_DIR" in
    ""|/|/bin|/boot|/dev|/etc|/home|/root|/run|/usr|/var) echo "Unsafe output directory" >&2; exit 1 ;;
esac
command -v "$GO_BIN" >/dev/null 2>&1 || { echo "Go toolchain was not found" >&2; exit 1; }
command -v sha256sum >/dev/null 2>&1 || { echo "sha256sum was not found" >&2; exit 1; }
command -v tar >/dev/null 2>&1 || { echo "tar was not found" >&2; exit 1; }
command -v gzip >/dev/null 2>&1 || { echo "gzip was not found" >&2; exit 1; }

if [[ -n "${TDZ_PRIVATE_SOURCE:-}" ]]; then
    "$GO_BIN" run ./release-tools/packer \
        -source "$TDZ_PRIVATE_SOURCE" \
        -out "$PAYLOAD_FILE" \
        -key-out "$KEY_FILE"
fi
[[ -s "$PAYLOAD_FILE" ]] || { echo "Packed payload is missing" >&2; exit 1; }

if [[ -n "${TDZ_PAYLOAD_KEY:-}" ]]; then
    PAYLOAD_KEY=$TDZ_PAYLOAD_KEY
else
    [[ -r "$KEY_FILE" ]] || { echo "Payload key file is missing" >&2; exit 1; }
    PAYLOAD_KEY=$(tr -d '\r\n' < "$KEY_FILE")
fi
[[ "$PAYLOAD_KEY" =~ ^[a-fA-F0-9]{64}$ ]] || { echo "Payload key is invalid" >&2; exit 1; }

BUILD_COMMIT="${TDZ_BUILD_COMMIT:-$(git rev-parse --verify HEAD)}"
BUILD_TIME="${TDZ_BUILD_TIME:-$(git show -s --format=%cI "$BUILD_COMMIT")}"
SOURCE_EPOCH="${SOURCE_DATE_EPOCH:-$(git show -s --format=%ct "$BUILD_COMMIT")}"
mkdir -p "$OUT_DIR"

architectures=(
    "amd64:amd64:"
    "arm64:arm64:"
    "armv7:arm:7"
    "armv6:arm:6"
    "386:386:"
    "ppc64le:ppc64le:"
    "s390x:s390x:"
    "riscv64:riscv64:"
)

for target in "${architectures[@]}"; do
    IFS=: read -r asset_arch goarch goarm <<<"$target"
    stage=$(mktemp -d "${TMPDIR:-/tmp}/tdz-release-${asset_arch}.XXXXXX")
    archive="$OUT_DIR/tdz-linux-${asset_arch}.tar.gz"
    tar_tmp=$(mktemp "${TMPDIR:-/tmp}/tdz-archive-${asset_arch}.XXXXXX")
    archive_tmp="${tar_tmp}.gz"

    build_env=(CGO_ENABLED=0 GOOS=linux GOARCH="$goarch")
    [[ -n "$goarm" ]] && build_env+=(GOARM="$goarm")
    env "${build_env[@]}" "$GO_BIN" build \
        -trimpath -buildvcs=false \
        -ldflags="-s -w -buildid= -X main.payloadKeyHex=$PAYLOAD_KEY -X main.buildCommit=$BUILD_COMMIT -X main.buildTime=$BUILD_TIME" \
        -o "$stage/tdz" ./release-tools/launcher
    chmod 755 "$stage/tdz"

    if [[ "$asset_arch" == "amd64" && "$(uname -m)" =~ ^(x86_64|amd64)$ ]]; then
        "$stage/tdz" self-test >/dev/null
        "$stage/tdz" version --json | grep -Fq "\"version\":\"$RELEASE_NAME\""
        "$stage/tdz" --source-only </dev/null >/dev/null
        "$stage/tdz" runtime tdz-openvpn-runtime --help >/dev/null
    fi

    tar --sort=name --owner=0 --group=0 --numeric-owner \
        --mtime="@$SOURCE_EPOCH" -C "$stage" -cf "$tar_tmp" tdz
    gzip -n -9 "$tar_tmp"
    gzip -t "$archive_tmp"
    [[ $(tar -tzf "$archive_tmp") == "tdz" ]]
    [[ $(stat -c '%s' "$archive_tmp") -gt 0 ]]
    mv -f "$archive_tmp" "$archive"
    echo "Built $(basename "$archive")"
    find "$stage" -depth -type f -delete 2>/dev/null || true
    find "$stage" -depth -type d -empty -delete 2>/dev/null || true
done

checksums_tmp=$(mktemp "${TMPDIR:-/tmp}/tdz-checksums.XXXXXX")
(
    cd "$OUT_DIR"
    sha256sum tdz-linux-*.tar.gz | sort -k2
) > "$checksums_tmp"
mv -f "$checksums_tmp" "$OUT_DIR/checksums.txt"
chmod 644 "$OUT_DIR"/*.tar.gz "$OUT_DIR/checksums.txt"
printf 'Release assets ready: %s (%d architectures)\n' "$OUT_DIR" "${#architectures[@]}"
