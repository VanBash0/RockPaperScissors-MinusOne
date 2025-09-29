#include "PlayView.hpp"
#include "Constants.hpp"

void PlayView::LoadAssets() {
    Image rockImg = LoadImage("assets/rock.png");
    Image paperImg = LoadImage("assets/paper.png");
    Image scissorsImg = LoadImage("assets/scissors.png");

    ImageResize(&rockImg, 200, 200);
    ImageResize(&paperImg, 200, 200);
    ImageResize(&scissorsImg, 200, 200);

    rockTexturePlayer = LoadTextureFromImage(rockImg);
    paperTexturePlayer = LoadTextureFromImage(paperImg);
    scissorsTexturePlayer = LoadTextureFromImage(scissorsImg);

    ImageFlipHorizontal(&rockImg);
    ImageFlipHorizontal(&paperImg);
    ImageFlipHorizontal(&scissorsImg);

    rockTextureEnemy = LoadTextureFromImage(rockImg);
    paperTextureEnemy = LoadTextureFromImage(paperImg);
    scissorsTextureEnemy = LoadTextureFromImage(scissorsImg);

    UnloadImage(rockImg);
    UnloadImage(paperImg);
    UnloadImage(scissorsImg);
}

void PlayView::UnloadAssets() {
    UnloadTexture(rockTexturePlayer);
    UnloadTexture(paperTexturePlayer);
    UnloadTexture(scissorsTexturePlayer);
    UnloadTexture(rockTextureEnemy);
    UnloadTexture(paperTextureEnemy);
    UnloadTexture(scissorsTextureEnemy);
}

void PlayView::Render(const std::vector<Figure>& playerFigures, const std::vector<Figure>& enemyFigures) {
    Texture2D texture;
    for (size_t i = 0; i < playerFigures.size(); ++i) {
        if (playerFigures[i] == Figure::EMPTY) continue;
        switch (playerFigures[i]) {
        case Figure::ROCK: texture = rockTexturePlayer; break;
        case Figure::PAPER: texture = paperTexturePlayer; break;
        case Figure::SCISSORS: texture = scissorsTexturePlayer; break;
        }
        DrawTexture(texture, 0, (Constants::SCREEN_HEIGHT / 3) * (i + 1) - 100, WHITE);
    }
    for (size_t i = 0; i < enemyFigures.size(); ++i) {
        if (enemyFigures[i] == Figure::EMPTY) continue;
        switch (enemyFigures[i]) {
        case Figure::ROCK: texture = rockTextureEnemy; break;
        case Figure::PAPER: texture = paperTextureEnemy; break;
        case Figure::SCISSORS: texture = scissorsTextureEnemy; break;
        }
        DrawTexture(texture, Constants::SCREEN_WIDTH - 200, (Constants::SCREEN_HEIGHT / 3) * (i + 1) - 100, WHITE);
    }
    PrintLabel();
}

void PlayView::PrintLabel() {
    int totalHeight = label.size() * Constants::FONT_SIZE +
        (label.size() - 1) * Constants::SPACING;
    int startY = (Constants::SCREEN_HEIGHT - totalHeight) / 2;

    for (size_t i = 0; i < label.size(); i++) {
        const char* text = label[i].c_str();
        int textWidth = MeasureText(text, Constants::FONT_SIZE);
        int x = (Constants::SCREEN_WIDTH - textWidth) / 2;
        int y = startY + i * (Constants::FONT_SIZE + Constants::SPACING);

        DrawText(text, x, y, Constants::FONT_SIZE, BLACK);
    }
}

PlayView::PlayView() {
    LoadAssets();
}

PlayView::~PlayView() {
    UnloadAssets();
}

void PlayView::SetText(const std::vector<std::string>& text) {
    label = text;
}