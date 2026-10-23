#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/BoomListView.cpp>
#else
#include <Geode/source_intel/BoomListView.cpp>
#endif
