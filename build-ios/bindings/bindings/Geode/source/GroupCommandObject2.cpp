#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GroupCommandObject2.cpp>
#else
#include <Geode/source_intel/GroupCommandObject2.cpp>
#endif
