// The main GUI file, where the GUI is built
// Standard libraries and internal headers
#include <format> // Used for average_score formatting
#include <vector> // Used for passing tooltips to CenteredButtonRow()
#include "GUIBackend.h" // Used for button_press_sound
#include "GUIHelpers.h" // Used for many elements
#include "GUIStyle.h" // Used for GUI Styling
#include "GameInfo.h" // Used for the game name in main screen
#include "GameSettings.h" // Used for ApplyGameSettings() and difficulty line in results screen
#include "GameRoundData.h" // Used in gameplay and results screens
#include "GameState.h" // Used for controlling which menu is displayed
// External libraries and headers
#include "imgui.h" // ImGui API

// Default GUI selections
static std::string selected_difficulty = "Normal";
static int selected_rounds = 20;
static bool content_creator_mode = false;

// Draw GUI, runs once per frame
// The following repeated if statements are intentionally kept on one line to avoid excessive vertical space, improving readability
void DrawGUI(bool &game_running) {
  // Make the ImGui window fill the SDL window (Main window) and remove Title, resize etc
  ImGuiViewport* viewport = ImGui::GetMainViewport();
  ImGui::SetNextWindowPos(viewport->WorkPos);
  ImGui::SetNextWindowSize(viewport->WorkSize);

  // Main screen
  if (game_state.in_main_screen) {
    ImGui::Begin("MainScreen", nullptr, window_flags);
    DrawMenuBackground(0.55f);
    VerticalSpacer(15.0f);
    // Apply larger font for title
    ImGui::PushFont(custom_font, title_font_size * ui_scale);
    CenteredText(game_info.game_name_all_caps.c_str());
    // Clear larger font again and apply normal font for everything else
    ImGui::PopFont();
    ImGui::PushFont(custom_font, font_size * ui_scale);

    VerticalSpacer(75.0f);
    if (CenteredButton("Play")) {FromMainToSettings(); PlaySound(button_press_sound);}
    VerticalSpacer(5.0f);
    if (CenteredButton("Help")) {FromMainToHelp(); PlaySound(button_press_sound);}
    VerticalSpacer(5.0f);
    if (CenteredButton("Credits")) {FromMainToCredits(); PlaySound(button_press_sound);}
    VerticalSpacer(5.0f);
    if (CenteredButton("Quit")) {QuitGame(); PlaySound(button_press_sound);}

    PlaceFooter();
    ImGui::PopFont();
    ImGui::End();
  }

  // Game setup screen
  else if (game_state.in_settings_screen) {
      ImGui::Begin("GameSettingsScreen", nullptr, window_flags);
      DrawMenuBackground(0.55f);
      ImGui::PushFont(custom_font, font_size * ui_scale);
      if (PlaceHeader("Back", "Game Setup")) {SettingsBack(); PlaySound(button_press_sound);}
      // Difficulty setting
      VerticalSpacer(35.0f);
      CenteredText("Difficulty");
      VerticalSpacer(5.0f);

      // Convert the selected difficulty into an index for to build the button row
      int selected_difficulty_index = 0;
      if (selected_difficulty == "Easy") {selected_difficulty_index = 0;}
      else if (selected_difficulty == "Normal") {selected_difficulty_index = 1;}
      else if (selected_difficulty == "Hard") {selected_difficulty_index = 2;}
      else if (selected_difficulty == "Extreme") {selected_difficulty_index = 3;}

      // Draw button row, including hover tooltips and check which one was clicked
      std::vector<std::string> difficulty_tooltips = {
        "For players who know the game and its most iconic dialogue", 
        "For players who are familiar with the game and its dialogue", 
        "For players who know the game's dialogue incredibly well", 
        "For true dialogue experts who know the game inside out"
      };
      int difficulty_clicked = CenteredButtonRow(difficulty_labels, 4, selected_difficulty_index, difficulty_tooltips);

      // Convert back to selected difficulty
      if (difficulty_clicked == 0) {selected_difficulty = "Easy"; PlaySound(button_press_sound);}
      else if (difficulty_clicked == 1) {selected_difficulty = "Normal"; PlaySound(button_press_sound);}
      else if (difficulty_clicked == 2) {selected_difficulty = "Hard"; PlaySound(button_press_sound);}
      else if (difficulty_clicked == 3) {selected_difficulty = "Extreme"; PlaySound(button_press_sound);}

      VerticalSpacer(35.0f);

      // Number of rounds setting
      CenteredText("Number of rounds");
      VerticalSpacer(5.0f);

      // Allow 1 round games in debug for easier testing of results screen
      if (game_state.debug_enabled) {
        CenteredSlider("##centered_slider", &round_slider_value, 1, round_slider_max);
      }
      else {
        CenteredSlider("##centered_slider", &round_slider_value, round_slider_min, round_slider_max);
      }
      
      selected_rounds = round_slider_value;
      VerticalSpacer(35.0f);

      // Extra settings
      CenteredText("Extra settings");
      VerticalSpacer(5.0f);
      CenteredCheckBox("Content Creator Mode", content_creator_mode);
      
      if (ImGui::IsItemHovered()) {
        ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, box_rounding);
        ImGui::PushStyleColor(ImGuiCol_PopupBg, tooltip_box_color);
        ImGui::BeginTooltip();
        ImGui::TextUnformatted("Censors some problematic words");
        ImGui::EndTooltip();
        ImGui::PopStyleColor();
        ImGui::PopStyleVar();
      }

      VerticalSpacer(5.0f);
      CenteredCheckBox("UI Sound", global_settings.sound_enabled);

      VerticalSpacer(35.0f);
      // Set gameplay_started to true so that main() can continue
      if (CenteredButton("Play")) {ConfirmSettings(); PlaySound(button_press_sound);}

      PlaceFooter();
      ImGui::PopFont();
      ImGui::End();
      return;
  }

    // Help screen
  else if (game_state.in_help_screen) {
    ImGui::Begin("HelpScreen", nullptr, window_flags);
    DrawMenuBackground(0.55f);
    ImGui::PushFont(custom_font, font_size * ui_scale);
    if (PlaceHeader("Back", "Help")) {HelpBack(); PlaySound(button_press_sound);}

    VerticalSpacer(25.0f);
    CenteredText("If you have an issue with the game, please see \"Issue Reporting\" in README.md");

    VerticalSpacer(40.0f);
    CenteredText("Keybinds: ");
    VerticalSpacer(5.0f);
    CenteredText("F11: Toggle Fullscreen");
    CenteredText("Enter: Confirm answer during gameplay");
    CenteredText("Escape: Go back/exit in any screen");

    PlaceFooter();
    ImGui::PopFont();
    ImGui::End();
  }

  // Credits screen
  else if (game_state.in_credits_screen) {
    ImGui::Begin("CreditsScreen", nullptr, window_flags);
    DrawMenuBackground(0.55f);
    ImGui::PushFont(custom_font, font_size * ui_scale);
    if (PlaceHeader("Back", "Credits")) {CreditsBack(); PlaySound(button_press_sound);}

    // Put credits content in scrolling child so that footer stays anchored to bottom while scrolling
    float footer_height_scaled = UIScale(footer_height);
    ImGui::BeginChild("CreditsContent", ImVec2(0.0f, -footer_height_scaled), ImGuiChildFlags_None, ImGuiWindowFlags_None);
        VerticalSpacer(35.0f);
        CenteredText("GTA V Voiceline Guesser was developed by Chris6ix (https://github.com/Chris6ix).");

        VerticalSpacer(40.0f);
        CenteredText("Disclaimer");
        VerticalSpacer(25.0f);
        CenteredWrappedText("This is a free, non-commercial, fan-made trivia game and is not affiliated with,"
                        "sponsored by, or endorsed by Rockstar Games or Take-Two Interactive."
                        "Grand Theft Auto V, its characters, dialogue, names, and other related intellectual property"
                        "are the property of their respective rights holders."
                        "Certain references to Grand Theft Auto V, including selected dialogue, character depictions,"
                        "and visual elements inspired by the game, are included solely for the purpose of creating a fan-made trivia experience."
                        "The background artwork and other original assets included in this application are"
                        "independently created and are not official Rockstar Games assets."
                        "No Rockstar Games software, game files, audio recordings, or other proprietary game assets are distributed with this application.");
        VerticalSpacer(40.0f);

        CenteredText("Third-Party Notices");
        VerticalSpacer(25.0f);
        CenteredText("This game uses third-party libraries and assets.");
        CenteredText("For more information, please see THIRD_PARTY_NOTICES.md");
    ImGui::EndChild();

    PlaceFooter();
    ImGui::PopFont();
    ImGui::End();
  }

  // Gameplay screen
  else if (game_state.in_gameplay_screen) {
    ImGui::Begin("GameplayScreen", nullptr, window_flags);
    DrawMenuBackground(0.55f);
    ImGui::PushFont(custom_font, font_size * ui_scale);
    // If exit is pressed during gameplay, send signal to main() to stop the gameplay loop
    if (PlaceHeader("Exit", "")) {GameplayExit(); PlaySound(button_press_sound);}
    
    PlaceTimer();
    VerticalSpacer(35.0f);
    CenteredText("Voiceline:");
    VerticalSpacer(35.0f);
    CenteredWrappedText(current_round_data.current_voiceline.c_str());
    VerticalSpacer(35.0f);
    // Create both input boxes, and pass whether input was correct and whether answer has been confirmed for coloring
    CenteredInputBoxRow("Character", current_round_data.entered_character, current_round_data.character_correct, 
                        "Mission", current_round_data.entered_mission, current_round_data.mission_correct,
                        current_round_data.answer_confirmed);
    VerticalSpacer(35.0f);
    // Tells main() that the player confirmed his answer, so that main() can proceed with the game loop
    if (CenteredButton("Confirm")) {ConfirmAnswer(); PlaySound(button_press_sound);}

    PlaceFooter();
    ImGui::PopFont();
    ImGui::End();
  }

  // Results screen
  else if (game_state.in_results_screen) {
    ImGui::Begin("ResultsScreen", nullptr, window_flags);
    DrawMenuBackground(0.55f);
    ImGui::PushFont(custom_font, font_size * ui_scale);
    CenteredText("Results");
    ImGui::Separator();
    
    // Format and print result
    VerticalSpacer(35.0f);
    std::string final_score = "Final Score: " + std::to_string(current_round_data.current_score);
    CenteredText(final_score.c_str());
    VerticalSpacer(5.0f);
    CenteredText(("Difficulty Played: " + game_settings.difficulty).c_str());
    VerticalSpacer(5.0f);
    std::string rounds_played = "Rounds Played: " + std::to_string(selected_rounds);
    CenteredText(rounds_played.c_str());
    VerticalSpacer(5.0f);
    // Round average score to 2 decimal, need to use format() here as CenteredText() doesnt support formatting strings
    std::string average_score = std::format("Average Score: {:.2f}", current_round_data.average_score);
    CenteredText(average_score.c_str());

    VerticalSpacer(35.0f);
    if (CenteredButton("Exit")) {ResultsExit(); PlaySound(button_press_sound);}

    PlaceFooter();
    ImGui::PopFont();
    ImGui::End();
  }
}

// Apply the selected settings
bool ApplyGameSettings(GameSettings &settings) {
    if (!game_state.settings_confirmed) {
        return false;
    }

    settings.difficulty = selected_difficulty;
    settings.total_rounds = selected_rounds;
    settings.content_creator_mode = content_creator_mode;
    game_state.settings_confirmed = false;
    return true;
}