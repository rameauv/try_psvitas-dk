#pragma once
#ifndef SCENEMANAGER_HPP
#define SCENEMANAGER_HPP

#include "ISceneControler.hpp"
#include "SplashScreenControler.hpp"
#include "MainMenuControler.hpp"

class SceneManager
{
    private:
        ISceneControler *_sceneControler;
        ISceneControler *_newSceneControler;
    public:
        SceneManager();
    public:
        void load(ISceneControler::sceneControlerId_e sceneControlerId);
        ISceneControler* getSceneControler();
        ISceneControler* getNewSceneControler();
        ISceneControler::sceneControlerId_e getNewControlerId();
        void clean();
};
#endif /* SCENEMANAGER_HPP */
