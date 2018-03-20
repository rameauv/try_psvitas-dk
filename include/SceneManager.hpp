#pragma once

#include "ISceneControler.hpp"
#include "SplashScreenControler.hpp"
#include "MainMenuControler.hpp"
#include "SettingsControler.hpp"
#include "GameControler.hpp"

class SceneManager
{
    private:
        ISceneControler *_sceneControler;
        ISceneControler *_newSceneControler;
    public:
        SceneManager();
    public:
        void load(Scene::sceneControlerId_e sceneControlerId);
        ISceneControler* getSceneControler();
        ISceneControler* getNewSceneControler();
        Scene::sceneControlerId_e getNewControlerId();
        void clean();
};