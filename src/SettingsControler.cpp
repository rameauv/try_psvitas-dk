#include "SettingsControler.hpp"
#include "globals.hpp"
#include <chrono>

SettingsControler::SettingsControler()
    : SceneControler(Scene::SETTINGS) {
    // this->_gSoloud = new SoLoud::Soloud;
    // this->_gWave = new SoLoud::Wav;
    // this->_gSoloud->init(); // Initialize SoLoud
    // this->_gWave->load("ux0:/music.ogg"); // Load a wave
}

SettingsControler::~SettingsControler() {
    // this->_gSoloud->deinit();
    // delete this->_gSoloud;
    // delete this->_gWave;
}

void SettingsControler::init() {
    // this->_gSoloud->play(*this->_gWave); // Play the wave
}

int SettingsControler::handleInput() {
    this->_view.render(this->_model.getInstance());
    globals::key.update();
    if (globals::key.getPressed() & SCE_CTRL_CROSS && (*this->_model.getButtons())[0].getState()) {
        globals::sceneManager.load(Scene::MAIN_MENU);
        if (globals::sceneManager.getNewSceneControler())
            ((SettingsControler*)globals::sceneManager.getNewSceneControler())->init();
    }
    if (globals::key.getPressed() & SCE_CTRL_UP)
        this->hoverPrev();
    if (globals::key.getPressed() & SCE_CTRL_DOWN)
        this->hoverNext();
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