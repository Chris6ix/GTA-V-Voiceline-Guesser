// Constants about the game's info
# pragma once
// Standard libraries and internal headers
#include <string> // Required for std::string

struct GameInfo {
  const std::string game_name = "GTA V Voiceline Guesser";
  const std::string game_name_all_caps = "GTA V VOICELINE GUESSER";
  const std::string author_name = "Chris6ix";
  const std::string author_name_all_caps = "CHRIS6IX";
  const std::string game_version = "v0.6.0";
};

extern GameInfo game_info;