#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/cocos2d.cpp>
#else
#include <Geode/source_intel/cocos2d.cpp>
#endif
