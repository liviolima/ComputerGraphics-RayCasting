#ifndef NUMBERVECTOR_H
#define NUMBERVECTOR_H

class NumberVector
{
public:
    double x,y,z;

    NumberVector();
    NumberVector(double, double, double);
    NumberVector normalize();
    NumberVector cross_product(NumberVector other);
    NumberVector add(NumberVector other);
};

#endif // NUMBERVECTOR_H
