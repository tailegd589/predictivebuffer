#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>


class SFXTriggerInstance {
public:
    static constexpr auto CLASS_NAME = "SFXTriggerInstance";
    int m_groupID1;
    int m_groupID2;
    int m_controlID;
    SFXTriggerGameObject* m_sfxTriggerGameObject;
};
