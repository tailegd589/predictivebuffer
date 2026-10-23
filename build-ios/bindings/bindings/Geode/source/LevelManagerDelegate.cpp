#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/LevelManagerDelegate.cpp>
#else
#include <Geode/source_intel/LevelManagerDelegate.cpp>
#endif
