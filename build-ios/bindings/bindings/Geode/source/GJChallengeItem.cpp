#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GJChallengeItem.cpp>
#else
#include <Geode/source_intel/GJChallengeItem.cpp>
#endif
