#include "Config.hpp"
#include <fstream>

Config::Config() {
    LoadFromFile();
}

void Config::SaveToFile() {
    std::ofstream file("save.json");
    file << std::setw(4) << data << std::endl;
    file.close();
}

void Config::LoadFromFile() {
    std::ifstream file("save.json");
    file >> data;
    file.close();
}