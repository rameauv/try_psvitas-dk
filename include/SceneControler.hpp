#pragma once

#include "ISceneControler.hpp"
class SceneControler : public ISceneControler
{
    protected:
        const ISceneControler::sceneControlerId_e id;
    protected:
        SceneControler(ISceneControler::sceneControlerId_e id);
    public:
        virtual ISceneControler::sceneControlerId_e getId();
        virtual int handleInput() = 0;
};