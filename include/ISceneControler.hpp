#pragma once

#include "SceneType.hpp"

class ISceneControler
{
    public:
        virtual Scene::sceneControlerId_e getId() = 0;
        virtual int handleInput() = 0;
};