#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/EndPortalObject.cpp>
#else
#include <Geode/source_intel/EndPortalObject.cpp>
#endif
