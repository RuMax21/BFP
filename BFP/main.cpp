#include "mainwindow.h"
#include <QApplication>
//#include "/home/artem/MAIN_PROJECT/BFP/Geometry_library/Geometry_library/geometry_library.h"
#include "../Geometry_library/Geometry_library/geometry_library.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("BFP");
    w.show();
    return a.exec();
}
