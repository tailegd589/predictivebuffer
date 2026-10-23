#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCKeypadDispatcher.hpp>
#else
#include <Geode/modify_intel/CCKeypadDispatcher.hpp>
#endif
