// Holds game states, allows: 
// The GUI to transition between screens with UI buttons
// The GUI to stop the gameplay loop via gameplay_started
// The game to "lock" a round until the player has answered, preventing a new round from being started via round_ongoing
// The game to hold the current screen for some time to display answer feedback
// SDLEventRunner() in GUIBackend.cpp to modify gui states using keybinds
#pragma once

struct GameState {
  // Logic states
  bool game_running = false;
  bool debug_enabled = false;
  bool gameplay_ongoing = false;
  bool round_ongoing = false;
  bool settings_confirmed = false;
  bool in_answer_feedback = false;
  bool answer_feedback_finished = false;
  // GUI states
  bool gui_open = true;
  bool in_main_screen = true;
  bool in_credits_screen = false;
  bool in_help_screen = false;
  bool in_settings_screen = false;
  bool in_gameplay_screen = false;
  bool in_results_screen = false;
};

extern GameState game_state;
