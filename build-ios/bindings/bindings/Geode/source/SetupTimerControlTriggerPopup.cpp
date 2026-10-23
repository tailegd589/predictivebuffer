#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SetupTimerControlTriggerPopup.cpp>
#else
#include <Geode/source_intel/SetupTimerControlTriggerPopup.cpp>
#endif
