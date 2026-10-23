#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCAtlasNode.hpp>
#else
#include <Geode/modify_intel/CCAtlasNode.hpp>
#endif
