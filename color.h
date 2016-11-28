#ifndef COLOR_H
#define COLOR_H


class Color
{
public:
    Color(double red, double green, double blue, int integer);
    Color();
    void setColor(Color color);
    double red, green, blue;
    int integer;

};

#endif // COLOR_H
