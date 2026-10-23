#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/xml_document.hpp>
#else
#include <Geode/modify_intel/xml_document.hpp>
#endif
