#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCGrid3DAction.cpp>
#else
#include <Geode/source_intel/CCGrid3DAction.cpp>
#endif
