#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCFlipX3D.cpp>
#else
#include <Geode/source_intel/CCFlipX3D.cpp>
#endif
