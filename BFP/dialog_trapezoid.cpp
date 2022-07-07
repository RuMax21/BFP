#include "dialog_trapezoid.h"
#include "ui_dialog_trapezoid.h"
//#include "/home/artem/MAIN_PROJECT/BFP/Geometry_library/Geometry_library/geometry_library.h"
#include "../Geometry_library/Geometry_library/geometry_library.h"
#include <QMessageBox>

Dialog_trapezoid::Dialog_trapezoid(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_trapezoid)
{
    ui->setupUi(this);
}

Dialog_trapezoid::~Dialog_trapezoid()
{
    delete ui;
}

void Dialog_trapezoid::painter_trap(double top_side, double bottom_side, double left_side, double right_side, double hight, double angel_bottom_left, double angel_bottom_right){
    if(angel_bottom_left > 89.8 and angel_bottom_left < 90.2){
        QGraphicsScene *scene;
        QGraphicsItemGroup *group1;

        scene = new QGraphicsScene();
        group1 = new QGraphicsItemGroup();

        scene->addItem(group1);

        ui->graphicsView->setScene(scene);

        group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));
        group1->addToGroup(scene->addLine(0, 0, 0, -hight));
        group1->addToGroup(scene->addLine(0, -hight, top_side - sqrt(pow(left_side,2) - pow(hight, 2)), -hight));
        group1->addToGroup(scene->addLine(top_side - sqrt(pow(left_side,2) - pow(hight, 2)), -hight, bottom_side, 0));
    }else if (left_side == right_side){
        QGraphicsScene *scene;
        QGraphicsItemGroup *group1;

        scene = new QGraphicsScene();
        group1 = new QGraphicsItemGroup();

        scene->addItem(group1);

        ui->graphicsView->setScene(scene);

        int ratio1 = ( bottom_side - top_side >= 0 ) ? ( bottom_side - top_side ) / 2 : 0;
        int ratio2 = ( top_side - bottom_side >= 0 ) ? ( top_side - bottom_side ) / 2 : 0;

        group1->addToGroup(scene->addLine(ratio1, ratio2, ratio1 + top_side, 0));
        group1->addToGroup(scene->addLine(ratio1, 0, ratio2, hight));
        group1->addToGroup(scene->addLine(ratio2, hight, bottom_side + ratio2, hight));
        group1->addToGroup(scene->addLine(bottom_side + ratio2, hight, top_side + ratio1, 0));
    }else{
        QGraphicsScene *scene;
        QGraphicsItemGroup *group1;

        scene = new QGraphicsScene();
        group1 = new QGraphicsItemGroup();

        scene->addItem(group1);

        ui->graphicsView->setScene(scene);

        //int ratio1 = ( bottom_side - top_side >= 0 ) ? ( bottom_side - top_side ) / 2 : 0;
        //int ratio2 = ( top_side - bottom_side >= 0 ) ? ( top_side - bottom_side ) / 2 : 0;
        double left, right;

        left = (left_side >= right_side) ? (left = left_side) : left = right_side;
        right = (left_side <= right_side) ? (right = left_side) : right = right_side;

        group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));
        group1->addToGroup(scene->addLine(0, 0, sqrt(pow(right,2) - pow(hight, 2)), -hight));
        group1->addToGroup(scene->addLine(sqrt(pow(right,2) - pow(hight, 2)), -hight, abs(bottom_side - sqrt(pow(right,2) - pow(hight, 2)) - sqrt(pow(right,2) - pow(hight, 2))), -hight));
        group1->addToGroup(scene->addLine(abs(bottom_side - sqrt(pow(right,2) - pow(hight, 2)) - sqrt(pow(right,2) - pow(hight, 2))), -hight, bottom_side, 0));

//        group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));
//        group1->addToGroup(scene->addLine(0, 0, sqrt(pow(left_side,2) - pow(hight, 2)), -hight));
//        group1->addToGroup(scene->addLine(sqrt(pow(left_side,2) - pow(hight, 2)), -hight, abs(bottom_side - sqrt(pow(left_side,2) - pow(hight, 2)) - sqrt(pow(left_side,2) - pow(hight, 2))), -hight));
//        group1->addToGroup(scene->addLine(abs(bottom_side - sqrt(pow(left_side,2) - pow(hight, 2)) - sqrt(pow(left_side,2) - pow(hight, 2))), -hight, bottom_side, 0));
    }


}


void Dialog_trapezoid::slot_arbitrary_trapezoid(double left_side, double right_side, double top_side, double bottom_side)
{
    Arbitrary_trapezoid *arb_trap = new Arbitrary_trapezoid(left_side,right_side,top_side,bottom_side);

    QString top_side_str = QString::number(arb_trap->Get_top_side());
    ui->tab_rect->setItem(0, 2, new QTableWidgetItem(top_side_str));

    QString bottom_side_str = QString::number(arb_trap->Get_bottom_side());
    ui->tab_rect->setItem(0, 3, new QTableWidgetItem(bottom_side_str));

    QString hight_str = QString::number(arb_trap->Get_hight());
    ui->tab_rect->setItem(0, 4, new QTableWidgetItem(hight_str));

    QString square_str = QString::number(arb_trap->Get_square());
    ui->tab_rect->setItem(0, 5, new QTableWidgetItem(square_str));

    QString perimetr_str = QString::number(arb_trap->Get_perimetr());
    ui->tab_rect->setItem(0, 6, new QTableWidgetItem(perimetr_str));

    //Заполнение таблицы углов



    if (arb_trap->Get_left_side() < arb_trap->Get_right_side()){

        QString left_side_str = QString::number(arb_trap->Get_left_side());
        ui->tab_rect->setItem(0, 0, new QTableWidgetItem(left_side_str));

        QString right_side_str = QString::number(arb_trap->Get_right_side());
        ui->tab_rect->setItem(0, 1, new QTableWidgetItem(right_side_str));

        QString left_bottom_str = QString::number(arb_trap->Get_angel_bottom_left());
        ui->table_ang->setItem(0, 0, new QTableWidgetItem(left_bottom_str));

        QString left_top_str = QString::number(arb_trap->Get_angel_top_left());
        ui->table_ang->setItem(0, 1, new QTableWidgetItem(left_top_str));

        QString right_top_str = QString::number(arb_trap->Get_angel_top_right());
        ui->table_ang->setItem(0, 2, new QTableWidgetItem(right_top_str));

        QString right_bottom_str = QString::number(arb_trap->Get_angel_bottom_right());
        ui->table_ang->setItem(0, 3, new QTableWidgetItem(right_bottom_str));
    }
    else{
        QString left_side_str = QString::number(arb_trap->Get_left_side());
        ui->tab_rect->setItem(0, 1, new QTableWidgetItem(left_side_str));

        QString right_side_str = QString::number(arb_trap->Get_right_side());
        ui->tab_rect->setItem(0, 0, new QTableWidgetItem(right_side_str));

        QString left_bottom_str = QString::number(arb_trap->Get_angel_bottom_left());
        ui->table_ang->setItem(0, 3, new QTableWidgetItem(left_bottom_str));

        QString left_top_str = QString::number(arb_trap->Get_angel_top_left());
        ui->table_ang->setItem(0, 2, new QTableWidgetItem(left_top_str));

        QString right_top_str = QString::number(arb_trap->Get_angel_top_right());
        ui->table_ang->setItem(0, 1, new QTableWidgetItem(right_top_str));

        QString right_bottom_str = QString::number(arb_trap->Get_angel_bottom_right());
        ui->table_ang->setItem(0, 0, new QTableWidgetItem(right_bottom_str));
    }



    painter_trap(arb_trap->Get_top_side(), arb_trap->Get_bottom_side(), arb_trap->Get_left_side(), arb_trap->Get_right_side(), arb_trap->Get_hight(), arb_trap->Get_angel_bottom_left(), arb_trap->Get_angel_bottom_right());
}

void Dialog_trapezoid::slot_isosceles_trapezoid(double top_side, double bottom_side, double hight)
{
    Isosceles_trapezoid *iso_trap = new Isosceles_trapezoid(top_side,bottom_side,hight);

    QString left_side_str = QString::number(iso_trap->Get_left_side());
    ui->tab_rect->setItem(0, 0, new QTableWidgetItem(left_side_str));

    QString right_side_str = QString::number(iso_trap->Get_right_side());
    ui->tab_rect->setItem(0, 1, new QTableWidgetItem(right_side_str));

    QString top_side_str = QString::number(iso_trap->Get_top_side());
    ui->tab_rect->setItem(0, 2, new QTableWidgetItem(top_side_str));

    QString bottom_side_str = QString::number(iso_trap->Get_bottom_side());
    ui->tab_rect->setItem(0, 3, new QTableWidgetItem(bottom_side_str));

    QString hight_str = QString::number(iso_trap->Get_hight());
    ui->tab_rect->setItem(0, 4, new QTableWidgetItem(hight_str));

    QString square_str = QString::number(iso_trap->Get_square());
    ui->tab_rect->setItem(0, 5, new QTableWidgetItem(square_str));

    QString perimetr_str = QString::number(iso_trap->Get_perimetr());
    ui->tab_rect->setItem(0, 6, new QTableWidgetItem(perimetr_str));

    //Заполнение таблицы углов
    QString left_bottom_str = QString::number(iso_trap->Get_angel_bottom_left());
    ui->table_ang->setItem(0, 0, new QTableWidgetItem(left_bottom_str));

    QString left_top_str = QString::number(iso_trap->Get_angel_top_left());
    ui->table_ang->setItem(0, 1, new QTableWidgetItem(left_top_str));

    QString right_top_str = QString::number(iso_trap->Get_angel_top_right());
    ui->table_ang->setItem(0, 2, new QTableWidgetItem(right_top_str));

    QString right_bottom_str = QString::number(iso_trap->Get_angel_bottom_right());
    ui->table_ang->setItem(0, 3, new QTableWidgetItem(right_bottom_str));

    painter_trap(iso_trap->Get_top_side(), iso_trap->Get_bottom_side(), iso_trap->Get_left_side(), iso_trap->Get_right_side(), iso_trap->Get_hight(), iso_trap->Get_angel_bottom_left(), iso_trap->Get_angel_bottom_right());

}

void Dialog_trapezoid::slot_rectangular_trapezoid(double top_side, double bottom_side, double left_side)
{
    Rectangular_trapezoid *rec_trap = new Rectangular_trapezoid(top_side,bottom_side,left_side);

    QString left_side_str = QString::number(rec_trap->Get_left_side());
    ui->tab_rect->setItem(0, 0, new QTableWidgetItem(left_side_str));

    QString right_side_str = QString::number(rec_trap->Get_right_side());
    ui->tab_rect->setItem(0, 1, new QTableWidgetItem(right_side_str));

    QString top_side_str = QString::number(rec_trap->Get_top_side());
    ui->tab_rect->setItem(0, 2, new QTableWidgetItem(top_side_str));

    QString bottom_side_str = QString::number(rec_trap->Get_bottom_side());
    ui->tab_rect->setItem(0, 3, new QTableWidgetItem(bottom_side_str));

    QString hight_str = QString::number(rec_trap->Get_hight());
    ui->tab_rect->setItem(0, 4, new QTableWidgetItem(hight_str));

    QString square_str = QString::number(rec_trap->Get_square());
    ui->tab_rect->setItem(0, 5, new QTableWidgetItem(square_str));

    QString perimetr_str = QString::number(rec_trap->Get_perimetr());
    ui->tab_rect->setItem(0, 6, new QTableWidgetItem(perimetr_str));

    //Заполнение таблицы углов
    QString left_bottom_str = QString::number(rec_trap->Get_angel_bottom_left());
    ui->table_ang->setItem(0, 0, new QTableWidgetItem(left_bottom_str));

    QString left_top_str = QString::number(rec_trap->Get_angel_top_left());
    ui->table_ang->setItem(0, 1, new QTableWidgetItem(left_top_str));

    QString right_top_str = QString::number(rec_trap->Get_angel_top_right());
    ui->table_ang->setItem(0, 2, new QTableWidgetItem(right_top_str));

    QString right_bottom_str = QString::number(rec_trap->Get_angel_bottom_right());
    ui->table_ang->setItem(0, 3, new QTableWidgetItem(right_bottom_str));

    painter_trap(rec_trap->Get_top_side(), rec_trap->Get_bottom_side(), rec_trap->Get_left_side(), rec_trap->Get_right_side(), rec_trap->Get_hight(), rec_trap->Get_angel_bottom_left(), rec_trap->Get_angel_bottom_right());
}
