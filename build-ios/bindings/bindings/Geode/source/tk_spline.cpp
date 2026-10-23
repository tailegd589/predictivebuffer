#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/tk_spline.cpp>
#else
#include <Geode/source_intel/tk_spline.cpp>
#endif
