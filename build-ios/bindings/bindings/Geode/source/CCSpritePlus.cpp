#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCSpritePlus.cpp>
#else
#include <Geode/source_intel/CCSpritePlus.cpp>
#endif
