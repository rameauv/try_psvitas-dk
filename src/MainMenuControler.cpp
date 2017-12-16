#include "MainMenuControler.hpp"
#include "globals.hpp"

MainMenuControler::MainMenuControler()
    : SceneControler(ISceneControler::SPLASH_SCREEN) {
    this->_gSoloud.init(); // Initialize SoLoud
    this->_gWave.load("ux0:/music.ogg"); // Load a wave
    memset(&this->_pad, 0, sizeof(this->_pad));
    // this->init();
}

void MainMenuControler::init() {
    this->_gSoloud.play(this->_gWave); // Play the wave
}

int MainMenuControler::handleInput() {
    this->_view.render(this->_model.getX(), this->_model.getY());
    sceCtrlPeekBufferPositive(0, &this->_pad, 1);
    if (this->_pad.buttons & SCE_CTRL_START)
		globals::global_state = globals::STATE_QUIT;
    if (this->_pad.buttons == SCE_CTRL_UP)
        this->_model.setY(this->_model.getY() - 1);
    if (this->_pad.buttons == SCE_CTRL_DOWN)
        this->_model.setY(this->_model.getY() + 1);
    if (this->_pad.buttons == SCE_CTRL_LEFT)
        this->_model.setX(this->_model.getX() - 1);
    if (this->_pad.buttons == SCE_CTRL_RIGHT)
        this->_model.setX(this->_model.getX() + 1);
}