#ifndef NUMBERVECTOR_H
#define NUMBERVECTOR_H

class NumberVector
{
public:
    double x,y,z;

    NumberVector(double, double, double);
    NumberVector normalize();
    NumberVector cross_product();
    NumberVector add(NumberVector other);
};

#endif // NUMBERVECTOR_H
