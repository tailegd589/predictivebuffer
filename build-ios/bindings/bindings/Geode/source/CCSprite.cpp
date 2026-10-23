#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCSprite.cpp>
#else
#include <Geode/source_intel/CCSprite.cpp>
#endif
