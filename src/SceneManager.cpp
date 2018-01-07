#include "SceneManager.hpp"

SceneManager::SceneManager() {
    this->_sceneControler = nullptr;
    this->_newSceneControler = nullptr;
}

void SceneManager::load(ISceneControler::sceneControlerId_e sceneControlerId) {
    switch (sceneControlerId) {
        case ISceneControler::SPLASH_SCREEN :
            this->_newSceneControler = new SplashScreenControler();
            break;
        case ISceneControler::MAIN_MENU :
            this->_newSceneControler = new MainMenuControler();
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

SceneControler::sceneControlerId_e SceneManager::getNewControlerId() {
    if (this->_sceneControler == nullptr)
        return (ISceneControler::UNKNOW);
    return (this->_sceneControler->getId());
}

void SceneManager::clean() {
    if (this->_newSceneControler == nullptr)
        return ;
    if (this->_sceneControler && this->_sceneControler->getId() == ISceneControler::MAIN_MENU) {
        delete (MainMenuControler*)this->_sceneControler;
        this->_sceneControler = nullptr;
    }
    else if (this->_sceneControler && this->_sceneControler->getId() == ISceneControler::SPLASH_SCREEN) {
        delete (SplashScreenControler*)this->_sceneControler;
        this->_sceneControler = nullptr;
    }
    this->_sceneControler = this->_newSceneControler;
    this->_newSceneControler = nullptr;
}