#include "MainMenuView.hpp"

MainMenuView::MainMenuView()
    : _buttons(3) {
    this->_pgf = vita2d_load_default_pgf();
}

MainMenuView::~MainMenuView() {
    vita2d_free_pgf(this->_pgf);
}

void MainMenuView::render(const MainMenuModel* model) {
    if (!model)
        return;
    vita2d_start_drawing();
    vita2d_clear_screen();
    vita2d_pgf_draw_text(this->_pgf, 400, 30, RGBA8(0,255,0,255), 1.0f, model->_debug.c_str());

    for (unsigned int i = 0; i < model->getButtons()->size(); i++) {
        if (i < this->_buttons.size())
            this->_buttons[i].render((*model->getButtons())[i].getInstance());
    }
    vita2d_end_drawing();
    vita2d_swap_buffers();
};