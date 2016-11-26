#ifndef TRIANGLE_H
#define TRIANGLE_H
#import "object.h"
#import "numbervector.h"
#import "ray.h"

class Triangle: public Object
{
public:
    Triangle();

    NumberVector vertex[3];


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

    NumberVector getNormalAt(NumberVector point);
    bool findIntersection(Ray ray, NumberVector origin, NumberVector direction);



};

#endif // TRIANGLE_H
