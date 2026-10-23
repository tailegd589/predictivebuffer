#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/binding/SetupTriggerPopup.hpp>

class SetupEnterTriggerPopup : public SetupTriggerPopup {
public:
    static constexpr auto CLASS_NAME = "SetupEnterTriggerPopup";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SetupEnterTriggerPopup, SetupTriggerPopup)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     SetupEnterTriggerPopup();

    /**
     * @note[short] MacOS (ARM): 0x23ab0c
     * @note[short] MacOS (Intel): 0x29ad90
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x2d27dc
     * @note[short] Android
     */
    static SetupEnterTriggerPopup* create(EnterEffectObject* object, cocos2d::CCArray* objects);

    /**
     * @note[short] MacOS (ARM): 0x23b278
     * @note[short] MacOS (Intel): 0x29b610
     * @note[short] Windows: 0x28f7e0
     * @note[short] iOS: 0x2d2dd0
     * @note[short] Android
     */
    virtual void determineStartValues();

    /**
     * @note[short] MacOS (ARM): 0x23ac9c
     * @note[short] MacOS (Intel): 0x29afd0
     * @note[short] Windows: 0x28f260
     * @note[short] iOS: 0x2d28c0
     * @note[short] Android
     */
    bool init(EnterEffectObject* object, cocos2d::CCArray* objects);

    /**
     * @note[short] MacOS (ARM): 0x23b1a4
     * @note[short] MacOS (Intel): 0x29b540
     * @note[short] Windows: 0x28f8b0
     * @note[short] iOS: 0x2d2d04
     * @note[short] Android
     */
    void onEnterType(cocos2d::CCObject* sender);
    CCMenuItemToggler* m_enterOnlyToggler;
    CCMenuItemToggler* m_exitOnlyToggler;
    int m_enterType;
};
