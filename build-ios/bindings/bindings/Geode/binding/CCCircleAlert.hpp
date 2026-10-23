#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/CCCircleAlert.hpp>
#else
#include <Geode/binding_intel/CCCircleAlert.hpp>
#endif
