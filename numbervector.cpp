#include "numbervector.h"

NumberVector::NumberVector(){}


NumberVector::NumberVector(double x, double y, double z){
    this->x = x;
    this->y = y;
    this->z = z;
}

NumberVector NumberVector::normalize(){
    // TODO
    return NumberVector(1,1,1);
}

NumberVector NumberVector::cross_product(NumberVector other){
    // CROSSPRODUCT of Other x Self.
    // If you do Self x Other, the result will be anticommutative
    // e.g Other x Self = a, then Self x Other = -a
    return NumberVector(1,1,1);
}

NumberVector NumberVector::add(NumberVector other){
    return NumberVector(1,1,1);
}

