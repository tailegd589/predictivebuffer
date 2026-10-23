#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/binding/GJGameState.hpp>
#include <Geode/binding/GJShaderState.hpp>
#include <Geode/binding/FMODAudioState.hpp>
#include <Geode/binding/EffectManagerState.hpp>
#include <Geode/binding/SavedObjectStateRef.hpp>
#include <Geode/binding/SavedActiveObjectState.hpp>
#include <Geode/binding/SavedSpecialObjectState.hpp>
#include <Geode/binding/SequenceTriggerState.hpp>
#include <Geode/mapping/CCNode.hpp>
#include <Geode/mapping/unordered_map.hpp>
#include <Geode/mapping/vector.hpp>

class CheckpointObject : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "CheckpointObject";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(CheckpointObject, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): 0xb2380
     * @note[short] MacOS (Intel): 0xca020
     * @note[short] Windows: 0x3a51c0
     * @note[short] iOS: 0x1277c4
     * @note[short] Android: Rebinded
     */
     CheckpointObject();

    /**
     * @note[short] MacOS (ARM): 0xac388
     * @note[short] MacOS (Intel): 0xbf920
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x122d10
     * @note[short] Android: Rebinded
     */
     ~CheckpointObject();

    /**
     * @note[short] MacOS (ARM): 0xa8c2c
     * @note[short] MacOS (Intel): 0xbb800
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x11fc94
     * @note[short] Android
     */
    static CheckpointObject* create();

    /**
     * @note[short] MacOS (ARM): 0xac4b4
     * @note[short] MacOS (Intel): 0xbfae0
     * @note[short] Windows: 0x77de0
     * @note[short] iOS: 0x122de8
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0xa842c
     * @note[short] MacOS (Intel): 0xbaeb0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x11f644
     * @note[short] Android
     */
    GameObject* getObject();

    /**
     * @note[short] MacOS (ARM): 0xa9890
     * @note[short] MacOS (Intel): 0xbc990
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x120870
     * @note[short] Android
     */
    void setObject(GameObject* object);
    GJGameState m_gameState;
    GJShaderState m_shaderState;
    FMODAudioState m_audioState;
    GameObject* m_physicalCheckpointObject;
    PlayerCheckpoint* m_player1Checkpoint;
    PlayerCheckpoint* m_player2Checkpoint;
    int m_unke78;
    int m_unke7c;
    float m_unke80;
    bool m_ground2Invisible;
    bool m_streakBlend;
    int m_uniqueID;
    int m_respawnID;
    gd::vector<SavedObjectStateRef> m_vectorSavedObjectStateRef;
    gd::vector<SavedActiveObjectState> m_vectorActiveSaveObjectState;
    gd::vector<SavedSpecialObjectState> m_vectorSpecialSaveObjectState;
    EffectManagerState m_effectManagerState;
    cocos2d::CCArray* m_gradientTriggerObjectArray;
    bool m_unk11e8;
    gd::unordered_map<int,SequenceTriggerState> m_sequenceTriggerStateUnorderedMap;
    int m_commandIndex;
};
