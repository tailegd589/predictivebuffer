#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/InfoLayer.hpp>
#else
#include <Geode/binding_intel/InfoLayer.hpp>
#endif
