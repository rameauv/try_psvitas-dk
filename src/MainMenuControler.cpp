#include "MainMenuControler.hpp"
#include "globals.hpp"

MainMenuControler::MainMenuControler()
    : SceneControler(ISceneControler::SPLASH_SCREEN) {
    this->_gSoloud.init(); // Initialize SoLoud
    this->_gWave.load("ux0:/music.ogg"); // Load a wave
    this->_buttonModel1.init(50, 50, 100, 20, true);
    this->_buttonModel2.init(50, 100, 100, 20, false);
}

void MainMenuControler::init() {
    this->_gSoloud.play(this->_gWave); // Play the wave
}

int MainMenuControler::handleInput() {
    this->_view.render(this->_model.getX(), this->_model.getY(), this->_buttonModel1.getInstance(), this->_buttonModel2.getInstance());
    // sceCtrlPeekBufferPositive(0, &this->_pad, 1);
    globals::key.update();
    if (globals::key.getPressed() & SCE_CTRL_START)
		globals::globalState = globals::STATE_QUIT;
    if (globals::key.getPressed() & SCE_CTRL_UP)
    {
        this->_buttonModel1.setState(!this->_buttonModel1.getState());
        this->_buttonModel2.setState(!this->_buttonModel1.getState());
    }
    if (globals::key.getPressed() & SCE_CTRL_DOWN)
    {
        this->_buttonModel1.setState(!this->_buttonModel1.getState());
        this->_buttonModel2.setState(!this->_buttonModel1.getState());
    }
    if (globals::key.getDown() & SCE_CTRL_UP)
        this->_model.setY(this->_model.getY() - 1);
    if (globals::key.getDown() & SCE_CTRL_DOWN)
        this->_model.setY(this->_model.getY() + 1);
    if (globals::key.getDown() & SCE_CTRL_LEFT)
        this->_model.setX(this->_model.getX() - 1);
    if (globals::key.getDown() & SCE_CTRL_RIGHT)
        this->_model.setX(this->_model.getX() + 1);
}