#include "SoundSoloud.hpp"

int SoundSoloud::load(const std::string &path) {
    if (_gWave.load(path.c_str()) != SoLoud::SO_NO_ERROR) // Load a wave
        return (-1);
    return (0);
}

SoLoud::Wav* SoundSoloud::getOriginal() {
    return (&_gWave);
}