#include "angel_side_triangle.h"
#include <cmath>

double Angel_side_triangle::Get_bottom_side() {
    return this -> bottom_side;
}

double Angel_side_triangle::Get_angel_bottom_left() {
    return (this -> angel_bottom_left);
}
double Angel_side_triangle::Get_angel_bottom_right() {
    return (this -> angel_bottom_right);
}

double Angel_side_triangle::Get_right_side() {
   return ( this -> bottom_side * sin(this -> angel_bottom_left*3.14/180) / sin(this -> Get_angel_top()*3.14/180) );
}

double Angel_side_triangle::Get_left_side() {
    return ( this -> bottom_side * sin(this -> angel_bottom_right*3.14/180) / sin(this -> Get_angel_top()*3.14/180) );
}

double Angel_side_triangle::Get_hight() {
    return (2 * this -> Get_square() / this -> bottom_side);
}

double Angel_side_triangle::Get_angel_top() {
    return ( 180 - ( this->angel_bottom_right + this -> angel_bottom_left) );
}

Angel_side_triangle::Angel_side_triangle(double bottom_side, double angel_bottom_left, double angel_bottom_right) {
    this -> bottom_side = bottom_side;
    this -> angel_bottom_left = angel_bottom_left;
    this -> angel_bottom_right = angel_bottom_right;
}

double Angel_side_triangle::Get_perimetr() {
    return (this -> Get_left_side() + this -> Get_right_side() + this -> bottom_side);
}

double Angel_side_triangle::Get_square() {
    return ( this -> bottom_side * this -> Get_left_side() * sin(this -> angel_bottom_left*3.14/180) * 0.5 );
}

double Angel_side_triangle::Get_input_cathet(){
    return -1;
}

double Angel_side_triangle::Get_cathet(){
    return -1;
}
double Angel_side_triangle::Get_hypotenuse(){
    return -1;
}
