#include "PlayScene.hpp"
#include "raylib.h"

SceneAction PlayScene::Update() {
    SceneAction action { GameState::PLAY, false };
    switch (state) {
    case PlaySceneStates::CHOOSING_FIGURES:
        auto pressedKey = GetKeyPressed();
        if (controller.TryHandleChoosingFigures(model, pressedKey))
            state = PlaySceneStates::ENEMY_CHOOSING_FIGURES;
        return action;
    case PlaySceneStates::ENEMY_CHOOSING_FIGURES:
        model.enemy.SetFigures();
        state = PlaySceneStates::DROPPING_FIGURE;
        return action;
    case PlaySceneStates::DROPPING_FIGURE:
        auto pressedKey = GetKeyPressed();
        if (controller.TryHandleDroppingFigure(model, pressedKey))
            state = PlaySceneStates::ENEMY_DROPPING_FIGURE;
        return action;
    case PlaySceneStates::ENEMY_DROPPING_FIGURE:
        model.enemy.DropFigure();
        state = PlaySceneStates::CALCULATING_RESULT;
        return action;
    case PlaySceneStates::CALCULATING_RESULT:
        auto gameResult = controller.GetGameResult(model);
        switch (gameResult) {
        case GameResult::DRAW:
            state = PlaySceneStates::CHOOSING_FIGURES;
            break;
        case GameR
        }
    }
    return action;
}

void PlayScene::Render() {
    DrawText("GAME STATE", 10, 10, 20, BLACK);
}