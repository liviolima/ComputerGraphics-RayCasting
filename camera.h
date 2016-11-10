#ifndef OBSERVER_H
#define OBSERVER_H
#include "numbervector.h"

class Camera
{    


public:    
    NumberVector camera_xyz_position;
    NumberVector look_at_xyz_position;
    NumberVector up_xyz;

    NumberVector camera_look_direction;
    NumberVector camera_right_direction;
    NumberVector camera_down_direction;

    Camera();
    Camera(NumberVector pos, NumberVector look_at, NumberVector up);
    double coordinatesWorldToCamera[4][4];


};

#endif // CAMERA_H
