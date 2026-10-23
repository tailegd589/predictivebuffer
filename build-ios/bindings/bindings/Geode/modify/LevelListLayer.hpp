#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/LevelListLayer.hpp>
#else
#include <Geode/modify_intel/LevelListLayer.hpp>
#endif
