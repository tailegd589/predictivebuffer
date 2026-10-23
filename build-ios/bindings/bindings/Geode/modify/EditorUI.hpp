#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/EditorUI.hpp>
#else
#include <Geode/modify_intel/EditorUI.hpp>
#endif
