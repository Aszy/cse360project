#-------------------------------------------------
#
# Project created by QtCreator 2014-03-30T11:37:10
#
#-------------------------------------------------

QT       += core gui webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = cse360project
TEMPLATE = app


SOURCES += main.cpp \
    Data/data.cpp \
    Data/healthdata.cpp \
    Data/pulseratedata.cpp \
    healthtrackerui.cpp \
    Data/bloodsugardata.cpp \
    Data/temperaturedata.cpp \
    Data/bloodpressuredata.cpp \
    Data/physicalactivitydata.cpp \
    Data/sleepamountdata.cpp \
    Data/strengthworkoutdata.cpp \
    Data/workhoursdata.cpp \
    Data/caloriesdata.cpp \
    Data/cardioworkoutdata.cpp \
    Data/UI/pulseratedataui.cpp \
    enterdataui.cpp \
    Data/UI/temperaturedataui.cpp \
    Data/UI/bloodsugardataui.cpp \
    Data/UI/bloodpressuredataui.cpp \
    Data/UI/caloriesdataui.cpp \
    Data/UI/sleepamountdataui.cpp \
    Data/UI/workhoursdataui.cpp \
    Data/UI/strengthworkoutdataui.cpp \
    Data/UI/cardioworkoutdataui.cpp \
    reportui.cpp \
    Data/serializer.cpp \
    Report/report.cpp \
    Report/pulseratereport.cpp \
    Report/bloodsugarreport.cpp \
    Report/bloodpressurereport.cpp \
    Report/temperaturereport.cpp \
    Report/caloriesreport.cpp \
    Report/sleepamountreport.cpp \
    Report/strengthworkoutreport.cpp \
    Report/workhoursreport.cpp \
    Report/cardioworkoutreport.cpp \
    Report/dailyaveragereport.cpp

HEADERS  += \
    Data/data.h \
    Data/healthdata.h \
    Data/pulseratedata.h \
    healthtrackerui.h \
    Data/bloodsugardata.h \
    Data/temperaturedata.h \
    Data/bloodpressuredata.h \
    Data/physicalactivitydata.h \
    Data/sleepamountdata.h \
    Data/strengthworkoutdata.h \
    Data/workhoursdata.h \
    Data/caloriesdata.h \
    Data/cardioworkoutdata.h \
    Data/UI/pulseratedataui.h \
    enterdataui.h \
    Data/UI/temperaturedataui.h \
    Data/UI/bloodsugardataui.h \
    Data/UI/bloodpressuredataui.h \
    Data/UI/caloriesdataui.h \
    Data/UI/sleepamountdataui.h \
    Data/UI/workhoursdataui.h \
    Data/UI/strengthworkoutdataui.h \
    Data/UI/cardioworkoutdataui.h \
    reportui.h \
    Data/serializer.h \
    Report/report.h \
    Report/pulseratereport.h \
    Report/bloodsugarreport.h \
    Report/bloodpressurereport.h \
    Report/temperaturereport.h \
    Report/caloriesreport.h \
    Report/sleepamountreport.h \
    Report/strengthworkoutreport.h \
    Report/workhoursreport.h \
    Report/cardioworkoutreport.h \
    Report/dailyaveragereport.h

FORMS    += \
    healthtrackerui.ui \
    Data/UI/pulseratedataui.ui \
    enterdataui.ui \
    Data/UI/temperaturedataui.ui \
    Data/UI/bloodsugardataui.ui \
    Data/UI/bloodpressuredataui.ui \
    Data/UI/caloriesdataui.ui \
    Data/UI/sleepamountdataui.ui \
    Data/UI/workhoursdataui.ui \
    Data/UI/strengthworkoutdataui.ui \
    Data/UI/cardioworkoutdataui.ui \
    reportui.ui

RESOURCES += \
    resources.qrc
