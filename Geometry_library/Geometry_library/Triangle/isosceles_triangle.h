#ifndef ISOSCELES_TRIANGLE_H
#define ISOSCELES_TRIANGLE_H
#include "triangle.h"

class Isosceles_triangle : public Triangle {
public:
    Isosceles_triangle(double bottom_side, double hight);

    double Get_perimetr();

    double Get_square();

    double Get_hight();

    double Get_left_side();

    double Get_right_side();

    double Get_bottom_side();

    double Get_angel_bottom_right();

    double Get_angel_top();

    double Get_angel_bottom_left();

    double Get_input_cathet();

    double Get_cathet();

    double Get_hypotenuse();
};


#endif //ISOSCELES_TRIANGLE_H
