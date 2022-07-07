#ifndef PARALLELOGRAM_SIDE_HIGHT_H
#define PARALLELOGRAM_SIDE_HIGHT_H

#include "parallelogram.h"

class Parallelogram_side_hight : public Parallelogram {
   public:
    Parallelogram_side_hight(double top_side, double left_side, double hight);

    double Get_perimetr();

    double Get_square();

    double Get_hight();

    double Get_left_side();

    double Get_top_side();

    double Get_angel_top_left();

    double Get_angel_bottom_left();
};


#endif //PARALLELOGRAM_SIDE_HIGHT_H
