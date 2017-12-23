#pragma once

#include <vita2d.h>
#include <string>

class ButtonModel
{
    private:
        float _x;
        float _y;
        float _w;
        float _h;
        bool _state;
        std::string _text;
    public:
        ButtonModel();
        void init(float x, float y, float w, float h, bool state, const std::string& text);
        const ButtonModel* getInstance() const;
        void setX(float val);
        float getX() const;
        void setY(float val);
        float getY() const;
        void setW(float val);
        float getW() const;
        void setH(float val);
        float getH() const;
        void setState(bool val);
        bool getState() const;
        void setText(const std::string& val);
        const std::string* getText() const;
};