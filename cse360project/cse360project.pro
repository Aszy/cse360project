#-------------------------------------------------
#
# Project created by QtCreator 2014-03-30T11:37:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cse360project
TEMPLATE = app


SOURCES += main.cpp\
    Data/data.cpp \
    Data/healthdata.cpp \
    Data/pulseratedata.cpp \
    sampleui.cpp \
    healthtrackerui.cpp

HEADERS  += \
    Data/data.h \
    Data/healthdata.h \
    Data/pulseratedata.h \
    sampleui.h \
    healthtrackerui.h

FORMS    += \
    sampleui.ui \
    healthtrackerui.ui

RESOURCES += \
    resources.qrc
