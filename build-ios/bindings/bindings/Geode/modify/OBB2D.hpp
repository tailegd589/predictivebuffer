#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/OBB2D.hpp>
#else
#include <Geode/modify_intel/OBB2D.hpp>
#endif
