#ifndef HUMAN_PLAYER
#define HUMAN_PLAYER

#include "Player.hpp"

class HumanPlayer : public Player {
public:
    void setFigure(Figure figure, int index);
    void dropFigure(int index);
};

#endif // HUMAN_PLAYER