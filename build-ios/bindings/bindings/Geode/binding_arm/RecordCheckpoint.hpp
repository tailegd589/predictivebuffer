#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>


class RecordCheckpoint {
public:
    static constexpr auto CLASS_NAME = "RecordCheckpoint";
    int m_index;
    int m_step;
    uint64_t m_seed;
    int m_attempts;
    int m_ticks;
    uint64_t m_time;
    int m_clicks;
    int m_points;
    gd::string m_inputs;
};
