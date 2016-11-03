#ifndef SCENE_H
#define SCENE_H
#include "leg.h"
#include "toptable.h"
#include "xobject.h"

class Scene
{
    Leg leg1, leg2, leg3, leg4;
    TopTable toptable;
    Xobject xobject;

    int ilumination_xyz_position[3];

public:
    Scene();
};

#endif // SCENE_H
