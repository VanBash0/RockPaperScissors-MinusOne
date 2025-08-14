#ifndef ENEMY_PLAYER
#define ENEMY_PLAYER

#include "Player.hpp"

class EnemyPlayer : public Player {
public:
    void setFigures();
    void dropFigure();
};

#endif // ENEMY_PLAYER