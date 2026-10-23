#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCFileUtilsWin32.hpp>
#else
#include <Geode/modify_intel/CCFileUtilsWin32.hpp>
#endif
