#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/EventTriggerInstance.cpp>
#else
#include <Geode/source_intel/EventTriggerInstance.cpp>
#endif
