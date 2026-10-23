#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/GroupCommandObject2.hpp>
#else
#include <Geode/modify_intel/GroupCommandObject2.hpp>
#endif
