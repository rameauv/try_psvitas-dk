#include "ButtonView.hpp"

ButtonView::ButtonView () {
    this->_pgf = vita2d_load_default_pgf();
}

void ButtonView::render(const ButtonModel* model_instance)
{
    if (!model_instance)
        return;
    if (model_instance->getState())
        vita2d_draw_rectangle(model_instance->getX(), model_instance->getY(), model_instance->getW(), model_instance->getH(), RGBA8(0, 0, 255, 255));
    else
        vita2d_draw_rectangle(model_instance->getX(), model_instance->getY(), model_instance->getW(), model_instance->getH(), RGBA8(255, 255, 255, 255));
    vita2d_pgf_draw_text(this->_pgf, model_instance->getX(), model_instance->getY() + vita2d_pgf_text_height(this->_pgf, 1, model_instance->getText()->c_str()), RGBA8(0,255,0,255), 1.0f, model_instance->getText()->c_str());
}