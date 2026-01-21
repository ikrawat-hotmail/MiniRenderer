#include <vector>
#include <map>
#include "rigidBody2D.h"


class Scene {
private:
    // vector of shared pointers of RigidBody2D
    std::vector<std::shared_ptr<RigidBody2D>> mRigidBody2DPtr;
    std::map<int, std::string> mSceneNamePath;                      // scene number and path map

    int mSceneId;
    int populatePaths();

public:
    Scene(int id);
    int init();

    // kinda updation when vsync is received
    void onSyncUpdate();
};
