#include "ray.h"

Ray::Ray()
{
    Pinitial.x = 0;
    Pinitial.y = 0;
    Pinitial.z = 0;

    v.x = 0;
    v.y = 0;
    v.z = 0;
}

void Ray::setPinitial(double x, double y, double z){
    Pinitial.x = x;
    Pinitial.y = y;
    Pinitial.z = z;
}

void Ray::calculateV(NumberVector P){
    v.x = P.x - v.x;
    v.y = P.y - v.y;
    v.z = P.z - v.z;

    v.normalize();
}
