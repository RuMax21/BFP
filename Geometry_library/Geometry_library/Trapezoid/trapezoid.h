#ifndef TRAPEZOID_H
#define TRAPEZOID_H


class Trapezoid {
protected:
    double left_side{};//Левая сторона трапеции
    double right_side{};//Правая сторона трапеции
    double top_side{};//Верхнее основание
    double bottom_side{};//Нижнее основание
    double hight{};//Высота
    double angel_bottom_right{};
    double angel_top_right{};
    double angel_top_left{};
    double angel_bottom_left{};

public:
    //ГЕТТЕРЫ И СЕТТЕРЫ
    virtual double Get_left_side() = 0;

    virtual double Get_right_side() = 0;

    virtual double Get_top_side() = 0;

    virtual double Get_bottom_side() = 0;

    virtual double Get_hight() = 0;

    virtual double Get_perimetr() = 0;

    virtual double Get_square() = 0;

    virtual double Get_angel_bottom_right() = 0;

    virtual double Get_angel_top_right() = 0;

    virtual double Get_angel_top_left() = 0;

    virtual double Get_angel_bottom_left() = 0;
    //

};



#endif //TRAPEZOID_H
