#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCToggleVisibility.cpp>
#else
#include <Geode/source_intel/CCToggleVisibility.cpp>
#endif
