#ifndef SCENE_H
#define SCENE_H
#include "triangle.h"

class Scene
{

public:
    Scene();

    Triangle triangle;
    int ilumination_xyz_position[3];
};

#endif // SCENE_H
