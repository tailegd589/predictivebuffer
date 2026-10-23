#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/OBB2D.hpp>
#else
#include <Geode/binding_intel/OBB2D.hpp>
#endif
