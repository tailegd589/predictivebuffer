#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCScale9Sprite.hpp>
#else
#include <Geode/modify_intel/CCScale9Sprite.hpp>
#endif
