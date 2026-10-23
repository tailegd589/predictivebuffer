#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/MusicDelegateHandler.hpp>
#else
#include <Geode/modify_intel/MusicDelegateHandler.hpp>
#endif
