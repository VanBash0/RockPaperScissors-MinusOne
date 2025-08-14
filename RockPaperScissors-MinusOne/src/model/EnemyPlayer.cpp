#include "EnemyPlayer.hpp"
#include "RandomIntGenerator.hpp"

#include <random>

void EnemyPlayer::setFigures() {
    figures[0] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
    figures[1] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
}

void EnemyPlayer::dropFigure() {
    figures[RandomIntGenerator::Next(0, 1)] = Figure::EMPTY;
}