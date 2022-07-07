#ifndef ANGEL_SIDE_TRIANGLE_H
#define ANGEL_SIDE_TRIANGLE_H
#include "triangle.h"

class Angel_side_triangle : public Triangle {
public:
    Angel_side_triangle(double bottom_side, double angel_bottom_left, double angel_bottom_right);

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


#endif //ANGEL_SIDE_TRIANGLE_H
