#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GJSmartTemplate.cpp>
#else
#include <Geode/source_intel/GJSmartTemplate.cpp>
#endif
