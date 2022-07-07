#ifndef RECTANGULAR_TRAPEZOID_H
#define RECTANGULAR_TRAPEZOID_H

#include "trapezoid.h"

class Rectangular_trapezoid : public Trapezoid {
public:
    Rectangular_trapezoid(double top_side, double bottom_side, double left_side);

    double Get_perimetr();

    double Get_square();

    double Get_hight();

    double Get_left_side();

    double Get_right_side();

    double Get_top_side();

    double Get_bottom_side();

    double Get_angel_bottom_right();

    double Get_angel_top_right();

    double Get_angel_top_left();

    double Get_angel_bottom_left();
};


#endif //RECTANGULAR_TRAPEZOID_H
