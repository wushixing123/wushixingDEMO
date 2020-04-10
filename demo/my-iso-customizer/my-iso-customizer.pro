QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = my-iso-customizer
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    mainwindow.cpp \
    selectiso.cpp \
    selectconstruct.cpp \
    programconfiguration.cpp \
    preliminarypreparation.cpp \
    intermediateinstallation.cpp \
    postcleaning.cpp \
    selectkernel.cpp \
    output.cpp \
    pushbutton.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    mainwindow.h \
    selectiso.h \
    selectconstruct.h \
    programconfiguration.h \
    preliminarypreparation.h \
    intermediateinstallation.h \
    postcleaning.h \
    selectkernel.h \
    output.h \
    pushbutton.h
