#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/CCTiledGrid3DAction.hpp>
#else
#include <Geode/modify_intel/CCTiledGrid3DAction.hpp>
#endif
