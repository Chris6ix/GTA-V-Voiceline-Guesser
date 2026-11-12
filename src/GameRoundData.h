// Information about the currently played round
#pragma once
// Standard libraries and internal headers
#include <string> // Required for std::string
#include <SDL3/SDL.h> // Required for Uint64

struct GameRoundData {
    // Basic round info
    int current_round;
    std::string current_character;
    std::string current_character_for_display;
    std::string current_mission;
    std::string current_mission_for_display;
    std::string current_voiceline;
    int current_score;
    float average_score;

    // Round timer
    Uint64 round_start_time = 0;
    int current_timer;
    bool timer_ran_out;

    // Answer confirmation and feedback
    bool answer_confirmed;
    bool character_correct;
    bool mission_correct;

    // Entered by the player
    std::string entered_character;
    std::string entered_mission;
};

extern GameRoundData current_round_data;