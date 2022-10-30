# -----------------------------------------------------
# Soobin Rho
# October 29, 2022
# COSC 226: C++ Programming
#
# Hw5b: Graphics Classes
#
# This file is in charge of storing the project configs
# for Qt Creator. When we open Qt Creator,
# this file is what we open first.
# -----------------------------------------------------
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += RhoS_Hw5b.cpp

HEADERS += RhoS_Hw5b.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
