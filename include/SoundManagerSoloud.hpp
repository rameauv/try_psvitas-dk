#pragma once

#include <stdint.h>
#include <math.h>
#include <psp2/audioout.h>

#include "ISoundManager.hpp"
#include "ISound.hpp"

#include "SoundSoloud.hpp"

#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_speech.h"

class SoundMangerSoloud : ISoundManager {
    private:
        SoLoud::Soloud _gSoloud; // SoLoud engine
    public:
        virtual int init();
        virtual int uninit();
    public:
        virtual int play(ISound* sound);
        virtual int stop(ISound* sound);
};