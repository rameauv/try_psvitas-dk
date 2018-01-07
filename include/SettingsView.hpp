#pragma once

#include <vita2d.h>
#include "ButtonView.hpp"
#include "SettingsModel.hpp"

class SettingsView
{
    private:
        vita2d_pgf *_pgf;
        ButtonView _buttonView;
        std::vector<ButtonView> _buttons;
    public:
        SettingsView();
        ~SettingsView();
    public:
        void render(const SettingsModel* model);
};