#include "Config.hpp"
#include <fstream>

Config::Config() {
    LoadFromFile();
}

void Config::SaveToFile() {
    std::ofstream output_file("assets/save.json");
    output_file << std::setw(4) << data;
    output_file.close();
}

void Config::LoadFromFile() {
    std::ifstream input_file("assets/save.json");
    data = nlohmann::json::parse(input_file);
    input_file.close();
}