#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/CCPageTurn3D.cpp>
#else
#include <Geode/source_intel/CCPageTurn3D.cpp>
#endif
