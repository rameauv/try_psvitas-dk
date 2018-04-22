#pragma once

#include "SceneManager.hpp"
#include "KeyVita.hpp"
#include "GraphicVita.hpp"
#include "SoundManagerSoloud.hpp"

namespace Services
{
    typedef enum state {
        STATE_RUN,
        STATE_QUIT
    } state_e;
    extern state_e state;
    extern SceneManager sceneManager;
    extern Key key;
    extern Graphic graphic;
    extern SoundMangerSoloud soundManger;
}