#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <psp2/kernel/processmgr.h>
//debug
#include "debugScreen.h"
#define printf psvDebugScreenPrintf

#include "globals.hpp"
#include "GraphicVita.hpp"

int main()
{
	psvDebugScreenInit();
	Graphic::init();
	globals::globalState = globals::STATE_RUN;
	globals::sceneManager.load(Scene::SPLASH_SCREEN);
	while (globals::globalState == globals::STATE_RUN) {
		globals::sceneManager.getSceneControler()->handleInput();
		globals::sceneManager.clean();
	}
	Graphic::deinit();
		sceKernelExitProcess(0);
	return 0;
}