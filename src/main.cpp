/*
 * Copyright (c) 2015 Sergi Granell (xerpi)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include <vita2d.h>
//debug
#include "debugScreen.h"
#define printf psvDebugScreenPrintf

//sound management headers
#include <stdint.h>
#include <math.h>
#include <psp2/audioout.h>
#include "soloud.h"
#include "soloud_wav.h"
#include "soloud_speech.h"
//

#include "globals.hpp"
#include "SplashScreenControler.hpp"
#include "MainMenuControler.hpp"

int main()
{
	// Key key;
	// SceCtrlData pad;
	// memset(&pad, 0, sizeof(pad));

	// while (1) {
	// 	sceCtrlPeekBufferPositive(0, &pad, 1);
	// 	key.update(pad.buttons);
	// 	// printf("Buttons:\n");
	// 	if (key.getPressed() & SCE_CTRL_START)
	// 		printf("Buttons:%08X == %08X\n", key.getDown(), key.getPressed());
	// 	sceKernelDelayThread(1000 * 100);
	// }



	psvDebugScreenInit();
	vita2d_init();
    vita2d_pgf *pgf;
    pgf = vita2d_load_default_pgf();
	globals::globalState = globals::STATE_RUN;
	unsigned long long a = 0;
    std::string b;
	// while (1)
	// {
    //     globals::sceneManager.load(ISceneControler::MAIN_MENU);
    //     if (globals::sceneManager.getNewSceneControler())
    //         ((MainMenuControler*)globals::sceneManager.getNewSceneControler())->init();
	// 	globals::sceneManager.clean();
	// 	sceKernelDelayThread(1000 * 100);
	// }
	globals::sceneManager.load(ISceneControler::SPLASH_SCREEN);
	while (globals::globalState == globals::STATE_RUN)
	{
		globals::sceneManager.getSceneControler()->handleInput();
		globals::sceneManager.load(ISceneControler::MAIN_MENU);
        if (globals::sceneManager.getNewSceneControler())
            ((MainMenuControler*)globals::sceneManager.getNewSceneControler())->init();
		 globals::sceneManager.clean();
    	b = std::to_string(a++);
		vita2d_start_drawing();
		vita2d_clear_screen();
    	vita2d_pgf_draw_text(pgf, 400, 400, RGBA8(0,255,0,255), 1.0f, b.c_str());
		vita2d_end_drawing();
		vita2d_swap_buffers();
		sceKernelDelayThread(1000 * 100);
	}
	/*
	 * vita2d_fini() waits until the GPU has finished rendering,
	 * then we can free the assets freely.
	 */
    vita2d_free_pgf(pgf);
	vita2d_fini();

	sceKernelExitProcess(0);
	return 0;
}
