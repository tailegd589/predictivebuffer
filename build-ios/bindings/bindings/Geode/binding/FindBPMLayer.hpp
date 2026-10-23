#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/FindBPMLayer.hpp>
#else
#include <Geode/binding_intel/FindBPMLayer.hpp>
#endif
