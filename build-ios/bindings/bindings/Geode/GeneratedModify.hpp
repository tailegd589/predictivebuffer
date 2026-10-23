#pragma once
#include <Geode/platform/platform.hpp>

#ifdef GEODE_IS_ARM_MAC
#include "GeneratedModifyArm.hpp"
#else
#include "GeneratedModifyIntel.hpp"
#endif
