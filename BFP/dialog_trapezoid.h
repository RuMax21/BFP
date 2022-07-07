#ifndef DIALOG_TRAPEZOID_H
#define DIALOG_TRAPEZOID_H

#include <QDialog>
#include <QPainter>
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItemGroup>

namespace Ui {
class Dialog_trapezoid;
}

class Dialog_trapezoid : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_trapezoid(QWidget *parent = nullptr);
    ~Dialog_trapezoid();

    void painter_trap(double top_side, double bottom_side, double left_side, double right_side, double hight, double angel_bottom_left, double angel_bottom_right);
public slots:
   void slot_arbitrary_trapezoid(double left_side, double right_side, double top_side, double bottom_side);
   void slot_isosceles_trapezoid(double top_side, double bottom_side, double hight);
   void slot_rectangular_trapezoid(double top_side, double bottom_side, double left_side);

private:
    Ui::Dialog_trapezoid *ui;
};

#endif // DIALOG_TRAPEZOID_H
