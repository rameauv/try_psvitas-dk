#pragma once

#include <stdint.h>
#include <math.h>
#include <psp2/audioout.h>

#include "ISound.hpp"
#include "SoundSoloud.hpp"

#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_speech.h"

class SoundMangerSoloud {
    private:
        SoLoud::Soloud _gSoloud; // SoLoud engine
    public:
        SoundMangerSoloud();
        ~SoundMangerSoloud();
    public:
        int play(ISound* sound);
        int stop(ISound* sound);
};