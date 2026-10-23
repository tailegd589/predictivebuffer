#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>


class DynamicMoveCalculation {
public:
    static constexpr auto CLASS_NAME = "DynamicMoveCalculation";
    CCMoveCNode* m_moveNode;
    cocos2d::CCPoint m_offset;
    GameObject* m_gameObject;
};
