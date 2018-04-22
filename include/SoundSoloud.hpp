#pragma once

#include <iostream>
#include <stdint.h>
#include <math.h>
#include <psp2/audioout.h>

#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_speech.h"

class SoundSoloud {
    private:
        SoLoud::Wav _gWave;      // One wave file
    public:
        virtual int load(const std::string &path);
        SoLoud::Wav* getOriginal();
};