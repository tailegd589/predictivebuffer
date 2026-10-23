#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCSpeed.cpp>
#else
#include <Geode/source_intel/CCSpeed.cpp>
#endif
