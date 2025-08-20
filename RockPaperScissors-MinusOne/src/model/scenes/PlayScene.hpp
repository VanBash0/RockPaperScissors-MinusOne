#ifndef PLAY_SCENE
#define PLAY_SCENE

#include "IScene.hpp"

class PlayScene : public IScene {
public:
    SceneAction Update() override;
    void Render() override;
};

#endif // PLAY_SCENE