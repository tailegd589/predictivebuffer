#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/AdvancedFollowTriggerObject.cpp>
#else
#include <Geode/source_intel/AdvancedFollowTriggerObject.cpp>
#endif
