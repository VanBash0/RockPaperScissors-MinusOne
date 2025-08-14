#include "Revolver.hpp"

#include "RandomIntGenerator.hpp"

#include <algorithm>
#include <array>

bool Revolver::fire() {
    bool hasBullet = (chambers >> currIndex) & 1;
    if (hasBullet) chambers &= ~(1 << currIndex);
    currIndex = (currIndex + 1) % 6;
    return hasBullet;
}

void Revolver::loadChambers(int n) {
    chambers = 0;
    std::array<int, 6> indices = { 0, 1, 2, 3, 4, 5 };
    std::shuffle(indices.begin(), indices.end(), RandomIntGenerator::getGenerator());
    for (int i = 0; i < n; ++i) {
        chambers |= (1 << indices[i]);
    }
}