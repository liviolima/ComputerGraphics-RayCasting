#ifndef TRIANGLE_H
#define TRIANGLE_H
#import "numbervector.h"
#import "ray.h"
#include "material.h"

class Triangle
{
public:
    Triangle();
    Triangle(NumberVector v1, NumberVector v2, NumberVector v3);
    Triangle(NumberVector v1, NumberVector v2, NumberVector v3, Material material);

    NumberVector vertex[3];
    NumberVector normal_vector;

    Material material;
    double T_intersection;

    void scale(double x, double y, double z);
    void translate(double x, double y, double z);
    double findIntersection(NumberVector origin, NumberVector direction);
    double get_T_intersection();
    void printVertexes();
    NumberVector getNormal();
    void setVertexes(NumberVector new_value_for_vertex[3]);


};

#endif // TRIANGLE_H
