#ifndef MATERIAL_H
#define MATERIAL_H

class Material
{
public:
    Material();
    Material(double new_ka[4], double new_kd[4], double new_ks[4]);

    /*
    [0] red
    [1] green
    [2] blue
    [3] alpha
    */
    double ka[4], kd[4], ks[4];

};

#endif // MATERIAL_H
