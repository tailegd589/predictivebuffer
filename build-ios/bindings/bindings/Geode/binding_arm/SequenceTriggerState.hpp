#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/mapping/unordered_map.hpp>

class SequenceTriggerState {
public:
    static constexpr auto CLASS_NAME = "SequenceTriggerState";
    gd::unordered_map<int, float> m_sequenceTimes;
    gd::unordered_map<int, int> m_sequenceIndices;
};
