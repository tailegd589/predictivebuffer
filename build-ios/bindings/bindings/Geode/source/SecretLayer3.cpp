#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SecretLayer3.cpp>
#else
#include <Geode/source_intel/SecretLayer3.cpp>
#endif
