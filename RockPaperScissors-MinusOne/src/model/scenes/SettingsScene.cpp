#include "SettingsScene.hpp"
#include "raylib.h"
#include "Config.hpp"

SceneAction SettingsScene::Update() {
    switch (state) {
    case SettingsSceneState::LOADING:
        model.LoadFromConfig();
        state = SettingsSceneState::IDLE;
        return { GameState::SETTINGS, false };
    case SettingsSceneState::IDLE:
        auto menuItems = model.GetMenuItems();
        auto handleResult = controller.HandleInput(menuItems, view, GameState::SETTINGS);

        SceneAction action;
        action.targetState = handleResult.targetState;
        selected = handleResult.selectedIndex;
        bool isSceneChanged = (selected == Constants::NOT_SELECTED) ? false : true;
        if (isSceneChanged) {
            if (action.targetState == GameState::SETTINGS_CHANGED) {
                if (selected == 0) model.ChangeStrategy();
                if (selected == 1) model.ChangeBullets();
                if (selected == 2) model.ChangeSpin();
            }
            else {
                model.SaveToConfig();
                Config& config = Config::GetInstance();
                config.SaveToFile();
            }
        }
        action.isSceneChanged = action.targetState == GameState::MAIN_MENU;
        return action;
    }
}

void SettingsScene::Render() {
    auto menuItems = model.GetMenuItems();
    view.Render(menuItems, selected);
}