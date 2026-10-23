#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>


class DelayedSpawnNode {
public:
    static constexpr auto CLASS_NAME = "DelayedSpawnNode";
    EffectGameObject* m_gameObject;
    float m_spawnDelay;
};
