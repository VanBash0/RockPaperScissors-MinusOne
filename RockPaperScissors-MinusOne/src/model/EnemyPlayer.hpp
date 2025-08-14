#ifndef ENEMY_PLAYER
#define ENEMY_PLAYER

#include "Player.hpp"

class EnemyPlayer : public Player {
public:
    void SetFigures();
    void DropFigure();
};

#endif // ENEMY_PLAYER