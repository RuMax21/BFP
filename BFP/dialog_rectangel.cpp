#include "dialog_rectangel.h"
#include "ui_dialog_rectangel.h"
//#include "/home/artem/MAIN_PROJECT/BFP/Geometry_library/Geometry_library/geometry_library.h"
#include "../Geometry_library/Geometry_library/geometry_library.h"

Dialog_rectangel::Dialog_rectangel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_rectangel)
{
    ui->setupUi(this);
}

Dialog_rectangel::~Dialog_rectangel()
{
    delete ui;
}

void Dialog_rectangel::painter_rect(float height, float width){

    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->graphicsView->setScene(scene);

    group1->addToGroup(scene->addRect(0, 0, height, width));
    //group1->addToGroup(scene->addLine(radius, radius, radius*0.3, radius*0.3));


}

void Dialog_rectangel::slot_rectangel(double val1, double val2)
{
        float height = static_cast<float>(val1);
        float width = static_cast<float>(val2);

        Rectangel *rectangel = new Rectangel(width, height);

        QString square = QString::number(rectangel->Get_square());
        ui->tab_rect->setItem(0, 0, new QTableWidgetItem(square));

        QString perimeter = QString::number(rectangel->Get_perimeter());
        ui->tab_rect->setItem(0, 1, new QTableWidgetItem(perimeter));

        painter_rect(val1, val2);
}
