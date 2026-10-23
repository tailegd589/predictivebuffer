#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCDeccelAmplitude.hpp>
#else
#include <Geode/modify_intel/CCDeccelAmplitude.hpp>
#endif
