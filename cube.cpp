#include "cube.h"
#include "numbervector.h"
#include "material.h"
#include <math.h>

#define PI 3.14159265

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
    double x = this->size_x = this->size_y = this->size_z = 1;

    v1 = NumberVector( x  , -x,  -x);
    v2 = NumberVector( x  , -x,   x);
    v3 = NumberVector(-x  , -x,   x);
    v4 = NumberVector(-x  , -x,  -x);
    v5 = NumberVector( x  ,  x,  -x);
    v6 = NumberVector( x  ,  x,   x);
    v7 = NumberVector(-x  ,  x,   x);
    v8 = NumberVector(-x  ,  x,  -x);
/*
    trianglesv[0] = Triangle(v2, v3, v4, color);
    trianglesv[1] = Triangle(v8, v7, v6, color);
    trianglesv[2] = Triangle(v5, v6, v2, color);
    trianglesv[3] = Triangle(v6, v7, v3, color);
    trianglesv[4] = Triangle(v3, v7, v8, color);
    trianglesv[5] = Triangle(v1, v4, v8, color);
    trianglesv[6] = Triangle(v1, v2, v4, color);
    trianglesv[7] = Triangle(v5, v8, v6, color);
    trianglesv[8] = Triangle(v1, v5, v2, color);
    trianglesv[9] = Triangle(v2, v6, v3, color);
    trianglesv[10] = Triangle(v4, v3, v8, color);
    trianglesv[11] = Triangle(v5, v1, v8, color);
*/

    for(int i = 0; i < 12; i++)
        triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[i]));

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



}

Cube::Cube(double size, Color newColor)
{
    color.red = newColor.red;
    color.green = newColor.green;
    color.blue = newColor.blue;

    double x = size;
    this->size_x = this->size_y = this->size_z = size;

    v1 = NumberVector( x  , -x,  -x);
    v2 = NumberVector( x  , -x,   x);
    v3 = NumberVector(-x  , -x,   x);
    v4 = NumberVector(-x  , -x,  -x);
    v5 = NumberVector( x  ,  x,  -x);
    v6 = NumberVector( x  ,  x,   x);
    v7 = NumberVector(-x  ,  x,   x);
    v8 = NumberVector(-x  ,  x,  -x);
/*
    trianglesv[0] = Triangle(v2, v3, v4, color);
    trianglesv[1] = Triangle(v8, v7, v6, color);
    trianglesv[2] = Triangle(v5, v6, v2, color);
    trianglesv[3] = Triangle(v6, v7, v3, color);
    trianglesv[4] = Triangle(v3, v7, v8, color);
    trianglesv[5] = Triangle(v1, v4, v8, color);
    trianglesv[6] = Triangle(v1, v2, v4, color);
    trianglesv[7] = Triangle(v5, v8, v6, color);
    trianglesv[8] = Triangle(v1, v5, v2, color);
    trianglesv[9] = Triangle(v2, v6, v3, color);
    trianglesv[10] = Triangle(v4, v3, v8, color);
    trianglesv[11] = Triangle(v5, v1, v8, color);
*/
    for(int i = 0; i < 12; i++)
        triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[i]));

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


}

Cube::Cube(double size, Material material)
{
    color.red = 255.0;
    color.green = 0.0;
    color.blue = 0.0;

    this->material = material;

    double x = size;
    this->size_x = this->size_y = this->size_z = size;

    v1 = NumberVector( x  , -x,  -x);
    v2 = NumberVector( x  , -x,   x);
    v3 = NumberVector(-x  , -x,   x);
    v4 = NumberVector(-x  , -x,  -x);
    v5 = NumberVector( x  ,  x,  -x);
    v6 = NumberVector( x  ,  x,   x);
    v7 = NumberVector(-x  ,  x,   x);
    v8 = NumberVector(-x  ,  x,  -x);
/*
    trianglesv[0] = Triangle(v2, v3, v4, color);
    trianglesv[1] = Triangle(v8, v7, v6, color);
    trianglesv[2] = Triangle(v5, v6, v2, color);
    trianglesv[3] = Triangle(v6, v7, v3, color);
    trianglesv[4] = Triangle(v3, v7, v8, color);
    trianglesv[5] = Triangle(v1, v4, v8, color);
    trianglesv[6] = Triangle(v1, v2, v4, color);
    trianglesv[7] = Triangle(v5, v8, v6, color);
    trianglesv[8] = Triangle(v1, v5, v2, color);
    trianglesv[9] = Triangle(v2, v6, v3, color);
    trianglesv[10] = Triangle(v4, v3, v8, color);
    trianglesv[11] = Triangle(v5, v1, v8, color);
*/
    for(int i = 0; i < 12; i++)
        triangles.push_back(dynamic_cast<Triangle*>(&trianglesv[i]));
/*
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
*/

    trianglesv[0] = Triangle(v2, v3, v4, material);
    trianglesv[1] = Triangle(v8, v7, v6, material);
    trianglesv[2] = Triangle(v5, v6, v2, material);
    trianglesv[3] = Triangle(v6, v7, v3, material);
    trianglesv[4] = Triangle(v3, v7, v8, material);
    trianglesv[5] = Triangle(v1, v4, v8, material);
    trianglesv[6] = Triangle(v1, v2, v4, material);
    trianglesv[7] = Triangle(v5, v8, v6, material);
    trianglesv[8] = Triangle(v1, v5, v2, material);
    trianglesv[9] = Triangle(v2, v6, v3, material);
    trianglesv[10] = Triangle(v4, v3, v8, material);
    trianglesv[11] = Triangle(v5, v1, v8, material);

}



Color Cube::getColor(){
    return this->color;
}

Material Cube::getMaterial(){
    return this->material;
}

void Cube::scale(double x, double y, double z){

    size_x = size_x*x;
    size_y = size_y*y;
    size_z = size_z*z;

    v1 = NumberVector( size_x  , -size_y,  -size_z);
    v2 = NumberVector( size_x  , -size_y,   size_z);
    v3 = NumberVector(-size_x  , -size_y,   size_z);
    v4 = NumberVector(-size_x  , -size_y,  -size_z);
    v5 = NumberVector( size_x  ,  size_y,  -size_z);
    v6 = NumberVector( size_x  ,  size_y,   size_z);
    v7 = NumberVector(-size_x  ,  size_y,   size_z);
    v8 = NumberVector(-size_x  ,  size_y,  -size_z);
/*
    trianglesv[0] = Triangle(v2, v3, v4, color);
    trianglesv[1] = Triangle(v8, v7, v6, color);
    trianglesv[2] = Triangle(v5, v6, v2, color);
    trianglesv[3] = Triangle(v6, v7, v3, color);
    trianglesv[4] = Triangle(v3, v7, v8, color);
    trianglesv[5] = Triangle(v1, v4, v8, color);
    trianglesv[6] = Triangle(v1, v2, v4, color);
    trianglesv[7] = Triangle(v5, v8, v6, color);
    trianglesv[8] = Triangle(v1, v5, v2, color);
    trianglesv[9] = Triangle(v2, v6, v3, color);
    trianglesv[10] = Triangle(v4, v3, v8, color);
    trianglesv[11] = Triangle(v5, v1, v8, color);
*/

    /*
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
    */

    trianglesv[0] = Triangle(v2, v3, v4, material);
    trianglesv[1] = Triangle(v8, v7, v6, material);
    trianglesv[2] = Triangle(v5, v6, v2, material);
    trianglesv[3] = Triangle(v6, v7, v3, material);
    trianglesv[4] = Triangle(v3, v7, v8, material);
    trianglesv[5] = Triangle(v1, v4, v8, material);
    trianglesv[6] = Triangle(v1, v2, v4, material);
    trianglesv[7] = Triangle(v5, v8, v6, material);
    trianglesv[8] = Triangle(v1, v5, v2, material);
    trianglesv[9] = Triangle(v2, v6, v3, material);
    trianglesv[10] = Triangle(v4, v3, v8, material);
    trianglesv[11] = Triangle(v5, v1, v8, material);


}

void Cube::translate(double x, double y, double z){

    v1 = NumberVector( v1.x+x  ,  v1.y+y,   v1.z+z);
    v2 = NumberVector( v2.x+x  ,  v2.y+y,   v2.z+z);
    v3 = NumberVector( v3.x+x  ,  v3.y+y,   v3.z+z);
    v4 = NumberVector( v4.x+x  ,  v4.y+y,   v4.z+z);
    v5 = NumberVector( v5.x+x  ,  v5.y+y,   v5.z+z);
    v6 = NumberVector( v6.x+x  ,  v6.y+y,   v6.z+z);
    v7 = NumberVector( v7.x+x  ,  v7.y+y,   v7.z+z);
    v8 = NumberVector( v8.x+x  ,  v8.y+y,   v8.z+z);
/*
    trianglesv[0] = Triangle(v2, v3, v4, color);
    trianglesv[1] = Triangle(v8, v7, v6, color);
    trianglesv[2] = Triangle(v5, v6, v2, color);
    trianglesv[3] = Triangle(v6, v7, v3, color);
    trianglesv[4] = Triangle(v3, v7, v8, color);
    trianglesv[5] = Triangle(v1, v4, v8, color);
    trianglesv[6] = Triangle(v1, v2, v4, color);
    trianglesv[7] = Triangle(v5, v8, v6, color);
    trianglesv[8] = Triangle(v1, v5, v2, color);
    trianglesv[9] = Triangle(v2, v6, v3, color);
    trianglesv[10] = Triangle(v4, v3, v8, color);
    trianglesv[11] = Triangle(v5, v1, v8, color);
*/

    /*
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
    */

    trianglesv[0] = Triangle(v2, v3, v4, material);
    trianglesv[1] = Triangle(v8, v7, v6, material);
    trianglesv[2] = Triangle(v5, v6, v2, material);
    trianglesv[3] = Triangle(v6, v7, v3, material);
    trianglesv[4] = Triangle(v3, v7, v8, material);
    trianglesv[5] = Triangle(v1, v4, v8, material);
    trianglesv[6] = Triangle(v1, v2, v4, material);
    trianglesv[7] = Triangle(v5, v8, v6, material);
    trianglesv[8] = Triangle(v1, v5, v2, material);
    trianglesv[9] = Triangle(v2, v6, v3, material);
    trianglesv[10] = Triangle(v4, v3, v8, material);
    trianglesv[11] = Triangle(v5, v1, v8, material);


}

void Cube::rotate_x(double angle){

    double sin_angle = sin(angle*PI/180);
    double cos_angle = cos(angle*PI/180);


    v1 = NumberVector( v1.x  ,  v1.y*cos_angle-v1.z*sin_angle,   v1.y*sin_angle+v1.z*cos_angle);
    v2 = NumberVector( v2.x  ,  v2.y*cos_angle-v2.z*sin_angle,   v2.y*sin_angle+v2.z*cos_angle);
    v3 = NumberVector( v3.x  ,  v3.y*cos_angle-v3.z*sin_angle,   v3.y*sin_angle+v3.z*cos_angle);
    v4 = NumberVector( v4.x  ,  v4.y*cos_angle-v4.z*sin_angle,   v4.y*sin_angle+v4.z*cos_angle);
    v5 = NumberVector( v5.x  ,  v5.y*cos_angle-v5.z*sin_angle,   v5.y*sin_angle+v5.z*cos_angle);
    v6 = NumberVector( v6.x  ,  v6.y*cos_angle-v6.z*sin_angle,   v6.y*sin_angle+v6.z*cos_angle);
    v7 = NumberVector( v7.x  ,  v7.y*cos_angle-v7.z*sin_angle,   v7.y*sin_angle+v7.z*cos_angle);
    v8 = NumberVector( v8.x  ,  v8.y*cos_angle-v8.z*sin_angle,   v8.y*sin_angle+v8.z*cos_angle);


    trianglesv[0] = Triangle(v2, v3, v4, material);
    trianglesv[1] = Triangle(v8, v7, v6, material);
    trianglesv[2] = Triangle(v5, v6, v2, material);
    trianglesv[3] = Triangle(v6, v7, v3, material);
    trianglesv[4] = Triangle(v3, v7, v8, material);
    trianglesv[5] = Triangle(v1, v4, v8, material);
    trianglesv[6] = Triangle(v1, v2, v4, material);
    trianglesv[7] = Triangle(v5, v8, v6, material);
    trianglesv[8] = Triangle(v1, v5, v2, material);
    trianglesv[9] = Triangle(v2, v6, v3, material);
    trianglesv[10] = Triangle(v4, v3, v8, material);
    trianglesv[11] = Triangle(v5, v1, v8, material);


}

void Cube::rotate_y(double angle){

    double sin_angle = sin(angle*PI/180);
    double cos_angle = cos(angle*PI/180);


    v1 = NumberVector( v1.x*cos_angle+v1.z*sin_angle  ,  v1.y,   v1.x*(-sin_angle)+v1.z*cos_angle);
    v2 = NumberVector( v2.x*cos_angle+v2.z*sin_angle  ,  v2.y,   v2.x*(-sin_angle)+v2.z*cos_angle);
    v3 = NumberVector( v3.x*cos_angle+v3.z*sin_angle  ,  v3.y,   v3.x*(-sin_angle)+v3.z*cos_angle);
    v4 = NumberVector( v4.x*cos_angle+v4.z*sin_angle  ,  v4.y,   v4.x*(-sin_angle)+v4.z*cos_angle);
    v5 = NumberVector( v5.x*cos_angle+v5.z*sin_angle  ,  v5.y,   v5.x*(-sin_angle)+v5.z*cos_angle);
    v6 = NumberVector( v6.x*cos_angle+v6.z*sin_angle  ,  v6.y,   v6.x*(-sin_angle)+v6.z*cos_angle);
    v7 = NumberVector( v7.x*cos_angle+v7.z*sin_angle  ,  v7.y,   v7.x*(-sin_angle)+v7.z*cos_angle);
    v8 = NumberVector( v8.x*cos_angle+v8.z*sin_angle  ,  v8.y,   v8.x*(-sin_angle)+v8.z*cos_angle);


    trianglesv[0] = Triangle(v2, v3, v4, material);
    trianglesv[1] = Triangle(v8, v7, v6, material);
    trianglesv[2] = Triangle(v5, v6, v2, material);
    trianglesv[3] = Triangle(v6, v7, v3, material);
    trianglesv[4] = Triangle(v3, v7, v8, material);
    trianglesv[5] = Triangle(v1, v4, v8, material);
    trianglesv[6] = Triangle(v1, v2, v4, material);
    trianglesv[7] = Triangle(v5, v8, v6, material);
    trianglesv[8] = Triangle(v1, v5, v2, material);
    trianglesv[9] = Triangle(v2, v6, v3, material);
    trianglesv[10] = Triangle(v4, v3, v8, material);
    trianglesv[11] = Triangle(v5, v1, v8, material);

}

void Cube::rotate_z(double angle){
    double sin_angle = sin(angle*PI/180);
    double cos_angle = cos(angle*PI/180);


    v1 = NumberVector( v1.x*cos_angle-v1.y*sin_angle  ,  v1.x*sin_angle+v1.y*cos_angle,   v1.z);
    v2 = NumberVector( v2.x*cos_angle-v2.y*sin_angle  ,  v2.x*sin_angle+v2.y*cos_angle,   v2.z);
    v3 = NumberVector( v3.x*cos_angle-v3.y*sin_angle  ,  v3.x*sin_angle+v3.y*cos_angle,   v3.z);
    v4 = NumberVector( v4.x*cos_angle-v4.y*sin_angle  ,  v4.x*sin_angle+v4.y*cos_angle,   v4.z);
    v5 = NumberVector( v5.x*cos_angle-v5.y*sin_angle  ,  v5.x*sin_angle+v5.y*cos_angle,   v5.z);
    v6 = NumberVector( v6.x*cos_angle-v6.y*sin_angle  ,  v6.x*sin_angle+v6.y*cos_angle,   v6.z);
    v7 = NumberVector( v7.x*cos_angle-v7.y*sin_angle  ,  v7.x*sin_angle+v7.y*cos_angle,   v7.z);
    v8 = NumberVector( v8.x*cos_angle-v8.y*sin_angle  ,  v8.x*sin_angle+v8.y*cos_angle,   v8.z);


    trianglesv[0] = Triangle(v2, v3, v4, material);
    trianglesv[1] = Triangle(v8, v7, v6, material);
    trianglesv[2] = Triangle(v5, v6, v2, material);
    trianglesv[3] = Triangle(v6, v7, v3, material);
    trianglesv[4] = Triangle(v3, v7, v8, material);
    trianglesv[5] = Triangle(v1, v4, v8, material);
    trianglesv[6] = Triangle(v1, v2, v4, material);
    trianglesv[7] = Triangle(v5, v8, v6, material);
    trianglesv[8] = Triangle(v1, v5, v2, material);
    trianglesv[9] = Triangle(v2, v6, v3, material);
    trianglesv[10] = Triangle(v4, v3, v8, material);
    trianglesv[11] = Triangle(v5, v1, v8, material);

}

void Cube::shearing_planeZY_push_Z(double angle){

    double tan_angle = tan(angle*PI/180);

    v1 = NumberVector( v1.x  ,  v1.y,   tan_angle*v1.y+v1.z);
    v2 = NumberVector( v2.x  ,  v2.y,   tan_angle*v2.y+v2.z);
    v3 = NumberVector( v3.x  ,  v3.y,   tan_angle*v3.y+v3.z);
    v4 = NumberVector( v4.x  ,  v4.y,   tan_angle*v4.y+v4.z);
    v5 = NumberVector( v5.x  ,  v5.y,   tan_angle*v5.y+v5.z);
    v6 = NumberVector( v6.x  ,  v6.y,   tan_angle*v6.y+v6.z);
    v7 = NumberVector( v7.x  ,  v7.y,   tan_angle*v7.y+v7.z);
    v8 = NumberVector( v8.x  ,  v8.y,   tan_angle*v8.y+v8.z);


    trianglesv[0] = Triangle(v2, v3, v4, material);
    trianglesv[1] = Triangle(v8, v7, v6, material);
    trianglesv[2] = Triangle(v5, v6, v2, material);
    trianglesv[3] = Triangle(v6, v7, v3, material);
    trianglesv[4] = Triangle(v3, v7, v8, material);
    trianglesv[5] = Triangle(v1, v4, v8, material);
    trianglesv[6] = Triangle(v1, v2, v4, material);
    trianglesv[7] = Triangle(v5, v8, v6, material);
    trianglesv[8] = Triangle(v1, v5, v2, material);
    trianglesv[9] = Triangle(v2, v6, v3, material);
    trianglesv[10] = Triangle(v4, v3, v8, material);
    trianglesv[11] = Triangle(v5, v1, v8, material);


}



double Cube::findIntersection(NumberVector origin, NumberVector direction){
    return -1;
}
