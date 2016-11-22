#ifndef RAY_H
#define RAY_H
#include "numbervector.h"

class Ray
{
public:
    Ray();
    NumberVector Pinitial;
    NumberVector v;

    void setPinitial(double x, double y, double z);
    void calculateV(NumberVector P);

};

#endif // RAY_H
