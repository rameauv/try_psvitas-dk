#include "GameView.hpp"

GameView::GameView() {
    this->_pgf = vita2d_load_default_pgf();
}

GameView::~GameView() {
    vita2d_free_pgf(this->_pgf);
}

void GameView::render(const GameModel* model) {
    if (!model)
        return;
    vita2d_start_drawing();
    vita2d_clear_screen();

    vita2d_draw_rectangle(model->getX(), model->getY(), 400, 250, RGBA8(255, 0, 0, 255));
    vita2d_draw_rectangle(680, 350, 100, 150, RGBA8(0, 0, 255, 255));
    vita2d_draw_fill_circle(200, 420, 100, RGBA8(0, 255,0 ,255));

    vita2d_draw_line(500, 30, 800, 300, RGBA8(255, 0, 255, 255));

    vita2d_pgf_draw_text(this->_pgf, 700, 30, RGBA8(0,255,0,255), 1.0f, "PGF Font sample!");

    vita2d_end_drawing();
    vita2d_swap_buffers();
};