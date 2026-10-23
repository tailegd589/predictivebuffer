#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SetupCameraModePopup.cpp>
#else
#include <Geode/source_intel/SetupCameraModePopup.cpp>
#endif
