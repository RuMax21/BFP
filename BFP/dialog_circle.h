#ifndef DIALOG_CIRCLE_H
#define DIALOG_CIRCLE_H

#include <QDialog>
#include <QPainter>
#include <QGraphicsScene>
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsItemGroup>

namespace Ui {
class Dialog_circle;
}

class Dialog_circle : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog_circle(QWidget *parent = nullptr);
    ~Dialog_circle();

    void painter_circle(double line);
public slots:
    void slot_circle(double line);

private:
    Ui::Dialog_circle *ui;
};

#endif // DIALOG_CIRCLE_H
