#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/MusicSearchResult.hpp>
#else
#include <Geode/modify_intel/MusicSearchResult.hpp>
#endif
