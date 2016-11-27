#ifndef OBJECT_H
#define OBJECT_H
#include "numbervector.h"
#include "color.h"
#include "triangle.h"
#include <vector>
#include <iostream>
using namespace std;

class Object
{
public:

    vector<Triangle> triangles;


    Object();



    virtual void scale(double x, double y, double z) = 0;
    virtual void translate(double x, double y, double z) = 0;
    virtual double findIntersection(NumberVector origin, NumberVector direction) = 0;
    virtual Color getColor();
};

#endif // OBJECT_H
