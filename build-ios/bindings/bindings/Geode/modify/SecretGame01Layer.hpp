#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/SecretGame01Layer.hpp>
#else
#include <Geode/modify_intel/SecretGame01Layer.hpp>
#endif
