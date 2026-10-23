#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SetupMGTrigger.cpp>
#else
#include <Geode/source_intel/SetupMGTrigger.cpp>
#endif
