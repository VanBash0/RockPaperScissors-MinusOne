#include "PlayView.hpp"
#include "Constants.hpp"

void PlayView::LoadAssets() {
    Image rockImg = LoadImage("assets/rock.png");
    Image paperImg = LoadImage("assets/paper.png");
    Image scissorsImg = LoadImage("assets/scissors.png");

    ImageResize(&rockImg, 200, 200);
    ImageResize(&paperImg, 200, 200);
    ImageResize(&scissorsImg, 200, 200);

    ImageRotate(&rockImg, 45);
    ImageRotate(&paperImg, 45);
    ImageRotate(&scissorsImg, 45);

    rockTexturePlayerRight = LoadTextureFromImage(rockImg);
    paperTexturePlayerRight = LoadTextureFromImage(paperImg);
    scissorsTexturePlayerRight = LoadTextureFromImage(scissorsImg);

    ImageFlipVertical(&rockImg);
    ImageFlipVertical(&paperImg);
    ImageFlipVertical(&scissorsImg);

    rockTexturePlayerLeft = LoadTextureFromImage(rockImg);
    paperTexturePlayerLeft = LoadTextureFromImage(paperImg);
    scissorsTexturePlayerLeft = LoadTextureFromImage(scissorsImg);

    ImageFlipHorizontal(&rockImg);
    ImageFlipHorizontal(&paperImg);
    ImageFlipHorizontal(&scissorsImg);

    rockTextureEnemyRight = LoadTextureFromImage(rockImg);
    paperTextureEnemyRight = LoadTextureFromImage(paperImg);
    scissorsTextureEnemyRight = LoadTextureFromImage(scissorsImg);

    ImageFlipVertical(&rockImg);
    ImageFlipVertical(&paperImg);
    ImageFlipVertical(&scissorsImg);

    rockTextureEnemyLeft = LoadTextureFromImage(rockImg);
    paperTextureEnemyLeft = LoadTextureFromImage(paperImg);
    scissorsTextureEnemyLeft = LoadTextureFromImage(scissorsImg);

    UnloadImage(rockImg);
    UnloadImage(paperImg);
    UnloadImage(scissorsImg);
}

void PlayView::UnloadAssets() {
    UnloadTexture(rockTexturePlayerLeft);
    UnloadTexture(rockTexturePlayerRight);
    UnloadTexture(paperTexturePlayerLeft);
    UnloadTexture(paperTexturePlayerRight);
    UnloadTexture(scissorsTexturePlayerLeft);
    UnloadTexture(scissorsTexturePlayerRight);
    UnloadTexture(rockTextureEnemyLeft);
    UnloadTexture(rockTextureEnemyRight);
    UnloadTexture(paperTextureEnemyLeft);
    UnloadTexture(paperTextureEnemyRight);
    UnloadTexture(scissorsTextureEnemyLeft);
    UnloadTexture(scissorsTextureEnemyRight);
}

void PlayView::Render(const std::vector<Figure>& playerFigures, const std::vector<Figure>& enemyFigures) {
    Texture2D texture;
    for (size_t i = 0; i < playerFigures.size(); ++i) {
        if (playerFigures[i] == Figure::EMPTY) continue;
        switch (playerFigures[i]) {
        case Figure::ROCK: texture = (i == 0) ? rockTexturePlayerLeft : rockTexturePlayerRight; break;
        case Figure::PAPER: texture = (i == 0) ? paperTexturePlayerLeft : paperTexturePlayerRight; break;
        case Figure::SCISSORS: texture = (i == 0) ? scissorsTexturePlayerLeft : scissorsTexturePlayerRight; break;
        }
        DrawTexture(texture, -50, (Constants::SCREEN_HEIGHT / 3) * (i + 1) - 100, WHITE);
    }
    for (size_t i = 0; i < enemyFigures.size(); ++i) {
        if (enemyFigures[i] == Figure::EMPTY) continue;
        switch (enemyFigures[i]) {
        case Figure::ROCK: texture = (i == 0) ? rockTextureEnemyRight : rockTextureEnemyLeft; break;
        case Figure::PAPER: texture = (i == 0) ? paperTextureEnemyRight : paperTextureEnemyLeft; break;
        case Figure::SCISSORS: texture = (i == 0) ? scissorsTextureEnemyRight : scissorsTextureEnemyLeft; break;
        }
        DrawTexture(texture, Constants::SCREEN_WIDTH - 225, (Constants::SCREEN_HEIGHT / 3) * (i + 1) - 100, WHITE);
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