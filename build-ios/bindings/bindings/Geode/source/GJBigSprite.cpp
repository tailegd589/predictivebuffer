#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GJBigSprite.cpp>
#else
#include <Geode/source_intel/GJBigSprite.cpp>
#endif
