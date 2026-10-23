#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/source_arm/GJPromoPopup.cpp>
#else
#include <Geode/source_intel/GJPromoPopup.cpp>
#endif
