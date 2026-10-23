#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCWaves3D.hpp>
#else
#include <Geode/modify_intel/CCWaves3D.hpp>
#endif
