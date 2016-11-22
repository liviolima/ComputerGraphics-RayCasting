#include "leg.h"


Leg::Leg()
{
    struct vertex{
        int vertex_identifier;

        double x;
        double y;
        double z;
    };

    struct edge{
        int edge_identifier;

        int first_vertex_identifier;
        int second_vertex_identifier;
    };

    struct face{
        int face_identifier;

        int first_edge_identifier;
        int second_edge_identifier;
        int third_edge_identifier;

    };

    vertex * all_vertexes = new vertex[8];

    all_vertexes[0] = {1, 0, 0, 5};
    all_vertexes[1] = {2, 5, 0, 5};
    all_vertexes[2] = {3, 0, 0, 0};
    all_vertexes[3] = {4, 5, 0, 0};

    all_vertexes[4] = {5, 0, 40, 5};
    all_vertexes[5] = {6, 5, 40, 5};
    all_vertexes[6] = {7, 0, 40, 0};
    all_vertexes[7] = {8, 5, 40, 0};


    edge * all_edges = new edge[18];

    all_edges[0] = {1, 1, 2};
    all_edges[1] = {2, 2, 6};
    all_edges[2] = {3, 6, 7};
    all_edges[3] = {4, 7, 8};
    all_edges[4] = {5, 8, 5};
    all_edges[5] = {6, 5, 1};
    all_edges[6] = {7, 1, 4};
    all_edges[7] = {8, 4, 8};
    all_edges[8] = {9, 4, 3};
    all_edges[9] = {10, 3, 2};
    all_edges[10] = {11, 3, 7};
    all_edges[11] = {12, 5, 6};
    all_edges[12] = {13, 4, 5};
    all_edges[13] = {14, 1, 6};
    all_edges[14] = {15, 3, 6};
    all_edges[15] = {16, 4, 7};
    all_edges[16] = {17, 4, 2};
    all_edges[17] = {18, 8, 6};


    face * all_faces = new face[12];

    all_faces[0] = {1 , 5, 8, 13};
    all_faces[1] = {2 , 7, 6, 13};
    all_faces[2] = {3 , 1, 2, 14};
    all_faces[3] = {4 , 12, 6, 14};
    all_faces[4] = {5 , 5, 12, 18};
    all_faces[5] = {6 , 3, 4, 18};
    all_faces[6] = {7 , 9, 11, 16};
    all_faces[7] = {8 , 16, 4, 8};
    all_faces[8] = {9 , 7, 1, 17};
    all_faces[9] = {10 , 17, 10, 9};
    all_faces[10] = {11 , 10, 2, 15};
    all_faces[11] = {12 , 15, 3, 11};

}

void Leg::translate(double x, double y, double z){
    for (int i = 0; i < 8; i++){
        //modify all the value of x, y, z
    }
}
