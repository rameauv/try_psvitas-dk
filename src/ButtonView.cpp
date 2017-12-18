#include "ButtonView.hpp"

ButtonView::ButtonView () {
    this->_pgf = vita2d_load_default_pgf();
}

void ButtonView::render(float x, float y, float w, float h, bool state) {
    if (state)
        vita2d_draw_rectangle(x, y, w, h, RGBA8(255, 255, 255, 255));
    else
        vita2d_draw_rectangle(x, y, w, h, RGBA8(0, 0, 255, 255));
}

void ButtonView::render(const ButtonModel* model_instance)
{
    if (!model_instance)
    {
        vita2d_pgf_draw_text(this->_pgf, 700, 30, RGBA8(0,255,0,255), 1.0f, "NULL");
        return;
    }
    if (model_instance->getState())
        vita2d_draw_rectangle(model_instance->getX(), model_instance->getY(), model_instance->getW(), model_instance->getH(), RGBA8(255, 255, 255, 255));
    else
        vita2d_draw_rectangle(model_instance->getX(), model_instance->getY(), model_instance->getW(), model_instance->getH(), RGBA8(0, 0, 255, 255));
}