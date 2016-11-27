#include "color.h"

Color::Color(double red, double green, double blue, int integer)
{
    this->red = red;
    this->green = green;
    this->blue = blue;
    this->integer = integer;
}


Color::Color(){
    this->red = 0;
    this->green = 0;
    this->blue = 0;
    this->integer = 0;
}


void Color::setColor(Color color){
    this->red = color.red;
    this->green = color.green;
    this->blue = color.blue;
    this->integer = color.integer;
}
