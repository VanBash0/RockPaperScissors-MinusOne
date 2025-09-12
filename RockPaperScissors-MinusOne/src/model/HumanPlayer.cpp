#include "HumanPlayer.hpp"

void HumanPlayer::SetFigure(Figure figure, int index) {
    figures[index] = figure;
}

void HumanPlayer::DropFigure(int index) {
    figures[index] = Figure::EMPTY;
}