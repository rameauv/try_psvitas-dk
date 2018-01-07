#include "GameControler.hpp"
#include "globals.hpp"

GameControler::GameControler()
    : SceneControler(ISceneControler::GAME) {
    // this->_gSoloud = new SoLoud::Soloud;
    // this->_gWave = new SoLoud::Wav;
    // this->_gSoloud->init(); // Initialize SoLoud
    // this->_gWave->load("ux0:/music.ogg"); // Load a wave
}

GameControler::~GameControler() {
    // this->_gSoloud->deinit();
    // delete this->_gSoloud;
    // delete this->_gWave;
}

void GameControler::init() {
    // this->_gSoloud->play(*this->_gWave); // Play the wave
}

int GameControler::handleInput() {
    this->_view.render(this->_model.getInstance());
    globals::key.update();
    if (globals::key.getPressed() & SCE_CTRL_SELECT)
		globals::globalState = globals::STATE_QUIT;
    if (globals::key.getDown() & SCE_CTRL_UP)
        this->_model.setY(this->_model.getY() - 1);
    if (globals::key.getDown() & SCE_CTRL_DOWN)
        this->_model.setY(this->_model.getY() + 1);
    if (globals::key.getDown() & SCE_CTRL_LEFT)
        this->_model.setX(this->_model.getX() - 1);
    if (globals::key.getDown() & SCE_CTRL_RIGHT)
        this->_model.setX(this->_model.getX() + 1);
    return (0);
}