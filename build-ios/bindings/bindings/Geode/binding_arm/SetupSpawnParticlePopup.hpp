#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/binding/SetupTriggerPopup.hpp>

class SetupSpawnParticlePopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupSpawnParticlePopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupSpawnParticlePopup, SetupTriggerPopup)

    /**
     * @note[short] MacOS (ARM): 0x4c8184
     * @note[short] MacOS (Intel): 0x57b1d0
     * @note[short] Windows: 0x468340
     * @note[short] iOS: 0x409950
     * @note[short] Android
     */
    static SetupSpawnParticlePopup* create(EffectGameObject* object, cocos2d::CCArray* objects);

    /**
     * @note[short] MacOS (ARM): 0x4c8310
     * @note[short] MacOS (Intel): 0x57b400
     * @note[short] Windows: 0x468450
     * @note[short] iOS: 0x409a2c
     * @note[short] Android
     */
    bool init(EffectGameObject* object, cocos2d::CCArray* objects);
};
