#include "material.h"

Material::Material()
{
    ka = NumberVector (0, 0, 0);
    ks = NumberVector (0, 0, 0);
    kd = NumberVector (0, 0, 0);
    alpha = 1.0;


}
/*
Material::Material(double new_ka[4], double new_kd[4], double new_ks[4])
{
    ka[0] = new_ka[0];
    ka[1] = new_ka[1];
    ka[2] = new_ka[2];
    ka[3] = new_ka[3];

    kd[0] = new_kd[0];
    kd[1] = new_kd[1];
    kd[2] = new_kd[2];
    kd[3] = new_kd[3];

    ks[0] = new_ks[0];
    ks[1] = new_ks[1];
    ks[2] = new_ks[2];
    ks[3] = new_ks[3];

}
*/

Material::Material(NumberVector new_ka, NumberVector new_kd, NumberVector new_ks, double new_alpha){
    ka = new_ka;
    ks = new_ks;
    kd = new_kd;
    alpha = new_alpha;
}


