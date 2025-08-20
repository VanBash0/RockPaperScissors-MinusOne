#ifndef MAIN_MENU_SCENE
#define MAIN_MENU_SCENE

#include "IScene.hpp"
#include "MainMenuModel.hpp"
#include "MenuController.hpp"
#include "Constants.hpp"

class MainMenuScene : public IScene {
public:
    SceneAction Update() override;
    void Render() override;
private:
    MainMenuModel model;
    MenuView view;
    MenuController controller;
    int selected = Constants::NOT_SELECTED;
};

#endif // MAIN_MENU_SCENE