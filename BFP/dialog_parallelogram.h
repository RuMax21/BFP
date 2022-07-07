#ifndef DIALOG_PARALLELOGRAM_H
#define DIALOG_PARALLELOGRAM_H

#include <QDialog>
#include <QPainter>
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItemGroup>

namespace Ui {
class Dialog_parallelogram;
}

class Dialog_parallelogram : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_parallelogram(QWidget *parent = nullptr);
    ~Dialog_parallelogram();

    void painter_par(double height, double width, double angel_bottom_left, double hight);
public slots:
    void slot_parallelogram_side_hight(double top_side, double left_side, double hight);
    void slot_parallelogram_sides(double top_side, double left_side, double angel_bottom_left);

private:
    Ui::Dialog_parallelogram *ui;
};

#endif // DIALOG_PARALLELOGRAM_H
