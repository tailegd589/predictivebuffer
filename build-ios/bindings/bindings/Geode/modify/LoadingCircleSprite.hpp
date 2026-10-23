#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/LoadingCircleSprite.hpp>
#else
#include <Geode/modify_intel/LoadingCircleSprite.hpp>
#endif
