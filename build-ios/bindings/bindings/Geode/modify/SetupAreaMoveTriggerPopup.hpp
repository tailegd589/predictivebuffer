#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/SetupAreaMoveTriggerPopup.hpp>
#else
#include <Geode/modify_intel/SetupAreaMoveTriggerPopup.hpp>
#endif
