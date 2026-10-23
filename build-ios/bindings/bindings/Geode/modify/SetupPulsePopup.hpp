#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/SetupPulsePopup.hpp>
#else
#include <Geode/modify_intel/SetupPulsePopup.hpp>
#endif
