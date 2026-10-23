#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SetupOpacityPopup.cpp>
#else
#include <Geode/source_intel/SetupOpacityPopup.cpp>
#endif
