#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <Artemis/Component.h>
#include "engine/Vector2D.h"
namespace components {

/**
 * @brief Represents the spacial properties of an object (position, scale and rotation).
 */
class Transform : public artemis::Component {
public:
    Transform();
    virtual ~Transform();

    void                                setPosition(float x, float y);
    void                                setPosition(Vector2D& position);
    void                                setScale(float x, float y);
    void                                setScale(Vector2D& scale);
    void                                setRotation(float angle);

    Vector2D                            getPosition();
    Vector2D                            getRelativePosition();
    Vector2D                            getScale();
    float                               getRotation();

    void                                move(Vector2D& direction);
    void                                rotate(float angle);

    void                                setParent(Transform* parent);
    void                                unsetParent();

private:
    Vector2D                            position;   // Represents the center point of the object
    Vector2D                            scale;      // Scale in the x and y axis. Used to multiply width and height of any RenderizableAsset attached
    float                               rotation;   // Rotation around the center point (position)

    Transform*                          parent;     // Used for GameObject hierarchy
};

}

#endif // TRANSFORM_H
