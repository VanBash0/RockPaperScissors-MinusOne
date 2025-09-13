#include "StatsScene.hpp"
#include "raylib.h"

SceneAction StatsScene::Update() {

    SceneAction action{ GameState::STATS, false };
    if (IsKeyPressed(KEY_E)) {
        action.isSceneChanged = true;
        action.targetState = GameState::MAIN_MENU;
    }
    return action;
}

void StatsScene::Render() {
    DrawText("STATS STATE", 10, 10, 20, BLACK);
}