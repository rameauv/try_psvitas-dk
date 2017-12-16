#pragma once
#ifndef MAINMENUMODEL_HPP
#define MAINMENUMODEL_HPP

class MainMenuModel
{
    private:
        float _x = 50;
        float _y = 50;
    public:
        float getX(){return(this->_x);}
        float getY(){return(this->_y);}
        float setX(float val){this->_x = val;}
        float setY(float val){this->_y = val;}
};
#endif /* MAINMENUMODEL_HPP */
