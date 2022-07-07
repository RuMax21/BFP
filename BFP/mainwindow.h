#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsTextItem>
#include <cmath>
#include <QMessageBox>
#include "dialog_circle.h"
#include "dialog_rectangel.h"
#include "dialog_trapezoid.h"
#include "dialog_parallelogram.h"
#include "dialog_triangle.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void paint_cir();
    void paint_rect();
    void paint_par_hight();
    void paint_par_ang();
    void paint_tri_side();
    void paint_tri_nor();
    void paint_tri_iso();
    void paint_tri_s_ang();
    void paint_trap_arb();
    void paint_trap_rect();
    void paint_trap_iso();


signals:
    void signal_circle(double);
    void signal_rect(double, double);

    void signal_arbitrary_trapezoid(double,double,double,double );
    void signal_isosceles_trapezoid(double ,double,double);
    void signal_rectangular_trapezoid(double ,double,double);

    void signal_parallelogram_side_hight(double ,double,double);
    void signal_parallelogram_sides(double,double,double);

    void signal_angel_side_triangle(double,double,double);
    void signal_isosceles_triangle(double, double);
    void signal_arbitrary_triangle(double, double, double);
    void signal_rectangular_triangle(double, double);

    void signal_parallelogram(double, double, double, double);


private slots:
    void on_pushButtonCircle_clicked();

    void on_cmbChoise_currentIndexChanged(int index);

    void on_cmbBox2_currentIndexChanged(int index);

    void on_cmbBox3_currentIndexChanged(int index);

    void on_pushButton_clicked();

    void on_btn_trap_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    Dialog_circle *form_2;   //Круг
    Dialog_rectangel *form_3;//Прямоугольник
    Dialog_trapezoid *form_4;//Трапеция
    Dialog_parallelogram *form_5;//Параллелограмм
    Dialog_triangle *form_6;//Треугольник

    bool arb_trap_check();
    bool iso_trap_check();
    bool rec_trap_check();

    bool par_angle_check();
    bool par_hight_check();

    bool arb_tri_check();
    bool iso_tri_check();
    bool rec_tri_check();
    bool ang_tri_check();

};
#endif // MAINWINDOW_H
