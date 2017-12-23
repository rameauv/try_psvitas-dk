#pragma once
#ifndef SCENECONTROLER_HPP
#define SCENECONTROLER_HPP

#include "ISceneControler.hpp"
class SceneControler : public ISceneControler
{
    protected:
        const ISceneControler::sceneControlerId_e id;
    protected:
        SceneControler(ISceneControler::sceneControlerId_e id);
    public:
        virtual ISceneControler::sceneControlerId_e getId();
        virtual int handleInput() = 0;
};
#endif /* SCENECONTROLER_HPP */
