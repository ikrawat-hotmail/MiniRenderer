#ifndef RIGID_BODY_H
#define RIGID_BODY_H

/*
    This rigid body is a container.
    It comprises several Rectangles and Circles relative to a center of mass.
    The rigid bodies will be tied relative to this center of mass.

    Somehow this is called composite body!!!
    Duh!!!
*/

#include <vector>
#include <memory>
#include "polygon2D.h"
#include "vector2f.h"
#include "rect.h"
#include "circle.h"
#include "collision.h"

class RigidBody2D {
public:
    Vec2f mPosition;                    // global position
    Vec2f mVelocity;                    // global velocity
    std::string mId;
    float mOrientation;

    // TODO:
    // Textures, rotation, mass, gravity, etc
    // other physics

    std::vector<std::shared_ptr<Polygon2D>> mPolygons;

    RigidBody2D(Polygon2D& poly);
    RigidBody2D();

    BodyType getType() const;

private:
    enum BodyType mType;

private:
    
};
#endif
