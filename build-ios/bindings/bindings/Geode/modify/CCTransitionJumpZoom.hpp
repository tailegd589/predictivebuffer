#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCTransitionJumpZoom.hpp>
#else
#include <Geode/modify_intel/CCTransitionJumpZoom.hpp>
#endif
