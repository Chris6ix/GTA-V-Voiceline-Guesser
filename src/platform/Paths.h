#pragma once

#include <filesystem> // Used for std::filesystem

namespace Paths {
    std::filesystem::path GetExecutableDirectory();
    std::filesystem::path GetAssetPath(const std::filesystem::path& path);

    #ifdef _WIN32
      bool AddLibraryDirectoryToDllSearchPath();
    #endif
}