#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/mapping/CCNode.hpp>

class GJHttpResult : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GJHttpResult";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GJHttpResult, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     GJHttpResult();

    /**
     * @note[short] MacOS (ARM): 0x473b8c
     * @note[short] MacOS (Intel): 0x51e0c0
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Rebinded
     */
    static GJHttpResult* create(bool success, gd::string response, gd::string tag, GJHttpType type);

    /**
     * @note[short] MacOS (ARM): 0x4b0bcc
     * @note[short] MacOS (Intel): 0x561b10
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Rebinded
     */
    bool init(bool success, gd::string response, gd::string tag, GJHttpType type);
    bool m_success;
    gd::string m_response;
    gd::string m_requestTag;
    GJHttpType m_httpType;
};
