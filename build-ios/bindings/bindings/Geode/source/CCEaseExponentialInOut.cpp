#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCEaseExponentialInOut.cpp>
#else
#include <Geode/source_intel/CCEaseExponentialInOut.cpp>
#endif
