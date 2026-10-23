#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCControlHuePicker.cpp>
#else
#include <Geode/source_intel/CCControlHuePicker.cpp>
#endif
