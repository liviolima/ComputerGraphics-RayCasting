#ifndef MATERIAL_H
#define MATERIAL_H
#include "numbervector.h"

class Material
{
public:
    Material();
    //Material(double new_ka[4], double new_kd[4], double new_ks[4]);
    Material(NumberVector new_ka, NumberVector new_kd, NumberVector new_ks, double new_alpha);
    /*
    [0] red
    [1] green
    [2] blue
    [3] alpha
    */
    //double ka[4], kd[4], ks[4];

    NumberVector ka, kd, ks;
    double alpha;

};

#endif // MATERIAL_H
