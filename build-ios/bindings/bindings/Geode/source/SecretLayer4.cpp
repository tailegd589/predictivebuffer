#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/SecretLayer4.cpp>
#else
#include <Geode/source_intel/SecretLayer4.cpp>
#endif
