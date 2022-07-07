#include "isosceles_triangle.h"
#include <cmath>



double Isosceles_triangle::Get_bottom_side() {
    return this -> bottom_side;
}

double Isosceles_triangle::Get_hight() {
    return this -> hight;
}

double Isosceles_triangle::Get_left_side() {
    return sqrt( pow( (0.5 * this -> bottom_side), 2) + pow((this -> hight),2) );
}

double Isosceles_triangle::Get_right_side() {
    return sqrt( pow( (0.5 * this -> bottom_side), 2) + pow((this -> hight),2) );
}
double Isosceles_triangle::Get_angel_bottom_left() {
    return (asin(this->hight / Get_left_side()) * 180 /3.14);
}
double Isosceles_triangle::Get_angel_bottom_right() {
    return (asin(this->hight / Get_right_side()) * 180 /3.14);
}

double Isosceles_triangle::Get_angel_top() {
    return ( 180 - ( this->Get_angel_bottom_right() + this -> Get_angel_bottom_left()) );
}

Isosceles_triangle::Isosceles_triangle(double bottom_side, double hight) {
    this -> bottom_side = bottom_side;
    this -> hight = hight;
}

double Isosceles_triangle::Get_perimetr() {
    return (this -> Get_left_side() + this -> Get_right_side() + this -> bottom_side);
}

double Isosceles_triangle::Get_square() {
    return (( this -> hight * this -> bottom_side ) / 2);
}

double Isosceles_triangle::Get_input_cathet(){
    return -1;
}

double Isosceles_triangle::Get_cathet(){
    return -1;
}
double Isosceles_triangle::Get_hypotenuse(){
    return -1;
}
