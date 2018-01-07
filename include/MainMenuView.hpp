#pragma once

#include <vita2d.h>
#include "ButtonView.hpp"
#include "MainMenuModel.hpp"

class MainMenuView
{
    private:
        ButtonView _buttonView;
        std::vector<ButtonView> _buttons;
    public:
        MainMenuView();
        ~MainMenuView();
    public:
        void render(const MainMenuModel* model);
};