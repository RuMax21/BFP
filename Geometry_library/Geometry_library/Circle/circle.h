#ifndef CIRCLE_H
#define CIRCLE_H


#include <iostream>
#include <cmath>

#pragma once

class Circle {
private:
    float radius;//Радиус
    float diametr;//Диаметр
    float square{};//Площадь
    float perimeter{};//Периметр
public:
    explicit Circle(float radius);

    ~Circle();

    [[nodiscard]] float Get_radius() const;

    [[nodiscard]] float Get_diametr() const;

    [[nodiscard]] float Get_square() const;

    [[nodiscard]] float Get_perimeter() const;
};

#endif // CIRCLE_H
