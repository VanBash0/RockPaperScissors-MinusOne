#include "SceneManager.hpp"

void SceneManager::AddScene(GameState state, std::unique_ptr<IScene> scene) {
    scenes[state] = std::move(scene);
}

void SceneManager::SetScene(GameState state) {
    currentScene = (state != GameState::EXIT) ? scenes[state].get() : nullptr;
}

void SceneManager::Update() {
    if (!currentScene) return;
    auto action = currentScene->Update();
    if (action.isSceneChanged)
        SetScene(action.targetState);
}

void SceneManager::Render() {
    if (currentScene) currentScene->Render();
}

bool SceneManager::ShouldExit() {
    return !currentScene;
}