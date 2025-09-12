#include "EnemyPlayer.hpp"
#include <random>
#include "RandomIntGenerator.hpp"
#include "GameResultCalculator.hpp"

void EnemyPlayer::SetFigures() {
    switch (strategy) {
    case EnemyStrategy::RANDOM:
        figures[0] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
        figures[1] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
        break;
    case EnemyStrategy::CAREFUL:
    case EnemyStrategy::AGGRESSIVE:
        figures[0] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
        do {
            figures[1] = static_cast<Figure>(RandomIntGenerator::Next(1, 3));
        } while (figures[1] == figures[0]);
    }
}

void EnemyPlayer::DropFigure(std::vector<Figure> playerFigures) {
    switch (strategy) {
    case EnemyStrategy::RANDOM:
        figures[RandomIntGenerator::Next(0, 1)] = Figure::EMPTY;
        break;
    case EnemyStrategy::CAREFUL:
    case EnemyStrategy::AGGRESSIVE:
        std::vector<int> predictions;
        for (auto enemyFigure : figures) {
            int prediction = 0;
            for (auto playerFigure : playerFigures) {
                GameResult gameResult = GameResultCalculator::GetGameResult(enemyFigure, playerFigure);
                if (strategy == EnemyStrategy::CAREFUL) prediction += (gameResult == GameResult::LOSE) ? 0 : 2;
                else prediction += (gameResult == GameResult::DRAW) ? 1 : (gameResult == GameResult::WIN) ? 2 : 0;
            }
            predictions.push_back(prediction);
        }
        if (predictions[0] > predictions[1]) figures[1] = Figure::EMPTY;
        else if (predictions[1] > predictions[0]) figures[0] = Figure::EMPTY;
        else figures[RandomIntGenerator::Next(0, 1)] = Figure::EMPTY;
    }
}

void EnemyPlayer::SetStrategy(EnemyStrategy strategy) {
    this->strategy = strategy;
}