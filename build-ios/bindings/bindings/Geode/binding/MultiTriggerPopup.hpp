#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/MultiTriggerPopup.hpp>
#else
#include <Geode/binding_intel/MultiTriggerPopup.hpp>
#endif
