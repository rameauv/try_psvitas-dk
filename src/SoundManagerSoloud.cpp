#include "SoundManagerSoloud.hpp"

int SoundMangerSoloud::init() {
    if (this->_gSoloud.init() != SoLoud::SO_NO_ERROR) // Initialize SoLoud
        return (-1);
}

int SoundMangerSoloud::uninit() {
    this->_gSoloud.deinit();
}

int SoundMangerSoloud::play(ISound* sound) {
    SoundSoloud* sound_soloud = (SoundSoloud*)(sound);
    SoLoud::Wav *wav;
    if (!(wav = sound_soloud->getOriginal()))
        return (-1);
    if (_gSoloud.play(*wav) != SoLoud::SO_NO_ERROR)
        return (-1);
    return (0);
}

int SoundMangerSoloud::stop(ISound* sound) {
    SoundSoloud* sound_soloud = (SoundSoloud*)(sound);
    SoLoud::Wav *wav;
    if (!(wav = sound_soloud->getOriginal()))
        return (-1);
    _gSoloud.stopAudioSource(*wav);
    return (0);
}