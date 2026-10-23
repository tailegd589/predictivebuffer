#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/EnhancedGameObject.hpp>
#else
#include <Geode/modify_intel/EnhancedGameObject.hpp>
#endif
