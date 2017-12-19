#pragma once
#ifndef MAINMENUVIEW_HPP
#define MAINMENUVIEW_HPP

#include <vita2d.h>
#include "ButtonView.hpp"
#include "MainMenuModel.hpp"

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
        void render(const MainMenuModel* model);
};
#endif /* MAINMENUVIEW_HPP */
