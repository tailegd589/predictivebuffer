#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/SelectArtDelegate.hpp>
#else
#include <Geode/modify_intel/SelectArtDelegate.hpp>
#endif
