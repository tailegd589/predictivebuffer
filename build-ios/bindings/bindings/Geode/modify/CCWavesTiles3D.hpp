#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCWavesTiles3D.hpp>
#else
#include <Geode/modify_intel/CCWavesTiles3D.hpp>
#endif
