#ifndef OBSERVER_H
#define OBSERVER_H
#include "numbervector.h"
#include "scene.h"
#include <vector>
#include "object.h"

class Camera
{    


public:    
    Camera();
    Camera(NumberVector pos, NumberVector look_at, NumberVector up);

    Scene scene;

    NumberVector camera_xyz_position;
    NumberVector look_at_xyz_position;
    NumberVector up_xyz;

    NumberVector camera_look_direction_k;
    NumberVector camera_right_direction_i;
    NumberVector camera_down_direction_j;

    double coordinatesWorldToCamera[4][4];
    double coordinatesCameraToWorld[4][4];


    void transformVertexesFromCoordinatesWorldToCamera(std::vector<Object*> scene_objects);
    void transformVertexesFromCoordinatesCameraToWorld(std::vector<Object*> scene_objects);




};

#endif // CAMERA_H
