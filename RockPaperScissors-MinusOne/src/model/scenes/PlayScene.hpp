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
    WAITING_AFTER_DRAW,
    SHOOTING,
    WAITING_AFTER_SHOOT_DRAW,
    WAITING_AFTER_WIN,
    WAITING_AFTER_LOSE,
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
    float waitTimer = 0;
    bool isWaiting = false;
};

#endif // PLAY_SCENE