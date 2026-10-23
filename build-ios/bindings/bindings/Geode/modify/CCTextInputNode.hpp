#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCTextInputNode.hpp>
#else
#include <Geode/modify_intel/CCTextInputNode.hpp>
#endif
