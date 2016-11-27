#ifndef CUBE_H
#define CUBE_H
#include "numbervector.h"
#include "color.h"
#include "object.h"
#include "triangle.h"
#include "vector"

class Cube : public Object
{
public:
    Cube();



    Color color;

    void scale(double x, double y, double z);
    void translate(double x, double y, double z);
    virtual double findIntersection(NumberVector origin, NumberVector direction);
    virtual Color getColor();

};

#endif // CUBE_H
