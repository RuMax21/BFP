#ifndef RECTANGEL_H
#define RECTANGEL_H


class Rectangel {
private:
    float width;
    float height;
public:
    Rectangel(float width, float height);
    ~Rectangel();

    float Get_width() const;
    float Get_height() const;
    float Get_square() const;
    float Get_perimeter() const;
};

#endif // RECTANGEL_H
