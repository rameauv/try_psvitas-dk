#pragma once
#ifndef SPLASHSCREENCONTROLER_HPP
#define SPLASHSCREENCONTROLER_HPP
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include <vita2d.h>

//sound management headers
#include <stdint.h>
#include <math.h>
#include <psp2/audioout.h>
#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_speech.h"
//

#include "SceneControler.hpp"
#include "SplashScreenModel.hpp"
#include "SplashScreenView.hpp"

class SplashScreenControler : public SceneControler
{
    private:
        SplashScreenModel _model;
        SplashScreenView _view;
    public:
        SplashScreenControler();
        virtual ~SplashScreenControler();
        virtual int handleInput();
};
#endif /* SPLASHSCREENCONTROLER_HPP */
