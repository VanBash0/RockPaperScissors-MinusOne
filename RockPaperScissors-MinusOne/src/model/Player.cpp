#include "Player.hpp"

Player::Player() {
    ResetFigures();
}

void Player::ResetFigures() {
    figures[0] = Figure::EMPTY;
    figures[1] = Figure::EMPTY;
}

Figure Player::GetFinalFigure() const {
    if (figures[0] == Figure::EMPTY && figures[1] == Figure::EMPTY)
        throw "Both figures are empty!";
    return figures[0] == Figure::EMPTY ? figures[1] : figures[0];
}

Hand Player::HandToPick() const {
    if (figures[Hand::LEFT] == Figure::EMPTY) return LEFT;
    if (figures[Hand::RIGHT] == Figure::EMPTY) return RIGHT;
    return NEITHER;
}

std::vector<Figure> Player::GetFigures() const {
    std::vector<Figure> result;
    result.push_back(figures[Hand::LEFT]);
    result.push_back(figures[Hand::RIGHT]);
    return result;
}