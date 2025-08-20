#ifndef PLAY_SCENE
#define PLAY_SCENE

#include "IScene.hpp"
#include "PlayModel.hpp"
#include "PlayController.hpp"

enum class PlaySceneStates {
    CHOOSING_FIGURES,
    ENEMY_CHOOSING_FIGURES,
    DROPPING_FIGURE,
    ENEMY_DROPPING_FIGURE,
    CALCULATING_RESULT,
    SHOOTING
};

class PlayScene : public IScene {
public:
    SceneAction Update() override;
    void Render() override;
private:
    PlayModel model;
    PlayController controller;
    PlaySceneStates state;
};

#endif // PLAY_SCENE