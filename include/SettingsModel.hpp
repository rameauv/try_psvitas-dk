#pragma once

#include <vector>
#include <string>
#include "ButtonModel.hpp"

class SettingsModel
{
    private:
        float _x = 50;
        float _y = 50;
        std::vector<ButtonModel> _buttons;
        unsigned int _hoverButtonId;
    public:
        SettingsModel();
    public:
        const SettingsModel* getInstance() const;
        float getX() const;
        float getY() const;
        const std::vector<ButtonModel>* getButtons() const;
        std::vector<ButtonModel>* getButtonsM();
        unsigned int getHoverButtonId() const;
        void setX(float val);
        void setY(float val);
        void setHoverButtonId(int val); 
};
