#include "arbitrary_triangle.h"
#include <cmath>

double Arbitrary_triangle::Get_left_side() {
    return this -> left_side;
}

double Arbitrary_triangle::Get_right_side() {
    return this -> right_side;
}

double Arbitrary_triangle::Get_bottom_side() {
    return this -> bottom_side;
}

double Arbitrary_triangle::Get_hight() {
    return (2 * this -> Get_square() / this -> bottom_side);
}

double Arbitrary_triangle::Get_angel_bottom_left() {
    return (acos( ( -pow(this->right_side, 2) + pow(this->left_side, 2) + pow(this->bottom_side, 2) ) / ( 2 * this->left_side * bottom_side ) ) * 180 / 3.14);
}
double Arbitrary_triangle::Get_angel_bottom_right() {
    return (asin(this->Get_hight() / this -> right_side) * 180 /3.14);
}

double Arbitrary_triangle::Get_angel_top() {
    return ( 180 - ( this->Get_angel_bottom_right() + this -> Get_angel_bottom_left()) );
}

Arbitrary_triangle::Arbitrary_triangle(double left_side, double right_side, double bottom_side) {
    this -> left_side = left_side;
    this -> right_side = right_side;
    this -> bottom_side = bottom_side;
}

double Arbitrary_triangle::Get_perimetr() {
    return (this -> left_side + this -> right_side + this -> bottom_side);
}

double Arbitrary_triangle::Get_square() {
    return ( sqrt( this -> Get_perimetr() * 0.5 * (this -> Get_perimetr() * 0.5 - this -> left_side) * (this -> Get_perimetr() * 0.5 - this -> right_side) * (this -> Get_perimetr() * 0.5 - this -> bottom_side) ) );
}

double Arbitrary_triangle::Get_input_cathet(){
    return -1;
}

double Arbitrary_triangle::Get_cathet(){
    return -1;
}
double Arbitrary_triangle::Get_hypotenuse(){
    return -1;
}
