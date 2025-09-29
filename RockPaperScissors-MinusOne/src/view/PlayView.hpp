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
    Texture2D rockTexturePlayerLeft;
    Texture2D rockTexturePlayerRight;
    Texture2D paperTexturePlayerLeft;
    Texture2D paperTexturePlayerRight;
    Texture2D scissorsTexturePlayerLeft;
    Texture2D scissorsTexturePlayerRight;
    Texture2D rockTextureEnemyLeft;
    Texture2D rockTextureEnemyRight;
    Texture2D paperTextureEnemyLeft;
    Texture2D paperTextureEnemyRight;
    Texture2D scissorsTextureEnemyLeft;
    Texture2D scissorsTextureEnemyRight;
    std::vector<std::string> label;
    void PrintLabel();
};

#endif // PLAY_VIEW
