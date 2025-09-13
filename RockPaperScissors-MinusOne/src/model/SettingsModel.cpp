#include "SettingsModel.hpp"
#include "Config.hpp"
#include "Constants.hpp"
#include <iostream>

void SettingsModel::LoadFromConfig() {
    Config& config = Config::GetInstance();
    enemyStrategy = config.Get<int>(Constants::ENEMY_STRATEGY);
    bullets = config.Get<int>(Constants::BULLETS);
}

std::vector<MenuItem> SettingsModel::GetMenuItems() {
    std::string enemyStrategyStr = "Enemy: " + GetStrategyName();
    const char* enemyStrategy = enemyStrategyStr.c_str();
    std::string bulletsStr = "Bullets: " + std::to_string(GetBullets());
    const char* bullets = bulletsStr.c_str();
    std::cout << enemyStrategyStr << " " << bulletsStr << "\n";
    return {
            { enemyStrategy, GameState::SETTINGS_CHANGED },
            { bullets, GameState::SETTINGS_CHANGED },
            { "Main Menu", GameState::MAIN_MENU }
    };
}

std::string SettingsModel::GetStrategyName() {
    switch (enemyStrategy) {
    case 0: return "Random";
    case 1: return "Careful";
    case 2: return "Aggressive";
    }
}

void SettingsModel::SaveToConfig() {
    Config& config = Config::GetInstance();
    config.Set(Constants::ENEMY_STRATEGY, enemyStrategy);
    config.Set(Constants::BULLETS, bullets);
}