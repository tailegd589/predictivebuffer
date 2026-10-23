#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <Geode/mapping/vector.hpp>

class ToggleTriggerAction {
public:
    static constexpr auto CLASS_NAME = "ToggleTriggerAction";

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     ToggleTriggerAction();

    /**
     * @note[short] MacOS (ARM): Out of line
     * @note[short] MacOS (Intel): Out of line
     * @note[short] Windows: Out of line
     * @note[short] iOS: Out of line
     * @note[short] Android: Out of line
     */
     ToggleTriggerAction(int targetID, bool activateGroup, gd::vector<int> const& remapKeys, int uniqueID, int controlID);
    bool m_disabled;
    int m_targetGroupID;
    bool m_activateGroup;
    int m_triggerUniqueID;
    int m_controlID;
    gd::vector<int> m_remapKeys;
};
