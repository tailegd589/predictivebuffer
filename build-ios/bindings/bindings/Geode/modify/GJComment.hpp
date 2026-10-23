#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/GJComment.hpp>
#else
#include <Geode/modify_intel/GJComment.hpp>
#endif
