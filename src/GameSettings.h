// Holds the game's settings
#pragma once
// Standard libraries and internal headers
#include <string> // Required for std::string

// Settings for gameplay
struct GameSettings {
    std::string difficulty = "Normal";
    int total_rounds = 20;
    bool content_creator_mode = false;
};

// Settings for the entire program
struct GlobalSettings {
    bool sound_enabled = true;
};

extern GameSettings game_settings;
extern GlobalSettings global_settings;