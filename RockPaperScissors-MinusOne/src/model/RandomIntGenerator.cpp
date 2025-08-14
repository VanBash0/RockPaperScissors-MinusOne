#include "RandomIntGenerator.hpp"

std::mt19937& RandomIntGenerator::getGenerator() {
    static std::mt19937 gen(std::random_device{}());
    return gen;
}

int RandomIntGenerator::Next(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(getGenerator());
}