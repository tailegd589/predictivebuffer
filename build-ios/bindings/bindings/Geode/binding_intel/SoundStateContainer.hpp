#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>


class SoundStateContainer {
public:
    static constexpr auto CLASS_NAME = "SoundStateContainer";
    int m_fadePointCount;
    std::array<float, 4> m_fadePointVolumes;
    std::array<uint64_t, 4> m_fadePointOffsets;
    uint64_t m_currentOffset;
    int m_loopStartMs;
    int m_loopEndMs;
    int m_currentMs;
    uint64_t m_playStartOffset;
    uint64_t m_playEndOffset;
    int m_usePlayOffsets;
};
