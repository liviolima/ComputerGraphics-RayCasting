#include "plane.h"

Plane::Plane()
{
    normal = NumberVector(1,0,0);
    distance = 1.0;
    color = Color(134.0, 23.0, 2.0, 0);
}


Plane::Plane(NumberVector normalValue, double distanceValue, Color colorValue)
{
    normal = normalValue;
    distance = distanceValue;
    color = colorValue;
}


void Plane::scale(double x, double y, double z){
    //qDebug() << "test-plane";
}

void Plane::translate(double x, double y, double z){
    //qDebug() << "test-plane";
}

double Plane::findIntersection(NumberVector origin, NumberVector direction){
    double a = direction.dot_product(normal);

    if(a == 0){
        //ray is parallel to the plane
        return -1;
    }
    else{
        double b = normal.dot_product(origin.add(normal.multiply(distance).negative()));
        return -1*b/a;
    }
}

NumberVector Plane::getNormalAt(){
    return normal;
}

Color Plane::getColor(){
    return color;
}
