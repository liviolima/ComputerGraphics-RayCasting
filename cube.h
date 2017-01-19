#ifndef CUBE_H
#define CUBE_H
#include "numbervector.h"
#include "object.h"
#include "triangle.h"
#include "vector"
#include "material.h"

class Cube : public Object
{
public:
    Cube();
    Cube(double size, Material material);

    Triangle trianglesv[12];

    Material material;

    NumberVector ka_default = NumberVector(0.6, 0.6, 0.6);
    NumberVector kd_default = NumberVector(0.4, 0.4, 0.4);
    NumberVector ks_default = NumberVector(0.4, 0.4, 0.4);
    Material defaultMaterial = Material(ka_default, kd_default, ks_default, 2.0);

    double size_x, size_y, size_z;

    void scale(double x, double y, double z);
    void translate(double x, double y, double z);
    void rotate_x(double angle);
    void rotate_y(double angle);
    void rotate_z(double angle);
    void shearing_planeZY_push_Z(double angle);


    virtual double findIntersection(NumberVector origin, NumberVector direction);
    virtual Material getMaterial();

    //Vertexes
    NumberVector v1, v2, v3, v4, v5, v6, v7, v8;

};

#endif // CUBE_H
