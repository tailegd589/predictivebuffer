#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCTMXMapInfo.hpp>
#else
#include <Geode/modify_intel/CCTMXMapInfo.hpp>
#endif
