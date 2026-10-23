#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/SelectListIconDelegate.hpp>
#else
#include <Geode/modify_intel/SelectListIconDelegate.hpp>
#endif
