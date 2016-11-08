#include "triangle.h"

Triangle::Triangle()
{
    vertex * all_vertexes = new vertex[3];

    edge * all_edges = new edge[2];

    face * all_faces = new face[1];


    all_vertexes[0] = {1, 0, 0, 0};
    all_vertexes[1] = {2, 10, 0, 0};
    all_vertexes[2] = {3, 5, 10, 0};

    all_edges[0] = {1, 1, 2};
    all_edges[1] = {2, 1, 3};

    all_faces[0] = {1 , 1, 2, 3};

}

void Triangle::scale(double x, double y, double z){

}



void Triangle::translate(double x, double y, double z){

}
