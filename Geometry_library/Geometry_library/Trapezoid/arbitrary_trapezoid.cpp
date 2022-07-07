#include "arbitrary_trapezoid.h"
#include <cmath>

double Arbitrary_trapezoid::Get_left_side() {
    return this -> left_side;
}

double Arbitrary_trapezoid::Get_right_side() {
    return this -> right_side;
}

double Arbitrary_trapezoid::Get_top_side() {
    return this -> top_side;
}

double Arbitrary_trapezoid::Get_bottom_side() {
    return this -> bottom_side;
}

double Arbitrary_trapezoid::Get_hight() {
    return (sqrt ( pow(this->left_side, 2) - ( pow( ( ((pow( (this->bottom_side - this->top_side), 2)) +
                                                       (pow(this->left_side, 2) - (pow(right_side, 2)))) / (2 * (this->bottom_side - this->top_side))), 2))));
}

double Arbitrary_trapezoid::Get_angel_bottom_left() {
    return (asin(Get_hight() / this->left_side )* 180 / 3.14);
}
double Arbitrary_trapezoid::Get_angel_bottom_right() {
    return (asin(Get_hight() / this->right_side )* 180 / 3.14);
}
double Arbitrary_trapezoid::Get_angel_top_left() {
    return (180 - this->Get_angel_bottom_left());
}
double Arbitrary_trapezoid::Get_angel_top_right() {
    return (180 - this->Get_angel_bottom_right());
}

Arbitrary_trapezoid::Arbitrary_trapezoid(double left_side, double right_side, double top_side, double bottom_side) {
    this -> left_side = left_side;
    this -> right_side = right_side;
    this -> top_side = top_side;
    this -> bottom_side = bottom_side;
}

double Arbitrary_trapezoid::Get_perimetr() {
    return (this -> left_side + this -> right_side + this -> top_side + this -> bottom_side);
}

double Arbitrary_trapezoid::Get_square() {
    return ( this -> Get_hight() * ( this -> top_side + this -> bottom_side ) * 0.5 );
}
