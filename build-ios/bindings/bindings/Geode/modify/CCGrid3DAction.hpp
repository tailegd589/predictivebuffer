#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCGrid3DAction.hpp>
#else
#include <Geode/modify_intel/CCGrid3DAction.hpp>
#endif
