#pragma once

#include <stdint.h>
#include <math.h>
#include <psp2/audioout.h>

#include "SoundSoloud.hpp"

#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_speech.h"

class SoundMangerSoloud{
    private:
        SoLoud::Soloud _gSoloud; // SoLoud engine
    public:
        int init();
        int uninit();
    public:
        int play(SoundSoloud& sound);
        int stop(SoundSoloud& sound);
};