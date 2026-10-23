#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/binding_arm/StarInfoPopup.hpp>
#else
#include <Geode/binding_intel/StarInfoPopup.hpp>
#endif
