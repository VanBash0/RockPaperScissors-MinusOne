#include "PlayController.hpp"
#include "raylib.h"

bool PlayController::TryHandleChoosingFigures(PlayModel& model, int pressedKey) {
    if (!(pressedKey == KEY_ONE) && !(pressedKey == KEY_TWO) && (pressedKey == KEY_THREE)) return false;
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

GameResult PlayController::GetGameResult(PlayModel& model) {
    auto playerChoice = model.player.GetFinalFigure();
    auto enemyChoice = model.enemy.GetFinalFigure();
    return model.calculator.GetGameResult(playerChoice, enemyChoice);
}

void PlayController::ResetFigures(PlayModel& model) {
    model.player.ResetFigures();
    model.enemy.ResetFigures();
}