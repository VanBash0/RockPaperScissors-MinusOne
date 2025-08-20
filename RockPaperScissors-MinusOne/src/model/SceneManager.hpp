#ifndef SCENE_MANAGER
#define SCENE_MANAGER

#include <unordered_map>
#include <memory>
#include "IScene.hpp"

class SceneManager {
public:
    void AddScene(GameState state, std::unique_ptr<IScene> scene);
    void SetScene(GameState state);
    void Update();
    void Render();
    bool ShouldExit();
private:
    std::unordered_map<GameState, std::unique_ptr<IScene>> scenes;
    IScene* currentScene = nullptr;
};

#endif // SCENE_MANAGER