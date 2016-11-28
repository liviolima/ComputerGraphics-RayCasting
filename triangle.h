#ifndef TRIANGLE_H
#define TRIANGLE_H
#import "numbervector.h"
#import "ray.h"
#include "color.h"

class Triangle
{
public:
    Triangle();
    Triangle(NumberVector v1, NumberVector v2, NumberVector v3);
    Triangle(NumberVector v1, NumberVector v2, NumberVector v3, Color newColor);


    NumberVector vertex[3];

    Color color;

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


    edge * all_edges;

    face * all_faces;

    void scale(double x, double y, double z);
    void translate(double x, double y, double z);
    double findIntersection(NumberVector origin, NumberVector direction);
    void printVertexes();
    Color getColor();

    NumberVector getNormalAt(NumberVector point);

    void setVertexes(NumberVector new_value_for_vertex[3]);


};

#endif // TRIANGLE_H
