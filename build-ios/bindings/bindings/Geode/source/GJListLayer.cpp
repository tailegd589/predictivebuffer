#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GJListLayer.cpp>
#else
#include <Geode/source_intel/GJListLayer.cpp>
#endif
