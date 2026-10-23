#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CustomSongDelegate.cpp>
#else
#include <Geode/source_intel/CustomSongDelegate.cpp>
#endif
