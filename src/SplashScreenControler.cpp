#include "SplashScreenControler.hpp"
#include "globals.hpp"

SplashScreenControler::SplashScreenControler()
    : SceneControler(ISceneControler::SPLASH_SCREEN) {
    memset(&this->_pad, 0, sizeof(this->_pad));
}

int SplashScreenControler::handleInput() {
    this->_view.render();
    sceCtrlPeekBufferPositive(0, &this->_pad, 1);
    if (this->_pad.buttons == SCE_CTRL_SELECT)
    {
        globals::sceneManager.load(ISceneControler::MAIN_MENU);
        if (globals::sceneManager.getNewSceneControler())
            ((MainMenuControler*)globals::sceneManager.getNewSceneControler())->init();
    }
}