#include "SplashScreenControler.hpp"
#include "globals.hpp"

SplashScreenControler::SplashScreenControler()
    : SceneControler(ISceneControler::SPLASH_SCREEN) {
}

int SplashScreenControler::handleInput() {
    this->_view.render();
    globals::key.update();
    if (globals::key.getPressed() & SCE_CTRL_START)
    {
        globals::sceneManager.load(ISceneControler::MAIN_MENU);
        if (globals::sceneManager.getNewSceneControler())
            ((MainMenuControler*)globals::sceneManager.getNewSceneControler())->init();
    }
}