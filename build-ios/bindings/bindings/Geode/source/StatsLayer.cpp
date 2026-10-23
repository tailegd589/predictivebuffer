#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/StatsLayer.cpp>
#else
#include <Geode/source_intel/StatsLayer.cpp>
#endif
