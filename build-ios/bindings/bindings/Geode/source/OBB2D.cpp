#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/OBB2D.cpp>
#else
#include <Geode/source_intel/OBB2D.cpp>
#endif
