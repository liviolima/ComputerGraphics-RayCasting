#include "scene.h"
#include "triangle.h"


Scene::Scene()
{
    //This must contain ours objects and the lighting.,

      ilumination_xyz_position = NumberVector(20, 30, 40);

      ambient  = NumberVector(0.7, 0.7, 0.7);
      diffuse  = NumberVector(0.8, 0.3, 0.3);
      specular = NumberVector(0.8, 0.3, 0.3);




}
