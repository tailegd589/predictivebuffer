#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/ColorAction2.hpp>
#else
#include <Geode/binding_intel/ColorAction2.hpp>
#endif
