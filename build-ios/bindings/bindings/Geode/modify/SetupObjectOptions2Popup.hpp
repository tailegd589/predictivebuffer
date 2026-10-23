#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/SetupObjectOptions2Popup.hpp>
#else
#include <Geode/modify_intel/SetupObjectOptions2Popup.hpp>
#endif
