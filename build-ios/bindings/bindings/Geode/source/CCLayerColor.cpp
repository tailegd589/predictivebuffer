#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCLayerColor.cpp>
#else
#include <Geode/source_intel/CCLayerColor.cpp>
#endif
