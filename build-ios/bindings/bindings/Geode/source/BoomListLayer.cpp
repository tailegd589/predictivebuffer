#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/BoomListLayer.cpp>
#else
#include <Geode/source_intel/BoomListLayer.cpp>
#endif
