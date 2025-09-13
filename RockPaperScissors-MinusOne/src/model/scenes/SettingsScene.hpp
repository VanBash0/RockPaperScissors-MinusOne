#ifndef SETTINGS_SCENE
#define SETTINGS_SCENE

#include "IScene.hpp"
#include "Constants.hpp"
#include "MenuView.hpp"
#include "MenuController.hpp"
#include "SettingsModel.hpp"

enum SettingsSceneState {
    LOADING,
    IDLE
};

class SettingsScene : public IScene {
public:
    SceneAction Update() override;
    void Render() override;
private:
    SettingsModel model;
    MenuView view;
    MenuController controller;
    int selected = Constants::NOT_SELECTED;
    SettingsSceneState state = SettingsSceneState::LOADING;
};

#endif // SETTINGS_SCENE