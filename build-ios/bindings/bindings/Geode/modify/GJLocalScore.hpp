#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/GJLocalScore.hpp>
#else
#include <Geode/modify_intel/GJLocalScore.hpp>
#endif
