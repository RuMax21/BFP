QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../Geometry_library/Geometry_library/Circle/circle.cpp \
    ../Geometry_library/Geometry_library/Rectangle/rectangel.cpp \
    ../Geometry_library/Geometry_library/Parallelogram/parallelogram.cpp \
    ../Geometry_library/Geometry_library/Parallelogram/parallelogram_side_hight.cpp \
    ../Geometry_library/Geometry_library/Parallelogram/parallelogram_sides.cpp \
    ../Geometry_library/Geometry_library/Trapezoid/arbitrary_trapezoid.cpp \
    ../Geometry_library/Geometry_library/Trapezoid/isosceles_trapezoid.cpp \
    ../Geometry_library/Geometry_library/Trapezoid/rectangular_trapezoid.cpp \
    ../Geometry_library/Geometry_library/Trapezoid/trapezoid.cpp \
    ../Geometry_library/Geometry_library/Triangle/angel_side_triangle.cpp \
    ../Geometry_library/Geometry_library/Triangle/arbitrary_triangle.cpp \
    ../Geometry_library/Geometry_library/Triangle/isosceles_triangle.cpp \
    ../Geometry_library/Geometry_library/Triangle/rectangular_triangle.cpp \
    ../Geometry_library/Geometry_library/Triangle/triangle.cpp \
    ../Geometry_library/Geometry_library/geometry_library.cpp \
    dialog_circle.cpp \
    dialog_parallelogram.cpp \
    dialog_rectangel.cpp \
    dialog_trapezoid.cpp \
    dialog_triangle.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ../Geometry_library/Geometry_library/Circle/circle.h \
    ../Geometry_library/Geometry_library/Rectangle/rectangel.h \
    ../Geometry_library/Geometry_library/Parallelogram/parallelogram.h \
    ../Geometry_library/Geometry_library/Parallelogram/parallelogram_side_hight.h \
    ../Geometry_library/Geometry_library/Parallelogram/parallelogram_sides.h \
    ../Geometry_library/Geometry_library/Trapezoid/arbitrary_trapezoid.h \
    ../Geometry_library/Geometry_library/Trapezoid/isosceles_trapezoid.h \
    ../Geometry_library/Geometry_library/Trapezoid/rectangular_trapezoid.h \
    ../Geometry_library/Geometry_library/Trapezoid/trapezoid.h \
    ../Geometry_library/Geometry_library/Triangle/angel_side_triangle.h \
    ../Geometry_library/Geometry_library/Triangle/arbitrary_triangle.h \
    ../Geometry_library/Geometry_library/Triangle/isosceles_triangle.h \
    ../Geometry_library/Geometry_library/Triangle/rectangular_triangle.h \
    ../Geometry_library/Geometry_library/Triangle/triangle.h \
    ../Geometry_library/Geometry_library/geometry_library.h \
    dialog_circle.h \
    dialog_parallelogram.h \
    dialog_rectangel.h \
    dialog_trapezoid.h \
    dialog_triangle.h \
    mainwindow.h

FORMS += \
    dialog_circle.ui \
    dialog_parallelogram.ui \
    dialog_rectangel.ui \
    dialog_trapezoid.ui \
    dialog_triangle.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ../Geometry_library/Geometry_library/Geometry_library.pro

DISTFILES += \
    ../Geometry_library/build-Geometry_library-Desktop_Qt_6_2_4_GCC_64bit-Debug/libGeometry_library.a
