#pragma once 
#include "SceneType.hpp"
#include "ISceneControler.hpp"
class SceneControler : public ISceneControler
{
    protected:
        const Scene::sceneControlerId_e id;
    protected:
        SceneControler(Scene::sceneControlerId_e id);
    public:
        virtual Scene::sceneControlerId_e getId();
        virtual int handleInput() = 0;
};