#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SetupAreaMoveTriggerPopup.cpp>
#else
#include <Geode/source_intel/SetupAreaMoveTriggerPopup.cpp>
#endif
