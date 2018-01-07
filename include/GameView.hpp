#pragma once

#include <vita2d.h>
#include "GameModel.hpp"

class GameView
{
    private:
        vita2d_pgf *_pgf;
    public:
        GameView();
        ~GameView();
    public:
        void render(const GameModel* model);
};