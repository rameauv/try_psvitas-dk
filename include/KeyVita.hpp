#pragma once

#include <string.h>
#include <psp2/ctrl.h>

class Key
{
    private:
        SceCtrlData _pad;
        unsigned int _down;
        unsigned int _release;
        unsigned int _pressed;
    private:
        void CalcRelease(unsigned int);
        void CalcPressed(unsigned int);
    public:
        Key();
        void update();
        unsigned int getDown();
        unsigned int getRelease();
        unsigned int getPressed();
};