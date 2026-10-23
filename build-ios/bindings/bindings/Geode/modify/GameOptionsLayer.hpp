#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/GameOptionsLayer.hpp>
#else
#include <Geode/modify_intel/GameOptionsLayer.hpp>
#endif
