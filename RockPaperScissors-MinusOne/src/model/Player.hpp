#ifndef PLAYER
#define PLAYER

#include "Figures.hpp"

class Player {
public:
    Player();
    void ResetFigures();
    Figure GetFinalFigure() const;
protected:
    Figure figures[2];
};

#endif // PLAYER