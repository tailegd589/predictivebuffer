#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCEaseBackOut.cpp>
#else
#include <Geode/source_intel/CCEaseBackOut.cpp>
#endif
