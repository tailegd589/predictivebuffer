#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/SecretGame01Layer.hpp>
#else
#include <Geode/binding_intel/SecretGame01Layer.hpp>
#endif
