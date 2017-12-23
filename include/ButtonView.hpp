#pragma once

#include <vita2d.h>
#include <string>
#include <chrono>
#include "ButtonModel.hpp"

class ButtonView
{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> _lastAnimTime;
        vita2d_pgf *_pgf;
        bool _anim;
        bool _firstAnim;
    public:
        ButtonView();
        ~ButtonView();
    public:
        void render(const ButtonModel* model_instance);
};