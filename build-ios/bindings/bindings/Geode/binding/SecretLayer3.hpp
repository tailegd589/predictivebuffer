#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/SecretLayer3.hpp>
#else
#include <Geode/binding_intel/SecretLayer3.hpp>
#endif
