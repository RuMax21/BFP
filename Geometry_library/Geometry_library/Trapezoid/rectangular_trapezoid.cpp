#include "rectangular_trapezoid.h"
#include <cmath>

double Rectangular_trapezoid::Get_top_side() {
    return this->top_side;
}

double Rectangular_trapezoid::Get_bottom_side() {
    return this->bottom_side;
}

double Rectangular_trapezoid::Get_left_side() {
    return this -> left_side;
}

double Rectangular_trapezoid::Get_right_side() {
    return (sqrt( pow(this -> left_side, 2) + pow( (this -> bottom_side - this -> top_side), 2)));
}

double Rectangular_trapezoid::Get_hight() {
    return (this->left_side);
}

double Rectangular_trapezoid::Get_angel_bottom_left() {
    return 90;
}
double Rectangular_trapezoid::Get_angel_bottom_right() {
    return (asin(this->Get_hight() / this->Get_right_side()) * 180 / 3.14);
}
double Rectangular_trapezoid::Get_angel_top_left() {
    return 90;
}
double Rectangular_trapezoid::Get_angel_top_right() {
    return (180 - this->Get_angel_bottom_right());
}

Rectangular_trapezoid::Rectangular_trapezoid(double top_side, double bottom_side, double left_side) {
    this->top_side = top_side;
    this->bottom_side = bottom_side;
    this->left_side = left_side;
}

double Rectangular_trapezoid::Get_perimetr() {
    return (this->top_side + this->bottom_side + this->Get_right_side() + this->left_side);
}

double Rectangular_trapezoid::Get_square() {
    return (0.5 * (this->top_side + this->bottom_side) * this->left_side);
}
