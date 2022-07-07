#ifndef PARALLELOGRAM_H
#define PARALLELOGRAM_H


class Parallelogram {
protected:
    double left_side{};//одна переменная на боковые стороны, т.к. они равны
    double top_side{};//аналогично боковым
    double hight{};//Высота
    double angel_top_left{};
    double angel_bottom_left{};

public:
    //ГЕТТЕРЫ И СЕТТЕРЫ
    virtual double Get_left_side() = 0;

    virtual double Get_top_side() = 0;

    virtual double Get_hight() = 0;

    virtual double Get_perimetr() = 0;

    virtual double Get_square() = 0;

    virtual double Get_angel_top_left() = 0;

    virtual double Get_angel_bottom_left() = 0;
    //

};



#endif //PARALLELOGRAM_H
