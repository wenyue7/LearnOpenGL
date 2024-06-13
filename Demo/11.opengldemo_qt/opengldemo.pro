#-------------------------------------------------
#
# Project created by QtCreator 2019-05-11T20:21:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = opengldemo
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
    Camera.cpp \
    Mesh.cpp \
    Model.cpp \
    Shader.cpp

HEADERS += \
    Camera.h \
    Mesh.h \
    Model.h \
    Shader.h

FORMS +=

RESOURCES += \
    shader.qrc

LIBS += -L/usr/local/lib \
        -L/usr/usr/lib \
        -lGLEW  \
        -lglfw3 \
        -lGL -lX11 \
        -lpthread \
        -lXrandr \
        -lXi \
        -lglib-2.0 \
        -lGLU \
        -ldl \
        -lglut \
        -lSOIL \
        -lXxf86vm \
        -lXinerama \
        -lXcursor \
        -lassimp