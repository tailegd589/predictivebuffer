#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/mapping/CCNode.hpp>

class GameEffectsManager : public cocos2d::CCNode {
public:
    static constexpr auto CLASS_NAME = "GameEffectsManager";
    GEODE_CUSTOM_CONSTRUCTOR_CUTOFF(GameEffectsManager, cocos2d::CCNode)

    /**
     * @note[short] MacOS (ARM): 0x1aecdc
     * @note[short] MacOS (Intel): 0x201f00
     * @note[short] Android
     */
    static GameEffectsManager* create(PlayLayer* playLayer);

    /**
     * @note[short] MacOS (ARM): 0x1aeeec
     * @note[short] MacOS (Intel): 0x2020b0
     * @note[short] Android
     */
    void addParticleEffect(cocos2d::CCParticleSystemQuad* particle, int unused);

    /**
     * @note[short] MacOS (ARM): 0x1aed38
     * @note[short] MacOS (Intel): 0x201f60
     * @note[short] Android
     */
    bool init(PlayLayer* playLayer);

    /**
     * @note[short] MacOS (ARM): 0x1aed44
     * @note[short] MacOS (Intel): 0x201f70
     * @note[short] Android
     */
    void scaleParticle(cocos2d::CCParticleSystemQuad* particle, float scale);
    PlayLayer* m_playLayer;
};
