#include "parallelogram_side_hight.h"
#include <cmath>

double Parallelogram_side_hight::Get_top_side() {
    return this->top_side;
}

double Parallelogram_side_hight::Get_hight() {
    return this->hight;
}

double Parallelogram_side_hight::Get_left_side() {
    return this -> left_side;
}

double Parallelogram_side_hight::Get_angel_top_left() { // равен нижнему правому
    return 180 - Get_angel_bottom_left();
}

double Parallelogram_side_hight::Get_angel_bottom_left() { // равен верхнему правому

    return (asin(this->hight / this -> left_side) * 180 /3.14);
}

Parallelogram_side_hight::Parallelogram_side_hight(double top_side, double left_side, double hight) {
    this->top_side = top_side;
    this->left_side = left_side;
    this->hight = hight;
}

double Parallelogram_side_hight::Get_perimetr() {
    return (this->top_side * 2 + this->left_side * 2);
}

double Parallelogram_side_hight::Get_square() {
    return ( this -> top_side * this -> hight );
}
