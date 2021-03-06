#include "MainMenuControler.hpp"
#include "Services.hpp"
#include <chrono>

MainMenuControler::MainMenuControler()
    : SceneControler(Scene::MAIN_MENU) {
    if (_sound.load("app0:/ressources/music.ogg") == -1) // Load a wave
        _model._debug += "cannot load sound\n";
    Services::soundManger.play(_sound);
}

MainMenuControler::~MainMenuControler() {
}

void MainMenuControler::init() {
}

int MainMenuControler::handleInput() {
    this->_view.render(this->_model.getInstance());
    Services::key.update();
    if (Services::key.getPressed() & SCE_CTRL_CROSS && (*this->_model.getButtons())[0].getState()) {
        Services::sceneManager.load(Scene::GAME);
        if (Services::sceneManager.getNewSceneControler())
            ((GameControler*)Services::sceneManager.getNewSceneControler())->init();
    }
    if (Services::key.getPressed() & SCE_CTRL_CROSS && (*this->_model.getButtons())[1].getState()) {
        Services::sceneManager.load(Scene::SETTINGS);
        if (Services::sceneManager.getNewSceneControler())
            ((SettingsControler*)Services::sceneManager.getNewSceneControler())->init();
    }
    if (Services::key.getPressed() & SCE_CTRL_CROSS && (*this->_model.getButtons())[2].getState())
		Services::state = Services::STATE_QUIT;
    if (Services::key.getPressed() & SCE_CTRL_UP)
        this->hoverPrev();
    if (Services::key.getPressed() & SCE_CTRL_DOWN)
        this->hoverNext();
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

void MainMenuControler::hoverNext() {
    if (this->_model.getHoverButtonId() + 1 < this->_model.getButtons()->size()) {
        (*this->_model.getButtonsM())[this->_model.getHoverButtonId()].setState(false);
        (*this->_model.getButtonsM())[this->_model.getHoverButtonId() + 1].setState(true);
        this->_model.setHoverButtonId(this->_model.getHoverButtonId() + 1);
        return;
    }
    (*this->_model.getButtonsM())[this->_model.getHoverButtonId()].setState(false);
    (*this->_model.getButtonsM())[0].setState(true);
    this->_model.setHoverButtonId(0);
}

void MainMenuControler::hoverPrev() {
    if (this->_model.getHoverButtonId() > 0) {
        (*this->_model.getButtonsM())[this->_model.getHoverButtonId()].setState(false);
        (*this->_model.getButtonsM())[this->_model.getHoverButtonId() - 1].setState(true);
        this->_model.setHoverButtonId(this->_model.getHoverButtonId() - 1);
        return;
    }
    (*this->_model.getButtonsM())[this->_model.getHoverButtonId()].setState(false);
    (*this->_model.getButtonsM())[this->_model.getButtons()->size()-1].setState(true);
    this->_model.setHoverButtonId(this->_model.getButtons()->size()-1);
}