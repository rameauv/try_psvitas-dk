#include "SceneControler.hpp"

SceneControler::SceneControler(ISceneControler::sceneControlerId_e id)
    : id(id) {

}

ISceneControler::sceneControlerId_e SceneControler::getId() {
    return (id);
}