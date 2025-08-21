#ifndef PLAY_VIEW
#define PLAY_VIEW

#include "raylib.h"
#include "Figures.hpp"
#include <vector>
#include <string>

class PlayView {
public:
    void LoadAssets();
    void UnloadAssets();
    void Render(const std::vector<Figure>& playerFigures, const std::vector<Figure>& enemyFigures);
    PlayView();
    ~PlayView();
private:
    Texture2D rockTexturePlayer;
    Texture2D paperTexturePlayer;
    Texture2D scissorsTexturePlayer;
    Texture2D rockTextureEnemy;
    Texture2D paperTextureEnemy;
    Texture2D scissorsTextureEnemy;
};

#endif // PLAY_VIEW
