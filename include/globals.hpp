#pragma once
#ifndef GLOBALS_HPP
#define GLOBALS_HPP

#include "SceneManager.hpp"
#include "Key.hpp"


namespace globals
{
    typedef enum state
            {
                STATE_RUN,
                STATE_QUIT
            } state_e;
    extern state_e globalState;
    extern SceneManager sceneManager;
    extern Key key;
}
#endif /* GLOBALS_HPP */
