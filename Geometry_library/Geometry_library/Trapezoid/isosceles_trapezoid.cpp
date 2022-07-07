#include "isosceles_trapezoid.h"
#include <cmath>

double Isosceles_trapezoid::Get_top_side() {
    return this->top_side;
}

double Isosceles_trapezoid::Get_bottom_side() {
    return this->bottom_side;
}

double Isosceles_trapezoid::Get_hight() {
    return this->hight;
}



double Isosceles_trapezoid::Get_right_side() { //
    return sqrt(pow(this->hight, 2) + pow(((this->bottom_side - this->top_side) / 2), 2));
}
double Isosceles_trapezoid::Get_left_side() {
    return sqrt(pow(this->hight, 2) + pow(((this->bottom_side - this->top_side) / 2), 2));
}

double Isosceles_trapezoid::Get_angel_bottom_right() {
    return (asin(this->hight / Get_right_side()) * 180 /3.14);
}

double Isosceles_trapezoid::Get_angel_top_right() {
    return 180 - Get_angel_bottom_right();
}

double Isosceles_trapezoid::Get_angel_top_left() {
    return 180 - Get_angel_bottom_right();
}

double Isosceles_trapezoid::Get_angel_bottom_left() {

    return  (asin(this->hight / Get_left_side()) * 180 /3.14);
}

Isosceles_trapezoid::Isosceles_trapezoid(double top_side, double bottom_side, double hight) {
    this->top_side = top_side;
    this->bottom_side = bottom_side;
    this->hight = hight;
}

double Isosceles_trapezoid::Get_perimetr() {
    return this->top_side + this->bottom_side + 2 * Get_right_side();
}

double Isosceles_trapezoid::Get_square() {
    return 0.5 * (this->top_side + this->bottom_side) * this->hight;
}
