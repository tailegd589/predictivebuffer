#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/binding/SFXInfoObject.hpp>

class SFXFolderObject : public SFXInfoObject {
public:
    static constexpr auto CLASS_NAME = "SFXFolderObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(SFXFolderObject, SFXInfoObject)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     SFXFolderObject();

    /**
     * @note[short] MacOS (ARM): 0x4e2724
     * @note[short] MacOS (Intel): 0x598e90
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x15c4f0
     * @note[short] Android: Rebinded
     */
     ~SFXFolderObject();

    /**
     * @note[short] MacOS (ARM): 0x4e04c8
     * @note[short] MacOS (Intel): 0x596560
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x15ab38
     * @note[short] Android: Rebinded
     */
    static SFXFolderObject* create(int id, gd::string name, int folderID);

    /**
     * @note[short] MacOS (ARM): 0x4e2864
     * @note[short] MacOS (Intel): 0x598f90
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x15c544
     * @note[short] Android: Rebinded
     */
    bool init(int id, gd::string name, int folderID);
    cocos2d::CCArray* m_sfxObjects;
};
