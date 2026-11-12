cmake_minimum_required(VERSION 3.25)
project(GTAVVoicelineGuesser LANGUAGES CXX)

# =========================================================================================
# Platform-specific settings
# =========================================================================================

if(WIN32)
    # Use Windows Resource Compiler for executable icon
    enable_language(RC)
    # Set Windows specific files and dirs
    set(DEBUG_FILE "DebugWindows.cpp")
    set(SDL3_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3-3.4.14/lib")
    set(SDL3_RUNTIME_FILE "SDL3.dll")
    set(SDL3_MIXER_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_mixer-3.2.4/lib")
    set(SDL3_MIXER_RUNTIME_FILE "SDL3_mixer.dll")
    # Attach "Windows" to executable name
    set(PLATFORM "Windows")

elseif(LINUX)
    # Set Linux specific files and dirs
    set(DEBUG_FILE "DebugLinux.cpp")
    set(SDL3_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3-3.4.14/lib")
    set(SDL3_RUNTIME_FILE "libSDL3.so")
    set(SDL3_MIXER_LIBRARY_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_mixer-3.2.4/lib")
    set(SDL3_MIXER_RUNTIME_FILE "libSDL3_mixer.so")
    # Attach "Linux" to executable name
    set(PLATFORM "Linux")

else()
    message(FATAL_ERROR "Unsupported platform")
endif()

# =========================================================================================
# Extract version string to attach to executable name
# (Only updates when CMake regenerates build system, can be triggered by saving this file)
# =========================================================================================

file(READ "${CMAKE_CURRENT_SOURCE_DIR}/src/GameInfo.h" GAME_INFO_HEADER)

string(REGEX MATCH "game_version[ \t]*=[ \t]*\"([^\"]+)\"" GAME_VERSION_MATCH "${GAME_INFO_HEADER}")

if(NOT GAME_VERSION_MATCH)
    message(FATAL_ERROR "Could not find game_version in src/GameInfo.h")
endif()

set(GAME_VERSION "${CMAKE_MATCH_1}")

message(STATUS "Game version: ${GAME_VERSION}")

# =========================================================================================
# Find Vulkan
# =========================================================================================

find_package(Vulkan REQUIRED)

# =========================================================================================
# Executable
# =========================================================================================

add_executable(GTAVVoicelineGuesser
    src/GTAVVoicelineGuesser.cpp
    src/GUIBackend.cpp
    src/GUIHelpers.cpp
    src/GUIStyle.cpp
    src/GUI.cpp
    src/platform/Debug.cpp
    src/platform/${DEBUG_FILE}
    src/platform/Paths.cpp
    src/Vulkan.cpp

    libs/imgui-1.92.9b/imgui.cpp
    libs/imgui-1.92.9b/imgui_draw.cpp
    libs/imgui-1.92.9b/imgui_tables.cpp
    libs/imgui-1.92.9b/imgui_widgets.cpp
    libs/imgui-1.92.9b/backends/imgui_impl_vulkan.cpp
    libs/imgui-1.92.9b/backends/imgui_impl_sdl3.cpp
    libs/imgui-1.92.9b/misc/cpp/imgui_stdlib.cpp
)

# =========================================================================================
# Windows executable icon
# =========================================================================================

if(WIN32)
    target_sources(GTAVVoicelineGuesser PRIVATE 
        "${CMAKE_CURRENT_SOURCE_DIR}/resources/icons/GTAVVoicelineGuesser_Icon.rc")
endif()

# =========================================================================================
# Output
# =========================================================================================

set(OUTPUT_DIR "${CMAKE_SOURCE_DIR}/.build")
set(OUTPUT_LIB_DIR "${OUTPUT_DIR}/libs")

# Linux uses /bin so the executable can be referenced by a .desktop file.
# Windows keeps the executable in the build root.
if(LINUX)
    set(OUTPUT_BIN_DIR "${OUTPUT_DIR}/bin")
elseif(WIN32)
    set(OUTPUT_BIN_DIR "${OUTPUT_DIR}")
endif()

set_target_properties(GTAVVoicelineGuesser PROPERTIES
    OUTPUT_NAME "GTAVVoicelineGuesser-${GAME_VERSION}-${PLATFORM}"
    RUNTIME_OUTPUT_DIRECTORY "${OUTPUT_BIN_DIR}"
)

# =========================================================================================
# C++ standard
# =========================================================================================

if(WIN32)
    # Set MSVC to std::c++latest, works better than std::c++23
    target_compile_options(GTAVVoicelineGuesser PRIVATE /std:c++latest)
else()
    target_compile_features(GTAVVoicelineGuesser PRIVATE cxx_std_23)
endif()

# =========================================================================================
# Debug information
# =========================================================================================

if(WIN32)
    target_compile_options(GTAVVoicelineGuesser PRIVATE /Zi)

    set_target_properties(GTAVVoicelineGuesser PROPERTIES
        COMPILE_PDB_OUTPUT_DIRECTORY
            "${CMAKE_SOURCE_DIR}/.build/.debug"

        PDB_OUTPUT_DIRECTORY
            "${CMAKE_SOURCE_DIR}/.build/.debug"
    )
endif()

# =========================================================================================
# Exception handling
# =========================================================================================

if(WIN32)
    target_compile_options(GTAVVoicelineGuesser PRIVATE /EHsc)
endif()

# =========================================================================================
# Include directories
# =========================================================================================

target_include_directories(GTAVVoicelineGuesser PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/libs/imgui-1.92.9b"
    "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3-3.4.14/include"
    "${CMAKE_CURRENT_SOURCE_DIR}/libs/SDL3_mixer-3.2.4/include"
)

# =========================================================================================
# SDL3
# =========================================================================================

target_link_directories(GTAVVoicelineGuesser PRIVATE
    "${SDL3_LIBRARY_DIR}"
    "${SDL3_MIXER_LIBRARY_DIR}"
)

target_link_libraries(GTAVVoicelineGuesser PRIVATE
    SDL3
    SDL3_mixer
    Vulkan::Vulkan
)

# =========================================================================================
# Windows linker settings
# =========================================================================================

if(WIN32)
    target_link_options(GTAVVoicelineGuesser PRIVATE
        /SUBSYSTEM:WINDOWS
        /ENTRY:mainCRTStartup
        /INCREMENTAL:NO
        /DELAYLOAD:SDL3.dll
        /DELAYLOAD:SDL3_mixer.dll
    )

    target_link_libraries(GTAVVoicelineGuesser PRIVATE
        delayimp.lib
    )
endif()

# =========================================================================================
# Linux runtime library search path
# =========================================================================================

if(LINUX)
    # SDL3 and SDL3_mixer are stored in ../libs relative to the executable.
    # $ORIGIN means "the directory containing the executable".
    set_target_properties(GTAVVoicelineGuesser PROPERTIES
        BUILD_RPATH "$ORIGIN/../libs"
        INSTALL_RPATH "$ORIGIN/../libs"
    )
endif()

# =========================================================================================
# Create .desktop file for linux
# =========================================================================================

if(LINUX)
    configure_file(
        "${CMAKE_CURRENT_SOURCE_DIR}/tools/GTAVVoicelineGuesser.desktop.in"
        "${OUTPUT_DIR}/GTAVVoicelineGuesser-${GAME_VERSION}.desktop"
        @ONLY
    )
endif()

# =========================================================================================
# Copy files and folders next to executable
# =========================================================================================

add_custom_command(TARGET GTAVVoicelineGuesser POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        "${OUTPUT_LIB_DIR}"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL3_LIBRARY_DIR}/${SDL3_RUNTIME_FILE}"
        "${OUTPUT_LIB_DIR}/${SDL3_RUNTIME_FILE}"
)

add_custom_command(TARGET GTAVVoicelineGuesser POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E make_directory
        "${OUTPUT_LIB_DIR}"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${SDL3_MIXER_LIBRARY_DIR}/${SDL3_MIXER_RUNTIME_FILE}"
        "${OUTPUT_LIB_DIR}/${SDL3_MIXER_RUNTIME_FILE}"
)

add_custom_command(TARGET GTAVVoicelineGuesser POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets"
        "${OUTPUT_DIR}/assets"
)

add_custom_command(TARGET GTAVVoicelineGuesser POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/licenses"
        "${OUTPUT_DIR}/licenses"
)

add_custom_command(TARGET GTAVVoicelineGuesser POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/README.md"
        "${OUTPUT_DIR}/README.md"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/CHANGELOG.md"
        "${OUTPUT_DIR}/CHANGELOG.md"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE.txt"
        "${OUTPUT_DIR}/LICENSE.txt"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/CONTRIBUTING.md"
        "${OUTPUT_DIR}/CONTRIBUTING.md"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/BUILDING.md"
        "${OUTPUT_DIR}/BUILDING.md"

    COMMAND ${CMAKE_COMMAND} -E copy_if_different
        "${CMAKE_CURRENT_SOURCE_DIR}/THIRD_PARTY_NOTICES.md"
        "${OUTPUT_DIR}/THIRD_PARTY_NOTICES.md"
)

# =========================================================================================
# Create release ZIP
# =========================================================================================

set(RELEASE_DIR "${CMAKE_SOURCE_DIR}/.build/release")
set(RELEASE_ZIP "${RELEASE_DIR}/GTAVVoicelineGuesser-${GAME_VERSION}-${PLATFORM}.zip")

# 2 different zip commands because linux has the executable in /bin and a .desktop
if(LINUX)
    add_custom_command(TARGET GTAVVoicelineGuesser POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
            "${RELEASE_DIR}"
        COMMAND ${CMAKE_COMMAND} -E rm -f
            "${RELEASE_ZIP}"
        COMMAND ${CMAKE_COMMAND} -E tar
            "cf"
            "${RELEASE_ZIP}"
            --format=zip
            "bin"
            "libs"
            "assets"
            "licenses"
            "GTAVVoicelineGuesser-${GAME_VERSION}.desktop"
            "README.md"
            "CHANGELOG.md"
            "LICENSE.txt"
            "CONTRIBUTING.md"
            "BUILDING.md"
            "THIRD_PARTY_NOTICES.md"

        WORKING_DIRECTORY "${OUTPUT_DIR}"
    )
elseif(WIN32)
    add_custom_command(TARGET GTAVVoicelineGuesser POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E make_directory
            "${RELEASE_DIR}"
        COMMAND ${CMAKE_COMMAND} -E rm -f
            "${RELEASE_ZIP}"
        COMMAND ${CMAKE_COMMAND} -E tar
            "cf"
            "${RELEASE_ZIP}"
            --format=zip
            "$<TARGET_FILE_NAME:GTAVVoicelineGuesser>"
            "libs"
            "assets"
            "licenses"
            "README.md"
            "CHANGELOG.md"
            "LICENSE.txt"
            "CONTRIBUTING.md"
            "BUILDING.md"
            "THIRD_PARTY_NOTICES.md"

        WORKING_DIRECTORY "${OUTPUT_DIR}"
    )
endif()
