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
    void ChangeStrategy();
    void ChangeBullets();
    std::vector<MenuItem> GetMenuItems();
private:
    std::string enemyStrategyStr;
    std::string bulletsStr;
    int enemyStrategy;
    int bullets;
    std::string GetStrategyName();
};

#endif // SETTINGS_MODEL