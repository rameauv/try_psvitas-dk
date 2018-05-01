#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <psp2/kernel/processmgr.h>
//debug
#include "debugScreen.h"
#define printf psvDebugScreenPrintf

#include "Services.hpp"
#include "GraphicVita.hpp"

int main()
{
	psvDebugScreenInit();
	Services::soundManger.init();
	Services::graphic.init();
	Services::state = Services::STATE_RUN;
	Services::sceneManager.load(Scene::SPLASH_SCREEN);
	while (Services::state == Services::STATE_RUN) {
		Services::sceneManager.getSceneControler()->handleInput();
		Services::sceneManager.clean();
	}
	Services::graphic.deinit();
		sceKernelExitProcess(0);
	return 0;
}