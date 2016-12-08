#ifndef SCENE_H
#define SCENE_H
#include "triangle.h"

class Scene
{

public:
    Scene();

    Triangle triangle;
    NumberVector ilumination_xyz_position;

    NumberVector ambient, diffuse, specular;
};

#endif // SCENE_H
