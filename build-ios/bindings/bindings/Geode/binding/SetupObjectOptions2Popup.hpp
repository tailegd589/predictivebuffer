#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/SetupObjectOptions2Popup.hpp>
#else
#include <Geode/binding_intel/SetupObjectOptions2Popup.hpp>
#endif
