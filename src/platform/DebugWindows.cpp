// Windows specific debugging implementation
#ifdef _WIN32
// Standard libraries and internal headers
#include <iostream> // Used for std::cout, std::cerr and std::cin clears
#include <windows.h> // Used for GetModuleFileNameW() and AttachConsole()
#include <filesystem> // Used for std::filesystem
#include <stdexcept> // Used for std::runtime_error
#include <cstdio> // Used for freopen_s()
#include "Debug.h" // Declarations being implemented

namespace Debug {
const std::string platform = "Windows";

std::filesystem::path GetExecutablePath() {
    std::wstring buffer(512, L'\0');
    for (;;) {
        DWORD length = GetModuleFileNameW(nullptr, buffer.data(), static_cast<DWORD>(buffer.size()));

        if (length == 0) {
            throw std::runtime_error("Failed to determine executable path");
        }

        if (length < buffer.size() - 1) {
            buffer.resize(length);
            return buffer;
        }

        buffer.resize(buffer.size() * 2);
    }
}

void AttachConsole() {
    // Make it look in global namespace to not collide with my function
    if (!::AttachConsole(ATTACH_PARENT_PROCESS)) {
        return;
    }

    FILE* fp = nullptr;
    freopen_s(&fp, "CONOUT$", "w", stdout);
    freopen_s(&fp, "CONOUT$", "w", stderr);
    freopen_s(&fp, "CONIN$", "r", stdin);
    std::cout.clear();
    std::cerr.clear();
    std::cin.clear();
}
}
#endif
