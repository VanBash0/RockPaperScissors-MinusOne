#include "raylib.h"
#include "GameStates.hpp"
#include "Constants.hpp"
#include "SceneManager.hpp"
#include "MainMenuScene.hpp"
#include "PlayScene.hpp"
#include "SettingsScene.hpp"
#include "StatsScene.hpp"

int main() {
    InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, Constants::APP_NAME);
    SetTargetFPS(60);
    
    SceneManager sceneManager;
    sceneManager.AddScene(GameState::MAIN_MENU, std::make_unique<MainMenuScene>());
    sceneManager.AddScene(GameState::PLAY, std::make_unique<PlayScene>());
    sceneManager.AddScene(GameState::SETTINGS, std::make_unique<SettingsScene>());
    sceneManager.AddScene(GameState::STATS, std::make_unique<StatsScene>());

    sceneManager.SetScene(GameState::MAIN_MENU);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        sceneManager.Update();
        if (sceneManager.ShouldExit()) return 0;
        sceneManager.Render();

        EndDrawing();
    }
}