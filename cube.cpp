#include "cube.h"

Cube::Cube()
{
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
