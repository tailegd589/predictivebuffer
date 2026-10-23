#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SelectPremadeDelegate.cpp>
#else
#include <Geode/source_intel/SelectPremadeDelegate.cpp>
#endif
