#include "GameControler.hpp"
#include "Services.hpp"

GameControler::GameControler()
    : SceneControler(Scene::GAME) {
    if (_sound.load("ux0:/music.ogg") != 0)
        sceKernelExitProcess(0);
}

GameControler::~GameControler() {
}

void GameControler::init() {
    Services::soundManger.play(_sound);
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