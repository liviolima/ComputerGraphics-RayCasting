#include "cube.h"
#include "numbervector.h"
#include <iostream>

Cube::Cube()
{
    color.red = 255.0;
    color.green = 0.0;
    color.blue = 0.0;

    double x = 1;
    NumberVector v1 = NumberVector( x  , -x,  x);
    NumberVector v2 = NumberVector( x  , -x, -x);
    NumberVector v3 = NumberVector(-x  , -x, -x);
    NumberVector v4 = NumberVector(-x  , -x,  x);
    NumberVector v5 = NumberVector( x  ,  x,  x);
    NumberVector v6 = NumberVector( x  ,  x, -x);
    NumberVector v7 = NumberVector(-x  ,  x, -x);
    NumberVector v8 = NumberVector(-x  ,  x,  x);


    triangles[0] = Triangle(v4, v5, v8);
    triangles[1] = Triangle(v1, v4, v5);
    triangles[2] = Triangle(v1, v2, v6);
    triangles[3] = Triangle(v1, v5, v6);
    triangles[4] = Triangle(v5, v6, v8);
    triangles[5] = Triangle(v6, v7, v8);

    triangles[6] = Triangle(v3, v4, v7);
    triangles[7] = Triangle(v4, v7, v8);
    triangles[8] = Triangle(v1, v3, v4);
    triangles[9] = Triangle(v2, v3, v6);
    triangles[10] = Triangle(v2, v3, v6);
    triangles[11] = Triangle(v3, v6, v1);


}

Cube::Cube(double size, Color newColor)
{
    color.red = newColor.red;
    color.green = newColor.green;
    color.blue = newColor.blue;
    double x = size;
    NumberVector v1 = NumberVector( x  , -x,  x);
    NumberVector v2 = NumberVector( x  , -x, -x);
    NumberVector v3 = NumberVector(-x  , -x, -x);
    NumberVector v4 = NumberVector(-x  , -x,  x);
    NumberVector v5 = NumberVector( x  ,  x,  x);
    NumberVector v6 = NumberVector( x  ,  x, -x);
    NumberVector v7 = NumberVector(-x  ,  x, -x);
    NumberVector v8 = NumberVector(-x  ,  x,  x);


    triangles[0] = Triangle(v4, v5, v8);
    triangles[1] = Triangle(v1, v4, v5);
    triangles[2] = Triangle(v1, v2, v6);
    triangles[3] = Triangle(v1, v5, v6);
    triangles[4] = Triangle(v5, v6, v8);
    triangles[5] = Triangle(v6, v7, v8);

    triangles[6] = Triangle(v3, v4, v7);
    triangles[7] = Triangle(v4, v7, v8);
    triangles[8] = Triangle(v1, v3, v4);
    triangles[9] = Triangle(v2, v3, v6);
    triangles[10] = Triangle(v2, v3, v6);
    triangles[11] = Triangle(v3, v6, v1);


}



Color Cube::getColor(){
    return this->color;
}

void Cube::scale(double x, double y, double z){
    //qDebug() << "test-plane";
}

void Cube::translate(double x, double y, double z){
    //qDebug() << "test-plane";
}

double Cube::findIntersection(NumberVector origin, NumberVector direction){
    double x = 0.0;
    return x;
}
