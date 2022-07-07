#include "dialog_triangle.h"
#include "ui_dialog_triangle.h"
//#include "/home/artem/MAIN_PROJECT/BFP/Geometry_library/Geometry_library/geometry_library.h"
#include "../Geometry_library/Geometry_library/geometry_library.h"

Dialog_triangle::Dialog_triangle(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog_triangle)
{
    ui->setupUi(this);
}

Dialog_triangle::~Dialog_triangle()
{
    delete ui;
}

void Dialog_triangle::painter_triangle(double left_side, double right_side, double bottom_side, double hight, double angel_bottom_right){

    if (angel_bottom_right > 89.8 and angel_bottom_right < 90.2){
        QGraphicsScene *scene;
        QGraphicsItemGroup *group1;

        scene = new QGraphicsScene();
        group1 = new QGraphicsItemGroup();

        scene->addItem(group1);

        ui->graphicsView->setScene(scene);

        group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));
        group1->addToGroup(scene->addLine(0, 0, bottom_side, -left_side));
        group1->addToGroup(scene->addLine(bottom_side, -left_side, bottom_side, 0));
    }else{
        QGraphicsScene *scene;
        QGraphicsItemGroup *group1;

        scene = new QGraphicsScene();
        group1 = new QGraphicsItemGroup();

        scene->addItem(group1);

        ui->graphicsView->setScene(scene);

        group1->addToGroup(scene->addLine(0, 0, sqrt ( pow( left_side, 2 ) - pow ( hight, 2 ) ), -hight ));
        group1->addToGroup(scene->addLine(sqrt ( pow( left_side, 2 ) - pow ( hight, 2 ) ), -hight , bottom_side, 0));
        group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));

    }
    //    group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));
    //    group1->addToGroup(scene->addLine(0, 0, left_side, -hight));
    //    group1->addToGroup(scene->addLine(left_side, -hight, right_side, bottom_side));
        //group1->addToGroup(scene->addLine(radius, radius, radius*0.3, radius*0.3));

    //group1->addToGroup(scene->addLine(0, 0, left_side * cos( sqrt( pow( 0.5 * bottom_side , 2) + pow(hight, 2 ) ) * 3.14 / 180), -hight));
    //group1->addToGroup(scene->addLine(left_side * cos( sqrt( pow( 0.5 * bottom_side , 2) + pow(hight, 2 ) ) * 3.14 / 180 ), -hight, right_side * cos( sqrt( pow( 0.5 * bottom_side , 2) + pow(hight, 2 ) ) * 3.14 / 180 ), 0));
    //group1->addToGroup(scene->addLine(0, 0, right_side * cos( sqrt( pow( 0.5 * bottom_side , 2) + pow(hight, 2 ) ) * 3.14 / 180 ), 0));

}

void Dialog_triangle::slot_angel_side_triangle(double bottom_side, double angel_bottom_left, double angel_bottom_right)
{
    Angel_side_triangle *ang_s_tri = new Angel_side_triangle(bottom_side,angel_bottom_left,angel_bottom_right);

    QString left_side_str = QString::number(ang_s_tri->Get_left_side());
    ui->tab_rect->setItem(0, 0, new QTableWidgetItem(left_side_str));

    QString right_side_str = QString::number(ang_s_tri->Get_right_side());
    ui->tab_rect->setItem(0, 1, new QTableWidgetItem(right_side_str));

    QString bottom_side_str = QString::number(ang_s_tri->Get_bottom_side());
    ui->tab_rect->setItem(0, 2, new QTableWidgetItem(bottom_side_str));

    QString hight_str = QString::number(ang_s_tri->Get_hight());
    ui->tab_rect->setItem(0, 3, new QTableWidgetItem(hight_str));

    QString square = QString::number(ang_s_tri->Get_square());
    ui->tab_rect->setItem(0, 4, new QTableWidgetItem(square));

    QString perimetr_str = QString::number(ang_s_tri->Get_perimetr());
    ui->tab_rect->setItem(0, 5, new QTableWidgetItem(perimetr_str));

    //Заполнение таблицы углов
    QString left_bottom_str = QString::number(ang_s_tri->Get_angel_bottom_left());
    ui->table_ang->setItem(0, 0, new QTableWidgetItem(left_bottom_str));

    QString right_bottom_str = QString::number(ang_s_tri->Get_angel_bottom_right());
    ui->table_ang->setItem(0, 1, new QTableWidgetItem(right_bottom_str));

    QString top_str = QString::number(ang_s_tri->Get_angel_top());
    ui->table_ang->setItem(0, 2, new QTableWidgetItem(top_str));

    painter_triangle(ang_s_tri->Get_left_side(), ang_s_tri->Get_right_side(), ang_s_tri->Get_bottom_side(), ang_s_tri->Get_hight(), ang_s_tri->Get_angel_bottom_right());
}

void Dialog_triangle::slot_isosceles_triangle(double bottom_side, double hight)
{
    Isosceles_triangle *isos_tri = new Isosceles_triangle(bottom_side,hight);

    QString left_side_str = QString::number(isos_tri->Get_left_side());
    ui->tab_rect->setItem(0, 0, new QTableWidgetItem(left_side_str));

    QString right_side_str = QString::number(isos_tri->Get_right_side());
    ui->tab_rect->setItem(0, 1, new QTableWidgetItem(right_side_str));

    QString bottom_side_str = QString::number(isos_tri->Get_bottom_side());
    ui->tab_rect->setItem(0, 2, new QTableWidgetItem(bottom_side_str));

    QString hight_str = QString::number(isos_tri->Get_hight());
    ui->tab_rect->setItem(0, 3, new QTableWidgetItem(hight_str));

    QString square = QString::number(isos_tri->Get_square());
    ui->tab_rect->setItem(0, 4, new QTableWidgetItem(square));

    QString perimetr_str = QString::number(isos_tri->Get_perimetr());
    ui->tab_rect->setItem(0, 5, new QTableWidgetItem(perimetr_str));

    //Заполнение таблицы углов
    QString left_bottom_str = QString::number(isos_tri->Get_angel_bottom_left());
    ui->table_ang->setItem(0, 0, new QTableWidgetItem(left_bottom_str));

    QString right_bottom_str = QString::number(isos_tri->Get_angel_bottom_right());
    ui->table_ang->setItem(0, 1, new QTableWidgetItem(right_bottom_str));

    QString top_str = QString::number(isos_tri->Get_angel_top());
    ui->table_ang->setItem(0, 2, new QTableWidgetItem(top_str));

    painter_triangle(isos_tri->Get_left_side(), isos_tri->Get_right_side(), isos_tri->Get_bottom_side(), isos_tri->Get_hight(), isos_tri->Get_angel_bottom_right());

}

void Dialog_triangle::slot_arbitrary_triangle(double left_side, double right_side, double bottom_side)
{
    Arbitrary_triangle *arb_tri = new Arbitrary_triangle(left_side, right_side, bottom_side);

    QString left_side_str = QString::number(arb_tri->Get_left_side());
    ui->tab_rect->setItem(0, 0, new QTableWidgetItem(left_side_str));

    QString right_side_str = QString::number(arb_tri->Get_right_side());
    ui->tab_rect->setItem(0, 1, new QTableWidgetItem(right_side_str));

    QString bottom_side_str = QString::number(arb_tri->Get_bottom_side());
    ui->tab_rect->setItem(0, 2, new QTableWidgetItem(bottom_side_str));

    QString hight_str = QString::number(arb_tri->Get_hight());
    ui->tab_rect->setItem(0, 3, new QTableWidgetItem(hight_str));

    QString square = QString::number(arb_tri->Get_square());
    ui->tab_rect->setItem(0, 4, new QTableWidgetItem(square));

    QString perimetr_str = QString::number(arb_tri->Get_perimetr());
    ui->tab_rect->setItem(0, 5, new QTableWidgetItem(perimetr_str));

    //Заполнение таблицы углов
    QString left_bottom_str = QString::number(arb_tri->Get_angel_bottom_left());
    ui->table_ang->setItem(0, 0, new QTableWidgetItem(left_bottom_str));

    QString right_bottom_str = QString::number(arb_tri->Get_angel_bottom_right());
    ui->table_ang->setItem(0, 1, new QTableWidgetItem(right_bottom_str));

    QString top_str = QString::number(arb_tri->Get_angel_top());
    ui->table_ang->setItem(0, 2, new QTableWidgetItem(top_str));


    painter_triangle(arb_tri->Get_left_side(), arb_tri->Get_right_side(), arb_tri->Get_bottom_side(), arb_tri->Get_hight(), arb_tri->Get_angel_bottom_right());
}

void Dialog_triangle::slot_rectangular_triangle(double input_cathet, double hypotenuse)
{
    Rectangular_triangle *rect_tri = new Rectangular_triangle(input_cathet, hypotenuse);

    ui->tab_rect->horizontalHeaderItem(0)->setText("Вводимый катет");
    ui->tab_rect->horizontalHeaderItem(1)->setText("Катет");
    ui->tab_rect->horizontalHeaderItem(2)->setText("Гипотенуза");

    QString input_cathet_str = QString::number(rect_tri->Get_input_cathet());
    ui->tab_rect->setItem(0, 0, new QTableWidgetItem(input_cathet_str));

    QString cathet_str = QString::number(rect_tri->Get_cathet());
    ui->tab_rect->setItem(0, 1, new QTableWidgetItem(cathet_str));

    QString hypotenuse_str = QString::number(rect_tri->Get_hypotenuse());
    ui->tab_rect->setItem(0, 2, new QTableWidgetItem(hypotenuse_str));

    QString hight_str = QString::number(rect_tri->Get_hight());
    ui->tab_rect->setItem(0, 3, new QTableWidgetItem(hight_str));

    QString square = QString::number(rect_tri->Get_square());
    ui->tab_rect->setItem(0, 4, new QTableWidgetItem(square));

    QString perimetr_str = QString::number(rect_tri->Get_perimetr());
    ui->tab_rect->setItem(0, 5, new QTableWidgetItem(perimetr_str));

    //Заполнение таблицы углов
    QString left_bottom_str = QString::number(rect_tri->Get_angel_bottom_left());
    ui->table_ang->setItem(0, 0, new QTableWidgetItem(left_bottom_str));

    QString right_bottom_str = QString::number(rect_tri->Get_angel_bottom_right());
    ui->table_ang->setItem(0, 1, new QTableWidgetItem(right_bottom_str));

    QString top_str = QString::number(rect_tri->Get_angel_top());
    ui->table_ang->setItem(0, 2, new QTableWidgetItem(top_str));

    painter_triangle(rect_tri->Get_input_cathet(), rect_tri->Get_cathet(), rect_tri->Get_hypotenuse(), rect_tri->Get_hight(), rect_tri->Get_angel_bottom_right());

}
