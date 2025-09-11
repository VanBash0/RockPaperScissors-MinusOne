#ifndef ENEMY_PLAYER
#define ENEMY_PLAYER

#include "Player.hpp"

enum class EnemyStrategy {
    Careful,
    Aggressive,
    Random
};

class EnemyPlayer : public Player {
public:
    void SetFigures();
    void DropFigure();
    void SetStrategy(EnemyStrategy strategy);
private:
    EnemyStrategy strategy;
};

#endif // ENEMY_PLAYER