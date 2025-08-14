#include "EnemyPlayer.hpp"
#include <random>
#include "RandomIntGenerator.hpp"

void EnemyPlayer::SetFigures() {
    figures[0] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
    figures[1] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
}

void EnemyPlayer::DropFigure() {
    figures[RandomIntGenerator::Next(0, 1)] = Figure::EMPTY;
}