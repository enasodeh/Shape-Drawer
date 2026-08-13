QT += core gui widgets xml

CONFIG += c++11

TARGET = ShapeDrawer_Q3
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    drawingarea.cpp \
    shape.cpp \
    shapelist.cpp \
    shapelistmemento.cpp

HEADERS += \
    mainwindow.h \
    drawingarea.h \
    shape.h \
    shapelist.h \
    shapelistmemento.h

OTHER_FILES += \
    shapes.xml
