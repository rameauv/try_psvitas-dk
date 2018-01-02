#pragma once

#include <vector>
#include <string>
#include "ButtonModel.hpp"

class MainMenuModel
{
    private:
        float _x = 50;
        float _y = 50;
        std::vector<ButtonModel> _buttons;
        unsigned int _hoverButtonId;
    public:
        MainMenuModel():_buttons(3) {
            this->_hoverButtonId = 0;
            this->_buttons[0].init(50, 50, 200, 100, true, std::string("button1"));
            this->_buttons[1].init(50, 250, 200, 100, false, std::string("button2"));
            this->_buttons[2].init(50, 450, 200, 100, false, std::string("exit"));
        }
    public:
        const MainMenuModel* getInstance() const {return(this);}
        float getX() const {return(this->_x);}
        float getY() const {return(this->_y);}
        const std::vector<ButtonModel>* getButtons() const {return(&(this->_buttons));}
        std::vector<ButtonModel>* getButtonsM(){return(&(this->_buttons));}
        unsigned int getHoverButtonId() const {return (this->_hoverButtonId);}
        void setX(float val){this->_x = val;}
        void setY(float val){this->_y = val;}
        void setHoverButtonId(int val) {this->_hoverButtonId = val;}
};
