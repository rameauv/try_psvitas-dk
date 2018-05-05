#include "SettingsControler.hpp"
#include "Services.hpp"
#include <chrono>

SettingsControler::SettingsControler()
    : SceneControler(Scene::SETTINGS) {
}

SettingsControler::~SettingsControler() {
}

void SettingsControler::init() {
}

int SettingsControler::handleInput() {
    this->_view.render(this->_model.getInstance());
    Services::key.update();
    if (Services::key.getPressed() & SCE_CTRL_CROSS && (*this->_model.getButtons())[0].getState()) {
        Services::sceneManager.load(Scene::MAIN_MENU);
        if (Services::sceneManager.getNewSceneControler())
            ((SettingsControler*)Services::sceneManager.getNewSceneControler())->init();
    }
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

void SettingsControler::hoverNext() {
    if (this->_model.getHoverButtonId() + 1 < this->_model.getButtons()->size())
    {
        (*this->_model.getButtonsM())[this->_model.getHoverButtonId()].setState(false);
        (*this->_model.getButtonsM())[this->_model.getHoverButtonId() + 1].setState(true);
        this->_model.setHoverButtonId(this->_model.getHoverButtonId() + 1);
        return;
    }
    (*this->_model.getButtonsM())[this->_model.getHoverButtonId()].setState(false);
    (*this->_model.getButtonsM())[0].setState(true);
    this->_model.setHoverButtonId(0);
}

void SettingsControler::hoverPrev() {
    if (this->_model.getHoverButtonId() > 0)
    {
        (*this->_model.getButtonsM())[this->_model.getHoverButtonId()].setState(false);
        (*this->_model.getButtonsM())[this->_model.getHoverButtonId() - 1].setState(true);
        this->_model.setHoverButtonId(this->_model.getHoverButtonId() - 1);
        return;
    }
    (*this->_model.getButtonsM())[this->_model.getHoverButtonId()].setState(false);
    (*this->_model.getButtonsM())[this->_model.getButtons()->size()-1].setState(true);
    this->_model.setHoverButtonId(this->_model.getButtons()->size()-1);
}