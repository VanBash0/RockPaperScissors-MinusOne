#ifndef PLAYER
#define PLAYER

#include "Figures.hpp"
#include <vector>

enum Hand {
    LEFT,
    RIGHT,
    NEITHER
};

class Player {
public:
    Player();
    void ResetFigures();
    Figure GetFinalFigure() const;
    Hand HandToPick() const;
    std::vector<Figure> GetFigures() const;
protected:
    Figure figures[2];
};

#endif // PLAYER