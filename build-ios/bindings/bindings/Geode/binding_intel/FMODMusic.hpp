#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <fmod.hpp>

class FMODMusic {
public:
    static constexpr auto CLASS_NAME = "FMODMusic";
    int m_channelID;
    FMOD::Sound* m_sound;
    gd::string m_filePath;
    bool m_ogg;
    bool m_dontReset;
};
