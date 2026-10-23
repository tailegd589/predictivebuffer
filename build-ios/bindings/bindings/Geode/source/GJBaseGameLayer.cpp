#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GJBaseGameLayer.cpp>
#else
#include <Geode/source_intel/GJBaseGameLayer.cpp>
#endif
