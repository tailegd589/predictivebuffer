#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCControlHuePicker.hpp>
#else
#include <Geode/modify_intel/CCControlHuePicker.hpp>
#endif
