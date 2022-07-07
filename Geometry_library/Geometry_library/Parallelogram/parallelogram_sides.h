#ifndef PARALLELOGRAM_SIDES_H
#define PARALLELOGRAM_SIDES_H

#include "parallelogram.h"

class Parallelogram_sides : public Parallelogram {
public:
    Parallelogram_sides(double top_side, double left_side, double angel_bottom_left);

    double Get_perimetr();

    double Get_square();

    double Get_hight();

    double Get_left_side();

    double Get_top_side();

    double Get_angel_top_left();

    double Get_angel_bottom_left();
};


#endif //PARALLELOGRAM_SIDES_H
