#include "raylib.h"
#include "GameStates.hpp"
#include "Constants.hpp"
#include "MainMenuModel.hpp"
#include "MenuView.hpp"
#include "MenuController.hpp"

int main() {
    InitWindow(Constants::SCREEN_WIDTH, Constants::SCREEN_HEIGHT, Constants::APP_NAME);
    SetTargetFPS(60);
    
    GameState currentState = GameState::MAIN_MENU;
    MainMenuModel mainMenuModel;
    MenuView mainMenuView;
    MenuController mainMenuController;
    int selected = Constants::NOT_SELECTED;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        switch (currentState) {
        case GameState::MAIN_MENU: {
            auto menuItems = mainMenuModel.GetMenuItems();
            mainMenuView.Render(menuItems, selected);
            auto handleResult = mainMenuController.HandleMouse(menuItems, mainMenuView);
            GameState nextState = handleResult.first;
            selected = handleResult.second;

            if (nextState == GameState::EXIT) {
                EndDrawing();
                return 0;
            }
            currentState = nextState;
            break;
        }
        case GameState::PLAY:
            // Логика игры
            DrawText("GAME STATE", 10, 10, 20, BLACK);
            break;
        case GameState::SETTINGS:
            // Логика настроек
            DrawText("SETTINGS STATE", 10, 10, 20, BLACK);
            break;
        case GameState::STATS:
            // Логика статистики
            DrawText("STATS STATE", 10, 10, 20, BLACK);
            break;
        default:
            break;
        }
        EndDrawing();
    }
}