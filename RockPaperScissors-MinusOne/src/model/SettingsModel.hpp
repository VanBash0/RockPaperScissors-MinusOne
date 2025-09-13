#ifndef SETTINGS_MODEL
#define SETTINGS_MODEL

#include "MenuModel.hpp"
#include <string>

class SettingsModel {
public:
    void LoadFromConfig();
    void SaveToConfig();
    int GetEnemyStrategy() { return enemyStrategy; };
    int GetBullets() { return bullets; };
    void ChangeStrategy() { enemyStrategy = (enemyStrategy + 1) % 3; };
    void ChangeBullets() { bullets = (bullets + 1) % 6; };
    std::vector<MenuItem> GetMenuItems();
private:
    int enemyStrategy;
    int bullets;
    std::string GetStrategyName();
};

#endif // SETTINGS_MODEL