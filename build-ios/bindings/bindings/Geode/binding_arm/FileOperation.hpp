#pragma once
#include <Geode/platform/platform.hpp>
#include <Geode/GeneratedPredeclare.hpp>
#include <Geode/Enums.hpp>


class FileOperation {
public:
    static constexpr auto CLASS_NAME = "FileOperation";

    /**
     * @note[short] MacOS (ARM): 0x549120
     * @note[short] MacOS (Intel): 0x625ab0
     * @note[short] Android
     */
    static gd::string getFilePath();

    /**
     * @note[short] MacOS (ARM): 0x54912c
     * @note[short] MacOS (Intel): 0x625ac0
     * @note[short] Android
     */
    static void readFile();

    /**
     * @note[short] MacOS (ARM): 0x54908c
     * @note[short] MacOS (Intel): 0x625a40
     * @note[short] Android
     */
    static void saveFile();
};
