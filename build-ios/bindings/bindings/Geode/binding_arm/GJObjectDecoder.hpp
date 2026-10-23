#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/mapping/CCNode.hpp>
#include <Geode/mapping/ObjectDecoderDelegate.hpp>

class GJObjectDecoder : public cocos2d::CCNode, public ObjectDecoderDelegate {
public:
    static constexpr auto CLASS_NAME = "GJObjectDecoder";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJObjectDecoder, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): 0x636fd0
     * @note[short] MacOS (Intel): 0x724810
     * @note[short] Windows: 0x283fc0
     * @note[short] iOS: 0x216a84
     * @note[short] Android
     */
    static GJObjectDecoder* sharedDecoder();

    /**
     * @note[short] MacOS (ARM): 0x637078
     * @note[short] MacOS (Intel): 0x724890
     * @note[short] Windows: 0x77de0
     * @note[short] iOS: 0x216b20
     * @note[short] Android
     */
    virtual bool init();

    /**
     * @note[short] MacOS (ARM): 0x63707c
     * @note[short] MacOS (Intel): 0x7248a0
     * @note[short] Windows: 0x284060
     * @note[short] iOS: 0x216b24
     * @note[short] Android
     */
    virtual cocos2d::CCObject* getDecodedObject(int type, DS_Dictionary* dict);
};
