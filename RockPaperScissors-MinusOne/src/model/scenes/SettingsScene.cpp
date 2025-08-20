#include "SettingsScene.hpp"
#include "raylib.h"

SceneAction SettingsScene::Update() {
    SceneAction action{ GameState::SETTINGS, false };
    if (IsKeyPressed(KEY_E)) {
        action.isSceneChanged = true;
        action.targetState = GameState::MAIN_MENU;
    }
    return action;
}

void SettingsScene::Render() {
    DrawText("SETTINGS STATE", 10, 10, 20, BLACK);
}