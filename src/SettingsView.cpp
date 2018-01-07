#include "SettingsView.hpp"

SettingsView::SettingsView()
    : _buttons(2) {
    this->_pgf = vita2d_load_default_pgf();
}

SettingsView::~SettingsView() {
    vita2d_free_pgf(this->_pgf);
}

void SettingsView::render(const SettingsModel* model) {
    if (!model)
        return;
    vita2d_start_drawing();
    vita2d_clear_screen();
    vita2d_pgf_draw_text(this->_pgf, 700, 30, RGBA8(0,255,0,255), 1.0f, "Settings");

    for (unsigned int i = 0; i < model->getButtons()->size(); i++)
    {
        if (i < this->_buttons.size())
            this->_buttons[i].render((*model->getButtons())[i].getInstance());
    }
    vita2d_end_drawing();
    vita2d_swap_buffers();
};