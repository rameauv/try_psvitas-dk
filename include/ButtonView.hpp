#pragma once

#include <vita2d.h>
#include <string>
#include "ButtonModel.hpp"

class ButtonView
{
    private:
        vita2d_pgf *_pgf;
    public:
        ButtonView();
    public:
        void render(const ButtonModel* model_instance);
};