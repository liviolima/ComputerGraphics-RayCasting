#ifndef OBJECT_H
#define OBJECT_H
#include "numbervector.h"
#include <iostream>
#include <vector>
#include "triangle.h"
#include "material.h"

class Object
{
public:
    Object();

    std::vector<Triangle*> triangles;

    virtual void scale(double x, double y, double z) = 0;
    virtual void translate(double x, double y, double z) = 0;
    virtual double findIntersection(NumberVector origin, NumberVector direction) = 0;
    virtual Material getMaterial();
};

#endif // OBJECT_H
