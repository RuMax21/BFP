#ifndef ARBITRARY_TRAPEZOID_H
#define ARBITRARY_TRAPEZOID_H
#include "trapezoid.h"

class Arbitrary_trapezoid : public Trapezoid { //Произвольная трапеция
public:
    Arbitrary_trapezoid(double left_side, double right_side, double top_side, double bottom_side);

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


#endif //ARBITRARY_TRAPEZOID_H
