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
    healthtrackerui.cpp \
    Data/bloodsugardata.cpp \
    Data/temperaturedata.cpp \
    Data/bloodpressuredata.cpp \
    Data/physicalactivitydata.cpp \
    Data/sleepamountdata.cpp \
    Data/strengthworkoutdata.cpp \
    Data/workhoursdata.cpp \
    Data/caloriesdata.cpp \
    Data/cardioworkoutdata.cpp

HEADERS  += \
    Data/data.h \
    Data/healthdata.h \
    Data/pulseratedata.h \
    sampleui.h \
    healthtrackerui.h \
    Data/bloodsugardata.h \
    Data/temperaturedata.h \
    Data/bloodpressuredata.h \
    Data/physicalactivitydata.h \
    Data/sleepamountdata.h \
    Data/strengthworkoutdata.h \
    Data/workhoursdata.h \
    Data/caloriesdata.h \
    Data/cardioworkoutdata.h

FORMS    += \
    sampleui.ui \
    healthtrackerui.ui

RESOURCES += \
    resources.qrc
