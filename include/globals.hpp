#pragma once

#include "SceneManager.hpp"
#include "KeyVita.hpp"

namespace globals
{
    typedef enum state {
        STATE_RUN,
        STATE_QUIT
    } state_e;
    extern state_e globalState;
    extern SceneManager sceneManager;
    extern Key key;
}