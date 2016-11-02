#ifndef LEG_H
#define LEG_H


class Leg
{
    struct vertex;

    struct edge;

    struct face;

    vertex * all_vertexes;

    edge * all_edges;

    face * all_faces;

public:
    Leg();

    void translate(double x, double y, double z);
};

#endif // LEG_H
