#pragma once
#ifndef MAINMENUVIEW_HPP
#define MAINMENUVIEW_HPP

#include <vita2d.h>

class MainMenuView
{
    private:
        vita2d_pgf *_pgf;
        vita2d_pvf *_pvf;
    public:
        MainMenuView();
        ~MainMenuView();
    public:
        void render(float x, float y);
};
#endif /* MAINMENUVIEW_HPP */
