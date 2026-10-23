#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/LocalLevelManager.hpp>
#else
#include <Geode/modify_intel/LocalLevelManager.hpp>
#endif
