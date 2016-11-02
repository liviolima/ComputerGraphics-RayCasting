#ifndef CUBE_H
#define CUBE_H


class Cube
{
    struct vertex;

    struct edge;

    struct face;

    vertex * all_vertexes;

    edge * all_edges;

    face * all_faces;

public:

    Cube();

    void scale(int Sx, int Sy, int Sz);

};

#endif // CUBE_H
