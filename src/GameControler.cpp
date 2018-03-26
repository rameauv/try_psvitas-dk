#include "GameControler.hpp"
#include "Services.hpp"

GameControler::GameControler()
    : SceneControler(Scene::GAME) {
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
    Services::key.update();
    if (Services::key.getPressed() & SCE_CTRL_SELECT)
		Services::state = Services::STATE_QUIT;
    if (Services::key.getDown() & SCE_CTRL_UP)
        this->_model.setY(this->_model.getY() - 1);
    if (Services::key.getDown() & SCE_CTRL_DOWN)
        this->_model.setY(this->_model.getY() + 1);
    if (Services::key.getDown() & SCE_CTRL_LEFT)
        this->_model.setX(this->_model.getX() - 1);
    if (Services::key.getDown() & SCE_CTRL_RIGHT)
        this->_model.setX(this->_model.getX() + 1);
    return (0);
}