#ifndef OBJECT_H
#define OBJECT_H
#include "numbervector.h"
#include "color.h"
#include <iostream>
#include <vector>
#include "triangle.h"

class Object
{
public:
    Object();

    std::vector<Triangle*> triangles;

    virtual void scale(double x, double y, double z) = 0;
    virtual void translate(double x, double y, double z) = 0;
    virtual double findIntersection(NumberVector origin, NumberVector direction) = 0;
    virtual Color getColor();
};

#endif // OBJECT_H
