#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <fmod.hpp>

class FMODSound {
public:
    static constexpr auto CLASS_NAME = "FMODSound";
    FMOD::Sound* m_sound;
    gd::string m_filePath;
    int m_length;
    int m_playCount;
    int m_playIndex;
    bool m_preloaded;
};
