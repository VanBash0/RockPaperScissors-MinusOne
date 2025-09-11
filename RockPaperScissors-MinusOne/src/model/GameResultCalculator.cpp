#include "GameResultCalculator.hpp"

GameResult GameResultCalculator::GetGameResult(Figure a, Figure b) {
    if (a == Figure::Empty || b == Figure::Empty) {
        return GameResult::INVALID;
    }

    if (a == b) {
        return GameResult::DRAW;
    }

    if ((a == Figure::Rock && b == Figure::Scissors) ||
        (a == Figure::Scissors && b == Figure::Paper) ||
        (a == Figure::Paper && b == Figure::Rock)) {
            return GameResult::WIN;
        }

    return GameResult::LOSE;
}