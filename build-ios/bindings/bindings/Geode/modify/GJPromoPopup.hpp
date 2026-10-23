#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/GJPromoPopup.hpp>
#else
#include <Geode/modify_intel/GJPromoPopup.hpp>
#endif
