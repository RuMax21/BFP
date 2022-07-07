#ifndef ISOSCELES_TRAPEZOID_H
#define ISOSCELES_TRAPEZOID_H

#include "trapezoid.h"

class Isosceles_trapezoid : public Trapezoid {
public:
    Isosceles_trapezoid(double top_side, double bottom_side, double hight);

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


#endif //ISOSCELES_TRAPEZOID_H
