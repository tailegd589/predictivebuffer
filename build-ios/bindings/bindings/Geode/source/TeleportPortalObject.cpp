#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/TeleportPortalObject.cpp>
#else
#include <Geode/source_intel/TeleportPortalObject.cpp>
#endif
