#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/binding/RingObject.hpp>
#include <Geode/mapping/vector.hpp>

class DashRingObject : public RingObject {
public:
    static constexpr auto CLASS_NAME = "DashRingObject";
    GEODE_CUSTOM_CONSTRUCTOR_GD(DashRingObject, RingObject)

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     DashRingObject();

    /**
     * @note[short] MacOS (ARM): 0x16f028
     * @note[short] MacOS (Intel): 0x1b50c0
     * @note[short] Windows: Out of line
     * @note[short] iOS: 0x382b64
     * @note[short] Android
     */
    static DashRingObject* create(char const* frame);

    /**
     * @note[short] MacOS (ARM): 0x16f154
     * @note[short] MacOS (Intel): 0x1b5210
     * @note[short] Windows: 0x4a2490
     * @note[short] iOS: 0x382c34
     * @note[short] Android: Rebinded
     */
    virtual void customObjectSetup(gd::vector<gd::string>& values, gd::vector<void*>& exists);

    /**
     * @note[short] MacOS (ARM): 0x16f2ac
     * @note[short] MacOS (Intel): 0x1b5380
     * @note[short] Windows: 0x4a26d0
     * @note[short] iOS: 0x382d78
     * @note[short] Android
     */
    virtual gd::string getSaveString(GJBaseGameLayer* layer);

    /**
     * @note[short] MacOS (ARM): 0x16f104
     * @note[short] MacOS (Intel): 0x1b51b0
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android
     */
    bool init(char const* frame);
    float m_dashSpeed;
    float m_endBoost;
    float m_maxDuration;
    bool m_allowCollide;
    bool m_stopSlide;
};
