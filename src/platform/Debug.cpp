// Platform agnostic hashing algorithm
// Standard libraries and internal headers
#include <filesystem> // Used for std::filesystem
#include <fstream> // Used for std::ifstream
#include <cstdint> // Used for std::uint64_t and std::uint8_t
#include <stdexcept> // Used for std::runtime_error
#include "Debug.h" // Used for GetExecutablePath()

namespace Debug {
std::uint64_t HashFile(const std::filesystem::path& path) {
    std::ifstream file(path, std::ios::binary);

    if (!file) {
        throw std::runtime_error("Failed to open executable");
    }

    // FNV-1a 64-bit, not cryptographically secure, but doesn't need to be, its just a simple hash
    constexpr std::uint64_t offsetBasis = 14695981039346656037ull;
    constexpr std::uint64_t prime       = 1099511628211ull;

    std::uint64_t hash = offsetBasis;
    char buffer[64 * 1024];
    while (file.read(buffer, sizeof(buffer)) || file.gcount() > 0) {
        const auto count = file.gcount();

        for (std::streamsize i = 0; i < count; ++i) {
            hash ^= static_cast<std::uint8_t>(buffer[i]);
            hash *= prime;
        }
    }

    return hash;
}

std::string ExecutableHash() {
    const auto hash = HashFile(GetExecutablePath());
    std::ostringstream stream;
    stream << std::hex
           << std::setw(16)
           << std::setfill('0')
           << hash;

    return stream.str();
}
}