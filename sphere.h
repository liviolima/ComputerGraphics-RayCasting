#ifndef __SPHERE_H__
#define __SPHERE_H__

#include "numbervector.h"
#include "color.h"
#include "object.h"

#include <cmath>

class Sphere : public Object {
public:
    Sphere();
    Sphere(NumberVector center, double radius, Color color);

    NumberVector getCenter() const;
    double getRadius() const;

    double findIntersection(NumberVector origin, NumberVector direction);
    NumberVector getNormalAt(NumberVector point);

    NumberVector center;
    double radius;
    Color color;

    virtual void scale(double x, double y, double z);
    virtual void translate(double x, double y, double z);
    virtual Color getColor();

};

#endif
