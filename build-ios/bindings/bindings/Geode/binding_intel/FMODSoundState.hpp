#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>

#include <fmod.hpp>
#include <Geode/binding/SoundStateContainer.hpp>

class FMODSoundState {
public:
    static constexpr auto CLASS_NAME = "FMODSoundState";
    gd::string m_filePath;
    float m_speed;
    float m_unkFloat1;
    float m_volume;
    bool m_shouldLoop;
    int m_channelID;
    SoundStateContainer m_soundStateContainer;
    int m_uniqueID;
    int m_sfxGroup;
    float m_pitch;
    bool m_fastFourierTransform;
    bool m_reverb;
    int m_effectID;
    bool m_isMusic;
    int m_musicID;
    bool m_unkBool2;
};
