#include "numbervector.h"
#include <math.h>

NumberVector::NumberVector(){}


NumberVector::NumberVector(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

NumberVector NumberVector::normalize(){
    double s = sqrt(x*x + y*y + z*z);
    return NumberVector(x/s, y/s, z/s);
}

NumberVector NumberVector::cross_product(NumberVector other){
    // CROSSPRODUCT of Other x Self.
    // If you do Self x Other, the result will be anticommutative
    // e.g Other x Self = a, then Self x Other = -a

    return NumberVector(
                y * other.z - z * other.y,
                z * other.x - x * other.z,
                x * other.y - y * other.x);
}

NumberVector NumberVector::multiply(double amount){
    this->x = this->x*amount;
    this->y = this->y*amount;
    this->z = this->z*amount;
}

double NumberVector::dot_product(NumberVector other){
    return (x * other.x + y * other.y + z * other.z);
}

NumberVector NumberVector::add(NumberVector other){
    return NumberVector(x + other.x, y + other.y, z + other.z);
}

NumberVector NumberVector::sub(NumberVector other){
    return NumberVector(x - other.x, y - other.y, z - other.z);
}


