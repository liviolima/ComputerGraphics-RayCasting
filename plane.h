#ifndef PLANE_H
#define PLANE_H
#include "object.h"
#include "color.h"


class Plane: public Object
{
public:
    Plane();
    Plane(NumberVector normalPlane, double distanceValue, Color colorValue);


    NumberVector normal;
    double distance;
    Color color;



    NumberVector getPlaneNormal();
    double getPlaneDistance();

    virtual void scale(double x, double y, double z);
    virtual void translate(double x, double y, double z);
    virtual double findIntersection(NumberVector origin, NumberVector direction);
    virtual Color getColor();

    NumberVector getNormalAt();



};

#endif // PLANE_H
