#pragma once

#include <string>

class GameModel
{
    private:
        float _x = 50;
        float _y = 50;
    public:
        GameModel() {
        }
    public:
        const GameModel* getInstance() const {return(this);}
        float getX() const {return(this->_x);}
        float getY() const {return(this->_y);}
        void setX(float val){this->_x = val;}
        void setY(float val){this->_y = val;}
};
