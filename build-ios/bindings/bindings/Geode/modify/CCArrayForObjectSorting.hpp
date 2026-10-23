#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCArrayForObjectSorting.hpp>
#else
#include <Geode/modify_intel/CCArrayForObjectSorting.hpp>
#endif
