#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GJColorSetupLayer.cpp>
#else
#include <Geode/source_intel/GJColorSetupLayer.cpp>
#endif
