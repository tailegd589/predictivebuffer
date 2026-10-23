#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GJActionManager.cpp>
#else
#include <Geode/source_intel/GJActionManager.cpp>
#endif
