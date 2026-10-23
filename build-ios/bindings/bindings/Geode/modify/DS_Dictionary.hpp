#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/DS_Dictionary.hpp>
#else
#include <Geode/modify_intel/DS_Dictionary.hpp>
#endif
