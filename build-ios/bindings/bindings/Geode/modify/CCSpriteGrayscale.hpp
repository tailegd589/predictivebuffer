#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCSpriteGrayscale.hpp>
#else
#include <Geode/modify_intel/CCSpriteGrayscale.hpp>
#endif
