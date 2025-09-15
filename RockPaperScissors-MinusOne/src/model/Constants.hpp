#ifndef CONSTANTS
#define CONSTANTS

#include <string>

namespace Constants {
    inline constexpr int SCREEN_WIDTH = 800;
    inline constexpr int SCREEN_HEIGHT = 600;
    inline constexpr int BUTTON_WIDTH = 240;
    inline constexpr int BUTTON_HEIGHT = 60;
    inline constexpr int SPACING = 20;
    inline constexpr int FONT_SIZE = 20;
    inline const char *APP_NAME = "Rock, Paper, Scissors, Minus One";
    inline constexpr int NOT_SELECTED = -1;
    inline const std::string& ENEMY_STRATEGY = "enemy_strategy";
    inline const std::string& BULLETS = "bullets";
    inline const std::string& REVOLVER_SPIN = "revolver_spin";
}

#endif // CONSTANTS