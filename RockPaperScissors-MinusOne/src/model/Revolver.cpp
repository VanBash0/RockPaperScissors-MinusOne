#include "Revolver.hpp"
#include <algorithm>
#include <array>
#include "RandomIntGenerator.hpp"

bool Revolver::Fire() {
    bool hasBullet = (chambers >> currIndex) & 1;
    if (hasBullet) chambers &= ~(1 << currIndex);
    currIndex = (currIndex + 1) % 6;
    if (ifSpins) LoadChambers(std::_Popcount(chambers));
    return hasBullet;
}

void Revolver::LoadChambers(int n) {
    chambers = 0;
    currIndex = 0;
    std::array<int, 6> indices = { 0, 1, 2, 3, 4, 5 };
    std::shuffle(indices.begin(), indices.end(), RandomIntGenerator::GetGenerator());
    for (int i = 0; i < n; ++i) {
        chambers |= (1 << indices[i]);
    }
}