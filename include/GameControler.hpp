#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <chrono>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include <vita2d.h>
#include "SoundSoloud.hpp"

// //sound management headers
// #include <stdint.h>
// #include <math.h>
// #include <psp2/audioout.h>
// #include "soloud.h"
// #include "soloud_wav.h"
// #include "soloud_speech.h"
//
#include "SceneControler.hpp"
#include "GameModel.hpp"
#include "GameView.hpp"

class GameControler : public SceneControler
{
    private:
        GameModel _model;
        GameView _view;
        SoundSoloud _sound;
        // SoLoud::Soloud* _gSoloud; // SoLoud engine
        // SoLoud::Wav* _gWave;      // One wave file
    public:
        GameControler();
        virtual ~GameControler();
    public:
        void init();
        virtual int handleInput();
};