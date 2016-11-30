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


void Triangle::scale(double x, double y, double z){

}


void Triangle::translate(double x, double y, double z){

}


NumberVector Triangle::getNormalAt(NumberVector point){

    NumberVector normal_vector; //It is necessary to implement.
    return normal_vector;
}

/*
double Triangle::findIntersection(NumberVector origin, NumberVector direction){
    int intersectTheTriangle = 1;

    //PART 1
    double kEpsilon = 0.00001;
    //v0v1 = v1 - v0
    NumberVector v0v1 = vertex[1].sub(vertex[0]);
    //v0v2 = v2 - v0
    NumberVector v0v2 = vertex[2].sub(vertex[0]);
    NumberVector N = v0v1.cross_product(v0v2);


    //PART 2
    // check if ray and plane are parallel ?
    double NdotProductWithRayDirection = N.dot_product(direction);
    if (abs(NdotProductWithRayDirection) < kEpsilon) // almost 0
        intersectTheTriangle = 0; // they are parallel so they don't intersect !


    //PART 3
    // compute d parameter using equation 2
    double d = N.dot_product(vertex[0]);
    // compute t (equation 3)
    double t = (N.dot_product(origin) + d) / NdotProductWithRayDirection;
    // check if the triangle is in behind the ray
    if (t < 0) intersectTheTriangle = 0; // the triangle is behind


    //PART 4
    NumberVector t_multiply_by_direction;
    t_multiply_by_direction.x = t*direction.x;
    t_multiply_by_direction.y = t*direction.y;
    t_multiply_by_direction.z = t*direction.z;
    //This means ---> P = origin + t * direction
    NumberVector P = origin.add(t_multiply_by_direction);



    //PART 5
    //edge 0
    //This means ---> edge0 = vertex[1] - vertex[0];
    NumberVector edge0 = vertex[1].sub(vertex[0]);
    //This means ---> vp0 = P - v0
    NumberVector vp0 = P.sub(vertex[0]);
    NumberVector C1 = edge0.cross_product(vp0);
    if(N.dot_product(C1) < 0) intersectTheTriangle = 0; // P is on the right side



    //PART 6
    //edge 1
    //This means --> edge1 = vertex[2] - vertex[1]
    NumberVector edge1 = vertex[2].sub(vertex[1]);
    //This means ---> vp1 = P - v1
    NumberVector vp1 = P.sub(vertex[1]);
    NumberVector C2 = edge1.cross_product(vp1);
    if(N.dot_product(C2) < 0) intersectTheTriangle = 0; // P is on the right side



    //PART 7
    //edge 2
    //This means --> edge2 = vertex[0] - vertex[2]
    NumberVector edge2 = vertex[0].sub(vertex[2]);
    //This means ---> vp2 = P - v2
    NumberVector vp2 = P.sub(vertex[2]);
    NumberVector C3 = edge1.cross_product(vp1);
    if(N.dot_product(C3) < 0) intersectTheTriangle = 0; // P is on the right side



    //PART 8
    // this ray hits the triangle
    if(intersectTheTriangle == 1){
        std::cout << "HIT";
        return t;
    }
    else return -1; // this ray does no hit the triangle

}
*/

/* */


double Triangle::findIntersection(NumberVector origin, NumberVector direction){
    NumberVector edge1, edge2, normal, p1_vector ;

    //std::cout<<" 1\n";
    edge1 = vertex[1].sub(vertex[0]);
    edge2 = vertex[2].sub(vertex[0]);

    normal = direction.cross_product(edge2);
    p1_vector = origin.sub(vertex[0]);

    double valueA = direction.dot_product(normal);
    double valueB = p1_vector.dot_product(normal);

    if (fabs(valueA) <= 0.00001)
        return false;

    std::cout<<" 2\n";
    float T = valueB / valueA;

    if (T <= 0.0001)
        return false;

    std::cout<<T<<" 3\n";
    return T;



}

/*
double Triangle::findIntersection(NumberVector origin, NumberVector direction){

    double EPSILON = 0.0000001;
    NumberVector edge1, edge2, P, Q, T;
    double det, inv_det, u, v, t;

    edge1 = vertex[1].sub(vertex[0]);
    edge2 = vertex[2].sub(vertex[0]);

    P = direction.cross_product(edge2);
    //if determinant is near zero, ray lies in plane of triangle or ray is parallel to plane of triangle
    det = edge1.dot_product(P);


    if (det > -EPSILON && det < EPSILON) return 0;
    inv_det = 1.f / det;


    T = origin.sub(vertex[0]);
    u = T.dot_product(P) * inv_det;


    if (u < 0.f || u > 1.f) return 0;

    Q = T.cross_product(edge1);
    v = direction.dot_product(Q);


    if (v < 0.f || u + v > 1.f) return 0;


    t = edge2.dot_product(Q) * inv_det;


    if (t > EPSILON){
        return t;
    } else{
        return -1;
    }
}
 */

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



