#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/binding/SFXStateContainer.hpp>

class SFXTriggerState {
public:
    static constexpr auto CLASS_NAME = "SFXTriggerState";
    SFXTriggerGameObject* m_sfxTriggerGameObject;
    int m_unkInt1;
    double m_unkDouble1;
    double m_unkDouble2;
    double m_unkDouble3;
    double m_unkDouble4;
    float m_unkFloat1;
    float m_unkFloat2;
    float m_unkFloat3;
    float m_unkFloat4;
    int m_unkInt2;
    bool m_processed;
    bool m_unkBool1;
    std::array<SFXStateContainer, 3> m_sfxStateContainers;
};
