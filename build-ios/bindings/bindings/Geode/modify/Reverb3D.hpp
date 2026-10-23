#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/Reverb3D.hpp>
#else
#include <Geode/modify_intel/Reverb3D.hpp>
#endif
