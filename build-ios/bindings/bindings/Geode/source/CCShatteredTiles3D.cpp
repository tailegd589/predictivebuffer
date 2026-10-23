#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCShatteredTiles3D.cpp>
#else
#include <Geode/source_intel/CCShatteredTiles3D.cpp>
#endif
