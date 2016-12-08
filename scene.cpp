#include "scene.h"
#include "triangle.h"


Scene::Scene()
{
    //This must contain ours objects and the lighting.,

      ilumination_xyz_position = NumberVector(20, 30, 40);

      ambient  = NumberVector(0.5, 0.5, 0.5);
      diffuse  = NumberVector(1.0, 1.0, 1.0);
      specular = NumberVector(1.0, 1.0, 1.0);




}
