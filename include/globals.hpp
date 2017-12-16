#pragma once
#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "SceneManager.hpp"

namespace globals
{
    typedef enum state
            {
                STATE_RUN,
                STATE_QUIT
            } state_e;
    extern state_e global_state;
    extern SceneManager sceneManager;
}
#endif /* GLOBALS_HPP */
