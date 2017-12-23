#pragma once
#ifndef ISCENECONTROLER_HPP
#define ISCENECONTROLER_HPP

class ISceneControler
{
    public:
        typedef enum sceneControlerId
        {
            UNKNOW,
            SPLASH_SCREEN,
            TITLE_MENU,
            MAIN_MENU,
        } sceneControlerId_e;
    public:
        virtual sceneControlerId_e getId() = 0;
        virtual int handleInput() = 0;
};
#endif /* ISCENECONTROLER_HPP */
