#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/ChallengeNode.hpp>
#else
#include <Geode/modify_intel/ChallengeNode.hpp>
#endif
