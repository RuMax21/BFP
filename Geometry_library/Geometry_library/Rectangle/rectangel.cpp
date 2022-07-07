#include "rectangel.h"

Rectangel::Rectangel(float width, float height)
{
    this->width = width;
    this->height = height;
}

float Rectangel::Get_width() const
{
    return this->width;
}

float Rectangel::Get_height() const
{
    return this->height;
}

float Rectangel::Get_square() const
{
    return (this->height * this->width);
}

float Rectangel::Get_perimeter() const
{
    return (this ->height * 2 + this->width * 2);
}
