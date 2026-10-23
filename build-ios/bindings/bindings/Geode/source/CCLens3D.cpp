#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCLens3D.cpp>
#else
#include <Geode/source_intel/CCLens3D.cpp>
#endif
