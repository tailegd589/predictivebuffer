#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCFileUtilsWin32.cpp>
#else
#include <Geode/source_intel/CCFileUtilsWin32.cpp>
#endif
