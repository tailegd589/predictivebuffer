#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCThread.hpp>
#else
#include <Geode/modify_intel/CCThread.hpp>
#endif
