#ifndef SCENE_H
#define SCENE_H
#include "triangle.h"

class Scene
{

public:
    Scene();

    Triangle triangle;
    NumberVector ilumination_xyz_position;

    double ambient[4], diffuse[4], specular[4];
};

#endif // SCENE_H
