#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/SecretLayer4.hpp>
#else
#include <Geode/binding_intel/SecretLayer4.hpp>
#endif
