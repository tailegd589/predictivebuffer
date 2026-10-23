#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCShakyTiles3D.cpp>
#else
#include <Geode/source_intel/CCShakyTiles3D.cpp>
#endif
