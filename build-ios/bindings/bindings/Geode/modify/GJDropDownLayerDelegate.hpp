#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/GJDropDownLayerDelegate.hpp>
#else
#include <Geode/modify_intel/GJDropDownLayerDelegate.hpp>
#endif
