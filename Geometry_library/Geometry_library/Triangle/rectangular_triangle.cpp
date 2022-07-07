#include "rectangular_triangle.h"
#include <cmath>



double Rectangular_triangle::Get_input_cathet() {
    return this -> input_cathet;
}

double Rectangular_triangle::Get_hypotenuse() {
    return this -> hypotenuse;
}

double Rectangular_triangle::Get_cathet() {
    return sqrt( pow ( (this -> hypotenuse), 2) - pow ((this -> input_cathet),2)) ;
}

double Rectangular_triangle::Get_angel_bottom_left() {
    return (asin( this -> input_cathet / this -> hypotenuse) * 180 / 3.14);
}
double Rectangular_triangle::Get_angel_bottom_right() {
    return 90;
}

double Rectangular_triangle::Get_angel_top() {
    return ( 90 - Get_angel_bottom_left() );
}

Rectangular_triangle::Rectangular_triangle(double input_cathet, double hypotenuse) {
    this -> input_cathet = input_cathet;
    this -> hypotenuse = hypotenuse;
}

double Rectangular_triangle::Get_perimetr() {
    return (this -> input_cathet + this -> Get_cathet() + this -> hypotenuse);
}

double Rectangular_triangle::Get_square() {
    return ( 0.5 * this -> Get_cathet() * this -> input_cathet );
}

double Rectangular_triangle::Get_hight(){
    return input_cathet;
}

double Rectangular_triangle::Get_left_side(){
    return -1;
}

double Rectangular_triangle::Get_right_side(){
    return -1;
}

double Rectangular_triangle::Get_bottom_side(){
    return -1;
}
