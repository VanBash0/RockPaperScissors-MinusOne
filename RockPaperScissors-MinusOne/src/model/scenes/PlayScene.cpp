#include "PlayScene.hpp"
#include "raylib.h"

SceneAction PlayScene::Update() {
    SceneAction action { GameState::PLAY, false };

    if (isWaiting) {
        waitTimer -= GetFrameTime();
        if (waitTimer <= 0) {
            isWaiting = false;
        }
        return action;
    }

    switch (state) {
    case PlaySceneState::LOADING_REVOLVER:
        controller.LoadRevolver(model, 6);
        state = PlaySceneState::CHOOSING_FIGURES;
        controller.ResetFigures(model);
        break;
    case PlaySceneState::CHOOSING_FIGURES: {
        view.SetText("Choose your figures");
        auto pressedKey = GetKeyPressed();
        if (controller.TryHandleChoosingFigures(model, pressedKey) && model.player.HandToPick() == NEITHER) {
            state = PlaySceneState::ENEMY_CHOOSING_FIGURES;
            view.SetText("");
        }
        break;
    }
    case PlaySceneState::ENEMY_CHOOSING_FIGURES:
        model.enemy.SetFigures();
        state = PlaySceneState::DROPPING_FIGURE;
        break;
    case PlaySceneState::DROPPING_FIGURE: {
        view.SetText("Pick one figure to leave");
        auto pressedKey = GetKeyPressed();
        if (controller.TryHandleDroppingFigure(model, pressedKey))
            state = PlaySceneState::ENEMY_DROPPING_FIGURE;
    } break;
    case PlaySceneState::ENEMY_DROPPING_FIGURE:
        model.enemy.DropFigure();
        state = PlaySceneState::CALCULATING_RESULT;
        break;
    case PlaySceneState::CALCULATING_RESULT:
        if (controller.IsGameEnded(model)) {
            state = PlaySceneState::SHOOTING;
        }
        else {
            view.SetText("Draw!");
            isWaiting = true;
            waitTimer = 2.0f;
            state = PlaySceneState::WAITING_AFTER_DRAW;
        }
        break;
    case PlaySceneState::WAITING_AFTER_DRAW:
        state = PlaySceneState::CHOOSING_FIGURES;
        controller.ResetFigures(model);
        break;
    case PlaySceneState::SHOOTING: {
        auto shootingResult = controller.TryShooting(model);
        switch (shootingResult) {
        case GameResult::DRAW:
            view.SetText("No bullet :(");
            isWaiting = true;
            waitTimer = 2.0f;
            state = PlaySceneState::WAITING_AFTER_SHOOT_DRAW;
            break;

        case GameResult::WIN:
            view.SetText("Your enemy is shot");
            isWaiting = true;
            waitTimer = 2.0f;
            state = PlaySceneState::WAITING_AFTER_WIN;
            break;

        case GameResult::LOSE:
            view.SetText("You are shot");
            isWaiting = true;
            waitTimer = 2.0f;
            state = PlaySceneState::WAITING_AFTER_LOSE;
            break;
        }
        break;
    }
    case PlaySceneState::WAITING_AFTER_SHOOT_DRAW:
        state = PlaySceneState::CHOOSING_FIGURES;
        controller.ResetFigures(model);
        view.SetText("Choose your figures");
        break;
    case PlaySceneState::WAITING_AFTER_WIN:
        state = PlaySceneState::WIN;
        break;
    case PlaySceneState::WAITING_AFTER_LOSE:
        state = PlaySceneState::LOSE;
        break;
    case PlaySceneState::WIN:
    case PlaySceneState::LOSE:
        if (controller.TryExitGame()) {
            action.isSceneChanged = true;
            action.targetState = GameState::MAIN_MENU;
            state = PlaySceneState::LOADING_REVOLVER;
            controller.ResetFigures(model);
        }
    }
    return action;
}

void PlayScene::Render() {
    view.Render(model.player.GetFigures(), model.enemy.GetFigures());
}