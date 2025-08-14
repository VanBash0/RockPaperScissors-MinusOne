#include "Revolver.hpp"

#include "RandomIntGenerator.hpp"

#include <algorithm>
#include <array>

bool Revolver::fire() {
    bool result = chambers[currIndex];
    currIndex = (currIndex + 1) % 6;
    return result;
}

void Revolver::loadChambers(int n) {
    std::fill(chambers, chambers + 6, false);
    std::array<int, 6> indices = { 0, 1, 2, 3, 4, 5 };
    std::shuffle(indices.begin(), indices.end(), RandomIntGenerator::getGenerator());
    for (int i = 0; i < n; ++i) {
        chambers[indices[i]] = true;
    }
}