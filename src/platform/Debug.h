// Interface for debugging tools/info
#pragma once
// Standard libraries and internal headers
#include <string> // Required for std::string
#include <filesystem> // Used for std::filesystem
#include <cstdint> // Used for std::uint64_t

namespace Debug {
    // Platform name
    extern const std::string platform;

    // Path to the currently running executable
    std::filesystem::path GetExecutablePath();

    // Hash of the currently running executable to build fingerprint for debug logs (To distinguish between offical releases and self built/modified ones)
    std::uint64_t HashFile(const std::filesystem::path& path);
    std::string ExecutableHash();

    // Attaches a terminal to the executable when run with -debug
    void AttachConsole();
}