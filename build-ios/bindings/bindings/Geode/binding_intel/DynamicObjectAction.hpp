#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>


class DynamicObjectAction {
public:
    static constexpr auto CLASS_NAME = "DynamicObjectAction";

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     DynamicObjectAction();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     DynamicObjectAction(EffectGameObject* object, GameObject* targetObject, GameObject* centerObject);
    union {
        EffectGameObject* m_trigger{};
        EffectGameObject* m_gameObject1;
    };
    union {
        GameObject* m_centerObject{};
        GameObject* m_gameObject2;
    };
    union {
        GameObject* m_aimTargetObject{};
        GameObject* m_gameObject3;
    };
    union {
        GameObject* m_targetObject{};
        GameObject* m_gameObject4;
    };
    union {
        GameObject* m_minXObject{};
        GameObject* m_gameObject5;
    };
    union {
        GameObject* m_minYObject{};
        GameObject* m_gameObject6;
    };
    union {
        GameObject* m_maxXObject{};
        GameObject* m_gameObject7;
    };
    union {
        GameObject* m_maxYObject{};
        GameObject* m_gameObject8;
    };
    union {
        float m_elapsed{};
        float m_unkFloat1;
    };
    float m_unkFloat2;
    float m_unkFloat3;
    bool m_unkBool1;
    bool m_unkBool2;
    bool m_unkBool3;
    bool m_unkBool4;
    int m_controlID;
    int m_targetGroupID;
    int m_centerGroupID;
};
