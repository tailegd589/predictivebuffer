#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/mapping/vector.hpp>

class TimerItem {
public:
    static constexpr auto CLASS_NAME = "TimerItem";
    int m_itemID;
    double m_time;
    bool m_active;
    float m_timeMod;
    bool m_ignoreTimeWarp;
    double m_targetTime;
    bool m_stopTimeEnabled;
    int m_targetGroupID;
    int m_triggerUniqueID;
    int m_controlID;
    gd::vector<int> m_remapKeys;
    bool m_disabled;
};
