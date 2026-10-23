#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/SimplePlayer.hpp>
#else
#include <Geode/modify_intel/SimplePlayer.hpp>
#endif
