#ifndef ISCENE
#define ISCENE

#include <utility>
#include "GameStates.hpp"

struct SceneAction {
    GameState targetState;
    bool isSceneChanged;
};

class IScene {
public:
    virtual ~IScene() = default;
    virtual SceneAction Update() = 0;
    virtual void Render() = 0;
};

#endif // ISCENE