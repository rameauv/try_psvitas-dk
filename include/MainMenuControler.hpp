#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>

// //sound management headers
// #include <stdint.h>
// #include <math.h>
// #include <psp2/audioout.h>
// #include "soloud.h"
// #include "soloud_wav.h"
// #include "soloud_speech.h"
//
#include "SoundSoloud.hpp"
#include "SceneControler.hpp"
#include "MainMenuModel.hpp"
#include "MainMenuView.hpp"
#include "ButtonModel.hpp"

class MainMenuControler : public SceneControler
{
    private:
        MainMenuModel _model;
        MainMenuView _view;
        SoundSoloud _sound;
        ButtonModel _buttonModel1;
        ButtonModel _buttonModel2;
    private:
        void hoverNext();
        void hoverPrev();
    public:
        MainMenuControler();
        virtual ~MainMenuControler();
    public:
        void init();
        virtual int handleInput();
};