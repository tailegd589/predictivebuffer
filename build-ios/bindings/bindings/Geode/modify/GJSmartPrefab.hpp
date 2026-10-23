#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/GJSmartPrefab.hpp>
#else
#include <Geode/modify_intel/GJSmartPrefab.hpp>
#endif
