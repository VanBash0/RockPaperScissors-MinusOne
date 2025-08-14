#ifndef GAME_RESULT_CALCULATOR
#define GAME_RESULT_CALCULATOR

#include "Figures.hpp"

enum class GameResult {
    INVALID,
    WIN,
    LOSE,
    DRAW
};

class GameResultCalculator {
public:
    static GameResult GetGameResult(Figure a, Figure b);
};

#endif // GAME_RESULT_CALCULATOR