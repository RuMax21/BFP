#include "circle.h"

Circle::Circle(float radius) {
    this->radius = radius;
    this->diametr = 2 * radius;
}

Circle::~Circle() {};

float Circle::Get_radius() const { return radius; }

float Circle::Get_diametr() const { return diametr; }

float Circle::Get_square() const { return pow(radius, 2) * 3.14; }

float Circle::Get_perimeter() const { return 2 * 3.14 * radius; }
