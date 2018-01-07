#include "MainMenuView.hpp"

MainMenuView::MainMenuView()
    : _buttons(3) {
}

MainMenuView::~MainMenuView() {
}

void MainMenuView::render(const MainMenuModel* model) {
    if (!model)
        return;
    vita2d_start_drawing();
    vita2d_clear_screen();
    for (unsigned int i = 0; i < model->getButtons()->size(); i++) {
        if (i < this->_buttons.size())
            this->_buttons[i].render((*model->getButtons())[i].getInstance());
    }
    vita2d_end_drawing();
    vita2d_swap_buffers();
};