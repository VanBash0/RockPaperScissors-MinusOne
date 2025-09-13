#include "MainMenuScene.hpp"
#include "Constants.hpp"

SceneAction MainMenuScene::Update() {
    auto menuItems = model.GetMenuItems();
    auto handleResult = controller.HandleInput(menuItems, view, GameState::MAIN_MENU);

    SceneAction action;
    action.targetState = handleResult.targetState;
    selected = handleResult.selectedIndex;
    action.isSceneChanged = (selected == Constants::NOT_SELECTED) ? false : true;
    return action;
}

void MainMenuScene::Render() {
    auto menuItems = model.GetMenuItems();
    view.Render(menuItems, selected);
}