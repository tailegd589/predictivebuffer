#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCShaky3D.cpp>
#else
#include <Geode/source_intel/CCShaky3D.cpp>
#endif
