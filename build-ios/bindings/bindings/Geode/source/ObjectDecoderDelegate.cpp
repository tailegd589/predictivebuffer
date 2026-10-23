#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/ObjectDecoderDelegate.cpp>
#else
#include <Geode/source_intel/ObjectDecoderDelegate.cpp>
#endif
