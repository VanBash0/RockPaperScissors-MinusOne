#ifndef MAIN_MENU_MODEL
#define MAIN_MENU_MODEL

#include <vector>
#include "GameStates.hpp"

struct MenuItem {
    const char* text;
    GameState targetState;
};

class MenuModel {
public:
    virtual std::vector<MenuItem> GetMenuItems() const = 0;
};

#endif