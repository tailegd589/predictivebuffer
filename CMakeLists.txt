cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_OSX_ARCHITECTURES "arm64")

# ── Project ──────────────────────────────────────────────────────────────────
project(ai.predictivebuffer VERSION 1.0.0)

# ── Geode SDK ─────────────────────────────────────────────────────────────────
# CPM will be fetched by setup.cmake — run `geode sdk install` first
if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR
        "GEODE_SDK environment variable not set.\n"
        "Run: geode sdk install\n"
        "Then set GEODE_SDK to the SDK path.")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# ── Sources ───────────────────────────────────────────────────────────────────
add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

# ── Geode setup ───────────────────────────────────────────────────────────────
setup_geode_mod(${PROJECT_NAME})

# ── iOS-specific flags ────────────────────────────────────────────────────────
if (${CMAKE_SYSTEM_NAME} STREQUAL "iOS")
    # Minimum deployment target — GD on iOS requires 16.0
    set_target_properties(${PROJECT_NAME} PROPERTIES
        XCODE_ATTRIBUTE_IPHONEOS_DEPLOYMENT_TARGET "16.0"
    )
endif()
