#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCShaky3D.hpp>
#else
#include <Geode/modify_intel/CCShaky3D.hpp>
#endif
