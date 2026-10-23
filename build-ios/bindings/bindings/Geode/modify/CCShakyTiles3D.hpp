#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCShakyTiles3D.hpp>
#else
#include <Geode/modify_intel/CCShakyTiles3D.hpp>
#endif
