#include "MenuController.hpp"
#include "raylib.h"
#include "Constants.hpp"

std::pair<GameState, int> MenuController::HandleMouse(const std::vector<MenuItem>& menuItems, const MenuView& menuView) const {
    int selected = -1;
    Vector2 mousePos = GetMousePosition();
    int numberOfItems = menuItems.size();
    int totalHeight = menuItems.size() * (Constants::BUTTON_HEIGHT + Constants::SPACING) - Constants::SPACING;
    int startY = (Constants::SCREEN_HEIGHT - totalHeight) / 2;

    for (auto i = 0; i < numberOfItems; ++i) {
        int buttonY = startY + i * (Constants::BUTTON_HEIGHT + Constants::SPACING);
        Rectangle collider = {
            (float)(Constants::SCREEN_WIDTH - Constants::BUTTON_WIDTH) / 2,
            (float)buttonY,
            (float)Constants::BUTTON_WIDTH,
            (float)Constants::BUTTON_HEIGHT
        };

        if (CheckCollisionPointRec(mousePos, collider)) {
            selected = i;
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
                return std::make_pair(menuItems[i].targetState, selected);
        }
    }
    return std::make_pair(GameState::MAIN_MENU, selected);
}