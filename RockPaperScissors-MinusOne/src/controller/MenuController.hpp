#ifndef MENU_CONTROLLER
#define MENU_CONTROLLER

#include <vector>
#include "MenuModel.hpp"
#include "MenuView.hpp"

struct MenuAction {
    GameState targetState;
    int selectedIndex;
};

class MenuController {
public:
    MenuAction HandleInput(const std::vector<MenuItem>& menuItems, const MenuView& menuView, GameState baseState) const;
};

#endif // MENU_CONTROLLER