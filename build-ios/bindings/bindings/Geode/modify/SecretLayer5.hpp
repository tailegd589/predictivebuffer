#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/SecretLayer5.hpp>
#else
#include <Geode/modify_intel/SecretLayer5.hpp>
#endif
