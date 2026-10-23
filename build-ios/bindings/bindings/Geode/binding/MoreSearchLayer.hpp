#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/MoreSearchLayer.hpp>
#else
#include <Geode/binding_intel/MoreSearchLayer.hpp>
#endif
