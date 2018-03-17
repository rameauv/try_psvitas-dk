#include "SceneControler.hpp"

SceneControler::SceneControler(Scene::sceneControlerId_e id)
    : id(id) {

}

Scene::sceneControlerId_e SceneControler::getId() {
    return (id);
}