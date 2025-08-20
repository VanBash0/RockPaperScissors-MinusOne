#include "MenuController.hpp"
#include "raylib.h"
#include "Constants.hpp"

MenuAction MenuController::HandleInput(const std::vector<MenuItem>& menuItems, const MenuView& menuView) const {
    int selected = Constants::NOT_SELECTED;
    Vector2 mousePos = GetMousePosition();
    size_t numberOfItems = menuItems.size();
    size_t totalHeight = menuItems.size() * (Constants::BUTTON_HEIGHT + Constants::SPACING) - Constants::SPACING;
    int startY = (Constants::SCREEN_HEIGHT - totalHeight) / 2;

    MenuAction action;
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
            if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
                action.targetState = menuItems[i].targetState;
                action.selectedIndex = selected;
                return action;
            }
        }
    }
    action.targetState = GameState::MAIN_MENU;
    action.selectedIndex = selected;
    return action;
}