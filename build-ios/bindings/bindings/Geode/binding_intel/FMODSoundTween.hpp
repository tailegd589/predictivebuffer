#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <fmod.hpp>

class FMODSoundTween {
public:
    static constexpr auto CLASS_NAME = "FMODSoundTween";
    float m_interval;
    float m_duration;
    float m_start;
    float m_end;
    float m_value;
    bool m_finished;
};
