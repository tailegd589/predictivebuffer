#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GraphicsReloadLayer.cpp>
#else
#include <Geode/source_intel/GraphicsReloadLayer.cpp>
#endif
