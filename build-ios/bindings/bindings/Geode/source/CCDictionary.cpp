#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCDictionary.cpp>
#else
#include <Geode/source_intel/CCDictionary.cpp>
#endif
