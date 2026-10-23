#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/Reverb3D.cpp>
#else
#include <Geode/source_intel/Reverb3D.cpp>
#endif
