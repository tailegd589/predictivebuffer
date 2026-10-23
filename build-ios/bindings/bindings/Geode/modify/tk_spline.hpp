#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/tk_spline.hpp>
#else
#include <Geode/modify_intel/tk_spline.hpp>
#endif
