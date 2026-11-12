// Separate file for the game's curse-word map, so the rest of the project can be read by 
// standard/censored LLMs without triggering content-safety or TOS-related issues.
#pragma once
// Standard libraries and internal headers
#include <string> // Required for std::string
#include <unordered_map> // Used for curse_words

// A map of curse words and their censored versions, used if content creator mode is on
const std::unordered_map<std::string, std::string> curse_words = {
  {"Cunt", "C***"}, {"cunt", "c***"}, 
  {"Nigga", "N****"}, {"nigga", "n****"}, {"nig", "n**"},
  {"Nazi", "N***"}, // Appears once in Simeons dialogue in Franklin and Lamar
  {"Rape", "R***"}, {"rape", "r***"} // Appears in Jimmys dialogue in Complications
  // Not sure if fuck, bitch, dick, cock need to be censored aswell
};