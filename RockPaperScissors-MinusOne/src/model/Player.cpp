#include "Player.hpp"

Player::Player() {
    resetFigures();
}

void Player::resetFigures() {
    figures[0] = Figure::EMPTY;
    figures[1] = Figure::EMPTY;
}

Figure Player::getFinalFigure() const {
    if (figures[0] == Figure::EMPTY && figures[1] == Figure::EMPTY)
        throw "Both figures are empty!";
    return figures[0] == Figure::EMPTY ? figures[1] : figures[0];
}