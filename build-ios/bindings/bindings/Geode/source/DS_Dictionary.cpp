#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/DS_Dictionary.cpp>
#else
#include <Geode/source_intel/DS_Dictionary.cpp>
#endif
