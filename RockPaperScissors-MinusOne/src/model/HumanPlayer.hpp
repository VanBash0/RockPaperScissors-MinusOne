#ifndef HUMAN_PLAYER
#define HUMAN_PLAYER

#include "Player.hpp"

class HumanPlayer : public Player {
public:
    void SetFigure(Figure figure, int index);
    void DropFigure(int index);
};

#endif // HUMAN_PLAYER