#ifndef ENEMY_PLAYER
#define ENEMY_PLAYER

#include "Player.hpp"

enum class EnemyStrategy {
    CAREFUL,
    AGGRESSIVE,
    RANDOM
};

class EnemyPlayer : public Player {
public:
    void SetFigures();
    void DropFigure(std::vector<Figure> playerFigures);
    void SetStrategy(EnemyStrategy strategy);
private:
    EnemyStrategy strategy;
};

#endif // ENEMY_PLAYER