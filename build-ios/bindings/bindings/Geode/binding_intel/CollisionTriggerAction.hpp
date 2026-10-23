#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/mapping/vector.hpp>

class CollisionTriggerAction {
public:
    static constexpr auto CLASS_NAME = "CollisionTriggerAction";
    bool m_disabled;
    int m_blockAID;
    int m_blockBID;
    int m_targetGroupID;
    int m_triggerOnExit;
    bool m_activateGroup;
    int m_triggerUniqueID;
    int m_controlID;
    gd::vector<int> m_remapKeys;
};
