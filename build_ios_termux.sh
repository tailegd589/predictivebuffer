#!/data/data/com.termux/files/usr/bin/bash
# ─────────────────────────────────────────────────────────────────────────────
#  build_ios_termux.sh
#  Build ai.predictivebuffer.ios.dylib trên Termux Android
#  Chạy từ thư mục gốc của project (nơi có CMakeLists.txt)
# ─────────────────────────────────────────────────────────────────────────────
set -e

# ── 0. Màu log ────────────────────────────────────────────────────────────────
RED='\033[0;31m'; GREEN='\033[0;32m'; YELLOW='\033[1;33m'; NC='\033[0m'
info()  { echo -e "${GREEN}[+]${NC} $*"; }
warn()  { echo -e "${YELLOW}[!]${NC} $*"; }
error() { echo -e "${RED}[x]${NC} $*"; exit 1; }

# ── 1. Kiểm tra & cài dependencies ───────────────────────────────────────────
info "Kiểm tra dependencies..."

MISSING=()
for tool in clang clang++ cmake ninja git zip; do
    command -v "$tool" &>/dev/null || MISSING+=("$tool")
done

if [ ${#MISSING[@]} -gt 0 ]; then
    warn "Thiếu: ${MISSING[*]}"
    info "Đang cài..."
    pkg update -y
    pkg install -y clang lld cmake ninja git zip
fi

# ── 2. Kiểm tra clang có support Darwin/MachO target không ───────────────────
info "Kiểm tra Darwin target support..."
echo 'int x;' > $TMPDIR/_test.c

if clang -target arm64-apple-ios16.0 -c $TMPDIR/_test.c -o $TMPDIR/_test.o 2>/dev/null; then
    info "clang Darwin target: OK"
    rm -f $TMPDIR/_test.o
else
    error "clang không support Darwin target.\n\
Thử cài llvm riêng: pkg install llvm\n\
Hoặc dùng script build_direct.sh thay thế."
fi

# Kiểm tra lld MachO
if ld.lld --help 2>&1 | grep -qi "macho\|darwin"; then
    info "lld MachO backend: OK"
else
    warn "lld có thể không có MachO backend — thử vẫn build, sẽ báo lỗi nếu fail."
fi

rm -f $TMPDIR/_test.c

# ── 3. Clone / update Geode SDK ───────────────────────────────────────────────
GEODE_SDK_DIR="$HOME/geode-sdk"

if [ ! -d "$GEODE_SDK_DIR" ]; then
    info "Clone Geode SDK..."
    git clone --depth=1 https://github.com/geode-sdk/geode "$GEODE_SDK_DIR"
else
    info "Geode SDK đã có tại $GEODE_SDK_DIR"
    cd "$GEODE_SDK_DIR"
    git pull --ff-only 2>/dev/null || warn "Không update được SDK (offline?)"
    cd - > /dev/null
fi

export GEODE_SDK="$GEODE_SDK_DIR"
info "GEODE_SDK = $GEODE_SDK"

# ── 4. Configure CMake ────────────────────────────────────────────────────────
PROJECT_DIR="$(cd "$(dirname "$0")" && pwd)"
BUILD_DIR="$PROJECT_DIR/build-ios"

info "Configure CMake..."
cmake -B "$BUILD_DIR" \
    -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_TOOLCHAIN_FILE="$PROJECT_DIR/ios.toolchain.cmake" \
    -DCMAKE_SYSTEM_NAME=iOS \
    -DCMAKE_OSX_ARCHITECTURES=arm64 \
    -DGEODE_DISABLE_PRECOMPILED_HEADERS=ON \
    "$PROJECT_DIR"

# ── 5. Build ──────────────────────────────────────────────────────────────────
info "Build..."
cmake --build "$BUILD_DIR" --config Release -j$(nproc)

# ── 6. Temukan output dylib ───────────────────────────────────────────────────
DYLIB=$(find "$BUILD_DIR" -name "*.dylib" | head -1)
if [ -z "$DYLIB" ]; then
    error "Không tìm thấy .dylib sau build.\nXem log trên để debug."
fi
info "Dylib built: $DYLIB"

# Verify Mach-O format
if file "$DYLIB" | grep -q "Mach-O"; then
    info "Format: $(file "$DYLIB")"
else
    warn "File không phải Mach-O — có thể clang đã build ELF thay vì MachO."
    warn "Xem BUILD_IOS.md phần 'Nếu vẫn ra ELF'."
fi

# ── 7. Đổi tên và đóng gói vào .geode ────────────────────────────────────────
IOS_DYLIB="$PROJECT_DIR/ai.predictivebuffer.ios.dylib"
cp "$DYLIB" "$IOS_DYLIB"
info "Copied → $IOS_DYLIB"

GEODE_FILE="$PROJECT_DIR/ai.predictivebuffer.geode"
if [ ! -f "$GEODE_FILE" ]; then
    warn "Không tìm thấy file 2.geode gốc. Copy nó vào project dir và đặt tên 'ai.predictivebuffer.geode' rồi chạy lại."
    info "Hiện tại chỉ có ai.predictivebuffer.ios.dylib — đóng gói thủ công sau."
else
    info "Đóng gói vào .geode..."
    # Zip vào file geode hiện có (update / add)
    cd "$PROJECT_DIR"
    zip -u "$GEODE_FILE" ai.predictivebuffer.ios.dylib mod.json
    info "Done: $GEODE_FILE"
fi

echo ""
echo -e "${GREEN}══════════════════════════════════════════${NC}"
echo -e "${GREEN}  BUILD XONG!${NC}"
echo -e "  iOS dylib : $IOS_DYLIB"
[ -f "$GEODE_FILE" ] && echo -e "  .geode    : $GEODE_FILE"
echo -e "${GREEN}══════════════════════════════════════════${NC}"
