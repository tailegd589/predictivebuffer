#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/NCSInfoLayer.hpp>
#else
#include <Geode/modify_intel/NCSInfoLayer.hpp>
#endif
