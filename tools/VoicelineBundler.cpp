// Bundles all .txt voiceline files into a single header file that can be nicely included in the executable itself, avoids having 100+ individual files later in the release
// Needs to be run before compiling the game itself (if changes to the list of voicelines were made)
// Standard libraries and internal headers
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> bundled_missions;

int main() {
    std::filesystem::path inputDirectory = "../resources/voicelines";
    std::filesystem::path outputFile = "../src/BundledVoicelines.h";

    // Overwrite existing file
    std::ofstream out(outputFile, std::ios::out | std::ios::trunc);

    if (!out) {
        std::cerr << "Could not create output file\n";
        return 1;
    }

    out << "// All implemented voicelines bundled into a single file to be nicely included in the executable itself\n";
    out << "#pragma once\n\n";
    out << "#include <string> // Required for std::string\n";
    out << "#include <unordered_map> // Used for bundled_voicelines\n\n";

    out << "inline const std::unordered_map<std::string, std::string> bundled_voicelines = {\n";

    // Recursively iterate through the input directory and all subdirectories
    for (const auto& entry : std::filesystem::recursive_directory_iterator(inputDirectory)) {
        if (!entry.is_regular_file() || entry.path().extension() != ".txt") {
            continue;
        }

        std::ifstream file(entry.path());

        if (!file) {
            std::cerr << "Failed reading: " << entry.path() << "\n";
            continue;
        }

        std::stringstream buffer;
        buffer << file.rdbuf();

        std::string mission_name = entry.path().stem().string();

        // Creates raw string for the voicelines
        out << "    {\"" << mission_name << "\", R\"(\n";
        out << buffer.str();
        out << "\n)\"},\n";

        bundled_missions.push_back(mission_name);
    }

    out << "};\n";

    std::cout << "Bundled Missions: ";
    for (const std::string& mission : bundled_missions) {
        std::cout << mission << ", ";
    }

    std::cout << "\nFinished bundling voicelines.\n";

    return 0;
}
