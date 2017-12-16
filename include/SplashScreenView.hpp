#pragma once

#include <vita2d.h>

class SplashScreenView
{
    private:
        vita2d_pgf *_pgf;
    public:
        SplashScreenView();
        ~SplashScreenView();
    public:
        void render();
};
