#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/DailyLevelPage.hpp>
#else
#include <Geode/binding_intel/DailyLevelPage.hpp>
#endif
