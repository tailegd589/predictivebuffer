#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/PlayLayer.cpp>
#else
#include <Geode/source_intel/PlayLayer.cpp>
#endif
