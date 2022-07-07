#ifndef DIALOG_TRIANGLE_H
#define DIALOG_TRIANGLE_H

#include <QDialog>
#include <QPainter>
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItemGroup>

namespace Ui {
class Dialog_triangle;
}

class Dialog_triangle : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_triangle(QWidget *parent = nullptr);
    ~Dialog_triangle();

    void painter_triangle(double left_side, double right_side, double bottom_side, double hight, double angel_bottom_right);
public slots:
    void slot_angel_side_triangle(double bottom_side, double angel_bottom_left, double angel_bottom_right);
    void slot_isosceles_triangle(double bottom_side, double hight);
    void slot_arbitrary_triangle(double left_side, double right_side, double bottom_side);
    void slot_rectangular_triangle(double input_cathet, double hypotenuse);
private:
    Ui::Dialog_triangle *ui;
};

#endif // DIALOG_TRIANGLE_H
