#ifndef ENEMY_PLAYER
#define ENEMY_PLAYER

#include "Player.hpp"

enum class EnemyStrategy {
    RANDOM,
    CAREFUL,
    AGGRESSIVE
};

class EnemyPlayer : public Player {
public:
    void SetFigures();
    void DropFigure(std::vector<Figure> playerFigures);
    void SetStrategy(int strategy);
private:
    EnemyStrategy strategy;
};

#endif // ENEMY_PLAYER