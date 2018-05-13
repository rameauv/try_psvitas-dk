#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <psp2/kernel/processmgr.h>
//debug
#include "debugScreen.h"
#define printf psvDebugScreenPrintf

#include "Services.hpp"
#include "GraphicVita.hpp"

extern "C"
{
    unsigned int sleep(unsigned int seconds)
    {
        sceKernelDelayThread(seconds*1000*1000);
        return 0;
    }

    int usleep(useconds_t usec)
    {
        sceKernelDelayThread(usec);
        return 0;
    }

    void __sinit(struct _reent *);
}

__attribute__((constructor(101)))
void pthread_setup(void) 
{
    pthread_init();
    __sinit(_REENT);
}

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