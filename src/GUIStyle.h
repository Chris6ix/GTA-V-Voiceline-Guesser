// GUI Style constants, shared for GUI.cpp and GUIHelpers.cpp
// Use inline so all files get the same variable instead of each getting its own copy
#pragma once
// External libraries and headers
#include "imgui.h" // ImGui API

// Reference resolution that the UI was originally designed for.
inline const float reference_width = 1280.0f;
inline const float reference_height = 720.0f;

// Current UI scale, updated whenever the window/framebuffer size changes.
inline float ui_scale = 1.0f;

// Apply global gui style
void LoadGUIStyle();

// Color overrides
// Uses ImVec(R, G, B, A) with float32 0.0-1.0 values
// Convert from 0-255 color values here for readability
// Input correct (For labels and input box)
inline const ImVec4 input_correct_color(40/255.0f, 225/255.0f, 40/255.0f, 1.0f);
// Input incorrect (For labels and input box)
inline const ImVec4 input_incorrect_color(255/255.0f, 50/255.0f, 50/255.0f, 1.0f);
// Timer about to run out color
inline const ImVec4 low_timer_color(255/255.0f, 50/255.0f, 50/255.0f, 1.0f);
// Hover tooltip box color
inline const ImVec4 tooltip_box_color(3/255.0f, 3/255.0f, 3/255.0f, 0.85f);

// Font sizes
// Base size is the resolution the font is loaded at, then scaled based on font type and screen resolution
inline const float font_base_size = 64.0f;
inline const float font_size = 32.0f;
inline const float title_font_size = font_size * 2.2f;

// Element sizes
// Uses ImVec(W, H) with dimensions in pixels
// Buttons
inline const ImVec2 button_size(200, 50);

// Header and Footer heights
inline const float header_height = 45.0f;
inline const float footer_height = 45.0f;

// Input box width
inline const float input_box_width = 300.0f;

// Right side padding (E.g for round, score, timer)
inline const float right_window_padding = 10.0f;

// Rounding of tooltip boxes
inline const float box_rounding = 4.0f;

// ImGui window flags for the window to look and behave as expected
inline const ImGuiWindowFlags window_flags =
    ImGuiWindowFlags_NoTitleBar |
    ImGuiWindowFlags_NoResize |
    ImGuiWindowFlags_NoMove |
    ImGuiWindowFlags_NoCollapse |
    ImGuiWindowFlags_NoBringToFrontOnFocus |
    ImGuiWindowFlags_NoBackground |
    ImGuiWindowFlags_NoScrollbar |
    ImGuiWindowFlags_NoScrollWithMouse;

// Button row labels, don't need to be redefined every frame
inline const char* difficulty_labels[] = {"Easy", "Normal", "Hard", "Extreme"};

// Slider values
// Slider value can't be const, ImGui needs to edit it
// The default slider value is also the start value
inline int round_slider_value = 20;
inline const int round_slider_min = 10;
inline const int round_slider_max = 100;

// Answer feedback screen durations
inline const float answer_feedback_duration = 3.0f;
inline const float answer_feedback_duration_debug = 0.5f;