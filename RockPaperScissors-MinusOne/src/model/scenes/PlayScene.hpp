#ifndef PLAY_SCENE
#define PLAY_SCENE

#include "IScene.hpp"
#include "PlayModel.hpp"
#include "PlayController.hpp"
#include "PlayView.hpp"

enum class PlaySceneState {
    LOADING_REVOLVER,
    CHOOSING_FIGURES,
    ENEMY_CHOOSING_FIGURES,
    DROPPING_FIGURE,
    ENEMY_DROPPING_FIGURE,
    CALCULATING_RESULT,
    SHOOTING,
    WIN,
    LOSE,
    LABEL
};

class PlayScene : public IScene {
public:
    SceneAction Update() override;
    void Render() override;
private:
    PlayView view;
    PlayModel model;
    PlayController controller;
    PlaySceneState state = PlaySceneState::LOADING_REVOLVER;
};

#endif // PLAY_SCENE