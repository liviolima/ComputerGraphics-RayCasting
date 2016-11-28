#include "cube.h"
#include "numbervector.h"

Cube::Cube()
{
    color.red = 255.0;
    color.green = 0.0;
    color.blue = 0.0;
/*
    v 1.000000 -1.000000 -1.000000
    v 1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 1.000000
    v -1.000000 -1.000000 -1.000000
    v 1.000000 1.000000 -0.999999
    v 0.999999 1.000000 1.000001
    v -1.000000 1.000000 1.000000
    v -1.000000 1.000000 -1.000000


    f 2 3 4
    f 8 7 6
    f 5 6 2
    f 6 7 3
    f 3 7 8
    f 1 4 8
    f 1 2 4
    f 5 8 6
    f 1 5 2
    f 2 6 3
    f 4 3 8
    f 5 1 8
*/
    double x = 1;

    NumberVector v1 = NumberVector( x  , -x,  -x);
    NumberVector v2 = NumberVector( x  , -x,   x);
    NumberVector v3 = NumberVector(-x  , -x,   x);
    NumberVector v4 = NumberVector(-x  , -x,  -x);
    NumberVector v5 = NumberVector( x  ,  x,  -x);
    NumberVector v6 = NumberVector( x  ,  x,   x);
    NumberVector v7 = NumberVector(-x  ,  x,   x);
    NumberVector v8 = NumberVector(-x  ,  x,  -x);

    trianglesv[0] = Triangle(v2, v3, v4, redColor);
    trianglesv[1] = Triangle(v8, v7, v6, darkRedColor);
    trianglesv[2] = Triangle(v5, v6, v2, greenColor);
    trianglesv[3] = Triangle(v6, v7, v3, darkGreenColor);
    trianglesv[4] = Triangle(v3, v7, v8, blueColor);
    trianglesv[5] = Triangle(v1, v4, v8, darkBlueColor);
    trianglesv[6] = Triangle(v1, v2, v4, yellowColor);
    trianglesv[7] = Triangle(v5, v8, v6, darkYellowColor);
    trianglesv[8] = Triangle(v1, v5, v2, purpleColor);
    trianglesv[9] = Triangle(v2, v6, v3, darkPurpleColor);
    trianglesv[10] = Triangle(v4, v3, v8, cianColor);
    trianglesv[11] = Triangle(v5, v1, v8, darkCianColor);


/*
    NumberVector v1 = NumberVector( -x  , -x,  x);
    NumberVector v2 = NumberVector( x  , -x,   x);
    NumberVector v3 = NumberVector(-x  , x,   x);
    NumberVector v4 = NumberVector(x  , x,  x);
    NumberVector v5 = NumberVector( x  ,  -x,  -x);
    NumberVector v6 = NumberVector( -x  , -x,   -x);
    NumberVector v7 = NumberVector(-x  ,  x,   -x);
    NumberVector v8 = NumberVector(x  ,  x,  -x);

    trianglesv[0] = Triangle(v1, v4, v3, redColor);
    trianglesv[1] = Triangle(v1, v2, v4, darkRedColor);
    trianglesv[2] = Triangle(v2, v8, v4, greenColor);
    trianglesv[3] = Triangle(v2, v5, v8, darkGreenColor);
    trianglesv[4] = Triangle(v4, v7, v3, blueColor);
    trianglesv[5] = Triangle(v4, v8, v7, darkBlueColor);
    trianglesv[6] = Triangle(v6, v8, v7, yellowColor);
    trianglesv[7] = Triangle(v6, v5, v8, darkYellowColor);
    trianglesv[8] = Triangle(v7, v3, v1, purpleColor);
    trianglesv[9] = Triangle(v7, v1, v5, darkPurpleColor);
    trianglesv[10] = Triangle(v5, v6, v1, cianColor);
    trianglesv[11] = Triangle(v5, v1, v2, darkCianColor);
*/
    for(int i = 0; i < 12; i++)
        triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[i]));

}

Cube::Cube(double size, Color newColor)
{
    color.red = newColor.red;
    color.green = newColor.green;
    color.blue = newColor.blue;

    double x = size;

    NumberVector v1 = NumberVector( x  , -x,  -x);
    NumberVector v2 = NumberVector( x  , -x,   x);
    NumberVector v3 = NumberVector(-x  , -x,   x);
    NumberVector v4 = NumberVector(-x  , -x,  -x);
    NumberVector v5 = NumberVector( x  ,  x,  -x);
    NumberVector v6 = NumberVector( x  ,  x,   x);
    NumberVector v7 = NumberVector(-x  ,  x,   x);
    NumberVector v8 = NumberVector(-x  ,  x,  -x);

    trianglesv[0] = Triangle(v2, v3, v4, redColor);
    trianglesv[1] = Triangle(v8, v7, v6, darkRedColor);
    trianglesv[2] = Triangle(v5, v6, v2, greenColor);
    trianglesv[3] = Triangle(v6, v7, v3, darkGreenColor);
    trianglesv[4] = Triangle(v3, v7, v8, blueColor);
    trianglesv[5] = Triangle(v1, v4, v8, darkBlueColor);
    trianglesv[6] = Triangle(v1, v2, v4, yellowColor);
    trianglesv[7] = Triangle(v5, v8, v6, darkYellowColor);
    trianglesv[8] = Triangle(v1, v5, v2, purpleColor);
    trianglesv[9] = Triangle(v2, v6, v3, darkPurpleColor);
    trianglesv[10] = Triangle(v4, v3, v8, cianColor);
    trianglesv[11] = Triangle(v5, v1, v8, darkCianColor);
/*
    NumberVector v1 = NumberVector( -x  , -x,  x);
    NumberVector v2 = NumberVector( x  , -x,   x);
    NumberVector v3 = NumberVector(-x  , x,   x);
    NumberVector v4 = NumberVector(x  , x,  x);
    NumberVector v5 = NumberVector( x  ,  -x,  -x);
    NumberVector v6 = NumberVector( -x  , -x,   -x);
    NumberVector v7 = NumberVector(-x  ,  x,   -x);
    NumberVector v8 = NumberVector(x  ,  x,  -x);

    trianglesv[0] = Triangle(v1, v4, v3, redColor);
    trianglesv[1] = Triangle(v1, v2, v4, darkRedColor);
    trianglesv[2] = Triangle(v2, v8, v4, greenColor);
    trianglesv[3] = Triangle(v2, v5, v8, darkGreenColor);
    trianglesv[4] = Triangle(v4, v7, v3, blueColor);
    trianglesv[5] = Triangle(v4, v8, v7, darkBlueColor);
    trianglesv[6] = Triangle(v6, v8, v7, yellowColor);
    trianglesv[7] = Triangle(v6, v5, v8, darkYellowColor);
    trianglesv[8] = Triangle(v7, v3, v1, purpleColor);
    trianglesv[9] = Triangle(v7, v1, v5, darkPurpleColor);
    trianglesv[10] = Triangle(v5, v6, v1, cianColor);
    trianglesv[11] = Triangle(v5, v1, v2, darkCianColor);
*/
    for(int i = 0; i < 12; i++)
        triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[i]));
}



Color Cube::getColor(){
    return this->color;
}

void Cube::scale(double x, double y, double z){

}

void Cube::translate(double x, double y, double z){

}

double Cube::findIntersection(NumberVector origin, NumberVector direction){
    double x = 0.0;
    return x;
}
