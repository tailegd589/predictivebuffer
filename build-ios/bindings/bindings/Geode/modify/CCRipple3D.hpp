#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCRipple3D.hpp>
#else
#include <Geode/modify_intel/CCRipple3D.hpp>
#endif
