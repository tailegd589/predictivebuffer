#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/InheritanceNode.cpp>
#else
#include <Geode/source_intel/InheritanceNode.cpp>
#endif
