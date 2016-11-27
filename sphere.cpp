#include "sphere.h"
#include <iostream>

Sphere::Sphere(){
    this->center = NumberVector(0.0, 0.0, 0.0);
    this->radius = 1.0;
    this->color = Color(0.5, 0.5, 0.5, 0);

}

Sphere::Sphere(NumberVector center, double radius, Color color2){
    this->center = center;
    this->radius = radius;

    this->color.red = color2.red;
    this->color.green = color2.green;
    this->color.blue = color2.blue;
    this->color.integer = color2.integer;

}

NumberVector Sphere::getCenter() const {
    return this->center;
}

double Sphere::getRadius() const {
    return this->radius;
}

double Sphere::findIntersection(NumberVector origin, NumberVector direction){
    double rayOriginX = origin.x;
    double rayOriginY = origin.y;
    double rayOriginZ = origin.z;

    double rayDirectionX = direction.x;
    double rayDirectionY = direction.y;
    double rayDirectionZ = direction.z;

    double centerX = this->center.x;
    double centerY = this->center.y;
    double centerZ = this->center.z;

    double a = 1.0; //Normalized.
    double b = (2*(rayOriginX - centerX)*rayDirectionX) + (2*(rayOriginY - centerY)*rayDirectionY) + (2*(rayOriginZ - centerZ)*rayDirectionZ);
    double c = std::pow(rayOriginX - centerX, 2) + std::pow(rayOriginY - centerY, 2) + std::pow(rayOriginZ - centerZ, 2) - (this->radius*this->radius);

    double discriminant = b*b - 4 *c; //b^2 -4ac

    if (discriminant > 0){
        //The ray intersects the sphere, intersecting two sides.

        //First root
        double root1 = ((-1*b - std::sqrt(discriminant))/2) - 0.00001;
        if (root1 > 0){
            //The first root is the smallest positive root.
            return root1;
        }
        else {
            //The second root is the smallest positive root.
            double root2 = ((std::sqrt(discriminant) - b)/2) - 0.00001;
            return root2;
        }
    }
    else {
        //The ray missed the sphere.
        return -1;
    }
}

NumberVector Sphere::getNormalAt(NumberVector point) {
    //Normal always points away from center of sphere.
    NumberVector normal = point.add(this->center.negative()).normalize();
    return normal;
}

Color Sphere::getColor(){
    return this->color;
}

void Sphere::scale(double x, double y, double z){
    //qDebug() << "test-plane";
}

void Sphere::translate(double x, double y, double z){
    //qDebug() << "test-plane";
}

