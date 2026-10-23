#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/DailyLevelNode.hpp>
#else
#include <Geode/modify_intel/DailyLevelNode.hpp>
#endif
