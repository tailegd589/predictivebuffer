#!/data/data/com.termux/files/usr/bin/bash
# ─────────────────────────────────────────────────────────────────────────────
#  build_direct.sh — fallback nếu CMake không chạy được
#  Gọi thẳng clang++ và ld.lld, không qua Geode's CMake system
# ─────────────────────────────────────────────────────────────────────────────
set -e

RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[1;33m'; NC='\033[0m'
info()  { echo -e "${GREEN}[+]${NC} $*"; }
warn()  { echo -e "${YELLOW}[!]${NC} $*"; }
error() { echo -e "${RED}[x]${NC} $*"; exit 1; }

GEODE_SDK="${GEODE_SDK:-$HOME/geode-sdk}"
PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
SRC="$PROJECT_DIR/src/main.cpp"
OBJ="$TMPDIR/predictivebuffer.o"
OUT="$PROJECT_DIR/ai.predictivebuffer.ios.dylib"

[ -d "$GEODE_SDK" ] || error "GEODE_SDK tidak ditemukan: $GEODE_SDK\nChạy build_ios_termux.sh trước để clone SDK."
[ -f "$SRC" ]       || error "src/main.cpp không tìm thấy"

# ── Include paths từ Geode SDK ───────────────────────────────────────────────
INCLUDES=(
    "-I$GEODE_SDK/loader/include"
    "-I$GEODE_SDK/loader/include/Geode"
    "-I$GEODE_SDK/loader/include/Geode/cocos/include"
    "-I$GEODE_SDK/loader/include/Geode/cocos/extensions"
    "-I$GEODE_SDK/loader/include/Geode/fmod"
    "-I$GEODE_SDK/bindings/include"          # GD class definitions
    "-I$PREFIX/include/c++/v1"               # libc++ headers từ Termux
)

TARGET="arm64-apple-ios16.0"

# ── Compile ───────────────────────────────────────────────────────────────────
info "Compiling $SRC..."
clang++ \
    -target "$TARGET" \
    -arch arm64 \
    -std=c++20 \
    -O2 \
    -fPIC \
    -fvisibility=hidden \
    -fvisibility-inlines-hidden \
    -DGEODE_IS_IOS=1 \
    -DCOCOS2D_DEBUG=0 \
    -DCC_TARGET_OS_IPHONE=1 \
    "${INCLUDES[@]}" \
    -c "$SRC" \
    -o "$OBJ"

info "Compile OK → $OBJ"

# ── Link ──────────────────────────────────────────────────────────────────────
info "Linking Mach-O dylib..."
clang++ \
    -target "$TARGET" \
    -arch arm64 \
    -fuse-ld=lld \
    -dynamiclib \
    -install_name "@rpath/ai.predictivebuffer.ios.dylib" \
    -compatibility_version 1.0 \
    -current_version 1.0 \
    -Wl,-undefined,dynamic_lookup \
    -Wl,-platform_version,ios,16.0,16.0 \
    "$OBJ" \
    -o "$OUT"

info "Link OK"

# ── Verify ────────────────────────────────────────────────────────────────────
if file "$OUT" | grep -q "Mach-O"; then
    info "✓ Mach-O ARM64 dylib: $OUT"
else
    warn "file output: $(file "$OUT")"
    warn "Có thể vẫn là ELF nếu lld không có MachO backend."
fi

# ── Pack ─────────────────────────────────────────────────────────────────────
GEODE_FILE="$PROJECT_DIR/ai.predictivebuffer.geode"
if [ -f "$GEODE_FILE" ]; then
    zip -u "$GEODE_FILE" "$(basename "$OUT")" mod.json
    info "Packed → $GEODE_FILE"
fi

echo ""
echo -e "${GREEN}Done: $OUT${NC}"
