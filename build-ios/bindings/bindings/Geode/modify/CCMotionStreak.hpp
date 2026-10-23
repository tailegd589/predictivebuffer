#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCMotionStreak.hpp>
#else
#include <Geode/modify_intel/CCMotionStreak.hpp>
#endif
