#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCFlipX3D.hpp>
#else
#include <Geode/modify_intel/CCFlipX3D.hpp>
#endif
