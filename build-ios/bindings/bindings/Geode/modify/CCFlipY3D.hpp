#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCFlipY3D.hpp>
#else
#include <Geode/modify_intel/CCFlipY3D.hpp>
#endif
