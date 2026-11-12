// Interface for the main GUI
#pragma once

struct GameSettings;
struct GameRound;

void DrawGUI(bool &game_running);

bool ApplyGameSettings(GameSettings &settings);