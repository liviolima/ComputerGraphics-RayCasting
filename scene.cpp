#include "scene.h"
#include "leg.h"



Scene::Scene()
{
    //deve possuir objeto e a iluminacao

    ilumination_xyz_position = {0, 0, 0};

    leg1.translate(0,0,0);
    leg2.translate(10,0,0);
    leg3.translate(0,0,5);
    leg4.translate(10,0,5);


}
