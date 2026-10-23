#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/ConfigureValuePopup.hpp>
#else
#include <Geode/modify_intel/ConfigureValuePopup.hpp>
#endif
