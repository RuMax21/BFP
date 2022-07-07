QT -= gui

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Parallelogram/parallelogram.cpp \
    Parallelogram/parallelogram_side_hight.cpp \
    Parallelogram/parallelogram_sides.cpp \
    Rectangle/rectangel.cpp \
    Trapezoid/arbitrary_trapezoid.cpp \
    Trapezoid/isosceles_trapezoid.cpp \
    Trapezoid/rectangular_trapezoid.cpp \
    Trapezoid/trapezoid.cpp \
    Triangle/angel_side_triangle.cpp \
    Triangle/arbitrary_triangle.cpp \
    Triangle/isosceles_triangle.cpp \
    Triangle/rectangular_triangle.cpp \
    Triangle/triangle.cpp \
    circle.cpp \
    geometry_library.cpp

HEADERS += \
    Parallelogram/parallelogram.h \
    Parallelogram/parallelogram_side_hight.h \
    Parallelogram/parallelogram_sides.h \
    Rectangle/rectangel.h \
    Trapezoid/arbitrary_trapezoid.h \
    Trapezoid/isosceles_trapezoid.h \
    Trapezoid/rectangular_trapezoid.h \
    Trapezoid/trapezoid.h \
    Triangle/angel_side_triangle.h \
    Triangle/arbitrary_triangle.h \
    Triangle/isosceles_triangle.h \
    Triangle/rectangular_triangle.h \
    Triangle/triangle.h \
    circle.h \
    geometry_library.h

# Default rules for deployment.
unix {
    target.path = $$[QT_INSTALL_PLUGINS]/generic
}
!isEmpty(target.path): INSTALLS += target
