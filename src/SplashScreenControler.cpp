#include "SplashScreenControler.hpp"
#include "globals.hpp"

SplashScreenControler::SplashScreenControler()
    : SceneControler(Scene::SPLASH_SCREEN) {
}

SplashScreenControler::~SplashScreenControler() {
}

int SplashScreenControler::handleInput() {
    this->_view.render();
    globals::key.update();
    if (globals::key.getPressed() & SCE_CTRL_START) {
        globals::sceneManager.load(Scene::MAIN_MENU);
        if (globals::sceneManager.getNewSceneControler())
            ((MainMenuControler*)globals::sceneManager.getNewSceneControler())->init();
    }
    return (0);
}