#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCGridAction.hpp>
#else
#include <Geode/modify_intel/CCGridAction.hpp>
#endif
