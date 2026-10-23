# Build hướng dẫn — ai.predictivebuffer iOS dylib

## Yêu cầu

| Công cụ | Version |
|---------|---------|
| macOS | 13+ (Ventura trở lên) |
| Xcode | 15+ |
| Geode CLI | mới nhất |
| Geode SDK | mới nhất |
| CMake | 3.21+ |

---

## Bước 1 — Cài Geode SDK

```bash
# Cài Geode CLI (nếu chưa có)
brew install geode-sdk/geode/geode-cli

# Cài SDK
geode sdk install
geode sdk update
```

---

## Bước 2 — Clone / đặt project

Đặt thư mục này ở bất kỳ đâu, ví dụ:
```
~/mods/predictivebuffer/
├── src/main.cpp
├── CMakeLists.txt
└── mod.json
```

---

## Bước 3 — Build cho iOS

```bash
cd ~/mods/predictivebuffer

cmake -B build-ios \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_SYSTEM_NAME=iOS \
    -DCMAKE_OSX_ARCHITECTURES=arm64 \
    -DCMAKE_OSX_DEPLOYMENT_TARGET=16.0 \
    -DCMAKE_TOOLCHAIN_FILE=$GEODE_SDK/cmake/ios.toolchain.cmake

cmake --build build-ios --config Release
```

Output: `build-ios/ai.predictivebuffer.dylib`

---

## Bước 4 — Đổi tên và đóng gói

```bash
# Đổi tên đúng format geode
cp build-ios/ai.predictivebuffer.dylib ai.predictivebuffer.ios.dylib

# Tạo .geode mới (copy từ bản gốc, thêm ios dylib)
cp 2.geode ai.predictivebuffer.geode
zip ai.predictivebuffer.geode ai.predictivebuffer.ios.dylib
zip ai.predictivebuffer.geode mod.json   # update mod.json có ios target
```

Hoặc dùng Geode CLI để build trực tiếp:
```bash
geode build --platform ios
# CLI tự tạo .geode với đúng filename
```

---

## Lưu ý về iOS toolchain của Geode

Geode SDK đã có sẵn `ios.toolchain.cmake` từ phiên bản 3.x trở đi.
Nếu thiếu, clone thêm:
```bash
git clone https://github.com/leetal/ios-cmake $GEODE_SDK/cmake/ios-cmake
# Dùng: -DCMAKE_TOOLCHAIN_FILE=$GEODE_SDK/cmake/ios-cmake/ios.toolchain.cmake
```

---

## Verify output

```bash
file ai.predictivebuffer.ios.dylib
# Phải ra: Mach-O 64-bit dynamically linked shared library arm64
```
