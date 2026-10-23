#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/MessagesProfilePage.cpp>
#else
#include <Geode/source_intel/MessagesProfilePage.cpp>
#endif
