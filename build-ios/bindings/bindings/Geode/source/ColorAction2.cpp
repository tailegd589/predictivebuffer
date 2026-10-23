#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/ColorAction2.cpp>
#else
#include <Geode/source_intel/ColorAction2.cpp>
#endif
