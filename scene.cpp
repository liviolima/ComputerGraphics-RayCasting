#include "scene.h"
#include "triangle.h"


Scene::Scene()
{
     //This must contain ours objects and the lighting

      ilumination_xyz_position = NumberVector(20, 30, 60);

      ambient  = NumberVector(0.8, 0.5, 0.1);
      diffuse  = NumberVector(0.8, 0.6, 0.4);
      specular = NumberVector(0.8, 0.6, 0.4);



}
