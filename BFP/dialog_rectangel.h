#ifndef DIALOG_RECTANGEL_H
#define DIALOG_RECTANGEL_H

#include <QDialog>
#include <QPainter>
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItemGroup>

namespace Ui {
class Dialog_rectangel;
}

class Dialog_rectangel : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_rectangel(QWidget *parent = nullptr);
    ~Dialog_rectangel();

    void painter_rect(float height, float width);

public slots:
    void slot_rectangel(double val1, double val2);

private:
    Ui::Dialog_rectangel *ui;
};

#endif // DIALOG_RECTANGEL_H
