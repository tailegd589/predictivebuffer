#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCProgressTo.cpp>
#else
#include <Geode/source_intel/CCProgressTo.cpp>
#endif
