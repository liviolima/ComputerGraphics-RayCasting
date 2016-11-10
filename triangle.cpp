#include "triangle.h"
#include "numbervector.h"

Triangle::Triangle()
{




    edge * all_edges = new edge[2];

    face * all_faces = new face[1];


    vertex[0] = NumberVector( 0, 0, 0);
    vertex[1] = NumberVector( 10, 0, 0);
    vertex[2] = NumberVector( 5, 10, 0);

    all_edges[0] = {1, 1, 2};
    all_edges[1] = {2, 1, 3};

    all_faces[0] = {1 , 1, 2, 3};

}

void Triangle::scale(double x, double y, double z){

}



void Triangle::translate(double x, double y, double z){

}

//void Triangle::changeCoordinateWorld
