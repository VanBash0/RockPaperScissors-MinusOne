#ifndef PLAYER
#define PLAYER

#include "Figures.hpp"

enum Hand {
    LEFT,
    RIGHT
};

class Player {
public:
    Player();
    void ResetFigures();
    Figure GetFinalFigure() const;
    Hand HandToPick() const;
protected:
    Figure figures[2];
};

#endif // PLAYER