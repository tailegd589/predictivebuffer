#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GJMapObject.cpp>
#else
#include <Geode/source_intel/GJMapObject.cpp>
#endif
