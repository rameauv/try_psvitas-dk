#include "SettingsModel.hpp"

SettingsModel::SettingsModel():_buttons(3) {
    this->_hoverButtonId = 0;
    this->_buttons[0].init(50, 50, 200, 100, true, std::string("Setting1"));
    this->_buttons[1].init(50, 250, 200, 100, false, std::string("Setting2"));
    this->_buttons[2].init(0, 850, 200, 100, false, std::string("return"));
}

const SettingsModel* SettingsModel::getInstance() const {
    return(this);
}

float SettingsModel::getX() const {
    return(this->_x);
}

float SettingsModel::getY() const {
    return(this->_y);
}

const std::vector<ButtonModel>* SettingsModel::getButtons() const {
    return(&(this->_buttons));
}

std::vector<ButtonModel>* SettingsModel::getButtonsM(){
    return(&(this->_buttons));
}

unsigned int SettingsModel::getHoverButtonId() const {
    return (this->_hoverButtonId);
}

void SettingsModel::setX(float val){
    this->_x = val;
}

void SettingsModel::setY(float val){
    this->_y = val;
}

void SettingsModel::setHoverButtonId(int val) {
    this->_hoverButtonId = val;
}