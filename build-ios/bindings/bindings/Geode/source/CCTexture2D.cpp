#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCTexture2D.cpp>
#else
#include <Geode/source_intel/CCTexture2D.cpp>
#endif
