#include "PlayController.hpp"
#include "raylib.h"
#include "Config.hpp"
#include "Constants.hpp"

bool PlayController::TryHandleChoosingFigures(PlayModel& model, int pressedKey) {
    if (!(pressedKey == KEY_ONE) && !(pressedKey == KEY_TWO) && !(pressedKey == KEY_THREE)) return false;
    auto handToPick = model.player.HandToPick();
    model.player.SetFigure(keyToFigure.at(pressedKey), handToPick);
    return true;
}

bool PlayController::TryHandleDroppingFigure(PlayModel& model, int pressedKey) {
    switch (pressedKey) {
    case KEY_Q:
        model.player.DropFigure(Hand::RIGHT);
        return true;
    case KEY_W:
        model.player.DropFigure(Hand::LEFT);
        return true;
    default:
        return false;
    }
}

bool PlayController::IsGameEnded(PlayModel& model) {
    auto playerChoice = model.player.GetFinalFigure();
    auto enemyChoice = model.enemy.GetFinalFigure();
    auto gameResult = model.calculator.GetGameResult(playerChoice, enemyChoice);
    if (gameResult == GameResult::DRAW) return false;
    model.playerWinsInRound = (gameResult == GameResult::WIN);
    return true;
}

void PlayController::ResetFigures(PlayModel& model) {
    model.player.ResetFigures();
    model.enemy.ResetFigures();
}

GameResult PlayController::TryShooting(PlayModel& model) {
    bool isShotDone = model.revolver.Fire();
    if (!isShotDone) return GameResult::DRAW;
    return (model.playerWinsInRound) ? GameResult::WIN : GameResult::LOSE;
}

bool PlayController::TryExitGame() {
    return (IsKeyPressed(KEY_E));
}

void PlayController::LoadRevolver(PlayModel& model, int bullets) {
    model.revolver.LoadChambers(bullets);
}

void PlayController::SetEnemyStrategy(PlayModel& model) {
    Config& config = Config::GetInstance();
    int strategy = config.Get<int>(Constants::ENEMY_STRATEGY);
    model.enemy.SetStrategy(static_cast<EnemyStrategy>(strategy));
}