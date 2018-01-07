#pragma once

class ISceneControler
{
    public:
        typedef enum sceneControlerId {
            UNKNOW,
            SPLASH_SCREEN,
            TITLE_MENU,
            MAIN_MENU,
            SETTINGS,
            GAME
        } sceneControlerId_e;
    public:
        virtual sceneControlerId_e getId() = 0;
        virtual int handleInput() = 0;
};