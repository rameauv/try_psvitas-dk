#include "ButtonModel.hpp"

ButtonModel::ButtonModel() {
}

void ButtonModel::init(float x, float y, float w, float h, bool state, const std::string& text) {
    this->_x = x;
    this->_y = y;
    this->_w = w;
    this->_h = h;
    this->_state = state;
    this->_text = text;
}

const ButtonModel* ButtonModel::getInstance() const {
    return (this);
}

void ButtonModel::setX(float val) {
    this->_x = val;
}

float ButtonModel::getX() const {
    return (this->_x);
}

void ButtonModel::setY(float val) {
    this->_y = val;
}

float ButtonModel::getY() const {
    return (this->_y);
}

void ButtonModel::setW(float val) {
    this->_w = val;
}

float ButtonModel::getW() const {
    return (this->_w);
}

void ButtonModel::setH(float val) {
    this->_h = val;
}

float ButtonModel::getH() const {
    return (this->_h);
}

void ButtonModel::setState(bool val) {
    this->_state = val;
}

bool ButtonModel::getState() const {
    return (this->_state);
}

void ButtonModel::setText(const std::string& val) {
    this->_text = val;
}

const std::string* ButtonModel::getText() const {
    return (&this->_text);
}
