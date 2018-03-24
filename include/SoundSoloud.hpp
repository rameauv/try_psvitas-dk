#pragma once

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <psp2/audioout.h>

#include "ISound.hpp"

#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_speech.h"

class SoundSoloud : ISound {
    private:
        SoLoud::Wav _gWave;      // One wave file
    public:
        virtual int Load(const std::string &path);
        SoLoud::Wav* getOriginal();
};