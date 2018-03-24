#include "SoundSoloud.hpp"

int SoundSoloud::Load(const std::string &path) {
    _gWave.load(path.c_str()); // Load a wave
    return (0);
}

SoLoud::Wav* SoundSoloud::getOriginal() {
    return (&_gWave);
}