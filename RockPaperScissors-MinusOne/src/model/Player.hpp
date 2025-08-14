#ifndef PLAYER
#define PLAYER

#include "Figures.hpp"

class Player {
public:
    Player();
    void resetFigures();
    Figure getFinalFigure() const;
protected:
    Figure figures[2];
};

#endif // PLAYER