// Helper functions for GUI.cpp and GUIBackend.cpp
// Standard libraries and internal headers
#include <vector> // Used for button row tooltips
#include "GUIHelpers.h" // Used for forward declarations
#include "GameState.h" // Used for screen transitions
#include "GameRoundData.h" // Used to display round data in GUI elements
#include "GUIBackend.h" // Used for PlaySound()
#include "GUIStyle.h" // Used for style constants
#include "GameSettings.h" // Used for round counter display in header
#include "GameInfo.h" // Used for game version display in footer
#include "Vulkan.h" // Used for GetVulkanBackgroundTexture().
// External libraries and headers
#include "imgui.h" // ImGui API
#include <SDL3_mixer/SDL_mixer.h> // Used for PlaySound()

// Performance metric values for the GUI to display in debug mode, updated from LimitFrameRate()
static double gui_fps;
static double gui_frame_time;

// Going back while in the settings screen
void SettingsBack() {
    game_state.in_main_screen = true; 
    game_state.in_settings_screen = false;
}

// Pressing "Play" in settings menu to confirm settings
void ConfirmSettings() {
    game_state.in_settings_screen = false; 
    game_state.settings_confirmed = true; 
    game_state.in_gameplay_screen= true; 
    game_state.gameplay_ongoing = true;
}

// Going back while in the help screen
void HelpBack() {
    game_state.in_main_screen = true; 
    game_state.in_help_screen = false;
}

// Going back while in the credits screen
void CreditsBack() {
    game_state.in_main_screen = true; 
    game_state.in_credits_screen = false;
}

// Exiting while in gameplay
void GameplayExit() {
    game_state.in_main_screen = true; 
    game_state.in_gameplay_screen = false; 
    game_state.gameplay_ongoing = false;
    game_state.round_ongoing = false;
}

// Confirming answer
void ConfirmAnswer() {
    current_round_data.answer_confirmed = true;
}

// Reaching the results screen from gameplay, for example via reaching round limit
void FromGameplayToResults() {
    game_state.in_gameplay_screen = false;
    game_state.in_results_screen = true;
}

// Exit while in the results screen
void ResultsExit() {
    game_state.in_main_screen = true; 
    game_state.in_results_screen = false;
}

// Clicking "Play" in main screen
void FromMainToSettings() {
    game_state.in_main_screen = false; 
    game_state.in_settings_screen = true;
}

// Clicking "Help" in main screen
void FromMainToHelp() {
    game_state.in_main_screen = false; 
    game_state.in_help_screen = true;
}

// Clicking "Credits" in main screen
void FromMainToCredits() {
    game_state.in_main_screen = false; 
    game_state.in_credits_screen = true;
}

// Quitting the game
void QuitGame() {
    game_state.game_running = false;
}

// Convert a reference-resolution pixel value to the current UI scale.
float UIScale(float value) {
    return value * ui_scale;
}

// Convert a reference-resolution ImVec2 to the current UI scale.
ImVec2 UIScale(ImVec2 value) {
    return ImVec2(value.x * ui_scale, value.y * ui_scale);
}

void DrawMenuBackground(float darkness) {
    ImDrawList* draw_list = ImGui::GetBackgroundDrawList();
    ImVec2 display_size = ImGui::GetIO().DisplaySize;
    // Background image
    draw_list->AddImage(GetVulkanBackgroundTexture(), ImVec2(0.0f, 0.0f), display_size);

    // Convert 0.0 - 1.0 darkness into 0 - 255 alpha
    int alpha = static_cast<int>(darkness * 255.0f);
    draw_list->AddRectFilled(ImVec2(0.0f, 0.0f), display_size, IM_COL32(0, 0, 0, alpha));
}

// Helper to center text
void CenteredText(const char* text) {
    ImVec2 text_size = ImGui::CalcTextSize(text);
    float available_width = ImGui::GetContentRegionAvail().x;
    float offset_x = (available_width - text_size.x) * 0.5f;
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + offset_x);
    ImGui::TextUnformatted(text);
}

// Helper to center wrapped text, accounting for text length to use different way for the result to look correct
void CenteredWrappedText(const char *text) {
    float available_width = ImGui::GetContentRegionAvail().x;
    // Calculate ideal wrap width (85% for long text, but cap for short)
    float wrap_width = available_width * 0.85f;
    // Calculate actual text width WITHOUT wrapping first
    ImVec2 single_line_size = ImGui::CalcTextSize(text, nullptr, false, 0.0f);
    // Determine if we need wrapping
    float final_wrap_width;
    float center_offset;
    
    if (single_line_size.x <= wrap_width) {
        // Short text - center the actual text, no wrapping needed
        final_wrap_width = 0.0f; // No wrapping
        center_offset = (available_width - single_line_size.x) * 0.5f;
    } 
    else {
        // Long text - use wrapping with container centering
        final_wrap_width = wrap_width;
        center_offset = (available_width - final_wrap_width) * 0.5f;
    }
    
    // Apply positioning
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + center_offset);

    if (final_wrap_width > 0.0f) {
        ImGui::PushTextWrapPos(ImGui::GetCursorPosX() + final_wrap_width);
        ImGui::TextUnformatted(text);
        ImGui::PopTextWrapPos();
    } 
    else {
        ImGui::TextUnformatted(text);
    }
}

// Helper to center buttons
bool CenteredButton(const char *button_label) {
    ImVec2 scaled_button_size = UIScale(button_size);
    float available_width = ImGui::GetContentRegionAvail().x;
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (available_width - scaled_button_size.x) * 0.5f);
    return ImGui::Button(button_label, scaled_button_size);
}

// Helper to center a row of selectable buttons
int CenteredButtonRow(const char *labels[], const int button_amount, const int selected_index, std::vector<std::string> hover_tooltips) {
    ImVec2 scaled_button_size = UIScale(button_size);
    float spacing = ImGui::GetStyle().ItemSpacing.x;
    float total_width = scaled_button_size.x * button_amount + spacing * (button_amount - 1);
    float available_width = ImGui::GetContentRegionAvail().x;
    // Center the entire row, rather than each individual button
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (available_width - total_width) * 0.5f);
    int clicked_index = -1;
    for (int i = 0; i < button_amount; i++) {
        // Change color of the selected button
        if (i == selected_index) {
            // Reuse the button press color, looks good
            ImGui::PushStyleColor(ImGuiCol_Button, ImGui::GetStyle().Colors[ImGuiCol_ButtonActive]);
        }

        if (ImGui::Button(labels[i], scaled_button_size)) {
            clicked_index = i;
        }

        if (i == selected_index) {
            ImGui::PopStyleColor();
        }

        // Hover tooltips per button
        if (ImGui::IsItemHovered()) {
            ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, box_rounding);
            ImGui::PushStyleColor(ImGuiCol_PopupBg, tooltip_box_color);
            ImGui::BeginTooltip();
            ImGui::TextUnformatted(hover_tooltips[i].c_str());
            ImGui::EndTooltip();
            ImGui::PopStyleColor();
            ImGui::PopStyleVar();
        }

        // Put the next button on the same line
        if (i < button_amount - 1) {
            ImGui::SameLine();
        }
    }

    return clicked_index;
}

// Helper to center a slider
// Important: label cannot be "" or trying to render the slider crashes the program,
// if you don't want to label it, use "##centered_slider". This gives it an id without displaying a label.
int CenteredSlider(const char* label, int* value, int value_min, int value_max) {
    ImVec2 scaled_button_size = UIScale(button_size);
    float spacing = ImGui::GetStyle().ItemSpacing.x;
    float slider_width = scaled_button_size.x * 4.0f + spacing * 3.0f;
    float available_width = ImGui::GetContentRegionAvail().x;
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (available_width - slider_width) * 0.5f);
    ImGui::SetNextItemWidth(slider_width);
    return ImGui::SliderInt(label, value, value_min, value_max);
}

// Helper to center a checkbox
bool CenteredCheckBox(const char *checkbox_label, bool &bool_to_change) {
    ImVec2 text_size = ImGui::CalcTextSize(checkbox_label);
    float available_width = ImGui::GetContentRegionAvail().x;
    ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (available_width) * 0.375f);
    return ImGui::Checkbox(checkbox_label, &bool_to_change);
}

// Helper to center a row of 2 input boxes with color changing for input correct/incorrect and ensures they are also vertically lined up
void CenteredInputBoxRow(const char *left_label, std::string& left_value, bool left_correct, const char *right_label, 
                        std::string &right_value, bool right_correct, bool answer_confirmed) {
    const float scaled_input_box_width = UIScale(input_box_width);
    const float spacing = ImGui::GetStyle().ItemSpacing.x;
    const float total_width = scaled_input_box_width * 2.0f + spacing;
    const float available_width = ImGui::GetContentRegionAvail().x;
    const float start_x = ImGui::GetCursorPosX() + (available_width - total_width) * 0.5f;
    ImGui::SetCursorPosX(start_x);

    if (ImGui::BeginTable("##CenteredInputBoxRow", 2, ImGuiTableFlags_SizingFixedFit)) {
        ImGui::TableSetupColumn("##left", ImGuiTableColumnFlags_WidthFixed, scaled_input_box_width);
        ImGui::TableSetupColumn("##right", ImGuiTableColumnFlags_WidthFixed, scaled_input_box_width);

        // Show the correct solution above the label when the input for that field was incorrect
        const float solution_row_height = ImGui::GetTextLineHeightWithSpacing();
        ImGui::TableNextRow(ImGuiTableRowFlags_None, solution_row_height);
        ImGui::TableSetColumnIndex(0);
        if (answer_confirmed && !left_correct) {
            const float label_width = ImGui::CalcTextSize(current_round_data.current_character_for_display.c_str()).x;
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (scaled_input_box_width - label_width) * 0.5f);
            ImGui::TextColored(input_incorrect_color, "%s", current_round_data.current_character_for_display.c_str());
        }

        ImGui::TableSetColumnIndex(1);
        if (answer_confirmed && !right_correct) {
            const float label_width = ImGui::CalcTextSize(current_round_data.current_mission_for_display.c_str()).x;
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (scaled_input_box_width - label_width) * 0.5f);
            ImGui::TextColored(input_incorrect_color, "%s", current_round_data.current_mission_for_display.c_str());
        }

        // Labels
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0); {
            const float label_width = ImGui::CalcTextSize(left_label).x;
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (scaled_input_box_width - label_width) * 0.5f);

            if (answer_confirmed) {
                ImGui::TextColored(left_correct
                    ? input_correct_color
                    : input_incorrect_color,
                    "%s", left_label);
            }
            else {
                ImGui::TextUnformatted(left_label);
            }
        }

        ImGui::TableSetColumnIndex(1); {
            const float label_width = ImGui::CalcTextSize(right_label).x;
            ImGui::SetCursorPosX(ImGui::GetCursorPosX() + (scaled_input_box_width - label_width) * 0.5f);

            if (answer_confirmed){
                ImGui::TextColored(right_correct
                ? input_correct_color
                : input_incorrect_color,
                "%s", right_label);
            }
            else {
                ImGui::TextUnformatted(right_label);
            }
        }

        // Input boxes
        ImGui::TableNextRow();
        ImGui::TableSetColumnIndex(0); {
            if (answer_confirmed) {
                ImGui::PushStyleColor(ImGuiCol_FrameBg, left_correct
                        ? input_correct_color
                        : input_incorrect_color);
            }

            ImGui::SetNextItemWidth(scaled_input_box_width);
            ImGui::InputText("##left_input", &left_value);

            if (answer_confirmed) {
                ImGui::PopStyleColor();
            }
        }

        ImGui::TableSetColumnIndex(1); {
            if (answer_confirmed) {
                ImGui::PushStyleColor(ImGuiCol_FrameBg, right_correct
                        ? input_correct_color
                        : input_incorrect_color);
            }

            ImGui::SetNextItemWidth(scaled_input_box_width);
            ImGui::InputText("##right_input", &right_value);

            if (answer_confirmed) {
                ImGui::PopStyleColor();
            }
        }

        ImGui::EndTable();
    }
}

// Helper for custom verical spacers
void VerticalSpacer(const float vertical_space_to_add) {
  ImGui::Dummy(ImVec2(0.0f, UIScale(vertical_space_to_add)));
}

// Helper to place header, including back/exit button, header text and round and score counters during gameplay
bool PlaceHeader(const char* button_label, const char* header_text) {
    if (ImGui::Button(button_label)) {
        return true;
    }

    ImGui::SameLine();
    // Center header text in the available header area.
    float header_width = ImGui::CalcTextSize(header_text).x;
    float window_width = ImGui::GetWindowWidth();
    float center_x = (window_width - header_width) * 0.5f;
    ImGui::SameLine();
    ImGui::SetCursorPosX(center_x);
    ImGui::TextUnformatted(header_text);

    // Display round and score when in gameplay
    if (game_state.in_gameplay_screen) {
        char round_text[64];
        char score_text[64];
        snprintf(round_text, sizeof(round_text), "Round: %d/%d", current_round_data.current_round, game_settings.total_rounds);
        snprintf(score_text, sizeof(score_text), "| Score: %d", current_round_data.current_score);
        float round_width = ImGui::CalcTextSize(round_text).x;
        float score_width = ImGui::CalcTextSize(score_text).x;
        float spacing = ImGui::GetStyle().ItemSpacing.x;
        float total_width = round_width + spacing + score_width;
        float right_x = ImGui::GetWindowContentRegionMax().x - right_window_padding - total_width;

        ImGui::SameLine();
        ImGui::SetCursorPosX(right_x);
        ImGui::TextUnformatted(round_text);
        ImGui::SameLine();
        ImGui::TextUnformatted(score_text);
    }

    return false;
}

// Helper to place footer, including game version
void PlaceFooter() {
    const float footer_offset = UIScale(-10.0f);
    float footer_y = ImGui::GetWindowHeight() - footer_offset - UIScale(footer_height);

    if (ImGui::GetCursorPosY() < footer_y) {
        ImGui::SetCursorPosY(footer_y);
    }

    ImGui::TextUnformatted(game_info.game_version.c_str());

    if (game_state.debug_enabled) {
        ImGui::SameLine();
        float remaining_horizontal_space = ImGui::GetContentRegionAvail().x;
        if (remaining_horizontal_space > 0.0f) {
            ImGui::Dummy(ImVec2(remaining_horizontal_space - UIScale(350.0f), 0.0f));
        }
        ImGui::SameLine();
        ImGui::Text("FPS: %.1f", gui_fps);
        ImGui::SameLine();
        ImGui::Text("| Frame time: %.1f ms", gui_frame_time * 1000.0);
    }
}

// Helper to play sound only if sound is enabled
void PlaySound(MIX_Audio *sound) {
    if (!global_settings.sound_enabled) {
        return;
    }

    MIX_PlayAudio(sdl_mixer, sound);
}

// Helper to place the timer during gameplay on the top right
void PlaceTimer() {
    char timer[64];
    snprintf(timer, sizeof(timer), "Time left: %ds", current_round_data.current_timer);
    float timer_width = ImGui::CalcTextSize(timer).x;
    float right_x = ImGui::GetWindowContentRegionMax().x - right_window_padding - timer_width;
    ImGui::SetCursorPosX(right_x);
    // Print timer red when low
    if (current_round_data.current_timer <= 10) {
        ImGui::TextColored(low_timer_color, "%s", timer);
    }
    else {
        ImGui::TextUnformatted(timer);
    }
}

void UpdateGUIPerfMetrics(double fps, double frame_time) {
  gui_fps = fps;
  gui_frame_time = frame_time;
}