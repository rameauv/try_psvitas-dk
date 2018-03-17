#include "SceneManager.hpp"

SceneManager::SceneManager() {
    this->_sceneControler = nullptr;
    this->_newSceneControler = nullptr;
}

void SceneManager::load(Scene::sceneControlerId_e sceneControlerId) {
    switch (sceneControlerId) {
        case Scene::SPLASH_SCREEN :
            this->_newSceneControler = new SplashScreenControler();
            break;
        case Scene::MAIN_MENU :
            this->_newSceneControler = new MainMenuControler();
            break;
        case Scene::SETTINGS:
            this->_newSceneControler = new SettingsControler();
            break;
        case Scene::GAME:
            this->_newSceneControler = new GameControler();
            break;
        default:
            break;
    }
    if (this->_sceneControler == nullptr)
        this->clean();
}

ISceneControler* SceneManager::getSceneControler() {
    return (this->_sceneControler);
}

ISceneControler* SceneManager::getNewSceneControler() {
    return (this->_newSceneControler);
}

Scene::sceneControlerId_e SceneManager::getNewControlerId() {
    if (this->_sceneControler == nullptr)
        return (Scene::UNKNOW);
    return (this->_sceneControler->getId());
}

void SceneManager::clean() {
    if (this->_newSceneControler == nullptr)
        return ;
    if (this->_sceneControler && this->_sceneControler->getId() == Scene::MAIN_MENU) {
        delete (MainMenuControler*)this->_sceneControler;
        this->_sceneControler = nullptr;
    }
    else if (this->_sceneControler && this->_sceneControler->getId() == Scene::SPLASH_SCREEN) {
        delete (SplashScreenControler*)this->_sceneControler;
        this->_sceneControler = nullptr;
    }
    this->_sceneControler = this->_newSceneControler;
    this->_newSceneControler = nullptr;
}