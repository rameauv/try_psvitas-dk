#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#ifdef VITA
	#include <psp2/kernel/processmgr.h>
#endif
//debug
#ifdef VITA
	#include "debugScreen.h"
	#define printf psvDebugScreenPrintf
#endif
#include "globals.hpp"
#include "Graphic.hpp"

int main()
{
	#ifdef VITA
		psvDebugScreenInit();
	#endif
	Graphic::init();
	globals::globalState = globals::STATE_RUN;
	globals::sceneManager.load(ISceneControler::SPLASH_SCREEN);
	while (globals::globalState == globals::STATE_RUN)
	{
		globals::sceneManager.getSceneControler()->handleInput();
		globals::sceneManager.clean();
	}
	Graphic::deinit();
	#ifdef VITA
		sceKernelExitProcess(0);
	#endif
	return 0;
}