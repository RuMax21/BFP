#include "dialog_circle.h"
#include "ui_dialog_circle.h"
//#include "/home/artem/MAIN_PROJECT/BFP/Geometry_library/Geometry_library/geometry_library.h"
#include "../Geometry_library/Geometry_library/geometry_library.h"

Dialog_circle::Dialog_circle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_circle)
{
    ui->setupUi(this);
}

Dialog_circle::~Dialog_circle()
{
    delete ui;
}

void Dialog_circle::painter_circle(double radius){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->graph_circle->setScene(scene);

    group1->addToGroup(scene->addEllipse( -2*radius*(pow(2, 0.5))/4, -2*radius*(pow(2, 0.5))/4, radius*2, radius*2));
    group1->addToGroup(scene->addLine(radius, radius, radius*0.3, radius*0.3));


}

void Dialog_circle::slot_circle(double line)
{
    float radius = static_cast<float>(line);
        Circle *circle = new Circle(radius);

        QString perimetr = QString::number(circle->Get_perimeter());
        ui->table->setItem(0, 0, new QTableWidgetItem(perimetr));

        QString rad = QString::number(circle->Get_radius());
        ui->table->setItem(0, 1, new QTableWidgetItem(rad));

        QString diametr = QString::number(circle->Get_diametr());
        ui->table->setItem(0, 2, new QTableWidgetItem(diametr));

        QString square = QString::number(circle->Get_square());
        ui->table->setItem(0, 3, new QTableWidgetItem(square));

        painter_circle(line);
}

