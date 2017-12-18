#pragma once
#ifndef MAINMENUVIEW_HPP
#define MAINMENUVIEW_HPP

#include <vita2d.h>
#include "ButtonView.hpp"
#include "ButtonModel.hpp"

class MainMenuView
{
    private:
        vita2d_pgf *_pgf;
        vita2d_pvf *_pvf;
        ButtonView _buttonView;
    public:
        MainMenuView();
        ~MainMenuView();
    public:
        void render(float x, float y, const ButtonModel* model_instance1, const ButtonModel* model_instance2);
};
#endif /* MAINMENUVIEW_HPP */
