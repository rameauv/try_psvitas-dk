#pragma once

#include "ISound.hpp"

class ISoundManager {
    public:
        virtual int init() = 0;
        virtual int desinit() = 0;
        virtual int play(ISound* sound) = 0;
        virtual int stop(ISound* sound) = 0;
};