#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCTextureAtlas.cpp>
#else
#include <Geode/source_intel/CCTextureAtlas.cpp>
#endif
