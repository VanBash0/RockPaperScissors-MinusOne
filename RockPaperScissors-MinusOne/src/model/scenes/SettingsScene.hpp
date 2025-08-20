#ifndef SETTINGS_SCENE
#define SETTINGS_SCENE

#include "IScene.hpp"

class SettingsScene : public IScene {
public:
    SceneAction Update() override;
    void Render() override;
};

#endif // SETTINGS_SCENE