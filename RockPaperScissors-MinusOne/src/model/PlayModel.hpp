#ifndef PLAY_MODEL
#define PLAY_MODEL

#include "HumanPlayer.hpp"
#include "EnemyPlayer.hpp"
#include "Revolver.hpp"
#include "GameResultCalculator.hpp"

struct PlayModel {
    HumanPlayer player;
    EnemyPlayer enemy;
    Revolver revolver;
    GameResultCalculator calculator;
};

#endif // PLAY_MODEL