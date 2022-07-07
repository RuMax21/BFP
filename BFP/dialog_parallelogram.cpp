#include "dialog_parallelogram.h"
#include "ui_dialog_parallelogram.h"
//#include "/home/artem/MAIN_PROJECT/BFP/Geometry_library/Geometry_library/geometry_library.h"
#include "../Geometry_library/Geometry_library/geometry_library.h"

Dialog_parallelogram::Dialog_parallelogram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_parallelogram)
{
    ui->setupUi(this);
}

Dialog_parallelogram::~Dialog_parallelogram()
{
    delete ui;
}

void Dialog_parallelogram::painter_par(double height, double width, double angel_bottom_left, double hight){
    if(angel_bottom_left > 89.8 and angel_bottom_left < 90.2){
        QGraphicsScene *scene;
        QGraphicsItemGroup *group1;

        scene = new QGraphicsScene();
        group1 = new QGraphicsItemGroup();

        scene->addItem(group1);

        ui->graphicsView->setScene(scene);

        group1->addToGroup(scene->addRect(0, 0, height, width));
    }else{
        QGraphicsScene *scene;
        QGraphicsItemGroup *group1;

        scene = new QGraphicsScene();
        group1 = new QGraphicsItemGroup();

        scene->addItem(group1);

        ui->graphicsView->setScene(scene);

        group1->addToGroup(scene->addLine(0, 0, width, 0));
        group1->addToGroup(scene->addLine(0, 0, height, -hight));


        group1->addToGroup(scene->addLine(height, -hight, height + width, -hight));
        group1->addToGroup(scene->addLine(height + width, -hight, width, 0));
    }
}

void Dialog_parallelogram::slot_parallelogram_side_hight(double top_side, double left_side, double hight)
{
    Parallelogram_side_hight *p_s_h = new Parallelogram_side_hight(top_side,  left_side,  hight);

    QString left_side_str = QString::number(p_s_h->Get_left_side());
    ui->tab_rect->setItem(0, 0, new QTableWidgetItem(left_side_str));

    QString right_side_str = QString::number(p_s_h->Get_left_side());
    ui->tab_rect->setItem(0, 1, new QTableWidgetItem(right_side_str));

    QString top_side_str = QString::number(p_s_h->Get_top_side());
    ui->tab_rect->setItem(0, 2, new QTableWidgetItem(top_side_str));

    QString bottom_side_str = QString::number(p_s_h->Get_top_side());
    ui->tab_rect->setItem(0, 3, new QTableWidgetItem(bottom_side_str));

    QString hight_str = QString::number(p_s_h->Get_hight());
    ui->tab_rect->setItem(0, 4, new QTableWidgetItem(hight_str));

    QString square_str = QString::number(p_s_h->Get_square());
    ui->tab_rect->setItem(0, 5, new QTableWidgetItem(square_str));

    QString perimetr_str = QString::number(p_s_h->Get_perimetr());
    ui->tab_rect->setItem(0, 6, new QTableWidgetItem(perimetr_str));

    //Заполнение таблицы углов
    QString left_bottom_str = QString::number(p_s_h->Get_angel_bottom_left());
    ui->table_ang->setItem(0, 0, new QTableWidgetItem(left_bottom_str));

    QString left_top_str = QString::number(p_s_h->Get_angel_top_left());
    ui->table_ang->setItem(0, 1, new QTableWidgetItem(left_top_str));

    QString right_top_str = QString::number(p_s_h->Get_angel_top_left());
    ui->table_ang->setItem(0, 2, new QTableWidgetItem(right_top_str));

    QString right_bottom_str = QString::number(p_s_h->Get_angel_bottom_left());
    ui->table_ang->setItem(0, 3, new QTableWidgetItem(right_bottom_str));

    painter_par(p_s_h->Get_left_side(), p_s_h->Get_top_side(), p_s_h->Get_angel_bottom_left(), p_s_h->Get_hight());
}

void Dialog_parallelogram::slot_parallelogram_sides(double top_side, double left_side, double angel_bottom_left)
{
    Parallelogram_sides *par_sides = new Parallelogram_sides(top_side,left_side,angel_bottom_left);

    QString left_side_str = QString::number(par_sides->Get_left_side());
    ui->tab_rect->setItem(0, 0, new QTableWidgetItem(left_side_str));

    QString right_side_str = QString::number(par_sides->Get_left_side());
    ui->tab_rect->setItem(0, 1, new QTableWidgetItem(right_side_str));

    QString top_side_str = QString::number(par_sides->Get_top_side());
    ui->tab_rect->setItem(0, 2, new QTableWidgetItem(top_side_str));

    QString bottom_side_str = QString::number(par_sides->Get_top_side());
    ui->tab_rect->setItem(0, 3, new QTableWidgetItem(bottom_side_str));

    QString hight_str = QString::number(par_sides->Get_hight());
    ui->tab_rect->setItem(0, 4, new QTableWidgetItem(hight_str));

    QString square_str = QString::number(par_sides->Get_square());
    ui->tab_rect->setItem(0, 5, new QTableWidgetItem(square_str));

    QString perimetr_str = QString::number(par_sides->Get_perimetr());
    ui->tab_rect->setItem(0, 6, new QTableWidgetItem(perimetr_str));

    //Заполнение таблицы углов
    QString left_bottom_str = QString::number(par_sides->Get_angel_bottom_left());
    ui->table_ang->setItem(0, 0, new QTableWidgetItem(left_bottom_str));

    QString left_top_str = QString::number(par_sides->Get_angel_top_left());
    ui->table_ang->setItem(0, 1, new QTableWidgetItem(left_top_str));

    QString right_top_str = QString::number(par_sides->Get_angel_top_left());
    ui->table_ang->setItem(0, 2, new QTableWidgetItem(right_top_str));

    QString right_bottom_str = QString::number(par_sides->Get_angel_bottom_left());
    ui->table_ang->setItem(0, 3, new QTableWidgetItem(right_bottom_str));


    painter_par(par_sides->Get_left_side(), par_sides->Get_top_side(), par_sides->Get_angel_bottom_left(), par_sides->Get_hight());




}






