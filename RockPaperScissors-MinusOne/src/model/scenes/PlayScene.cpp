#include "PlayScene.hpp"
#include "raylib.h"

SceneAction PlayScene::Update() {
    SceneAction action { GameState::PLAY, false };
    if (IsKeyPressed(KEY_E)) {
        action.isSceneChanged = true;
        action.targetState = GameState::MAIN_MENU;
    }
    return action;
}

void PlayScene::Render() {
    DrawText("GAME STATE", 10, 10, 20, BLACK);
}