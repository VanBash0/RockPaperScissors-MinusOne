#include "MenuModel.hpp"

class MainMenuModel : public MenuModel {
public:
    std::vector<MenuItem> GetMenuItems() const override {
        return {
            { "Play", GameState::PLAY },
            { "Statistics", GameState::STATS },
            { "Settings", GameState::SETTINGS },
            { "Exit", GameState::EXIT }
        };
    }
};