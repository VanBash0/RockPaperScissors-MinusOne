#include "GameResultCalculator.hpp"

GameResult GameResultCalculator::GetGameResult(Figure a, Figure b) {
    if (a == Figure::EMPTY || b == Figure::EMPTY) {
        return GameResult::INVALID;
    }

    if (a == b) {
        return GameResult::DRAW;
    }

    if ((a == Figure::ROCK && b == Figure::SCISSORS) ||
        (a == Figure::SCISSORS && b == Figure::PAPER) ||
        (a == Figure::PAPER && b == Figure::ROCK)) {
            return GameResult::WIN;
        }

    return GameResult::LOSE;
}