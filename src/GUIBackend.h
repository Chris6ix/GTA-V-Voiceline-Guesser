// Interface for GUI backend
#pragma once

#include "imgui.h" // ImGui API
#include <SDL3/SDL.h> // SDL API
#include <SDL3_mixer/SDL_mixer.h> // Used for button_press_sound

extern MIX_Mixer *sdl_mixer;
extern MIX_Audio *button_press_sound;
extern ImFont *custom_font;

bool InitializeEverything();
bool InitializeGUI(SDL_Window *window);

void ProcessGUIEvent(const SDL_Event &event);

void ToggleFullscreen(SDL_Window *window);

void UpdateUIScale(SDL_Window* window);

void SDLEventRunner(bool &game_running);

void StartAnswerFeedback();

void BeginGUIFrame();

void RenderGUIFrame();

void ShutdownEverything();
