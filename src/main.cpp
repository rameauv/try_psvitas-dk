/*
 * Copyright (c) 2015 Sergi Granell (xerpi)
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <psp2/ctrl.h>
#include <psp2/kernel/processmgr.h>

#include <vita2d.h>

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
	vita2d_init();

	globals::global_state = globals::STATE_RUN;

	globals::sceneManager.load(ISceneControler::SPLASH_SCREEN);
	while (globals::global_state == globals::STATE_RUN)
	{
		 globals::sceneManager.getSceneControler()->handleInput();
		 globals::sceneManager.clean();
	}
	/*
	 * vita2d_fini() waits until the GPU has finished rendering,
	 * then we can free the assets freely.
	 */
	vita2d_fini();

	sceKernelExitProcess(0);
	return 0;
}
