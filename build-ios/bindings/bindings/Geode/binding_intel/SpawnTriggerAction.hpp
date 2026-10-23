#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/mapping/vector.hpp>

class SpawnTriggerAction {
public:
    static constexpr auto CLASS_NAME = "SpawnTriggerAction";

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     SpawnTriggerAction();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     SpawnTriggerAction(GameObject* object, float delay, gd::vector<int> const& remapKeys, int uniqueID, int controlID);

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     SpawnTriggerAction(int targetID, float delay, bool spawnOrdered, gd::vector<int> const& remapKeys, int uniqueID, int controlID);

    /**
     * @note[short] MacOS (ARM): 0x273b10
     * @note[short] MacOS (Intel): 0x2d94f0
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android
     */
    bool isFinished();

    /**
     * @note[short] MacOS (ARM): 0x273ae0
     * @note[short] MacOS (Intel): 0x2d94c0
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android
     */
    void step(float dt);
    bool m_finished;
    bool m_disabled;
    double m_duration;
    double m_deltaTime;
    int m_targetGroupID;
    int m_triggerUniqueID;
    int m_controlID;
    bool m_spawnOrdered;
    GameObject* m_gameObject;
    gd::vector<int> m_remapKeys;
};
