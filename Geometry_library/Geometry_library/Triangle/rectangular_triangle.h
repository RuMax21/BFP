#ifndef RECTANGULAR_TRIANGLE_H
#define RECTANGULAR_TRIANGLE_H
#include "triangle.h"

class Rectangular_triangle : public Triangle {
public:
    Rectangular_triangle(double input_cathet, double hypotenuse);

    double Get_perimetr();

    double Get_square();

    double Get_input_cathet(); // катет противолежащий левому нижнему углы, при условии, что нижний правый - 90

    double Get_cathet();

    double Get_hypotenuse();

    double Get_angel_bottom_right(); // угол равный 90 гр.

    double Get_angel_top();

    double Get_angel_bottom_left();

    double Get_hight();

    double Get_left_side();

    double Get_right_side();

    double Get_bottom_side();

};


#endif //RECTANGULAR_TRIANGLE_H
