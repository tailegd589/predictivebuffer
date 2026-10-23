#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCAction.hpp>
#else
#include <Geode/modify_intel/CCAction.hpp>
#endif
