#include "EnemyPlayer.hpp"
#include <random>
#include "RandomIntGenerator.hpp"

void EnemyPlayer::SetFigures() {
    switch (strategy) {
    case EnemyStrategy::Random:
        figures[0] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
        figures[1] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
        break;
    case EnemyStrategy::Careful:
    case EnemyStrategy::Aggressive:
        figures[0] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
        do {
            figures[1] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
        } while (figures[1] == figures[0]);
    }
}

void EnemyPlayer::DropFigure() {
    figures[RandomIntGenerator::Next(0, 1)] = Figure::Empty;
}

void EnemyPlayer::SetStrategy(EnemyStrategy strategy) {
    this->strategy = strategy;
}