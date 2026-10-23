#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>


class EnterEffectAnimValue {
public:
    static constexpr auto CLASS_NAME = "EnterEffectAnimValue";
    int m_key;
    float m_value;
    float m_distance;
    float m_duration;
    float m_elapsed;
    EasingType m_easingType;
    float m_easingRate;
    int m_easingBuffer;
};
