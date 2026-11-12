# Changelog

## v0.6.0 - First Public Release

- Added background image for all menus.
- Replaced placeholder icon with custom made one.
- Added icon to Linux version via .desktop file and SDL BMP.
- Added sound effect on button presses.
- Adjusted GUI layout and color for improved look.
- Fixed a one-frame delay causing correct answers to briefly display as incorrect.
- Fixed an access violation during shutdown, causing the game to crash instead of properly shutdown.
- Fixed an issue where the game would fail to select a voiceline if the selected mission has no voicelines for the given difficulty.
- Cleaned up code, improved documentation and debug system.
- Added `BUILDING.md`.
- Added missions: Friend Request, The Long Stretch, Casing The Jewel Store, Carabine Rifles, Bugstars Equipment, BZ Gas Grenades, The Jewel Store Job (2024 voicelines total).

## v0.5.1

- Added hover tooltips to game settings.
- Added system to avoid showing duplicate voicelines.
- Made timer stop when player has confirmed their answer, avoids double confirmations when confirming close to timer end.

## v0.5.0 - Second Closed Beta

- Replaced the fixed 20, 30, 50, 100-round selection buttons with a 10–100 round slider.
- Added a 60-second timer for each round, including a red warning when 10 seconds or less remain.
- Improved answer feedback by displaying the correct solution directly in the GUI instead of only in debug logs.
- Improved input handling by allowing slashes, apostrophes and missing spaces in answers (E.g. `Daddys` → `Daddy's`).
- Improved project organization and documentation.
- Added `LICENSE.txt`, `CONTRIBUTING.md` and `THIRD_PARTY_NOTICES.md`.
- Added missions: Father/Son, Chop, Marriage Counseling, Daddy's Little Girl (1334 voicelines total).

## v0.4.2

- Added `README.md` with game rules, difficulty descriptions, installation instructions, included content, issue reporting guidelines and other project information.
- Improved build scripts to automatically bundle the game and included files into properly named, platform-specific `.zip` archives.

## v0.4.1

- Improved input handling by allowing leading and trailing spaces in answers.
- Added support for alternative character names and spellings in Easy Mode.
- Rebalanced some voicelines.
- Fixed incorrect character formatting in some voicelines.

## v0.4.0 - First Closed Beta

- Overhauled the GUI style with a significantly improved visual design.
- Added window resizing with proportional UI scaling, preventing stretched, blurry, or undersized UI elements.

## v0.3.0

- Transitioned from VS Code's `tasks.json` to CMake for building.
- Added the first Linux build.
- Added a placeholder icon to the Windows executable.
- Added Content Creator Mode to automatically censor potentially problematic words.
- Improved input handling by making answers case-insensitive.
- Added missions: Pulling Favors, Repossession, Complications (615 voicelines total).

## v0.2.0

- Added simple GUI screens for all existing game functions.
- Added Credits and Help screens.
- Added a round limit setting and Results screen.
- Improved answer feedback by displaying correct and incorrect answers using green and red colors.
- Added keybind support for confirming answers and settings, as well as navigating back and exiting menus.
- Added a debug system with performance metrics and detailed logs about game state.

## v0.1.0

- Initial game prototype, fully console-based.
- Added missions: Prologue, Franklin and Lamar (283 voicelines total).
