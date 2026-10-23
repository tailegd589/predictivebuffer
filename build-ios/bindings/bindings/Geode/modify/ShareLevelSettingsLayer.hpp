#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/ShareLevelSettingsLayer.hpp>
#else
#include <Geode/modify_intel/ShareLevelSettingsLayer.hpp>
#endif
