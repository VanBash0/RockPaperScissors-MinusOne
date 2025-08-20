#ifndef MENU_VIEW
#define MENU_VIEW

#include <vector>
#include "MenuModel.hpp"

class MenuView {
public:
    void Render(const std::vector<MenuItem>& menuItems, int selected) const;
};

#endif // MENU_VIEW