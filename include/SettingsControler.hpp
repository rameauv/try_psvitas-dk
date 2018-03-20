#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include <vita2d.h>

// //sound management headers
// #include <stdint.h>
// #include <math.h>
// #include <psp2/audioout.h>
// #include "soloud.h"
// #include "soloud_wav.h"
// #include "soloud_speech.h"
//
#include "SceneControler.hpp"
#include "SettingsModel.hpp"
#include "SettingsView.hpp"
#include "ButtonModel.hpp"

class SettingsControler : public SceneControler
{
    private:
        SettingsModel _model;
        SettingsView _view;
        // SoLoud::Soloud* _gSoloud; // SoLoud engine
        // SoLoud::Wav* _gWave;      // One wave file
        ButtonModel _buttonModel1;
        ButtonModel _buttonModel2;
    private:
        void hoverNext();
        void hoverPrev();
    public:
        SettingsControler();
        virtual ~SettingsControler();
    public:
        void init();
        virtual int handleInput();
};