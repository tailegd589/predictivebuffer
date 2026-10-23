#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/SetTargetIDLayer.hpp>
#else
#include <Geode/binding_intel/SetTargetIDLayer.hpp>
#endif
