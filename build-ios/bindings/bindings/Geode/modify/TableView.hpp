#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include <Geode/modify_arm/TableView.hpp>
#else
#include <Geode/modify_intel/TableView.hpp>
#endif
