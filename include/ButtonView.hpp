#pragma once

#include <vita2d.h>
#include "ButtonModel.hpp"

class ButtonView
{
    private:
        vita2d_pgf *_pgf;
    public:
        ButtonView();
    public:
        void render(float x, float y, float w, float h, bool state);
        void render(const ButtonModel* model_instance);
};