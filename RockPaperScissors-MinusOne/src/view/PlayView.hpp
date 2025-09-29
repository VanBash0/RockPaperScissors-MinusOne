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
    void SetText(const std::vector<std::string>& text);
private:
    Texture2D rockTexturePlayer;
    Texture2D paperTexturePlayer;
    Texture2D scissorsTexturePlayer;
    Texture2D rockTextureEnemy;
    Texture2D paperTextureEnemy;
    Texture2D scissorsTextureEnemy;
    std::vector<std::string> label;
    void PrintLabel();
};

#endif // PLAY_VIEW
