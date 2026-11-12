// Linux specific debugging implementation
#ifdef __linux__
// Standard libraries and internal headers
#include <filesystem> // Used for std::filesystem
#include <stdexcept> // Used for std::runtime_error
#include <unistd.h> // Used for readlink()
#include "Debug.h" // Declarations being implemented

namespace Debug {
const std::string platform = "Linux";

std::filesystem::path GetExecutablePath() {
    std::string buffer(512, '\0');
    for (;;) {
        ssize_t length = readlink("/proc/self/exe", buffer.data(), buffer.size());

        if (length < 0) {
            throw std::runtime_error("Failed to determine executable path");
        }

        if (static_cast<size_t>(length) < buffer.size()) {
            buffer.resize(length);
            return buffer;
        }

        buffer.resize(buffer.size() * 2);
    }
}

void AttachConsole() {
    // On Linux, a process launched from a terminal always
    // inherits the terminal's stdout/stderr file descriptors.
}
}

#endif
