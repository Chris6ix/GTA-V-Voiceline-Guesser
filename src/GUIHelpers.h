// Interface for the GUI helpers
#pragma once
// Standard libraries and internal headers
#include <string> // Required for std::string
#include <vector> // Used in CenteredButtonRow()
#include "GUIBackend.h" // Used for PlaySound()
// External libraries and headers
#include "imgui.h" // ImGui API
#include "misc/cpp/imgui_stdlib.h" // Allows to use std::string in ImGui instead of char *. Required for compilation even if IntelliSense says it's unused.

// Menu transitions
void SettingsBack();
void ConfirmSettings();
void HelpBack();
void CreditsBack();
void GameplayExit();
void ConfirmAnswer();
void FromGameplayToResults();
void ResultsExit();
void FromMainToSettings();
void FromMainToHelp();
void FromMainToCredits();
void QuitGame();

float UIScale(float value);
ImVec2 UIScale(ImVec2 value);

void DrawMenuBackground(float darkness);

void CenteredText(const char *text);

void CenteredWrappedText(const char *text);

bool CenteredButton(const char *button_label);

int CenteredButtonRow(const char *labels[], const int button_amount, const int selected_index, std::vector<std::string> hover_tooltips);

int CenteredSlider(const char *label, int *value, int value_min, int value_max);

bool CenteredCheckBox(const char *checkbox_label, bool &bool_to_change);

void CenteredInputBoxRow(const char *left_label, std::string &left_value, bool left_correct, 
                        const char *right_label, std::string &right_value, bool right_correct, bool answer_confirmed);

void VerticalSpacer(const float vertical_space_to_add);

bool PlaceHeader(const char *button_label, const char *header_text);
void PlaceFooter();

void PlaySound(MIX_Audio *sound);

void PlaceTimer();

void UpdateGUIPerfMetrics(double fps, double frame_time);