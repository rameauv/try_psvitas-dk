#include "SplashScreenControler.hpp"
#include "Services.hpp"

SplashScreenControler::SplashScreenControler()
    : SceneControler(Scene::SPLASH_SCREEN) {
}

SplashScreenControler::~SplashScreenControler() {
}

int SplashScreenControler::handleInput() {
    this->_view.render();
    Services::key.update();
    if (Services::key.getPressed() & SCE_CTRL_START) {
        Services::sceneManager.load(Scene::MAIN_MENU);
        if (Services::sceneManager.getNewSceneControler())
            ((MainMenuControler*)Services::sceneManager.getNewSceneControler())->init();
    }
    return (0);
}