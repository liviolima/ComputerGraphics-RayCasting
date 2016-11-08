#ifndef OBSERVER_H
#define OBSERVER_H
#include "numbervector.h"

class Camera
{    

public:    
    NumberVector camera_xyz_position;
    NumberVector look_at_xyz_position;
    NumberVector up_xyz;
    Camera();
};

#endif // CAMERA_H
