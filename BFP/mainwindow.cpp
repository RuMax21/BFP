#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //ФОРМА ОКРУЖНОСТИ
        paint_cir();
        form_2 = new Dialog_circle;
        form_2->setWindowTitle("BF Circle");
        connect(this, &MainWindow::signal_circle, form_2, &Dialog_circle::slot_circle);
    //Форма прямоугольника
        paint_rect();
        form_3 = new Dialog_rectangel;
        form_3->setWindowTitle("BF Rectangel");
        connect(this, &MainWindow::signal_rect, form_3, &Dialog_rectangel::slot_rectangel);
    //Форма под трапецию
        paint_trap_arb();
        form_4 = new Dialog_trapezoid;
        form_4->setWindowTitle("BF Trapezoid");
        connect(this, &MainWindow::signal_arbitrary_trapezoid, form_4, &Dialog_trapezoid::slot_arbitrary_trapezoid);
        connect(this, &MainWindow::signal_isosceles_trapezoid, form_4, &Dialog_trapezoid::slot_isosceles_trapezoid);
        connect(this, &MainWindow::signal_rectangular_trapezoid, form_4, &Dialog_trapezoid::slot_rectangular_trapezoid);
    //Форма под параллелограмм
        paint_par_hight();
        form_5 = new Dialog_parallelogram;
        form_5->setWindowTitle("BF parallelogram");
        connect(this, &MainWindow::signal_parallelogram_side_hight, form_5, &Dialog_parallelogram::slot_parallelogram_side_hight);
        connect(this, &MainWindow::signal_parallelogram_sides, form_5, &Dialog_parallelogram::slot_parallelogram_sides);
     //Форма под треугольник
        paint_tri_side();
        form_6 = new Dialog_triangle;
        form_6->setWindowTitle("BF triangle");
        connect(this, &MainWindow::signal_angel_side_triangle, form_6, &Dialog_triangle::slot_angel_side_triangle);
        connect(this, &MainWindow::signal_isosceles_triangle, form_6, &Dialog_triangle::slot_isosceles_triangle);
        connect(this, &MainWindow::signal_arbitrary_triangle, form_6, &Dialog_triangle::slot_arbitrary_triangle);
        connect(this, &MainWindow::signal_rectangular_triangle, form_6, &Dialog_triangle::slot_rectangular_triangle);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonCircle_clicked()
{
    emit signal_circle(ui->doubleSpinBox->value());
        form_2->show();
}




void MainWindow::on_cmbChoise_currentIndexChanged(int index)
{
    switch (index) {
        case 0: // все стороны
            paint_trap_arb();
            ui->label_3->setText("Укажите все стороны:");
            ui->f_text1->setText("Меньшее основание:");
            ui->f_text2->setText("Большее основание:");
            ui->s_text1->setText("Боковая сторона:");
            ui->s_text2->setText("Боковая сторона:");
            ui->s_text1->setText("Боковая сторона:");
            ui->s_text1->setVisible(true);
            ui->s_text2->setText("Боковая сторона:");
            ui->s_text2->setVisible(true);
            ui->side1->setVisible(true);
            ui->side2->setVisible(true);
            break;
        case 1: // равнобедренная
            paint_trap_iso();
            ui->label_3->setText("Укажите основания и высоту:");
            ui->f_text1->setText("Меньшее основание:");
            ui->f_text2->setText("Большее основание:");
            ui->s_text1->setText("Высота:");
            ui->s_text2->setVisible(false);
            ui->side2->setVisible(false);
            break;
        case 2: // прямоугольная
            paint_trap_rect();
            ui->label_3->setText("Укажите основания и боковую сторону:");
            ui->f_text1->setText("Меньшее основание:");
            ui->f_text2->setText("Большее основание:");
            ui->s_text1->setText("Боковая сторона:");
            ui->s_text1->setVisible(true);
            ui->s_text2->setVisible(false);
            ui->side1->setVisible(true);
            ui->side2->setVisible(false);
            break;
    }
}

void MainWindow::on_cmbBox2_currentIndexChanged(int index)
{
    switch (index) {
        case 0:
            paint_par_hight();
            ui->label_11->setText("Укажите стороны и высоту:");
            ui->label_10->setText("Высота h<sub>b</sub>");
            break;
        case 1:
            paint_par_ang();
            ui->label_11->setText("Укажите стороны и угол:");
            ui->label_10->setText("Угол α");
            break;
    }
}

void MainWindow::on_cmbBox3_currentIndexChanged(int index)
{
    switch (index) {
        case 1:
            paint_tri_iso();
            ui->label_13->setText("Укажите сторону и высоту:");
            ui->label_14->setText("Боковая сторона");
            ui->label_15->setText("Высота");
            ui->label_16->setVisible(false);
            ui->doubleSpinBox_9->setVisible(false);
            break;
        case 0:
            paint_tri_side();
            ui->label_16->setVisible(true);
            ui->doubleSpinBox_9->setVisible(true);
            ui->label_13->setText("Укажите все стороны:");
            ui->label_14->setText("Сторона <b>a</b>");
            ui->label_15->setText("Сторона <b>b</b>");
            ui->label_16->setText("Сторона <b>c</b>");
            break;
        case 2:
            paint_tri_nor();
            ui->label_13->setText("Укажите катет и гипотенузу:");
            ui->label_14->setText("Катет");
            ui->label_15->setText("Гипотенуза");
            ui->label_16->setVisible(false);
            ui->doubleSpinBox_9->setVisible(false);
            break;
        case 3:
            paint_tri_s_ang();
            ui->label_16->setVisible(true);
            ui->doubleSpinBox_9->setVisible(true);
            ui->label_13->setText("Укажите 2 угла и сторону:");
            ui->label_14->setText("Сторона <b>a</b>");
            ui->label_15->setText("Угол <b>α</b>");
            ui->label_16->setText("Угол <b>β</b>");
            break;
        }
}


void MainWindow::on_pushButton_clicked()
{
    emit signal_rect( ui->doubleSpinBox_2->value(), ui->doubleSpinBox_3->value() );
       form_3->show();
}


void MainWindow::on_btn_trap_clicked()
{
    int index = 0;
    index = ui->cmbChoise->currentIndex();

    switch(index){
    case 0:{

        if ( arb_trap_check() == true ){
            emit signal_arbitrary_trapezoid(ui->side1->value(), ui->side2->value(), ui->footing1->value(), ui->footing2->value());
            form_4 -> show();
            break;
        }else{
            QMessageBox::warning(this, "Ошибка", "Такой трапеции не сущеаствует!!");
            break;
        }
    }
    case 1:{
        if( iso_trap_check() == true ){
           emit signal_isosceles_trapezoid(ui->footing2->value(), ui->footing1->value(), ui->side1->value());
           form_4 -> show();
           break;
        }else{
            QMessageBox::warning(this, "Ошибка", "Такой трапеции не сущеаствует!!");
            break;
        }
    }
    case 2:{
        if(rec_trap_check() == true){
            emit signal_rectangular_trapezoid(ui->footing2->value(), ui->footing1->value(), ui->side1->value());
            form_4->show();
            break;
        }else{
            QMessageBox::warning(this, "Ошибка", "Такой трапеции не сущеаствует!!");
            break;
        }
    }
    default: ;
    }

}


void MainWindow::on_pushButton_3_clicked()
{
    int index = 0;

    index = ui->cmbBox2->currentIndex();

    switch(index){
    case 0:{
        if (par_hight_check() == true){
            emit signal_parallelogram_side_hight(ui->doubleSpinBox_4->value(), ui->doubleSpinBox_5->value(),ui->doubleSpinBox_6->value());
            form_5->show();
            break;
        }else{
            QMessageBox::warning(this, "Ошибка", "Такого параллелограмма не сущеаствует!!");
            break;
        }
    }
    case 1:{
        if ( par_angle_check() == true ){
            emit signal_parallelogram_sides(ui->doubleSpinBox_4->value(), ui->doubleSpinBox_5->value(),ui->doubleSpinBox_6->value());
            form_5->show();
            break;
        }else{
            QMessageBox::warning(this, "Ошибка", "Такого параллелограмма не сущеаствует!!");
            break;
        }
    }



    }
}


void MainWindow::on_pushButton_4_clicked()
{
    int index = 0;
    index = ui-> cmbBox3->currentIndex();

    switch(index){
    case 3:{
        if(ang_tri_check() == true){
            emit signal_angel_side_triangle(ui->doubleSpinBox_7->value(), ui->doubleSpinBox_8->value(), ui->doubleSpinBox_9->value());
            form_6->show();
            break;
        }else{
            QMessageBox::warning(this, "Ошибка", "Такого треугольника не сущеаствует!!");
            break;
        }
    }
    case 1:{
        if(iso_tri_check() == true){
            emit signal_isosceles_triangle(ui->doubleSpinBox_7->value(), ui->doubleSpinBox_8->value());
            form_6->show();
            break;
        }else{
            QMessageBox::warning(this, "Ошибка", "Такого треугольника не сущеаствует!!");
            break;
        }
    }
    case 0:{
        if(arb_tri_check() == true){
            emit signal_arbitrary_triangle(ui->doubleSpinBox_7->value(), ui->doubleSpinBox_8->value(), ui->doubleSpinBox_9->value());
            form_6->show();
            break;
        }else{
            QMessageBox::warning(this, "Ошибка", "Такого треугольника не сущеаствует!!");
            break;
        }
    }
    case 2:{
        if ( rec_tri_check() == true ){
            emit signal_rectangular_triangle(ui->doubleSpinBox_7->value(), ui->doubleSpinBox_8->value());
            form_6->show();
            break;
        }else{
            QMessageBox::warning(this, "Ошибка", "Такого треугольника не сущеаствует!!");
            break;
        }
    }
}
}

bool MainWindow::arb_trap_check()
{
    double left_side = ui->side1->value();
    double bottom_side = ui->footing1->value();
    double top_side = ui->footing2->value();
    double right_side = ui->side2->value();
    double hight =(sqrt ( pow(left_side, 2) - ( pow( ( ((pow( (bottom_side - top_side), 2)) +
                                                              (pow(left_side, 2) - (pow(right_side, 2)))) / (2 * (bottom_side - top_side))), 2))));

    if ( !(std::isnan(hight))  && (hight != 0.0))  {
        return true;
    }else{
        return false;
    }
}

bool MainWindow::iso_trap_check()
{
    double hight = ui->side1->value();

    if ( !(std::isnan(hight))  && (hight != 0.0))  {
        return true;
    }else{
        return false;
    }
}

bool MainWindow::rec_trap_check()
{
    double hight = ui->side1->value();

    if ( hight != 0.0 )  {
        return true;
    }else{
        return false;
    }
}

bool MainWindow::par_angle_check()
{
    double angle = ui->doubleSpinBox_6->value();

    if (angle > 0 and angle < 180){
        return true;
    }else{
        return false;
    }
}

bool MainWindow::par_hight_check()
{
    double side_a = ui->doubleSpinBox_4->value();
    double side_b = ui->doubleSpinBox_5->value();
    double hight = ui->doubleSpinBox_6->value();

    if ( sqrt(pow(side_a, 2) - pow(side_b, 2)) == hight ){
        return true;
    }
    else{
        return false;
    }

}

bool MainWindow::arb_tri_check()
{
    double side1 = ui->doubleSpinBox_7->value();
    double side2 = ui->doubleSpinBox_8->value();
    double side3 = ui->doubleSpinBox_9->value();

    if ( ( (side1 + side2) > side3) and ( (side1 + side3) > side2) and ( (side3 + side2) > side1) ) {
        return true;
    }else{
        return false;
    }
}

bool MainWindow::iso_tri_check()
{
    double side = ui->doubleSpinBox_7->value();
    double hight = ui->doubleSpinBox_8->value();

    if ( side > hight ){
        return true;
    }else{
        return false;
    }
}

bool MainWindow::rec_tri_check()
{
    double input_cathet = ui->doubleSpinBox_7->value();
    double hypotenuse = ui->doubleSpinBox_8->value();

    if ( (input_cathet != 0) and (hypotenuse != 0) and ( hypotenuse > input_cathet)  ){
        return true;
    }else{
        return false;
    }
}

bool MainWindow::ang_tri_check()
{
    double angle1 = ui->doubleSpinBox_8->value();
    double angle2 = ui->doubleSpinBox_9->value();

    if( (angle1 + angle2) < 180){
        return true;
    }else{
        return false;
    }
}

void MainWindow::paint_cir(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    int radius = 100;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->gr_circle->setScene(scene);

    QGraphicsTextItem *text1 = new QGraphicsTextItem("r");
    text1->setPos(75, 25);
    group1->addToGroup(text1);

    group1->addToGroup(scene->addEllipse( -2*radius*(pow(2, 0.5))/4, -2*radius*(pow(2, 0.5))/4, radius*2, radius*2));
    group1->addToGroup(scene->addLine(radius, radius, radius*0.3, radius*0.3));
}

void MainWindow::paint_rect(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    int height, width;
    height = 200;
    width = 100;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();
    scene->addItem(group1);

    ui->gr_rect->setScene(scene);

    QGraphicsTextItem *text2 = new QGraphicsTextItem("b");
    text2->setPos(80, -30);
    QGraphicsTextItem *text3 = new QGraphicsTextItem("a");
    text3->setPos(-20, 40);
    group1->addToGroup(text3);
    group1->addToGroup(text2);

    group1->addToGroup(scene->addRect(0, 0, height, width));
}
void MainWindow::paint_par_hight(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    int height, width, hight;
    height = 100;
    width = 200;
    hight = 80;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->gr_par->setScene(scene);

    group1->addToGroup(scene->addLine(0, 0, width, 0));
    QGraphicsTextItem *text1 = new QGraphicsTextItem("h");
    text1->setPos(100, -50);
    QGraphicsTextItem *text2 = new QGraphicsTextItem("b");
    text2->setPos(30, -65);
    QGraphicsTextItem *text3 = new QGraphicsTextItem("a");
    text3->setPos(170, -100);
    group1->addToGroup(text1);
    group1->addToGroup(text2);
    group1->addToGroup(text3);

    group1->addToGroup(scene->addLine(0, 0, width, 0));
    group1->addToGroup(scene->addLine(0, 0, height, -hight));
    group1->addToGroup(scene->addLine(height, -hight, height + width, -hight));
    group1->addToGroup(scene->addLine(height, -hight, height, 0));
    group1->addToGroup(scene->addLine(height + width, -hight, width, 0));
}
void MainWindow::paint_par_ang(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    int height, width, hight;
    height = 100;
    width = 200;
    hight = 80;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->gr_par->setScene(scene);

    group1->addToGroup(scene->addLine(0, 0, width, 0));
    QGraphicsTextItem *text1 = new QGraphicsTextItem("α");
    text1->setPos(15, -20);
    QGraphicsTextItem *text2 = new QGraphicsTextItem("b");
    text2->setPos(30, -65);
    QGraphicsTextItem *text3 = new QGraphicsTextItem("a");
    text3->setPos(170, -100);
    group1->addToGroup(text1);
    group1->addToGroup(text2);
    group1->addToGroup(text3);
    group1->addToGroup(scene->addLine(0, 0, height, -hight));
    group1->addToGroup(scene->addLine(height, -hight, height + width, -hight));
    group1->addToGroup(scene->addLine(height + width, -hight, width, 0));
}
void MainWindow::paint_tri_side(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->gr_tri->setScene(scene);

    int left_side, bottom_side;
    left_side = 100;
    bottom_side = 100;

    group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));
    group1->addToGroup(scene->addLine(0, 0, bottom_side/2, -left_side));
    group1->addToGroup(scene->addLine(bottom_side/2, -left_side, bottom_side, 0));

    QGraphicsTextItem *text1 = new QGraphicsTextItem("a");
    text1->setPos(0, -50);
    QGraphicsTextItem *text2 = new QGraphicsTextItem("b");
    text2->setPos(85, -50);
    QGraphicsTextItem *text3 = new QGraphicsTextItem("c");
    text3->setPos(45, 0);
    group1->addToGroup(text1);
    group1->addToGroup(text2);
    group1->addToGroup(text3);
//    group1->addToGroup(scene->addLine(0, 0, left_side, -hight));
//    group1->addToGroup(scene->addLine(left_side, -hight, right_side, 0));
//    group1->addToGroup(scene->addLine(0, 0, right_side, 0));
}
void MainWindow::paint_tri_nor(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->gr_tri->setScene(scene);

    int left_side, bottom_side;
    left_side = 100;
    bottom_side = 100;

    QGraphicsTextItem *text1 = new QGraphicsTextItem("c");
    text1->setPos(20, -60);
    QGraphicsTextItem *text2 = new QGraphicsTextItem("a");
    text2->setPos(110, -60);
    group1->addToGroup(text1);
    group1->addToGroup(text2);
    group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));
    group1->addToGroup(scene->addLine(0, 0, bottom_side, -left_side));
    group1->addToGroup(scene->addLine(bottom_side, -left_side, bottom_side, 0));
}
void MainWindow::paint_tri_iso(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->gr_tri->setScene(scene);

    int left_side, bottom_side;
    left_side = 100;
    bottom_side = 100;


    QGraphicsTextItem *text1 = new QGraphicsTextItem("h");
    text1->setPos(50, -50);
    QGraphicsTextItem *text2 = new QGraphicsTextItem("a");
    text2->setPos(0, -50);
    group1->addToGroup(text1);
    group1->addToGroup(text2);

    group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));
    group1->addToGroup(scene->addLine(0, 0, bottom_side/2, -left_side));
    group1->addToGroup(scene->addLine(bottom_side/2, -left_side, bottom_side/2, 0));
    group1->addToGroup(scene->addLine(bottom_side/2, -left_side, bottom_side, 0));
}
void MainWindow::paint_tri_s_ang(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->gr_tri->setScene(scene);

    int left_side, bottom_side;
    left_side = 100;
    bottom_side = 100;


    QGraphicsTextItem *text1 = new QGraphicsTextItem("a");
    text1->setPos(45, 0);
    QGraphicsTextItem *text2 = new QGraphicsTextItem("α");
    text2->setPos(5, -20);
    QGraphicsTextItem *text3 = new QGraphicsTextItem("β");
    text3->setPos(80, -20);
    group1->addToGroup(text1);
    group1->addToGroup(text2);
    group1->addToGroup(text3);

    group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));
    group1->addToGroup(scene->addLine(0, 0, bottom_side/2, -left_side));
    group1->addToGroup(scene->addLine(bottom_side/2, -left_side, bottom_side, 0));
}
void MainWindow::paint_trap_arb(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->gr_trap->setScene(scene);

    int top_side, bottom_side;
    top_side = 150;
    double hight = 94.2809;
    bottom_side = 300;

    int ratio1 = ( bottom_side - top_side >= 0 ) ? ( bottom_side - top_side ) / 2 : 0;
    int ratio2 = ( top_side - bottom_side >= 0 ) ? ( top_side - bottom_side ) / 2 : 0;

    group1->addToGroup(scene->addLine(ratio1, ratio2, ratio1 + top_side, 0));
    group1->addToGroup(scene->addLine(ratio1, 0, ratio2, hight));
    group1->addToGroup(scene->addLine(ratio2, hight, bottom_side + ratio2, hight));
    group1->addToGroup(scene->addLine(bottom_side + ratio2, hight, top_side + ratio1, 0));

}
void MainWindow::paint_trap_rect(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->gr_trap->setScene(scene);

    int top_side, bottom_side, left_side;
    top_side = 150;
    double hight = 94.2809;
    bottom_side = 300;
    left_side = 150;


    QGraphicsTextItem *text1 = new QGraphicsTextItem("a");
    text1->setPos(15, -115);
    QGraphicsTextItem *text2 = new QGraphicsTextItem("b");
    text2->setPos(-15, -60);
    QGraphicsTextItem *text3 = new QGraphicsTextItem("c");
    text3->setPos(150, 5);
    group1->addToGroup(text1);
    group1->addToGroup(text2);
    group1->addToGroup(text3);

    group1->addToGroup(scene->addLine(0, 0, bottom_side, 0));
    group1->addToGroup(scene->addLine(0, 0, 0, -hight));
    group1->addToGroup(scene->addLine(0, -hight, top_side - sqrt(pow(left_side,2) - pow(hight, 2)), -hight));
    group1->addToGroup(scene->addLine(top_side - sqrt(pow(left_side,2) - pow(hight, 2)), -hight, bottom_side, 0));
}

void MainWindow::paint_trap_iso(){
    QGraphicsScene *scene;
    QGraphicsItemGroup *group1;

    scene = new QGraphicsScene();
    group1 = new QGraphicsItemGroup();

    scene->addItem(group1);

    ui->gr_trap->setScene(scene);

    int top_side, bottom_side;
    top_side = 150;
    double hight = 94.2809;
    bottom_side = 300;

    int ratio1 = ( bottom_side - top_side >= 0 ) ? ( bottom_side - top_side ) / 2 : 0;
    int ratio2 = ( top_side - bottom_side >= 0 ) ? ( top_side - bottom_side ) / 2 : 0;

    group1->addToGroup(scene->addLine(ratio1, ratio2, ratio1 + top_side, 0));
    group1->addToGroup(scene->addLine(ratio1, 0, ratio2, hight));
    group1->addToGroup(scene->addLine(ratio1, hight, ratio1, 0));
    group1->addToGroup(scene->addLine(ratio2, hight, bottom_side + ratio2, hight));
    group1->addToGroup(scene->addLine(bottom_side + ratio2, hight, top_side + ratio1, 0));
}
