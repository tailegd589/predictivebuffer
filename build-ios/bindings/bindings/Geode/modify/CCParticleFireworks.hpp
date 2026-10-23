#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCParticleFireworks.hpp>
#else
#include <Geode/modify_intel/CCParticleFireworks.hpp>
#endif
