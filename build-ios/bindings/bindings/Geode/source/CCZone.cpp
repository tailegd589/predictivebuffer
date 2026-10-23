#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCZone.cpp>
#else
#include <Geode/source_intel/CCZone.cpp>
#endif
