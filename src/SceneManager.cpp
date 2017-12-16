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

ISceneControler::sceneControlerId_e SceneManager::getNewControlerId() {
    if (this->_sceneControler == nullptr)
        return (ISceneControler::UNKNOW);
    return (this->_sceneControler->getId());
}

void SceneManager::clean() {
    if (this->_newSceneControler == nullptr)
        return ;
    if (this->_sceneControler)
        delete this->_sceneControler;
    this->_sceneControler = this->_newSceneControler;
    this->_newSceneControler = nullptr;
}