#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/binding/SetupAreaMoveTriggerPopup.hpp>

class SetupAreaFadeTriggerPopup : public SetupAreaMoveTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupAreaFadeTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupAreaFadeTriggerPopup, SetupAreaMoveTriggerPopup)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     SetupAreaFadeTriggerPopup();

    /**
     * @note[short] MacOS (ARM): 0x434524
     * @note[short] MacOS (Intel): 0x4d7050
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x372a8
     * @note[short] Android
     */
    static SetupAreaFadeTriggerPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects);

    /**
     * @note[short] MacOS (ARM): 0x4346b0
     * @note[short] MacOS (Intel): 0x4d7290
     * @note[short] Windows: 0x40f0f0
     * @note[short] iOS: 0x37388
     * @note[short] Android
     */
    bool init(EnterEffectObject* object, cocos2d::CCArray* objects);
};
