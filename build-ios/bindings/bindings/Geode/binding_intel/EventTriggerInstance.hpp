#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/mapping/vector.hpp>

class EventTriggerInstance {
public:
    static constexpr auto CLASS_NAME = "EventTriggerInstance";
    int m_targetID;
    int m_uniqueID;
    int m_controlID;
    bool m_inactive;
    gd::vector<int> m_remapKeys;
};
