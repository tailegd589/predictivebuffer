#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/GJEffectManager.hpp>
#else
#include <Geode/modify_intel/GJEffectManager.hpp>
#endif
