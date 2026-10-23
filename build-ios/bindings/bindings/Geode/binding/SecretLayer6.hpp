#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/SecretLayer6.hpp>
#else
#include <Geode/binding_intel/SecretLayer6.hpp>
#endif
