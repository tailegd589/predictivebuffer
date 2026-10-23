#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/SetupSFXEditPopup.hpp>
#else
#include <Geode/modify_intel/SetupSFXEditPopup.hpp>
#endif
