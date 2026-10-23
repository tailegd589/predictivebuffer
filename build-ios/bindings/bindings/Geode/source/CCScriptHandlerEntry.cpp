#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCScriptHandlerEntry.cpp>
#else
#include <Geode/source_intel/CCScriptHandlerEntry.cpp>
#endif
