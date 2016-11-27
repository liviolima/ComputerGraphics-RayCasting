#include "cube.h"
#include "numbervector.h"
#include <iostream>

Cube::Cube()
{
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




    /*
    Triangle face1_triangule1_t1 = Triangle();
    Triangle face1_triangule2_t2 = Triangle();
    Triangle face2_triangule1_t3 = Triangle();
    Triangle face2_triangule2_t4 = Triangle();
    Triangle face3_triangule1_t5 = Triangle();
    Triangle face3_triangule2_t6 = Triangle();
    Triangle face4_triangule1_t7 = Triangle();
    Triangle face4_triangule2_t8 = Triangle();
    Triangle face5_triangule1_t9 = Triangle();
    Triangle face5_triangule2_t10 = Triangle();
    Triangle face6_triangule1_t11 = Triangle();
    Triangle face6_triangule2_t12 = Triangle();



    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face1_triangule1_t1));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face1_triangule2_t2));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face2_triangule1_t3));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face2_triangule2_t4));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face3_triangule1_t5));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face3_triangule2_t6));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face4_triangule1_t7));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face4_triangule2_t8));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face5_triangule1_t9));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face5_triangule2_t10));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face6_triangule1_t11));
    triangles_of_the_cube.push_back(dynamic_cast<Triangle*>(&face6_triangule2_t12));
    */




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
