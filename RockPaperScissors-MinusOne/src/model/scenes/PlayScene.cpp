#include "PlayScene.hpp"
#include "raylib.h"

SceneAction PlayScene::Update() {
    SceneAction action { GameState::PLAY, false };
    switch (state) {
    case PlaySceneState::LOADING_REVOLVER:
        controller.LoadRevolver(model, 6);
        state = PlaySceneState::CHOOSING_FIGURES;
        controller.ResetFigures(model);
        break;
    case PlaySceneState::CHOOSING_FIGURES: {
        auto pressedKey = GetKeyPressed();
        if (controller.TryHandleChoosingFigures(model, pressedKey) && model.player.HandToPick() == NEITHER) {
            state = PlaySceneState::ENEMY_CHOOSING_FIGURES;
        }
        break;
    }
    case PlaySceneState::ENEMY_CHOOSING_FIGURES:
        model.enemy.SetFigures();
        state = PlaySceneState::DROPPING_FIGURE;
        break;
    case PlaySceneState::DROPPING_FIGURE: {
        auto pressedKey = GetKeyPressed();
        if (controller.TryHandleDroppingFigure(model, pressedKey))
            state = PlaySceneState::ENEMY_DROPPING_FIGURE;
        break;
    }
    case PlaySceneState::ENEMY_DROPPING_FIGURE:
        model.enemy.DropFigure();
        state = PlaySceneState::CALCULATING_RESULT;
        break;
    case PlaySceneState::CALCULATING_RESULT:
        if (controller.IsGameEnded(model)) {
            state = PlaySceneState::SHOOTING;
        } else {
            state = PlaySceneState::CHOOSING_FIGURES;
            controller.ResetFigures(model);
        }
        break;
    case PlaySceneState::SHOOTING: {
        auto shootingResult = controller.TryShooting(model);
        switch (shootingResult) {
        case GameResult::DRAW:
            state = PlaySceneState::CHOOSING_FIGURES;
            controller.ResetFigures(model);
            break;
        case GameResult::WIN:
            state = PlaySceneState::WIN;
            break;
        case GameResult::LOSE:
            state = PlaySceneState::LOSE;
            break;
        }
        break;
    }
    case PlaySceneState::WIN:
    case PlaySceneState::LOSE:
        if (controller.TryExitGame()) {
            action.isSceneChanged = true;
            action.targetState = GameState::MAIN_MENU;
            state = PlaySceneState::LOADING_REVOLVER;
        }
    }
    return action;
}

void PlayScene::Render() {
    view.Render(model.player.GetFigures(), model.enemy.GetFigures());
}