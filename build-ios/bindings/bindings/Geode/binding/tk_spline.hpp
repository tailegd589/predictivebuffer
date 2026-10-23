#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/tk_spline.hpp>
#else
#include <Geode/binding_intel/tk_spline.hpp>
#endif
