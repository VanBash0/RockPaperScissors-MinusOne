#ifndef STATS_SCENE
#define STATS_SCENE

#include "IScene.hpp"

class StatsScene : public IScene {
public:
    SceneAction Update() override;
    void Render() override;
};

#endif // STATS_SCENE