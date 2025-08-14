#include "HumanPlayer.hpp"

void HumanPlayer::setFigure(Figure figure, int index) {
    figures[index] = figure;
}

void HumanPlayer::dropFigure(int index) {
    figures[index] = Figure::EMPTY;
}