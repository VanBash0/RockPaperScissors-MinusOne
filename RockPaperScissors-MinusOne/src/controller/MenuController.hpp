#ifndef MENU_CONTROLLER
#define MENU_CONTROLLER

#include <vector>
#include "MenuModel.hpp"
#include "MenuView.hpp"

class MenuController {
public:
    std::pair<GameState, int> HandleMouse(const std::vector<MenuItem>& menuItems, const MenuView& menuView) const;
};

#endif