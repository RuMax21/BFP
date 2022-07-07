#ifndef TRIANGLE_H
#define TRIANGLE_H


class Triangle {
protected:
    double left_side{};//Левая сторона треугольника
    double right_side{};//Правая сторона треугольника
    double bottom_side{};//Основание
    double hight{};//Высота
    double angel_bottom_right{};
    double angel_top{};
    double angel_bottom_left{};
    double input_cathet{};
    double cathet{};
    double hypotenuse{};

public:
    //ГЕТТЕРЫ И СЕТТЕРЫ
    virtual double Get_left_side() = 0;

    virtual double Get_right_side() = 0;

    virtual double Get_bottom_side() = 0;

    virtual double Get_hight() = 0;

    virtual double Get_perimetr() = 0;

    virtual double Get_square() = 0;

    virtual double Get_angel_bottom_right() = 0;

    virtual double Get_angel_top() = 0;

    virtual double Get_angel_bottom_left() = 0;

    virtual double Get_input_cathet() = 0;

    virtual double Get_cathet() = 0;

    virtual double Get_hypotenuse() = 0;
    //

};



#endif //TRIANGLE_H
