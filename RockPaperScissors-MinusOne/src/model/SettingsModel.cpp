#include "SettingsModel.hpp"
#include "Config.hpp"
#include "Constants.hpp"
#include <iostream>

void SettingsModel::ChangeSpin() {
    revolverSpin = !revolverSpin;
    revolverSpinStr = "Revolver: " + GetRevolverSpin();
}

void SettingsModel::ChangeStrategy() {
    enemyStrategy = (enemyStrategy + 1) % 3;
    enemyStrategyStr = "Enemy: " + GetStrategyName();
}

void SettingsModel::ChangeBullets() {
    bullets = (bullets + 1) % 7;
    bulletsStr = "Bullets: " + std::to_string(GetBullets());
}

void SettingsModel::LoadFromConfig() {
    Config& config = Config::GetInstance();
    enemyStrategy = config.Get<int>(Constants::ENEMY_STRATEGY);
    bullets = config.Get<int>(Constants::BULLETS);
    revolverSpin = config.Get<bool>(Constants::REVOLVER_SPIN);
    enemyStrategyStr = "Enemy: " + GetStrategyName();
    bulletsStr = "Bullets: " + std::to_string(GetBullets());
    revolverSpinStr = "Revolver: " + GetRevolverSpin();
}

std::vector<MenuItem> SettingsModel::GetMenuItems() {
    return {
            { enemyStrategyStr.c_str(), GameState::SETTINGS_CHANGED },
            { bulletsStr.c_str(), GameState::SETTINGS_CHANGED },
            { revolverSpinStr.c_str(), GameState::SETTINGS_CHANGED },
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
    config.Set(Constants::REVOLVER_SPIN, revolverSpin);
}