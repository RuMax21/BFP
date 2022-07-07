#include "parallelogram_sides.h"
#include <cmath>

double Parallelogram_sides::Get_top_side() {
    return this->top_side;
}

double Parallelogram_sides::Get_angel_bottom_left() {
    return this->angel_bottom_left;
}

double Parallelogram_sides::Get_left_side() {
    return this -> left_side;
}

double Parallelogram_sides::Get_hight() {
    return ( this -> left_side * sin ( angel_bottom_left * 3.14 / 180 ) );
}

double Parallelogram_sides::Get_angel_top_left() {

    return (180 - this -> angel_bottom_left);
}

Parallelogram_sides::Parallelogram_sides(double top_side, double left_side, double angel_bottom_left) {
    this->top_side = top_side;
    this->left_side = left_side;
    this->angel_bottom_left = angel_bottom_left;
}

double Parallelogram_sides::Get_perimetr() {
    return (this->top_side * 2 + this->left_side * 2);
}

double Parallelogram_sides::Get_square() {
    return ( this -> top_side * this -> Get_hight() );
}
