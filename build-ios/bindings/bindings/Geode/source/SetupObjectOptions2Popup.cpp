#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SetupObjectOptions2Popup.cpp>
#else
#include <Geode/source_intel/SetupObjectOptions2Popup.cpp>
#endif
