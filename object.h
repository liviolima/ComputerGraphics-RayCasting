#ifndef OBJECT_H
#define OBJECT_H


class Object
{
public:
    Object();

    virtual void scale(double x, double y, double z) = 0;
    virtual void translate(double x, double y, double z) = 0;
};

#endif // OBJECT_H
