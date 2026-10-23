#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/MapSelectLayer.cpp>
#else
#include <Geode/source_intel/MapSelectLayer.cpp>
#endif
