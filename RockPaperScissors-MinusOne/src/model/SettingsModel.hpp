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
    void ChangeSpin();
    std::vector<MenuItem> GetMenuItems();
private:
    int enemyStrategy;
    int bullets;
    bool revolverSpin;

    std::string enemyStrategyStr;
    std::string bulletsStr;
    std::string revolverSpinStr;

    std::string GetStrategyName();
    std::string GetRevolverSpin() { return revolverSpin ? "Spin" : "No spin"; };
};

#endif // SETTINGS_MODEL