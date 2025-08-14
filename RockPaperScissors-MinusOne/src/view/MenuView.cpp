#include "MenuView.hpp"
#include "raylib.h"
#include "Constants.hpp"

void MenuView::Render(const std::vector<MenuItem>& menuItems, int selected) const {
    int numberOfItems = menuItems.size();
    int totalHeight = numberOfItems * (Constants::BUTTON_HEIGHT + Constants::SPACING) - Constants::SPACING;
    int startY = (Constants::SCREEN_HEIGHT - totalHeight) / 2;

    for (auto i = 0; i < numberOfItems; ++i) {
        int btnX = (Constants::SCREEN_WIDTH - Constants::BUTTON_WIDTH) / 2;
        int btnY = startY + i * (Constants::BUTTON_HEIGHT + Constants::SPACING);
        Color bgColor = (selected == i) ? Fade(LIGHTGRAY, 0.8f) : GRAY;
        DrawRectangle(btnX, btnY, Constants::BUTTON_WIDTH, Constants::BUTTON_HEIGHT, bgColor);
        DrawRectangleLines(btnX, btnY, Constants::BUTTON_WIDTH, Constants::BUTTON_HEIGHT, DARKGRAY);
        DrawText(
            menuItems[i].text,
            (Constants::SCREEN_WIDTH - MeasureText(menuItems[i].text, Constants::FONT_SIZE)) / 2,
            btnY + (Constants::BUTTON_HEIGHT - Constants::FONT_SIZE) / 2,
            Constants::FONT_SIZE,
            BLACK
        );
    }
}