// Standard libraries and internal headers
#include <iostream> // Used for debug prints
#include <random> // Used for randomly picking missions and voicelines
#include <array> // Used for mission arrays
#include <sstream> // Used for reading the bundled files
#include <vector> // Used for voiceline and difficulty vectors
#include <string> // Used for strings and getline()
#include <unordered_map> // Used for voiceline_database
#include <algorithm> // Used for find() and transform()
#include "GameInfo.h" // Used for name/version in startup log
#include "GameSettings.h" // Used throughout the file
#include "GameRoundData.h" // Used throughout the file
#include "GameState.h" // Used in main()
#include "BundledVoicelines.h" // Used in LoadAndSortLines()
#include "CurseWords.h" // Used in VoicelineSelector()
#include "AlternativeNames.h" // Used for easy mode matching
#include "GUIBackend.h" // Used for many gui backend calls in main()
#include "GUIHelpers.h" // Used for UpdateGUIPerfMetrics() and FromGameplayToResults()
#include "GUI.h" // Used for DrawGUI() and ApplyGameSettings()
#include "platform/Debug.h" // Used for Debug:: calls

// Variables used for measuring fps in debug mode, 
// must be placed here, above its instance (to keep instances grouped up)
struct PerfMetrics {
  double fps_timer = 0.0;
  int fps_frame_count = 0;
};

// Instances used throughout the game
GameSettings game_settings;
GlobalSettings global_settings;
GameRoundData current_round_data;
GameInfo game_info;
GameState game_state;
PerfMetrics perf_metrics;

// Caches for the voicelines, one per difficulty
struct VoicelineDifficulties {
  std::vector<std::string> easy;
  std::vector<std::string> normal;
  std::vector<std::string> hard;
  std::vector<std::string> extreme;
};

// The full voiceline database
static std::unordered_map<std::string, VoicelineDifficulties> voiceline_database;

// The implemented missions
// To keep a simple and consistent format, 
// capitalize every new word and replace every space and special character with an underscore.
// Dont forget to increase size of array
const static std::array<std::string, 15> implemented_main_missions = {
  "Prologue", "Franklin_And_Lamar", "Repossession", "Complications", "Father_Son", "Chop", "Marriage_Counseling", "Daddy_s_Little_Girl",
  "Friend_Request", "The_Long_Stretch", "Casing_The_Jewel_Store", "Carbine_Rifles", "Bugstars_Equipment", "BZ_Gas_Grenades", "The_Jewel_Store_Job"
};

const static std::array<std::string, 1> implemented_side_missions = {
  "Pulling_Favors"
};

// Random number generator (Better than rand())
std::random_device rd;
std::mt19937 gen(rd());
size_t RandomIndex(size_t size) {
    std::uniform_int_distribution<size_t> distribution(0, size - 1);
    return distribution(gen);
}

// Calculates the chance to select a main mission once, as the amount of implemented missions doesn't change in a game
const static float chance_of_main_mission = static_cast<float>(implemented_main_missions.size()) / (implemented_main_missions.size() + implemented_side_missions.size()) * 100;

// Stores the already used voicelines to avoid having duplicates in a run
static std::vector<std::string> used_voicelines;

// Preload all voicelines and sort them by difficulty once and cache them to avoid needing to load and destroy individual ones over and over again when they are used
void LoadAndSortLines() {
  std::cout << "LOADED VOICELINES DEBUG:" << std::endl
            << "-----------------------------------------------------------------------" << std::endl;

  int total_easy_loaded = 0;
  int total_normal_loaded = 0;
  int total_hard_loaded = 0;
  int total_extreme_loaded = 0;
  int total_loaded = 0;

  for (const std::pair<const std::string, std::string> &file : bundled_voicelines) {
    std::string mission_name = file.first;
    std::string voicelines = file.second;
    VoicelineDifficulties difficulties;
    std::istringstream stream(voicelines);
    std::string line;

    while (getline(stream, line)) {
      
      if (line.starts_with("[Easy]")) {
        difficulties.easy.push_back(line);
        total_easy_loaded++;
      }
      else if (line.starts_with("[Normal]")) {
        difficulties.normal.push_back(line);
        total_normal_loaded++;
      }
      else if (line.starts_with("[Hard]")) {
        difficulties.hard.push_back(line);
        total_hard_loaded++;
      }
      else if (line.starts_with("[Extreme]")) {
        difficulties.extreme.push_back(line);
        total_extreme_loaded++;
      }
    }

    std::cout << mission_name << " loaded: "
              << difficulties.easy.size() << " Easy, "
              << difficulties.normal.size() << " Normal, "
              << difficulties.hard.size() << " Hard, "
              << difficulties.extreme.size() << " Extreme"
              << std::endl;

    voiceline_database[mission_name] = difficulties;
  }

  std::cout << "-----------------------------------------------------------------------" << std::endl;
  total_loaded = total_easy_loaded + total_normal_loaded + total_hard_loaded + total_extreme_loaded;
  std::cout << "Total loaded: " << total_loaded 
            << " | Easy: " << total_easy_loaded  
            << " | Normal: " << total_normal_loaded 
            << " | Hard: " << total_hard_loaded
            << " | Extreme: " << total_extreme_loaded << std::endl
            << "-----------------------------------------------------------------------" << std::endl;
}

// Converts internal character and mission names into displayable ones
void SetDisplayNames() {
  std::string mission_to_edit = current_round_data.current_mission;
  std::string character_to_edit = current_round_data.current_character;

  // Replace underscores with spaces
  for (char &c : character_to_edit) {
    if (c == '_') {
      c = ' ';
    }
  }

  for (char &c : mission_to_edit) {
    if (c == '_') {
      c = ' ';
    }
  }

  // For Father/Son and Daddy's Little Girl its easier to just hardcode since its only 2
  if (current_round_data.current_mission == "Father_Son") {
    mission_to_edit = "Father/Son";
  }
  else if (current_round_data.current_mission == "Daddy_s_Little_Girl") {
    mission_to_edit = "Daddy's Little Girl";
  }
  current_round_data.current_character_for_display = character_to_edit;
  current_round_data.current_mission_for_display = mission_to_edit;
}

// Randomly picks a mission
void MissionSelector() {
  int random_mission_selector;
  std::string selected_mission;
  // Only use main missions on easy
  if (game_settings.difficulty == "Easy") {
    random_mission_selector = RandomIndex(implemented_main_missions.size());
    selected_mission = implemented_main_missions[random_mission_selector];
  }
  // On any difficulty other than easy, also have chance to select side missions
  else if (game_settings.difficulty == "Normal" || game_settings.difficulty == "Hard" || game_settings.difficulty == "Extreme") {
    // Chance to get a main mission, calculated: (main missions / (main missions + side missions)) * 100
    std::uniform_int_distribution<int> distribution(1, 100);
    // Pick random main mission
    if (distribution(gen) <= chance_of_main_mission) {
      random_mission_selector = RandomIndex(implemented_main_missions.size());
      selected_mission = implemented_main_missions[random_mission_selector];
    }
    // Pick random side mission
    else {
      random_mission_selector = RandomIndex(implemented_side_missions.size());
      selected_mission = implemented_side_missions[random_mission_selector];
    }
  }
  current_round_data.current_mission = selected_mission;
}

// Randomly picks a voiceline from the selected mission and difficulty
bool VoicelineSelector(std::string mission) {
  VoicelineDifficulties &difficulty = voiceline_database[mission];
  std::vector<std::string> *all_lines_of_selected_difficulty = nullptr;

  if (game_settings.difficulty == "Easy") {
    all_lines_of_selected_difficulty = &difficulty.easy;
  }
  else if (game_settings.difficulty == "Normal") {
    all_lines_of_selected_difficulty = &difficulty.normal;
  }
  else if (game_settings.difficulty == "Hard") {
    all_lines_of_selected_difficulty = &difficulty.hard;
  }
  else if (game_settings.difficulty == "Extreme") {
    all_lines_of_selected_difficulty = &difficulty.extreme;
  }
  // Detailed failure diagnostics for reoccurring "No voicelines available" error
  // Most often caused by forgetting or misspelling mission name either in .txt filename or in implemented mission arrays at the top
  if (all_lines_of_selected_difficulty == nullptr || all_lines_of_selected_difficulty->empty()) {
    std::cout << "========== VOICELINE SELECTION FAILURE ==========" << std::endl
              << "Mission:      [" << mission << "]" << std::endl
              << "Difficulty:   [" << game_settings.difficulty << "]" << std::endl;
      
    if (all_lines_of_selected_difficulty == nullptr) {
      std::cout << "Selected vector: NULL" << std::endl
                << "Reason: difficulty did not match any known difficulty." << std::endl;
    }
    else {
      std::cout << "Selected vector: EMPTY" << std::endl
                << "Selected vector size: " << all_lines_of_selected_difficulty->size() << std::endl;
    }

    std::cout << "Available lines for this mission:" << std::endl
              << "Easy: " << difficulty.easy.size() << " | Normal: " << difficulty.normal.size()
              << " | Hard:    " << difficulty.hard.size() << " | Extreme: " << difficulty.extreme.size() << std::endl
              << "=================================================" << std::endl;
    return false;
  }

  // Gets a random full line (as stored internally, so format is [Difficulty][Character]: VOICELINE)
  std::string selected_line = (*all_lines_of_selected_difficulty)[RandomIndex(all_lines_of_selected_difficulty->size())];

  // Extracts the character name from its tag in the line and stores it
  size_t beginning = selected_line.find_first_of(']');
  size_t end = selected_line.find_last_of(']');
  // subtr() takes start and length as parameters, not start and end like python would
  std::string character = selected_line.substr(beginning + 2, end - beginning - 2);
  current_round_data.current_character = character;
  // At this point we know both the character and mission, so set display names of both
  SetDisplayNames();

  // Get the separator between the line's tags and the actual line
  size_t separator = selected_line.find(':');

  // Cut out tags and separator
  std::string output_line;
  if (separator != std::string::npos) {
    output_line = selected_line.substr(separator + 1);
  }

  // Cut out whitespaces and tabs
  size_t first_char = output_line.find_first_not_of(" \t");
  if (first_char != std::string::npos) {
    output_line.erase(0, first_char);
  }

  // If content creator mode is enabled, replace curse words with censored versions
  if (game_settings.content_creator_mode) {
    for (const std::pair<const std::string, std::string> &entry : curse_words) {
      const std::string &word = entry.first;
      const std::string &censored = entry.second;
      size_t word_pos = output_line.find(word);
      
      while (word_pos != std::string::npos) {
        output_line.replace(word_pos, word.length(), censored);
        word_pos = output_line.find(word, word_pos + censored.length());
      }
    }
    current_round_data.current_voiceline = output_line;
  }
  else {
    current_round_data.current_voiceline = output_line;
  }
  return true;
}

// C++ doesn't have build in ToLowerCase, so need to build it using tolower (Which only lowers one character)
std::string ToLowerCase(std::string string) {
  transform(string.begin(), string.end(), string.begin(), ::tolower);
  return string;
}

// Normalizes the players input for comparison with interally stored characters and missions
std::string NormalizeInput(std::string input) {
    // Remove leading/trailing spaces
    size_t start = input.find_first_not_of(' ');
    size_t end = input.find_last_not_of(' ');

    if (start == std::string::npos) {
        return "";
    }

    input = input.substr(start, end - start + 1);

    // Convert to lowercase
    input = ToLowerCase(input);

    // Replace spaces, slashes (Father/Son), apostrophes (Daddy's Little Girl) inside the string with underscores
    for (char &c : input) {
        if (c == ' ' || c == '/' || c == '\'') {
            c = '_';
        }
    }

    // If "Daddys" is present, convert to "Daddy_s"
    if (input.length() >= 2 &&
        input[input.length() - 2] == 'y' &&
        input[input.length() - 1] == 's') {

        input.insert(input.length() - 1, "_");
    }

    return input;
}

// Handles the players answer and assigns the appropriate score
void ProcessPlayerAnswer() {
    // Character guess correct/incorrect
    if (NormalizeInput(current_round_data.entered_character) == ToLowerCase(current_round_data.current_character)) {
        current_round_data.current_score++;
        current_round_data.character_correct = true;
        std::cout << "- Character guess was correct!" << std::endl;
    }
    // Allow some less strict naming/spelling of character names on easy mode
    else if (game_settings.difficulty == "Easy") {
      std::map<std::string, std::string>::const_iterator iterator = alternative_names.find(current_round_data.current_character);
      
      if (iterator != alternative_names.end() && NormalizeInput(current_round_data.entered_character) == ToLowerCase(iterator->second)) {
        current_round_data.current_score++;
        current_round_data.character_correct = true;
        std::cout << "- Character guess was correct using alternative naming/spelling!" << std::endl;
      }
      else {
        current_round_data.character_correct = false;
        std::cout << "- Character guess was incorrect!" << std::endl 
                  << "Correct was: " << current_round_data.current_character_for_display << std::endl;
      }
    }
    else {
      current_round_data.character_correct = false;
      std::cout << "- Character guess was incorrect!" << std::endl
                << "Correct was: " << current_round_data.current_character_for_display << std::endl;
    }

    // Mission guess correct/incorrect
    if (NormalizeInput(current_round_data.entered_mission) == ToLowerCase(current_round_data.current_mission)) {
        current_round_data.current_score++;
        current_round_data.mission_correct = true;
        std::cout << "- Mission guess was correct!" << std::endl;
    }
    else {
        current_round_data.mission_correct = false;
        std::cout << "- Mission guess was incorrect!" << std::endl
                  << "Correct was: " << current_round_data.current_mission_for_display << std::endl;
    }
}


// Limits gameloop and framerate to 60hz/fps
void LimitFrameRate(Uint64 frame_start) {
  // The target frame time, using 1.0 / target fps
  const double target_frame_time = 1.0 / 60.0;
  Uint64 work_end = SDL_GetPerformanceCounter();
  double work_time = static_cast<double>(work_end - frame_start) / static_cast<double>(SDL_GetPerformanceFrequency());
  double remaining_time = target_frame_time - work_time;

  if (remaining_time > 0.0) {
    SDL_Delay( static_cast<Uint32>(remaining_time * 1000.0));
  }

  Uint64 frame_end = SDL_GetPerformanceCounter();
  double frame_time = static_cast<double>(frame_end - frame_start) / static_cast<double>(SDL_GetPerformanceFrequency());

  // If debug mode is enabled, calculate fps and send updates to GUI for display
  if (game_state.debug_enabled) {
    perf_metrics.fps_timer += frame_time;
    perf_metrics.fps_frame_count++;

    if (perf_metrics.fps_timer >= 1.0) {
      double fps = static_cast<double>(perf_metrics.fps_frame_count) / perf_metrics.fps_timer;
      UpdateGUIPerfMetrics(fps, frame_time);
      perf_metrics.fps_timer = 0.0;
      perf_metrics.fps_frame_count = 0;
    }
  }
}

int main(int argc, char *argv[]) {

  // Debug flag handling for console logging (Note: All std::cout, std::cerr etc will be visible in the attached console)
  for (int i = 1; i < argc; ++i) {
    if (std::string_view(argv[i]) == "-debug") {
      game_state.debug_enabled = true;
      Debug::AttachConsole();
    }
  }

  std::cout << std::endl << game_info.game_name << " " << game_info.game_version << " by " << game_info.author_name << " is starting..." << std::endl
            << "Platform: " << Debug::platform << std::endl
            << "Hash: " << Debug::ExecutableHash() << std::endl;

  if (!InitializeEverything()) {
    return 1;
  }

  // Is set to false if the player clicks quit, which then stops the game loop and runs ShutdownEverything()
  game_state.game_running = true;
  LoadAndSortLines();

  // The game loop
  while (game_state.game_running) {
    Uint64 frame_start = SDL_GetPerformanceCounter();
    SDLEventRunner(game_state.game_running);

    // Check the correctness of the players answer and display the feedback. 
    // Needs to be done before rendering the next frame.
    // Otherwise, character_correct and mission_correct are still false when the
    // frame is rendered, causing a correct answer to appear incorrect for one frame.
    if (current_round_data.answer_confirmed && !game_state.in_answer_feedback) {
      // Player answer debug prints
      std::cout << "Entered Character: " << current_round_data.entered_character << std::endl
                << "Entered Mission: " << current_round_data.entered_mission << std::endl;
      ProcessPlayerAnswer();
      // Hold the screen for a bit to show the player whether their answers were correct
      StartAnswerFeedback();
    }

    BeginGUIFrame();
    DrawGUI(game_state.game_running);

    // Apply the player's settings, reset game state and give signal that game started
    GameSettings new_settings;
    if (ApplyGameSettings(new_settings)) {
      game_settings = new_settings;
      // Ensure game state is clean for start of a round
      used_voicelines.clear();
      current_round_data.current_round = 0;
      current_round_data.current_score = 0;
      current_round_data.average_score = 0.0f;
      // Give signal that game started
      game_state.gameplay_ongoing = true;
      // Game start debug prints
      std::cout << "-------------------Game started-------------------" << std::endl
                << "Difficulty: " << game_settings.difficulty << std::endl
                << "Rounds: " << game_settings.total_rounds << std::endl
                << "Content Creator mode: " << game_settings.content_creator_mode << std::endl
                << "--------------------------------------------------" << std::endl;
    }

    // The gameplay loop, starts after the player confirms the settings, and is stopped
    // by reaching the selected round count or by the player clicking "Exit" during gameplay
    if (game_state.gameplay_ongoing) {
      if (!game_state.round_ongoing) {
        // Set round as ongoing so that no new round can be run before this one is finished
        game_state.round_ongoing = true;
        // Pick a voiceline that hasn't been used already
        while (true) {
          MissionSelector();
          // Try selecting a voiceline for that mission
          if (!VoicelineSelector(current_round_data.current_mission)) {
            // If no voiceline available for this mission and difficulty, try another mission
            continue;
          }

          // Check if the voiceline has already been used
          bool already_used = std::find(used_voicelines.begin(), used_voicelines.end(), current_round_data.current_voiceline) != used_voicelines.end();
          if (already_used) {
            continue;
          }
          else {
            // Valid voiceline found
            used_voicelines.push_back(current_round_data.current_voiceline);
            break;
          }
        }
        // Start the a new timer and incrase round counter
        current_round_data.timer_ran_out = false;
        current_round_data.current_timer = 60;
        current_round_data.round_start_time = SDL_GetPerformanceCounter();
        current_round_data.current_round++;
        // Per round debug prints
        std::cout << "---------------------Round " << current_round_data.current_round << "---------------------" << std::endl
                  << "Current Character: " << current_round_data.current_character_for_display << std::endl
                  << "Current Mission: " << current_round_data.current_mission_for_display << std::endl
                  << "Current Voice line: " << current_round_data.current_voiceline << std::endl
                  << "Current Score: " << current_round_data.current_score << std::endl
                  << "Average Score: " << current_round_data.average_score << std::endl
                  << "--------------------------------------------------" << std::endl;
      }
      
      // Update timer while round is active
      if (game_state.round_ongoing & !current_round_data.answer_confirmed) {
        Uint64 current_time = SDL_GetPerformanceCounter();
        double elapsed_seconds = static_cast<double>(current_time - current_round_data.round_start_time) / static_cast<double>(SDL_GetPerformanceFrequency());
        current_round_data.current_timer = 60 - static_cast<int>(elapsed_seconds);
        // When timer reaches 0, confirm the answer
        if (current_round_data.current_timer <= 0) {
          current_round_data.current_timer = 0;
          current_round_data.answer_confirmed = true;
          current_round_data.timer_ran_out = true;
        }
      }

      // When the timer is over, continue
      if (current_round_data.answer_confirmed && game_state.answer_feedback_finished) {
        // Only reset timer state once here, prevents the previous part from looping
        game_state.in_answer_feedback = false;
        game_state.answer_feedback_finished = false;
        // Reset answer confirmation for next round
        current_round_data.answer_confirmed = false;
        // Player has answered, so set round as finished
        game_state.round_ongoing = false;
        // Clear entered strings, needed for ImGui's Input boxes to clear
        current_round_data.entered_character.clear();
        current_round_data.entered_mission.clear();
        // When selected round limit is reached, calculate average score, transition to results screen 
        // and prevent new round from being started
        if (current_round_data.current_round >= game_settings.total_rounds) {
          current_round_data.average_score = static_cast<float>(current_round_data.current_score) / current_round_data.current_round;
          FromGameplayToResults();
          std::cout << "--------------------Game ended--------------------" << std::endl
                    << "Final Score: " << current_round_data.current_score << std::endl
                    << "Average Score " << current_round_data.average_score << std::endl
                    << "--------------------------------------------------" << std::endl;
          game_state.gameplay_ongoing = false;
        }
      }
    }

    RenderGUIFrame();
    LimitFrameRate(frame_start);
  }
  std::cout << "Shutting down..." << std::endl;
  ShutdownEverything();
  return 0;
}