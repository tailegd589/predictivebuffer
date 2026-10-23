#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>


class PlayerButtonCommand {
public:
    static constexpr auto CLASS_NAME = "PlayerButtonCommand";
    PlayerButton m_button;
    bool m_isPush;
    bool m_isPlayer2;
    int m_step;
    double m_timestamp;
};
