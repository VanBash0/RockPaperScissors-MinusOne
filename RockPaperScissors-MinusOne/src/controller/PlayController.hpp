#ifndef PLAY_CONTROLLER
#define PLAY_CONTROLLER

#include "PlayModel.hpp"
#include <unordered_map>

class PlayController {
public:
    bool TryHandleChoosingFigures(PlayModel& model, int pressedKey);
    bool TryHandleDroppingFigure(PlayModel& model, int pressedKey);
    GameResult GetGameResult(PlayModel& model);
    void ResetFigures(PlayModel& model);
private:
    std::unordered_map<int, Figure> keyToFigure = {
        {KEY_ONE, Figure::ROCK},
        {KEY_TWO, Figure::PAPER},
        {KEY_THREE, Figure::SCISSORS}
    };
};

#endif PLAY_CONTROLLER