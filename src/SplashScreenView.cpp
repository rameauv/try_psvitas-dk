#include "SplashScreenView.hpp"

SplashScreenView::SplashScreenView()
{
    this->_pgf = vita2d_load_default_pgf();
}

SplashScreenView::~SplashScreenView()
{
    vita2d_free_pgf(this->_pgf);
}

void SplashScreenView::render()
{
    vita2d_start_drawing();
    vita2d_clear_screen();
    vita2d_pgf_draw_text(this->_pgf, 200, 100, RGBA8(0,255,0,255), 1.0f, "Press start");
    vita2d_end_drawing();
    vita2d_swap_buffers();
};