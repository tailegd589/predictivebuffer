#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SetupEndPopup.cpp>
#else
#include <Geode/source_intel/SetupEndPopup.cpp>
#endif
