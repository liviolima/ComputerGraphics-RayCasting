#ifndef TRIANGLE_H
#define TRIANGLE_H
#import "object.h"


class Triangle: public Object
{
public:
    Triangle();

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

    vertex * all_vertexes;

    edge * all_edges;

    face * all_faces;

    void scale(double x, double y, double z);
    void translate(double x, double y, double z);

};

#endif // TRIANGLE_H
