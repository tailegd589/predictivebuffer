#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SongSelectNode.cpp>
#else
#include <Geode/source_intel/SongSelectNode.cpp>
#endif
