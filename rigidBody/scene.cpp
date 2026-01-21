#include "scene.h"
#include "modelLoader.h"


Scene::Scene(int id) : mSceneId(id) {}

// for now I am just using some simple path
// will use some file parsing method
int Scene::populatePaths() {
    mSceneNamePath[mSceneId] = "/local/mnt/workspace/learn/irawat/learn/re/resources/testScenes/scene1";
    return 0;
}

int Scene::init() {
    ModelLoader& modelloader = ModelLoader::getInstance();

    if (mSceneNamePath.size() != 0)
        modelloader.loadModels(mRigidBody2DPtr, mSceneNamePath[mSceneId]);
    return 0;
}
