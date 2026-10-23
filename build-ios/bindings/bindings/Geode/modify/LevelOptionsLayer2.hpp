#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/LevelOptionsLayer2.hpp>
#else
#include <Geode/modify_intel/LevelOptionsLayer2.hpp>
#endif
