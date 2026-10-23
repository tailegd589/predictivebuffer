#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/LeaderboardManagerDelegate.cpp>
#else
#include <Geode/source_intel/LeaderboardManagerDelegate.cpp>
#endif
