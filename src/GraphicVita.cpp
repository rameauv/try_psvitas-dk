#include "GraphicVita.hpp"

int Graphic::init() {
    vita2d_init();
    return (0);
}

int Graphic::deinit() {
    	/*
	 * vita2d_fini() waits until the GPU has finished rendering,
	 * then we can free the assets freely.
	 */
	vita2d_fini();
    return (0);
}