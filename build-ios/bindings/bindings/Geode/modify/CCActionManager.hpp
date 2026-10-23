#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCActionManager.hpp>
#else
#include <Geode/modify_intel/CCActionManager.hpp>
#endif
