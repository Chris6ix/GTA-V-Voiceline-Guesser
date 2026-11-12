// Handles platform specific pathing
#include "Paths.h" // Declarations being implemented
#ifdef _WIN32
#include <windows.h> // Used for GetModuleFileNameW(), AddDllDirectory() and SetDefaultDllDirectories()
#endif

namespace Paths {
    std::filesystem::path GetExecutableDirectory() {
#ifdef _WIN32
        wchar_t buffer[MAX_PATH];
        DWORD length = GetModuleFileNameW(nullptr, buffer, MAX_PATH);

        if (length == 0) {
            return {};
        }

        return std::filesystem::path(buffer).parent_path();

#elif defined(__linux__)
        return std::filesystem::read_symlink("/proc/self/exe").parent_path();
#else
        return {};
#endif
    }

    std::filesystem::path GetAssetPath(const std::filesystem::path& path) {
        auto executable_directory = GetExecutableDirectory();
#ifdef _WIN32
        return (executable_directory / "assets" / path).lexically_normal();
#elif defined(__linux__)
        return (executable_directory / "../assets" / path).lexically_normal();
#else
        return {};
#endif
    }

#ifdef _WIN32
    bool AddLibraryDirectoryToDllSearchPath() {
        const auto library_directory = (Paths::GetExecutableDirectory() / "libs").lexically_normal();
        if (!SetDefaultDllDirectories(LOAD_LIBRARY_SEARCH_DEFAULT_DIRS)) {
            return false;
        }

        return AddDllDirectory(library_directory.c_str()) != nullptr;
    }
#endif
}