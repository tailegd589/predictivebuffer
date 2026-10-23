#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCScale9Sprite.cpp>
#else
#include <Geode/source_intel/CCScale9Sprite.cpp>
#endif
