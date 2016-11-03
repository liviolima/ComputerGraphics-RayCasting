#ifndef TOPTABLE_H
#define TOPTABLE_H


class TopTable
{
    struct vertex;

    struct edge;

    struct face;

    vertex * all_vertexes;

    edge * all_edges;

    face * all_faces;

public:
    TopTable();

    void translate(double x, double y, double z);
};

#endif // TOPTABLE_H
