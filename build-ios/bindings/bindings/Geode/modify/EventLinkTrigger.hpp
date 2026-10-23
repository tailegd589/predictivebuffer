#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/EventLinkTrigger.hpp>
#else
#include <Geode/modify_intel/EventLinkTrigger.hpp>
#endif
