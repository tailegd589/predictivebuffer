#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/GooglePlayDelegate.hpp>
#else
#include <Geode/modify_intel/GooglePlayDelegate.hpp>
#endif
