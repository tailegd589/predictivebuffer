#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>


class RecordButtonCommand {
public:
    static constexpr auto CLASS_NAME = "RecordButtonCommand";
    PlayerButton m_button;
    bool m_isPush;
    bool m_isPlayer2;
    int m_step;
    int m_unk00c;
};
