#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/xml_node.cpp>
#else
#include <Geode/source_intel/xml_node.cpp>
#endif
