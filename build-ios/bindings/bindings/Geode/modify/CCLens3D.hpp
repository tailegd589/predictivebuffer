#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCLens3D.hpp>
#else
#include <Geode/modify_intel/CCLens3D.hpp>
#endif
