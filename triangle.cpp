#include "triangle.h"
#include "numbervector.h"
#include <QDebug>
#include "color.h"
#include "iostream"



Triangle::Triangle()
{
    color.red = 255.0;
    color.green = 255.0;
    color.blue = 0.0;

    vertex[0] = NumberVector( 0, 0, 0);
    vertex[1] = NumberVector( 2, 0, 0);
    vertex[2] = NumberVector( 1, 2, 0);

    normal_vector = NumberVector(0, 0, 0);

    edge * all_edges = new edge[2];

    face * all_faces = new face[1];


    all_edges[0] = {1, 1, 2};
    all_edges[1] = {2, 1, 3};

    all_faces[0] = {1,1, 2,3};

}

Triangle::Triangle(NumberVector v1, NumberVector v2, NumberVector v3)
{
    color.red = 255.0;
    color.green = 255.0;
    color.blue = 0.0;

    vertex[0] = v1;
    vertex[1] = v2;
    vertex[2] = v3;

    normal_vector = NumberVector(0, 0, 0);

    edge * all_edges = new edge[2];

    face * all_faces = new face[1];


    all_edges[0] = {1, 1, 2};
    all_edges[1] = {2, 1, 3};

    all_faces[0] = {1,1, 2,3};

}

Triangle::Triangle(NumberVector v1, NumberVector v2, NumberVector v3, Color newColor)
{

    color.red = newColor.red;
    color.green = newColor.green;
    color.blue = newColor.blue;

    vertex[0] = v1;
    vertex[1] = v2;
    vertex[2] = v3;

    edge * all_edges = new edge[2];

    face * all_faces = new face[1];


    all_edges[0] = {1, 1, 2};
    all_edges[1] = {2, 1, 3};

    all_faces[0] = {1,1, 2,3};

}

Triangle::Triangle(NumberVector v1, NumberVector v2, NumberVector v3, Material material)
{

    color.red = 255.0;
    color.green = 0.0;
    color.blue = 0.0;

    this->material = material;

    vertex[0] = v1;
    vertex[1] = v2;
    vertex[2] = v3;

    edge * all_edges = new edge[2];

    face * all_faces = new face[1];


    all_edges[0] = {1, 1, 2};
    all_edges[1] = {2, 1, 3};

    all_faces[0] = {1,1, 2,3};

}


void Triangle::scale(double x, double y, double z){

}


void Triangle::translate(double x, double y, double z){

}


NumberVector Triangle::getNormal(){
    return normal_vector;
}


double Triangle::findIntersection(NumberVector origin, NumberVector direction){

    NumberVector edge1, edge2, normal;
    edge1 = vertex[1].sub(vertex[0]);
    edge2 = vertex[2].sub(vertex[0]);
    normal = edge1.cross_product(edge2).normalize();


    NumberVector _a = vertex[2];
    NumberVector _b = vertex[1];
    NumberVector _c = vertex[0];

       double distance = normal.dot_product(_a);

       double a = direction.dot_product(normal);

       if (a == 0) {
           // Raio paralelo ao triangulo
           return -1;
       }

       double b = normal.dot_product(origin.add(normal.multiply(distance).negative()));
       double distance2plane = -1*b/a;

       double Qx = direction.multiply(distance2plane).x + origin.x;
       double Qy = direction.multiply(distance2plane).y + origin.y;
       double Qz = direction.multiply(distance2plane).z + origin.z;

       NumberVector Q(Qx, Qy, Qz);

       //[CAxQA] * N >= 0
       NumberVector CA(_c.x - _a.x, _c.y - _a.y, _c.z - _a.z);
       NumberVector QA(Q.x - _a.x, Q.y - _a.y, Q.z - _a.z);

       double test1 = (CA.cross_product(QA)).dot_product(normal);

       //[BCxQC] * N >= 0
       NumberVector BC(_b.x - _c.x, _b.y - _c.y, _b.z - _c.z);
       NumberVector QC(Q.x - _c.x, Q.y - _c.y, Q.z - _c.z);

       double test2 = (BC.cross_product(QC)).dot_product(normal);

       //[ABxQB] * N >= 0

       NumberVector AB(_a.x - _b.x, _a.y - _b.y, _a.z - _b.z);
       NumberVector QB(Q.x - _b.x, Q.y - _b.y, Q.z - _b.z);

       double test3 = (AB.cross_product(QB)).dot_product(normal);

       if(test1 >= 0  && test2 >= 0  && test3 >= 0  ) {
           //dentro do triangulo
           T_intersection = -1*b/a;
           normal_vector = normal;
           return -1*b/a;
       } else {
           T_intersection = -1;
           normal_vector = NumberVector(0, 0, 0);
           //fora do triangulo
           return -1;
       }
}


Color Triangle::getColor(){
    return color;
}

void Triangle::setVertexes(NumberVector new_value_for_vertex[3]){
    vertex[0] = new_value_for_vertex[0];
    vertex[1] = new_value_for_vertex[1];
    vertex[2] = new_value_for_vertex[2];
}

void Triangle::printVertexes(){
    std::cout<< "v0: " <<"x= "<<vertex[0].x<<", y= "<<vertex[0].y<<", z= "<<vertex[0].z<<"\n";
    std::cout<< "v1: " <<"x= "<<vertex[1].x<<", y= "<<vertex[1].y<<", z= "<<vertex[1].z<<"\n";
    std::cout<< "v2: " <<"x= "<<vertex[2].x<<", y= "<<vertex[2].y<<", z= "<<vertex[2].z<<"\n";
}

double Triangle::get_T_intersection(){
    return T_intersection;
}


