#include "PlayScene.hpp"
#include "raylib.h"
#include <map>

enum class Label {
    CHOOSE_FIGURES,
    EMPTY,
    PICK_FIGURE,
    DRAW,
    NO_BULLET,
    ENEMY_SHOT,
    YOU_SHOT
};

static std::unordered_map<Label, std::vector<std::string>> labelVector {
    { Label::CHOOSE_FIGURES, std::vector<std::string> { "Choose your figures:", "1 - Rock", "2 - Paper", "3 - Scissors" }},
    { Label::EMPTY, std::vector<std::string> { "" }},
    { Label::PICK_FIGURE, std::vector<std::string> { "Pick one figure to leave:", "Q - Left hand", "W - Right hand" }},
    { Label::DRAW, std::vector<std::string> { "Draw! Time to play again :)" }},
    { Label::NO_BULLET, std::vector<std::string> { "No bullet! Time to play again :)" }},
    { Label::ENEMY_SHOT, std::vector<std::string> { "Enemy is shot! You win! :)", "Press E to return to the main menu." }},
    { Label::YOU_SHOT, std::vector<std::string> { "You are shot! You lose! :)", "Press E to return to the main menu." }},
};

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
        controller.SetEnemyStrategy(model);
        controller.LoadRevolver(model);
        state = PlaySceneState::CHOOSING_FIGURES;
        controller.ResetFigures(model);
        break;
    case PlaySceneState::CHOOSING_FIGURES: {
        view.SetText(labelVector[Label::CHOOSE_FIGURES]);
        auto pressedKey = GetKeyPressed();
        if (controller.TryHandleChoosingFigures(model, pressedKey) && model.player.HandToPick() == NEITHER) {
            state = PlaySceneState::ENEMY_CHOOSING_FIGURES;
            view.SetText(labelVector[Label::EMPTY]);
        }
        break;
    }
    case PlaySceneState::ENEMY_CHOOSING_FIGURES:
        model.enemy.SetFigures();
        state = PlaySceneState::DROPPING_FIGURE;
        break;
    case PlaySceneState::DROPPING_FIGURE: {
        view.SetText(labelVector[Label::PICK_FIGURE]);
        auto pressedKey = GetKeyPressed();
        auto playerFigures = model.player.GetFigures();
        if (controller.TryHandleDroppingFigure(model, pressedKey)) {
            model.enemy.DropFigure(playerFigures);
            state = PlaySceneState::CALCULATING_RESULT;
        }
    } break;
    case PlaySceneState::CALCULATING_RESULT:
        if (controller.IsGameEnded(model)) {
            state = PlaySceneState::SHOOTING;
        }
        else {
            view.SetText(labelVector[Label::DRAW]);
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
            view.SetText(labelVector[Label::NO_BULLET]);
            isWaiting = true;
            waitTimer = 2.0f;
            state = PlaySceneState::WAITING_AFTER_SHOOT_DRAW;
            break;

        case GameResult::WIN:
            view.SetText(labelVector[Label::ENEMY_SHOT]);
            isWaiting = true;
            waitTimer = 2.0f;
            state = PlaySceneState::WAITING_AFTER_WIN;
            break;

        case GameResult::LOSE:
            view.SetText(labelVector[Label::YOU_SHOT]);
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
        view.SetText(labelVector[Label::CHOOSE_FIGURES]);
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