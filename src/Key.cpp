#include "Key.hpp"

Key::Key()
{
    memset(&this->_pad, 0, sizeof(this->_pad));
    this->_down = 0;
    this->_release = 0;
    this->_pressed = 0;
}

void Key::update() {
    sceCtrlPeekBufferPositive(0, &this->_pad, 1);
    this->CalcPressed(this->_pad.buttons);
    this->CalcRelease(this->_pad.buttons);
    this->_down = this->_pad.buttons;
}

void Key::CalcRelease(unsigned int button) {
    unsigned int full =  0b1111'1111'1111'1111'1111'1111'1111'1111;

    this->_release = button;
    this->_release ^= full;
    this->_release &= this->_down;
}

void Key::CalcPressed(unsigned int button) {
    unsigned int full =  0b1111'1111'1111'1111'1111'1111'1111'1111;
    unsigned int old;

    old = this->_down;
    this->_pressed = button;
    old ^= full;
    this->_pressed &= old;
}

unsigned int Key::getDown() {
    return (this->_down);
}

unsigned int Key::getRelease() {
    return (this->_release);
}

unsigned int Key::getPressed() {
    return (this->_pressed);
}