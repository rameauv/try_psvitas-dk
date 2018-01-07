#include "ButtonView.hpp"

ButtonView::ButtonView () {
    this->_pgf = vita2d_load_default_pgf();
    this->_firstAnim = true;
}

ButtonView::~ButtonView () {
    vita2d_free_pgf(this->_pgf);
}

void ButtonView::render(const ButtonModel* model_instance)
{
    std::string a;
    if (!model_instance)
        return;
    if (model_instance->getState()) {
        if (this->_firstAnim) {
            this->_lastAnimTime = std::chrono::high_resolution_clock::now();
            this->_firstAnim = false;
            this->_anim = true;
        }
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - this->_lastAnimTime).count() > 500) {
            this->_lastAnimTime = std::chrono::high_resolution_clock::now();
            this->_anim = !this->_anim;
        }
        if (this->_anim)
            vita2d_draw_rectangle(model_instance->getX(), model_instance->getY(), model_instance->getW(), model_instance->getH(), RGBA8(0, 0, 255, 255));
        else
            vita2d_draw_rectangle(model_instance->getX(), model_instance->getY(), model_instance->getW(), model_instance->getH(), RGBA8(255, 255, 255, 255));    
    }
    else {
        vita2d_draw_rectangle(model_instance->getX(), model_instance->getY(), model_instance->getW(), model_instance->getH(), RGBA8(255, 255, 255, 255));
        this->_firstAnim = true;
    }
    // a = std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - this->_lastAnimTime).count());
    // vita2d_pgf_draw_text(this->_pgf, 400, 400, RGBA8(0,255,0,255), 1.0f, a.c_str());
    vita2d_pgf_draw_text(this->_pgf, model_instance->getX(), model_instance->getY() + vita2d_pgf_text_height(this->_pgf, 1, model_instance->getText()->c_str()), RGBA8(0,255,0,255), 1.0f, model_instance->getText()->c_str());
}