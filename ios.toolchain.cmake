# ios.toolchain.cmake — cross-compile iOS Mach-O từ Termux (Linux ARM64)
# Dùng LLVM clang + lld (MachO backend)

set(CMAKE_SYSTEM_NAME      Darwin)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

# Termux clang path — điều chỉnh nếu khác
set(CLANG   "clang")
set(CLANGXX "clang++")

set(CMAKE_C_COMPILER   ${CLANG})
set(CMAKE_CXX_COMPILER ${CLANGXX})

# Target triple iOS arm64
set(IOS_TARGET "arm64-apple-ios16.0")

set(CMAKE_C_FLAGS_INIT   "-target ${IOS_TARGET} -arch arm64")
set(CMAKE_CXX_FLAGS_INIT "-target ${IOS_TARGET} -arch arm64")

# Linker: lld với MachO flavour
# ld.lld tự detect từ target triple khi dipassed qua clang -fuse-ld=lld
set(CMAKE_EXE_LINKER_FLAGS_INIT    "-fuse-ld=lld -target ${IOS_TARGET}")
set(CMAKE_SHARED_LINKER_FLAGS_INIT "-fuse-ld=lld -target ${IOS_TARGET}")
set(CMAKE_MODULE_LINKER_FLAGS_INIT "-fuse-ld=lld -target ${IOS_TARGET}")

# Tắt sysroot check (ta dùng header từ Geode SDK, không cần Xcode SDK)
set(CMAKE_SYSROOT "")
set(CMAKE_OSX_SYSROOT "")
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Không check compiler works (cross-compile)
set(CMAKE_C_COMPILER_WORKS   1)
set(CMAKE_CXX_COMPILER_WORKS 1)
