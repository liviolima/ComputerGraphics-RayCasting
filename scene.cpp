#include "scene.h"
#include "triangle.h"


Scene::Scene()
{
    //This must contain ours objects and the lighting.,

    ilumination_xyz_position = NumberVector(20, 30, 40);

      ambient[0] = 0.0f;
      ambient[1] = 0.0f;
      ambient[2] = 0.0f;
      ambient[3] = 1.0f;

      diffuse[0] = 1.0f;
      diffuse[1] = 1.0f;
      diffuse[2] = 1.0f;
      diffuse[3] = 1.0f;

      specular[0] = 1.0f;
      specular[1] = 1.0f;
      specular[2] = 1.0f;
      specular[3] = 1.0f;

      //It is necessary calculate vector n,l,v,r


}
